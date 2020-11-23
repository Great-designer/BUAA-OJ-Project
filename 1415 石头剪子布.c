#include<stdio.h>  
#include<string.h>  
#include<math.h>   
 
double PI=acos(-1.0);

struct complex  
{      
	double r,i;      
};

void change(struct complex y[],int len)  
{      
	int j=len>>1;   
	int i;    
	for(i=1;i<len-1;i++)      
	{          
		if(i<j)
		{
			struct complex temp;
			temp.r=y[i].r;
			temp.i=y[i].i;
			y[i].r=y[j].r;
			y[i].i=y[j].i;
			y[j].r=temp.r;
			y[j].i=temp.i;
		}
		int k=len>>1;           
		while(j>=k)          
		{              
			j-=k;              
			k>>=1;          
		}          
		if(j<k) 
		{
			j+=k;
		}     
	}  
}

void FFT(struct complex y[],int len,int t)  
{      
	change(y,len);
	int h;
	for(h=2;h<=len;h<<=1)      
	{          
		struct complex wn;
		wn.r=cos(2*PI/h);
		wn.i=sin(t*2*PI/h);
		int j;
		for(j=0;j<len;j+=h)          
		{              
			struct complex w;
			w.r=1;
			w.i=0;             
			int k;
			for(k=j;k<j+h/2;k++)              
			{                  
				struct complex u=y[k];        
				struct complex v;
				v.r=w.r*y[k+h/2].r-w.i*y[k+h/2].i;
				v.i=w.r*y[k+h/2].i+w.i*y[k+h/2].r;
				y[k].r=u.r+v.r;        
				y[k].i=u.i+v.i;                
				y[k+h/2].r=u.r-v.r;   
				y[k+h/2].i=u.i-v.i;
				struct complex temp;
				temp.r=w.r*wn.r-w.i*wn.i;
				temp.i=w.r*wn.i+w.i*wn.r;
				w=temp;
			}          
		}      
	}      
	if(t==-1)
	{
		int i;
		for(i=0;i<len;i++)
		{
			y[i].r/=len;
		}  	
	}	
}

void Conv(struct complex a[],struct complex b[],int len) 
{    
	FFT(a,len,1);      
	FFT(b,len,1);  
	int i;    
	for(i=0;i<len;i++)
	{
		struct complex temp;
		temp.r=a[i].r*b[i].r-a[i].i*b[i].i;
		temp.i=a[i].r*b[i].i+a[i].i*b[i].r;
		a[i]=temp;
	}    
	FFT(a,len,-1);
}

struct complex x1[400005],x2[400005];
char A[200003],B[200003];  
int ans[400005]; 
int n,m;

void solve(char first,char second)
{    
	int len=1;      
	while(len<n*2||len<m*2)
	{
		len<<=1;
	} 	
	int i;
	for(i=0;i<len;i++)
	{
		x1[i].r=0;
		x1[i].i=0;
		x2[i].r=0;
		x2[i].i=0;
	}
	for(i=0;i<n;i++)   
	{
		x1[i].r=(A[i]==first); 
	}       
	int j=m-1;	         
	for(i=0;i<m;i++,j--)     
	{
		x2[i].r=(B[j]==second); 
	}  
	Conv(x1,x2,len); 	                  
	for(i=0;i<n+m-1;i++)  
	{
		ans[i]+=(int)(x1[i].r+0.5);
	}  	
}

int main()  
{      
	scanf("%d%d%s%s",&n,&m,A,B);
	solve('S','R');	
	solve('R','P');	
	solve('P','S');   	
	int ANS=0;
	int i;
	for(i=m-1;i<n+m-1;i++)
	{
		ANS=(ans[i]>ANS?ans[i]:ANS);
	}
	printf("%d\n",ANS);
}  

