#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    ifstream inputFileStream;
    inputFileStream.open(argv[1]);
    
    int longestWordLength = 0;
    string word = "";
    while(inputFileStream >> word)
    {
        if(word.length() > longestWordLength)
        {
            longestWordLength = word.length();
        }
    }

    cout << longestWordLength << endl;
}