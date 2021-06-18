#include<stdio.h>  

#include<queue>  

using namespace std;  

priority_queue<int>q;

int main()  
{  
    int n;  
    while(scanf("%d",&n)==1)
	{  
        while(!q.empty())  
        {
			q.pop(); 
		}
		int i;
        for(i=0;i<n;i++)
		{  
            int x;  
            scanf("%d",&x);  
            q.push(-x);  
        }  
        int res=0;  
        for(i=n;i>=3;i=i-2)
		{  
            int x1=q.top();  
            q.pop();  
            int x2=q.top();  
            q.pop();  
            int x3=q.top();  
            q.pop();  
            int tmp=x1+x2+x3;  
            q.push(tmp);  
            res+=tmp;  
        }  
        printf("%d\n",-res);  
    }  
}  
