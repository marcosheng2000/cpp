// Problem: Minimum Maximum Gap After Adding Road Signs
// Description:
// Given a road of length D with N existing road signs, you are allowed to add up to K additional signs. You want to minimize the maximum distance between any two consecutive signs.

#include<iostream>
#include<algorithm>
using namespace std;
int a[100005];
int d, n, k, ans;
bool check(int x)
{
    int m=0;
    for(int i=2;i<=n;i++)
    {
        if(a[i]-a[i-1]<=x)
        {
            continue;
        }
        else
        {
            if(a[i]-a[i-1]%x==0)
            {
                m+=(a[i]-a[i-1])/x-1;
            }
            else
            {
                m+=(a[i]-a[i-1])/x;
            }
        }
        if(m>k)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cin >> d >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 1, r = d;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout << ans << endl;
    return 0;
}