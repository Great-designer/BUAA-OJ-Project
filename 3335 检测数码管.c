#include<stdio.h>
#include<string.h>

struct DigitalWatch
{
    char Crystal[7][66];
};

struct DigitalWatch plus(struct DigitalWatch a,struct DigitalWatch b)
{
    struct DigitalWatch ret;
    int i;
    for(i=0;i<7;++i)
    {
        char temp[66];
        strcpy(temp,a.Crystal[i]);
        strcat(temp,b.Crystal[i]);
        strcpy(ret.Crystal[i],temp);
	}
    return ret;
}

void readDW(struct DigitalWatch *a)
{
	int i;
    for(i=0;i<7;++i)
    {
        scanf("%s",a->Crystal[i]);
	}
}

struct DigitalWatch DW(const char a[],const char b[],const char c[],const char d[],const char e[],const char f[],const char g[])
{
	struct DigitalWatch wd;
    strcpy(wd.Crystal[0],a);
	strcpy(wd.Crystal[1],b);
	strcpy(wd.Crystal[2],c);
	strcpy(wd.Crystal[3],d);
	strcpy(wd.Crystal[4],e);
	strcpy(wd.Crystal[5],f);
	strcpy(wd.Crystal[6],g);
	return wd;
}

struct DigitalWatch Number[12];
struct DigitalWatch Colon,Space;

void buildPiece()
{
    Number[0]=DW(
                	".XX.",
                    "X..X",
                    "X..X",
                    "....",
                    "X..X",
                    "X..X",
                    ".XX."
                );
    Number[1]=DW(
                    "....",
                    "...X",
                    "...X",
                    "....",
                    "...X",
                    "...X",
                    "...."
                );
    Number[2]=DW(
                    ".XX.",
                    "...X",
                    "...X",
                    ".XX.",
                    "X...",
                    "X...",
                    ".XX."
                );
    Number[3]=DW(
                    ".XX.",
                    "...X",
                    "...X",
                    ".XX.",
                    "...X",
                    "...X",
                    ".XX."
                );
    Number[4]=DW(
                    "....",
                    "X..X",
                    "X..X",
                    ".XX.",
                    "...X",
                    "...X",
                    "...."
                );
    Number[5]=DW(
                    ".XX.",
                    "X...",
                    "X...",
                    ".XX.",
                    "...X",
                    "...X",
                    ".XX."
                );
    Number[6]=DW(
                    ".XX.",
                    "X...",
                    "X...",
                    ".XX.",
                    "X..X",
                    "X..X",
                    ".XX."
                );
    Number[7]=DW(
                    ".XX.",
                    "...X",
                    "...X",
                    "....",
                    "...X",
                    "...X",
                    "...."
                );
    Number[8]=DW(
                    ".XX.",
                    "X..X",
                    "X..X",
                    ".XX.",
                    "X..X",
                    "X..X",
                    ".XX."
                );
    Number[9]=DW(
                    ".XX.",
                    "X..X",
                    "X..X",
                    ".XX.",
                    "...X",
                    "...X",
                    ".XX."
                );
    Number[10]=DW(
                    "....",
                    "....",
                    "....",
                    "....",
                    "....",
                    "....",
                    "...."
                );
    Colon=DW(
                ".",
                ".",
                "X",
                ".",
                "X",
                ".",
                "."
            );
    Space=DW(
                ".",
                ".",
                ".",
                ".",
                ".",
                ".",
                "."
            );
}

int n;
struct DigitalWatch a[110];
struct DigitalWatch timetable[1550];

void getWatchFormTime(int timeline,struct DigitalWatch *s)
{
    timeline%=1440;
    int h=timeline/60,m=timeline%60;
    int t1=h/10?h/10:10,t2=h%10,t3=m/10,t4=m%10;
    struct DigitalWatch temp1,temp2;
    temp1=plus(Number[t1],Space);
    temp2=plus(temp1,Number[t2]);
    temp1=plus(temp2,Space);
    temp2=plus(temp1,Colon);
    temp1=plus(temp2,Space);
    temp2=plus(temp1,Number[t3]);
    temp1=plus(temp2,Space);
    (*s)=plus(temp1,Number[t4]);
}

void initTimeTable()
{
	int i; 
    for(i=0;i<=1540;++i)
    {
    	getWatchFormTime(i,&timetable[i]);
	}
}

struct AnswerPack
{
    char ans[8][22];
};

void printAP(struct AnswerPack ap)
{
	int i;
    for(i=0;i<7;++i)
	{
		int j;
        for(j=0;j<21;++j)
		{
            switch(ap.ans[i][j])
			{
                case 0:
				putchar('?');
				break;
                case 1:
				putchar('.');
				break;
                case 2:
				putchar('W');
				break;
                case 4:
				putchar('0');
				break;
                case 3:
				putchar('1');
				break;
                default:
				break;
            }
        }
        putchar('\n');
    }
}

struct AnswerPack AP()
{
	struct AnswerPack pa;
    memset(pa.ans,0,sizeof(pa.ans));
    pa.ans[0][0] = pa.ans[0][3] = pa.ans[0][4] =
    pa.ans[0][5] = pa.ans[0][8] = pa.ans[0][9] =
    pa.ans[0][10] = pa.ans[0][11] = pa.ans[0][12] =
    pa.ans[0][15] = pa.ans[0][16] = pa.ans[0][17] = pa.ans[0][20] = 1;
    pa.ans[1][1] = pa.ans[1][2] = pa.ans[1][4] =
    pa.ans[1][6] = pa.ans[1][7] = pa.ans[1][9] =
    pa.ans[1][10] = pa.ans[1][11] = pa.ans[1][13] =
    pa.ans[1][14] = pa.ans[1][16] = pa.ans[1][18] = pa.ans[1][19] = 1;
    pa.ans[2][1] = pa.ans[2][2] = pa.ans[2][4] =
    pa.ans[2][6] = pa.ans[2][7] = pa.ans[2][9] =
    pa.ans[2][11] = pa.ans[2][13] = pa.ans[2][14] =
    pa.ans[2][16] = pa.ans[2][18] = pa.ans[2][19] = 1;
    pa.ans[3][0] = pa.ans[3][3] = pa.ans[3][4] =
    pa.ans[3][5] = pa.ans[3][8] = pa.ans[3][9] =
    pa.ans[3][10] = pa.ans[3][11] = pa.ans[3][12] =
    pa.ans[3][15] = pa.ans[3][16] = pa.ans[3][17] = pa.ans[3][20] = 1;
    pa.ans[4][1] = pa.ans[4][2] = pa.ans[4][4] =
    pa.ans[4][6] = pa.ans[4][7] = pa.ans[4][9] =
    pa.ans[4][11] = pa.ans[4][13] = pa.ans[4][14] =
    pa.ans[4][16] = pa.ans[4][18] = pa.ans[4][19] = 1;
    pa.ans[5][1] = pa.ans[5][2] = pa.ans[5][4] =
    pa.ans[5][6] = pa.ans[5][7] = pa.ans[5][9] =
    pa.ans[5][10] = pa.ans[5][11] = pa.ans[5][13] =
    pa.ans[5][14] = pa.ans[5][16] = pa.ans[5][18] = pa.ans[5][19] = 1;
    pa.ans[6][0] = pa.ans[6][3] = pa.ans[6][4] =
    pa.ans[6][5] = pa.ans[6][8] = pa.ans[6][9] =
    pa.ans[6][10] = pa.ans[6][11] = pa.ans[6][12] =
    pa.ans[6][15] = pa.ans[6][16] = pa.ans[6][17] = pa.ans[6][20] = 1;
    return pa;
}

struct AnswerPack exclusive(struct AnswerPack a,struct AnswerPack b)
{
    struct AnswerPack ret=AP();
    int i;
    for(i=0;i<7;++i)
    {
    	int j;
    	for(j=0;j<21;++j)
    	{
    		ret.ans[i][j]=(a.ans[i][j]==b.ans[i][j])?a.ans[i][j]:0;
		}
	}
    return ret;
}

struct AnswerPack possible[1450];

int legalsize;
char breakdown[8][22];
char occur[2][8][22];

void buildOccur()
{
	int k;
    for(k=0;k<n;++k)
	{
		int i;
        for(i=0;i<7;++i)
		{
			int j;
            for(j=0;j<21;++j)
			{
                int num=a[k].Crystal[i][j]=='X';
                occur[num][i][j]=1;
            }
        }
    }
}

char parse(int s)
{
    memset(breakdown,0,sizeof(breakdown));
    int k;
    for(k=0;k<n;++k)
	{
		int i;
        for(i=0;i<7;++i)
		{
			int j;
            for(j=0;j<21;++j)
			{
                if(timetable[k+s].Crystal[i][j]!=a[k].Crystal[i][j])
				{
                    breakdown[i][j]=1;
                    if(occur[0][i][j]&&occur[1][i][j]&&breakdown[i][j])
                    {
                    	return 0;
					}
                }
            }
        }
    }
    return 1;
}

struct AnswerPack getans()
{
    struct AnswerPack ret=AP();
    int i;
    for(i=0;i<7;++i)
	{
		int j;
        for(j=0;j<21;++j)
		{
            if(ret.ans[i][j]==1)
			{
				continue;
			}
            if(breakdown[i][j])
            {
            	ret.ans[i][j]=occur[0][i][j]?4:3;
			}
            else if(occur[0][i][j]==occur[1][i][j])
            {
            	ret.ans[i][j]=2;
			}
            else
			{
				ret.ans[i][j]=0;
			}
        }
    }
    return ret;
}

int main()
{
    buildPiece();
    initTimeTable();
    scanf("%d",&n);
    int i;
    for(i=0;i<n;++i)
    {
    	readDW(&a[i]);
	}
    buildOccur();
    for(i=0;i<1440;++i)
    {
    	if(parse(i))
    	{
    		possible[++legalsize]=getans();
		}
	}
    if(legalsize==0)
	{
		puts("impossible");
	}
    else
	{
        for(i=2;i<=legalsize;++i)
        {
        	possible[1]=exclusive(possible[1],possible[i]);
		}
        printAP(possible[1]);
    }
}
