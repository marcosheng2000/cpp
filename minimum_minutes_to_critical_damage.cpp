// Problem: Minimum Minutes to Reach Critical Damage Threshold
// Description:
// There are n critical components. Each component has an initial damage level a[i] and increases by b[i] each minute. When a component’s damage exceeds threshold x, it becomes completely broken. Find the minimum number of minutes until at least m components become completely broken.

#include <iostream>
using namespace std;
int a[1000005], b[1000005], n, m, x, l, r, mid, ans;
bool check(int k)
{
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]+k*b[i]>x)
        {
            sum++;
        }
    }
    return sum>=m;
}
int main()
{
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    l=0;
    r=100;
    while (l<=r)
    {
        mid=(l+r)/2;
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
    cout<<ans;
    return 0;
}