#include<stdio.h>
#include<string.h>

struct Text
{
	char input[10010];
	char occur[150];
	int weight[150];
	int size;
};

void initText(struct Text *a)
{
	memset(a->weight,0,sizeof(a->weight));
	memset(a->occur,0,sizeof(a->occur));
	a->size=0;
}

void read2(struct Text *a)
{
	int i=0;
	char c;
	while(~(c=getchar()))
	{
		a->input[i++]=c;
	}
}

void buildWeight(struct Text *a)
{
	int l=strlen(a->input);
	int i;
	for(i=0;i<l;++i)
	{
		a->weight[a->input[i]]++;
		a->occur[a->input[i]]=1;
	}
	for(i=1;i<150;++i)
	{
		if(a->occur[i])
		{
			++a->size;
		}
	}
}

struct Node
{
	int data;
	int weight;
	int lchild, rchild, parent;
};

struct HuffmanTree
{
	struct Node nodes[300];
	int size;
};

void initHuffmanTree(struct HuffmanTree *a)
{
	memset(a->nodes,0,sizeof(a->nodes));
	a->size=0;
}

void create(int weight[],int n,struct HuffmanTree *a)
{
	int p1=0,p2=0,min1,min2;
	int cnt=1;
	int i;
	for(i=1;i<=n&&cnt<150;cnt++)
	{
		if(weight[cnt])
		{
			a->nodes[i].weight=weight[cnt];
			i++;
		}
	}
	for(i=n+1;i<(n<<1);++i)
	{
		min1=min2=0x3f3f3f3f;
		int j;
		for(j=1;j<i;++j)
		{
			if(!a->nodes[j].parent)
			{
				if(a->nodes[j].weight<min1)
				{
					p2=p1;
					min2=min1;
					p1=j;
					min1=a->nodes[j].weight;
				}
				else if(a->nodes[j].weight<min2)
				{
					p2=j;
					min2=a->nodes[j].weight;
				}
			}
		}
		a->nodes[i].lchild=p1,a->nodes[i].rchild=p2;
		a->nodes[i].weight=a->nodes[p1].weight+a->nodes[p2].weight;
		a->nodes[p1].parent=a->nodes[p2].parent=i;
	}
	a->size=n;
}

void printHuffmanLength(struct HuffmanTree *a)
{
	int ans=0;
	int i;
	for(i=1;i<=a->size;++i)
	{
		int dep=0,pos=i;
		while(a->nodes[pos].parent)
		{
			dep++;
			pos=a->nodes[pos].parent;
		}
		ans+=a->nodes[i].weight*dep;
	}
	printf("%d\n",ans);
}

struct Text text;
struct HuffmanTree a;
int n;

int main()
{
	initText(&text);
	initHuffmanTree(&a);
	read2(&text);
	buildWeight(&text);
	create(text.weight,text.size,&a);
	printHuffmanLength(&a);
}
