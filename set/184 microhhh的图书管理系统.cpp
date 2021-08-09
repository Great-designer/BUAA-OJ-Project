#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

struct Book
{
	string title, author;
	bool operator < (const Book &b) const
	{
		return author < b.author || (author==b.author && title < b.title);
	}
};

struct Book tmp;
vector<Book> books;
map<string, int> ID;
set<int> desk, shelve;
string op, line, title;

int main()
{
	while(getline(cin, line) && line!="END")
	{
		int p = line.find("by");
		tmp = Book{ line.substr(0, p-1), line.substr(p+3) };
		books.push_back(tmp);
	}
	sort(books.begin(), books.end());
	for(int i = 0; i < books.size(); i++)
	{
		ID[ books[i].title ] = i;       //为书本名称编号
		shelve.insert(i);
	}
	while(cin>>op && op!="END")
	{
		if(op=="SHELVE")
		{
			for(auto x:desk)
			{
				auto p = shelve.find(x);
				printf("Put %s", books[x].title.c_str());
				if(p == shelve.begin()) puts(" first");
				else printf(" after "), puts(books[*(--p)].title.c_str());
			}
			desk.clear();
			puts("END");
			continue;
		}
		else
		{
			getline(cin, title);
			title = title.substr(1);        ///getline不会忽略cin>>op时留下的空格
			if(op == "RETURN") desk.insert(ID[title]), shelve.insert(ID[title]);
			else if(op == "BORROW") shelve.erase(ID[title]);
		}
	}
}
