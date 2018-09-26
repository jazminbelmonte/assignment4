#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <sstream>
#include "jsinspiredarray.h"
using namespace std;

TEST_CASE("Push and pop") {
    JSInspiredArray<double> numbers;
    REQUIRE(numbers.empty());
    REQUIRE(numbers.length() == 0);
    numbers.push(4.5);
    REQUIRE(numbers.length() == 1);
    numbers.push(7.2);
    numbers.push(9.4);
    numbers.push(10.6);
    REQUIRE(numbers.length() == 4);
    REQUIRE(numbers.pop() == 10.6);
    REQUIRE(numbers.length() == 3);
    REQUIRE(numbers.pop() == 9.4);
    REQUIRE(numbers.pop() == 7.2);
    REQUIRE(!numbers.empty());
    REQUIRE(numbers.length() == 1);
    REQUIRE(numbers.pop() == 4.5);
    REQUIRE(numbers.empty());
    REQUIRE_THROWS(numbers.pop());
}

TEST_CASE("Unshift and shift") {
    JSInspiredArray<double> numbers;
    REQUIRE(numbers.empty());
    REQUIRE(numbers.length() == 0);
    numbers.unshift(4.5);
    REQUIRE(numbers.length() == 1);
    numbers.unshift(7.2);
    numbers.unshift(9.4);
    numbers.unshift(10.6);
    REQUIRE(numbers.length() == 4);
    REQUIRE(numbers.shift() == 10.6);
    REQUIRE(numbers.length() == 3);
    REQUIRE(numbers.shift() == 9.4);
    REQUIRE(numbers.shift() == 7.2);
    REQUIRE(!numbers.empty());
    REQUIRE(numbers.length() == 1);
    REQUIRE(numbers.shift() == 4.5);
    REQUIRE(numbers.empty());
    REQUIRE_THROWS(numbers.shift());
}

TEST_CASE("Mixed push, unshift, pop, and shift") {
    JSInspiredArray<int> numbers;
    numbers.push(4);
    numbers.unshift(7);
    numbers.push(9);
    numbers.unshift(12);
    REQUIRE(numbers.length() == 4);
    REQUIRE(numbers.pop() == 9);
    REQUIRE(numbers.shift() == 12);
    REQUIRE(numbers.shift() == 7);
    REQUIRE(numbers.pop() == 4);
    REQUIRE(numbers.length() == 0);
    REQUIRE(numbers.empty());
    REQUIRE_THROWS(numbers.shift());
    REQUIRE_THROWS(numbers.pop());
}

TEST_CASE("Find") {
    JSInspiredArray<int> numbers;
    numbers.push(4);
    numbers.unshift(7);
    numbers.push(9);
    numbers.unshift(12);
    numbers.unshift(2);
    REQUIRE(*numbers.find(7) == 7);
    REQUIRE(*numbers.find(4) == 4);
    REQUIRE(*numbers.find(2) == 2);
    REQUIRE(*numbers.find(9) == 9);
    REQUIRE(numbers.find(15) == numbers.end());
}

TEST_CASE("Concat") {
    JSInspiredArray<int> numbers;
    numbers.push(4);
    numbers.unshift(7);
    numbers.push(9);
    numbers.unshift(12);
    numbers.unshift(2);
    REQUIRE(numbers.length() == 5);

    JSInspiredArray<int> moreNumbers;
    moreNumbers.unshift(12);
    moreNumbers.unshift(23);
    REQUIRE(moreNumbers.length() == 2);

    moreNumbers.concat(numbers);
    REQUIRE(moreNumbers.length() == 7);
    REQUIRE(*moreNumbers.find(12) == 12);
}

TEST_CASE("Begin and end") {
    JSInspiredArray<int> numbers;
    numbers.push(4);
    numbers.push(7);
    numbers.push(9);
    numbers.unshift(1);
    REQUIRE(*numbers.begin() == 1);
    REQUIRE(numbers.end() == LinkedListIterator<int>(nullptr));

    for(auto n : numbers){
        REQUIRE(n == *numbers.find(n));
    }
}

TEST_CASE("Constructors and assignment") {
    JSInspiredArray<int> numbers;
    numbers.push(4);
    numbers.push(7);
    numbers.push(9);
    numbers.unshift(2);

    JSInspiredArray<int> moreNumbers;
    moreNumbers.unshift(12);
    moreNumbers.unshift(23);

    JSInspiredArray<int> numbers2(numbers);
    REQUIRE(numbers.length() == numbers2.length());
    for(int i = 0; i < 4; i++){
        REQUIRE(numbers.pop() == numbers2.pop());
    }

    REQUIRE(numbers.empty());

    numbers = moreNumbers;
    REQUIRE(numbers.shift() == moreNumbers.shift());
    REQUIRE(numbers.length() == moreNumbers.length());
}

TEST_CASE("Operator<<") {
    stringstream sout1, sout2;
    JSInspiredArray<int> numbers;
    sout1 << numbers;
    numbers.push(4);
    numbers.push(7);
    numbers.push(9);
    numbers.unshift(2);
    sout2 << numbers;

    REQUIRE(sout1.str() == "");
    REQUIRE(sout2.str() == "2,4,7,9");
}