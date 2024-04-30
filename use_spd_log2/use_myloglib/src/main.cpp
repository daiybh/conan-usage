#include <vector>
#include <string>
#include "myloglib.h"
int main()
{
    myloglib();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    myloglib_print_vector(vec);
    for (int i = 0; i < 10; i++)
    {
        MyLogLib::debug("c:\\logs\\aa.log", i, "hello world");
        MyLogLib::error("c:\\logs\\aa.log", i, "hello world");
    }
    return 0;
}
