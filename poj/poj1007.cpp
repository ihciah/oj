#include<iostream>
#include<string>
#include<algorithm>
#include<set>
using namespace std;
int data[4];//A C G T
int sum;
void clear(){
	sum = 0;
	for (int i = 0; i < 4; i++){
		data[i] = 0;
	}
}
int main(){
	string s;
	multiset<pair<int, string> > v;
	int len, n;
	cin >> len >> n;
	for (int i = 0; i < n; i++){
		clear();
		string s;
		cin >> s;
		for (int j = 0; j < len; j++){
			if (s[j] == 'A'){
				data[0]++;
				sum = sum + data[1] + data[2] + data[3];
			}
			if (s[j] == 'C'){
				data[1]++;
				sum = sum + data[2] + data[3];
			}
			if (s[j] == 'G'){
				data[2]++;
				sum = sum + data[3];
			}
			if (s[j] == 'T'){
				data[3]++;
			}
		}
		v.insert(pair<int, string>(sum, s));
		
	}
	multiset<pair<int, string> >::iterator it=v.begin();
	for (; it != v.end(); it++){
		cout << it->second << endl;
	}
	return 0;
}