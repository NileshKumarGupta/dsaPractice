#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool greater_pair(pair<long long int, int> a, pair<long long int, int> b){
  return abs(a.first) > abs(b.first);
}

int main(){
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  int t;
  cin >> t;

  for(int tcn = 0; tcn < t; tcn++){
    int n, k;
    cin >> n >> k;

    vector<pair<long long int, int>> nums;

    for(int i = 0; i < n; i++){
      int num;
      cin >> num;
      nums.push_back(make_pair(num, i));
    }

    sort(nums.begin(), nums.end(), greater_pair);

    int subseqlen = 0;
    long long int product = 1;
    vector<long long int> num_store;
    int last_index = 0;

    for(int i = 0; i < n; i++){
      if(subseqlen == k)
        break;
      if(nums[i].first > 0){
        product *= nums[i].first;
        subseqlen++;
        last_index = i;
      }
      else if (nums[i].first < 0){
        num_store.push_back(nums[i].first);
        if(num_store.size() == 2 && subseqlen + 2 <= k){
          product *= num_store[0] * num_store[1];
          subseqlen += 2;
          num_store.clear();
          last_index = i;
        }
      }
    }

    // test case 4,3 -4, -3, -2. -1
    
    int i = n - 1;
    while(subseqlen < k){
        product *= nums[i].first;
        subseqlen++;
        i--;
    }

    product = product % 1000000007;
    if(product < 0)
      product += 1000000007;

    cout<<product<<'\n';

  }

}
