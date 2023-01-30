// ====================================================
// Julien Savary
// CS 1D
// Professor Lebowitz
// ====================================================
// Assignment 1: (Recursion): Palindrome
// This function ignores white spaces, capital letters,
// and punctuation marks. For example:
// "A man a plan a canal Panama" would be a palindrome.
// The program outputs if the string entered is
// a palindrome or not. And the user can exit.
// ====================================================
// ====================================================
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Function Prototypes
bool isPalindrome(string str);
bool isPalindrome(string str, int start, int end);
void removePunctuation(string &str);
void removeSpaces(string &str);
void toLower(string &str);

// ====================================================

int main()
{
    string str;
    char choice;
    do
    {
        cout << "Enter a string: ";
        getline(cin, str);

        // these three functions help to filter the input
        removePunctuation(str);
        removeSpaces(str);
        toLower(str);

        if (isPalindrome(str))
            cout << "The string is a palindrome." << endl;
        else
            cout << "The string is not a palindrome." << endl;

        cout << "Do you want to continue? (y/n): ";
        cin >> choice;
        cin.ignore();

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

// this function calls the recursive function isPalindrome
bool isPalindrome(string str)
{
    return isPalindrome(str, 0, str.length() - 1);
}

// this function checks if the string is a palindrome
bool isPalindrome(string str, int start, int end)
{
    //if it starts with what it ends then it is a palindrome
    if (start >= end)
        return true; // TRUE
    else if (str[start] != str[end])
        return false; // FALSE
    else
        return isPalindrome(str, start + 1, end - 1);
}

// this function iterates through the string and removes all punctuation marks.
void removePunctuation(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (ispunct(str[i]))
        {
            str.erase(i, 1);
            i--;
        }
    }
}

// this function iterates through the string and removes all white spaces.
void removeSpaces(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (isspace(str[i]))
        {
            str.erase(i, 1);
            i--;
        }
    }
}

// this function iterates through the string and converts all capital letters to lower case.
void toLower(string &str)
{
    for (int i = 0; i < str.length(); i++)
        str[i] = tolower(str[i]);
}

// ====================================================
// ====================================================
// Output
/*This is my palindrome program. It runs. It first
  prompts us to enter a string. We can then exit by
  writing N or n. A little different but not too much.
  Finding a way to make the program case insentive
  was tough but I found a way by creating multiple
  functions which do their own seperate work. No global
  variables were used and the program does not seem to
  bug as much as when I used fgets.
  I hope you enjoy my program.
    Thank you.
Enter a string: Racecar
The string is a palindrome.
Do you want to continue? (y/n): y
Enter a string: Dad
The string is a palindrome.
Do you want to continue? (y/n): y
Enter a string: Mom
The string is a palindrome.
Do you want to continue? (y/n): y
Enter a string: Was it a cat I saw?
The string is a palindrome.
Do you want to continue? (y/n): y
Enter a string: Saddleback College
The string is not a palindrome.
Do you want to continue? (y/n): y
Enter a string: CS 1D
The string is not a palindrome.
Do you want to continue? (y/n): y
Enter a string: A man a plan a canal Panama
The string is a palindrome.
Do you want to continue? (y/n): y
Enter a string: The rain in Spain
The string is not a palindrome.
Do you want to continue? (y/n): Y
Enter a string: RAdar
The string is a palindrome.
Do you want to continue? (y/n): N *
// ====================================================
// ====================================================