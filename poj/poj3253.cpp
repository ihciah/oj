#include<iostream>
#include<set>
using namespace std;

int main(){
	long long num,tmp,sum=0;
	multiset<int>::iterator it;
	cin >> num;
	multiset<int> v;
	for (int i = 0; i < num; i++){
		cin >> tmp;
		v.insert(tmp);
	}
	while (v.size() >= 2){
		tmp = 0;
		it = v.begin();
		tmp += *it;
		v.erase(it);
		it = v.begin();
		tmp += *it;
		v.erase(it);
		v.insert(tmp);
		sum += tmp;
	}
	cout << sum << endl;
	return 0;
}