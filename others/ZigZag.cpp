#include<iostream>
#include<algorithm>
using namespace std;
//ZigZag
//动态规划
//http://community.topcoder.com/stat?c=problem_statement&pm=1259&rd=4493
int main(){
	int x,temp,temp2,maxi;
	cin >> x;
	int **a = new int*[2];
	for (int i = 0; i < 2; i++)
		a[i] = new int[x];
	int *p = new int[x];
	for (int i = 0; i < x; i++)
		cin >> p[i];
	//a:标记数组
	//p:数据数组
	for (int i = 0; i < x; i++){
		temp = 1;
		temp2 = 1;
		for (int j = 0; j < i; j++){
			if (p[i]>p[j])
			temp = max(temp,a[0][j]+1);
			if (p[i] < p[j])
			temp2 = max(temp2, a[1][j] + 1);
		}
		a[0][i] = temp2;
		a[1][i] = temp;
		maxi = max(temp, temp2);
	}
	cout << maxi;
	return 0;
}