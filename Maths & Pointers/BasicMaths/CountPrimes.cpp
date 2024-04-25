#include<iostream> 
#include<cmath> 

using namespace std;

// Naive Approach
int isPrime1(int n) {
    int result = 1;
    if (n == 1) {
        result = 0;
    } 
    for (int i = 2 ; i < n ; i++) {
        if (n % i == 0) {
            result = 0;
        }
    }
    return result;
}

int countPrimes1(int n) {
    int count = 0;
    for (int i = 2 ; i < n ; i++) {
        if (isPrime1(i)) {
            count++;
        }
    }
    return count;
}

int isPrime2(int n) {
    int result = 1;
    if (n == 1) {
        result = 0;
    } 
    for (int i = 2 ; i < sqrt(n) ; i++) {
        if (n % i == 0) {
            result = 0;
        }
    }
    return result;
}

int countPrimes2(int n) {
    int count = 0;
    for (int i = 2 ; i < n ; i++) {
        if (isPrime2(i)) {
            count++;
        }
    }
    return count;
}

// Sieve of Eratosthenes
bool isPrime3(int n) {
    
}

int main() {
    
}