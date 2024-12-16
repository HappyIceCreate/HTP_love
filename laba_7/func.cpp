#include "func.hpp"
#include <iostream>
#include <cmath>

using namespace std;
const int MAX_N = 100;
namespace def
{
bool isPrime(int x)
{
    if (x == 1) return false;
    int r = sqrt(x);
    for (int d = 2; d <= r; d++) {
        if (x % d == 0) {
            return false;
        }
    }
    return true;
}

void read_matrix(int matrix[MAX_N][MAX_N], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

void prime_num(int matrix[MAX_N][MAX_N], int n, int prime_num[MAX_N], int &prime_cnt) {
    prime_cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (isPrime(matrix[i][j])) {
                prime_num[prime_cnt++] = matrix[i][j];
            }
        }
    }
}

void replace_primes(int matrix[MAX_N][MAX_N], int n, int prime_num[MAX_N], int prime_cnt) {
    if (prime_cnt == 0) return;

    int max_prime = prime_num[0];
    for (int i = 1; i < prime_cnt; ++i) {
        if (prime_num[i] > max_prime) {
            max_prime = prime_num[i];
        }
    }

    for (int j = 0; j < n; ++j) {
        int min_val = matrix[0][j];
        int min_indx = 0;
            for (int k = 1; k < n; ++k) {
                if (matrix[k][j] < min_val) {
                    min_val = matrix[k][j];
                    min_indx = k;
                }
            }
            matrix[min_indx][j] = max_prime;

    }
}

void print_matrix(int matrix[MAX_N][MAX_N], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

}
}