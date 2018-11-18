#include <iostream>
#include <fstream>
#include <cmath>


int main(int argc, const char * argv[])
{
    int arraySize = 4;
    double *numbers = new double [arraySize];
    int numValues = 0;
    double value,
           total = 0.0,
           average;

    std::ifstream myReadFile;
    
    myReadFile.open(argv[1]);
    
    //Testing for file open errors before processing it
    if(myReadFile)
    {
        while (myReadFile >> value)
        {
            if(numValues == arraySize) 
            {
                double *tempArray = new double[arraySize * 2];
                for(int i = 0; i < arraySize; i++)
                {
                    tempArray[i] = numbers[i];
                }
                arraySize = arraySize * 2;
                delete [] numbers;
                numbers = tempArray; 
                tempArray = nullptr;
            }
            numbers[numValues] = value;
            total += value;
            numValues++;
        }
        //The condition will evaluate to true if the attempted file operation failed and it was not the end of the file
        if (myReadFile.fail() && !(myReadFile.eof()))
        {
            std::cout << "The file contained invalid input.\nThe program will terminate." << std::endl;
            exit(1);
        }
        myReadFile.close();
    }
    else
    {
        std::cout << "Error opening the file.\n"; 
        exit(1);
    }

    average = total / numValues;

    for(int i = 0; i < numValues; i++)
    {
        if(numbers[i] > average)
        {
            numbers[i] = round(numbers[i] * 1000) / 1000.0;
            std::cout << numbers[i] << " ";
        }   
    }

    return 0;
}