/*Write a program that reads in a line of text and replaces all four-letter words with the word "love". For example, the input string
   I hate you, you dodo!
should produce the following output:
   I love you, you love!
Of course, the output will not always make sense. For example, the input string
   John will run home.
should produce the following output:
   Love love run love.
If the four-letter word starts with a capital letter, it should be replaced by "Love", not by "love". You need not check capitalization, except for the first letter of a word. A word is any string consisting of the letters of the alphabet and delimited at each end by a blank, the end of the line, or any other character that is not a letter.
Your program should repeat this action until the user says to quit.*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // repeat until user quits
    string line = "";
    while (line[0] != 'q')
    {
        cout << endl;
        cout <<"Enter sentence or press q(quit):";
        getline(cin, line); // read input line from user

        string word;
        for (int i = 0; i < line.length(); i++)
        {
            // check if the character is a letter (uppercase or lowercase)
            if ((line[i] <= 'z' && line[i] >= 'a') || (line[i] <= 'Z' && line[i] >= 'A'))
            {
                word = "";
                // if it's a letter, loop through the word until it ends
                while (i < line.length() && ((line[i] <= 'z' && line[i] >= 'a') || (line[i] <= 'Z' && line[i] >= 'A')))
                {
                    word += line[i];
                    i++;
                }
                i--;
            }
            else
            {
                // if it's not a letter, consider it a word of length 1
                word = line[i];
            }
            // if the word has length 4, print "love"
            if (word.size() == 4)
            {
                cout << "love";
            }
            else
            {
                // otherwise, print the word as is
                cout << word;
            }
        }
    }
}
