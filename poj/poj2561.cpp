#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;
set<string> v;
vector<pair<string, string> > vec;

void dfs(const string &str) {
	for (vector<pair<string, string> >::iterator it = vec.begin(); it != vec.end(); ++it) {
		int pos = 0;
		while ((pos = str.find(it->first, pos)) != string::npos) {
			string next = str;
			next.replace(pos, it->first.size(), it->second);
			if (v.count(next) == 0) {
				v.insert(next);
				if (v.size() > 1000) throw "Too many.";
				dfs(next);
			}
			pos += it->first.size();
		}
	}
}

int main(){
	int mcount = 0;
	string so;
	cin >> so;
	so = so.substr(1, so.find('"', 1)-1);
	string s;
	v.insert(so);
	while (cin >> s && s!=""){
		int sec = s.find('"', 1);
		string br = s.substr(1, sec-1);
		string r = s.substr(sec + 4, s.length()-sec-5);
		vec.push_back(pair<string, string>(br,r));
	}
	
	try {
		dfs(so);
	}
	catch (const char *str) {}

	mcount = v.size();
	if (mcount > 1000)
		cout << "Too many." << endl;
	else
		cout << mcount << endl;
	return 0;
}