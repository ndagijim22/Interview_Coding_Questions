#include <iostream>
#include <string>

using namespace std;

class Person{
    private:
        string name;
        int age;
    public:
        Person(string name, int age): name(name), age(age) {}

        Person(){}

        void setName(string name){
            this->name = name;
        }

        void setAge(int age){
            this->age = age;
        }

        int getAge(){
            return this->age;
        }

        string getName(){
            return this->name;
        }
};

int main(){
    Person person;
    
    person.setAge(99);
    person.setName("John");

    cout << "Name: " << person.getName() << endl;
    cout << "Age: " << person.getAge() << endl;

    person.setAge(60);
    person.setName("Moses Karemera");

    cout << "Name: " << person.getName() << endl;
    cout << "Age: " << person.getAge() << endl;

    return 0;
}