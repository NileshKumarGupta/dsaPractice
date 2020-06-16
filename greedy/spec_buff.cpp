#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL); 

  int n;
  cin >> n;
  int prices[n];

  for(int i = 0; i < n; i++)
    cin>>prices[i];
  
  int profit = 0;
  int cp = 0;
  int sp = 0;
  bool bought = false;

  for(int i = 0; i < n - 1; i++){
    if(prices[i] < prices[i + 1]){
      if(!bought){
        cp = prices[i];
        bought = true;
      }
    } 
    if(prices[i] > prices[i + 1]){
      if(bought){
        sp = prices[i];
        profit += sp - cp;
        bought = false;
      }
    }
  }

  cout<<profit<<"\n";
}
