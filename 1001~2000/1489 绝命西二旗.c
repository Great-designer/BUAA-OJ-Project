#include <stdio.h>

int ah,am,as;
int bh,bm,bs;
int c,d;
int ans;
int k;

int g(int h,int m,int s){
	return h*3600+m*60+s;
}

int main()
{
	scanf("%d:%d:%d%d:%d:%d%d%d",&ah,&am,&as,&bh,&bm,&bs,&c,&d);
	while (g(bh,bm,bs)+d*k<=g(ah,am,as)+c)
		k++;
	ans=g(bh,bm,bs)+d*k;
	printf("%d:%02d:%02d",ans/60/60,ans/60%60,ans%60);
	return 0;
}
