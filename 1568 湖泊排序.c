#include<stdio.h>

int main()
{
	int dt,hz,py,th;
	for(py=1;py<=4;py++)
	{
		for (dt=1;dt<=4;dt++)
		{
			for (th=1;th<=4;th++)
			{
				for (hz=1;hz<=4;hz++) 
				{ 
					if( py!=dt && py!=th && py!=hz && dt!=th && dt!=hz && th!=hz )
					{
						if ( (dt==1) + (hz==4) + (py==3) == 1 )
						if ( (hz==1) + (dt==4) + (py==2) + (th==3) == 1 )
						if ( (hz==4) + (dt==3) == 1 )
						if ( (py==1) + (th==4) + (dt==3) == 1 )
						printf("%d %d %d %d\n",hz,py,th,dt);
					}
				}
			}
		}
	} 
	return 0;
}
