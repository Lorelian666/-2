// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "stdafx.h"
#include <cstdio>
#include <conio.h>
#include <clocale>
#include <windows.h>
struct Bilet {
	int num;
	char pn[30];
	int rei; 
	char name[40]; 
	int day;
	int monat;
	int year;

	Bilet *next;
};
Bilet* first(int, char*, int, char*, int, int, int);
void add(Bilet**, int, char*, int, char*, int, int, int);
Bilet* search(Bilet* const, int);
void viewList(Bilet*);
void viewHead();

Bilet* first(int num, char *pn, int rei, char *name, int day, int monat, int year) {
	Bilet *enew = new Bilet;
	enew->num = num;
	strcpy(enew->pn, pn);
	strcpy(enew->name, name);
	enew->day = day;
	enew->monat = monat;
	enew->year = year;
	enew->rei = rei;
	enew->next = 0;
	return enew;
}
void add(Bilet **eend, int num, char *pn, int rei, char *name, int day, int monat, int year)
{
	Bilet *enew = new Bilet;
	enew->num = num;
	strcpy(enew->pn, pn);
	strcpy(enew->name, name);
	enew->rei = rei;
	enew->day = day;
	enew->monat = monat;
	enew->year = year;
	enew->next = 0;
	(*eend)->next = enew;
	*eend = enew;
	return;
}
Bilet* search(Bilet * const ebeg, int num) {
	Bilet *enew = ebeg;
	while (enew) {
		if (enew->num == num)
			break;
		enew = enew->next;
	}
	return enew;
}
void viewAvialableList(Bilet *ebeg) {
}

void viewList(Bilet *ebeg) {
	Bilet *enew = ebeg;
	while (enew) {
		printf(" Заявка номер %d\n", enew->num);
		printf(" Пункт назначения: %s\n", enew->pn);
		printf(" ФИО пассажжира: %s\n", enew->name);
		printf(" Номер рейса: %d\n", enew->rei);
		printf(" Дата вылета: %d/%d/%d\n\n", enew->day, enew->monat, enew->year);
		if (enew->next) printf("\n");
		enew = enew->next;
	}
	return;
}
void viewHead() {
	system("cls");
	printf("1. Добавить заявку.\n");
	printf("2. Вывод всех заявок.\n");
	printf("3. Запрос заявки по номеру рейса.\n");
	printf("4. Запрос заявки по дате.\n\n");

	printf("0. Выход.\n");
	return;
}

int main()
{
	{SetConsoleCP(1251);
	SetConsoleOutputCP(1251); }
	setlocale(0, "Russian");
	bool exit = false;
	char c = 0;
	Bilet *ebeg = 0, *eend = 0;
	int day = 0, monat = 0, year = 0, num = 0, rei = 0;
	char pn[30] = { 0 },
		name[40] = { 0 };
	while (!exit) {
		viewHead();
		c = _getch();
		system("cls");
		switch (c) {
		case '1': 
			if (!eend) num = 1;
			else num = eend->num + 1;
			printf("Номер заявки: %d\n", num);
			printf("Пункт назначения: ");
			scanf("%s", pn);
			printf("Номер рейса: ");
			scanf("%d", &rei);
			printf("ФИО пассажира(ИвановИА): ");
			scanf("%s", name);
			printf("Дата вылета(день/месяц/год): ");
			scanf("%d/%d/%d", &day, &monat, &year);
			if (!ebeg) {
				ebeg = first(num, pn, rei, name, day, monat, year);
				eend = ebeg;
			}
			else
				add(&eend, num, pn, rei, name, day, monat, year);
			printf("Заявка добавлена!");
			fflush(stdin);
			_getch();
			break;

		case '2': 
			if (ebeg)
				viewList(ebeg);
			else
				printf("Заявок нет!.\n");
			_getch();
			break;

		case '3':
			if (ebeg)
				viewAvialableList(ebeg);
			else
				printf("Такой заявки не существует.\n");
			_getch();
			break;
		case '0':
			exit = true;
			break;
		default:
			break;
		}
	}
	return 0;
}