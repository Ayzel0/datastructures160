#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int readInNumbersAndAdd(string fileName)
{
    ifstream inputFileStream;
    inputFileStream.open(fileName);
    int sum = 0;
    
    if(!inputFileStream.is_open())
    {
        cout << "file did not open successfully" << endl;
        return -1;
    }

    else
    {
        string readString;
        while(inputFileStream >> readString)
        {
            int tempInt = stoi(readString);
            sum += tempInt;
        }
    }

    return sum;
}

int doubleInt(int &numberToBeDoubled)
{
    numberToBeDoubled = numberToBeDoubled*2;
    return numberToBeDoubled;
}

void doubleIntNoReturn(int &numberToBeDoubled)
{
    numberToBeDoubled = numberToBeDoubled*2;
}

int main()
{
    int num = 5;
    doubleIntNoReturn(num);
    cout << num << endl;
}