#include<iostream>
#include<algorithm>
#include<set>
#include<iterator>
using namespace std;
typedef pair<int, char> p;
multiset<p> data;
int main(){
	int n;
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++){
		cin >> a >> b;
		data.insert(p(a, 'a'));
		data.insert(p(b, 'b'));
	}
	multiset<pair<int, char> >::iterator it;
	int anum = 0;
	int astart = 0;
	for (it = data.begin(); it != data.end(); it++){
		if (it->second == 'a'){
			if (anum == 0)
				astart = it->first;
			anum++;
		}
		else if (it->second == 'b'){
			anum--;
			if (anum == 0){
				cout << astart << " " << it->first << endl;
			}
		}
	}
	
	return 0;
}