#include <string>
using namespace std;

class MyString{
    public:
        char* data;

        //shallow copy constructor
        MyString(const MyString& other): data(other.data){}

        //deep copy
        MyString(const MyString& other){
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }

        //destctror
        ~MyString(){
            delete[] data;
        }
};