

int fact(int val)
{
	int res = 1;
	for (int i = 1; i <= val ;++i) {
		res *= i;
	}
	return res;
}