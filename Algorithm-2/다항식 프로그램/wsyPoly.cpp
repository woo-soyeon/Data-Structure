#include "wsyPoly.h"
void main() {
	Polynomial a, b, c, d, e;
	a.read();	// 다항식 a를 읽음 (키보드로 입력)
	b.read();	// 다항식 b를 읽음 (키보드로 입력)
	c.add (a, b);	// c = a + b
	d.sub (a, b);	// c = a - b
	e.mult(a, b);	// c = a * b
	a.display("A = "); // 다항식 a를 화면에 출력
	a.display2("Trim A = ");
	b.display("B = ");	// 다항식 b를 화면에 출력
	b.display2("Trim B = ");
	c.display("A+B = ");	// 다항식 c=a+b를 화면에 출력
	c.trim();
	c.display2("Trim A+B = ");
	d.display("A-B = ");	// 다항식 c=a-b를 화면에 출력
	d.trim();
	d.display2("Trim A-B = ");
	e.display("A*B = ");	// 다항식 c=a*b를 화면에 출력
	e.trim();
	e.display2("Trim A*B = ");
}