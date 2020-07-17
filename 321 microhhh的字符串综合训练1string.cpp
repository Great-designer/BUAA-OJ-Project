#include<iostream>
#include<string>

using namespace std;

string input;
string instr;
string op2;

int InstrCnt;
int op1,op1a;

void handler()
{
	if(instr=="Length")
	{
		cout << input.length() << endl;
	} 
	else if(instr=="Insert")
	{
		cin >> op1 >> op2;
		input.insert(op1-1,op2);
	}
	else if(instr=="Delete")
	{
		cin >> op1 >> op1a;
		input.erase(op1-1,op1a);
	}
	else if(instr=="Replace")
	{
		cin >> op1 >> op1a >> op2;
		input.replace(op1-1,op1a,op2);
	}
	else if(instr=="Substr")
	{
		cin >> op1 >> op1a;
		cout << input.substr(op1-1,op1a) << endl;
	}
	else if(instr=="Compare")
	{
		cin >> op1 >> op1a >> op2;
		cout << input.compare(op1-1,op1a,op2) << endl;
	}
	else if(instr=="Find")
	{
		cin >> op1 >> op2;
		string sub=input.substr(op1-1,input.length()-op1+1);
		if(sub.find(op2)==sub.npos)
		{
			cout << 0 << endl;
		} 
	}
}

int main()
{
	while(cin >> input)
	{
		cin >> InstrCnt;
		while(InstrCnt--)
		{
			cin >> instr;
			handler();
		}
		cout << input << endl;
	}
}
