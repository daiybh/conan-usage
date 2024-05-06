#include <vector>
#include <string>
#include "logLib.h"
#include "lib_headeronly.h"
int main()
{
    SimplyLive::Logger* logger=new SimplyLive::Logger(L"c:\\logs\\use_mylogAPP.log");
    for(int i=0;i<10;i++)
    {
        logger->debug("hello world debug {}",i);
        logger->error("hello world {}",i);
    }  
     std::cout << "1 + 3 = " << sum(1, 3) << std::endl;
    return 0;
}
