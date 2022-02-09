#include<stdio.h>
#include<string.h>

int tmpw;
char mapp[505][505];
int w[505],v[505],b[505],c[505],f[505][5*505],d[505];

void init()
{
	tmpw = 0;
	memset(mapp, 0, sizeof(mapp));
	memset(w, 0, sizeof(w));
	memset(v, 0, sizeof(v));
	memset(c, 0, sizeof(c));
	memset(b, 0, sizeof(b));
	memset(d, 0, sizeof(d));
	memset(f, 0, sizeof(f));
}

int n;
//图论判环
void floyd()
{
	for (int i = 1; i <= n; i++) //弗洛里德判断是否有环；
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				if (mapp[k][i] == 1 && mapp[i][j] == 1)
					mapp[k][j] = 1;
}

int tmpn;

void merge()  //合点
{
	tmpn = n;
	for (int i = 1; i <= tmpn; i++)
		for (int j = 1; j <= tmpn; j++)
		{
			if (mapp[i][j] == 1 && mapp[j][i] == 1 && i != j && w[i] > 0 && w[j] > 0)//如果是新环；
			{
				tmpn++;
				v[tmpn] = v[i] + v[j];
				w[tmpn] = w[i] + w[j];
				tmpw--;
				w[i] = tmpw;
				w[j] = tmpw;    //tmpw+tmpn永远等于最开始的n
			}

			//如果j依赖的点被合并(是旧环),且j在环里
			if (w[d[j]] < 0 && w[j]>0 && mapp[j][d[j]] == 1)
			{
				w[n - w[d[j]]] += w[j];
				v[n - w[d[j]]] += v[j];
				w[j] = w[d[j]];
			}

			//如果j依赖的点在环里，但是j不在环里
			if (w[d[j]] < 0 && w[j]>0)
				if ((mapp[j][d[j]] == 1 && mapp[d[j]][j] == 0) || (mapp[j][d[j]] == 0 && mapp[d[j]][j] == 1))
					d[j] = n - w[d[j]];
		}
}
//树形DP
int dfs(int x, int k)
{
	if(f[x][k] > 0)
	{
		return f[x][k];
	}
	if(x == 0 || k <= 0)
	{
		return 0;
	}
	//不取x
	f[b[x]][k] = dfs(b[x], k);
	f[x][k] = f[b[x]][k];
	int y = k - w[x];
	int i;
	for(i = 0; i <= y; i++)
	{
		f[c[x]][y - i] = dfs(c[x], y - i);
		f[b[x]][i] = dfs(b[x], i);
		f[x][k]=f[x][k]>(v[x] + f[c[x]][y - i] + f[b[x]][i])?f[x][k]:(v[x] + f[c[x]][y - i] + f[b[x]][i]);
	}
	return f[x][k];
}

int m;

int main()
{
	tmpw=0;
	while (scanf("%d%d",&n,&m) != EOF)
	{
		init();
		int i;
		for(i = 1; i <= n; i++)
		{
			scanf("%d",&w[i]);
		}
		for(i = 1; i <= n; i++)
		{
			scanf("%d",&v[i]);
		}
		for(i = 1; i <= n; i++)
		{
			scanf("%d",&d[i]);
			mapp[d[i]][i] = 1;
		}
		floyd();
		merge();
		for(i = 1; i <= tmpn; i++)//多叉转二叉
		{
			if (w[i] > 0)
			{
				b[i] = c[d[i]];
				c[d[i]] = i;
			}
		}
		printf("%d\n",dfs(c[0],m));
	}
}