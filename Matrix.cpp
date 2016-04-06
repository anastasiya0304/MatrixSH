#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "Matrix.h"

int main()
{
	

	Matrix<int> a(3, 3);
	//cin >> a;
	//cout << a;
	Matrix<int> b(2, 2);
	Matrix<int> c = a + b;
	cout << c;
	/*Matrix<wchar_t> b(3, 3);
	cout << a;
	cout << b;
	Matrix<wchar_t>c(3, 3);
	c = a * b;
	cout << c;
	Matrix<wchar_t> f(3, 3);
	f = a + b;
	cout << f;
	
	a[1][1] = 2;
	cout << "\n";
	cout <<  a[1][1];
	int n = a.columns();
	cout << "\n";
	cout << n;
	int m = a.lines();
	cout << "\n";
	cout << m;*/
	
	system("pause");
	return 0;
}