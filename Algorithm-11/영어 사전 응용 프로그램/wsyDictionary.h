#include "wsyBinSrchTree.h"
class Dictionary : public BinSrchTree {
public :
	void printAllWords() {
		printf("   >> ���� �ܾ��� : \n");
		if(!isEmpty()) inorder(root);
	}
	void searchWord( char *word ) {
		BinaryNode *node = search( word );
		if( node != NULL ) {
			printf("   >> ");
			node->display();
		}
		else printf("   >> ��ϵ��� ���� �ܾ� : %s\n", word );
	}
	void searchMeaning( char *m ) {
		BinaryNode *node = (isEmpty()) ? NULL:searchByMeaning(root,m );
		if( node != NULL ) {
			printf("   >> ");
			node->display();
		}
		else printf("   >> ��ϵ��� ���� �ǹ� : %s\n", m );
	}
	BinaryNode *searchByMeaning(BinaryNode *node, char* m) {
		if( node == NULL || node->compareMeaning(m)==0 ) return node;
		BinaryNode *theNode = searchByMeaning(node->getLeft(), m);
		if( theNode != NULL ) return theNode;
		return searchByMeaning(node->getRight(), m);
	}
};