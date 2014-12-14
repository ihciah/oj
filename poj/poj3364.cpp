#include<cstdio>
int main(){
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c), a + b + c){
		int sum = (a - 7)*(b - 7);
		if (c)
			printf("%d\n", sum / 2 + sum%2);
		else
			printf("%d\n", sum / 2);
	}
	return 0;
}