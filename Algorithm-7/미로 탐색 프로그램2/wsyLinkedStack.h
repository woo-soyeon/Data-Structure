#include "wsyNode.h"	// Node Ŭ���� ����
#include <cstdio>
#include <cstdlib>

class LinkedStack {
	Node* top;	// ��� ������
public :
	LinkedStack() {	// ������
		top = NULL;
	}
	~LinkedStack() { // �Ҹ���
		while(!isEmpty()) delete pop();	
	}
	bool isEmpty() {
		return top == NULL;
	}
	void push(Node *p) {
		if(isEmpty())
			top = p;
		else {
			p->link = top;
			top = p;
		}
	}
	Node* pop() {
		if(isEmpty())
			return NULL;
		Node *p = top;
		top = top->link;
		return p;
	}
	Node* peek() {
		return top;
	}
	void print() {
		printf("[LinkedStack]\n");
		for(Node *p = top; p != NULL; p = p->link)
			p -> print();
		printf( "\n");
	}
};