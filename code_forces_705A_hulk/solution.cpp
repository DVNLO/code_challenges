#include<cstdio>
#include <string>

int main(int const argc, char * argv[])
{
    int n;
    std::scanf("%d", &n);
    std::string const HATE = "I hate";
    std::string const LOVE = "I love";
    std::string const THAT = " that ";
    std::string const IT = " it";
    std::string ret(HATE);
    for(int i = 1; i < n; ++i)
    {
	ret += THAT;
        if(i & 0x1)
	{
	    ret += LOVE;
	}
	else
	{
	    ret += HATE;
	}
    }
    ret += IT;
    std::puts(ret.c_str());
}
