#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int chainingPrimeConstant = 5;

long long int hashFunction(string s);

int main(int argc, char* argv[])
{
    //string testingString = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    
    string testingString = "hello there my name is andrew lee";
    cout << hashFunction(testingString) << endl;
}

long long int hashFunction(string value){
    long long int hash = 0;
    for(int i = 0; i<value.length(); i++)
    {
        if(i < 10)
            hash += value.at(i)*pow(chainingPrimeConstant, i);
        else
            hash += value.at(i)*pow(chainingPrimeConstant, 10);
    }

    return hash;
}