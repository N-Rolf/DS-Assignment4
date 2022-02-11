#include "Queue.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

int main()
{

    string a = "sword";
    string b = "shield";
    string c = "mace";
    string d = "spear";
    string e = "hammer";
    string f = "bow";
    string catchStr;

    Queue testA(5);
    
    catchStr = testA.dequeue();

    testA.enqueue(a);
    testA.enqueue(b);
    testA.enqueue(c);
    testA.enqueue(d);
    testA.enqueue(e);
    testA.enqueue(f);

    cout << "*********TestA View 1***********" <<endl;
    testA.view();

    Queue copyA(testA);

    catchStr = testA.dequeue();
    catchStr = testA.dequeue();
    catchStr = testA.dequeue();
    catchStr = testA.dequeue();
    catchStr = testA.dequeue();
    catchStr = testA.dequeue();

    cout << "*********TestA (empty) View 2***********" <<endl;
    testA.view();

    testA.enqueue(a);
    testA.enqueue(b);
    testA.enqueue(c);

    //cout << "Dequeued value in main: " << d << endl;

    cout << "*********TestA View 2***********" <<endl;
    testA.view();

    // cout << "*********CopyA View***********" <<endl;
    // copyA.view();

    // copyA.enqueue(a);
    // copyA.enqueue(b);
    // copyA.enqueue(c);

    // catchStr = copyA.dequeue();
    // catchStr = copyA.dequeue();
    // catchStr = copyA.dequeue();
    // catchStr = copyA.dequeue();
    // catchStr = copyA.dequeue();
    // catchStr = copyA.dequeue();



    // copyA.enqueue(a);
    // copyA.enqueue(b);
    // copyA.enqueue(c);

    return 0;
}
