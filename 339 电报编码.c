#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char input[2010];
char occur[30];
int weight[30];
int Textsize;

int read()
{
	return scanf("%s",input);
}

void textinit()
{
	memset(weight,0,sizeof(weight));
	memset(occur,0,sizeof(occur));
	Textsize=0;
}

void buildWeight()
{
	int l=strlen(input);
	int i;
	for(i=0;i<l;++i)
	{
		weight[input[i]-'a'+1]++;
		occur[input[i]-'a'+1]=1;
	}
	for(i=1;i<30;++i)
	{	
		if(occur[i])
		{
			++Textsize;
		}
	}
}

struct Node
{
	int data;
	int weight;
	int lchild,rchild,parent;
};


struct Node nodes[300];
int HuffmanTreesize;

void ainit()
{
	memset(nodes,0,sizeof(nodes));
	HuffmanTreesize=0;
}

void create(int weight[],int n)
{
	int p1=0,p2=0,min1,min2;
	int cnt=1;
	int i;
	for(i=1;i<=n&&cnt<30;cnt++)
	{
		if(weight[cnt])
		{
			nodes[i].weight=weight[cnt];
			i++;
		}
	}
	for(i=n+1;i<(n<<1);++i)
	{
		min1=min2=0x3f3f3f3f;
		int j;
		for(j=1;j<i;++j)
		{
			if(!nodes[j].parent)
			{
				if(nodes[j].weight<min1)
				{
					p2=p1;
					min2=min1;
					p1=j;
					min1=nodes[j].weight;
				}
				else if(nodes[j].weight<min2)
				{
					p2=j;
					min2=nodes[j].weight;
				}
			}
		}
		nodes[i].lchild=p1;
		nodes[i].rchild=p2;
		nodes[i].weight=nodes[p1].weight+nodes[p2].weight;
		nodes[p1].parent=nodes[p2].parent=i;
	}
	HuffmanTreesize=n;
}

void printHuffmanLength()
{
	int ans=0;
	int i;
	for(i=1;i<=HuffmanTreesize;++i)
	{
		int dep=0,pos=i;
		while(nodes[pos].parent)
		{
			dep++;
			pos=nodes[pos].parent;
		}
		ans+=nodes[i].weight*dep;
	}
	printf("%d\n",ans);
}

int n;

int main()
{
	scanf("%d",&n);
	while(n--)
	{
		textinit();
		ainit();
		read();
		buildWeight();
		create(weight,Textsize);
		printHuffmanLength();
	}
}
