#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char input[130];
int len;

struct parse_tree_node
{
	int dfs_time;
	char key_link;
	int child_index[130];
	int child_cnt;
};

struct parse_tree_node memory_pool[130];
int node_cnt;//在内存池中开设的节点个数
int root;//语法树根节点的下标
int dfs_cnt;//dfs序的时间戳
int time_table[130];//dfs_time memory_pool_index

void clear(struct parse_tree_node * x)
{
	int i;
	for (i = 0; i < x->child_cnt; ++i)
	{
		x->child_index[i] = 0;
	}
	x->dfs_time = 0;
	x->key_link = '\0';
	x->child_cnt = 0;
}

int is_leaf(struct parse_tree_node * x)
{
	int i;
	for (i = 0; i < x->child_cnt; ++i)
	{
		if (x->child_index[i])
		{
			return 0;
		}
	}
	return 1;
}

void print(struct parse_tree_node * x)
{
	putchar(x->key_link), putchar(' ');
	int i;
	for (i = 0; i < x->child_cnt; ++i)
	{
		int ch = x->child_index[i];
		if (memory_pool[ch].dfs_time)
		{
			printf("%d ", memory_pool[ch].dfs_time);
		}
		else
		{
			putchar(memory_pool[ch].key_link);
			putchar(' ');
		}
	}
	putchar('\n');
}

//后序遍历dfs序部分

void back_trace(int _index)
{
	int i;
	for (i = 0; i < memory_pool[_index].child_cnt; ++i)
	{
		back_trace(memory_pool[_index].child_index[i]);
	}
	if (!is_leaf(&memory_pool[_index]))
	{
		memory_pool[_index].dfs_time = ++dfs_cnt;
		time_table[dfs_cnt] = _index;
	}
}

void init()
{
	int i;
	for (i = 1; i <= node_cnt; ++i)
	{
		clear(&memory_pool[i]);
	}
	node_cnt = root = 0;
	dfs_cnt = 0;
}

int is_duplicate_bracket(int l, int r)
{
	int s[130], cnt = 0;
	memset(s, 0, sizeof(s));
	int ret = 0;
	int i;
	for (i = l; i < r; ++i)
	{
		if (input[i] == '(')
		{
			s[cnt] = i;
			cnt++;
		}
		if (input[i] == ')')
		{
			cnt--;
			s[cnt] = 0;
		}
	}
	if (cnt == 1 && s[0] == l)
	{
		ret = 1;
	}
	return ret;
}

int get_plus_or_minus(int l, int r)
{
	int in = 0;//在多少层括号内，无论正负，只有0才是真的需要的
	int i;
	for (i = r; i >= l; --i)
	{
		in += input[i] == '(';
		in -= input[i] == ')';
		if (in)
		{
			continue;
		}
		if (input[i] == '+' || input[i] == '-')
		{
			return i;
		}
	}
	return -1;
}

int get_multi_or_div(int l, int r)
{
	int in = 0;//在多少层括号内，无论正负，只有0才是真的需要的
	int i;
	for (i = r; i >= l; --i)
	{
		in += input[i] == '(';
		in -= input[i] == ')';
		if (in)
		{
			continue;
		}
		if (input[i] == '*' || input[i] == '/')
		{
			return i;
		}
	}
	return -1;
}

int get_member_func(int l, int r)
{
	int in = 0;//在多少层括号内，无论正负，只有0才是真的需要的
	int i;
	for (i = r; i >= l; --i)
	{
		in += input[i] == '(';
		in -= input[i] == ')';
		if (in)
		{
			continue;
		}
		if (input[i] == '.')
		{
			return i;
		}
	}
	return -1;
}

int isStandardFunc(int l, int r)
{
	if (r - l + 1 <= 3)
	{
		return 0;
	}
	return islower(input[l]) && input[l + 1] == '(' && input[r] == ')';
}

int build(int l, int r)
{
	if (l > r)
	{
		return 0;
	}
	//pre-treat : 去掉所有括号
	while (is_duplicate_bracket(l, r))
	{
		l++;
		r--;
	}
	int ptn = ++node_cnt, pos;
	//特判 priority 5 : 常量
	if (l == r)
	{
		memory_pool[ptn].key_link = input[l];
		return ptn;
	}
	//priority 1 : 加减符
	pos = get_plus_or_minus(l, r);
	if (pos != -1)
	{
		memory_pool[ptn].key_link = input[pos];
		memory_pool[ptn].child_index[memory_pool[ptn].child_cnt] = build(l, pos - 1);
		memory_pool[ptn].child_cnt++;
		memory_pool[ptn].child_index[memory_pool[ptn].child_cnt] = build(pos + 1, r);
		memory_pool[ptn].child_cnt++;
		return ptn;
	}
	//priority 2 : 乘除符
	pos = get_multi_or_div(l, r);
	if (pos != -1)
	{
		memory_pool[ptn].key_link = input[pos];
		memory_pool[ptn].child_index[memory_pool[ptn].child_cnt] = build(l, pos - 1);
		memory_pool[ptn].child_cnt++;
		memory_pool[ptn].child_index[memory_pool[ptn].child_cnt] = build(pos + 1, r);
		memory_pool[ptn].child_cnt++;
		return ptn;
	}
	//priority 3 : 成员函数
	pos = get_member_func(l, r);
	if (pos != -1)
	{
		memory_pool[ptn].key_link = input[pos + 1];//注意字母在'.'后面
		memory_pool[ptn].child_index[memory_pool[ptn].child_cnt] = build(l, pos - 1);
		memory_pool[ptn].child_cnt++;
		int* commas;
		commas = (int*)malloc(sizeof(int) * 130);
		memset(commas, -1, sizeof(int) * 130);
		int cnt = 0;
		int in = 0;
		int i;
		for(i=pos+3; i<=r-1; ++i)
		{
			in += input[i] == '(';
			in -= input[i] == ')';
			if (in)
			{
				continue;
			}
			if (input[i] == ',')
			{
				commas[cnt] = i;
				cnt++;
			}
		}
		int commas_size = 0;
		while (commas[commas_size] >= 0)
		{
			++commas_size;
		}
		commas[commas_size] = r;
		commas_size++;
		int start = pos + 3;
		for (i = 0; i < commas_size; ++i)
		{
		    memory_pool[ptn].child_index[memory_pool[ptn].child_cnt] = build(start, commas[i] - 1);
			memory_pool[ptn].child_cnt++;
			start = commas[i] + 1;
		}
		return ptn;
	}
	//priority 4 : 普通函数
	pos = isStandardFunc(l, r);
	if (pos)
	{
		memory_pool[ptn].key_link = input[l];
		int* commas;
		commas = (int*)malloc(sizeof(int) * 130);
		memset(commas, -1, sizeof(int) * 130);
		int cnt = 0;
		int in = 0;
		int i;
		for(i=l+2; i<=r-1; ++i)
		{
			in += input[i] == '(';
			in -= input[i] == ')';
			if (in)
			{
				continue;
			}
			if (input[i] == ',')
			{
				commas[cnt] = i;
				cnt++;
			}
		}
		int commas_size = 0;
		while (commas[commas_size] >= 0)
		{
			++commas_size;
		}
		commas[commas_size] = r;
		commas_size++;
		int start = l + 2;
		for (i = 0; i < commas_size; ++i)
		{
		    memory_pool[ptn].child_index[memory_pool[ptn].child_cnt] = build(start, commas[i] - 1);
			memory_pool[ptn].child_cnt++;
			start = commas[i] + 1;
		}
		return ptn;
	}
	return 0;
}

int main()
{
	while (scanf("%s", input) != EOF)
	{
		init();
		len = (int)strlen(input);
		root = build(0, len - 1);
		back_trace(root);
		int i;
		for (i = 1; i <= dfs_cnt; ++i)
		{
			print(&memory_pool[time_table[i]]);
		}
	}
}