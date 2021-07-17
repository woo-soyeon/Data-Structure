#include <cstdio>

class Node {
public :
	Node* link;	// ���� ��带 ����Ű�� ������ ����
	float data;	// ����� ������ �ʵ�

	Node(float val = 0) : data(val), link(NULL) { }
	Node* getLink() {
		return link;
	}
	void setLink(Node* next) {
		link = next;
	}
	void display() {
		printf(" <%2.2f>", data);
	}
	bool hasData(float val) {
		return data == val;
	}

	// �ڽ��� ������ ���ο� ��� n�� �����ϴ� �Լ�
	void insertNext(Node *n) {
		if(n != NULL) {
			n -> link = link;
			link = n;
		}
	}

	// �ڽ��� ���� ��带 ����Ʈ���� �����ϴ� �Լ�
	Node* removeNext() {
		Node* removed = link;
		if(removed != NULL)
			link = removed -> link;
		return removed;
	}
};