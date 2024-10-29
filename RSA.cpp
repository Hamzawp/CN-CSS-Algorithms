#include <iostream>
using namespace std;

int power(int a, int b, int mod)
{
    int x = a;
    int result = 1;
    int count = 0;
    cout << "--------------------------------------------------" << endl;
    while (b > 0)
    {
        if ((b & 1) == 1)
            result = (result * a) % mod;
        if ((b & 1) == 1)
            cout << "Binary Expo: " << x << "^" << (1 << count) << endl;
        a = (a * a) % mod;
        b >>= 1;
        count++;
    }
    cout << "--------------------------------------------------" << endl;
    return result;
}

int encryption(int e, int m, int n)
{
    if (m < n)
    {
        int cipher = power(m, e, n);
        return cipher;
    }
    else
    {
        return -1;
    }
}

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int decryption(int d, int c, int n)
{
    int message = power(c, d, n);
    return message;
}

int extendedEuclidean(int r1, int r2)
{
    int t1 = 0;
    int t2 = 1;
    while (r2 > 0)
    {
        int q = r1 / r2;
        int rem = r1 % r2;
        int t = t1 - (q * t2);
        r1 = r2;
        r2 = rem;
        t1 = t2;
        t2 = t;
    }
    return t1;
}

int calculateD(int e, int phi)
{
    int d = extendedEuclidean(phi, e);
    if (d < 0)
    {
        d += phi;
    }
    return d;
}

int calculateE(int phi)
{
    for (int i = 2; i < phi; i++)
    {
        if (gcd(phi, i) == 1)
        {
            return i;
        }
    }
    return -1;
}

bool isPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cout << "Enter the value of p: ";
    int p;
    cin >> p;
    cout << "Enter the value of q: ";
    int q;
    cin >> q;
    if (isPrime(p) && isPrime(q))
    {
        int n = p * q;
        int phi = (p - 1) * (q - 1);
        int e = calculateE(phi);
        int d = calculateD(e, phi);
        cout << "phi(n): " << phi << endl;
        cout << "e: " << e << endl;
        cout << "d: " << d << endl;
        int message;
        cout << "Enter the Message: ";
        cin >> message;
        int cipher = encryption(e, message, n);
        if (cipher != -1)
        {
            cout << "Encrypted Text: " << cipher << endl;
            int decryptedMessage = decryption(d, cipher, n);
            cout << "Decrypted Text: " << decryptedMessage << endl;
        }
        else
        {
            cout << "Encryption not possible, choose big p and q." << endl;
        }
    }
    else
    {
        cout << "Both p and q should be prime." << endl;
    }
    return 0;
}