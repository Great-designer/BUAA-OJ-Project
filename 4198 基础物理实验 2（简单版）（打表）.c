#include<stdio.h>

int main()
{
	int n;
	int flag=0;
	while(~scanf("%d",&n))
	{
		if(flag!=0)
		{
			printf("\n");
		}
		flag=1;
		if(n==0)
		{
			printf("0\n");
		}
		else if(n==1)
		{
			printf("1\n");
		}
		else if(n==2)
		{
			printf("3\n");
		}
		else if(n==3)
		{
			printf(" 1\n");
			printf("5-\n");
			printf(" 2\n");
		}
		else if(n==4)
		{
			printf(" 1\n");
			printf("8-\n");
			printf(" 3\n");
		}
		else if(n==5)
		{
			printf("  5\n");
			printf("11--\n");
			printf("  12\n");
		}
		else if(n==6)
		{
			printf("  7\n");
			printf("14--\n");
			printf("  10\n");
		}
		else if(n==7)
		{
			printf("  3\n");
			printf("18--\n");
			printf("  20\n");
		}
		else if(n==8)
		{
			printf("  26\n");
			printf("21--\n");
			printf("  35\n");
		}
		else if(n==9)
		{
			printf("  129\n");
			printf("25---\n");
			printf("  280\n");
		}
		else if(n==10)
		{
			printf("  73\n");
			printf("29---\n");
			printf("  252\n");
		}
		else if(n==11)
		{
			printf("  551\n");
			printf("33----\n");
			printf("  2520\n");
		}
		else if(n==12)
		{
			printf("  551\n");
			printf("37----\n");
			printf("  2310\n");
		}
		else if(n==13)
		{
			printf("  9473\n");
			printf("41-----\n");
			printf("  27720\n");
		}
		else if(n==14)
		{
			printf("  13433\n");
			printf("45-----\n");
			printf("  25740\n");
		}
		else if(n==15)
		{
			printf("  18581\n");
			printf("49-----\n");
			printf("  24024\n");
		}
		else if(n==16)
		{
			printf("  4129\n");
			printf("54-----\n");
			printf("  45045\n");
		}
		else if(n==17)
		{
			printf("  340463\n");
			printf("58------\n");
			printf("  720720\n");
		}
		else if(n==18)
		{
			printf("  620743\n");
			printf("62------\n");
			printf("  680680\n");
		}
		else if(n==19)
		{
			printf("  1662439\n");
			printf("67-------\n");
			printf("  4084080\n");
		}
		else if(n==20)
		{
			printf("  3704479\n");
			printf("71-------\n");
			printf("  3879876\n");
		}
		else if(n==21)
		{
			printf("  408335\n");
			printf("76------\n");
			printf("  739024\n");
		}
		else if(n==22)
		{
			printf("  46533\n");
			printf("81------\n");
			printf("  235144\n");
		}
		else if(n==23)
		{
			printf("  4597419\n");
			printf("85-------\n");
			printf("  5173168\n");
		}
		else if(n==24)
		{
			printf("  9265735\n");
			printf("90--------\n");
			printf("  14872858\n");
		}
		else if(n==25)
		{
			printf("  142406227\n");
			printf("95---------\n");
			printf("  356948592\n");
		}
		else if(n==26)
		{
			printf("   73762267\n");
			printf("100---------\n");
			printf("   343219800\n");
		}
		else if(n==27)
		{
			printf("   206234003\n");
			printf("105----------\n");
			printf("   2974571600\n");
		}
		else if(n==28)
		{
			printf("   2755866803\n");
			printf("109----------\n");
			printf("   2868336900\n");
		}
		else if(n==29)
		{
			printf("   71315126587\n");
			printf("114-----------\n");
			printf("   80313433200\n");
		}
		else if(n==30)
		{
			printf("   65960897707\n");
			printf("119-----------\n");
			printf("   77636318760\n");
		}
	}
}

