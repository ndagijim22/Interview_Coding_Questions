#include <iostream>
using namespace std;

#define NAME_SIZE 50

class Person{
    //all members are private by default
    int id;
    char name[NAME_SIZE];

    public:
        void aboutMe(){
            cout << "I'm a person" << endl;
        }
};

class Student : public Person{
    public:
        void aboutMe(){
            cout << "I'm a student" << endl;
        }
};

int main(){
    Student *p = new Student();
    p->aboutMe();
    delete p; //delete allocated memory

    return 0;
}