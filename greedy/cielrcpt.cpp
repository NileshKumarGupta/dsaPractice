#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t; 
  
  int prices[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
  for(int i = 0; i < t; i++){
    int p; 
    cin >> p;

    int num_menus = 0;
    int index = 11;

    while(p > 0){
      num_menus += p / prices[index];
      p = p % prices[index];
      index--;
    } 

    cout<<num_menus<<"\n";
  }
}
