#pragma once
#include <stdio.h>
#include "wsyNode.h"	// Node Ŭ���� ����

class LinkedQueue {
	Node* front;	// ���� ���� ���Ե� ����� ������
	Node* rear;		// �������� ���Ե� ����� ������
public :
	LinkedQueue() : front(NULL), rear(NULL) {
	}
	~LinkedQueue() {
		while(!isEmpty()) delete dequeue();
	}
	bool isEmpty() {
		return front == NULL;
	}

	// ���� ���� : ����� ť�� �� �ڿ� ��� ����
	void enqueue(Node* p) {
		if(isEmpty())
			front = rear = p;
		else {
			rear->link = p;
			rear = p;
		}
	}

	// ���� ���� : ����� ť�� �� �� ��带 ����
	Node* dequeue() {
		if(isEmpty())
			return NULL;
		Node* p = front;
		front = front->link;
		if(front == NULL)
			rear = NULL;
		return p;
	}
	Node* peek() {
		return front;
	}
	void print() {
		printf("[ť����] : ");
		for(Node* p = front; p != NULL; p = p->link)
			p -> print();
		printf("\n");
	}
};

//void main() {
//	LinkedQueue que;
//	for(int i = 0; i < 10; i++)
//		que.enqueue(new Node(Location2D(i, i)));
//	que.print();
//	delete que.dequeue();
//	delete que.dequeue();
//	delete que.dequeue();
//	que.print();
//}
