#include <iostream>
#include <cstdlib>
#include <experimental/filesystem>
#include <fstream>
#include <regex>
using namespace std;

bool containsMain(string);

int main(int argc, char *argv[]){
    for(auto& p: experimental::filesystem::recursive_directory_iterator(argv[1])){
        if(experimental::filesystem::is_regular_file(p)){
            if(containsMain(p.path())){
                cout << p.path() << endl;
            } 
        }
    }

    return 0;
}


//Returns true if the given file contains a main method
bool containsMain(string path){
    //Make sure the file is valid
    if(!regex_match(path, regex(".+cpp"))){ //TODO Make work with cxx, C, c files
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

