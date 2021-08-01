#include<stdio.h>  
#include<string.h>  
#include<math.h>
#include<complex.h>
 
double PI=acos(-1.0);

void change(complex y[],int len)  
{      
	int j=len>>1;   
	int i;    
	for(i=1;i<len-1;i++)      
	{          
		if(i<j)
		{
			complex temp;
			temp=y[i];
			y[i]=y[j];
			y[j]=temp;
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

void FFT(complex y[],int len,int t)  
{      
	change(y,len);
	int h;
	for(h=2;h<=len;h<<=1)      
	{          
		complex wn=cos(2*PI/h)+sin(t*2*PI/h)*I;
		int j;
		for(j=0;j<len;j+=h)          
		{              
			complex w=1;
			int k;
			for(k=j;k<j+h/2;k++)              
			{                  
				complex u=y[k];        
				complex v;
				v=w*y[k+h/2];
				y[k]=u+v;        
				y[k+h/2]=u-v;   
				complex temp;
				temp=w*wn;
				w=temp;
			}          
		}      
	}      
	if(t==-1)
	{
		int i;
		for(i=0;i<len;i++)
		{
			y[i]/=len;
		}  	
	}	
}

void Conv(complex a[],complex b[],int len) 
{    
	FFT(a,len,1);      
	FFT(b,len,1);  
	int i;    
	for(i=0;i<len;i++)
	{
		complex temp;
		temp=a[i]*b[i];
		a[i]=temp;
	}    
	FFT(a,len,-1);
}

complex x1[400005],x2[400005];
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
		x1[i]=0;
		x2[i]=0;
	}
	for(i=0;i<n;i++)   
	{
		x1[i]=(A[i]==first); 
	}       
	int j=m-1;	         
	for(i=0;i<m;i++,j--)     
	{
		x2[i]=(B[j]==second); 
	}  
	Conv(x1,x2,len); 	                  
	for(i=0;i<n+m-1;i++)  
	{
		ans[i]+=(int)(creal(x1[i])+0.5);
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

