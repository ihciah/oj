#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int N,S;
	cin >> N >> S;
	vector<int> x;
	for (int i = 0; i < N; i++){
		int temp;
		cin >> temp;
		x.push_back(temp);
	}
	sort(x.begin(), x.end());
	
	int sum = 0;
	for (int i = 0; i < N; i++){
		if (x[i] * 2 > S)
			break;
		for (int j = i + 1; j < N; j++){
			if (x[i] + x[j] <= S)
				sum++;
			else
				break;
		}
	}
	cout << sum << endl;
}