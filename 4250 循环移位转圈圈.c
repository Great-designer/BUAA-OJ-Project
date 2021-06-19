#include<stdio.h>

int main()
{
	int N,k;
	unsigned long long a,left,right,result;//注意数据范围 int 肯定不够用
	while(scanf("%d%d%llu",&N,&k,&a)!=EOF)
	{
		k=k%N;//循环左移k次，本质上等于循环左移k%N次，减小运算量
		a<<=k;//将被操作数左移k
		right=a&((1ULL<<N)-1);//将溢出N位的部分截断，实质上是留下了被操作数右半部分
		left=(a&((1ULL<<(N+k))-(1ULL<<N)))>>N;//取被操作数左半部分，向右移位置于低位
		result=right+left;//合并
		printf("%llu\n",result);
	}
	return 0;
}