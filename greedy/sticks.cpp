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
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
      cin >> a[i];

    sort(a, a + n, greater<int>());

    vector<int> sides;

    for(int i = 1; i < n ; i++){
      if(a[i] == a[i - 1]){
        sides.push_back(a[i]);
        i++;
        if(sides.size() == 2)
          break;
      }
    }

    if(sides.size() == 2)
      cout << sides[0] * sides[1] <<"\n";
    else
      cout << "-1\n";

  }
}
