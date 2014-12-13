#include<iostream>
#include<set>
using namespace std;
int main(){
	int t;
	while (cin >> t, t--){
		int k; cin >> k;
		int last = k; cout << k << " ";
		while (t--){
			cin >> k;
			if (last != k){
				cout << k << " ";
				last = k;
			}
		}
		cout << "$" << endl;
	}
	return 0;
}