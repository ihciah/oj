#include<iostream>
#include<math.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		double x, y;
		cin >> x >> y;
		double l = x*x + y*y;
		double s = 3.1415926*l / 2.0;
		int year = s / 50;
		cout << "Property " << i << ": This property will begin eroding in year " << year+1 << "."<<endl;
	}
	cout << "END OF OUTPUT." << endl;
	return 0;
}