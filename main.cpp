#include <iostream>
#include <cstdlib>
#include <experimental/filesystem>

using namespace std;

int main(int argc, char *argv[]){
    for(auto& p: experimental::filesystem::recursive_directory_iterator(argv[1])){
        if(experimental::filesystem::is_regular_file(p)){
            cout << p.path() << endl;
        }
    }

    return 0;
}
