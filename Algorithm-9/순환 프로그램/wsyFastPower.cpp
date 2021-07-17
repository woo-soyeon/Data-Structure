//#include <stdio.h>
//
//double fastPower();
//
//double fastPower(double x, int n) {
//	printf("%d\n",n);
//	if(n == 0) 
//		return 1;
//	else if((n % 2) == 0)
//		return fastPower(x * x, n/2);
//	else
//		return x * fastPower(x * x, (n-1)/2);
//}
//
//void main() {
//	double a;
//	int b;
//	double result;
//	printf("Á¦°öÇÒ ¼ö : ");
//	scanf("%lf", &a);
//	printf("Á¦°ö ½Â : ");
//	scanf("%d", &b);
//	result = fastPower(a, b);
//	printf("%.lf\n",result);
//}