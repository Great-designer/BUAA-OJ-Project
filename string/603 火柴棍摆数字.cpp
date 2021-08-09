#include<iostream>
#include<string>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		if(n==4)
		{
			puts("11 4");
			continue;
		}
		string big = "";
		while(n > 6)
		{
			big =big + "1";
			n -= 2;
		}
		if(n==6)
		{
			printf("111");
			cout<<big;
			printf(" 77");
			cout<<big;
			printf("\n");
		}
		else if(n==5)
		{
			printf("71");
			cout<<big;
			printf(" 17");
			cout<<big;
			printf("\n");
		}
	}
}