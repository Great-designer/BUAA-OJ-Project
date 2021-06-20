#include<stdio.h>
#include<string.h>

char a[50]="XABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int i;
        for(i=1;i<=(n+1)/2;i++)
        {
            int counter;
            for(counter=1;counter<=(n+1)/2;counter++)
            {
                if(counter<=(n+1)/2-i||counter>=(n+1)/2+i)
                {
                    printf(" ");
                }
                else
                {
                    printf("%c",a[counter+i-(n+1)/2]);
                }
            }
            counter=counter-2;
            for(;counter>0;counter--)
            {
                if(counter<=(n+1)/2-i||counter>=(n+1)/2+i)
                {
                    printf(" ");
                }
                else
                {
                    printf("%c",a[counter+i-(n+1)/2]);
                }
            }
            printf("\n");
        }
        i=i-2;
        for(;i>0;i--)
        {
            int counter;
            for(counter=1;counter<=(n+1)/2;counter++)
            {
                if(counter<=(n+1)/2-i||counter>=(n+1)/2+i)
                {
                    printf(" ");
                }
                else
                {
                    printf("%c",a[counter+i-(n+1)/2]);
                }
            }
            counter=counter-2;
            for(;counter>0;counter--)
            {
                if(counter<=(n+1)/2-i||counter>=(n+1)/2+i)
                {
                    printf(" ");
                }
                else
                {
                    printf("%c",a[counter+i-(n+1)/2]);
                }
            }
            printf("\n");
        }
    }
} 

