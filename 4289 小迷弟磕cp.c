#include<stdio.h>
#include<stdlib.h>

int m, n, t, cnt = 0;

struct CP
{
	int a,b;
};

struct CP cp[33000],tmp;

int cmp(const void *x, const void *y)
{
	struct CP *p1 = (struct CP *)x,*p2 = (struct CP *)y;
	if(p1->a > p2->a) return 1;//比较第一关键字 按照升序排列
	else if(p1->a < p2->a) return -1;
	else if(p1->b > p2->b) return 1;//第一关键字相同 按第二关键字升序排列
	else if(p1->b < p2->b) return -1;
	return 0;//不然双方一样大 返回0
}

int main()
{
	int i;
	scanf("%d%d%d",&n,&t,&m);
	for(i = 0; i < m; i ++) scanf("%d%d", &cp[i].a, &cp[i].b);//把人们要磕的cp放到结构体里
	qsort(cp, m, sizeof(cp[0]), cmp);//按照上述比较函数排序
	for(i = 0; i < m; i ++)
	{
		if(cp[i].a == cp[i + 1].a && cp[i].b == cp[i + 1].b) continue;//注意有重复 像样例中的1 2只找一次就可以了所以重复的要continue
		tmp.a = cp[i].b,tmp.b = cp[i].a;//从同样的数组中找它倒过来的 如果找到了就是人们想磕的
		if(bsearch(&tmp, cp, m, sizeof(cp[0]), cmp) != NULL) cnt++;//结构体也是可以用库函数二分找到的~
	}
	printf("%d",cnt>>1);//比如1 2和2 1都有过 1 2找到了2 1   2 1也找到了1 2  所以要对半输出
	return 0;
}