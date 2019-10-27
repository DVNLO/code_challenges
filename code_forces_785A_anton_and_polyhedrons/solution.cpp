#include <cstdio>
#include <string>
#include <utility>

int main()
{
    int n;
    std::scanf("%d", &n);
    std::pair<char const * const, unsigned const> constexpr T{ "Tetrahedron", 4U };
    std::pair<char const * const, unsigned const> constexpr C{ "Cube", 6U };
    std::pair<char const * const, unsigned const> constexpr O{ "Octahedron", 8U };
    std::pair<char const * const, unsigned const> constexpr D{ "Dodecahedron", 12U };
    std::pair<char const * const, unsigned const> constexpr I{ "Icosahedron", 20U };
    unsigned const BUFFER_SIZE{ 1024 };
    char buffer[BUFFER_SIZE];
    int rc;
    unsigned face_count{ 0 };
    for(int i = 0; i < n; ++i)
    {
	rc = std::scanf("%s", buffer);
	if(rc < 0)
	{
	    std::exit(EXIT_FAILURE);
	}
	switch(buffer[0])
	{
	case T.first[0]:
	    face_count += T.second;
	    break;
	case C.first[0]:
	    face_count += C.second;
	    break;
	case O.first[0]:
	    face_count += O.second;
	    break;
	case D.first[0]:
	    face_count += D.second;
	    break;
	case I.first[0]:
	    face_count += I.second;
	    break;
	default:
	    std::exit(EXIT_FAILURE);
	    break;
	}
    }
    std::printf("%u\n", face_count);
}
