
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	float i, a, b, c, x0, x1, dx, f;
	cout << "  a="; cin >> a;
	cout << "  b="; cin >> b;
	cout << "  c="; cin >> c;
	cout << "  x0="; cin >> x0;
	cout << "  x1="; cin >> x1;
	cout << "  dx="; cin >> dx;
	cout << "\n\n  X     Y\n";
	cout.precision(3);
	if ((a < 0) && (c != 0))
		for (i = x0; i <= x1; i += dx) { f = float((a*i*i) / (i - c)); cout << "\n  " << i << "  " << f; }
	if ((a > 0) && (c == 0))
		for (i = x0; i <= x1; i += dx) { f = float(-a / (i + c)); cout << "\n  " << i << "  " << f; }
	else
		for (i = x0; i <= x1; i += dx) { f = a * (i + c); cout << "\n  " << i << "  " << f; }
	_getch();
}
