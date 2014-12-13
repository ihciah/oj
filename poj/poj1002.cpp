#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;


int main(){
	int fl = 1;
	char m[256];
	for (int i = 0; i < 255; i++)
		m[i] = i;
	m['A'] = m['B'] = m['C'] = '2';
	m['D'] = m['E'] = m['F'] = '3';
	m['G'] = m['H'] = m['I'] = '4';
	m['J'] = m['K'] = m['L'] = '5';
	m['M'] = m['N'] = m['O'] = '6';
	m['P'] = m['R'] = m['S'] = '7';
	m['T'] = m['U'] = m['V'] = '8';
	m['W'] = m['X'] = m['Y'] = '9';
	int n;
	cin >> n;
	map<string,int> v;
	string s,s2;
	for (int i = 0; i < n; i++){
		cin >> s;
		s2 = "";
		for (int j = 0; j < s.length(); j++){
			if (s[j] != '-')
				s2 += m[s[j]];
		}
		s2.insert(3, "-");
		++v[s2];
	}
	for (map<string,int>::iterator it=v.begin(); it!=v.end(); it++)
		if (it->second != 1){
			cout << it->first << " " << it->second << endl;
			fl = 0;
		}
	if (fl)
		cout << "No duplicates." << endl;
	return 0;
}