#include <iostream>
#include <math.h>
using namespace std;

int count = 0;

void hanoiTower(int n, char from, char tmp, char to) {
	if(n == 1){
		printf("%d��° ���� 1�� %c���� %c���� �ű��. \n", ++count, from, to);
		
	}
	else{
		hanoiTower(n - 1, from, to, tmp);
		printf("%d��° ���� %d�� %c���� %c���� �ű��.\n",	++count, n, from, to);
		hanoiTower(n-1, tmp, from, to);
	
	}
}
void main() {
	int n;
	scanf("%d", &n);
	hanoiTower(n, 'A', 'B', 'C');
	printf("�� %d�� ��µǾ����ϴ�.\n", count);
}