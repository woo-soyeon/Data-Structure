#include "wsyNode.h"

class LinkedList {
	Node org;	// ��� ���
public :
	LinkedList() : org(0) { }	// ������
	~LinkedList() {	// �Ҹ���
		clear();
	}
	void clear() {
		while(!isEmpty())
			delete remove(0);
	}
	Node* getHead() {
		return org.getLink();
	}
	bool isEmpty() {
		return getHead() == NULL;
	}

	// pos��° �׸��� ��ȯ��
	Node* getEntry(int pos) {
		Node* n = &org;
		for(int i = -1; i < pos; i++, n = n -> getLink())
			if(n == NULL)
				break;
		return n;
	}

	// ����Ʈ�� � ��ġ�� �׸� ����
	void insert(int pos, Node *n) {
		Node* prev = getEntry(pos - 1);
		if(prev != NULL)
			prev -> insertNext(n);
	}

	// ����Ʈ�� � ��ġ�� �׸� ����
	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1);
		return prev -> removeNext();
	}

	// Ž�� �Լ�
	Node* find(float val) {
		for(Node *p = getHead(); p != NULL; p = p -> getLink())
			if(p -> hasData(val))
				return p;
		return NULL;
	}

	// ����Ʈ�� � ��ġ�� �ִ� �׸� ��ȯ
	void replace(int pos, Node *n) {
		Node* prev = getEntry(pos - 1);
		if(prev != NULL) {
			delete prev -> removeNext();
			prev -> insertNext(n);
		}
	}

	// ����Ʈ �׸� ������ ��ȯ
	int size() {
		int count = 0;
		for(Node *p = getHead(); p != NULL; p = p -> getLink())
			count++;
		return count;
	}

	// ȭ�鿡 ���� ���� ���
	void display() {
		printf("[��ü �׸� �� = %2d] : ", size());
		for(Node *p = getHead(); p != NULL; p = p -> getLink())
			p -> display();
		printf("\n");
	}
};

class LinkedList2 {
	Node* head;	// ��� ������
public :
	LinkedList2() : head(0) { }	// ������
	~LinkedList2() {	// �Ҹ���
		clear();
	}
	void clear() {
		while(!isEmpty())
			delete remove(0);
	}
	Node* getHead() {
		return head -> getLink();
	}
	bool isEmpty() {
		return getHead() == NULL;
	}

	// pos��° �׸��� ��ȯ��
	Node* getEntry(int pos) {
		Node* n = head;
		for(int i = -1; i < pos; i++, n = n -> getLink())
			if(n == NULL)
				break;
		return n;
	}
	// ����Ʈ�� � ��ġ�� �׸� ����
	void insert(int pos, Node *n) {
		if(pos == 0) {
			n -> link = head;
			head = n;
		}
		else {
		Node* prev = getEntry(pos - 1);
		if(prev != NULL)
			prev -> insertNext(n);
		}
	}

	// ����Ʈ�� � ��ġ�� �׸� ����
	Node* remove(int pos) {
		if(pos == 0) {
			Node* n = head;
			head = n -> link;
			return n;
		}
		else {
		Node* prev = getEntry(pos - 1);
		return prev -> removeNext();
		}
	}

	// Ž�� �Լ�
	Node* find(float val) {
		for(Node *p = getHead(); p != NULL; p = p -> getLink())
			if(p -> hasData(val))
				return p;
		return NULL;
	}

	// ����Ʈ�� � ��ġ�� �ִ� �׸� ��ȯ
	void replace(int pos, Node *n) {
		Node* prev = getEntry(pos - 1);
		if(prev != NULL) {
			delete prev -> removeNext();
			prev -> insertNext(n);
		}
	}

	// ����Ʈ �׸� ������ ��ȯ
	int size() {
		int count = 0;
		for(Node *p = getHead(); p != NULL; p = p -> getLink())
			count++;
		return count;
	}

	// ȭ�鿡 ���� ���� ���
	void display() {
		printf("[��ü �׸� �� = %2d] : ", size());
		for(Node *p = getHead(); p != NULL; p = p -> getLink())
			p -> display();
		printf("\n");
	}
};
