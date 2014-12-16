#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.second > b.second;
}

int main(){
	int n;
	while (cin >> n, n){
		vector<pair<int, int> > v1, v2;
		for(int i=0;i<n;i++){
			int t1, t2;
			cin >> t1 >> t2;
			if (t1 < t2)
				v1.push_back(pair<int, int>(t1, t2));
			else
				v2.push_back(pair<int, int>(t1, t2));
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end(), cmp);
		int t1=0, t2=0;
		for (vector<pair<int, int> >::iterator it = v1.begin(); it != v1.end(); it++){
			t1 += it->first;
			t2 = max(t2, t1) + it->second;
		}
		for (vector<pair<int, int> >::iterator it = v2.begin(); it != v2.end(); it++){
			t1 += it->first;
			t2 = max(t2, t1) + it->second;
		}
		cout << t2 << endl;

	}
	return 0;
}