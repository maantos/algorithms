// MaxHeap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "maxHeap.h"
#include <queue>
int main()
{
    MaxHeap heap = MaxHeap(10);
    heap.insertKey(15);
    heap.insertKey(7);
    heap.insertKey(6);
    heap.insertKey(12);
    heap.insertKey(10);
    heap.insertKey(5);
    heap.print();
    heap.deletekey(4);
    heap.print();


    std::priority_queue <int> pq;
    pq.push(15);
    pq.push(7);
    pq.push(6);
    pq.push(12);
    pq.push(10);
    pq.push(5);
    std::cout << "-----\n";
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
