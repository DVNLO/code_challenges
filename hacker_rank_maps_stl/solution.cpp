#include <cstdio>
#include <cstdlib>
#include <map>

int read_int_val()
{
    int val{ -1 };
    int return_count{ std::scanf("%d", &val) };
    if(return_count != 1)
    {
        std::exit(EXIT_FAILURE);
    }
    return val;
}

enum class QUERY_TYPE{ ADD = 1, DELETE = 2, FIND = 3 };

int main() 
{
    int const QUERY_COUNT{ read_int_val() };
    std::map<std::string, int> student_marks;
    QUERY_TYPE query_type;
    static char str_buffer[7];
    std::string student_name;
    auto itr{ student_marks.end() };
    for(int i{ 0 }; i < QUERY_COUNT; ++i)
    {
        query_type = static_cast<QUERY_TYPE>(read_int_val());
        std::scanf("%s", &str_buffer);
        student_name = str_buffer;
        itr = student_marks.find(student_name);
        switch(query_type)
        {
            case QUERY_TYPE::ADD:
                if(itr == student_marks.end())
                {
                    student_marks[student_name] = read_int_val();
                }
                else
                {
                    student_marks[student_name] += read_int_val();
                }
                break;
            case QUERY_TYPE::DELETE:
                if(itr == student_marks.end())
                {
                    continue;   // do nothing according to prompt
                }
                else
                {
                    student_marks.erase(itr);
                }
                break;
            case QUERY_TYPE::FIND:
                if(itr == student_marks.end())
                {
                    std::puts("0");
                }
                else
                {
                    std::printf("%d\n", itr->second);
                }
                break;
        }
    }
    return 0;
}
