//#include <stdio.h>
//
//int fiboIter(int n) {
//	if(n < 2)
//		return n;
//	else {
//		int tmp, current = 1, last = 0;
//		for(int i = 2; i <= n; i++) {
//			tmp = current;
//			current += last;
//			last = tmp;
//		}
//		return current;
//	    printf("Fibo(%d)\n", current);
//	}
//}
//
//void main() {
//	int n;
//	scanf("%d", &n);
//	printf("Fibo(%d) = %d\n", n, fiboIter(n));
//}