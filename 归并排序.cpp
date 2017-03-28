//王辉
//20170322上传
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
void Mergepass(int *initList, int *MergeList, int n, int  s);// 迭代归并声明
void Merge(int *initList, int *MergeList, int left, int mid, int right);//二路归并声明


//二路归并
//将两个有序的序列initList[left,mid]和initList[mid+1,right]归并到一个新数组d[10]中MergeList
void Merge(int *initList, int *MergeList, int left, int mid, int right)
{         //未排序的数组       新数组        最左边    中间       最右边
	int i, j, k;//i,j,k都是下标
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid&&j <= right)
	{
		if (initList[i] < initList[j])
			MergeList[k++] = initList[i++];//把下标为i的元素复制到新数组中，并且都++
		else
			MergeList[k++] = initList[j++];//把下标为j的元素复制到新数组中，并且都++
	}
	//可能有剩余的情况，直接把剩余的复制到新数组就可以了
	if (i>mid)
	{

		while (j <= right)
			MergeList[k++] = initList[j++];
	}
	else if (j >= mid)

	{
		while (i <= mid)
			MergeList[k++] = initList[i++];
	}
}
//迭代归并排序
//合并大小为s的相邻的数组，数组的总长为n
void Mergepass(int *initList, int *MergeList, int n ,int  s)//n代表多少个元素 s代表归并后数组的大小
{
	int i,j;//用于循环
	for (i = 0; i <= n - 2 * s + 1; i += 2*s)
	{
		Merge(initList, MergeList, i, i + s - 1, i + 2 * s - 1);
	}
	//剩下的元素不够时，大于s小于2s，对这段用Merge
	if (i + s < n)
		Merge(initList, MergeList, i, i + s-1, n - 1);
	else
		//剩下的元素小于s直接copy到MergeList中
	for (j = i; j <= n - 1; j++)
		MergeList[j] = initList[j];
}
void Mergesort(int *a, int *b, int n)
{
	int s = 1;
	while (s < n)
	{
		Mergepass(a, b, n, s);
		s *= 2;
		Mergepass(b, a, n, s);
	}
}
int main()
{
	int i;
	int s[10] = {26,5,77,1,61,11,59,15,48,19};
	int d[10] = { 0 };
	//1
	Mergesort(s, d,  10);
	for (i = 0; i < 10; i++)
		printf("%d,", d[i]);
		printf("\n");
		//2
	////可以定义一个函数把下面的归到一个函数里
	//Mergepass(s, d, 10,1);
	//for (i = 0; i < 10; i++)
	//	printf("%d,", d[i]);
	//	printf("\n");
	//Mergepass(d, s, 10, 2);//归并后两数组互换了
	//for (i = 0; i < 10; i++)
	//	printf("%d,", s[i]);
	//	printf("\n");
	//Mergepass(s, d, 10, 4);
	//for (i = 0; i < 10; i++)
	//	printf("%d,", d[i]);
	//printf("\n");
	//Mergepass(d, s, 10, 8);//归并后两数组互换了
	//for (i = 0; i < 10; i++)
	//	printf("%d,", s[i]);
	//printf("\n");
	return 0;
}
//int s[10] = { 23, 47, 85, 95, 7, 14, 39, 55, 62, 74 };
//int d[10] = { 0 };
//Merge(s, d, 0, 3, 9);//s原数组 d新数组 0第一个元素 第一行最后一个元素 最后一个元素
//for (i = 0; i < 10; i++)
//{
//	printf("%d,", d[i]);
//	printf("\n");
//
//}