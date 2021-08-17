#include<stdio.h>
#include<string.h>

struct Text
{
	char input[2010];
	bool occur[150];
	int weight[150];
	int size;
	int read()
	{
		return scanf("%s", input);
	}
	void init()
	{
		memset(weight, 0, sizeof(weight));
		memset(occur, false, sizeof(occur));
		size = 0;
	}
	void buildWeight()
	{
		int l = strlen(input);
		for (int i = 0; i < l; ++i)
		{
			weight[input[i] - 'A' + 1]++;
			occur[input[i] - 'A' + 1] = true;
		}
		for (int i = 1; i < 150; ++i)
		{
			if (occur[i])
			{
				++size;
			}
		}
	}
};

struct HuffmanTree
{
	struct Node
	{
		int data;
		int weight;
		int lchild, rchild, parent;
	} nodes[300];
	int size;
	void init()
	{
		memset(nodes, 0, sizeof(nodes));
		size = 0;
	}
	void create(int weight[], int n)
	{
		int p1 = 0, p2 = 0, min1, min2;
		int cnt = 1;
		for (int i = 1; i <= n && cnt < 150; cnt++)
		{
			if (weight[cnt])
			{
				nodes[i].weight = weight[cnt];
				i++;
			}
		}
		for (int i = n + 1; i < (n << 1); ++i)
		{
			min1 = min2 = 0x3f3f3f3f;
			for (int j = 1; j < i; ++j)
			{
				if (!nodes[j].parent)
				{
					if (nodes[j].weight < min1)
					{
						p2 = p1;
						min2 = min1;
						p1 = j;
						min1 = nodes[j].weight;
					}
					else if (nodes[j].weight < min2)
					{
						p2 = j;
						min2 = nodes[j].weight;
					}
				}
			}
			nodes[i].lchild = p1, nodes[i].rchild = p2;
			nodes[i].weight = nodes[p1].weight + nodes[p2].weight;
			nodes[p1].parent = nodes[p2].parent = i;
		}
		size = n;
	}
	void printHuffmanLength()
	{
		//所求长度即为非叶子节点的权值和
		int ans = 0;
		for (int i = 1; i <= size; ++i)
		{
			int dep = 0, pos = i;
			while (nodes[pos].parent)
			{
				dep++;
				pos = nodes[pos].parent;
			}
			ans += nodes[i].weight * dep;
		}
		printf("%d\n", ans);
	}
};

Text text;
HuffmanTree a;
int n;

int main()
{
	scanf("%d", &n);
	while (n--)
	{
		text.init(), a.init();
		text.read();
		text.buildWeight();
		a.create(text.weight, text.size);
		a.printHuffmanLength();
	}
}
