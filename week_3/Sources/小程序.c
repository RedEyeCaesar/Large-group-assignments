#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>

//创建数组
int* CreatArray(int MAX,int*arr) {

    arr = (int*)malloc(sizeof(int) * MAX);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++) {

		int randNum = rand() % MAX;
		arr[i] = randNum;
	}
	return arr;
}

/*插入排序*/
void insertSort(int* a, int n) {
	int i, j, temp;
	for (i = 1; i < n; i++)
	{
		temp = a[i];
		j = i - 1;
		while ((j >= 0 && a[j] > temp))
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
}

/*归并排序（合并数组）*/
void MergeArray(int* a, int begin, int mid, int end, int* temp) {
	int i = begin, j = mid + 1;
	int k = 0;
	while (i <= mid && j <= end)
	{
		if (a[i] <= a[j])
		{
			temp[k++] = a[i++];
		}
		else
		{
			temp[k++] = a[j++];
		}
	}
	while (i <= mid)
	{
		temp[k++] = a[i++];
	}
	while (j <= end)
	{
		temp[k++] = a[j++];
	}
	for (i = 0; i < k; i++)
	{
		a[begin + i] = temp[i];
	}
}

/*归并排序*/
void MergeSort(int* a, int begin, int end, int* temp) {
	if (begin < end)
	{
		int mid = (begin + end) / 2;
		MergeSort(a, begin, mid, temp);
		MergeSort(a, mid + 1, end, temp);
		MergeArray(a, begin, mid, end, temp);
	}
}

/*快速排序*/
void QuickSort_Recursion(int* a, int begin, int end) {
	if (begin > end)
	{
		return;
	}
	int temp = a[begin];
	int i = begin, j = end;
	while (i != j)
	{
		while (a[j] >= temp && j > i)
		{
			j--;
		}
		while (a[i] <= temp && j > i)
		{
			i++;
		}
		if (j > i)
		{
			int k = a[i];
			a[i] = a[j];
			a[j] = k;
		}
	}
	a[begin] = a[i];
	a[i] = temp;
	QuickSort_Recursion(a, begin, i - 1);
	QuickSort_Recursion(a, i + 1, end);
}

/*计数排序*/
void CountSort(int* a, int size, int max) {
	assert(a);
	max = a[0];
	int min = a[0], i;
	for (i = 0; i < size; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int range = max - min + 1;
	int* temp = (int*)calloc(range, sizeof(int));
	for (i = 0; i < size; i++)
	{
		temp[a[i] - min] += 1;
	}
	int j = 0;
	for (i = 0; i < range; i++)
	{
		while (temp[i]--)
		{
			a[j++] = i + min;
		}
	}
	free(temp);
	temp = NULL;
}

/*基数排序*/
void RadixCountSort(int* a, int size) {

	int i, max = a[0], base = 1;
	for (i = 0; i < size; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	int* t = (int*)malloc(sizeof(int) * size);
	while (max / base > 0) {

		int bucket[10] = { 0 };
		for (i = 0; i < size; i++) {
			bucket[a[i] / base % 10]++;
		}
		for (i = 1; i < 10; i++) {
			bucket[i] += bucket[i - 1];
		}
		for (i = size - 1; i >= 0; i--) {
			t[bucket[a[i] / base % 10] - 1] = a[i];
			bucket[a[i] / base % 10]--;
		}
		for (i = 0; i < size; i++) {
			a[i] = t[i];

		}
		base = base * 10;
	}
}




void list() {
	printf("\t\t\t********************系统功能菜单****************************\n");
	printf("\t\t\t**********--------------------------------******************\n");
	printf("\t\t\t\t*********  0.退出系统      *****************\n");
	printf("\t\t\t\t*********  1.插入排序      *****************\n");
	printf("\t\t\t\t*********  2.归并排序      *****************\n");
	printf("\t\t\t\t*********  3.快速排序      *****************\n");
	printf("\t\t\t\t*********  4.计数排序      *****************\n");
	printf("\t\t\t\t*********  5.基数排序      *****************\n");
	printf("\t\t\t----------------------------------------------------\n");
	printf("\t\t\t请输入您的选择：");
}

int main() {
	list();
	int n,MAX=10000,*arr;
	void* t;
	clock_t start_time;
	do
	{
		scanf_s("%d",&n);
		switch (n)
		{
		case 0:printf("退出系统"); break;
		case 1:CreatArray(MAX, arr);
			clock_t start_time = clock();
			{
				insertSort(arr, 10000);
			}; break;
		case 2:int* temp;
			CreatArray(MAX, arr);
			clock_t start_time = clock();
			{
				MergeSort(arr, 0, 9999, temp);
			}; break;
		case 3: CreatArray(MAX, arr);
			clock_t start_time = clock();
			{
				QuickSort_Recursion(arr, 0, 9999);
			};  break;
		case 4:int max;
			CreatArray(MAX, arr);
			clock_t start_time = clock();
			{
				CountSort(arr, 10000, max);
			};  break;
		case 5: CreatArray(MAX, arr);
			clock_t start_time = clock();
			{
				RadixCountSort(arr, 10000);
			};  break;
		default:printf("error\a");
		}
	} while (n != 0);
		clock_t end_time = clock();
		printf("用时: %lfms\n", static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000);
		printf("\n");
		return 0;
	}

