#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

string s1, s2;
int m;
int countv[30];
void countSons(int curPrePos, int curPostPos, int endPrePos)
{
	if (curPrePos == endPrePos)
		return;
	int pPre = curPrePos + 1, postP;
	char c;
	while (pPre <= endPrePos)
	{
		c = s1[pPre];
		countv[curPrePos]++;
		postP = curPostPos;
		while (s2[postP] != c) postP++;
		countSons(pPre, curPostPos, pPre + (postP - curPostPos));
		pPre = pPre + (postP - curPostPos) + 1;
		curPostPos = postP + 1;
	}
}
long long getC(int n){
	long long r = 1,tm=m,tr=1;
	for (int i = n; i >= 1; i--){
		r *= tm--;
	}
	for (int i = n; i >= 1; i--){
		tr*=i;
	}
	return r/tr;
}
int main(){
	
	while (cin >> m&&m){
		cin >> s1 >> s2;
		memset(countv, 0, sizeof(countv));
		countSons(0, 0, s1.length() - 1);
		long long r = 1;
		for (int i = 0; i < 30; i++)
			r *= getC(countv[i]);
		cout << r << endl;
	}
	return 0;
}


