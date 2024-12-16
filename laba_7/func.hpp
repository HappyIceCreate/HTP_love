#pragma once
#include <iostream>
#include <cmath>

using namespace std;
namespace def
{
bool isPrime(int x);
const int MAX_N = 100;

    void read_matrix(int matrix[MAX_N][MAX_N], int n);

    void prime_num(int matrix[MAX_N][MAX_N], int n, int prime_num[MAX_N], int &prime_cnt);

    void replace_primes(int matrix[MAX_N][MAX_N], int n, int prime_num[MAX_N], int prime_cnt);

    void print_matrix(int matrix[MAX_N][MAX_N], int n);
}