#include<iostream>
#include<vector>
using namespace std;
//题目要求：输入两个数a,b
//1~a中选择任意个数字使和为b
//输出所有可能
void choose(int under, int sum, vector<int> &s){
	if (sum == 0){
		for (int i = 0; i < s.size(); i++)
			cout << s[i]<<" ";
		cout << endl;
		return;
	}
	if (sum >= under){
		if (under >= 1){
			s.push_back(under);
			choose(under - 1, sum - under,s);
			s.pop_back();
		}
		else
			return;
	}
	if (sum>0&&under>=1)
		choose(under - 1, sum,s);
}
int main(){
	int m, n;
	cin >> m >> n;
	vector<int> s;
	choose(m, n,s);
	return 0;
}