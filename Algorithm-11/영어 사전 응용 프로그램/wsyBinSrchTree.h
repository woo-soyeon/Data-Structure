#include "wsyBinaryTree.h"
class BinSrchTree : public BinaryTree {
public :
	//���� Ž�� Ʈ���� Ž�� ����
	BinaryNode* search(char* key) {return searchRecur(root, key); }
	BinaryNode* searchRecur(BinaryNode* n, char* key) {
		if(n == NULL) return NULL;
		if(n->compare(key) == 0) return n;
		else if(n->compare(key) < 0)
			return searchRecur(n->getLeft(), key);
		else return searchRecur(n->getRight(), key);
	}
	//���� Ž�� Ʈ���� ���� ����
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
	//���� Ž�� Ʈ���� ���� ����
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
	// ���� Ž�� Ʈ���� ���� �Լ� (��ȯ���� ���)
	// �Ϲ� �Լ��� ���� (BinSrchTree�� ��� �Լ��� �־ ��)
	void remove(BinaryNode* parent, BinaryNode* node) {
		// case 1: �����Ϸ��� ��尡 �ܸ� ����� ���
		if( node->isLeaf() ) {
			if(parent == NULL)	// node == root�� ��� => ������°� ��
				root = NULL;
			else {				// �ƴ� ��� => parent�� �ش� �ڽ��� NULL
				if( parent->getLeft() == node )
					parent->setLeft(NULL);
				else
					parent->setRight(NULL);
			}
		}
		// case 2: �����Ϸ��� ��尡 �����̳� ������ �ڽĸ� ���� ���
		else if( node->getLeft()==NULL|| node->getRight()==NULL ) {
			// ������ ����� ������ �ڽ� ��� => child
			BinaryNode *child = (node->getLeft() != NULL )
				? node->getLeft() : node->getRight();
			// ������ ��尡 ��Ʈ�̸� ==> child�� ���ο� root�� ��
			if(node == root) root = child;
			// �ƴϸ� ==> �θ� ����� �ڽ����� �ڽ� ��� child�� ���� ����
			else {
				if( parent->getLeft() == node )
					parent->setLeft(child);
				else
					parent->setRight(child);
			}
		}
		// chas 3: �����Ϸ��� ��尡 �ΰ��� �ڽ��� ��� �ִ� ���
		else {
			// �����Ϸ��� ����� ������ ����Ʈ������ ���� ū ��带 Ž��
			// succ => �İ� ��� : ������ ����Ʈ������ ���� key�� ���� ���
			// succp => �İ� ����� �θ� ���
			BinaryNode* succp = node;
			BinaryNode* succ = node->getRight();
			while (succ->getLeft() != NULL) {	// �İ� ��� Ž��
				succp = succ;	// �İ� ����� �θ� ���
				succ = succ->getLeft();	// �İ� ���
			}
			// �İ� ����� �θ�� �İ� ����� ������ �ڽ��� ���� ����
			if(succp->getLeft() == succ )
				succp->setLeft(succ->getRight());
			else	// �İ� ��尡 ������ ����� �ٷ� ������ �ڽ��� ���
				succp->setRight(succ->getRight());
			// ������ ��带 �İ� ���� ���� : �����δ� �İ� ��尡 ���ŵ�
			node = succ;
		}
		delete node;		// �޸� ���� ����
	}
};
