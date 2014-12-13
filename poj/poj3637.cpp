#include<stdio.h>
#include <utility>
using namespace std;
int partition(int* array, int left, int right)
{
	int index = left;
	int pivot = array[index];
	swap(array[index], array[right]);
	for (int i = left; i<right; i++)
	{
		if (array[i] > pivot)
			swap(array[index++], array[i]);
	}
	swap(array[right], array[index]);
	return index;
}

void qsort(int* array, int left, int right)
{
	if (left >= right)
		return;
	int index = partition(array, left, right);
	qsort(array, left, index - 1);
	qsort(array, index + 1, right);
}
int main(){
	int num, count,tmp;
	int v[20001];
	scanf_s("%d",&num);
	for (int i = 0; i < num; i++){
		scanf_s("%d", &count);
		int sum = 0;
		for (int j = 0; j < count; j++){
			scanf_s("%d", &v[j]);
		}
		qsort(v,0, count-1);
		for (int i = 2; i < count; i+=3)
			sum += v[i];
		printf("%d\n", sum);
	}
	return 0;
}