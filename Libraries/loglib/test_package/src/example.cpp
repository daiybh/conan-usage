#include <vector>
#include <string>
#include "logLib.h"
#include <format>

int main() {
    printf("hello world\n");

    SimplyLive::Logger* logger=new SimplyLive::Logger(L"c:\\logs\\aa.log");
    for(int i=0;i<10;i++)
    {
        logger->debug("hello world debug {}",i);
        logger->error("hello world {}",i);
    }    
    logger->debug("Over here");
    return 0;

}
