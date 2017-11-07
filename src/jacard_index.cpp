#include "../include/hash.hpp"
#include "../../include/index.hpp"

int main(int argc, const char * argv[]) {
    cout << getJacardIndex("ABCDE","ABCFE",3) <<endl;
    return 0;
}