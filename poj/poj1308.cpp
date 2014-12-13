#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <cstdlib>  
#include <algorithm>  
using namespace std;

const int maxn = 10000;
int father[maxn];
int into[maxn];
int flag[maxn];
bool istree; 

void InIt()
{
	for (int i = 1; i <= maxn; i++)
	{
		father[i] = i;
		into[i] = 0;
		flag[i] = 1;
	}
}

int find(int v)
{
	if (father[v] != v)
		father[v] = find(father[v]);
	return father[v];
}

void merge(int x, int y) //ºÏ²¢  
{
	int xf = find(x);
	int yf = find(y);
	if (xf == yf)
	{
		istree = 0;
		return;
	}
	father[xf] = yf;
}

int main()
{
	int x, y, t, n;
	t = 1;
	while (scanf("%d%d", &x, &y) != EOF)
	{
		istree = 1;
		n = 0;
		InIt();
		if (x < 0 || y < 0) return 0;
		if (x == 0 && y == 0)
		{
			cout << "Case " << t++ << " is a tree." << endl;
			continue;
		}
		do
		{
			if (x != y)
				into[y] = 1;
			if (flag[x] == 1)
			{
				n++;
				flag[x] = 0;
			}
			if (flag[y] == 1)
			{
				n++;
				flag[y] = 0;
			}
			merge(x, y);
		}while (scanf("%d%d", &x, &y), (x != 0 && y != 0));
		int sum = 0;
		for (int i = 1; i <= maxn; i++)
			sum += into[i];
		if (sum == n - 1 && istree)
			cout << "Case " << t++ << " is a tree." << endl;
		else
			cout << "Case " << t++ << " is not a tree." << endl;
	}

	return 0;
}