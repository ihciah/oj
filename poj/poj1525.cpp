#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<pair<int, int>,int> p3;//target,from,jump
int data[35];
int ld[] = { 1, 4, 7, 14, 21, 28, 31 };
int nd[] = { 3, 3, 7, 7, 7, 3, 3 };
int lc[] = { 1, 2, 3, 7, 8, 12, 13 };
int nc[] = { 7, 7, 7, 3, 3, 3, 3 };
vector<p3> v;

inline int dleft(int s){return s - 1;}
inline int dright(int s){ return s + 1; }
inline int dup(int s){ 
	if (s >= 7 && s <= 13)
		return s - 5;
	else if (s >= 14 && s <= 27)
		return s - 7;
	else if (s >= 28 && s <= 30)
		return s - 5;
	else
		return s - 3;
}
inline int ddown(int s){
	if (s >= 4 && s <= 6)
		return s + 5;
	else if (s >= 7 && s <= 20)
		return s + 7;
	else if (s >= 21 && s <= 27)
		return s + 5;
	else
		return s + 3;
}

void findsuit(int start,int num,int t){
	int(*tl)(int s); int(*tr)(int s);
	if (t){
		tl = dup; tr = ddown;
	}
	else{
		tl = dleft; tr = dright;
	}
	for (int s = start, i = 0; i < num; i++, s = tr(s)){
		if (!data[s]){
			if (i >= 2 && data[tl(tl(s))] && data[tl(s)])
				v.push_back(p3(pair<int, int>(s, tl(tl(s))), tl(s)));
			if (i <num-2 && data[tr(tr(s))] && data[tr(s)])
				v.push_back(p3(pair<int, int>(s, tr(tr(s))), tr(s)));
		}
		
	}
}
bool le(p3 a, p3 b){return a>b;}
void calc(){
	v.clear();
	for (int i = 0; i < 7; i++)
		findsuit(ld[i], nd[i], 0);
	for (int i = 0; i < 7; i++)
		findsuit(lc[i], nc[i], 1);
	sort(v.begin(),v.end(),le);
	if (!v.empty()){
		data[v[0].first.first] = 1;
		data[v[0].first.second] = 0;
		data[v[0].second] = 0;
		calc();
	}
}
int main(){
	int num;
	cin >> num;
	cout << "HI Q OUTPUT" << endl;
	for (int i = 0; i < num;i++){
		memset(data, 0, sizeof(data));
		int p;
		while (cin >> p, p)
			data[p] = 1;
		calc();
		int sum = 0;
		for (int i = 1; i < 34; i++){
			sum += (data[i]==1?i:0);
		}
		cout << sum << endl;
	}
	cout << "END OF OUTPUT" << endl;
}