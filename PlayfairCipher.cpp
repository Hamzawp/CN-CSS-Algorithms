#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;

char mat[5][5];
const char PADD_CHAR = 'x';
bool is_odd = false;

void generate_the_matrix(string key)
{
    int checkSmall[26] = {0};
    int r = 0, c = 0;
    for (int i = 0; i < key.length(); i++)
    {
        if (key[i] == 'j')
        {
            key = key.substr(0, i) + 'i' + key.substr(i + 1);
        }
        if (checkSmall[key[i] - 'a'] == 0)
        {
            mat[r][c++] = key[i];
            checkSmall[key[i] - 'a'] = 1;
        }
        if (c == 5)
        {
            c = 0;
            r++;
        }
    }
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        if (ch == 'j')
        {
            continue;
        }
        if (checkSmall[ch - 'a'] == 0)
        {
            checkSmall[ch - 'a'] = 1;
            mat[r][c++] = ch;
        }
        if (c == 5)
        {
            c = 0;
            r++;
        }
    }
}
string partition(string text)
{
    for (int i = 0; i < text.length(); i += 2)
    {
        if (text[i] == text[i + 1])
        {
            text.insert(i + 1, 1, PADD_CHAR);
        }
    }
    if (text.length() % 2 == 1)
    {
        text += PADD_CHAR;
        is_odd = true;
    }
    return text;
}
string encryption(string text, int flag)
{
    string result;
    cout << "Encryption Process:\n";
    for (int i = 0; i < text.length(); i += 2)
    {
        int p1[2], p2[2];
        p1[0] = -1;
        p1[1] = -1;
        p2[0] = -1;
        p2[1] = -1;
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (mat[j][k] == text[i])
                {
                    p1[0] = j;
                    p1[1] = k;
                }
                if (mat[j][k] == text[i + 1])
                {
                    p2[0] = j;
                    p2[1] = k;
                }
                if (p1[0] != -1 && p2[0] != -1)
                {
                    break;
                }
            }
            if (p1[0] != -1 && p2[0] != -1)
            {
                break;
            }
        }
        char ch1, ch2;
        if (p1[0] == p2[0])
        {
            ch1 = mat[p1[0]][(p1[1] + flag) % 5];
            ch2 = mat[p2[0]][(p2[1] + flag) % 5];
        }
        else if (p1[1] == p2[1])
        {
            ch1 = mat[(p1[0] + flag) % 5][p1[1]];
            ch2 = mat[(p2[0] + flag) % 5][p2[1]];
        }
        else
        {
            ch1 = mat[p1[0]][p2[1]];
            ch2 = mat[p2[0]][p1[1]];
        }
        result.push_back(ch1);
        result.push_back(ch2);
        cout << text[i] << text[i + 1] << "---- " << ch1 << ch2 << "\n";
    }
    return result;
}
int main()
{
    string text, key;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the Key: ";
    getline(cin, key);
    text.erase(remove_if(text.begin(), text.end(), ::isspace), text.end());
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    key.erase(remove_if(key.begin(), key.end(), ::isspace), key.end());
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    generate_the_matrix(key);
    cout << "The Playfair Matrix: " << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    string f_msg = partition(text);
    cout << "\nFormatted msg: " << f_msg << "\n"
         << endl;
    string cipher = encryption(f_msg, 1);
    cout << "\nEncrypted msg: " << cipher << "\n"
         << endl;
    cout << "Decryption Process:\n";
    string decryptedMsg = encryption(cipher, 4);
    cout << "\nDecrypted msg: " << decryptedMsg << endl;
    return 0;
}
