/**
 * @file fib.cpp
 * Contains Fibonacci-number generating functions both utilizing and not
 * utilizing memoization.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "fib.h"

#include <map>
#include <iostream>

using namespace std;


/**
 * Calculates the nth Fibonacci number where the zeroth is defined to be
 * 0.
 * @param n Which number to generate.
 * @return The nth Fibonacci number.
 */
unsigned long fib(unsigned long n)
{

    /* Your code goes here! */
    unsigned long result;

    if(n == 1) {
        return 1;
    }
    else if(n == 0) {
        return 0;
    } else {
         result =  fib(n-1) + fib(n-2);
    }
    return result;
}

/**
 * Calculates the nth Fibonacci number where the zeroth is defined to be
 * 0. This version utilizes memoization.
 * @param n Which number to generate.
 * @return The nth Fibonacci number.
 */
unsigned long memoized_fib(unsigned long n)
{
    /* Your code goes here! */
    static map <unsigned long, unsigned long> hash = {{0,0}, {1,1}};

    map <unsigned long, unsigned long>::iterator mapped = hash.find(n);

    if(mapped == hash.end()) {
        unsigned long found = memoized_fib(n-1) + memoized_fib(n-2);
        hash[n] = found;
        return found;
    } else if (mapped != hash.end()){
        return mapped->second;
    }

    return 0;
}