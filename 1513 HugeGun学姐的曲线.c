#include<stdio.h> 

const double e=1e-10;

double a,b,c,d,k1,k2,w,x,y,z,b1,b2; 
double jx,jy;
int kk1=0,kk2=0; 

void q(double xx,double kk,double aa,double bb)
{ 
	jx=xx;
	jy=kk*(xx-aa)+bb; 
	jx=jx+e; 
	jy=jy+e; 
} 
  
void j(double kkk,double kkkk,double bbb,double bbbb)
{ 
	jx=(bbbb-bbb)/(kkk-kkkk);
	jy=kkk*jx+bbb; 
	jx=jx+e; 
	jy=jy+e; 
} 

int main()
{ 
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d); 
	scanf("%lf%lf%lf%lf",&w,&x,&y,&z); 
	if(a==c)
	{ 
		kk1=1;
	} 
	else
	{ 
		k1=(b-d)/(a-c); 
	} 
	if(w==y)
	{ 
		kk2=1; 
	} 
	else
	{ 
		k2=(x-z)/(w-y); 
	} 
	if(k1==k2||(kk1==1&&kk2==1))
	{ 
		printf("Zyysb"); 
	} 
	else
	{ 
		if(kk1==1&&kk2==0)
		{ 
			q(a,k2,w,x); 
			printf("(%.6f,%.6f)",jx,jy); 
		} 
		if(kk1==0&&kk2==1)
		{ 
			q(w,k1,a,b); 
			printf("(%.6f,%.6f)",jx,jy); 
		} 
		if(kk1==0&&kk2==0)
		{ 
			q(0,k1,a,b);
			b1=jy; 
			q(0,k2,w,x); 
			b2=jy; 
			j(k1,k2,b1,b2); 
			printf("(%.6f,%.6f)",jx,jy); 
		} 
	}
}
