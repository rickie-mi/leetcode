int fib(int n) {
	if (n == 0) return 0;
	if (n <= 2) return 1;
	int pre = 1, ppre = 1;
	for (int i = 3; i <= n; i++)
	{
		int cur = pre + ppre;
		ppre = pre;
		pre = cur;
	}
	return pre;
}