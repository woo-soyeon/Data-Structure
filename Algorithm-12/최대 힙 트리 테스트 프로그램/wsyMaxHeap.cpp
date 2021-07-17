#include "wsyMaxHeap.h"		// 최대 힙 클래스 포함
// 주함수
void main() {
	MaxHeap heap;

	//삽입 테스트
	heap.insert(14);	heap.insert( 3);
	heap.insert(35);	heap.insert (4);
	heap.insert( 6);	heap.insert( 8);
	heap.insert( 1);
	heap.display( );	// 상태 출력

	// 삭제 테스트
	heap.remove();	heap.display();
	heap.remove();	heap.display();
	printf("\n");
}