#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <unordered_map>

namespace HRML
{
    class tag
    {
        std::size_t static const BUFFER_SIZE{ static_cast<std::size_t>(200) };
        char buffer[BUFFER_SIZE] = { 0 };

        std::unordered_map<std::string, std::string> attributes;
        std::unordered_map<std::string, tag &> tags;
        
        std::string read_line(std::FILE * const source);

    public:    
        tag() = delete;
        tag(std::FILE * const source);
        tag(std::FILE * const source, 
            std::string const & line);
        ~tag() = default;
    };


    tag::tag(std::FILE * const source)
    {
        
    }
    
    class file
    {
        std::unordered_map<std::string, HRML::tag &> data;
    public:

    };
}

HRML::HRML(std::FILE * const source)
{
    if(!source)
    {
        throw std::domain_error("null source");
    }
    // for the number of lines / 2 
}

int main() {
    int HRML_LINE_COUNT{ -1 };
    int HRML_QUERY_COUNT{ -1 };
    int const SUCCESSFUL_READ_COUNT{ 2 };
    int read_count{ std::scanf("%d%d", 
                               &HRML_LINE_COUNT, 
                               &HRML_QUERY_COUNT) };
    if(read_count != SUCCESSFUL_READ_COUNT
       || HRML_LINE_COUNT <= 0 
       || HRML_QUERY_COUNT < 0)
    {
        std::exit(EXIT_FAILURE);
    }
    HRML::file data(stdin);
    query(data, stdin, stdout);
    return 0;
}
