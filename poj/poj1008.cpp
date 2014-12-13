#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string ts[] = {"imix", "ik", "akbal", "kan", "chicchan",
"cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };
string v[] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu" };
int main(){
	int n;
	cin >> n;
	cout << n<<endl;
	for (int i = 0; i < n; i++){
		double x; cin >> x;
		int t = x;
		string s;cin >> s;
		int year;cin >> year;
		int j;
		for (j = 0; j < 18; j++)
			if (s == v[j])
				break;
		int days = j * 20 + year * 365 + t;
		int nyear = days / 260;
		int ndays = days % 260;
		int od = ndays % 13+1;
		int om = ndays % 20;
		cout << od << " " << ts[om] <<" "<<nyear<< endl;
	}
	
	return 0;
}