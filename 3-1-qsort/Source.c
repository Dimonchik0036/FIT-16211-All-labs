//LABA 3-1-qsort
//by Dimochik0036

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

//��������� ������
void quickSort(int* a, int first, int last);

//������ �������� ������� �������
void swap(int *arr, int i, int j);

int main()
{
	int n; //���������� ����� � �������

	scanf("%d", &n);

	//������ �� n �����
	int *numberArray;
	numberArray = malloc(n * sizeof(*numberArray));

	if (numberArray == NULL)
	{
		printf("not memory");

		return 0;
	}

	int i; //���������� ��� �����

	for (i = 0; i < n; i++)
	{
		scanf("%d", &numberArray[i]); //���� ������ � ������
	}

	//����������
	quickSort(numberArray, 0, n - 1);

	//����� �������
	for (i = 0; i < n; i++)
	{
		printf("%d ", numberArray[i]);
	}

	free(numberArray);

	return 0;
}

void swap(int *arr, int i, int j)
{
	int keys = arr[i];
	arr[i] = arr[j];
	arr[j] = keys;
}

void quickSort(int* arr, int first, int last)
{
	int i = first;
	int j = last;
	int centr = arr[(first + last) / 2]; //����� �������� ��� ������� ����������

	do
	{
		while (arr[i] < centr)
			i++;
		while (centr < arr[j])
			j--;

		if (i <= j)
		{
			if (i < j)
			{
				swap(arr, i, j);
			}
			i++;
			j--;
		}
	} while (i <= j);

	//����� ���������� ������ �����
	if (i < last)
		quickSort(arr, i, last);

	//����� ���������� ����� �����
	if (first < j)
		quickSort(arr, first, j);
}
