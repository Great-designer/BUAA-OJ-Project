#include<stdio.h>
#define max(a,b) a>b?a:b
int a[105];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,ans=1;
		int len=1;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int flag=0;
		for(int i=0;i<n-1;i++){
			
			if(flag&&(a[i-1]>a[i])^(a[i]>a[i+1])){
				len++;
			}
			else{
				ans=max(ans,len);
				len=1;
				flag=0;
			}
			if(a[i]>a[i+1]&&flag==0){
				flag=1;
				len++;
			}
			
		}
		ans=max(ans,len);
		printf("%d\n",ans);
	}
	return 0;
}