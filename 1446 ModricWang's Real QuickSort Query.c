#include<stdio.h>  

int arr[1000002];

void quicksort(int l,int r,int depth)  
{  
    int i=l;
	int j=r;
	int mid=arr[(i+j+1)/2];  
    while(i<=j)
	{  
        while(arr[i]<mid)
        {
        	i++;
		}
        while(arr[j]>mid)
		{
			j--;
		}  
        if(i<=j)
		{  
			int tmp=arr[i];  
    		arr[i]=arr[j];  
    		arr[j]=tmp; 
            i++;
			j--;  
        }  
    }  
    if(depth==2)
	{  
        for(;i<=r;i++)
        {
        	printf("%d ",arr[i]); 
		}
        printf("\n");  
        exit(0);  
    }  
    if(l<j)
    {
    	quicksort(l,j,depth+1); 
	}
    if(r>i)  
    {
    	quicksort(i,r,depth+1);
	}
}  

int main()  
{  
    int n;  
    scanf("%d",&n);  
    int i;  
    for(i=0;i<n;i++)
    { 
        scanf("%d",&arr[i]);
    } 
    quicksort(0,n-1,1);  
}  
