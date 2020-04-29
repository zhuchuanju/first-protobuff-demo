#include "writedat.h"

WriteDat::WriteDat()
{
    test();
}

WriteDat::~WriteDat()
{

}

void WriteDat::test()
{
    //验证我们链接的库的版本是否为
    //与我们编译的头的版本兼容。
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    tutorial::AddressBook addressBook;
//    addressBook.add_people();
//    addressBook.mutable_people(1)

    promptForAddress1(addressBook.add_people());
    promptForAddress1(addressBook.add_people());
    promptForAddress2(addressBook.add_people());

    string strFileName = "firstPro.dat";
    ofstream output;
    output.open(strFileName, ios::out | ios::trunc | ios::binary);

    if (!addressBook.SerializeToOstream(&output))
    {
        cerr << "Failed to write address book." << endl;
        return ;
    }

    // Optional:  Delete all global objects allocated by libprotobuf.
    // 可选：删除libprotobuf分配的所有全局对象。
    google::protobuf::ShutdownProtobufLibrary();
}

void WriteDat::promptForAddress1(tutorial::Person *person)
{
    person->set_id(1);
    person->set_name("zcj");
    person->set_email("zhuchuanjuzcj@163.com");

    tutorial::Person::PhoneNumber* phone = person->add_phones();
    phone->set_type(tutorial::Person::MOBILE);
    phone->set_number("15201015026");

    tutorial::Person::PhoneNumber* phone2 = person->add_phones();
    phone2->set_type(tutorial::Person::WORK);
    phone2->set_number("15201015023");
}

void WriteDat::promptForAddress2(tutorial::Person *person)
{
    person->set_id(2);
    person->set_name("zcj2");
    person->set_email("zhuchuanjuzcj2@163.com");

    tutorial::Person::PhoneNumber* phone = person->add_phones();

    phone->set_number("15201015027");
}
