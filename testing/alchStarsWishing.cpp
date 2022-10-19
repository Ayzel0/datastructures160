#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int numberOfTrials = 10000;
    int probability = 20;
    double averageNumOfRolls = 0;
    vector<int> rollCounter;

    for(int i = 0; i<numberOfTrials; i++)
    {
        // seeding random number generator
        srand(time(NULL)+i);
        
        bool rolled = false;
        int pityCounter = 0;

        // reset probability
        probability = 20;

        while(rolled == false)
        {
            // one roll
            pityCounter++;

            // check if we're over 50 yet
            if(pityCounter > 50)
            {
                probability += 25;
            }

            if(rand()%1000 < probability)
            {
                // roll was successful
                rollCounter.push_back(pityCounter);
                rolled = true;
            }
        }
    }

    // print out the average
    double average = 0;
    double sum = 0;
    for(int num : rollCounter)
    {
        sum += num;
    }
    average = sum/numberOfTrials;
    cout << average << endl;
}