#include <iostream>

using namespace std;

int quickSort(int*, int, int);
void swapValues(int*, int, int);
void sortMedianOfThree(int*, int, int, int);

int main()
{

}

int quicksort(int* array, int left, int right)
{
    int leftValue = array[left];
    int rightValue = array[right];
    int middleValue = array[(right-left)/2];
    if(leftValue > rightValue && leftValue > middleValue)
    {

    }
}

void swapValues(int* array, int left, int right)
{
    int tempNum = array[left];
    array[left] = array[right];
    array[right] = tempNum;
    return;
}

void sortMedianOfThree(int* array, int one, int two, int three)
{
    
}