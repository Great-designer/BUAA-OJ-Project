#include<stdio.h>
#include<algorithm>

using namespace std;

int n;
int arr1[4007],arr2[4007];

int main()
{
	while(~scanf("%d", &n))
	{
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr1[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr2[i]);
		}
		nth_element(arr1,arr1,arr1+n);
		nth_element(arr2,arr2,arr2+n);
		printf("%d\n",arr1[0]+arr2[0]);
	}
}

