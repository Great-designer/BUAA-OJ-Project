#include<cstdio>
#define maxn 1010
struct Tree {
	char value;
	Tree* lchild,* rchild;
	Tree(Tree* l = NULL, Tree* r = NULL, char a = '\0') {
		value = a;
		lchild = l;
		rchild = r;
	}
};
char input[maxn];
int index;
int n;
void createBinTree(Tree*& t) {
	++index;
	if (input[index] == '\0')return;
	if (input[index] != '#') {
		t = new Tree;
		t->value = input[index];
		createBinTree(t->lchild);
		createBinTree(t->rchild);
	}
	else t = NULL;
}
int height(Tree* t) {
	if (t == NULL)return 0;
	else {
		int l = height(t->lchild);
		int r = height(t->rchild);
		return (l < r) ? r + 1 : l + 1;
	}
}
Tree* root;
int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%s", input + 1);
		index = 0;
		createBinTree(root);
		printf("%d\n", height(root));
	}
}
