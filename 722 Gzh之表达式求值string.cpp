#include<math.h>

#include<iostream>
#include<stack>

using namespace std;

string expr;
stack<double> opnd;
stack<char> optr;

const char pri[10][10]=
{
	'>', '>', '<', '<', '<', '<', '<', '<', '>', '>',
	'>', '>', '<', '<', '<', '<', '<', '<', '>', '>',
	'>', '>', '>', '>', '>', '<', '<', '<', '>', '>',
	'>', '>', '>', '>', '>', '<', '<', '<', '>', '>',
	'>', '>', '>', '>', '>', '<', '<', '<', '>', '>',
	'>', '>', '>', '>', '>', '>', '<', '<', '>', '>',
	'>', '>', '>', '>', '>', '>', '>', ' ', '>', '>',
	'<', '<', '<', '<', '<', '<', '<', '<', '=', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	'<', '<', '<', '<', '<', '<', '<', '<', ' ', '='
};

int optr2rank(char op)
{
	switch(op)
	{
		case '+' : return 0;
		case '-' : return 1;
		case '*' : return 2;
		case '/' : return 3;
		case '%' : return 4;
		case '^' : return 5;
		case '!' : return 6;
		case '(' : return 7;
		case ')' : return 8;
		default : return 9;
	}
}

char orderBetween(char op1,char op2)
{
	return pri[optr2rank(op1)][optr2rank(op2)];
}

long long fac(int n)
{
	long long ret=1;
	while(n>1)
	{
		ret*=n--;
	}
	return ret;
}

double cal(double a,char op,double b)
{
	switch (op)
	{
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		case '/': return a/b;
		case '%': return (double)((long long)a%(long long)b);
		case '^': return pow(a,b);
		default : return 0;
	}
}

double cal(double a,char op)
{
	switch(op)
	{
		case '!': return (double)fac((int)a);
		default : return 0;
	}
}

void init(string *expr)
{
	while(!opnd.empty())
	{
		opnd.pop();
	}
	while(!optr.empty())
	{
		optr.pop();
	}
	int findstr;
	while((findstr=expr->find("**"))!=expr->npos)
	{
		expr->replace(findstr,2,"^");
	}
}

int main()
{
	while(cin>>expr)
	{
		init(&expr);
		optr.push('#');
		opnd.push(0);
		int len=expr.length(),i=0;
		expr+="#";
		while(!opnd.empty()&&!optr.empty()&&i<=len)
		{
			if(isdigit(expr[i]))
			{
				double tmp=0;
				while(isdigit(expr[i]))
				{
					tmp=tmp*10+expr[i]-'0';
					++i;
				}
				if(expr[i]=='.')
				{
					double fraction=1;
					++i;
					while(isdigit(expr[i]))
					{
						fraction/=10;
						tmp+=(expr[i]-'0')*fraction;
						++i;
					}
				}
				opnd.push(tmp);
			}
			else
			{
				if(i>=1&&expr[i]=='-'&&expr[i-1]=='(')
				{
					opnd.push(0);
				}
				char op;
				switch(orderBetween(optr.top(),expr[i]))
				{
					case '<' :
					optr.push(expr[i]);
					++i;
					break;
					case '=':
					optr.pop();
					++i;
					break;
					case '>':
					op=optr.top();
					optr.pop();
					if('!'==op)
					{
						double a=opnd.top();
						opnd.pop();
						opnd.push(cal(a,op));
					}
					else
					{
						double b=opnd.top();
						opnd.pop();
						double a=opnd.top();
						opnd.pop();
						opnd.push(cal(a,op,b));
					}
					break;
					default: exit(-1);
				}
			}
		}
		printf("%lld\n",(long long)opnd.top());
	}
}
