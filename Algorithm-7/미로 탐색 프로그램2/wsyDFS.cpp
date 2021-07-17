//#pragma once
//#include <stdio.h>
//#include "wsyLinkedStack.h"
//
//const int MAZE_SIZE = 6;	// 미로 맵 크기 고정
//char map[MAZE_SIZE][MAZE_SIZE] = {	// 미로 맵 데이터
//	{'1', '1', '1', '1', '1', '1'},
//	{'e', '0', '1', '0', '0', '1'},
//	{'1', '0', '0', '0', '1', '1'},
//	{'1', '0', '1', '0', '1', '1'},
//	{'1', '0', '1', '0', '0', 'x'},
//	{'1', '1', '1', '1', '1', '1'}
//};
//
//// (r, c)가 갈 수 있는 위치인지를 검사하는 함수
//// (r, c)가 배열 안에 있고, 값이 갈 수있는 위치 '0'이거나 출구 'x'이어야 함
//bool isValidLoc(int r, int c) {
//	if(r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE)
//		return false;
//	else return map[r][c] == '0' || map[r][c] == 'x';
//}
//
//void main() {
//	LinkedStack locStack;
//	Location2D entry(1,0);	// 입구 객체
//	Node *n = new Node(entry);
//	locStack.push(n);	// 덱에 입구 위치 삽입
//
//	while(locStack.isEmpty() == false) {	// 덱이 비어있지 않는 동안
//		n = locStack.pop();
//		Location2D here(n->row, n->col);	// 덱의 front 상단 객체 복사
//		delete n;
//
//		int r = here.row;
//		int c = here.col;
//		printf("(%d,%d)", r, c);	// 현재 위치를 화면에 출력
//		if(map[r][c] == 'x') {	// 출구이면 -> 탐색 성공
//			printf("미로 탐색 성공\n");
//			return;
//		}
//		else {
//			map[r][c] = '.';	// 현재위치를 "지나옴" 처리
//			if(isValidLoc(r - 1, c))
//				locStack.push(new Node(Location2D(r - 1, c)));
//			if(isValidLoc(r + 1, c))
//				locStack.push(new Node(Location2D(r + 1, c)));
//			if(isValidLoc(r, c - 1))
//				locStack.push(new Node(Location2D(r, c - 1)));
//			if(isValidLoc(r, c + 1))
//				locStack.push(new Node(Location2D(r, c + 1)));
//		}
//
//	}
//	printf("미로탐색실패\n");
//}
