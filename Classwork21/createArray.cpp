#include <iostream>
#include "createArray.h"

void createArray() {
    int sizeOriginal = 5;
    int input = 0, sum = 0, counter = 0;

    int* arrayOriginal = new int[sizeOriginal];
    int* arrayNew = nullptr;

    // flag to check to see if the array has been switched 
    bool changeArray = false;

    while (true) {
        std::cout << "Please input a number.\n";
        std::cin >> input;
        if (std::cin.fail()) {
            break;
        }

        // checks to see which array to send the input to
        if (changeArray == true) {
            arrayNew[counter] = input;
        } else {
            arrayOriginal[counter] = input;
        }

        counter++;
        sum += input;

        // checks to see if we should exit the while loop
        if (counter >= sizeOriginal && changeArray == true) {
            break;
        }

        // creates new array if the counter size exeeds the array size
        if (counter >= (sizeOriginal)) {
            std::cout << "Switching arrays\n";

            arrayNew = new int[sizeOriginal * 2];

            //copies info to new array
            for (int i = 0; i < sizeOriginal; i++) {
                arrayNew[i] = arrayOriginal[i];
            }

            // doubles array size and
            sizeOriginal *= 2;
            changeArray = true;

        }
    }

    // prints the array
    for (int i = 0; i < sizeOriginal; i++) {
        std::cout << arrayNew[i] << ' ';
    }

    std::cout << " the sum is:" << sum << std::endl;

    // deleting and resetting pointers
    delete arrayOriginal;
    delete arrayNew;
    arrayOriginal = nullptr;
    arrayNew = nullptr;
}