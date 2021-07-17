int sumAlgorithmA(int num)			//O(1) �˰���
{
	return num*(num + 1) / 2;		//n*(n+1)/2 ���� ���
}
int sumAlgorithmB(int num)			//O(n) �˰���
{
	int sum = 0;
	int	i;
	for (i = 1; i<=num ; i++) {
		sum = sum + i;				//1+2+3+..+n 
	}
	return sum;
}
int sumAlgorithmC(int num)			//O(1) �˰���
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


