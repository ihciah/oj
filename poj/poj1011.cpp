#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cstring>

using namespace std;
vector<int> v;
bool vis[51];
int sum,i,pnum;
int flag = 0;

bool le(int a, int b){
	return a > b;
}
void dfs(int now,int need,int nowpos){
	if (need == 0){
		need = i; now += 1; nowpos = 0;
	}
	if (now == pnum)
		flag = i;
}
int main(){
	int o;
	while (cin >> o, o){
		v.clear();
		int m;
		sum=0;
		while (o--){
			cin >> m;
			v.push_back(m);
			sum += m;
		}
		sort(v.begin(), v.end(),le);
		for (i = *(v.cend()); i < 50;i++){
			if (sum%i == 0){
				pnum = sum / i;
				memset(vis, 0, sizeof(vis));
				dfs(0,i,0);
				
			}
		}
	}
	return 0;
}