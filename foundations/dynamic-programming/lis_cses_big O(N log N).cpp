#include <iostream>
using namespace std;
 
int N,arr[200002],dp[200002];
 
int main()
{
  cin>>N;
  for (int i=0;i<N;i++) cin>>arr[i];
  
  for (int i=0;i<=N;i++) dp[i]=1001001001;
  
  for (int i=0;i<N;i++){
  
    int low=0,high=i+1,mid;
    
    while (low+1<high){
    
      mid=(low+high)/2;
      
      if (dp[mid]<arr[i])
      
	low=mid;
      else
      
	high=mid;
    }
    
    dp[low+1]=min(dp[low+1],arr[i]);
  }
  
  int ans=1;
  
  for (int i=1;i<=N;i++)
  
    if (dp[i]!=1001001001)
    
      ans=i;
      
  cout<<ans<<endl;
  
  return 0;
}
