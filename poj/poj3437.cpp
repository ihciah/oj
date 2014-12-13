#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
string x;
int de(){
	int count = 0;
	int maxnum = 0;
	for (string::iterator it = x.begin(); it != x.end(); it++){
		if (*it == 'd'){
			count++;
			maxnum = max(maxnum, count);
		}
		else
			count--;
	}
	return maxnum;

}
int dfs(int left, int right){
	int times = 0; int count = 0; int last = left; int a = 0;
	if (right - left == 1)
		return 1;
	for (int i = left; i <= right; i++){
		if (x[i] == 'd')
			count++;
		else
			count--;
		if (count == 0&&i>last){
			if (i - last == 1)
				a = max(a, 1 + times++);
			else
				a = max((times++) + dfs(last + 1, i - 1)+1, a);
			last = i+1;
		}
	}
	return a;

}

int main(){
	int casenum = 1;
	while (cin >> x&&x!="#"){
		int adeepth = de();
		int bdeepth=dfs(0, x.length() - 1);
		cout << "Tree "<<casenum++<<": "<<adeepth<<" => "<<bdeepth << endl;
	}
	return 0;
}