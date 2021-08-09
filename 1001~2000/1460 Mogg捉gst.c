#include<stdio.h>

struct Choice
{
	int g_pos;
	int m_pos;
	int now_player;
};

struct State
{
	int g_pos;
	int m_pos;
	int now_player;
	int win_player;
};

int V;
char winner[233][233][3];
char degree[233][233][3];
struct State queue[233*233];
int head, tail;

int edge[233][100010];
int top[100010];

int generPrevChoices(struct Choice *avaChoices, int g_pos, int m_pos, int now_player)
{
	int cnt = 0;
	if (now_player == 2)
	{
		int prev_g_pos;
		for (prev_g_pos=0; prev_g_pos<top[g_pos]; prev_g_pos++)
		{
			struct Choice temp;
			temp.g_pos=edge[g_pos][prev_g_pos];
			temp.m_pos=m_pos;
			temp.now_player=1;
			avaChoices[cnt++]=temp;
		}
	}
	else
	{
		int prev_m_pos;
		for (prev_m_pos=0; prev_m_pos<top[m_pos]; prev_m_pos++)
		{
			if (edge[m_pos][prev_m_pos])
			{
				struct Choice temp;
				temp.g_pos=g_pos;
				temp.m_pos=edge[m_pos][prev_m_pos];
				temp.now_player=2;
				avaChoices[cnt++]=temp;
			}
		}
	}
	return cnt;
}

void initSearch(void)
{
	// 初始化无向图的度
	for (int g_pos=0; g_pos<V; ++g_pos)
	{
		for (int m_pos=0; m_pos<V; ++m_pos)
		{
			degree[g_pos][m_pos][1]=top[g_pos];
			degree[g_pos][m_pos][2]=top[m_pos];
			int dest;
			for (dest=0; dest<top[m_pos]; dest++)
			{
				if (edge[m_pos][dest]==0)
				{
					degree[g_pos][m_pos][2]--;
				}
			}
		}
	}
	head = tail = 0;
	for (int v=0; v<V; ++v)
	{
		for (int now_player = 1; now_player <= 2; ++now_player)
		{
			winner[0][v][now_player] = 1;
			struct State temp;
			temp.g_pos=0;
			temp.m_pos=v;
			temp.now_player=now_player;
			temp.win_player=1;
			queue[tail++]=temp;
			if (v != 0)
			{
				winner[v][v][now_player] = 2;
				temp.g_pos=v;
				temp.m_pos=v;
				temp.now_player=now_player;
				temp.win_player=2;
				queue[tail++]=temp;
			}
		}
	}
}

int search(void)
{
	while (head != tail)
	{
		const struct State *now_state = &queue[head++];
		struct Choice ava_choices[233];
		int ava_cnt = generPrevChoices(ava_choices, (*now_state).g_pos, (*now_state).m_pos, (*now_state).now_player);
		for (struct Choice *it=ava_choices, *E=it+ava_cnt; it!=E; ++it)
		{
			int prev_g_pos = it->g_pos;
			int prev_m_pos = it->m_pos;
			int prev_player = it->now_player;
			if (winner[prev_g_pos][prev_m_pos][prev_player] == 0)
			{
				if (prev_player == (*now_state).win_player)	//  可以扩展至必胜结点，prev_player获胜
				{
					winner[prev_g_pos][prev_m_pos][prev_player] = (*now_state).win_player;
					struct State temp;
					temp.g_pos=prev_g_pos;
					temp.m_pos=prev_m_pos;
					temp.now_player=prev_player;
					temp.win_player=(*now_state).win_player;
					queue[tail++]=temp;
				}
				else
				{
					degree[prev_g_pos][prev_m_pos][prev_player]--;
					if (!degree[prev_g_pos][prev_m_pos][prev_player]) // 可扩展的结点全部都是必败结点，连拖延都没法拖延，prev_player必败
					{
						winner[prev_g_pos][prev_m_pos][prev_player] = 3 - prev_player;
						struct State temp;
						temp.g_pos=prev_g_pos;
						temp.m_pos=prev_m_pos;
						temp.now_player=prev_player;
						temp.win_player=3 - prev_player;
						queue[tail++]=temp;
					}
				}
			}
		}
	}
	return winner[1][2][1];
}

int main()
{
	scanf("%d",&V);
	for(int v=0; v<V; v++)
	{
		int U;
		scanf("%d",&U);
		while(U--)
		{
			int dest;
			scanf("%d",&dest);
			edge[v][top[v]]=dest;
			top[v]++;
		}
	}
	initSearch();
	printf("%d", search());
}
