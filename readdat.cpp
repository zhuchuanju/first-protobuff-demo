#include "readdat.h"

ReadDat::ReadDat()
{
    test();
}

ReadDat::~ReadDat()
{

}

void ReadDat::test()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    string strFile = "firstPro.dat";
    ifstream fin(strFile, ios::in | std::ios::binary);

    tutorial::AddressBook address_book;
    address_book.ParseFromIstream(&fin);

    showAddressBook(address_book);

    google::protobuf::ShutdownProtobufLibrary();
}

void ReadDat::showAddressBook(const tutorial::AddressBook &addressBook)
{
    for (int i = 0; i < addressBook.people_size(); ++i)
    {
        string prinInfo = "";
        const tutorial::Person& person = addressBook.people(i);

        prinInfo += "Person id: " + to_string(person.id()) + "\n";
        prinInfo += "Person name: " + person.name() + "\n";
        if (person.has_email())
        {
            prinInfo += "Person email: " + person.email() + "\n";
        }

        for (int j = 0; j < person.phones_size(); ++j)
        {
            const tutorial::Person::PhoneNumber& phoneNumber = person.phones(j);
            switch (phoneNumber.type()) {
            case tutorial::Person::MOBILE:
                prinInfo += " mobile: " + phoneNumber.number() + "\n";
                break;
            case tutorial::Person::HOME:
                prinInfo += " home: " + phoneNumber.number() + "\n";
                break;
            case tutorial::Person::WORK:
                prinInfo += " work: " + phoneNumber.number() + "\n";
                break;
            default:
                break;
            }
        }
        cout << prinInfo << endl;
    }
}













