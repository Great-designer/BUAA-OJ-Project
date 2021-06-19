#include<stdio.h>

int main()
{
	int m,n,single,ten,hund,thou,tk;
	scanf("%d%d",&m,&n);
	if(n==3)
	{
		for(hund=1; hund<=m; hund++)
			for(ten=1; ten<=m; ten++)
				for(single=1; single<=m; single++)
					if(hund!=ten&&ten!=single&&hund!=single)
						printf("%d%d%d\n",hund,ten,single);
	}
	else if(n==4)
	{
		for(thou=1; thou<=m; thou++)
			for(hund=1; hund<=m; hund++)
				for(ten=1; ten<=m; ten++)
					for(single=1; single<=m; single++)
						if(hund!=ten&&ten!=single&&hund!=single&&thou!=hund&&thou!=ten&&thou!=single)
							printf("%d%d%d%d\n",thou,hund,ten,single);
	}
	else if(n==5)
	{
		for(tk=1; tk<=m; tk++)
			for(thou=1; thou<=m; thou++)
				for(hund=1; hund<=m; hund++)
					for(ten=1; ten<=m; ten++)
						for(single=1; single<=m; single++)
							if(hund!=ten&&ten!=single&&hund!=single&&thou!=hund&&thou!=ten&&thou!=single&&tk!=thou&&tk!=hund&&tk!=ten&&tk!=single)
								printf("%d%d%d%d%d\n",tk,thou,hund,ten,single);
	}
	return 0;
}