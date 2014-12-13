#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
int **data2;
int **data;
int h, l;

bool findNeighbor(int &x, int &y, int dir){
	static const int dx[] = { -1, 0, 0, 1 };
	static const int dy[] = { 0, -1, 1, 0 };
	x += dx[dir]; y += dy[dir];
	if (x < 0) return false;
	if (y < 0) return false;
	if (x == h) return false;
	if (y == l) return false;
	return true;
}

int d(int x, int y){
	if (data2[x][y] != 0)
		return data2[x][y];
	int tt=1;
	for (int i = 0; i < 4; i++){
		int xx = x, yy = y;
		if (findNeighbor(xx, yy, i)){
			if (data[x][y] > data[xx][yy])
				tt= max(tt,d(xx, yy)+1);
		}
	}
	data2[x][y] = tt;
	return tt;
}
int main(){
	int tmp;
	cin >> h >> l;
	data = new int*[h];
	for (int i = 0; i < h; i++){
		data[i] = new int[l];
	}
	data2 = new int*[h];
	for (int i = 0; i < h; i++){
		data2[i] = new int[l];
	}

	for (int i = 0; i < h; i++){
		for (int j = 0; j < l; j++){
			cin >> tmp;
			data[i][j] = tmp;
			data2[i][j] = 0;
		}
	}
	int res=1;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < l; j++){
		res = max(res, d(i, j));
		}
	cout << res;
	return 0;
}