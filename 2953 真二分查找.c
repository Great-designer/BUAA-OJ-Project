#include<stdio.h>

int binarySearch(int nums[],int begin,int end,int target)
{
    int length=end;
    int mid;
    while(begin<end)
	{
        mid=begin+(end-begin)/2;
        if(target==nums[mid])
        {
        	end=mid;
		}
        else if(target<nums[mid])
        {
        	end=mid;
		}
        else
        {
        	begin=mid+1;
		}
    }
    if(begin==length)
    {
    	return -1;
	}
    else
    {
    	return nums[begin]==target?begin:-1;
	}
}

int nums[100000];

int main()
{
    int n,a,q,x;
    scanf("%d",&n);
    int i; 
    for(i=0;i<n;i++)
    {
    	scanf("%d",nums+i);
	}
    scanf("%d",&q);
    for(i=0;i<q;i++)
	{
        scanf("%d",&x);
        int result=binarySearch(nums,0,n,x);
        if(result==-1)
        {
        	printf("No\n");
		}
        else
		{
            printf("Yes %d\n",result+1);
        }
    }
}
