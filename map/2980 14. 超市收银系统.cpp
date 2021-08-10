#include<stdio.h>
#include<string.h>

#include<map>
#include<algorithm>
#include<string>

using namespace std;

map<int, pair<string, double> >menu;
map<string, pair<double, int> > buy;

void init()
{
	menu.insert(make_pair(932071, make_pair("chips", 3.50)));
	menu.insert(make_pair(114049, make_pair("chocolate", 8.00)));
	menu.insert(make_pair(304985, make_pair("soap", 2.90)));
	menu.insert(make_pair(955962, make_pair("cupcake", 4.90)));
	menu.insert(make_pair(313903, make_pair("cookie", 6.50)));
	menu.insert(make_pair(243813, make_pair("milk", 3.20)));
	menu.insert(make_pair(961995, make_pair("toothbrush", 4.80)));
	menu.insert(make_pair(933328, make_pair("toothpaste", 9.30)));
	menu.insert(make_pair(914500, make_pair("teapot", 29.80)));
}

int input;
int maxlen;
char tmp[10];
string Tmp;
double total;

int main()
{
	init();
	total = 0.0;
	while (scanf("%d", &input) && input)
	{
		if (!buy.count(menu[input].first))
			buy.insert(make_pair(menu[input].first, make_pair(menu[input].second, 1)));
		else
			buy[menu[input].first].second++;
	}
	for (map<string,pair<double, int> >::iterator it = buy.begin(); it != buy.end(); ++it)
		maxlen = max(maxlen, (int)(*it).first.size());
	printf("NAME");
	for (int i = 0; i <= maxlen - 4; ++i)putchar(' ');
	puts("QUANTITY PRICE SUM");
	for (map<string,pair<double, int> >::iterator it = buy.begin(); it != buy.end(); ++it)
	{
		printf("%s", (*it).first.c_str());
		for (int i = 0; i <= maxlen - (*it).first.size(); ++i)putchar(' ');
		memset(tmp, 0, sizeof(tmp));
		sprintf(tmp, "%d", (*it).second.second);
		Tmp = tmp;
		printf("%s", Tmp.c_str());
		for(int i = 0; i <= 8 - Tmp.size(); ++i)putchar(' ');
		memset(tmp, 0, sizeof(tmp));
		sprintf(tmp, "%.1f", (*it).second.first);
		printf("%s", tmp);
		Tmp = tmp;
		for (int i = 0; i <= 5 - Tmp.size(); ++i)putchar(' ');
		double add = (*it).second.first * (double)(*it).second.second;
		printf("%.2f\n", add);
		total += add;
	}
	printf("total:%.2f", total);
}
