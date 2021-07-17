#include <cstdio>

class Node {
public :
	Node* link;	// 다음 노드를 가리키는 포인터 변수
	float data;	// 노드의 데이터 필드

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

	// 자신의 다음에 새로운 노드 n을 삽입하는 함수
	void insertNext(Node *n) {
		if(n != NULL) {
			n -> link = link;
			link = n;
		}
	}

	// 자신의 다음 노드를 리스트에서 삭제하는 함수
	Node* removeNext() {
		Node* removed = link;
		if(removed != NULL)
			link = removed -> link;
		return removed;
	}
};