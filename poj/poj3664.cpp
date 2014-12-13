#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
	return a.first.second < b.first.second;
}
int main(){
	int num, y;
	cin >> num>>y;
	int tmp1, tmp2;
	vector<pair<pair<int, int>, int>> data;
	for (int i = 0; i < num; i++){
		cin >> tmp1 >> tmp2;
		data.push_back(pair<pair<int, int>,int>(pair<int,int>(tmp1, tmp2),i+1));
	}
	sort(data.begin(), data.end());
	sort(data.end() - y, data.end(), cmp);

	cout << data[data.size() - 1].second;
	return 0;
}