#include<iostream>

using namespace std;

int main()
{
	string lalala;
	string tls = "tls";
	string lls = "lls";
	string lzy = "lzy";
	int counter;
	int index;
	while (cin >> lalala)
	{

		counter = 0;
		index = 0;
		while ((index = lalala.find(tls, index)) != -1)
		{
			counter++;
			index++;
		}
		index = 0;
		while ((index = lalala.find(lls, index)) != -1)
		{
			counter++;
			index++;
		}
		index = 0;
		while ((index = lalala.find(lzy, index)) != -1)
		{
			counter++;
			index++;
		}
		if (counter == 1)printf("YES\n");
		else printf("NO\n");
	}

}
