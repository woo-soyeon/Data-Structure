#include "wsyLinkedList.h"

void main() {
	printf("LinkedList Test\n");
	printf("\n");
	LinkedList list;	// ����Ʈ ��ü ����
	list.insert(0, new Node(10));	// ����Ʈ �� �տ� 10 ����
	list.insert(0, new Node(20));	// ����Ʈ �� �տ� 20 ����
	list.insert(1, new Node(30));	// ����Ʈ 1��ġ�� 30 ����
	list.insert(list.size(), new Node(40));	// ����Ʈ �������� 40 ����
	list.insert(2, new Node(50));	// ����Ʈ 1��ġ�� 50 ����
	list.display();	// ����Ʈ���� ȭ�����
	list.remove(2);	// ����Ʈ 2��ġ�� �׸� ����
	list.remove(list.size() - 1);	// ����Ʈ ������ �׸� ����
	list.remove(0);	// ����Ʈ �� �� �׸� ����
	list.replace(1, new Node(90));	// ����Ʈ 1��ġ �׸� �� ����
	list.display();	// ����Ʈ���� ȭ�����
	list.clear();	// ����Ʈ�� ��� �׸� ����
	list.display();	// ����Ʈ���� ȭ�����
	printf("\n");
	printf("LinkedList2 Test\n");
	printf("\n");
	LinkedList2 list2;	// ����Ʈ ��ü ����
	list2.insert(0, new Node(10));	// ����Ʈ �� �տ� 10 ����
	list2.insert(0, new Node(20));	// ����Ʈ �� �տ� 20 ����
	list2.insert(1, new Node(30));	// ����Ʈ 1��ġ�� 30 ����
	list2.insert(list.size(), new Node(40));	// ����Ʈ �������� 40 ����
	list2.insert(2, new Node(50));	// ����Ʈ 1��ġ�� 50 ����
	list2.display();	// ����Ʈ���� ȭ�� ���
	list2.remove(2);	// ����Ʈ 2��ġ�� �׸� ����
	list2.remove(list.size() - 1);	// ����Ʈ ������ �׸� ����
	list2.remove(0);	// ����Ʈ �� �� �׸� ����
	list2.replace(1, new Node(90));	// ����Ʈ�� 1��ġ �׸� �� ����
	list2.display();	// ����Ʈ���� ȭ�� ���
	list2.clear();	// ����Ʈ�� ��� �׸� ����
	list2.display();	// ����Ʈ���� ȭ�� ���
}