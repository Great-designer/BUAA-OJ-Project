#include<stdio.h>
#include<string.h>

#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;
//类似八数码难题，直接bfs就完事了
char map[4][4];
unordered_map<unsigned long long,int> a;
queue<unsigned long long>q_black_first;
queue<unsigned long long>q_white_first;
int ans;

int transNum(char a)
{
	return (a == 'O') ? 0 : (a == 'B') ? 1 : 2;
}

char transChar(int a)
{
	return (a == 0) ? 'O' : (a == 1) ? 'B' : 'W';
}

char next_black_first(int a)
{
	return (a & 1) ? 'B' : 'W';
}

char next_white_first(int a)
{
	return (a & 1) ? 'W' : 'B';
}

bool illegal(int _x, int _y)
{
	return _x < 0 || _x > 3 || _y < 0 || _y > 3;
}

bool check()
{
	bool a1 = map[0][0] == map[0][1] && map[0][0] == map[0][2] && map[0][0] == map[0][3];
	bool a2 = map[1][0] == map[1][1] && map[1][0] == map[1][2] && map[1][0] == map[1][3];
	bool a3 = map[2][0] == map[2][1] && map[2][0] == map[2][2] && map[2][0] == map[2][3];
	bool a4 = map[3][0] == map[3][1] && map[3][0] == map[3][2] && map[3][0] == map[3][3];
	bool b1 = map[0][0] == map[1][0] && map[0][0] == map[2][0] && map[0][0] == map[3][0];
	bool b2 = map[0][1] == map[1][1] && map[0][1] == map[2][1] && map[0][1] == map[3][1];
	bool b3 = map[0][2] == map[1][2] && map[0][2] == map[2][2] && map[0][2] == map[3][2];
	bool b4 = map[0][3] == map[1][3] && map[0][3] == map[2][3] && map[0][3] == map[3][3];
	bool c1 = map[0][0] == map[1][1] && map[0][0] == map[2][2] && map[0][0] == map[3][3];
	bool c2 = map[3][0] == map[2][1] && map[3][0] == map[1][2] && map[3][0] == map[0][3];
	return a1 || a2 || a3 || a4 || b1 || b2 || b3 || b4 || c1 || c2;
}

int nx[4] = { -1,0,0,1 };
int ny[4] = { 0,-1,1,0 };

unsigned long long pack_map()
{
	unsigned long long ret = 0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			ret = (ret << 1) + (ret << 3) + transNum(map[i][j]);
		}
	}
	return ret;
}

pair<pair<int,int>,pair<int,int> > unpack_map(unsigned long long pack)
{
	pair<pair<int,int>,pair<int,int> > ret;
	bool flag = false;
	for (int i = 3; i >= 0; --i)
	{
		for (int j = 3; j >= 0; --j)
		{
			map[i][j] = transChar(pack % 10);
			pack /= 10;
			if (map[i][j] == 'O')
			{
				if (!flag)ret.first.first = i, ret.first.second = j, flag = true;
				else ret.second.first = i, ret.second.second = j;
			}
		}
	}
	return ret;
}

int main()
{
	for (int i = 0; i < 4; ++i)scanf("%[^\n]", map[i]), getchar();
	unsigned long long first = pack_map();
	q_black_first.push(first);
	q_white_first.push(first);
	a[first] = 0;
	while (!q_black_first.empty())
	{
		unsigned long long u = q_black_first.front();
		q_black_first.pop();
		memset(map, 0, sizeof(map));
		pair<pair<int,int>,pair<int,int> > place = unpack_map(u);
		pair<int,int> O1 = place.first, O2 = place.second;
		int round = a[u];
		if (check())
		{
			ans = round;
			break;
		}
		char side = next_black_first(round);
		int x_2 = O1.first, y_2 = O1.second;
		for (int i = 0; i < 4; ++i)
		{
			int x3 = x_2 + nx[i], y3 = y_2 + ny[i];
			if (illegal(x3, y3))continue;
			if (map[x3][y3] != side)continue;
			swap(map[x_2][y_2], map[x3][y3]);
			unsigned long long ns = pack_map();
			if (!a.count(ns))
			{
				a[ns] = round + 1;
				q_black_first.push(ns);
			}
			swap(map[x_2][y_2], map[x3][y3]);
		}
		x_2 = O2.first, y_2 = O2.second;
		for (int i = 0; i < 4; ++i)
		{
			int x3 = x_2 + nx[i], y3 = y_2 + ny[i];
			if (illegal(x3, y3))continue;
			if (map[x3][y3] != side)continue;
			swap(map[x_2][y_2], map[x3][y3]);
			unsigned long long ns = pack_map();
			if (!a.count(ns))
			{
				a[ns] = round + 1;
				q_black_first.push(ns);
			}
			swap(map[x_2][y_2], map[x3][y3]);
		}
	}
	a.clear();
	a[first] = 0;
	while (!q_white_first.empty())
	{
		unsigned long long u = q_white_first.front();
		q_white_first.pop();
		memset(map, 0, sizeof(map));
		pair<pair<int,int>,pair<int,int> > place = unpack_map(u);
		pair<int,int> O1 = place.first, O2 = place.second;
		int round = a[u];
		if (check())
		{
			ans = (ans < round) ? ans : round;
			break;
		}
		char side = next_white_first(round);
		int x_2 = O1.first, y_2 = O1.second;
		for (int i = 0; i < 4; ++i)
		{
			int x3 = x_2 + nx[i], y3 = y_2 + ny[i];
			if (illegal(x3, y3))continue;
			if (map[x3][y3] != side)continue;
			swap(map[x_2][y_2], map[x3][y3]);
			unsigned long long ns = pack_map();
			if (!a.count(ns))
			{
				a[ns] = round + 1;
				q_white_first.push(ns);
			}
			swap(map[x_2][y_2], map[x3][y3]);
		}
		x_2 = O2.first, y_2 = O2.second;
		for (int i = 0; i < 4; ++i)
		{
			int x3 = x_2 + nx[i], y3 = y_2 + ny[i];
			if (illegal(x3, y3))continue;
			if (map[x3][y3] != side)continue;
			swap(map[x_2][y_2], map[x3][y3]);
			unsigned long long ns = pack_map();
			if (!a.count(ns))
			{
				a[ns] = round + 1;
				q_white_first.push(ns);
			}
			swap(map[x_2][y_2], map[x3][y3]);
		}
	}
	printf("%d\n", ans);
}