#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int p, e, i, d,n;
	n = 1;
	while (cin >> p >> e >> i >> d, p != -1 && e != -1){
		int m;
		while(1){
			m = max(max(p, e), i);
			if (p < m) p += 23;
			if (e < m) e += 28;
			if (i < m) i += 33;
			if (p == e&&p == i)
				break;
		}
		m = max(max(p, e), i);
		for (; m > d; m -= 21252);
		m += 21252;
		cout << "Case "<<n<<": the next triple peak occurs in "<<m-d<<" days." << endl;
		n++;
	}
	return 0;
}