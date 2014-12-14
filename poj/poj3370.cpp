#include<cstdio>
#include<cstring>
int tag[100005];
int main(){
	int a, b;
	while (scanf("%d%d",&a,&b), a!=0){
		int sum = 0;
		int tmp;
		int ans1=-1, ans2=-1;
		memset(tag, 0, sizeof(tag));
		for (int i = 1; i <= b;i++){
			scanf("%d",&tmp);
			if (ans1 != -1)
				continue;
			sum = (sum+tmp)%a;
			if (sum == 0){
				ans1 = 1; ans2 = i;
			}
			if (tag[sum] == 0){
				tag[sum] = i;
			}
			else{
				ans1 = tag[sum] + 1;
				ans2 = i;
			}
		}
		for (int i = ans1; i < ans2; i++)
			printf("%d ", i);
		printf("%d\n",ans2);
	}
	return 0;
}