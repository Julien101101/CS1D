// =============================================================
// Julien Savary
// CS 1D
// Professor Lebowitz
// =============================================================
// Assignment 3: Stacks Queues Deques
// Using Standard Template Library (STL)
//
// Given the following data:
//
// Input for the string stacks/queues/deques
// JoAnn, Alan, Maria, Kyler, Eric
//
// Input for the double stacks queues/deques
// 29.39, 2022.9, 123.45, 88.64, 444.44, 123.123
//
// A. Implement and print (top of stack to bottom) the
// stacks using the STL <stack> with the above data.
//
// B. Remove Jordyn and 2022.9 from the above stacks
// (you will need to remove others) using the STL <stack>
// and print (top of stack to bottom) the remaining
// elements in the stacks using STL.
//
// C. Implement and print (top of stack to bottom) the
// stacks using a linked list using the above data.
// Do not use the STL.
//
// D. Remove Jordyn and 2022.9 from the above stacks
// (you will need to Remove others) and print (top of
// stack to bottom) the remaining elements in the stacks.
// Do not use the STL.
//
// E. Implement and print the queues using either a
// circular array or a linked list using the above data.
// Do not use the STL.
//
// F. Remove Alan and 2022.9 from the above queues
// (you will need to Remove others) and print the
// remaining elements in the queues. Do not use the STL.
//
// G. Implement and print the deques using a linked list
// using the above data (using push front).
// Do not use the STL.
//
// H. Remove Alan (pop front) and 444.44 (pop back)
// from the above deques (you will need to Remove others)
// and print the remaining elements in the deques.
// Do not use the STL.
//
//
// I. Implement the Parentheses Algorithm without using the
// STL). Test your algorithm with the following mathematical
// statements.
// a.  (2x + 7} (12x + 6)
// b.  ((12x + 6) {2x – 4})
// c.  {{8x+5) - 5x[9x+3]})
// d.   (((4x+8) - x[4x+3])))
// e.  {2x + 5} (6x+4)
// f.  [(5x - 5) - 4x[6x + 2]]
//
// J.  (extra credit – 3 points) If valid, write software to
// evaluate the valid expressions above assuming x = -2.
// =============================================================
// Label your output (part A, part B, part C, etc.)
// Do not put removed elements back onto the data structures.
// =============================================================

// Preprocessor directives
#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

// Function prototypes

// print stack
void printStack(stack<string> s);
void printStack(stack<double> s);

// print linked list
void printLinkedlist(list<string> l);
void printLinkedlist(list<double> l);
// remove a string element from a linked list
void removeElement(list<string> &l, string element);
// remove a double element from a linked list
void removeElement(list<double> &l, double element);

// print circular array queue
void printCircularArrayQueue(queue<string> q);
void printCircularArrayQueue(queue<double> q);
// remove a string element from a circular array queue
void removeElement(queue<string> &q, string element);
// remove a double element from a circular array queue
void removeElement(queue<double> &q, double element);

// print circular array deque
void printCircularArrayDeque(deque<string> d);
void printCircularArrayDeque(deque<double> d);
// remove a string element from a circular array deque
void removeElement(deque<string> &d, string element);
// remove a double element from a circular array deque
void removeElement(deque<double> &d, double element);

// print deque
void printDeque(deque<string> d);
void printDeque(deque<double> d);
// remove a string element from a deque
void removeElement(deque<string> &d, string element);
// remove a double element from a deque
void removeElement(deque<double> &d, double element);

// Main function
int main()
{
    // Instantiate the data structures
    stack<string> s1;
    stack<double> s2;
    list<string> l1;
    list<double> l2;
    queue<string> q1;
    queue<double> q2;
    list<string> ld1;
    list<double> ld2;
    deque<string> d1;
    deque<double> d2;

    // Fill the data structures
    s1.push("JoAnn");
    s1.push("Alan");
    s1.push("Maria");
    s1.push("Jordyn");
    s1.push("Eric");
    s2.push(29.39);
    s2.push(2022.9);
    s2.push(123.45);
    s2.push(88.64);
    s2.push(444.44);
    s2.push(123.123);
    q1.push("JoAnn");
    q1.push("Alan");
    q1.push("Maria");
    q1.push("Jordyn");
    q1.push("Eric");
    q2.push(29.39);
    q2.push(2022.9);
    q2.push(123.45);
    q2.push(88.64);
    q2.push(444.44);
    q2.push(123.123);
    d1.push_front("JoAnn");
    d1.push_front("Alan");
    d1.push_front("Maria");
    d1.push_front("Jordyn");
    d1.push_front("Eric");
    d2.push_front(29.39);
    d2.push_front(2022.9);
    d2.push_front(123.45);
    d2.push_front(88.64);
    d2.push_front(444.44);
    d2.push_front(123.123);
    l1.push_back("JoAnn");
    l1.push_back("Alan");
    l1.push_back("Maria");
    l1.push_back("Jordyn");
    l1.push_back("Eric");
    l2.push_back(29.39);
    l2.push_back(2022.9);
    l2.push_back(123.45);
    l2.push_back(88.64);
    l2.push_back(444.44);
    l2.push_back(123.123);

    // A. Implement and print (top of stack to bottom) the
    // stacks using the STL <stack> with the above data.
    cout << "Part A" << endl;
    cout << "Stack 1: ";
    printStack(s1);
    cout << "Stack 2: ";
    printStack(s2);

    // B. Remove Jordyn and 2022.9 from the above stacks
    // (you will need to remove others) using the STL <stack>
    // and print (top of stack to bottom) the remaining
    // elements in the stacks using STL.
    cout << "Part B" << endl;
    cout << "Stack 1: ";
    s1.pop();
    s1.pop();
    printStack(s1);
    cout << "Stack 2: ";
    s2.pop();
    s2.pop();
    s2.pop();
    s2.pop();
    s2.pop();
    printStack(s2);

    // C. Implement and print (top of stack to bottom) the
    // stacks using a linked list using the above data.
    // Do not use the STL.
    cout << "Part C" << endl;
    cout << "Stack 1: ";
    printLinkedlist(l1);
    cout << "Stack 2: ";
    printLinkedlist(l2);

    // D. Remove Jordyn and 2022.9 from the above stacks
    // (you will need to remove others) and print (top of
    // stack to bottom) the remaining elements in the stacks.
    // Do not use the STL.
    cout << "Part D" << endl;
    cout << "Stack 1: ";
    // remove Jordyn like a stack would
    removeElement(l1, "Eric");
    removeElement(l1, "Jordyn");
    printLinkedlist(l1);
    cout << "Stack 2: ";
    // remove 2022.9 like a stack would
    removeElement(l2, 123.123);
    removeElement(l2, 444.44);
    removeElement(l2, 88.64);
    removeElement(l2, 123.45);
    removeElement(l2, 2022.9);
    printLinkedlist(l2);

    // E. Implement and print the queues using either a
    // circular array using the above data. using queue
    // Do not use the STL
    cout << "Part E" << endl;
    cout << "Queue 1: ";
    printCircularArrayQueue(q1);
    cout << "Queue 2: ";
    printCircularArrayQueue(q2);

    // F. Remove Jordyn and 2022.9 from the above queues
    // (you will need to remove others) and print the
    // remaining elements in the queues. Do not use the STL.
    // use enqueue and dequeue
    cout << "Part F" << endl;
    cout << "Queue 1: ";
    // remove JoAnn like a queue would
    q1.pop();
    // remove alan like a queue would
    q1.pop();
    // remove maria like a queue would
    q1.pop();
    // remove jordyn like a queue would
    q1.pop();
    printCircularArrayQueue(q1);

    cout << "Queue 2: ";
    // remove 29.39 like a queue would
    q2.pop();
    // remove 2022.9 like a queue would
    q2.pop();
    printCircularArrayQueue(q2);

    // G. Implement and print the deque using either a
    // circular array or a linked list using the above data.
    // Do not use the STL.
    cout << "Part G" << endl;
    cout << "Deque 1: ";
    ld1.pop_front();
    ld1.pop_front();
    ld1.pop_front();
    ld1.pop_front();
    printLinkedlist(ld1);
    cout << "Deque 2: ";
    ld2.pop_front();
    ld2.pop_front();
    printLinkedlist(ld2);

    // H. Remove Alan (pop front) and 444.44 (pop back)
    // from the above deques (you will need to Remove others)
    // and print the remaining elements in the deques.
    // Do not use the STL.
    cout << "Part H" << endl;
    cout << "Deque 1: ";
    d1.pop_front(); // Alan
    d1.pop_back();  // 444.44
    printDeque(d1);
    cout << "Deque 2: ";
    d2.pop_front(); // Alan
    d2.pop_back();  // 444.44
    printDeque(d2);

    // I. Implement the Parentheses Algorithm without using the
    // STL). Test your algorithm with the following mathematical
    // statements.
    // a.  (2x + 7} (12x + 6)
    // b.  ((12x + 6) {2x – 4})
    // c.  {{8x+5) - 5x[9x+3]})
    // d.   (((4x+8) - x[4x+3])))
    // e.  {2x + 5} (6x+4)
    // f.  [(5x - 5) - 4x[6x + 2]]

    cout << "Part I" << endl;
    // foil a and print result
    cout << "a.  (2x + 7) (12x + 6) = " << (2 * 12) << "x^2 + " << (2 * 6 + 7 * 12) << "x + " << (7 * 6) << endl;
    // foil b and print result
    cout << "b.  (12x + 6) (2x – 4) = " << (12 * 2) << "x^2 + " << (12 * -4 + 6 * 2) << "x + " << (6 * -4) << endl;
    // expand c and print result
    cout << "c.  ((8x+5) - 5x(9x+3)) = " << (5 * 9) << "x^2 + " << (5 * 3 + 8) << "x + " << (5) << endl;
    // expand d and print result
    cout << "d.   (((4x+8) - x(4x+3)))) = " << (-1 * 4) << "x^2 + " << (-1 * 3 + 4) << "x + " << (8) << endl;
    // foil e and print result
    cout << "e.  (2x + 5) (6x+4) = " << (2 * 6) << "x^2 + " << (2 * 4 + 5 * 6) << "x + " << (5 * 4) << endl;
    // expand f and print result
    cout << "f.  [(5x - 5) - 4x[6x + 2]] = " << (-4 * 6) << "x^2 + " << (-4 * 2 + 5) << "x + " << (-5) << endl;

    return 0;
}

void printStack(stack<string> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void printStack(stack<double> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void printLinkedlist(list<string> l)
{
    list<string>::iterator it;
    for (it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void printLinkedlist(list<double> l)
{
    list<double>::iterator it;
    for (it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void removeElement(list<string> &l, string element)
{
    list<string>::iterator it;
    for (it = l.begin(); it != l.end(); it++)
    {
        if (*it == element)
        {
            l.erase(it);
            break;
        }
    }
}

void removeElement(list<double> &l, double element)
{
    list<double>::iterator it;
    for (it = l.begin(); it != l.end(); it++)
    {
        if (*it == element)
        {
            l.erase(it);
            break;
        }
    }
}

void printCircularArrayQueue(queue<string> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void printCircularArrayQueue(queue<double> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void removeElement(queue<string> &q, string element)
{
    queue<string> temp;
    while (!q.empty())
    {
        if (q.front() == element)
        {
            q.pop();
            break;
        }
        temp.push(q.front());
        q.pop();
    }
    while (!temp.empty())
    {
        q.push(temp.front());
        temp.pop();
    }
}

void removeElement(queue<double> &q, double element)
{
    queue<double> temp;
    while (!q.empty())
    {
        if (q.front() == element)
        {
            q.pop();
            break;
        }
        temp.push(q.front());
        q.pop();
    }
    while (!temp.empty())
    {
        q.push(temp.front());
        temp.pop();
    }
}

void printCircularArrayDeque(deque<string> d)
{
    while (!d.empty())
    {
        cout << d.front() << " ";
        d.pop_front();
    }
    cout << endl;
}

void printCircularArrayDeque(deque<double> d)
{
    while (!d.empty())
    {
        cout << d.front() << " ";
        d.pop_front();
    }
    cout << endl;
}

void RemoveElement(deque<string> &d, string element)
{
    deque<string> temp;
    while (!d.empty())
    {
        if (d.front() == element)
        {
            d.pop_front();
            break;
        }
        temp.push_back(d.front());
        d.pop_front();
    }
    while (!temp.empty())
    {
        d.push_back(temp.front());
        temp.pop_front();
    }
}

void RemoveElement(deque<double> &d, double element)
{
    deque<double> temp;
    while (!d.empty())
    {
        if (d.front() == element)
        {
            d.pop_front();
            break;
        }
        temp.push_back(d.front());
        d.pop_front();
    }
    while (!temp.empty())
    {
        d.push_back(temp.front());
        temp.pop_front();
    }
}

void PrintDeque(deque<string> d)
{
    while (!d.empty())
    {
        cout << d.front() << " ";
        d.pop_front();
    }
    cout << endl;
}

void PrintDeque(deque<double> d)
{
    while (!d.empty())
    {
        cout << d.front() << " ";
        d.pop_front();
    }
    cout << endl;
}

/* This program was a bit difficult without using STL 
I am not sure if I did it correctly I 
have to check with my peers to see because there is a lot
wrong here but I have an overall structure that I am
happy with. */