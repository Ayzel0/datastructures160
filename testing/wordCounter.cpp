#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    ifstream inputFileStream;
    inputFileStream.open(argv[1]);
    int count = 0;
    string word = "";
    while(inputFileStream >> word)
    {
        count++;
    }
    cout << count << endl;
}