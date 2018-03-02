// test.cpp
//
// "I pledge my honor that I've abided by the Stevens Honor System."
//
// Nicholas Primamore and Matthew Monaco
//

#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>

#define TOTAL_TESTS 3

bool run_test(int test_number) {
    switch(test_number) {
        case 1: {
            // test01 :
            break;
        }
            
        case 2: {
            // test02
            break;
        }
            
        case 3: {
            // test03 :
            break;
        }
            
            /*
             case 4: {
             // test04 : (description here)
             (implementation here)
             break; // if your test suceeds, break
             }
             */
            
        default: {
            printf("ERROR! Test number %d was not found!\n", test_number);
            exit(1);
        }
            
    }
    // test must have passed.
    return true;
}

int main() {
    int num_fail = 0;
    for (int tn = 1; tn <= TOTAL_TESTS; tn++) {
        printf("- running test # %02d ... ", tn);
        int result = run_test(tn);
        printf("%s\n", (result == true ? "succeed" : "FAIL"));
        if (result == false) num_fail++;
    }
    printf("SUMMARY: %d FAIL, %d succeed\n", num_fail, TOTAL_TESTS - num_fail);
}



