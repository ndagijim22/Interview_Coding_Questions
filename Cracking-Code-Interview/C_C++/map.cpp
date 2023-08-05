#include <iostream>
#include <map>

using namespace std;

int main(){
    map<string, int> mp, mp2;

    //insert values
    mp["one"] = 1;
    mp["two"] = 2;
    mp["three"] = 3;

    //insert pair using insert()
    mp.insert({"four", 4});
    mp.insert({"five", 5});
    mp.insert({"nine", 5}); //this is okay. The problem is one you have the same keys for 2 diff values
    
    //iterate through the map and print elts
    auto it = mp.begin();
    while(it != mp.end()){
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
        it++;
    }
    cout << "Map size is: " << mp.size() << endl;
    cout << "Max size of mp " << mp.max_size() << endl;

    if(mp2.empty())
        cout << "True" << endl;
    else 
        cout << "False" << endl;

    return 0;
}