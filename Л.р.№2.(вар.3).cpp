// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <conio.h>

using namespace std;

void main()
{
	int n, i, k, p, s = 0, pro = 1;
	cout << "  N=";
	cin >> n;
	int *a = new int[n];
	cout << "\n  Enter elements: ";
	for (i = 0; i < n; i++) cin >> a[i];
	for (i = 0; i < n; i++)
		if (a[i] == 0) { k = i; break; }
	for (i = 0; i < n; i++)
		if (a[i] == 0) p = i;
	for (i = k; i < p; i++) s += a[i];
	cout << "\n\n  S=" << s;
	for (i = 1; i < n; i += 2) pro *= a[i];
	cout << "\n  Pro=" << pro;
	delete[]a;
	_getch();
}