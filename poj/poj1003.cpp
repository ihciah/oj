#include<iostream>

using namespace std;
int main(){
	double x,sum;
	int i;
	while (cin >> x,x!=0.0){
		for (sum = 0, i = 2; sum < x; sum += (1.0 / i), i++);
		cout << i - 2 << " card(s)" << endl;
	}
	return 0;
}