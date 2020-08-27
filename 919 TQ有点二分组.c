#include<stdio.h>
#include<ctype.h>

unsigned long long read()
{
	unsigned long long k = 0;
	char c = getchar();
	while(!isdigit(c))
	{
		c = getchar();
	}
	while(isdigit(c))
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k;
}

void write(unsigned long long x)
{
	if(x >= 10)
	{
		write(x / 10);
	}
	putchar(x % 10 + 48);
}

long long pow(int c)
{
	return (long long)1 << c;
}

long long mask[6]={	0b0101010101010101010101010101010101010101010101010101010101010101,
					0b0011001100110011001100110011001100110011001100110011001100110011,
					0b0000111100001111000011110000111100001111000011110000111100001111,
					0b0000000011111111000000001111111100000000111111110000000011111111,
					0b0000000000000000111111111111111100000000000000001111111111111111,
					0b0000000000000000000000000000000011111111111111111111111111111111};
					  
inline long long round(long long n, int c)
{
	return (n & mask[c]) + (n >> pow(c)& mask[c]);
}

long long countOnes2(unsigned long long n)
{
	n = round(n, 0);
	n = round(n, 1);
	n = round(n, 2);
	n = round(n, 3);
	n = round(n, 4);
	n = round(n, 5);
	return n;
}

long long n, m;
long long result;

int main()
{
	n = read();
	while(n--)
	{
		m = read();
		result = countOnes2(m);
		if(result == 1)
		{
			putchar('2');
			putchar('2');
			putchar('2');
		}
		else
		{
			write(result);
		}
		putchar('\n');
	}
}
