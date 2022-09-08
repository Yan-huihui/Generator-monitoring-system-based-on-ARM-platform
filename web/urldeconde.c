#include <stdio.h>
#include <string.h>
#include "urldeconde.h"
unsigned char FromHex(unsigned char x)
{
	if(0 == x ) return -1;
	unsigned char y;
	if(x>='A' &&x<='Z') y = x-'A'+10;
	else if(x>='a' &&x <='z') y = x-'a'+10;
	else if(x>='0' && x<='9') y = x-'0';

	return y;
}

int  urlDecode(  char* dest, const char* src)
{
	if(NULL ==src || NULL == dest)
	{
		return -1;

	}
	int len = strlen(src);
	int i =0 ;
	for(i = 0 ;i<len;i++)
	{

		if('+' == src[i]) strcat(dest,"");
		else if('%'==src[i])
		{
			//if(i+2len)return -1;
			unsigned char high = FromHex((unsigned char)src[++i]);
			unsigned char low = FromHex((unsigned char)src[++i]);
			unsigned char temp = high*16 +low;
			char temp2[5]={0};
			sprintf(temp2,"%c",temp);
			strcat(dest , temp2);
		}
	}
	return 0;
}

