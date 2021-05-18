#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
#define maxn 520
#define maxq 1919810
int rd() {
    int k = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
char rd_ch() {
    char c = getchar();
    while (!isalpha(c)) c = getchar();
    return c;
}
void wr(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9)wr(x / 10);
    putchar(x % 10 + '0');
}

typedef struct queue {
    int a[maxq];
    int head, tail;
}queue;
void init_q(queue *q) {
    q->head = q->tail = 0;
}
void push(queue* q, int val) {
    q->a[q->tail++] = val;
}
int front(queue* q) {
    return q->a[q->head];
}
void pop(queue* q) {
    q->a[q->head++] = 0;
}
bool empty(queue* q) {
    return q->head == q->tail;
}

queue single;//single male

int t, n;
int u, v;

int f_see_m_rank[maxn][maxn];//(i, j) : rank of i-th female towards j-th male
int m_prefer_f[maxn][maxn];//(i, j) : the female who has j-th rank of i-th male

int wife[maxn], husband[maxn];
int nxt[maxn];

void engage(int male, int female) {
    int m = husband[female];//dissolve original engagement
    if (m) wife[m] = 0, push(&single, m);
    wife[male] = female, husband[female] = male;
}

char male_name[30], female_name[30];
int name_to_male[30], name_to_female[30];
int cmp(const void* p1, const void* p2) {
    char* a = (char*)p1, * b = (char*)p2;
    if (*a < *b)return -1;
    else if (*a > *b) return 1;
    else return 0;
}


int main() {

    t = rd();
    while (t--) {
        memset(male_name, 0, sizeof(male_name)), memset(female_name, 0, sizeof(female_name));
        memset(name_to_male, 0, sizeof(name_to_male)), memset(name_to_male, 0, sizeof(name_to_male));
        init_q(&single);
        n = rd();
        int i = 0, j = 0;
        for (i = 1; i <= n; ++i) male_name[i] = rd_ch(); 
        qsort(male_name + 1, n, sizeof(male_name[1]), cmp);
        for (i = 1; i <= n; ++i) name_to_male[male_name[i] - 'a' + 1] = i;
        for (i = 1; i <= n; ++i) female_name[i] = rd_ch(), name_to_female[female_name[i] - 'A' + 1] = i;

        //male
        for (i = 1; i <= n; ++i) {
            u = name_to_male[rd_ch() - 'a' + 1];
            for (j = 1; j <= n; ++j)
                m_prefer_f[u][j] = name_to_female[rd_ch() - 'A' + 1];
            nxt[u] = 1;
            wife[u] = 0;
            push(&single, u);
        }

        //female
        for (i = 1; i <= n; ++i) {
            u = name_to_female[rd_ch() - 'A' + 1];
            for (j = 1; j <= n; ++j)
                v = name_to_male[rd_ch() - 'a' + 1], f_see_m_rank[u][v] = j;
            husband[u] = 0;
        }

        while (!empty(&single)) {
            int male = front(&single); pop(&single);
            int female = m_prefer_f[male][nxt[male]++];//next prefer female of male
            //female hasn't paired yet or current male is better for female
            if (!husband[female]) engage(male, female);
            else if (f_see_m_rank[female][male] < f_see_m_rank[female][husband[female]]) engage(male, female);
            else push(&single, male);
        }
        while (!empty(&single)) pop(&single);
        for (i = 1; i <= n; ++i) putchar(male_name[i]), putchar(' '), putchar(female_name[wife[i]]), putchar('\n');
        if (t)putchar('\n');
    }
}
