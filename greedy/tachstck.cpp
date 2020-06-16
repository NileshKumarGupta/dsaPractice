#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  long long int d;
  cin >> n >> d;

  long long int lengths[n];
  for(int i = 0; i < n; i++)
    cin >> lengths[i];

  sort(lengths, lengths + n, greater<int>());

  int num_pairs = 0;
  for(int i = 0; i < n - 1; i++){
    if(lengths[i] - lengths[i + 1] <= d){
      num_pairs++;
      i++;
    }
  }
  
  cout<<num_pairs<<"\n";
}
