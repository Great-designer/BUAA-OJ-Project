#include<string.h>
#include<stdio.h>
#include<ctype.h>

char s[2010];
int _index, len, _size;
int ans;
int need;

void write(int x)
{
	if (x < 0)
		putchar('-'), x = -x;
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + 48);
}

int main()
{
	while(scanf("%s", s) != EOF)
	{
		need = 0;
		len = strlen(s);
		_index = ans = 0;
		while(_index < len)
		{
			if(islower(s[_index])) ++ans, ans += need, need = 0, ++_index;
			else
			{
				_size = 0;
				while(isupper(s[_index])) ++_size, ++_index;
				if(_size == 1) ans += 2;
				else ans += 1 + _size, need = 1;
			}
		}
		write(ans), putchar('\n');
	}
}