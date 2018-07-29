#include <cstdlib>
#include <string>
#include <fstream>
#include <regex>
#include "helpers.h"

using namespace std;

//Returns true if the given file contains a main method
bool containsMain(std::string path){
    //Make sure the file is of the right type
    if(!isCFile(path)){
        return false;
    }

    ifstream file;
    file.open(path);
    std::string line;
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
int isCFile(std::string fileName){
    if(regex_match(fileName, regex(".+\\.h"))){
        return 2;
    } else if (regex_match(fileName, regex(".+(\\.cpp|\\.cxx|\\.c|\\.C|\\.h)"))){
        return 1;
    }
    return 0;
}