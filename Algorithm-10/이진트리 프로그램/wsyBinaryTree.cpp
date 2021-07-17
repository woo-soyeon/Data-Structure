#include "wsyBinaryTree.h"

void main() {
	BinaryTree tree;
	BinaryTree tree2;
	BinaryTree tree3;

	BinaryNode *d = new BinaryNode('D', NULL, NULL);
	BinaryNode *e = new BinaryNode('E', NULL, NULL);
	BinaryNode *b = new BinaryNode('B', d, e);
	BinaryNode *f = new BinaryNode('F', NULL, NULL);
	BinaryNode *c = new BinaryNode('C', f, NULL);
	BinaryNode *a = new BinaryNode('A', b, c);

	BinaryNode *n1 = new BinaryNode(3, NULL, NULL);
	BinaryNode *n2 = new BinaryNode(2, NULL, NULL);
	BinaryNode *n3 = new BinaryNode('*', n1, n2);
	BinaryNode *n4 = new BinaryNode(5, NULL, NULL);
	BinaryNode *n5 = new BinaryNode(6, NULL, NULL);
	BinaryNode *n6 = new BinaryNode('-', n4, n5);
	BinaryNode *n7 = new BinaryNode('+', n3, n6);

	BinaryNode *m4 = new BinaryNode(200, NULL, NULL);
	BinaryNode *m5 = new BinaryNode(500, NULL, NULL);
	BinaryNode *m3 = new BinaryNode(100, m4, m5);
	BinaryNode *m2 = new BinaryNode(50, NULL, NULL);
	BinaryNode *m1 = new BinaryNode(0, m2, m3);

	tree.setRoot(a);
	printf(" ����� ���� = %d\n", tree.getCount());
	printf(" �ܸ��� ���� = %d\n", tree.getLeafCount());
	printf(" Ʈ���� ���� = %d\n", tree.getHeight());

	tree.printinorder();
	tree.preorder();
	tree.postorder();
	tree.levelorder();
	printf("\n");

	tree2.setRoot(n7);
	printf(" ��� ��� = %d\n", tree2.evaluate());
	printf("\n");

	tree3.setRoot(m1);
	printf(" ���丮 �뷮 ��� ��� = %d KB\n", tree3.calcSize());
	printf("\n");
}