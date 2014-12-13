//naive!


#include<iostream>
#include<string>
#include<set>
using namespace std;

string s1,s2;
set<int> sw[31];
int alc;
int co;

void swit(int n){
	for (set<int>::iterator it = sw[n].begin(); it != sw[n].end(); it++){
		if (s1[*it] == '1')
			s1[*it] = '0';
		else
			s1[*it] = '1';
	}
	if (s1[n] == '1')
		s1[n] = '0';
	else
		s1[n] = '1';
}
void dfs(int n){
	if (n == co){
		if (s1 == s2)
			alc++;
		return;
	}
	else{
		dfs(n + 1);
		swit(n);
		dfs(n + 1);
		swit(n);
	}
}
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		alc = 0;
		cin >> co;
		s1 = ""; s2 = "";
		for (int j = 0; j < co; j++){
			char temp;
			cin >> temp;
			s1 += temp;
		}
		for (int j = 0; j < co; j++){
			char temp;
			cin >> temp;
			s2 += temp;
		}
		int tmp1, tmp2;
		while (cin >> tmp1 >> tmp2, tmp1&&tmp2){
			sw[tmp1 - 1].insert(tmp2 - 1);
		}
		dfs(0);
		if (alc != 0)
			cout << alc << endl;
		else
			cout << "Oh,it's impossible~!!" << endl;
	}
	return 0;
}