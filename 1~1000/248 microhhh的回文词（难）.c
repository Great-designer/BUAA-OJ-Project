#include<stdio.h>
#include<string.h>

inline char judgeMirror(char c1,char c2)
{
	return c1==c2;
}

inline char judgeReverse(char c1,char c2)
{
	return (c1=='A'&&c2=='A')||(c1=='E'&&c2=='3')||(c1=='3'&&c2=='E')||(c1=='H'&&c2 =='H')||
		(c1=='I'&&c2=='I')||(c1=='J'&&c2=='L')||(c1=='L'&&c2=='J')||(c1=='M'&&c2=='M')||
		(c1=='O'&&c2=='O')||(c1=='S'&&c2=='2')||(c1=='2'&&c2=='S')||(c1=='T'&&c2=='T')||
		(c1=='U'&&c2=='U')||(c1=='V'&&c2=='V')||(c1=='W'&&c2=='W')||(c1=='X'&&c2=='X')||
		(c1=='Y'&&c2=='Y')||(c1=='5'&&c2=='Z')||(c1=='Z'&&c2=='5')||(c1=='1'&&c2=='1')||
		(c1=='8'&&c2=='8');
}

char s[10010];

int main()
{
	while(~scanf("%s",s))
	{
		char isPalindrome=1,isMirrored=1;
		int n=strlen(s);
		int i=0,j=n-1;
		while(i<=j)
		{
			isPalindrome=isPalindrome&&judgeMirror(s[i],s[j]);
			isMirrored=isMirrored&&judgeReverse(s[i],s[j]);
			j--;
			i++;
		}
		if(isMirrored&&isPalindrome)
		{
			printf("%s -- is a mirrored palindrome.\n",s);
		}
		else if(isMirrored != 0)
		{
			printf("%s -- is a mirrored string.\n",s);
		}
		else if(isPalindrome != 0)
		{
			printf("%s -- is a regular palindrome.\n",s);
		}
		else
		{
			printf("%s -- is not a palindrome.\n",s);
		}
	}
}
