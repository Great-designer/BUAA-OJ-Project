#include<stdio.h>

int main()
{
	int yy, mm, dd;
	int n;
	scanf("%d",&n);
	while (n--)
	{
		scanf("%d%d%d",&yy,&mm,&dd);
		if (mm < 3)
		{
			yy--;
			mm += 12;
		}
		int century = yy / 100;
		int y = yy - century * 100;
		int result = (y + y / 4 + century / 4 - 2 * century + 26 * (mm + 1) / 10 + dd - 1) % 7;
		while (result <= 0)
		{
			result += 7;
		}
		printf("%d\n",result);
	}
	return 0;
}
