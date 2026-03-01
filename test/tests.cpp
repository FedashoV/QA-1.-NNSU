// Copyright 2025 UNN-CS

#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"

TEST(checkPrimeTest, SmallNumbers) {
    EXPECT_FALSE(checkPrime(0));
    EXPECT_FALSE(checkPrime(1));
    EXPECT_TRUE(checkPrime(2));
    EXPECT_TRUE(checkPrime(3));
    EXPECT_FALSE(checkPrime(4));
    EXPECT_TRUE(checkPrime(5));
    EXPECT_FALSE(checkPrime(6));
    EXPECT_TRUE(checkPrime(7));
    EXPECT_FALSE(checkPrime(8));
    EXPECT_FALSE(checkPrime(9));
    EXPECT_FALSE(checkPrime(10));
}

TEST(checkPrimeTest, PrimeNumbers) {
    EXPECT_TRUE(checkPrime(11));
    EXPECT_TRUE(checkPrime(13));
    EXPECT_TRUE(checkPrime(17));
    EXPECT_TRUE(checkPrime(19));
    EXPECT_TRUE(checkPrime(23));
    EXPECT_TRUE(checkPrime(29));
    EXPECT_TRUE(checkPrime(31));
    EXPECT_TRUE(checkPrime(37));
    EXPECT_TRUE(checkPrime(41));
    EXPECT_TRUE(checkPrime(43));
}

TEST(checkPrimeTest, CompositeNumbers) {
    EXPECT_FALSE(checkPrime(12));
    EXPECT_FALSE(checkPrime(14));
    EXPECT_FALSE(checkPrime(15));
    EXPECT_FALSE(checkPrime(16));
    EXPECT_FALSE(checkPrime(18));
    EXPECT_FALSE(checkPrime(20));
    EXPECT_FALSE(checkPrime(21));
    EXPECT_FALSE(checkPrime(22));
    EXPECT_FALSE(checkPrime(24));
    EXPECT_FALSE(checkPrime(25));
}

TEST(checkPrimeTest, LargeNumbers) {
    EXPECT_TRUE(checkPrime(997));
    EXPECT_FALSE(checkPrime(999));
    EXPECT_TRUE(checkPrime(1009));
    EXPECT_TRUE(checkPrime(1013));
    EXPECT_FALSE(checkPrime(1000));
}

TEST(nPrimeTest, FirstPrimes) {
    EXPECT_EQ(2, nPrime(1));
    EXPECT_EQ(3, nPrime(2));
    EXPECT_EQ(5, nPrime(3));
    EXPECT_EQ(7, nPrime(4));
    EXPECT_EQ(11, nPrime(5));
    EXPECT_EQ(13, nPrime(6));
    EXPECT_EQ(17, nPrime(7));
    EXPECT_EQ(19, nPrime(8));
    EXPECT_EQ(23, nPrime(9));
    EXPECT_EQ(29, nPrime(10));
}

TEST(nPrimeTest, MediumPrimes) {
    EXPECT_EQ(31, nPrime(11));
    EXPECT_EQ(37, nPrime(12));
    EXPECT_EQ(41, nPrime(13));
    EXPECT_EQ(43, nPrime(14));
    EXPECT_EQ(47, nPrime(15));
    EXPECT_EQ(53, nPrime(16));
    EXPECT_EQ(59, nPrime(17));
    EXPECT_EQ(61, nPrime(18));
    EXPECT_EQ(67, nPrime(19));
    EXPECT_EQ(71, nPrime(20));
}

TEST(nPrimeTest, LargerPrimes) {
    EXPECT_EQ(97, nPrime(25));
    EXPECT_EQ(541, nPrime(100));
    EXPECT_EQ(7919, nPrime(1000));
}

TEST(nPrimeTest, EdgeCases) {
    EXPECT_EQ(0, nPrime(0));
    EXPECT_EQ(2, nPrime(1));
}

TEST(nextPrimeTest, SmallNumbers) {
    EXPECT_EQ(2, nextPrime(0));
    EXPECT_EQ(2, nextPrime(1));
    EXPECT_EQ(3, nextPrime(2));
    EXPECT_EQ(5, nextPrime(3));
    EXPECT_EQ(5, nextPrime(4));
    EXPECT_EQ(7, nextPrime(5));
    EXPECT_EQ(7, nextPrime(6));
    EXPECT_EQ(11, nextPrime(7));
    EXPECT_EQ(11, nextPrime(8));
    EXPECT_EQ(11, nextPrime(9));
    EXPECT_EQ(11, nextPrime(10));
}

TEST(nextPrimeTest, MediumNumbers) {
    EXPECT_EQ(13, nextPrime(11));
    EXPECT_EQ(13, nextPrime(12));
    EXPECT_EQ(17, nextPrime(13));
    EXPECT_EQ(17, nextPrime(14));
    EXPECT_EQ(17, nextPrime(15));
    EXPECT_EQ(17, nextPrime(16));
    EXPECT_EQ(19, nextPrime(17));
    EXPECT_EQ(19, nextPrime(18));
    EXPECT_EQ(23, nextPrime(19));
    EXPECT_EQ(23, nextPrime(20));
}

TEST(nextPrimeTest, EdgeCases) {
    EXPECT_EQ(2, nextPrime(1));
    EXPECT_EQ(3, nextPrime(2));
    EXPECT_EQ(101, nextPrime(100));
}

TEST(nextPrimeTest, ConsecutiveCalls) {
    uint64_t prime = nextPrime(10);
    EXPECT_EQ(11, prime);
    prime = nextPrime(prime);
    EXPECT_EQ(13, prime);
    prime = nextPrime(prime);
    EXPECT_EQ(17, prime);
    prime = nextPrime(prime);
    EXPECT_EQ(19, prime);
}

TEST(sumPrimeTest, SmallSums) {
    EXPECT_EQ(0, sumPrime(0));
    EXPECT_EQ(0, sumPrime(1));
    EXPECT_EQ(0, sumPrime(2));
    EXPECT_EQ(2, sumPrime(3));
    EXPECT_EQ(5, sumPrime(4));
    EXPECT_EQ(10, sumPrime(6));
    EXPECT_EQ(17, sumPrime(8));
    EXPECT_EQ(17, sumPrime(9));
    EXPECT_EQ(17, sumPrime(10));
}

TEST(sumPrimeTest, KnownSums) {
    EXPECT_EQ(17, sumPrime(10));  
    EXPECT_EQ(28, sumPrime(12));
    EXPECT_EQ(41, sumPrime(14));
    EXPECT_EQ(58, sumPrime(16));
    EXPECT_EQ(77, sumPrime(18));
    EXPECT_EQ(100, sumPrime(20));
    EXPECT_EQ(129, sumPrime(22));
    EXPECT_EQ(160, sumPrime(24));
    EXPECT_EQ(160, sumPrime(25));
}

TEST(sumPrimeTest, LargerSums) {
    EXPECT_EQ(1060, sumPrime(100));
    EXPECT_EQ(76127, sumPrime(1000));
}

TEST(sumPrimeTest, FromAssignment) {
    uint64_t res = sumPrime(2000000);
    uint64_t expected = 142913828922;
    EXPECT_EQ(expected, res);
}

TEST(sumPrimeTest, EdgeCases) {
    EXPECT_EQ(0, sumPrime(0));
    EXPECT_EQ(0, sumPrime(1));
    EXPECT_EQ(0, sumPrime(2));
    EXPECT_EQ(2, sumPrime(3));
}
