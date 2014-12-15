#include<iostream>
#include<string>
#include<deque>
using namespace std;
int tnext[400005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	while (cin >> s){

		int len = s.length();
		tnext[0] = 0;
		for (int i = 1; i < len; i++){
			int t;
			t = tnext[i - 1];
			while (t&&s[i] != s[t])
				t = tnext[t - 1];
			if (s[i] == s[t])
				tnext[i] = t + 1;
			else
				tnext[i] = 0;
		}
		//KMP真的忘完了

		int t;
		t = len;
		deque<int> deq;
		while (t != 0){
			deq.push_back(t);
			t = tnext[t - 1];
		}
		cout << deq.back();
		deq.pop_back();
		while (!deq.empty()){
			cout << " " << deq.back();
			deq.pop_back();
		}
		cout << endl;

	}

	return 0;
}