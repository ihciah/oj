#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<int> num;
vector<string> st;
string x;
char c;
int i;
bool isstring;
bool iss[100000];
int run = 1;

bool le(string a, string b){
	transform(a.begin(), a.end(), a.begin(), ::tolower);
	transform(b.begin(), b.end(), b.begin(), ::tolower);
	return a < b;
}
void init(){
	i = 0; x = "";
	isstring = 1;
	st.clear(); num.clear();
}
void print(){
	sort(num.begin(), num.end());
	sort(st.begin(), st.end(), le);
	vector<string>::iterator sit=st.begin();
	vector<int>::iterator iit=num.begin();
	
	for (int l = 0; sit != st.end() || iit != num.end(); l++){
		if (iss[l])
			cout<<*sit++;
		else
			cout<<*iit++;
		if (sit == st.end() && iit == num.end())
			printf(".\n");
		else
			printf(", ");
	}
}
int main(){
	init();
	while (scanf("%c", &c)&&run){
		if (c == '\n')
			continue;
		if ((c >= '0'&&c <= '9') || c == '-')
			isstring = 0;
		if (x == ""&&c == '.'){
			run = 0;
			continue;
		}
		if ((c == '.'||c==',')&&x!=""){
			if (isstring){
				st.push_back(x);
				x = "";
				iss[i++] = 1;
			}
			else{
				num.push_back(atoi(x.c_str()));
				x = "";
				isstring = 1;
				iss[i++] = 0;
			}
		}
		else if (c != ' '&&c!=','&&c!='.'){
			x += c;
		}
		if (c == '.'){
			print();
			init();
		}

	}
	return 0;
}