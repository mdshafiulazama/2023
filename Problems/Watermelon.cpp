#include <iostream>
using namespace std;

int main()
{
    int i, n, f1, f2, f3, all, ans = 0;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> f1 >> f2 >> f3;
        all = f1 + f2 + f3;
        if (all >= 2)
        {
            ans++;
        }
        ans = ans;
    }
    cout<<ans<<endl;
    return 0;
}
