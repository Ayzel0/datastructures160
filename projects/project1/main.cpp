#include "main.h"

int main(int argc, char* argv[])
{
    cout << "program started" << endl;
    cout << "text file name is " << argv[1] << endl;

    // move to front list
    MTFlist moveToFrontList;
    moveToFrontList.readInFileAndQuery(argv[1]);
    moveToFrontList.printList();

    // ordered list
    orderedList oList;
    oList.readInFile(argv[1]);
    oList.printList();
}