#include "main.h"
#include <fstream>
#include <chrono>
#include <string>

string cleanWord(string);

int main(int argc, char* argv[])
{
    // set up chrono
    chrono::time_point<std::chrono::system_clock> quadProbingStart, quadProbingEnd, chainingStart, chainingEnd;
    chrono::duration<double> quadProbingElapsed, chainingElapsed;

    // create the dictionary array
    string* dictionary = new string[500000];

    // read words from the dictionary file and insert into hash table
    ifstream dictionaryInputFileStream;
    dictionaryInputFileStream.open(argv[1]);
    string word = "";
    int count = 0;
    while(dictionaryInputFileStream >> word)
    {
        dictionary[count] = cleanWord(word);
        count++;
    }

    // create the array of words to be spell checked
    string* spellCheckWords = new string[250000];

    // read in the document to be spell checked into an array
    ifstream wordCheckerInputFileStream;
    wordCheckerInputFileStream.open(argv[2]);
    string checkWord = "";
    int spellCheckCount = 0;
    while(wordCheckerInputFileStream >> checkWord)
    {
        string pushString = "";
        if(cleanWord(checkWord) != "")
        {
            for(int i = 0; i<checkWord.length(); i++)
            {
                // check for lowercase letters
                if(checkWord.at(i) >= 97 && checkWord.at(i) <= 122)
                {
                    pushString.push_back(checkWord.at(i));
                }
                
                // check for capital letters
                else if(checkWord.at(i) >= 65 && checkWord.at(i) <= 90)
                {
                    pushString.push_back(checkWord.at(i)+32);
                }

                // else, split the word
                else
                {
                    if(pushString != "")
                    {
                        // cout << "pushing string " << pushString << " to the spell check array" << endl;
                        spellCheckWords[spellCheckCount] = pushString;
                        spellCheckCount++;
                        pushString = "";
                    }
                }
            }
        }

        // push the string to the array
        if(pushString != "")
        {
            spellCheckWords[spellCheckCount] = pushString;
            spellCheckCount++;
        }
    }

    // create the quad probing hash table
    QuadProbingHashTable qpHashTable;

    // insert words into the quadratic probing hash table
    quadProbingStart = chrono::system_clock::now();
    for(int i = 0; i<count; i++)
    {
        qpHashTable.insertValue(dictionary[i], qpHashTable.hashFunction(dictionary[i]), 0);
    }
    quadProbingEnd = chrono::system_clock::now();
    quadProbingElapsed = quadProbingEnd - quadProbingStart;

    // spell check with quadratically probing
    int misspelledCountQuadProbing = 0;
    for(int i = 0; i<spellCheckCount; i++)
    {
        if(qpHashTable.searchValue(spellCheckWords[i], qpHashTable.hashFunction(spellCheckWords[i]), 0) == -1)
        {
            //cout << "quadProbing found " << spellCheckWords[i] << " to be a misspelled word" << endl;
            misspelledCountQuadProbing++;
        }
    }

    // calculate time taken for quad probing and show number of misspelled words
    cout << misspelledCountQuadProbing << " misspelled words found with quadratic probing" << endl;
    cout << "Quadratic probing took " << quadProbingElapsed.count()*1000000000 << " nanoseconds" << endl;

    // create the chaining hash table
    ChainingHashTable chainingHashTable;

    // insert values into the chaining hash table
    chainingStart = chrono::system_clock::now();
    for(int i = 0; i<count; i++)
    {
        chainingHashTable.insertValue(dictionary[i]);
    }
    chainingEnd = chrono::system_clock::now();
    chainingElapsed = chainingEnd-chainingStart;
    
    // perform spell check with chaining hash table
    int misspelledCountChaining = 0;
    for(int i = 0; i<spellCheckCount; i++)
    {
        if(chainingHashTable.searchValue(spellCheckWords[i]) == -1)
        {
            //cout << "chaining found " << spellCheckWords[i] << " to be a misspelled word" << endl;
            misspelledCountChaining++;
        }
    }

    // calculate time taken for chaining and show number of misspelled words
    cout << misspelledCountChaining << " misspelled words found with chaining" << endl;
    cout << "Chaining took " << chainingElapsed.count()*1000000000 << " nanoseconds" << endl;
    
    if(chainingElapsed.count() > quadProbingElapsed.count())
    {
        cout << "chaining was more efficient" << endl;
    }
    else
    {
        cout << "quadratic probing was more efficient" << endl;
    }

    // deallocate memory
    delete dictionary;
    delete spellCheckWords;
}

// remove punctuation and decapitalize word
string cleanWord(string s)
{
    string returnString; 
    for(int i = 0; i<s.length(); i++)
    {
        // check for lowercase letters
        if(s.at(i) >= 97 && s.at(i) <= 122)
        {
            returnString.push_back(s.at(i));
        }
        
        // check for capital letters
        else if(s.at(i) >= 65 && s.at(i) <= 90)
        {
            returnString.push_back(s.at(i)+32);
        }

        // anything that doesn't fall into one of these two categories doesn't get pushed
    }

    return returnString;
}