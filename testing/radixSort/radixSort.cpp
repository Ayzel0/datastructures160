#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    ifstream inputFileStream;
    inputFileStream.open(argv[1]);

    string readString;
    while(inputFileStream >> readString)
    {
        
    }
}