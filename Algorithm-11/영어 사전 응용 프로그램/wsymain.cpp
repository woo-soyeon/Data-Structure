//이진 탐색 트리를 사용하는 영어 사전 프로그램 메인 함수
#include "wsyDictionary.h"
#include <conio.h>
void help() {
	printf("[사용법] i-추가 d-삭제 w-단어검색 m-의미검색 p-출력 q-종료 => ");
}
void main() {
	char command;
	char word[80];
	char meaning[200];
	Dictionary tree;
	do {
		help();
		command = getche();
		printf("\n");
		switch(command) {
		case'i' : printf("   > 삽입 단어 : "); gets(word);
			printf("   > 단어 설명 : "); gets(meaning);
			tree.insert( new BinaryNode(word, meaning) );
			break;
		case'd' : printf("   > 삭제 단어 : "); gets(word);
			tree.remove( word );
			break;
		case'p' : tree.printAllWords( );
			printf("\n");
			break;
		case 'w' : printf("   > 검색 단어 : "); gets(word);
			tree.searchWord( word );
			break;
		case 'm' : printf("   > 검색 위치 : "); gets(word);
			tree.searchMeaning( word );
			break;
		}
	} while(command != 'q');
}