#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define maxn 500050
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
typedef long long ll;
const ll INF = 1145141919810ll;
inline void write(ll x) {
    if (x < 0)putchar('-'), x = -x;
    if (x > 9)write(x / 10);
    putchar(x % 10 + 48);
}
inline ll read() {
    ll k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
inline char readOP() {
    char c = getchar();
    while (!isalpha(c))c = getchar();
    return c;
}
struct AVL {
    struct AVLNode {
        int lchild, rchild, parent;//仨指针, 然而parent其实用不上
        ll value;//树的值,永不更新
        int height;//树的高度
        int size;//子树
    }nodes[maxn];
    int avl_size;//AVL节点个数
    int avl_root;//当前根节点的下标
    AVL() {
        avl_size = avl_root = 0;
        //memset(nodes, 0, sizeof(nodes));
    }
    inline void newNode(int& now, ll val) {
        nodes[now = ++avl_size].value = val;
        nodes[avl_size].size = 1;
    }
    inline void update(int& now) {//更新节点高度和子树规模
        nodes[now].size = nodes[nodes[now].lchild].size + nodes[nodes[now].rchild].size + 1;
        nodes[now].height = max(nodes[nodes[now].lchild].height, nodes[nodes[now].rchild].height) + 1;
    }
    inline int BalFac(int now) {
        return nodes[nodes[now].lchild].height - nodes[nodes[now].rchild].height;
    }
    inline void zag(int& now) {//以now为中心左旋
        int rchild = nodes[now].rchild;
        nodes[now].rchild = nodes[rchild].lchild;
        nodes[rchild].lchild = now;
        now = rchild;
        update(nodes[now].lchild);
        update(now);
    }
    inline void zig(int& now) {//以now为中心右旋
        int lchild = nodes[now].lchild;
        nodes[now].lchild = nodes[lchild].rchild;
        nodes[lchild].rchild = now;
        now = lchild;
        update(nodes[now].rchild);
        update(now);
    }
    inline void rebalance(int& now) {//根据平衡因子做重平衡调整
        //如果失衡了,那就根据对应子树的平衡因子单旋双旋
        int fac = BalFac(now);
        if (fac > 1) {
            int lchild_fac = BalFac(nodes[now].lchild);
            if (lchild_fac > 0)zig(now);//单旋
            else zag(nodes[now].lchild), zig(now);//双旋
        }
        else if (fac < -1) {
            int rchild_fac = BalFac(nodes[now].rchild);
            if (rchild_fac < 0)zag(now);//单旋
            else zig(nodes[now].rchild), zag(now);//双旋
        }
        else if (now)update(now);
    }
    inline void insert(int& now, ll val) {//AVL树插入,性质同BST
        //本题默认是左子树小于自己,右子树大于等于自己
        if (!now)newNode(now, val);
        else if (val < nodes[now].value)insert(nodes[now].lchild, val);
        else insert(nodes[now].rchild, val);
        rebalance(now);
    }
    inline int find(int& now, int pre) {//AVL查找元素,性质同BST
        int ret = 0;//没找到
        if (!nodes[now].lchild) {
            ret = now;
            nodes[pre].lchild = nodes[now].rchild;
        }
        else {
            ret = find(nodes[now].lchild, now);
            rebalance(now);
        }
        return ret;
    }
    inline void Delete(int& now, ll val) {//AVL删除元素,性质同BST
        if (val == nodes[now].value) {
            //命中情况,根据单分支和双分支的情况删除
            int lchild = nodes[now].lchild, rchild = nodes[now].rchild;
            if (!lchild || !rchild)now = lchild + rchild;
            else {
                now = find(rchild, rchild);
                if (now != rchild)nodes[now].rchild = rchild;
                nodes[now].lchild = lchild;
            }
        }
        else if (val < nodes[now].value)Delete(nodes[now].lchild, val);
        else Delete(nodes[now].rchild, val);
        rebalance(now);
    }
    inline int get_rank_by_num(ll val) {
        //重复元素排名的话默认找最小的
        int now = avl_root, rank = 1;
        while (now) {
            if (val <= nodes[now].value) now = nodes[now].lchild;
            else {
                //比该节点以及其左子树的点都要大
                rank += nodes[nodes[now].lchild].size + 1;
                now = nodes[now].rchild;
            }
        }
        return rank;
    }
    inline ll get_num_by_rank(int rank) {
        int now = avl_root;
        while (now) {
            //左子树+自身正好是rank,则命中，大了则往左子树找,削了就减掉这些往右子树找
            if (nodes[nodes[now].lchild].size + 1 == rank) break;
            else if (nodes[nodes[now].lchild].size >= rank) now = nodes[now].lchild;
            else rank -= (nodes[nodes[now].lchild].size + 1), now = nodes[now].rchild;
        }
        return nodes[now].value;
    }
    inline ll lower_bound(ll x) {
        return get_num_by_rank(get_rank_by_num(x) - 1);
    }
    inline ll upper_bound(ll x) {
        return get_num_by_rank(get_rank_by_num(x + 1));
    }
    inline void Insert(ll x) {
        insert(avl_root, x);
    }
    inline void Remove(ll x) {
        Delete(avl_root, x);
    }
    inline ll min_val() {
        return upper_bound(-INF);
    }
    inline ll max_val() {
        return lower_bound(INF);
    }
};

AVL Tree;
int n;
int op, x;
ll v;
ll sum;
ll size;
int main() {
    sum = v = read();
    n = read();
    Tree.Insert(INF), Tree.Insert(-INF);
    Tree.Insert(v), ++size;
    //这里不存在查找失败的结果,所以可以有6这种骚操作
    for (int i = 1; i <= n; ++i) {
        op = read();
        if (op == 1) {
            ll add = Tree.min_val(), after = min(add << 1, v);
            //printf("add is %lld  after is %lld\n", add, after);
            sum -= add, sum += after;
            Tree.Remove(add), Tree.Insert(after);
            printf("Day %d: %lld\n", i, sum);
        }
        else if (op == 2) {
            if (!sum) { printf("Day %d: Such beautiful flowers, what a pity!\n", i); continue; }
            ll drink = Tree.max_val();
            sum--;
            if(drink)Tree.Remove(drink), --size; if (drink > 1 || size == 0) Tree.Insert(drink - 1), ++size;
            printf("Day %d: %lld\n", i, sum);
        }
        else {
            Tree.Insert(v); ++size;
            while (Tree.min_val() == 0) Tree.Remove(0), --size;
            sum += v;
            printf("Day %d: %lld\n", i, sum);
        }
    }
}