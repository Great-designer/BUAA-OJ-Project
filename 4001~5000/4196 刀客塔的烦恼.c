#include<stdio.h>

int main()
{
	int level,record,coin;
	int need_record,need_coin;
	scanf("%d %d %d",&level,&record,&coin);
	need_record=(80-level)*10;
	need_coin=(80-level)*1000;
	if(need_record<=record&&need_coin<=coin)
	{
		printf("YES %d %d",need_record,need_coin);
		return 0;
	}
	else if(need_record>record&&need_coin<=coin)
	{
		need_record=need_record-record;
		need_coin=0;
	}
	else if(need_record<=record&&need_coin>coin)
	{
		need_coin=need_coin-coin;
		need_record=0;
	}
	else if(need_record>record&&need_coin>coin)
	{
		need_record=need_record-record;
		need_coin=need_coin-coin;
	}
	printf("NO %d %d",need_record,need_coin);
	return 0;
}