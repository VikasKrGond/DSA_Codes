#include<iostream>
#include "logger.hpp"
using namespace std;

int main()
{
    Logger* log1=Logger::getLogger();
    log1->Log("This message is from User_1");

     Logger* log2=Logger::getLogger();
    log2->Log("This message is from User_1");
    return 0;
}
