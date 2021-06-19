#include<stdio.h>

int main()
{
	int a,i,j,crc=0xFFFF,str[10];
	for(i=0; i<8; i++)
	{
		scanf("%X",&a);
		str[i]=a;
	}
	i=0;
	while(i<8)
	{
		crc=crc^str[i];
		for(j=0; j<8; j++)
		{
			if(crc&0x0001)
			{
				crc=crc>>1;
				crc=crc^0xA001;
			}
			else
			{
				crc=crc>>1;
			}
		}
		i++;
	}
	printf("%02X %02X",crc&0xFF,crc>>8);
}