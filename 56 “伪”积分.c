#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main()
{
    double x,y,r,cnt=0;
    srand(time(NULL));
    int i;
    for(i=100000000;i>0;i--)
    {
        x=(double)rand()/RAND_MAX;
        y=(double)rand()/RAND_MAX;
        r=y-(sin(x)/x);
        if(r<=0)
        {
        	cnt++;
		}
    }
    printf("%.3f\n",cnt/100000000);
}


