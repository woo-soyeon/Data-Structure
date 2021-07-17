#include "wsyBinaryTree.h"
class BinSrchTree : public BinaryTree {
public :
	//이진 탐색 트리의 탐색 연산
	BinaryNode* search(char* key) {return searchRecur(root, key); }
	BinaryNode* searchRecur(BinaryNode* n, char* key) {
		if(n == NULL) return NULL;
		if(n->compare(key) == 0) return n;
		else if(n->compare(key) < 0)
			return searchRecur(n->getLeft(), key);
		else return searchRecur(n->getRight(), key);
	}
	//이진 탐색 트리의 삽입 연산
	void insert(BinaryNode* n) {
		if(n == NULL) return;
		if(isEmpty()) root = n;
		else insertRecur(root, n);
	}
	void insertRecur(BinaryNode* r, BinaryNode* n) {
		if(n->compare(r) == 0) return;
		else if(n->compare(r) > 0) {
			if(r->getLeft() == NULL) r->setLeft(n);
			else insertRecur(r->getLeft(), n);
		}
		else {
			if(r->getRight() == NULL) r->setRight(n);
			else insertRecur(r->getRight(), n);
		}
	}
	//이진 탐색 트리의 삭제 연산
	void remove (char* data) {
		if(isEmpty()) return;
		BinaryNode* parent = NULL;
		BinaryNode* node = root;
		while(node!=NULL & node->compare(data)!=0) {
			parent = node;
			node = (node->compare(data) < 0)
				? node->getLeft() : node->getRight();
		}
		if(node != NULL) remove(parent, node);
	}
	// 이진 탐색 트리의 삭제 함수 (순환적인 방법)
	// 일반 함수로 구현 (BinSrchTree의 멤버 함수로 넣어도 됨)
	void remove(BinaryNode* parent, BinaryNode* node) {
		// case 1: 삭제하려는 노드가 단말 노드일 경우
		if( node->isLeaf() ) {
			if(parent == NULL)	// node == root인 경우 => 공백상태가 됨
				root = NULL;
			else {				// 아닌 경우 => parent의 해당 자식을 NULL
				if( parent->getLeft() == node )
					parent->setLeft(NULL);
				else
					parent->setRight(NULL);
			}
		}
		// case 2: 삭제하려는 노드가 왼쪽이나 오른쪽 자식만 갖는 경우
		else if( node->getLeft()==NULL|| node->getRight()==NULL ) {
			// 삭제할 노드의 유일한 자식 노드 => child
			BinaryNode *child = (node->getLeft() != NULL )
				? node->getLeft() : node->getRight();
			// 삭제할 노드가 루트이면 ==> child가 새로운 root가 됨
			if(node == root) root = child;
			// 아니면 ==> 부모 노드의 자식으로 자식 노드 child를 직접 연결
			else {
				if( parent->getLeft() == node )
					parent->setLeft(child);
				else
					parent->setRight(child);
			}
		}
		// chas 3: 삭제하려는 노드가 두개의 자식이 모두 있는 경우
		else {
			// 삭제하려는 노드의 오른쪽 서브트리에서 가장 큰 노드를 탐색
			// succ => 후계 노드 : 오른쪽 서브트리에서 가장 key가 작은 노드
			// succp => 후계 노드의 부모 노드
			BinaryNode* succp = node;
			BinaryNode* succ = node->getRight();
			while (succ->getLeft() != NULL) {	// 후계 노드 탐색
				succp = succ;	// 후계 노드의 부모 노드
				succ = succ->getLeft();	// 후계 노드
			}
			// 후계 노드의 부모와 후계 노드의 오른쪽 자식을 직접 연걸
			if(succp->getLeft() == succ )
				succp->setLeft(succ->getRight());
			else	// 후계 노드가 삭제할 노드의 바로 오른쪽 자식인 경우
				succp->setRight(succ->getRight());
			// 삭제할 노드를 후계 노드로 변경 : 실제로는 후계 노드가 제거됨
			node = succ;
		}
		delete node;		// 메모리 동적 해제
	}
};
