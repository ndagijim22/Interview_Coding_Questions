#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    unordered_map<string, int> umap;

    // inserting values by using [] operator
    umap["GeeksforGeeks"] = 10;
    umap["Practice"] = 20;
    umap["Contribute"] = 30;

    //traverse
    for(auto it: umap){
        cout << "Key: " << it.first << " " << "Value: " << it.second << endl;
    }

    try{
        cout << umap.at("Contribute") << endl;
    }
    catch(const out_of_range &e){
        cerr << "Exception at " << e.what() << endl;
    }
    return 0;
}