//���� Ž�� Ʈ���� ����ϴ� ���� ���� ���α׷� ���� �Լ�
#include "wsyDictionary.h"
#include <conio.h>
void help() {
	printf("[����] i-�߰� d-���� w-�ܾ�˻� m-�ǹ̰˻� p-��� q-���� => ");
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
		case'i' : printf("   > ���� �ܾ� : "); gets(word);
			printf("   > �ܾ� ���� : "); gets(meaning);
			tree.insert( new BinaryNode(word, meaning) );
			break;
		case'd' : printf("   > ���� �ܾ� : "); gets(word);
			tree.remove( word );
			break;
		case'p' : tree.printAllWords( );
			printf("\n");
			break;
		case 'w' : printf("   > �˻� �ܾ� : "); gets(word);
			tree.searchWord( word );
			break;
		case 'm' : printf("   > �˻� ��ġ : "); gets(word);
			tree.searchMeaning( word );
			break;
		}
	} while(command != 'q');
}