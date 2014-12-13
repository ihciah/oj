#include<iostream>
using namespace std;
#define MAXN 1000005
int cnt;
int a[MAXN], c[MAXN];
void MergeSort(int l, int r)
{
	int mid, i, j, tmp;
	if (r>l + 1)
	{
		mid = (l + r) / 2;
		MergeSort(l, mid);
		MergeSort(mid, r);
		tmp = l;
		for (i = l, j = mid; i<mid&&j<r;)
		{
			if (a[i]>a[j])
			{
				c[tmp++] = a[j++];
				cnt += mid - i;
			}
			else c[tmp++] = a[i++];
		}
		while (j<r)   c[tmp++] = a[j++];
		while (i<mid) c[tmp++] = a[i++];
		for (i = l; i<r; ++i)   a[i] = c[i];
	}
}
int main()
{
	int n, m, pl;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		if (n == 0 || m == 0)break;
		cnt = 0;
		pl = 0;
		int x, loc0;
		for (int i = 0; i < n*m; i++)
		{
			scanf("%d", &a[pl]);
			if (a[pl] == 0)
			{
				x = pl / m;
				loc0 = pl;
			}
			pl++;
		}
		MergeSort(0, pl);
		cnt -= loc0;
		int step = 0;
		if (m % 2 == 1)
			step = 0;
		else
			step = n - 1 - x;
		if (step % 2 == cnt % 2)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}