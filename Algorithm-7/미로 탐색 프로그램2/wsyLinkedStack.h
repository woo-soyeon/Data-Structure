#include "wsyNode.h"	// Node 클래스 포함
#include <cstdio>
#include <cstdlib>

class LinkedStack {
	Node* top;	// 헤드 포인터
public :
	LinkedStack() {	// 생성자
		top = NULL;
	}
	~LinkedStack() { // 소멸자
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