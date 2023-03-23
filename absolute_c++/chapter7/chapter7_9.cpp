/*Prior to 2009 the bar code on an envelope used by the U.S. Postal Service repre- sented a five (or more) digit zip code using a format called POSTNET. The bar code consists of long and short bars as shown here:
For this program, we will represent the bar code as a string of digits. The digit 1 represents a long bar, and the digit 0 represents a short bar. Therefore, the bar code shown would be represented in our program as follows:
   110100101000101011000010011
The first and last digits of the bar code are always 1. Removing these leave 25 digits. If these 25 digits are split into groups of five digits each then we have the following:
   10100 10100 01010 11000 01001
Next, consider each group of five digits. There always will be exactly two 1’s in each group of digits. Each digit stands for a number. From left to right, the digits encode the values 7, 4, 2, 1, and 0. Multiply the corresponding value with the digit and compute the sum to get the final encoded digit for the zip code. The following table shows the encoding for 10100.
Zip Code Digit = 7 + 0 + 2 + 0 + 0 = 9
Repeat this for each group of five digits and concatenate to get the complete zip code. There is one special value. If the sum of a group of five digits is 11, then this represents the digit 0 (this is necessary because with two digits per group it is not possible to represent zero). The zip code for the sample bar code decodes to 99504. While the POSTNET scheme may seem unnecessarily complex, its design allows machines to detect whether errors have been made in scanning the zip code.
Bar Code Digits
1 0 1 0 0
Value
7 4 2 1 0
Product of Digit * Value
7 0 2 0 0
Write a zip code class that encodes and decodes five-digit bar codes used by the U.S. Postal Service on envelopes. The class should have two constructors. The first constructor should input the zip code as an integer, and the second constructor should input the zip code as a bar code string consisting of 0’s and 1’s as described above. Although you have two ways to input the zip code, internally, the class should only store the zip code using one format. (You may choose to store it as a bar code string or as a zip code number.) The class also should have at least two public member functions: one to return the zip code as an integer and the other to return the zip code in bar code format as a string. All helper functions should be declared private. Embed your class definition in a suitable test program.*/

#include <iostream>
#include <string>

using namespace std;

class Posta
{
public:
    Posta();
    Posta(string kod);
    Posta(int number);
    void calBarCod(string kod);
    void calCodBar(int number);

private:
    string barCod;
    int value[5] = {0, 1, 2, 4, 7};
};
Posta::Posta()
{
    barCod = "";
}
Posta::Posta(string kod)
{
    barCod = "0000000000000000000000000";
    calBarCod(kod);
}
Posta::Posta(int num)
{
    barCod = "";
    calCodBar(num);
}
void Posta::calBarCod(string kod)
{
    barCod = "0000000000000000000000000";
    for (int i = 1; i < 26; i++) // Copy the 25 digits of the input string to barCod
    {
        barCod[i - 1] = kod[i];
    }
    int totalCount = 0;
    int count = 0;
    int sum = 0;
    int deger[5] = {0};
    int i = -1;
    while (totalCount != 25) // Divide the 25 digits of barCod into groups of 5, and calculate the sum of each group
    {
        count = 0;
        sum = 0;
        while (count != 5) // Sum the products of each digit and its corresponding value in the value array
        {
            sum += (barCod[totalCount] - '0') * value[count];
            totalCount++;
            count++;
        }
        i++;
        deger[i] = sum; // Store the sum of the group in the deger
    }
    cout << "Barkod " << kod << "convert to  ";
    for (int j = 0; j < 5; j++)
    {
        cout << deger[j];
    }
    cout << " number" << endl;
}
void Posta::calCodBar(int number)
{
    int N = number;
    // Calculate the barcode digits for each digit of the given number.
    for (int i = 0; i < 5; i++)
    {
        // Get the last digit of the number.
        int son_basamak = number % 10;
        // Remove the last digit from the number.
        number = number / 10;
        // Add the corresponding barcode digits for the last digit.
        switch (son_basamak)
        {
        case 0:
            barCod += "00001";
            break;
        case 1:
            barCod += "00010";
            break;
        case 2:
            barCod += "00101";
            break;
        case 3:
            barCod += "00110";
            break;
        case 4:
            barCod += "01000";
            break;
        case 5:
            barCod += "01010";
            break;
        case 6:
            barCod += "01100";
            break;
        case 7:
            barCod += "10001";
            break;
        case 8:
            barCod += "10010";
            break;
        case 9:
            barCod += "10100";
            break;
        default:
            break;
        }
    }
    // Reverse the barcode digits.
    int n = barCod.size();
    for (int i = 0; i < n / 2; i++)
    {
        swap(barCod[i], barCod[n - i - 1]);
    }
    // Add the start and stop digits to the barcode.
    barCod = "1" + barCod + "1";
    // Print the converted barcode.
    cout << "Number " << N << " converted to barcode " << barCod << endl;
}

int main()
{
    Posta p("110100101000101011000010011");
    Posta pstl(22518);
}