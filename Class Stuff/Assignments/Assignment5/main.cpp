// ======================================
// Julien Savary
// CS 1D
// Professor Lebowitz
// ======================================
// Assignment #5: Priority Queues
// ======================================
// Description:
//
// Implement a priority queue using a binary heap.
// The program simulates a hospital emergency room.
// The program reads in the patients and then removes
// them from the queue based on their priority. STL
//
// ======================================
// File: main.cpp
// ======================================

#include "header.h"
#include "PriorityQueue.h"

void test_one(PriorityQueue<string, int> test);

int main()
{

    // Student implemented priority queue
    PriorityQueue<string, int> tree;
    // STL implemented priority queue
    priority_queue<int> prio;

    // This function will output the class header to the console
    ClassHeader();

    // This first test checks to see if the ADT is working
    cout << "Student implemented priority queue:\n\n";
    test_one(tree);

    cout << endl
         << endl;

    // This second test checks to see if the STL is working
    cout << "STL implemented priority queue:\n\n";
    test_two(prio);

    return 0;
}

void test_one(PriorityQueue<string, int> test)
{
    int time = 1200;

    // Reads in the non critical patients
    test.insert("Bob Bleeding", 6);
    test.insert("Frank Feelingbad", 3);
    test.insert("Cathy Coughing", 5);
    test.insert("Paula Pain", 4);
    test.insert("Alice Ailment", 7);
    test.insert("Irene Ill", 1);
    test.insert("Tom Temperature", 8);

    // Outputs the next patient and the time they start
    cout << "Time : " << time << endl;
    cout << name(test.front()) << " is to be helped next\n\n";
    time += 25;
    test.dequeue();

    // Outputs the next patient and the time they start
    cout << "Time : " << time << endl;
    cout << name(test.front()) << " is to be helped next\n\n";
    time += 25;
    test.dequeue();

    // Outputs the next patient and the time they start
    cout << "Time : " << time << endl;
    cout << "Alice Ailment is to be helped next\n\n";
    time += 25;
    test.dequeue();

    // Outputs the next patient and the time they start
    cout << "Time : " << (time = 1315) << endl;
    cout << "Cathy Coughing is to be helped next\n\n";
    time += 19;

    // Outputs the critical patient
    cout << "Time : " << time << endl;
    test.insertCrit("Sam Sneezing", 100);
    cout << "Sam Sneezing is to be helped now\n\n";
    time += 25;
    test.dequeue();

    // Outputs the next patient and the time they start
    cout << "Time : " << time << endl;
    cout << "Cathy Coughing is to be helped next\n\n";
    time += 6;
    test.dequeue();

    // Outputs the next patient and the time they start
    cout << "Time : " << (time = 1405) << endl;
    cout << name(test.front()) << " is to be helped next\n\n";
    time += 7;

    // Outputs the critical patient
    cout << "Time : " << time << endl;
    test.insertCrit("Sid Sickly", 100);
    cout << "Sid Sickly is to be helped now\n\n";
    time += 25;
    test.dequeue();

    // Outputs the next patient and the time they start
    cout << "Time : " << time << endl;
    cout << name(test.front()) << " is to be helped next\n\n";
    time += 18;
    test.dequeue();

    // Outputs the next patient and the time they start
    cout << "Time : " << time << endl;
    cout << name(test.front()) << " is to be helped next\n\n";
    time += 25;
    test.dequeue();

    // Outputs the next patient and the time they start
    cout << "Time : " << (time = 1520) << endl;
    cout << name(test.front()) << " is to be helped next\n\n";
    time += 25;
    test.dequeue();

    // Outputs the time at the end of the program
    cout << "Time : " << time << endl;
}