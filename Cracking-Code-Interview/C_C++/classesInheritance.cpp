#include <iostream>

using namespace std;

class Myclass{
    private:
        int data;
    
    public:
        Myclass(int val): data(val) {}
        //getter
        int getData(){
            return this->data;
        }

        //setter
        void setData(int val){
            this->data = val;
        }
        void myFunc();
};

void Myclass:: myFunc(){
    cout << data << endl;
}

class ChildClass : public Myclass{
    private:
        string name;
    public:
        // ChildClass(string value){
        //     this->name = value;
        // }
};

int main(void){
    Myclass obj(90);
    obj.myFunc();
    return 0;
}