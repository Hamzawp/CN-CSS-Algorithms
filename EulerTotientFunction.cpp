#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> primeFactors(int n)
{
    unordered_map<int, int> factors;
    for (int i = 2; i * i <= n; ++i)
    {
        while (n % i == 0)
        {
            factors[i] = factors[i] + 1;
            n /= i;
        }
    }
    if (n > 1)
    {
        factors[n] = factors[n] + 1;
    }
    return factors;
}

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void printCoprimes(int n)
{
    for (int i = 1; i < n; ++i)
    {
        if (gcd(i, n) == 1)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

void eulerTotient(int n)
{
    unordered_map<int, int> factors = primeFactors(n);
    if (factors.size() == 1 && factors[n] == 1)
    {
        cout << "Euler Totient Function: " << (n - 1) << endl;
        cout << "Coprimes: ";
        printCoprimes(n);
    }
    else
    {
        int size = factors.size();
        if (size == 2 && factors.begin()->second == 1 &&
            next(factors.begin())->second == 1)
        {
            int p = factors.begin()->first;
            int q = next(factors.begin())->first;
            int totient = (p - 1) * (q - 1);
            cout << "Euler Totient Function: " << totient << endl;
            cout << "Coprimes: ";
            printCoprimes(n);
        }
        else
        {
            int totient = 1;
            for (const auto &entry : factors)
            {
                int p = entry.first;
                int k = entry.second;
                totient *= (pow(p, k) - pow(p, k - 1));
            }
            cout << "Euler Totient Function: " << totient << endl;
            cout << "Coprimes: ";
            printCoprimes(n);
        }
    }
}

int main()
{
    for (int i = 1; i <= 3; i++)
    {
        cout << "\nEnter the number for calculating Euler Totient: ";
        int n;
        cin >> n;
        cout << endl;
        eulerTotient(n);
    }
    return 0;
}
