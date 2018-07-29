#include <cstdlib>
#include <experimental/filesystem>
#include <iostream>
#include <fstream>
#include <regex>
using namespace std;

bool containsMain(string);
int isCFile(string);

int main(int argc, char *argv[]){
    for(auto& p: experimental::filesystem::recursive_directory_iterator(argv[1])){
        if(experimental::filesystem::is_regular_file(p)){
            cout << p.path() << " " << isCFile(p.path()) << endl;
        }
    }
    return 0;
}


//Returns true if the given file contains a main method
bool containsMain(string path){
    //Make sure the file is of the right type
    if(!isCFile(path)){
        return false;
    }

    ifstream file;
    file.open(path);
    string line;
    while(getline(file, line)){
        if(regex_search(line, regex("main"))){ //TODO Make more robost
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

//Return 2 if file extension is .h, 1 if other C/C++ source file, 0 ow
int isCFile(string fileName){
    if(regex_match(fileName, regex(".+\\.h"))){
        return 2;
    } else if (regex_match(fileName, regex(".+(\\.cpp|\\.cxx|\\.c|\\.C|\\.h)"))){
        return 1;
    }
    return 0;
}


