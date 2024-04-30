#include "myloglib.h"
#include <vector>
#include <string>

int main() {
    
    for(int i=0;i<10;i++)
    {MyLogLib::debug("c:\\logs\\aa.log", 123, "hello world");
    MyLogLib::error("c:\\logs\\aa.log", 123, "hello world");}
    myloglib();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    myloglib_print_vector(vec);
    return 0;

}
