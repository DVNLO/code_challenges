// the following is pseudo code for parallel recursive search in an unsorted array

/* Perform sequential recursive search for a value v within an unsorted array a.
 * sequentially solve sub-problems until the value v is discovered or the search 
 * bottoms out in which case a nullptr is returned indicating the value was 
 * not found.
 */
int *
rs_seq(int * a, int n, int v)
{
	if(n <= 0)
		return nullptr;
	int m = n / 2;
	if(a[m] == v)
		return a + m;
	else
	{
		L = rs_seq(a, m - 1, v);
		R = rs_seq(a + m + 1, n - m - 1, v);
		if(L != nullptr)
			return L;
		else
			return R;
	}
}

/* Perform parallel recursive search for a value v within an unsorted 
 * array a. Recursively solve sub-problems in parallel until the problem
 * size n is less than or equal to the threshold size t then solve sequentially.
 */
int *
rs_para(int * a, int n, int v, int t)
{
	if(n <= t)
		rs_seq(a, n, v)
	else
	{
		m = n/2;
		if(a[m] == v)
			return a + m;
		else
		{
			paralell_do:
				L = rs_para(a, m - 1, v, t);
				R = rs_para(a + m + 1, n - m - 1, v, t);
			sync;
			if(L != nullptr)
				return L;
			else
				return R;
		}
	}

}