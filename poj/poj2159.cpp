#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


int main(){
	string as1, as2;
	cin >> as1 >> as2;
	if (as1.length() != as2.length()){
		cout << "NO";
		return 0;
	}
	int l = as1.length();
	int *data = new int[26];
	int *data2 = new int[26];
	vector<int> s1, s2;
	for (int i = 0; i < 26; i++){
		data[i] = 0; data2[i] = 0;
	}
	for (string::iterator x = as1.begin(); x < as1.end(); x++){
		data[*x - 'A']++;
	}
	for (string::iterator x = as2.begin(); x < as2.end(); x++){
		data2[*x - 'A']++;
	}
	for (int i = 0; i < 26; i++){
		s1.push_back(data[i]);
		s2.push_back(data2[i]);
	}
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	for (int i = 0; i < 26;i++)
		if (s1[i] != s2[i]){
		cout << "NO";
		delete[] data;
		return 0;
		}
	cout << "YES";
	delete[] data;
	return 0;
}