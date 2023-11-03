#include <iostream>
using namespace std;

int main()
{
    int w, aa, bb;
    cin >> w;
    if (w > 2)
    {

        aa = w % 2;

        if (aa == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
