int sumAlgorithmA(int num)			//O(1) 알고리즘
{
	return num*(num + 1) / 2;		//n*(n+1)/2 공식 사용
}
int sumAlgorithmB(int num)			//O(n) 알고리즘
{
	int sum = 0;
	int	i;
	for (i = 1; i<=num ; i++) {
		sum = sum + i;				//1+2+3+..+n 
	}
	return sum;
}
int sumAlgorithmC(int num)			//O(1) 알고리즘
{
	int sum = 0;
	int	i, j;
	for (i = 0; i <= num; i++) {
		for (j = 1; j<=i; j++) {
			sum = sum + 1;			//1+(1+1)+..(1+1+1+1+...)
		}
	}
	return sum;
}


