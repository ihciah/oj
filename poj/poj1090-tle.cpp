#include<iostream>
using namespace std;
#define MAXN 1005
int n;
int data[MAXN];
int step = 0;
void change(int);
void changetop(int m){
	//��ǰmλ���m-1��0��1��1
	if (m == 0)
		return;
	else if (m == 1){
		if (data[1] == 0){
			step++;
			data[1] = 1;
		}
	}
	else{
		changetop(m - 1);
		if (data[m] == 0){
			step++;
			data[m] = 1;
		}
		change(m - 1);
	}
}

void change(int m){
	//�ı��mλΪ0
	if (data[m] == 0)
		return;
	else{
		changetop(m - 1);
		step++;
		data[m] = 0;
	}
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> data[i];
	}
	for (int i = n; i > 0; i--){
		change(i);
	}
	cout << step<<endl;
	return 0;
}