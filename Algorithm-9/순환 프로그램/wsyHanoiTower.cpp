#include <iostream>
#include <math.h>
using namespace std;

int count = 0;

void hanoiTower(int n, char from, char tmp, char to) {
	if(n == 1){
		printf("%d번째 원판 1을 %c에서 %c으로 옮긴다. \n", ++count, from, to);
		
	}
	else{
		hanoiTower(n - 1, from, to, tmp);
		printf("%d번째 원판 %d을 %c에서 %c으로 옮긴다.\n",	++count, n, from, to);
		hanoiTower(n-1, tmp, from, to);
	
	}
}
void main() {
	int n;
	scanf("%d", &n);
	hanoiTower(n, 'A', 'B', 'C');
	printf("총 %d번 출력되었습니다.\n", count);
}