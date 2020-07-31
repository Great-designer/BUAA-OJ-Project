#include<stdio.h>
#include<string.h>

struct Trie
{
    int tot,root,child[510000][26];
    int cnt[510000];
};

void clear(struct Trie *a)
{
    memset(a->child[1],0,sizeof(a->child[1]));
    memset(a->cnt,0,sizeof(a->cnt));
    a->root=a->tot=1;
}

void insert(const char *str,struct Trie *a)
{
    int *cur=&a->root;
    const char *p;
    for(p=str;*p;++p)
    {
        cur=&a->child[*cur][*p-'a'];
        if (*cur==0)
        {
            *cur=++a->tot;
            memset(a->child[a->tot],0,sizeof(a->child[a->tot]));
        }
        a->cnt[*cur]++;
    }
}

struct Trie S,T;

int n;
char s[1100000];
int ans;

void dfs(int x,int y)
{
    ans+=(S.cnt[x]<T.cnt[y]?S.cnt[x]:T.cnt[y]);
    int i;
    for(i=0;i<26;i++)
    {
        if (S.cnt[S.child[x][i]]!=0&&T.cnt[T.child[y][i]]!=0)
		{
			dfs(S.child[x][i],T.child[y][i]);
		}
    }
}

int main()
{
    while (scanf("%d",&n)==1)
    {
        clear(&S);
        clear(&T);
        int i;
        for(i=1;i<=n;i++)
        {
            scanf("%s",s);
            insert(s,&S);
        }
        for(i=1;i<=n;i++)
        {
            scanf("%s",s);
            insert(s,&T);
        }
        ans=0;
        dfs(1,1);
        printf("%d\n",ans);
    }
    return 0;
}

