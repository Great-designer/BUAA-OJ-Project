#include <stdio.h>

int main()
{
	unsigned int Mass = 0;
	scanf("%u", &Mass);
	for (int i = 0; i < 32; i++)
	{
		unsigned int ToolNum = 1u << i;
		if (ToolNum & Mass)
			printf("%u\n", ToolNum);
	}
	return 0;
}