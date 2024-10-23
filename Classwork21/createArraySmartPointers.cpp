#include <memory>
#include <iostream>
#include "print.h"
namespace array {
    void createArraySmartPointers() {

        int sizeOriginal = 5;
        int input = 0, sum = 0, counter = 0;


        std::unique_ptr<int[]> arrayOriginal(new int[sizeOriginal]);
        std::shared_ptr<int[]> arrayNew(new int[sizeOriginal * 2]);

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
            }
            else {
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


                //copies info to new array
                for (int i = 0; i < sizeOriginal; i++) {
                    arrayNew[i] = arrayOriginal[i];
                }

                // doubles array size and
                sizeOriginal *= 2;
                changeArray = true;

            }
        }
        array::print(arrayNew, sizeOriginal, sum);

    }
}
