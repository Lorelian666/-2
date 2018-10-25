// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include "iostream"
#include "fstream"

using namespace std;

struct student
{
	char name[20];
	int group; 
	int  ses[5]; 
};

double sort(student *, int n);    
double horoshist(student *, int n); 
double srbalgrup(student *, int n);
int main()
{
	setlocale(LC_CTYPE, "Russian"); 
	int n, i, j; 
	cout << "Введите количество структур типа студент - ";
	cin >> n; 

	student *stud1 = new student[n]; 
	ifstream instr("inform.txt");   
	if (!instr) 
	{
		cout << "File can not be open\n"; 
		return 0; 
	}

	cout << endl << "Фамилия\tГруппа\t\t    Оценки" << endl << endl;

		for (i = 0; i < n; i++)
	{
		instr >> stud1[i].name >> stud1[i].group;
		cout << stud1[i].name << '\t' << stud1[i].group;
		for (j = 0; j < 5; j++)
		{
			instr >> stud1[i].ses[j];
			cout << '\t' << stud1[i].ses[j];
		}
		cout << endl;
	}
	instr.close();

	cout << endl << "Mассив STUD1 по возрастанию среднего балла" << endl;
	cout << endl << "Фамилия\tГруппа\t\t     Оценки\t\t     Средний бал" << endl << endl;
	sort(stud1, n); 

	cout << endl << "Фамилии и номера групп для всех студентов, имеющих оценки только 4 и 5" << endl;
	cout << endl << "Фамилия\tГруппа" << endl << endl;
	horoshist(stud1, n); 
	cout << endl << "Средний балл по группам" << endl;
	srbalgrup(stud1, n);
	delete[] stud1; 
	system("pause >> null"); 
	return 0; 
}


double sort(student *gr, int n)
{
	double s; 
	double *avg = new double[n]; 

	for (int i = 0; i < n; i++)
	{
		s = 0.;
		for (int j = 0; j < 5; j++)
		{
			s += gr[i].ses[j];
			avg[i] = s / 5;
		}
	}

	bool flag = true; 

	while (flag) 
	{
		flag = false;  

		for (int i = 0; i < n - 1; ++i)
		{
			if (avg[i] > avg[i + 1]) 
			{
				student x = gr[i];
				gr[i] = gr[i + 1];
				gr[i + 1] = x;

				double temp = avg[i];
				avg[i] = avg[i + 1];
				avg[i + 1] = temp;

				flag = true; 
			}
		}
	}
		
	for (int i = 0; i < n; i++)

	{
		cout << gr[i].name << '\t' << gr[i].group;
		for (int j = 0; j < 5; j++)
		{
			cout << '\t' << gr[i].ses[j];

		}
		cout << "\t" << avg[i]; 
		cout << endl;
	}
	delete[] avg; 
	return 0;
}


double horoshist(student *gr, int n)
{
	int x, z = 0; 

	for (int i = 0; i < n; i++)
	{
		x = 0;
		for (int j = 0; j < 5; j++)
		{

			if (gr[i].ses[j] == 4 || gr[i].ses[j] == 5)
			{
				x++; 
			}
		}
		if (x == 5) 
		{
			cout << gr[i].name << '\t' << gr[i].group << endl; 
			z++;
		}

	}
	if (z == 0) 
	{
		cout << "Среди студентов нет хорошистов" << endl; 
	}
	return 0;
}

double srbalgrup(student *gr, int n)
{
	int k = 0;
	double sum = 0;
	int count = 0;

	for (int i = 0; i < n; ++i)
	{
		if (gr->group == k)
		{
			double gr_sum = 0;

			for (int j = 0; j < 5; ++j)
				gr_sum += gr->ses[j];

			sum += gr_sum / 5;
			++count;

		}
		cout << sum << endl;
	}
	return 0;
}