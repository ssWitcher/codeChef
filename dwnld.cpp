#include <iostream>

using namespace std;

int main()
{
  int tc;
  cin >>tc;
  while(tc--)
  {
    int N,K;
    cin>>N>>K;
    arr1 = new int[N];
    arr2 = new int[N];
    for(int i=0;i<N;i++)
      cin>>arr1[i]>>arr2[i];
    int res=0;
    int i;
    for(i=0;i<N;i++)
    {
      res += arr1[i];
      if ( res > K)
        break;
    }
    if(i != N)
      {
        int ans = (res - K)*arr2[i];
        while(i<N)
         ans += arr1[i]*arr2[i];
        cout<<ans<<"\n";
      }
    else
      cout<<0<<"\n";

  }
}
