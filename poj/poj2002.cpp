#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

typedef pair<int, int> pa2;
typedef vector<pa2> vp;
int main(){
	int t;
	while (cin >> t, t){
		vp v;
		while (t--){
			int a; int b;
			cin >> a >> b;
			v.push_back(pa2(a, b));
		}
		sort(v.begin(), v.end());
		int mcount = 0;
		for (vp::iterator it = v.begin(); it != v.end(); it++){
			for (vp::iterator itt = it + 1; itt != v.end(); itt++){
				pa2 tmp1(it->second - itt->second + it->first, itt->first - it->first + it->second);
				pa2 tmp2(it->second - itt->second + itt->first, itt->first - it->first + itt->second);
				if (!binary_search(v.begin(), v.end(), tmp1))
					continue;
				if (!binary_search(v.begin(), v.end(), tmp2))
					continue;
				mcount++;
			}
		}
		cout << (mcount >> 1) << endl;
	}
	return 0;
}