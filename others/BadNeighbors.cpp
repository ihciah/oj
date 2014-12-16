#include<iostream>
#include<algorithm>
using namespace std;

void calc(const int* t,const int count){
	bool isodd = count % 2;
	int **mark = new int*[2];
	for (int i = 0; i < 2; i++)
		mark[i] = new int[count];
	int t1, t2,maxi;
	mark[0][0] = 0;
	mark[1][0] = t[0];
	for (int i = 1; i < count; i++){
		mark[0][i] = max(mark[0][i - 1], mark[1][i - 1]);
		mark[1][i] = mark[0][i - 1] + t[i];
	}
	//for (int i = 0; i < count; i++)
	//	cout << mark[0][i] << " " << mark[1][i] << endl;
	cout << max(mark[0][count - 1], mark[1][count - 1]);
}
int main(){
	int count;
	int* v;
	cin >> count;
	v=new int[count];
	for (int i = 0; i < count; i++)
		cin >> v[i];
	calc(v,count);
	return 0;
}