#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
struct st
{
	int val;
	int num;
};


map<int, int> ma;
vector<pair<int, int> > res;
int width;
int i;
st v[1005];


int getnum(int n){
	int res;
	for (res = 0; res < i; res++){
		if (v[res].num > n)
			break;
	}

	return v[res-1].val;
}
void cx(int n){
	if (n < 0||n>=i)
		return;
	int imax=0;
	int numn = getnum(n);
	if (n - width>0)
		imax = max(imax, abs(getnum(n - width) - numn));
	if (n-1>0)
		imax = max(imax, abs(getnum(n - 1) - numn));
	if (n + 1<i)
		imax = max(imax, abs(getnum(n + 1) - numn));
	if (n + width<i)
		imax = max(imax, abs(getnum(n + width) - numn));
	ma.insert(n, imax);
}
int main(){
	
	while (cin >> width, width){
		int val, num,coun=0;
		i = 0;
		while (cin >> val >> num, val&&num){
			v[i].val = val; v[i].num = coun;
			coun += num;
		}
		for (int j = 0; j < i; j++){
			int thw = v[j].num / width;
			int thc = v[j].num % width;

		}






	}
	return 0;
}