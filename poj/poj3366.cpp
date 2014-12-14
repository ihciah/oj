#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	map<string, string> ma;
	int n, m;
	cin >> n >> m;
	string x1, x2;
	while (n--){
		cin >> x1 >> x2;
		ma[x1] = x2;
	}
	while (m--){
		cin >> x1;
		if (ma.count(x1) == 1)
			cout << ma[x1] << endl;
		else{
			char x = x1[x1.length() - 1];
			char y = '1';
			if (x1.length() >= 2)
				y = x1[x1.length() - 2];
		if (x == 'y'&&x1.length() >= 2&&y!='a'&&y!='e'&&y!='i'&&y!='o'&&y!='u'){
				x1[x1.length() - 1] = 'i';
				cout << x1 << "es" << endl;
				continue;
			}
			if (x == 'o' || x == 's' || x == 'x'){
				cout << x1 << "es" << endl;
				continue;
			}
			if (x == 'h'&&x1.length() >= 2 && (y == 'c' || y == 's')){
				cout << x1 << "es" << endl;
				continue;
			}
			cout << x1 << "s" << endl;
		}
	}

	return 0;
}