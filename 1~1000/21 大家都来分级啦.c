#include<stdio.h>

int main()
{
    int n,a=0;
    while(~scanf("%d",&n))
	{
        if(n>=0&&n<=100)
		{
            a=n/10;
            switch(a)
			{
                case 10:
			    case 9:printf("A\n");break;                    
				case 8:printf("B\n");break;                    
				case 7:printf("C\n");break;                    
				case 6:printf("D\n");break;                    
				case 5:                    
				case 4:                    
				case 3:                    
				case 2:                    
				case 1:                    
				case 0:printf("E\n");break;                
			}
        }
	    else
		{
            printf("wrong\n");
		}
    }
    return 0;
}

