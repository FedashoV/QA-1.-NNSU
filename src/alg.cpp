// Copyright 2025 UNN-CS
#include <cstdint>
#include <vector>
#include "alg.h"

std::vector<uint64_t> figures;

bool checkPrime(uint64_t value) {
    if (value < 2) return false;
    std::vector<uint64_t> temp;
    temp.push_back(0);
    temp.push_back(0);
    for (uint64_t i = 2; i <= value; ++i) {
        temp.push_back(1);
    }
    for (uint64_t i = 2; i * i <= value; ++i) {
        if (temp[i] == 0) continue;
        for (uint64_t j = i * i; j <= value; j += i) {
            temp[j] = 0;
        }
    }
    figures = temp;
    return figures[value] == 1;
}

uint64_t nPrime(uint64_t n) {
    if (n == 0) return 0;
    uint64_t count = 0;
    uint64_t candidate = 1;
    while (count < n) {
        candidate++;
        if (checkPrime(candidate)) {
            count++;
        }
    }
    return candidate;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t candidate = value + 1;
    while (!checkPrime(candidate)) {
        candidate++;
    }
    return candidate;
}

uint64_t sumPrime(uint64_t hbound) {
    if (hbound <= 2) return 0;
    uint64_t sum = 0;
    for (uint64_t i = 2; i < hbound; ++i) {
        if (checkPrime(i)) {
            sum += i;
        }
    }
    return sum;
}
