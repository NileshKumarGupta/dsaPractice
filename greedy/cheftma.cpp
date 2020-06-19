#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int t;
  cin >> t;

  for(int tcn = 0; tcn < t; tcn++){
    int n, k, m;
    cin >> n >> k >> m;

    int a[n], b[n], all[k + m];

    for(int i = 0; i < n; i++)
      cin >> a[i];

    for(int i = 0; i < n; i++)
      cin >> b[i];

    for(int i = 0; i < k + m; i++)
      cin >> all[i];

    int incomplete_tasks[n];
    for(int i = 0; i < n ;i++)
      incomplete_tasks[i] = a[i] - b[i];

    sort(incomplete_tasks, incomplete_tasks + n, greater<int>());

    sort(all, all + k + m );

    int cindex = k - 1;
    int dindex = m - 1;

    int allindex = k + m - 1;

    for(int i = 0; i < n; i++){
      int req_val = incomplete_tasks[i];
      while(req_val - all[allindex] < 0 && allindex >= 0)
        allindex--;

      if(allindex < 0)
        break;

      incomplete_tasks[i] -= all[allindex];
      allindex--;
    }

    int sum = 0;
    for(int i = 0; i < n; i++)
      sum += incomplete_tasks[i];

    cout<<sum<<"\n";

  }
}
