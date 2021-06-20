#include<stdio.h>
#include<string.h>

int res, len;
char s[15];

int main()
{
	int ord=1, i;
	scanf("%s", s);
	len = strlen(s);
	for(i=0; i<len-1; ++i)
		if(s[i] != '-')
		{
			res += (s[i]-'0')*ord;
			ord ++;
		}
	res %= 11;
	if((s[len-1]!='X'&&res==s[len-1]-'0') || (s[len-1]=='X'&&res==10))
		printf("Right");
	else
	{
		for(i=0; i<len-1; ++i)
			printf("%c", s[i]);
		if(res == 10)
			printf("X");
		else    printf("%d", res);
	}
	return 0;
}