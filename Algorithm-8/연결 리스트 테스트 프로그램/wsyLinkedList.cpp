#include "wsyLinkedList.h"

void main() {
	printf("LinkedList Test\n");
	printf("\n");
	LinkedList list;	// 리스트 객체 생성
	list.insert(0, new Node(10));	// 리스트 맨 앞에 10 삽입
	list.insert(0, new Node(20));	// 리스트 맨 앞에 20 삽입
	list.insert(1, new Node(30));	// 리스트 1위치에 30 삽입
	list.insert(list.size(), new Node(40));	// 리스트 마지막에 40 삽입
	list.insert(2, new Node(50));	// 리스트 1위치에 50 삽입
	list.display();	// 리스트내용 화면출력
	list.remove(2);	// 리스트 2위치의 항목 삭제
	list.remove(list.size() - 1);	// 리스트 마지막 항목 삭제
	list.remove(0);	// 리스트 맨 앞 항목 삭제
	list.replace(1, new Node(90));	// 리스트 1위치 항목 값 변경
	list.display();	// 리스트내용 화면출력
	list.clear();	// 리스트의 모든 항목 삭제
	list.display();	// 리스트내용 화면출력
	printf("\n");
	printf("LinkedList2 Test\n");
	printf("\n");
	LinkedList2 list2;	// 리스트 객체 생성
	list2.insert(0, new Node(10));	// 리스트 맨 앞에 10 삽입
	list2.insert(0, new Node(20));	// 리스트 맨 앞에 20 삽입
	list2.insert(1, new Node(30));	// 리스트 1위치에 30 삽입
	list2.insert(list.size(), new Node(40));	// 리스트 마지막에 40 삽입
	list2.insert(2, new Node(50));	// 리스트 1위치에 50 삽입
	list2.display();	// 리스트내용 화면 출력
	list2.remove(2);	// 리스트 2위치의 항목 삭제
	list2.remove(list.size() - 1);	// 리스트 마지막 항목 삭제
	list2.remove(0);	// 리스트 맨 앞 항목 삭제
	list2.replace(1, new Node(90));	// 리스트의 1위치 항목 값 변경
	list2.display();	// 리스트내용 화면 출력
	list2.clear();	// 리스트의 모든 항목 삭제
	list2.display();	// 리스트내용 화면 출력
}