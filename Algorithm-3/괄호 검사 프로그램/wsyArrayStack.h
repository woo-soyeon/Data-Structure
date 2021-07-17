#include <cstdio>	// C ������� <stdio.h>�� �����ϴ� �Ͱ� ����
#include <cstdlib>	// C ������� <stdlib.h>�� �����ϴ� �Ͱ� ����

// ���� ó�� �Լ�
inline void error(char *message) {
			printf("%s\n", message);
			exit(1);
}
const int MAX_STACK_SIZE = 20;	// ������ �ִ� ũ�� ����
class ArrayStack {
	int top;	// ����� ����
	int data[MAX_STACK_SIZE];	// ����� �迭
public :
	ArrayStack() { top = -1; }	// ���� ������ (ADT�� create() ����)
	~ArrayStack() {}	// ���� �Ҹ���
	bool isEmpty() { return top == 0; }
	bool isFull() {return top == MAX_STACK_SIZE; }

	void push(int e) {	// �� ���� �׸� ����
		if(isFull()) error ("���� ��ȭ ����");
		data[top++] = e;
	}

	int pop() {	// �� ���� ��Ҹ� �����ϰ� ��ȯ
		if(isEmpty()) error ("���� ���� ����");
		return data[--top];
	}

	int peek() {	// �������� �ʰ� ��� ��ȯ
		if(isEmpty()) error ("���� ���� ����");
		return data[top-1];
	}
	void display() {	// ���� ������ ȭ�鿡 ���
		printf("[���� �׸��� �� = %2d] ==> ", top);
		for(int i = 0; i <= top; i++)
			printf("<%2d>", data[i]);
		printf("\n");
	}
	void reset() {	// ������ ������ �ʱ�ȭ�ϴ� �Լ�
		top = 0;
		for(int i = 0; i < MAX_STACK_SIZE; i++)
			data[i] = NULL;
	}
};