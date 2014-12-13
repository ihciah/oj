#include<iostream>
#include<cstring>
#include<string>
using namespace std;

string preord, inord;

void po(int root, int left, int right){
	if (left > right)
		return;
	int i;
	for (i = left; i <= right&&preord[root] != inord[i]; i++);
	po(root + 1, left, i - 1);
	po(root + i - left + 1, i + 1, right);
	cout << preord[root];
}
int main(){
	while (cin >> preord >> inord){
		po(0, 0, preord.length() - 1);
		cout << endl;
	}
	return 0;
}