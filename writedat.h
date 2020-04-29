#ifndef H_WRITE_DAT_H
#define H_WRITE_DAT_H

#include <iostream>
#include <fstream>
#include <string>

#include "firstProto.pb.h"

using namespace std;

class WriteDat
{
public:
    WriteDat();
    ~WriteDat();

    void test();

private:
    void promptForAddress1(tutorial::Person* person);
    void promptForAddress2(tutorial::Person* person);


};

#endif // WRITEDAT_H
