// Problem: Longest Balanced Fence Segment
// Description:
// You are given a binary array representing red and blue fence bars (0 = red, 1 = blue). Find the length of the longest contiguous segment in which the number of red and blue bars are equal.

#include<iostream>
using namespace std;
int n, ans=0;
int b[100010],r[100010];
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        b[i]+=b[i-1];
        r[i]+=r[i-1];
        if (x==1)
            b[i]++;
        else
            r[i]++;
    }
    for (int i=n/2*2;i>=0;i-=2)
    {
        for(int j=1;j+i-1<=n;j++)
        {
            if(b[j+i-1]-b[j-1]==r[j+i-1]-r[j-1])
            {
                cout<<i;
                return 0;
            }
        }
    }
    cout<<0;
    return 0;
}