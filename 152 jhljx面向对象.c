#include<stdio.h>
#include<string.h>
#include<stdlib.h> 

struct student
{
    char name[25];
    int id;
    int yy,mm,dd;
};

struct student sheet[15];

int compare(const void *p1,const void *p2)
{
	struct student *a=(struct student*)p1;
	struct student *b=(struct student*)p2;
	return a->id>b->id;
}

void read(struct student *a)
{
    scanf("%s%d%d%d%d",a->name,&a->id,&a->yy,&a->mm,&a->dd);
}

void print(struct student a)
{
    printf("Name:%s\n",a.name);
    printf("StudentId:%d\n",a.id);
    printf("Birth:%d.%d.%d\n",a.yy,a.mm,a.dd);
}

int n;

int main()
{
    while(~scanf("%d",&n))
	{
        memset(sheet,0,sizeof(sheet));
        int i;
        for(i=0;i<n;++i)
		{
			read(&sheet[i]);
		}
        qsort(sheet,n,sizeof(struct student),compare);
        for(i=0;i<n;++i)
		{
			print(sheet[i]);
		}
    }
}
