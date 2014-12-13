#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int v[5845];
int main(){
	v[1] = 1;
	int m2 =1, m3=1, m5 =1, m7 = 1;
	int n2, n3, n5, n7,m;
	string s;
	for (int i = 2; i < 5845; i++){
		n2 = v[m2] * 2;
		n3 = v[m3] * 3;
		n5 = v[m5] * 5;
		n7 = v[m7] * 7;
		m = min(min(n2, n3), min(n7, n5));
		v[i] = m;
		if (m == n2) {
			m2++;
		}
		if (m == n3) {
			m3++;
		}
		if (m == n5) {
			m5++;
		}
		if (m == n7) {
			m7++;
		}
	}
	while (cin >> m, m){
		if (m % 10 == 1 && m % 100 != 11)
			s = "st";
		else if (m % 10 == 2 && m % 100 != 12)
			s = "nd";
		else if (m % 10 == 3 && m % 100 != 13)
			s = "rd";
		else s = "th";
		cout << "The " << m << s << " humble number is " << v[m] << "." << endl;
	}
	return 0;
}