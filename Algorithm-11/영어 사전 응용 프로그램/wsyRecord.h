#include <cstdio>
#include <cstring>
#define MAX_WORD_SIZE 40
#define MAX_MEANING_SIZE 200
class Record {
	char word[MAX_WORD_SIZE];  //단어 : 키 필드
	char meaning[MAX_MEANING_SIZE];  //단어의 의미 : 키 필드가 아님
public:
	Record(char* w="", char* m="") { set(w, m); }
	void set(char* w, char* m) {
		strcpy(word, w);
		strcpy(meaning, m);
	}
	int compare(Record* n) { return compare (n->word); }
	int compare(char* w) {return strcmp(w, word); }
	int compareMeaning(char* m) {return strcmp(meaning, m); }
	void display() { printf(" %12s : %-40s\n", word, meaning); }
	void copy(Record* n) { set(n->word, n->meaning); }
};