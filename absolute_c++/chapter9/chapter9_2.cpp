/*Write a program that will read in a line of text and output the number of words in the line and the number of occurrences of each letter.
Define a word to be any string of letters that is delimited at each end by either whitespace, a period, a comma, or the beginning or end of the line. You can assume that the input consists entirely of letters, whitespace, commas, and periods.
When outputting the number of letters that occur in a line, be sure to count uppercase and lowercase versions of a letter as the same letter. Output the letters in alphabetical order and list only those letters that occur in the input line. For example, the input line
I say Hi.
should produce output similar to the following:
3 words 1a
1h
2i
1s 1y*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string sen;
    getline(cin, sen);

    // Count the number of words in the sentence
    int wordCount = 0;
    for (int i = 0; i < sen.length(); i++)
    {
        if (sen[i] == ' ' || sen[i] == '.' || sen[i] == ',' || sen[i] == '\n')
        {
            wordCount++;
        }
    }
    cout << wordCount + 1 << " words\n";
    // Count the number of occurrences of each letter
    int charCount[26] = {0};
    for (int i = 0; i < sen.length(); i++)
    {
        char c = tolower(sen[i]);
        if (c >= 'a' && c <= 'z')
        {
            charCount[c - 'a']++;
        }
    }
    // Output the counts for each letter in alphabetical order
    for (int i = 0; i < 26; i++)
    {
        if (charCount[i] > 0)
        {
            cout << charCount[i] << (char)('a' + i) << endl;
        }
    }
    return 0;
}
