#include "main.h"

int main(int argc, char* argv[])
{
    // setting up chrono
    chrono::time_point<std::chrono::system_clock> mtfstart, mtfend, orderedstart, orderedend;

    // move to front list
    mtfstart = chrono::system_clock::now();
    MTFlist moveToFrontList;
    int moveToFrontQueryCount = moveToFrontList.readInFileAndQuery(argv[1]);
    mtfend = chrono::system_clock::now();
    cout << "MTFlist after Queries: ";
    moveToFrontList.printList();
    chrono::duration<double> mtfElapsed = mtfend - mtfstart;

    // ordered list
    orderedstart = chrono::system_clock::now();
    orderedList oList;
    int orderedListQueryCount = oList.readInFile(argv[1]);
    orderedend = chrono::system_clock::now();
    cout << "orderedList after Queries: ";
    oList.printList();
    chrono::duration<double> orderedElapsed = orderedend - orderedstart;

    cout << endl;

    cout << "MTFlist Traversal Count: " << moveToFrontQueryCount << endl;
    cout << "MTFlist time: "<< mtfElapsed.count()*1000 << " milliseconds." << endl << endl;
    cout << "orderedList Traversal Count: " << orderedListQueryCount << endl;
    cout << "orderedList time: " << orderedElapsed.count()*1000 << " milliseconds." << endl;

    cout << endl;
    if(mtfElapsed.count() > orderedElapsed.count())
        cout << "ordered list is faster for this data." << endl;
    else
        cout << "move to front is faster for this data." << endl;
}