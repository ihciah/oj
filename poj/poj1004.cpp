#include<iostream>

using namespace std;
int main(){
	double sum = 0.0;
	for (int i = 0; i < 12; i++){
		double x;
		cin >> x;
		sum += x;
	}
	cout <<"$"<< (sum / 12.0) << endl;
	return 0;
}