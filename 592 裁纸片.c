#include<stdio.h>

int L[205][205];
int R[205][205];
int U[205][205];
int D[205][205];
char s[205][205];
int n, m;
void gao()
{
	for(int i = 1; i <= n; i++)
	{
		s[i][0] = '#';
		for(int j = 1; j <= m; j++)
		{
			s[0][j] = '#';
			if(s[i][j] != '#')
			{
				if(s[i][j - 1] != '#')
					L[i][j] = L[i][j - 1];
				if(s[i - 1][j] != '#')
					U[i][j] = U[i - 1][j];
			}
		}
	}
	for(int i = n; i >= 1; i--)
	{
		s[i][m + 1] = '#';
		for(int j = m; j >= 1; j--)
		{
			s[n + 1][j] = '#';
			if(s[i][j] != '#')
			{
				if(s[i][j + 1] != '#')
					R[i][j] = R[i][j + 1];
				if(s[i + 1][j] != '#')
					D[i][j] = D[i + 1][j];
			}
		}
	}
}
void init()
{
	scanf("%d%d",&n,&m);
	for(int i = 0; i <= 105; i++)
	{
		for(int j = 0 ; j <= 105; j++)
		{
			L[i][j] = j;
			R[i][j] = j;
			U[i][j] = i;
			D[i][j] = i;
		}
	}
}
int main()
{
	int cas;
	scanf("%d",&cas);
	while(cas--)
	{
		init();
		for(int i = 1; i <= n; i++)
		{
			scanf("%s", s[i] + 1);
		}
		gao();
		int _T = 0, _L = 0, _S = 0;
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = 1; j <= m ; j++)
			{
				if(s[i][j] != '#')
				{
					int _l = j - L[i][j] + 1;
					int _r = R[i][j] - j + 1;
					int _d = D[i][j] - i + 1;
					int _u = i - U[i][j] + 1;
					int _k = ((_l<_r?_l:_r)<< 1) - 1;
					if((_l<_r?_l:_r)>= 2 && _d >= 3)
					{
						if(_k <= _d)
							_T +=(_l<_r?_l:_r)- 1;
						else
						{
							_T += (_d - 1)/ 2;
						}
					}
					if((_u<_r?_u:_r)>= 2)
					{
						_L +=(_u<_r?_u:_r)- 1;
					}
					for(int z = j + 2; z <= R[i][j]; z++)
					{
						int l = z - j + 1;
						if(_d < l)break;
						int ni = l + i - 1;
						int nr = R[ni][j] - j + 1;
						if(nr < l)continue;
						int _ni = ni, _nj = z;
						int _nd = D[_ni][_nj] - _ni + 1;
						if(_nd < l)continue;
						int __ni = _ni + l - 1, __nj = _nj;
						int __k = __nj - L[__ni][__nj] + 1;
						if(__k >= l)
						{
							_S++;
						}
					}
				}
			}
		}
		printf("%d %d %d\n",_T,_L,_S);
	}
}