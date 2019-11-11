#include <cstdio>
using namespace std;
int main()
{
	size_t const SIZE{ 2 };
	char table_card[SIZE + 1];
	scanf("%s", table_card);
	char hand_card[SIZE + 1];
	for(int i = 0; i < 5; ++i)
	{
		scanf("%s", hand_card);
		if(hand_card[0] == table_card[0]
			|| hand_card[1] == table_card[1])
		{
			printf("YES");
			return 0;
		}
	}
	printf("NO");
	return 1;
}
	

