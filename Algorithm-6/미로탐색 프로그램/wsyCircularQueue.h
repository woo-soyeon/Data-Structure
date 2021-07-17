#include "wsyLocation2D.h"
#include <cstdio>
#include <cstdlib>

#define MAX_QUEUE_SIZE 100

inline void error(char* str) {
	printf("%s\n", str);
	exit(1);
}

typedef Location2D Element;	// ���ÿ� ������ �׸��� Location2D�� ������

class CircularQueue {
protected : 
	int front;	// ù��° ��� ���� ��ġ
	int rear;	// ������ ��� ��ġ
	Element data[MAX_QUEUE_SIZE];	// ����� �迭
public :
	CircularQueue() {
		front = rear = 0;
	}
	bool isEmpty() {
		return front == rear;
	}
	bool isFull() {
		return (rear + 1) % MAX_QUEUE_SIZE == front;
	}
	void enqueue(Element val) {	// ť�� ����
		if(isFull())
			error("error : ť�� ��ȭ�����Դϴ�.\n");
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}
	Element dequeue() {	// ù �׸��� ť���� ���� ��ȯ
		if(isEmpty())
			error("error : ť�� ��������Դϴ�.\n");
		else {
			 front = (front + 1) % MAX_QUEUE_SIZE;
			 return data[front];
		}
	}
	Element peek() {	// ù �׸��� ť���� ���� �ʰ� ��ȯ
		if(isEmpty())
			error("error : ť�� ��������Դϴ�.\n");
		else
			return data[(front + 1) % MAX_QUEUE_SIZE];
	}
	void display() {	// ť�� ��� ������ ������� ���
		printf("ť ���� : ");
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
		for(int i = front + 1; i <= maxi; i++)
			data[i % MAX_QUEUE_SIZE].print();	// ����
		printf("\n");
	}
};
