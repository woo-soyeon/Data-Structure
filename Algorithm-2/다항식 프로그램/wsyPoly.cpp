#include "wsyPoly.h"
void main() {
	Polynomial a, b, c, d, e;
	a.read();	// ���׽� a�� ���� (Ű����� �Է�)
	b.read();	// ���׽� b�� ���� (Ű����� �Է�)
	c.add (a, b);	// c = a + b
	d.sub (a, b);	// c = a - b
	e.mult(a, b);	// c = a * b
	a.display("A = "); // ���׽� a�� ȭ�鿡 ���
	a.display2("Trim A = ");
	b.display("B = ");	// ���׽� b�� ȭ�鿡 ���
	b.display2("Trim B = ");
	c.display("A+B = ");	// ���׽� c=a+b�� ȭ�鿡 ���
	c.trim();
	c.display2("Trim A+B = ");
	d.display("A-B = ");	// ���׽� c=a-b�� ȭ�鿡 ���
	d.trim();
	d.display2("Trim A-B = ");
	e.display("A*B = ");	// ���׽� c=a*b�� ȭ�鿡 ���
	e.trim();
	e.display2("Trim A*B = ");
}