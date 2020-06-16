#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

  for(int test_num = 0; test_num < t; test_num++){
    int n, k;
    cin >> n >> k;

    k = n / 2 >= k ? k : n - k;

    int weights[n];
    for(int i = 0; i < n; i++)
      cin >> weights[i];

    sort(weights, weights + n);

    int heavy_group_weight = 0;
    for(int i = k; i < n; i++)
      heavy_group_weight += weights[i];

    int light_group_weight = 0;
    for(int i = 0; i < k; i++)
      light_group_weight += weights[i];

    int max_diff = abs(heavy_group_weight - light_group_weight);

    cout<<max_diff<<"\n";
  }
}
