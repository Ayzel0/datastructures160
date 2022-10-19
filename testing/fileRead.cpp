#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    int sum = 0;

    
    /*
    // creating the input file stream
    ifstream inputFileStream;
    inputFileStream.open("values.txt");

    // creating the output file stream
    ofstream outputFileStream;
    outputFileStream.open("valuesOutput.txt");

    int choice = 7;
    for(int i = 0; i<choice; i++)
    {
        cout << "*";
    }
    
    string tempString;
    int tempInt;
    while(inputFileStream >> tempString)
    {
        tempInt = stoi(tempString);
        if(tempInt >= 0)
        {
            switch(tempInt)
            {
            case 1:
                inputFileStream >> tempString;
                double height = stod(tempString);
                break;
            case 2:
                // we know that we need 3 more values, so extract 3 values from the inputFileStream
                // do calculations with those values, and write the result to the output file
                break;
            case 3:
                // we know that we need 3 more values, so extract 3 values from the inputFileStream
                // do calculations with those values, and write the result to the output file
                break;
            case 0:
                return 0;
                break;
            default:
                for(int i = 0; i<tempInt; i++)
                {
                    cout << "*";
                }
                break; 
            }
        }
        else
        {
            // say that you're being given an invalid value and terminate the program
        }
    }
    

    // reading values in from file and printing out to file
    /*
    string tempVal;
    while(inputFileStream >> tempVal)
    {
        int num = stoi(tempVal);
        intValues.push_back(num);
    }

    int product = 1;
    for(int i : intValues)
    {
        product *= i;
    }

    for(int i = 0; i<product; i++)
    {
        cout << "*";
    }
    */
}