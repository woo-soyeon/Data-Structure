#include "wsyMaxHeap.h"		// �ִ� �� Ŭ���� ����
// ���Լ�
void main() {
	MaxHeap heap;

	//���� �׽�Ʈ
	heap.insert(14);	heap.insert( 3);
	heap.insert(35);	heap.insert (4);
	heap.insert( 6);	heap.insert( 8);
	heap.insert( 1);
	heap.display( );	// ���� ���

	// ���� �׽�Ʈ
	heap.remove();	heap.display();
	heap.remove();	heap.display();
	printf("\n");
}