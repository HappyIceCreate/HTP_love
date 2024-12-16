#include <iostream>
#include "func.hpp"

int main() 
{
    int n;
    std::cin >> n;

    if (n > def::MAX_N) {
        return 1;
    }

    int matrix[def::MAX_N][def::MAX_N];
    def::read_matrix(matrix, n);

    int prime_num[def::MAX_N];
    int prime_cnt = 0;

    def::prime_num(matrix, n, prime_num, prime_cnt);

    def::replace_primes(matrix, n, prime_num, prime_cnt);

    def::print_matrix(matrix, n);

    return 0;
}
