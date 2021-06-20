#include<stdio.h>
#include<string.h>
#include<ctype.h>

#include<algorithm>

using namespace std;

class Scanner
{
	private:
		char buf[30000002], *p_now;
		bool isc(const char c)
		{
			return c >= 33 && c <= 123;
		}
	public:
		Scanner(void) :
			p_now(buf) { }
		void read(void)
		{
			fread(buf, 1, 30000002, stdin);
		}
		int nextInt(void)
		{
			int ret = 0;
			while (!isdigit(*p_now))
				++p_now;
			do ret = ret * 10 + *p_now++ - '0';
			while (isdigit(*p_now));
			return ret;
		}
		char *nextLine(void)
		{
			while (!isc(*p_now))
				++p_now;
			char *begin = p_now;
			while (isc(*p_now))
				++p_now;
			*p_now = '\0';
			return begin;
		}
};

Scanner in;
char *str[3000006];

int main()
{
	in.read();
	int T = in.nextInt();
	int k, n;
	while (T--)
	{
		k = in.nextInt(), n = in.nextInt();
		for (int i=0; i<n; ++i)
			str[i] = in.nextLine();
		nth_element(str, str+k-1, str+n, [](const char *p, const char *q) -> bool
		{
			return strcmp(p, q) < 0;
		});
		puts(str[k-1]);
	}
	return 0;
}
