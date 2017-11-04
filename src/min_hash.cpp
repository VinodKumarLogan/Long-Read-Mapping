//
//  main.cpp
//  Computational Biology
//
//  Created by Anand Kulkarni on 11/1/17.
//  Copyright © 2017 Anand Kulkarni. All rights reserved.
//

#include "../include/hash.h"

int main (int argc, const char * argv[]) {
    vector<string> shringles = getShringles("ABCDE",3);
    minHash("ABCDEF", "ABCDEE",4,3);
    return 0;
}