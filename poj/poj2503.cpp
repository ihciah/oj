#include<cstdio>
#include<iostream>
#include<map>
#include<string>

using namespace std;
map<string, string> v;
int main(){
	char st[200];
	char s1[100], s2[100];
	while (gets(st),st[0]!=0){
		sscanf(st, "%s%s", s1, s2);
		v[string(s2)]=string(s1);
	}
	string s;
	map<string, string>::iterator it;
	while (cin>>s){
		it = v.find(s);
		if (it != v.end())
			cout << it->second << endl;
		else
			cout << "eh" << endl;
	}
	
	return 0;
}