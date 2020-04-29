#ifndef H_READ_DAT_H
#define H_READ_DAT_H

#include <iostream>
#include <fstream>
#include <string>

#include "firstProto.pb.h"

using namespace std;

class ReadDat
{
public:
    ReadDat();
    ~ReadDat();

    void test();

private:
    void showAddressBook(const tutorial::AddressBook &addressBook);

};

#endif // READDAT_H
