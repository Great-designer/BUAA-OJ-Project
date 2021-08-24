#include<iostream>
#include<list>
#include<string>
using namespace std;

struct Card
{
	enum color {Spade, Heart, Diamond, Club, Joker, JOKER};
	color c;//花色
	int num;//点数 Joker = 14 JOKER = 15
	Card(color cc = Spade,int n = 0)
	{
		num = n, c = cc;
	}
	Card(const string& in)
	{
		if (in.size() <= 1) c = Spade, num = 0;
		else
		{
			if (in[0] == 'j')c = Joker, num = 14;
			else if (in[0] == 'J')c = JOKER, num = 15;
			else
			{
				switch (in[0])
				{
					case 'H':
						c = Heart;
						break;
					case 'D':
						c = Diamond;
						break;
					case 'S':
						c = Spade;
						break;
					case 'C':
						c = Club;
						break;
					default:
						break;
				}
				string n = in.substr(1, in.size() - 1);
				if (n[0] == 'A')num = 1;
				else if (n[0] == 'J')num = 11;
				else if (n[0] == 'Q')num = 12;
				else if (n[0] == 'K')num = 13;
				else num = stoi(n);
			}
		}
	}
	void print(string& s)
	{
		if (c == Joker)s += "joker";
		else if (c == JOKER)s += "JOKER";
		else
		{
			switch (c)
			{
				case Heart:
					s += "H";
					break;
				case Diamond:
					s += "D";
					break;
				case Spade:
					s += "S";
					break;
				case Club:
					s += "C";
					break;
				default:
					break;
			}
			if (num == 1)s += "A";
			else if (num == 11)s += "J";
			else if (num == 12)s += "Q";
			else if (num == 13)s += "K";
			else s += to_string(num);
		}
	}
};

char flag;
list<Card>Z, Kurisu, Public;
int counter[16];//点数记牌器
string tmp;
string res[10010];
int q;
int k;
void read()
{
	for (int i = 0; i < 27; ++i)
		cin >> tmp, Z.push_back(Card(tmp));
	for (int i = 0; i < 27; ++i)
		cin >> tmp, Kurisu.push_back(Card(tmp));
}
void print(int cnt)
{
	for (list<Card>::iterator it = Z.begin(); it != Z.end(); ++it)
	{
		(*it).print(res[cnt]);
		list<Card>::iterator tmp = it;
		++tmp;
		res[cnt] += (tmp == Z.end() ? "\n" : " ");
	}
	for (list<Card>::iterator it = Kurisu.begin(); it != Kurisu.end(); ++it)
	{
		(*it).print(res[cnt]);
		list<Card>::iterator tmp = it;
		++tmp;
		res[cnt] += (tmp == Kurisu.end() ? "\n" : " ");
	}
}
void parsePublic(int num, bool flag)
{
	//检查点数num是否超标, 根据flag决定被谁收走
	if (counter[num] >= 2)
	{
		while (counter[num])
		{
			Card tmp = Public.back();
			Public.pop_back();
			counter[tmp.num]--;
			if (flag)Z.push_back(tmp);
			else Kurisu.push_back(tmp);
		}
	}
}
bool getZtoKurisu(int cnt)
{
	//Z要给Kurisu这么多牌,成功给牌返回true,空了返回false,并且确定结果
	while (cnt--)
	{
		if (Z.empty())
		{
			flag = 2;
			return false;
		}
		Card tmp = Z.front();
		Z.pop_front();
		Kurisu.push_back(tmp);
	}
	return true;
}
bool getKurisutoZ(int cnt)
{
	while (cnt--)
	{
		if (Kurisu.empty())
		{
			flag = 1;
			return false;
		}
		Card tmp = Kurisu.front();
		Kurisu.pop_front();
		Z.push_back(tmp);
	}
	return true;
}
bool getZtoPublic()
{
	if(Z.empty())
	{
		flag = 2;
		return false;
	}
	Card tmp = Z.front();
	Public.push_back(tmp);
	counter[tmp.num]++;
	Z.pop_front();
	if (tmp.c == Card::Joker)getKurisutoZ(3);
	else if (tmp.c == Card::JOKER)getKurisutoZ(5);
	else parsePublic(tmp.num, 1);
	return true;
}
bool getKurisutoPublic()
{
	if(Kurisu.empty())
	{
		flag = 1;
		return false;
	}
	Card tmp = Kurisu.front();
	Public.push_back(tmp);
	counter[tmp.num]++;
	Kurisu.pop_front();
	if (tmp.c == Card::Joker)getZtoKurisu(3);
	else if (tmp.c == Card::JOKER)getZtoKurisu(5);
	else parsePublic(tmp.num, 0);
	return true;
}
void simulate(bool flag)
{
	if (flag)getZtoPublic();
	else getKurisutoPublic();
}
int main()
{
	read();
	for (int i = 0; i < 10010; ++i)res[i] = "";
	print(0);
	flag = 0;
	bool turn = true;//Z先手
	for (int i = 1; i <= 10000; ++i)
	{
		if (flag != 0)
			res[i] = (flag == 1 ? "Zwin\n" : "Kurisuwin\n");
		else
		{
			simulate(turn);
			turn = 1 - turn;
			if (Z.empty())flag = 2;
			else if (Kurisu.empty())flag = 1;
			if (flag == 0)print(i);
			else res[i] = (flag == 1 ? "Zwin\n" : "Kurisuwin\n");
		}
	}
	cin >> q;
	while (q--)
	{
		cin >> k;
		cout << res[k];
	}
}