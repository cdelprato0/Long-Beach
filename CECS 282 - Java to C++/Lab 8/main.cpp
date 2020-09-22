#include "Matrix.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	Matrix m1(2, 2);
	Matrix m2(2, 2);
	Matrix m3(2, 2);
	Matrix m4(2, 3);
	Matrix m5(3, 2);
	
	m1[0][0] = 2;
	m1[1][1] = 2;
	m2[0][0] = 1;
	m2[1][1] = 2;
	
	const Matrix s = -m1;
	
	//a.
	cout << "a" << endl;
	cout << m1 << endl << s << endl;
	m3 = m1 + m2;
	
	//b.
	cout << "b" << endl;
	cout << m3 << endl;
	m3 = m1 - m2;
	
	//c.
	cout << "c" << endl;
	cout << m3 << endl;
	m3 = m1 * m2;
	
	//d.
	cout << "d" << endl;
	cout << m3 << endl;
	//m3 = 1 + m3;
	
	//e.
	//cout << m3 << endl;
	m2 = m3;
	
	//f.
	cout << "f" << endl;
	cout << m2 << endl;
//	m3 = 5*m3;
	
	//g.
//	cout << m3 << endl;
	
	//h
	cout << "h" << endl;
	cout << m3[1][1] << endl;
//	m2=++m3;
	
	//k
//	cout << m2 << endl;
	
//l
	cout << "l" << endl;
	cout << m3 << endl;
	cin >> m4;
	cin >> m5;
	m1 = m4*m5;
	
	//m
	cout << m1;
	return 0;
}
