#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool greater_pair( pair<int, int> a, pair<int, int> b){
  return a.first > b.first;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, x, y;
  cin >> n >> x >> y;

  int a[n];
  int b[n];

  for(int i = 0; i < n; i++)
    cin >> a[i];

  for(int i = 0; i < n; i++)
    cin >> b[i];

  vector <pair <int, int>> diff;

  for(int i = 0; i < n; i++){
    int subt = a[i] - b[i];
    diff.push_back(make_pair(subt, i));
  }

  sort(diff.begin(), diff.end(), greater_pair);

  int tip = 0;
  int index = 0;
  while(x && diff[index].first > 0){
    tip += a[diff[index].second];
    index++;
    x--;
  }
  index--;
  
  int rev_index = n - 1;
  while(y && diff[rev_index].first < 0){
    if(rev_index == index)
      break;
    tip += b[diff[rev_index].second];
    rev_index--;
    y--;
  }
  rev_index++;

  while(rev_index - index > 1){
    if(y){
      rev_index--;
      tip += b[diff[rev_index].second];
      y--;
    }
    else{
      index++;
      tip += a[diff[index].second];
      x--;
    }
  }

  cout<<tip<<'\n';
}
