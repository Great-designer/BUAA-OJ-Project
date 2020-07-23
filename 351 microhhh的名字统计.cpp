#include<stdio.h>
#include<string.h>

#include<map>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	char a[41];
	map<string,int> mata;
	while(n--)
	{
		scanf("%s",a);
		int len=strlen(a);
		sort(a,a+len);
		string aa=a;
		printf("%d\n",mata[aa]);
		mata[aa]++;
	}
}
