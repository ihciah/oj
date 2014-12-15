#include<cstdio>
#include<string.h>
using namespace std;
int tnext[1000005];
char str[1000005];
int main(){
	while (scanf("%s",str), strcmp(str,".")!=0){
		int len = strlen(str);
		tnext[0] = 0;
		for (int i = 1; i < len; i++){
			int t;
			t = tnext[i - 1];
			while (t&&str[i] != str[t])
				t = tnext[t - 1];
			if (str[i] == str[t])
				tnext[i] = t + 1;
			else
				tnext[i] = 0;
		}
		int ans;
		if (len % (len - tnext[len - 1]) == 0)
			ans = len / (len - tnext[len - 1]);
		else
			ans = 1;
		printf("%d\n",ans);
	}
	return 0;
}