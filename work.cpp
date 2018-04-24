#include <iostream>
#include "work.h"

using namespace std;

void Zap(Chisla* c)
{
	c[0].i = 1;
	c[0].c = 'I';
	c[1].i = 5;
	c[1].c = 'V';
	c[2].i = 10;
	c[2].c = 'X';
	c[3].i = 50;
	c[3].c = 'L';
	c[4].i = 100;
	c[4].c = 'C';
	c[5].i = 500;
	c[5].c = 'D';
	c[6].i = 1000;
	c[6].c = 'M';
}

int Size(char* c)
{
	int n = 0;
	while (*c != 0) {
		if (isdigit(*c)) {
			while (isdigit(*c)) {
				n *= 10;
				n += (*c - '0');
				c++;
			}
			return n;
		}
	}
	return -3;
}

int prob(char a, Chisla* c)
{
	for (int i = 0; i < 7; i++)
		if (a == c[i].c)
			return c[i].i;
	return 0;
}

void rimArab(char* a, Chisla* ch)
{
	int n = 0, count = 0;
	int m = strlen(a);
	if (m == 1) {
		cout << prob(*a, ch) << endl;
		return;
	}
	n = prob(*a, ch);
	a++;
	while (*a != 0)
	{
		if (n < prob(*a, ch))
			count -= n;
		else
			count += n;
		n = prob(*a, ch);
		a++;
	}
	count += n;
	cout << count << endl;
}

void arabRim(int n, Chisla* ch)
{
	char* arr = new char[10];
	char* parr = arr;
	int j = 0;
	while (n != 0)
	{
		int i = n % 10;
		if (i == 4) 
		{
			*arr++ = ch[j + 1].c;
			*arr++ = ch[j].c;
			n /= 10;
			j += 2;
			continue;
		}
		if (i == 9)
		{
			*arr++ = ch[j + 2].c;
			*arr++ = ch[j].c;
			n /= 10;
			j += 2;
			continue;
		}
		if (i >= 5)
		{
			i -= 5;
			for (int k = 0; k < i; k++)
				*arr++ = ch[j].c;
			*arr++ = ch[j + 1].c;
		}
		else
			for (int k = 0; k < i; k++)
				*arr++ = ch[j].c;
		n /= 10;
		j += 2;
	}
	arr--;
	while (arr != parr) {
		cout << *arr;
		arr--;
	}
	cout << *arr << endl;
	delete[] arr;
}
