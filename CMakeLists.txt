cmake_minimum_required(VERSION 3.17)
project(primes C)

include_directories(.)

set(CMAKE_C_STANDARD 11)

add_executable(primes main.c int32list.c filtered_sieve/FilteredSieve.c filtered_sieve/FilteredSieve.h)

add_executable(int32ListTest int32list.c tests/int32ListTest.c)
