#include<cstdio>  
#include<cstring>  
#include<iostream>  
#include<algorithm>  
using namespace std;
const int maxn = 1e5 + 1000;
int a[maxn], n, m, ans;
bool test(int val)
{
	int cnt = 0;
	for (int i = 0; i<n; i++)
	{
		cnt += n - (lower_bound(a, a + n, a[i] + val) - a);
	}
	return cnt>m;
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		m = n*(n - 1) / 4;
		ans = -1;
		for (int i = 0; i<n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		int l = 0, r = a[n - 1] - a[0];
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (test(mid))
			{
				ans = mid;
				l = mid + 1;
			}
			else
				r = mid - 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}