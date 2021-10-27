#include "Queue.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

int main()
{

    Queue testA;
    Queue copyA(testA);

    testA.enqueue("shit");
    testA.enqueue("fuck");
    testA.enqueue("tits");


    cout << "*********View***********" <<endl;
    testA.view();

    return 0;
}
