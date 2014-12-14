#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<deque>
using namespace std;
struct Node {
	char c;
	struct Node *lc, *rc;
} *root, nodes[10010];
deque<Node*> deq;
deque<char> res;
bool islower(char c){
	return (c >= 'a'&&c <= 'z');
}
void out(){
	while (!res.empty()){
		cout << res.back();
		res.pop_back();
	}
}
void bfs(){
	while (!deq.empty()){
		Node* t = deq.front();
		deq.pop_front();
		res.push_back(t->c);

		if (t->lc != NULL){
			deq.push_back(t->lc);
			deq.push_back(t->rc);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--){


		string s;
		cin >> s;
		int nu=0;//nodes当前下标
		stack<Node*> stac;
		deq.clear();
		res.clear();
		for (string::iterator it = s.begin(); it != s.end(); it++){
			if (islower(*it)){
				nodes[nu].c = *it;
				nodes[nu].lc = nodes[nu].rc = NULL;
				stac.push(&nodes[nu]);
				nu++;
			}
			else{
				nodes[nu].rc = stac.top();
				stac.pop();
				nodes[nu].lc = stac.top();
				stac.pop();
				nodes[nu].c =*it;
				stac.push(&nodes[nu]);
				nu++;
			}
		}
		root = &nodes[--nu];
		deq.push_back(root);
		bfs();
		out();
		cout << endl;
	}
	return 0;
}