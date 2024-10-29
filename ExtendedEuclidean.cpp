#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;
    int r1 = max(a, b);
    int r2 = min(a, b);
    a = r1;
    b = r2;
    int s1 = 1;
    int s2 = 0;
    int t1 = 0;
    int t2 = 1;
    cout << "Q r1 r2 r s1 s2 s t1 t2 t" << endl;
    cout << "------------------------------------" << endl;
    while (r2 > 0)
    {
        int q = r1 / r2;
        int rem = r1 % r2;
        int s = s1 - (q * s2);
        int t = t1 - (q * t2);
        cout << q << " " << r1 << " " << r2 << " " << rem << " " << s1 << " " << s2
             << " " << s << " " << t1 << " " << t2 << " " << t << endl;
        r1 = r2;
        r2 = rem;
        s1 = s2;
        s2 = s;
        t1 = t2;
        t2 = t;
    }
    cout << endl;
    cout << "The Euclidean Eq is ax + by = GCD: " << endl;
    cout << "Proof: " << endl;
    cout << "a is : " << a << endl;
    cout << "b is : " << b << endl;
    cout << "x is : " << s1 << endl;
    cout << "y is : " << t1 << endl;
    cout << "GCD is : ax + by i.e " << a << "(" << s1 << ") + " << b << "(" << t1
         << ") = " << (a * s1 + b * t1) << endl;
    return 0;
}