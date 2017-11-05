//
//  main.cpp
//  Computational Biology
//
//  Created by Anand Kulkarni on 11/1/17.
//  Copyright © 2017 Anand Kulkarni. All rights reserved.
//

#include "../include/hash.hpp"

int main (int argc, const char * argv[]) {
    float minHashNumber =  minHash("ABCDEF", "ABCDEE",4,3);
    cout << minHashNumber;
    return 0;
}
