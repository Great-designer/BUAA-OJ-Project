#include<stdio.h>

int n;
char str[12];
//其实两个参数就可以 这里为了表达意思更明确设了第三个参数
//step表示我们递归到了第几层 now是我们要输出的字符串数组 len是我们现在字符串的长度
void dfs(int step,char now[],int len)
{
	if(!step)  //已经填满了
	{
		puts(now);//输出即可
		return;
	}
	now[len]='l';//将新的一位设为'l'
	dfs(step-1,now,len+1);//向下递归 步数少1 长度多1
	now[len]='n';//同理
	dfs(step-1,now,len+1);
	now[len]='x';//同理
	dfs(step-1,now,len+1);
}

int main()
{
	scanf("%d",&n);
	int i,now=1;
	for(i=1; i<=n; i++) now=(now<<1)+now;//每位有3种选择 所以乘3
	printf("%d\n",now);
	dfs(n,str,0);
	return 0;
}