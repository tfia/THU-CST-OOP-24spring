#include <iostream>

#include "Monomial.h"

using namespace std;

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int n;
    int m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Monomial x, y;
        cin >> x;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int opr, a, b;
            cin >> opr;
            switch (opr)
            {
            case 1:
                cin >> y;
                x = x + y;
                cout << x;
                break;

            case 2:
                cin >> y;
                x = x - y;
                cout << x;
                break;

            case 3:
                cin >> y;
                x = x * y;
                cout << x;
                break;

            case 4:
                cin >> y;
                x = x / y;
                cout << x;
                break;

            case 5:
                cin >> a >> b;
                cout << x.definite_integral(a, b) << "\n";
                break;

            case 6:
                x = x.derive();
                cout << x;
                break;

            default:
                break;
            }
        }
        int par;
        cin >> par;
        cout << x.get_val(par) << endl;
    }
    return 0;
}