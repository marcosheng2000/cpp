// Problem: Maximum Minimum Jump Distance After Removing Rocks
// Description:
// Given a river of width m with n rocks positioned in it, you are allowed to remove up to k rocks. Your goal is to maximize the minimum distance one has to jump between remaining rocks. Output this maximum possible minimum distance.

#include <iostream>
using namespace std;
int n, m, k, l, r, mid, ans;
int a[50005];
bool check(int x)
{
    int last = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] - last < x)
        {
            sum++;
        }
        else
        {
            last = a[i];
        }
        if (sum > k)
            return false;
    }
    return true;
}
int main()
{
    cin >> m >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[n + 1] = m;
    l=1;
    r=m;

    while (l<=r)
    {
        mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }

    cout << ans << endl;
    return 0;
}