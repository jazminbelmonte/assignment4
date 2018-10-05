#include <iostream>
#include "jsinspiredarray.h"
using namespace std;

int main(){
  //POP PUSH LENGTH EMPTY 
    JSInspiredArray<double> numbers;
    cout << (numbers.empty()) << endl;
    cout << (numbers.length() == 0) << endl;
    numbers.push(4.5);
    numbers.push(2.5);
    numbers.push(3.2);
    cout << (numbers.length() == 3) << endl;
    cout << (numbers.pop() == 3.2) << endl;
    cout << (numbers.length() == 2) << endl;
    cout << endl;
    
    //SHIFT UNSHIFT BEGIN END 
    JSInspiredArray<int> moreNumbers;
    moreNumbers.unshift(5);
    moreNumbers.unshift(5);
    moreNumbers.unshift(2);
    cout << (*moreNumbers.begin() == 2) << endl;
    cout << (moreNumbers.end() == LinkedListIterator<int>(nullptr)) << endl;
    cout << (moreNumbers.length() == 3) << endl;
    cout << (moreNumbers.shift() == 2) << endl;
    cout << endl;
    
    //FIND 
    JSInspiredArray<int> findNumbers;
    findNumbers.push(12);
    findNumbers.push(14);
    findNumbers.push(16);
    findNumbers.push(18);
    cout<< (*findNumbers.find(16) == 16) << endl;
    cout<< (*findNumbers.find(14) == 14) << endl;
    cout<< (findNumbers.find(15) == findNumbers.end()) << endl;
    cout<< endl;
    
    //CONCAT <<OPERATOR 
    JSInspiredArray<int> firstSet;
    firstSet.push(8);
    firstSet.push(7);
    firstSet.push(6);
    firstSet.push(5);
    cout << firstSet << endl;
    JSInspiredArray<int> secondSet;
    secondSet.push(4);
    secondSet.push(3);
    secondSet.push(2);
    secondSet.push(1);
    cout << secondSet << endl;
    firstSet.concat(secondSet);
    cout<< firstSet << endl;
    cout<< endl;
    
    //=OPERATOR
    JSInspiredArray<int> assignmentNums;
    assignmentNums.push(4);
    assignmentNums.push(7);
    assignmentNums.push(9);
    assignmentNums.unshift(2);

    JSInspiredArray<int> reassignedNums;
    reassignedNums.unshift(12);
    reassignedNums.unshift(23);
    assignmentNums = reassignedNums;
    cout << (assignmentNums.shift() == reassignedNums.shift()) << endl;
    cout << (assignmentNums.length() == reassignedNums.length()) << endl;
    cout<< endl;
    
    //COPY CONSTRUCTOR
    JSInspiredArray<double> copyNumbers;
    copyNumbers.push(9.7);
    copyNumbers.push(9.6);
    copyNumbers.push(9.5);
    copyNumbers.unshift(9.8);
    
    JSInspiredArray<double> copiedNumbers(copyNumbers);
    cout << copiedNumbers;

  return 0;
}
