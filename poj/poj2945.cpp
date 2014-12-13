#include <cstdio>
#include <map>
#include <cstring>
using namespace std;
struct cmp{
	bool operator()(const char* a, const char* b){
		return strcmp(a, b) < 0;
	}
};


int main(){
	int a, b;
	char data[20000][21];
	int num[20000];

	map<char*, int, cmp> v;
	while (scanf_s("%d%d", &a, &b) && a&&b){
		v.clear();
		for (int i = 0; i < a; i++){
			scanf_s("%s", data[i], 24);
			v[data[i]]++;
		}
		memset(num, 0, sizeof(num));
		for (map<char*, int, cmp>::iterator i=v.begin();i!=v.end();i++){
			num[i->second-1]++;
		}
		for (int i = 0; i < a; i++)
		{
			printf("%d\n", num[i]);
		}
	}
	return 0;
}