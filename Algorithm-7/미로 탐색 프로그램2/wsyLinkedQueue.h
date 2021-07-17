#pragma once
#include <stdio.h>
#include "wsyNode.h"	// Node 클래스 포함

class LinkedQueue {
	Node* front;	// 가장 먼저 삽입된 노드의 포인터
	Node* rear;		// 마지막에 삽입된 노드의 포인터
public :
	LinkedQueue() : front(NULL), rear(NULL) {
	}
	~LinkedQueue() {
		while(!isEmpty()) delete dequeue();
	}
	bool isEmpty() {
		return front == NULL;
	}

	// 삽입 연산 : 연결된 큐의 맨 뒤에 노드 삽입
	void enqueue(Node* p) {
		if(isEmpty())
			front = rear = p;
		else {
			rear->link = p;
			rear = p;
		}
	}

	// 삭제 연산 : 연결된 큐의 맨 앞 노드를 삭제
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
		printf("[큐내용] : ");
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
