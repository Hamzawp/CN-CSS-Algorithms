#include <bits/stdc++.h>
using namespace std;

int main()
{

    string ip_address;

    cout << "Enter the IP Address" << endl;
    cin >> ip_address;

    vector<int> ip;

    istringstream ss(ip_address);
    string token;

    while (getline(ss, token, '.'))
    {
        ip.push_back(stoi(token));
    }

    char classs = 'A';

    if (ip[0] >= 0 && ip[0] < 128)
    {
        classs = 'A';
    }
    else if (ip[0] >= 128 && ip[0] < 192)
    {
        classs = 'B';
    }
    else if (ip[0] >= 192 && ip[0] < 223)
    {
        classs = 'C';
    }

    cout << "This IP address belongs to the class : " << classs << endl;

    int subnets;
    cout << "Enter the no of subnets" << endl;
    cin >> subnets;

    int adjSub = 0;
    int numIP = 0;
    int add = 0;
    int addL = 0;
    int addH = 0;

    int in;

    switch (classs)
    {
    case 'A':
        cout << "Network mask is 255.0.0.0" << endl;
        cout << "No. of IP Address available are 2^24" << endl;

        for (int i = 0; i < 24; i++)
        {
            if (pow(2, i) >= subnets)
            {
                adjSub = pow(2, i);
                in = i;
                break;
            }
        }

        numIP = pow(2, 24) / adjSub;
        add = 256 / adjSub;
        addL = 0;
        addH = addL + add - 1;
        cout << endl;
        cout << "Total no of IP Address Possible in each subnet : " << numIP << endl;
        cout << "Total no. of bits in Subnet id: " << in << endl;
        for (int i = 1; i <= subnets; i++, addL = addL + add, addH = addH + add)
        {
            cout << "For Subnet " << i << endl;
            cout << "Subnet Address: " << ip[0] << "." << addL << ".0.0" << endl;
            cout << "Broadcast Address: " << ip[0] << "." << addH << ".255.255" << endl;
            cout << "Valid Range: " << ip[0] << "." << addL << ".0.1"
                 << " to " << ip[0] << "." << addH << ".255.254" << endl;
            cout << endl;
        }

        break;

    case 'B':

        cout << "Network mask is 255.255.0.0" << endl;
        cout << "No. of IP Address available are 2^16" << endl;

        for (int i = 0; i < 16; i++)
        {
            if (pow(2, i) >= subnets)
            {
                adjSub = pow(2, i);
                in = i;
                break;
            }
        }

        numIP = pow(2, 16) / adjSub;
        add = 256 / adjSub;
        addL = 0;
        addH = addL + add - 1;
        cout << endl;
        cout << "Total no of IP Address Possible in each subnet : " << numIP << endl;
        cout << "Total no. of bits in Subnet id: " << in << endl;
        for (int i = 1; i <= subnets; i++, addL = addL + add, addH = addH + add)
        {
            cout << "For Subnet " << i << endl;
            cout << "Subnet Address: " << ip[0] << "." << ip[1] << "." << addL << ".0" << endl;
            cout << "Broadcast Address: " << ip[0] << "." << ip[1] << "." << addH << ".255" << endl;
            cout << "Valid Range: " << ip[0] << "." << ip[1] << "." << addL << ".1"
                 << " to " << ip[0] << "." << ip[1] << "." << addH << ".254" << endl;
            cout << endl;
        }

        break;
    case 'C':

        cout << "Network mask is 255.255.0.0" << endl;
        cout << "No. of IP Address available are 2^16" << endl;

        for (int i = 0; i < 8; i++)
        {
            if (pow(2, i) >= subnets)
            {
                adjSub = pow(2, i);
                in = i;
                break;
            }
        }

        numIP = pow(2, 8) / adjSub;
        add = 256 / adjSub;
        addL = 0;
        addH = addL + add - 1;
        cout << endl;
        cout << "Total no of IP Address Possible in each subnet : " << numIP << endl;
        cout << "Total no. of bits in Subnet id: " << in << endl;
        for (int i = 1; i <= subnets; i++, addL = addL + add, addH = addH + add)
        {
            cout << "For Subnet " << i << endl;
            cout << "Subnet Address: " << ip[0] << "." << ip[1] << "." << ip[2] << "." << addL << endl;
            cout << "Broadcast Address: " << ip[0] << "." << ip[1] << "." << ip[2] << "." << addH << endl;
            cout << "Valid Range: " << ip[0] << "." << ip[1] << "." << ip[2] << "." << addL + 1
                 << " to " << ip[0] << "." << ip[1] << "." << ip[2] << "." << addH - 1 << endl;
            cout << endl;
        }

        break;

    default:
        cout << "Belong to Class D or E or Invalid IP Address" << endl;
        break;
    }

    return 0;
}