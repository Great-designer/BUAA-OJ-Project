#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<vector>
#define maxn 1100
using namespace std;

struct Tree {
	char value;
	Tree* lchild, * rchild;
	Tree(char val = 0) {
		value = val;
		lchild = rchild = NULL;
	}
};
bool isTree;

Tree* getTree(vector<char>& preorder, vector<char>& inorder, int prebegin, int preend, int inbegin, int inend) {
	if (prebegin < preend && inbegin < inend) {
		Tree* rev = new Tree(preorder[prebegin]);
		vector<char>::iterator mid = find(inorder.begin() + inbegin, inorder.begin() + inend, preorder[prebegin]);
		if (mid == inorder.end()) {
			isTree = false; return NULL;
		}
		int offset = mid - (inorder.begin() + inbegin);
		/*
		前序遍历时，头结点如果可以在中序遍历找到的话（设为offset）
		那么
		头结点的左子树size为offset，右子树size为n-1-offset
		左子节点的
		前序遍历位置一定在begin+1
		中序遍历位置一定在begin
		右子节点的
		前序遍历位置一定在begin+offset+1
		中序遍历位置一定在begin+offset+1
		然后末尾位置就跟offset有关
		*/
		rev->lchild = getTree(preorder, inorder, prebegin + 1, prebegin + 1 + offset,
			inbegin, inbegin + offset);
		rev->rchild = getTree(preorder, inorder, prebegin + 1 + offset, preend,
			inbegin + offset + 1, inend);
		return rev;
	}
	else return NULL;
}

Tree* buildTree(vector<char>& preorder, vector<char>& inorder) {
	return getTree(preorder, inorder, 0, preorder.size(), 0, inorder.size());
}

void printBackOrder(Tree* t, vector<char>& v) {
	if (t->value <= 0)return;
	if (t->lchild)printBackOrder(t->lchild, v);
	if (t->rchild)printBackOrder(t->rchild, v);
	v.push_back(t->value);
}

Tree t, * ans;
vector<char>pre, in;
vector<char> v;
int n, tmp;
string a, b;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	pre.resize(maxn), in.resize(maxn), v.resize(maxn);
	while (cin >> a >> b) {
		n = a.length();
		pre.clear(), in.clear(), v.clear();
		for (int i = 0; i < n; ++i) {
			pre.push_back(a[i]);
		}
		for (int i = 0; i < n; ++i) {
			in.push_back(b[i]);
		}
		isTree = true;
		ans = buildTree(pre, in);

		printBackOrder(ans, v);
		if (ans == NULL || v.size() != n || !isTree)cout << "No" << endl;
		else {
			for (char a : v)cout << a;
			cout << endl;
		}
	}

}
