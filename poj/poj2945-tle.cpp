#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
vector<pair<string, int>> v;

bool cmp(pair<string, int> a, pair<string, int> b){
	return a.second < b.second;
}
void addcount(const string &st){
	int left = 0;
	int right = v.size() - 1;
	while (left <= right)
	{
		int middle = left + ((right - left) >> 1);
		if (v[middle].first>st)
		{
			right = middle - 1;
		}
		else if (v[middle].first<st)
		{
			left = middle + 1;
		}
		else{
			v[middle].second += 1; 
			return;
		}
	}
	int s = v.size(); int o = 0;
	for (o = 0; o < s&&v[o].first < st; o++);
	v.insert(v.begin() + o, pair<string, int>(st, 1));
}
int main(){
	int a, b;
	char tmp[25];
	string st;
	while (scanf_s("%d%d", &a, &b) && a&&b){
		v.clear();
		for (int i = 0; i < a; i++){
			scanf_s("%s", tmp,24);
			st = string(tmp);
			addcount(st);
		}
		vector<int> tempv;
		for (int d = 0; d < v.size(); d++)
			tempv.push_back(v[d].second);
		sort(tempv.begin(), tempv.end());
		int mp = 0, l;
		int si = tempv.size();
		for (int p = 0; p < a;p++){
			for (l = mp; l<si&&tempv[l] == p + 1; l++);
			cout << l - mp << endl;
			mp = l;
		}
	}
	return 0;
}