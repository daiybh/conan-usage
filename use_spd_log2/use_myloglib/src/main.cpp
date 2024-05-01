#include <vector>
#include <string>
#include "logLib.h"
int main()
{
    SimplyLive::Logger* logger=new SimplyLive::Logger(L"c:\\logs\\use_mylogAPP.log");
    for(int i=0;i<10;i++)
    {
        logger->debug("hello world debug {}",i);
        logger->error("hello world {}",i);
    }  
    return 0;
}
