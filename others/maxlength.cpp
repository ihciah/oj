#include<iostream>
#include<cstring>
#include<algorithm>
//求二叉树中最长的两点距离
using namespace std;
class Node{
public:
	int left, right;
	Node(){ left = -1; right = -1;}
	Node(int l, int r) :left(l), right(r){}
};
Node t[10000];
int maxnum = 0;
int dfs(int no){
	int a = 0, b = 0;
	if (t[no].left != -1)
		a = 1+dfs(t[no].left);
	if (t[no].right != -1)
		b = 1+dfs(t[no].right);
	maxnum = max(maxnum, a + b);
	return max(a,b);
}
int main(){
	
	int a, b, c;
	int n;//node
	int m;//inputline
	cin >> n >> m;
	for (int k = 0; k < m;k++){
		cin >> a >> b >> c;
		t[a] = Node(b, c);
	}
	dfs(0);
	cout << maxnum << endl;
}