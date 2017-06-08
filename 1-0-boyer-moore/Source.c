//LABA 1-0-boyer-moore
//by Dimonchik0036

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

#define TEXT_SIZE 500
#define SHABLON_SIZE 20
#define MAX_CHAR 256

//���������� ��������� ������� � �������, ��� ����������
void search(char *text, char *shablon, int digit, int index);

int main()
{
	setlocale(LC_ALL, "Russian");

	char shablon[SHABLON_SIZE];
	char *text = (char *)malloc(TEXT_SIZE);

	gets(shablon);

	int sizeShablon = strlen(shablon);

	//���������� ��� ���������� ���������
	int shift = 0;
	int textSize = fread(text, sizeof(char), TEXT_SIZE, stdin);

	//�������� ������� ����-��������
	//============================================
	unsigned char skip[MAX_CHAR];

	for (int i = 0; i < MAX_CHAR; ++i)
		skip[i] = sizeShablon;

	for (int i = 0; i < sizeShablon - 1; ++i)
		skip[shablon[i]] = sizeShablon - i - 1;
	//============================================

	unsigned char lastCharInShablon, charInText;
	int index; //������� ������� � �����

	lastCharInShablon = shablon[sizeShablon - 1];
	index = 0;

	while ((textSize == TEXT_SIZE) || (index <= textSize - sizeShablon) )
	{
		//���������� ������ ����� ��� �������������
		if (index + sizeShablon > textSize)
		{
			int bufBegin = index;
			int bufSize = TEXT_SIZE - bufBegin;

			for (int i = 0; i < bufSize; i++)
				text[i] = text[i + bufBegin];

			textSize = fread(text + bufSize, sizeof(char), TEXT_SIZE - bufSize, stdin) + bufSize;

			index = 0;
			shift += TEXT_SIZE - bufSize;
		}

		charInText = text[index + sizeShablon - 1];

		printf("%d ", index + sizeShablon + shift);

		if (charInText == lastCharInShablon)
			search(&text[index], shablon, sizeShablon - 1, index + shift);

		index += skip[charInText];
	}

	return 0;
}

void search(char *text, char *shablon, int digit, int index)
{
	while ((*(text + digit) == *(shablon + digit)) && (digit > 0))
	{
		printf("%d ", index + digit);
		digit--;
	}
}