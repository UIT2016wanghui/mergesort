//����
//20170322�ϴ�
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
void Mergepass(int *initList, int *MergeList, int n, int  s);// �����鲢����
void Merge(int *initList, int *MergeList, int left, int mid, int right);//��·�鲢����


//��·�鲢
//���������������initList[left,mid]��initList[mid+1,right]�鲢��һ��������d[10]��MergeList
void Merge(int *initList, int *MergeList, int left, int mid, int right)
{         //δ���������       ������        �����    �м�       ���ұ�
	int i, j, k;//i,j,k�����±�
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid&&j <= right)
	{
		if (initList[i] < initList[j])
			MergeList[k++] = initList[i++];//���±�Ϊi��Ԫ�ظ��Ƶ��������У����Ҷ�++
		else
			MergeList[k++] = initList[j++];//���±�Ϊj��Ԫ�ظ��Ƶ��������У����Ҷ�++
	}
	//������ʣ��������ֱ�Ӱ�ʣ��ĸ��Ƶ�������Ϳ�����
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
//�����鲢����
//�ϲ���СΪs�����ڵ����飬������ܳ�Ϊn
void Mergepass(int *initList, int *MergeList, int n ,int  s)//n������ٸ�Ԫ�� s����鲢������Ĵ�С
{
	int i,j;//����ѭ��
	for (i = 0; i <= n - 2 * s + 1; i += 2*s)
	{
		Merge(initList, MergeList, i, i + s - 1, i + 2 * s - 1);
	}
	//ʣ�µ�Ԫ�ز���ʱ������sС��2s���������Merge
	if (i + s < n)
		Merge(initList, MergeList, i, i + s-1, n - 1);
	else
		//ʣ�µ�Ԫ��С��sֱ��copy��MergeList��
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
	////���Զ���һ������������Ĺ鵽һ��������
	//Mergepass(s, d, 10,1);
	//for (i = 0; i < 10; i++)
	//	printf("%d,", d[i]);
	//	printf("\n");
	//Mergepass(d, s, 10, 2);//�鲢�������黥����
	//for (i = 0; i < 10; i++)
	//	printf("%d,", s[i]);
	//	printf("\n");
	//Mergepass(s, d, 10, 4);
	//for (i = 0; i < 10; i++)
	//	printf("%d,", d[i]);
	//printf("\n");
	//Mergepass(d, s, 10, 8);//�鲢�������黥����
	//for (i = 0; i < 10; i++)
	//	printf("%d,", s[i]);
	//printf("\n");
	return 0;
}
//int s[10] = { 23, 47, 85, 95, 7, 14, 39, 55, 62, 74 };
//int d[10] = { 0 };
//Merge(s, d, 0, 3, 9);//sԭ���� d������ 0��һ��Ԫ�� ��һ�����һ��Ԫ�� ���һ��Ԫ��
//for (i = 0; i < 10; i++)
//{
//	printf("%d,", d[i]);
//	printf("\n");
//
//}