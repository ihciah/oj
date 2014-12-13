#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comp(int a, int b){
	return abs(a)< abs(b);
}

int main(){
	int limit, num,temp;
	cin >> limit >> num;
	vector<int> data;
	for (int i = 0; i < num; i++){
		cin >> temp;
		data.push_back(temp);
	}
	sort(data.begin(),data.end(), comp);
	int node = 0;
	int sum = 0;
	int i;
	for (i = 0; sum <= limit&&i < data.size();i++){
		sum += abs(data[i] - node);
		node = data[i];
	}
	cout << i-1;
	return 0;
}