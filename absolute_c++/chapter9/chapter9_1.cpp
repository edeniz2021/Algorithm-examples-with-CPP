/*Write a program that will read in a sentence of up to 100 characters and output the sentence with spacing corrected and with letters corrected for capitalization. In other words, in the output sentence all strings of two or more blanks should be compressed to a single blank.
The sentence should start with an uppercase letter but should contain no other uppercase letters. Do not worry about proper names; if their first letter is changed to lowercase, that is acceptable. Treat a line break as if it were a blank in the sense that a line break and any number of blanks are com- pressed to a single blank. Assume that the sentence ends with a period and contains no other periods.
For example, the input
the    Answer to life, the Universe, and  everything
 IS 42.
should produce the following output:
The answer to life, the universe, and everything is 42.*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
   // read input sentence
   string sen;
   getline(cin, sen);

   // truncate the sentence if it's longer than 100 characters
   if (sen.length() > 100)
   {
      sen = sen.substr(0, 100);
   }

   // initialize variables
   int count = 0;
   string neWord = "";
   
   // process each character in the sentence
   for (int i = 0; i < sen.length(); i++)
   {
      char c = sen[i];
      // if the character is a newline or a space, replace it with a space
      if (i < sen.length() - 1)
      {
         if (c == '\n' || c == ' ')
         {
            c = ' ';
         }
      }
      // if it's the first character and it's a letter, make it uppercase
      if (i == 0 && isalpha(c))
      {
         c = toupper(c);
      }
      // if it's not the first character and it's a letter, make it lowercase
      else if (i != 0 && isalpha(c))
      {
         c = tolower(c);
      }
      // add the modified character to the new sentence
      neWord += c;
   }
   // output the new sentence
   cout << neWord;
}
