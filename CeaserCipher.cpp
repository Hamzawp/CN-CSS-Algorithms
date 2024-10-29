#include <cctype>
#include <iostream>
using namespace std;

string encrypt(const string &text, int shift)
{
    string result = "";
    for (char ch : text)
    {
        if (isalpha(ch))
        {
            char base = isupper(ch) ? 'A' : 'a';
            result += static_cast<char>((ch - base + shift) % 26 + base);
        }
        else
        {
            result += ch;
        }
    }
    return result;
}
int main()
{
    string plaintext;
    int shift;
    cout << "Enter the text to encrypt: ";
    getline(cin, plaintext);
    cout << "Enter the shift value: ";
    cin >> shift;
    string ciphertext = encrypt(plaintext, shift);
    cout << "Encrypted text: " << ciphertext << endl;
    return 0;
}
