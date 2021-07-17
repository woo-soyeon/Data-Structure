#include <cstdio>
#define MAX_DEGREE 80	// ���׽��� ó�� ������ �ִ����� +1
class Polynomial {
	int degree;		// ���׽��� �ְ� ����
	float coef[MAX_DEGREE];		// �� �׿� ���� ���
public :
	Polynomial() { degree = 0; }	// ������ : �ִ� ������ 0���� �ʱ�ȭ

	// ���׽��� ������ �Է¹޴� ����Լ�
	void read() {
		printf("���׽��� �ְ� ������ �Է��Ͻÿ� : ");
		scanf("%d", &degree);
		printf("�� ���� ����� �Է��Ͻÿ� (�� %d��) : ", degree+1);
		for(int i = 0; i <= degree; i++)
			scanf("%f", coef+degree-i);
	}
	// ���׽��� ������ ȭ�鿡 ����ϴ� �Լ�
	void display(char *str = "Poly = ") {	// ����Ʈ �Ű����� ���
		printf("\t%s", str);
		for(int i = 0; i < degree; i++) 
			printf("%5.1f x^%d + ", coef[i], degree-i);
		printf("%4.1f\n", coef[degree]);
	}
	void display2(char *str = "Poly = ") {	// ����Ʈ �Ű����� ���
		printf("\t%s", str);
		if(degree != 0)	// �ְ� ������ 0�� �ƴϸ�
			printf("%5.1f x^%d", coef[0], degree);	// �ְ� ������ ���
		for(int i = 1; i < degree; i++) {	// �ְ� ���� ����
			if(coef[i] == 0)
				continue;	// ����� 0�� ���� ������� ����
			else if(coef[i] == 1)
				printf(" + x^%d",degree-i);
			else if(coef[i] == -1)
				printf(" - x^%d",degree-i);
			else if(coef[i] > 1)
				printf(" + %5.1f x^%d", coef[i], degree-i);
			else
				printf(" - %5.1f x^%d", -(coef[i]), degree-i);	// ������ ��� - ���
		}
		if(coef[degree] != 0) {	// ����� 0�� �ƴ� ��
			if(degree != 0)
				if(coef[degree] > 0)
					printf(" + %5.1f", coef[degree]);
				else
					printf(" - %5.1f", -(coef[degree]));
			else
				printf("%5.1f", coef[degree]);
		}
		else
			if(degree == 0)
				printf("0");
		printf("\n");
	}
	// ���׽� a�� b �� ���ϴ� �Լ�. a�� b�� ���� �ڽ��� ���׽� ����
	void add(Polynomial a, Polynomial b) {
		if (a.degree > b.degree) {	// a�� > b��
			*this = a;	// a ���׽��� �ڱ� ��ü�� ����
			for(int i = 0; i <= b.degree; i++)
				coef[i+(degree-b.degree)] += b.coef[i];
		}
		else {	// a�� <= b��
			*this = b;	// b ���׽��� �ڽſ� ����
			for(int i = 0; i <= a.degree; i++)
				coef[i+(degree-a.degree)] += a.coef[i];
		}
	}
	// ���׽� a�� b�� ���� �Լ�. a�� b�� ���� �ڽ��� ���׽� ����
	void sub(Polynomial a, Polynomial b) {
		if (a.degree > b.degree) {	// a�� > b��
			*this = a;	// a ���׽��� �ڱ� ��ü�� ����
			for(int i = 0; i <= b.degree; i++)
				coef[i+(degree-b.degree)] -= b.coef[i];
		}
		else {	// a�� <= b��
			*this = b;	// b ���׽��� �ڽſ� ����
			for(int i = 0; i <= a.degree; i++)
				coef[i+(degree-a.degree)] -= a.coef[i];
		}
	}
	// ���׽� a�� b�� ���ϴ� �Լ�. a�� b�� ���ؼ� �ڽ��� ���׽� ����
	void mult(Polynomial a, Polynomial b) {
		degree = a.degree + b.degree;		// ���� �ְ� ������ a, b�� �ְ����� ��
		for(int i = 0; i<= degree; i++)
			coef[i] = 0;
		for(int i = 0; i <= a.degree; i++)
			for (int j = 0; j <= b.degree; j++)
				coef[i + j] += a.coef[i] * b.coef[j];
	}
	// �ְ������� ����� 0�̾ƴ� ���� �������� �ϴ� �Լ�
	void trim() {
		for( ; ; ) {
			if(coef[degree] == 0) {	// �ְ� ������ ����� 0�̸�
				degree--;	// �ְ� ������ 1 ����
				//for (int i = 0; i <= degree; i--)
				//	coef[i] = coef[i+1];	// �پ�� ��ŭ ��ĭ�� �ű�
				if(degree == 0)	// ������� �Ǹ� ����
					break;
			}
			else	// �ְ� ������ ����� 0�� �ƴϸ� ����
				break;
		}
	}
	bool isZero() {return degree == 0;}		// �ְ������� 0�ΰ�?
	void negate() {		// ��� ����� ��ȣ�� �ٲ�
		for(int i = 0; i < degree; i++ )
			coef[i] = -coef[i];		// ����� ��ȣ�� �ٲ�
	}
};