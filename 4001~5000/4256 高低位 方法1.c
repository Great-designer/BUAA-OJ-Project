#include<stdio.h>

int main()
{
	int Dec[42]= {}; //十进制结果
	int DecLength=1;//十进制结果长度
	unsigned long long AHigh,ALow;
	unsigned long long BHigh,BLow;
	unsigned long long CLow=0x0;
	unsigned long long CHigh=0x0;
	scanf("%llu%llu%llu%llu",&AHigh,&ALow,&BHigh,&BLow);
	/*------------全加器------------*/
	unsigned long long CarryLow=0; //低位进位数纪录变量
	int Index;
	for(Index=0; Index<64; Index++)
	{
		CarryLow=CarryLow<<1;
		unsigned long long ToolNum=1;
		ToolNum=ToolNum<<Index;
		CLow|=ToolNum&(ALow^BLow^CarryLow);
		CarryLow=(ToolNum&((ALow&BLow)|(CarryLow&BLow)|(ALow&CarryLow)));
	}
	unsigned long long CarryHigh=CarryLow>>63; //高位进位数纪录变量，转存低位结果
	for(Index=0; Index<64; Index++)
	{
		unsigned long long ToolNum=1;
		ToolNum=ToolNum<<Index;
		CHigh|=ToolNum&(AHigh^BHigh^CarryHigh);
		CarryHigh=(ToolNum&((AHigh&BHigh)|(CarryHigh&BHigh)|(AHigh&CarryHigh)))<<1;
	}
	unsigned long long IsLessThanZero;
	/*-----------#全加器#-----------*/
	if (CHigh==0&&CLow==0) //防止0减一取反
	{
		printf("%d",0);
	}
	else if(CHigh==0x8000000000000000&&CLow==0x0)  //防止最小数减一取反
	{
		printf("-170141183460469231731687303715884105728");
	}
	else
	{
		/*------------绝对值------------*/
		IsLessThanZero=CHigh&0x8000000000000000;
		if(IsLessThanZero)
		{
			if (CLow<1)
			{
				CHigh--; //高位借位
				CLow=0xffffffffffffffff;//低位减一
			}
			else
			{
				CLow--; //低位减一
			}
			CLow=~CLow; //取反
			CHigh=~CHigh;
		}
		/*-----------#绝对值#-----------*/
		/*------------十进制------------*/
		int BitToDec[42]= {1}; //当前位二进制数的十进制权重
		int LastBitToDec[42]= {1}; //上一位二进制数的十进制权重,没啥用
		int TBDLenth=1;//当前位二进制数的十进制权重的数组长度
		int LowCounter=0,HighCounter=0; //当前处理位的偏移量
		unsigned long long ToolNumber=1; //用于截取某一位数字的工具数
		while (LowCounter<64)
		{
			if (CLow&(ToolNumber<<LowCounter))
			{
				/*-----向求和数中加上当前位的权重-----*/
				for(int i=0; i<TBDLenth; i++)
				{
					Dec[i]+=BitToDec[i];
					DecLength=i+1;
					if(Dec[i]>9)
					{
						Dec[i]%=10;
						Dec[i+1]++;
						DecLength=i+2;
					}
				}
				/*-----#向求和数中加上当前位的权重#-----*/
			}
			int WaitBit=0; //进位记录
			/*-----权重乘2-----*/
			int i;
			for(i=0; i<TBDLenth; i++)
			{
				LastBitToDec[i]=BitToDec[i];
				BitToDec[i]*=2;
				BitToDec[i]+=WaitBit;
				WaitBit=0;
				if(BitToDec[i]>9)
				{
					WaitBit=BitToDec[i]/10;
					BitToDec[i]%=10;
					if(i==TBDLenth-1)
					{
						TBDLenth++;
					}
				}
			}
			/*-----#权重乘2#-----*/
			LowCounter++;
		}
		while (HighCounter<64)
		{
			if (CHigh&(ToolNumber<<HighCounter))
			{
				/*-----向求和数中加上当前位的权重-----*/
				int i;
				for(i=0; i<TBDLenth; i++)
				{
					Dec[i]+=BitToDec[i];
					DecLength=i+1;
					if(Dec[i]>9)
					{
						Dec[i]%=10;
						Dec[i+1]++;
						DecLength=i+2;
					}
				}
				/*-----#向求和数中加上当前位的权重#-----*/
			}
			int WaitBit=0;//进位记录
			/*-----权重乘2-----*/
			int i;
			for(i=0; i<TBDLenth; i++)
			{
				LastBitToDec[i]=BitToDec[i];
				BitToDec[i]*=2;
				BitToDec[i]+=WaitBit;
				WaitBit=0;
				if(BitToDec[i]>9)
				{
					WaitBit=BitToDec[i]/10;
					BitToDec[i]%=10;
					if(i==TBDLenth-1)
					{
						TBDLenth++;
					}
				}
			}
			/*-----#权重乘2#-----*/
			HighCounter++;
		}
		/*-----------#十进制#-----------*/
		if (IsLessThanZero)
		{
			putchar('-');
		}
		int i;
		for(i=DecLength-1; i>=0; i--)
		{
			printf("%d",Dec[i]);
		}
	}
	return 0;
}