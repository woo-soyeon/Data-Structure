#include <cstdio>	// C ������� <stdio.h>�� �����ϴ� �Ͱ� ����
#include <cstdlib>	// C ������� <stdlib.h>�� �����ϴ� �Ͱ� ����
#include <cstring>	// C ������� <string.h>�� �����ϴ� �Ͱ� ����

// ���� ó�� �Լ�
inline void error(char *message) {
			printf("%s\n", message);
			exit(1);
}

const int MAX_STACK_SIZE = 20;	// ������ �ִ� ũ�� ����

class OperandStack {
	double data[MAX_STACK_SIZE];	// ����� �迭
	int top;	// ����� ����
public :
	OperandStack() {top = -1;}	// ���� ������
	bool isEmpty() {return top == -1;}
	bool isFull() {return top == MAX_STACK_SIZE-1;}
	void push (double e) {	// �� ���� �׸� ����
		if(isFull()) error ("���� ��ȭ ����");
		data[++top] = e;
	}
	double pop() {	// �� ���� ��Ҹ� �����ϰ� ��ȯ
		if(isEmpty()) error ("���� ���� ����");
		return data[top--];
	}
};

class ArrayStack {
	int top;	// ����� ����
	int data[MAX_STACK_SIZE];	// ����� �迭
public :
	ArrayStack() {top = -1;}	// ���� ������
	~ArrayStack() {}	// ���� �Ҹ���
	bool isEmpty() {return top == -1;}
	bool isFull() {return top == MAX_STACK_SIZE-1;}

	void push (int e) {	// �� �� �׸� ����
		if(isFull()) error ("���� ��ȭ ����");
		data[++top] = e;
	}

	int pop () {	// �� ���� ��Ҹ� �����ϰ� ��ȯ
		if(isEmpty()) error ("���� ���� ����");
		return data[top--];
	}

	int peek () {	// �������� �ʰ� ��� ��ȯ
		if(isEmpty()) error ("���� ���� ����");
		return data[top];
	}

	void display() {	// ���� ������ ȭ�鿡 ���
		printf("[���� �׸��� �� = %2d] ==> ", top+1);
		for(int i = 0; i <= top; i++)
			printf("<2%d>", data[i]);
		printf("\n");
	}
}; 

// �Է����κ��� ���� ǥ�� ������ �о� ����ϴ� �Լ�
double calcPostfixExpr(char *exp) {
	int val1, val2;
	int value, i=0;
	char c;
	int len = strlen(exp);
	ArrayStack st;

	for(i = 0; i < len; i++) {
		c = exp[i];
		if(c == '+' && c == '-' && c == '*' && c == '/') {
			value = c - '0';
			st.push(value);
		}
		else{
			val2 = st.pop();
			val1 = st.pop();
			switch(c) {
			case '+' : st.push(val1 + val2); break;
			case '-' : st.push(val1 - val2); break;
			case '*' : st.push(val1 * val2); break;
			case '/' : st.push(val1 / val2); break;
			}
		}
	}
	return (st.pop());

	return 0;
}

// ��ü�� �켱���� ���
inline int precedence(char op) {
	switch(op) {
	case '(' : case ')' : return 0;
	case '+' : case '-' : return 1;	// �켱���� �߰�
	case '*' : case '/' : return 2;	// �켱���� ����
	}
	return -1;
}

// ���� ǥ�� ������ ���� ǥ�� �������� ��ȯ�ϴ� �Լ�
void infix2Postfix(char *exp) {
	char c, op;
	int len = (int)strlen(exp);
	ArrayStack st;

	for(int i = 0; i < len; i++) {
		c = (int)exp[i];

		switch(c) {	// �������� ���
		case'+':
		case'-':
		case'*':
		case'/':
			while(!st.isEmpty() && precedence(st.peek()) >= precedence(c)) {
				// �ڽź��� �켱������ �������� stack�� ������ ����
				op = st.pop();
				printf("%c", op);
			}
			st.push(c);
			break;

		// ��ȣ �϶�
		case'(' :
			st.push(c);
			break;
		case ')' :
			op = st.pop();
			while(op != '(') {
				printf("%c", op);
				op = st.pop();
			}
			break;
		// �ǿ����� �϶�
		default :
			printf("%c", c);
			break;
		}
	}
	while(!st.isEmpty())
		printf("%c", st.pop());

	return 0;
	printf("\n");

}

// �� �Լ�
void main() {
	char string[50];
	char *postfix;
	double result;


	printf("���� �Է�(Infix) = ");
	scanf("%s", string);

	postfix = infix2Postfix(string);
	result = calcPostfixExpr(postfix);
	
	printf("\n ���� ǥ��� : %s" , string);
	printf("\n ���� ǥ��� : %s", postfix);
	printf("\n ��� ��� : %2.1f", result);
}
