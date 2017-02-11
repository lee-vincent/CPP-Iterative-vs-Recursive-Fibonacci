//
//  main.cpp
//  lab10
//
//  Created by Vincent Lee on 12/1/15.
//  Copyright © 2015 10k Bulbs. All rights reserved.
//

#include <iostream>
#include <ctime>


unsigned long long fibIt(unsigned int n);
unsigned long long fibRec(unsigned int n);
long factorial(int n);
long factorialHelper (int n, int result);
long rfactorial (int n);

int main(int argc, const char * argv[]) {
    
    const unsigned long long FIBONNACI_ITERATIONS = 10000000;
    const unsigned long long FACTORIAL_ITERATIONS = 100000000;
    
    std::cout << "Calculating Fibonacci numbers...this may take a few seconds\n" << std::endl;
    clock_t fibTimeIterative;
    clock_t fibTimeRecursive;

    fibTimeIterative = clock();
    for(unsigned long long n = 0; n < FIBONNACI_ITERATIONS; n++) {
        unsigned long long throwAway = fibIt(10);
    }
    fibTimeIterative = clock() - fibTimeIterative;
    
    
    fibTimeRecursive = clock();
    for(unsigned long long n = 0; n < FIBONNACI_ITERATIONS; n++) {
        unsigned long long throwAway = fibRec(10);
    }
    fibTimeRecursive = clock() - fibTimeRecursive;


    std::cout << "Calculated the 10th Fibonacci number " << FIBONNACI_ITERATIONS << " times using iteration and recursion.\n" << std::endl;
    std::cout << "Recursion: " << fibTimeRecursive/(float)CLOCKS_PER_SEC << " seconds." << std::endl;
    std::cout << "Iteration: " << fibTimeIterative/(float)CLOCKS_PER_SEC << " seconds.\n" << std::endl;
    
    
    
    
    
    
    
    std::cout << "Calculating factorials...this may take a few seconds\n" << std::endl;
    clock_t facTimeSingleRecursion;
    clock_t facTimeTail;
    
    facTimeSingleRecursion = clock();
    for(unsigned long long n = 0; n < FACTORIAL_ITERATIONS; n++) {
        unsigned long long throwAway = rfactorial(10);
    }
    facTimeSingleRecursion = clock() - facTimeSingleRecursion;
    
    
    facTimeTail = clock();
    for(unsigned long long n = 0; n < FACTORIAL_ITERATIONS; n++) {
        unsigned long long throwAway = factorial(10);
    }
    facTimeTail = clock() - facTimeTail;
    
    
    std::cout << "Calculated 10! " << FACTORIAL_ITERATIONS << " times using single recursion and tail recursion.\n" << std::endl;
    std::cout << "Single Recursion: " << facTimeSingleRecursion/(float)CLOCKS_PER_SEC << " seconds.\n" << std::endl;
    std::cout << "Tail Recursion: " << facTimeTail/(float)CLOCKS_PER_SEC << " seconds.\n" << std::endl;
    
    
    return 0;
}



// return the n'th Fibonacci number
// 7/11/13 Levin Fritz
// http://codereview.stackexchange.com/questions/28346/fibonacci-sequence-implementation
unsigned long long fibIt(unsigned int n) {
    if (n == 0) return 0;
    unsigned long long previous = 0;
    unsigned long long current = 1;
    for (unsigned int i = 1; i < n; ++i) {
        unsigned long long next = previous + current;
        previous = current;
        current = next;
    }
    return current;
}


// Programming Abstractions in C++
// Eric Roberts
// Stanford University
unsigned long long fibRec(unsigned int n){
    if(n < 2)
        return n;
    else
        return fibRec(n-1) + fibRec(n-2);
}




long rfactorial (int n) {
    if (n == 1)
        return 1;
    else
        return n * rfactorial(n-1);
}




long factorialHelper (int n, int result) {
    if (n == 1)
        return result;
    else
        return factorialHelper(n-1,n*result);
}

long factorial(int n) {
    return factorialHelper(n,1);
}







