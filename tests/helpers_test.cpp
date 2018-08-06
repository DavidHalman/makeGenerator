#include <iostream>
#include <cstdlib>
#include <assert.h>

#include "../src/helpers.h"
#include "test.h"

void helpers_test(){
        
    //Tests for isCFile(std::string fileName)
    assert(isCFile("test.h") == 2);
    assert(isCFile("test.cpp") == 1);
    assert(isCFile("test.c") == 1);
    assert(isCFile("test.C") == 1);
    assert(isCFile("test.d") == 0);
    assert(isCFile(".cpp.") == 0);
    assert(isCFile(".cpp ") == 0);
    
    //Tests for containsMain(std::string path) TODO
}
