#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

int tnext[1000000];
int main(){
	int casenum = 1;
	string s;
	int len;
	while (cin >> len,len){
		cin >> s;
		cout << "Test case #" << casenum++ << endl;
		tnext[0] = 0;
		for (int i = 1; i < len; i++){
			int t;
			t = tnext[i - 1];
			while (t&&s[i] != s[t])
				t = tnext[t - 1];
			if (s[i] == s[t])
				tnext[i] = t + 1;
			else
				tnext[i] = 0;
		}
		for (int i = 1; i <= len; i++)
			if (tnext[i - 1] != 0 && i - tnext[i - 1] !=0 && i % (i - tnext[i - 1]) == 0)
				printf("%d %d\n", i, i / (i - tnext[i-1]));
		printf("\n");
	}
	return 0;
}