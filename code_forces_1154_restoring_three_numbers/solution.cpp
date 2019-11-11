#include <cstdio>
int main()
{
	int x[4];
	scanf("%d %d %d %d", x, x + 1, x + 2, x + 3);
	for(int i = 0; i < 4; ++i) {	// x
	for(int j = 0; j < 4; ++j) {	// y
	for(int k = 0; k < 4; ++k) {	// z
		if(i == j || i == k || j == k)
			continue;
	//	printf("x == %d y == %d z == %d ", x[i], x[j], x[k]);
		int c = (-x[i])/2 + x[j]/2 + x[k]/2;
		int b = x[k] - c;
		int a = x[i] - b;
	//	printf("a == %d b == %d c == %d\n", a, b, c);
		if((a > 0 && b > 0 && c > 0) 
		    && x[i] == (a + b) 
		    && x[j] == (a + c) 
		    && x[k] == (b + c)){
			printf("%d %d %d\n", a, b, c);
			return 0;
		}
	}}}
	return 1;
}
