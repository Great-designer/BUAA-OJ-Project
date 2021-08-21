#include<cstdio>

#include<set>
#include<vector>
#include<algorithm>

using namespace std;

struct Node
{
    int val;
    int link[2], par;
};

struct Node node[200005];

struct splaytree
{
    int root;
};

void rotate(int n)
{
    int p = node[n].par;
    int d = (node[node[n].par].link[0] != n);
    node[p].link[d] = node[n].link[!d];
    if (node[n].link[!d])
    {
        node[node[n].link[!d]].par = p;
    }
    node[n].par = node[p].par;
    if (node[p].par)
    {
        node[node[p].par].link[node[node[p].par].link[0] != p] = n;
    }
    node[n].link[!d] = p;
    node[p].par = n;
}

void splay(struct splaytree *a, int x, int f)
{
    if (x == f)
    {
        return;
    }
    for (; node[x].par != f; rotate(x))
    {
        if (node[node[x].par].par != f)
        {
            if ((node[node[x].par].link[0] != x) == (node[node[node[x].par].par].link[0] != node[x].par))
            {
                rotate(node[x].par);
            }
            else
            {
                rotate(x);
            }
        }
    }
    if (f == 0)
    {
        a->root = x;
    }
}

int erase_end(struct splaytree *a, int v)
{
    int n = a->root, l = 0, r = 0;
    while (n)
    {
        if (node[n].val >= v)
        {
            r = n;
            n = node[n].link[0];
        }
        else
        {
            l = n;
            n = node[n].link[1];
        }
    }
    if (r == 0)
    {
        return 0;
    }
    else if (l == 0)
    {
        int tmp = a->root;
        a->root = 0;
        return tmp;
    }
    else
    {
        splay(a, l, 0);
        splay(a, r, l);
        node[r].par = 0;
        node[l].link[1] = 0;
        return r;
    }
}

int max_element(int n)
{
    if (!node[n].link[1])
    {
        return n;
    }
    else
    {
        return max_element(node[n].link[1]);
    }
}

int back(struct splaytree *a)
{
    int v = max_element(a->root);
    splay(a, v, 0);
    return v;
}

void push_back(struct splaytree *a, int n)
{
    splay(a, max_element(a->root), 0);
    node[a->root].link[1] = n;
    node[n].par = a->root;
}

void printsplaytree(int n)
{
    if (node[n].link[0])
    {
        printsplaytree(node[n].link[0]);
    }
    printf("%d ", node[n].val);
    if (node[n].link[1])
    {
        printsplaytree(node[n].link[1]);
    }
}

splaytree A[200005];
set<int> X;
int D[200005];

void print(int t)
{
    printf("%d\n", t);
    for (int c : X)
    {
        printf("%d : ", c);
        printsplaytree(A[c].root);
        printf("\n");
    }
}

bool cmp(pair<int, struct splaytree> c, int l)
{
    return c.first > l;
}

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", D + i);
    }
    for (int i = 1; i <= N; i++)
    {
        node[i].val = i;
    }
    vector<pair<int, struct splaytree>> L;
    for (int i = 1; i <= N; i++)
    {
        int d = lower_bound(L.begin(), L.end(), D[i], cmp) - L.begin();
        if (L.size() == d)
        {
            node[D[i]].val = D[i];
            splaytree tmp;
            tmp.root = D[i];
            L.emplace_back(D[i], tmp);
        }
        else
        {
            push_back(&L[d].second, D[i]);
            L[d].first = D[i];
        }
    }
    for (pair<int, struct splaytree> c : L)
    {
        X.insert(c.first);
        swap(A[c.first], c.second);
    }
    int t, mx = N;
    for (t = 0; X.size() > 1; t++)
    {
        int cur = *X.rbegin();
        splaytree lst = A[cur];
        while (lst.root && back(&lst) == mx)
        {
            erase_end(&lst, mx--);
        }
        X.erase(cur);
        while (lst.root)
        {
            int en = back(&lst), st;
            auto it = X.lower_bound(en);
            if (it != X.begin())
            {
                st = *prev(it);
            }
            else
            {
                break;
            }
            int v = erase_end(&lst, st);
            push_back(&A[st], v);
            int tmp = back(&A[st]);
            X.erase(st);
            X.insert(tmp);
            swap(A[st], A[tmp]);
        }
        if (lst.root)
        {
            int tmp = back(&lst);
            swap(A[tmp], lst);
            X.insert(tmp);
        }
    }
    printf("%d\n", t);
}
