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

    long long int n1, n2, m;
    cin >> n1 >> n2 >> m;

    int x = min(n1, n2);
    m = m * (m + 1) / 2;
    x = x < m ? x : m;
    cout<<n1 + n2 - 2 * x<<"\n";

  }
}
