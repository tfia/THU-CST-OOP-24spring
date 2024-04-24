#include <iostream>
#include <string>

#include "Hash.h"
#include "HashTable.h"

using namespace std;

int main()
{
    int n1, n2, n3, n4, p, q, opr;
    cin >> n1 >> n2 >> n3 >> n4;
    HashTable<int, int> hii(n1);
    HashTable<int, string> his(n2);
    HashTable<string, int> hsi(n3);
    HashTable<string, string> hss(n4);

    int a, b;
    string c, d;
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        cin >> opr;
        switch (opr)
        {
        case 1:
            cin >> a >> b;
            hii.addItem(a, b);
            break;

        case -1:
            cin >> a;
            hii.removeItem(a);
            break;

        case 2:
            cin >> a >> c;
            his.addItem(a, c);
            break;

        case -2:
            cin >> a;
            his.removeItem(a);
            break;

        case 3:
            cin >> c >> a;
            hsi.addItem(c, a);
            break;

        case -3:
            cin >> c;
            hsi.removeItem(c);
            break;

        case 4:
            cin >> c >> d;
            hss.addItem(c, d);
            break;

        case -4:
            cin >> c;
            hss.removeItem(c);
            break;

        default:
            break;
        }
    }

    int *intPointer;
    string *stringPointer;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> opr;
        switch (opr)
        {
        case 1:
            cin >> a;
            intPointer = hii.findByKey(a);
            if (intPointer == nullptr)
                cout << "NULL\n";
            else
                cout << *intPointer << "\n";
            break;

        case 2:
            cin >> a;
            stringPointer = his.findByKey(a);
            if (stringPointer == nullptr)
                cout << "NULL\n";
            else
                cout << *stringPointer << "\n";
            break;

        case 3:
            cin >> c;
            intPointer = hsi.findByKey(c);
            if (intPointer == nullptr)
                cout << "NULL\n";
            else
                cout << *intPointer << "\n";
            break;

        case 4:
            cin >> c;
            stringPointer = hss.findByKey(c);
            if (stringPointer == nullptr)
                cout << "NULL\n";
            else
                cout << *stringPointer << "\n";
            break;

        default:
            break;
        }
    }
    return 0;
}