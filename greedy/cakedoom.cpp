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
    int k;
    cin >> k;
    k = k + '0';

    string arrangement;
    cin >> arrangement;

    int len = arrangement.size();
    //case for length 1 string
    
    if(len == 1){
      if(arrangement[0] == '?')
        cout<<"0\n";
      else
        cout<<arrangement<<'\n';
      continue;
    }

    //case for k = 2
    
    if(k == '2'){
      int num_index = -1;

      if(len & 1){ 
        cout<<"NO\n";
        continue;
      }


      for(int i = 0; i < len; i++){
        if(arrangement[i] != '?'){
          num_index = i;
          break;
        }
      }

      if(num_index == -1)
        for(int i = 0; i < len; i++)
          arrangement[i] == i % 2 + '0';
      else{
        int req_num = arrangement[num_index] - '0';
        for(int i = 0; i < len; i++){
          if(i % 2 == num_index % 2){
            arrangement[i] = (char)(req_num + '0');
          }
          else{
            arrangement[i] =(char)(!req_num + '0');
          }
        }
      }
      
      cout<<arrangement<<"\n";
      continue;
    }

    //case for string length > 1

    arrangement.append(1, arrangement[0]);
    string s(1, arrangement[len-1]);
    arrangement = s.append(arrangement);

    bool valid = true;

    for(int i = 1; i <= len; i++){
      if(i > 1)
        arrangement[len + 1] = arrangement[1];
      if(arrangement[i] != '?')
        continue;
      
      char cherry = '0';

      while(cherry < k){
        if(arrangement[i - 1] == cherry){
          cherry++;
          continue;
        }
        if(arrangement[i + 1] == cherry){
          cherry++;
          continue;
        }
        arrangement[i] = cherry;
        break;
      }
      if(cherry == k){
        valid = false;
        break;
      }
    }

    for(int i = 1; i <= len; i++){
      if(arrangement[i] == arrangement[i - 1] || arrangement[i] == arrangement[i + 1]){
        valid = false;
        break;
      }
    }

    if(valid){
      for(int i = 1; i <= len; i++)
        cout<<arrangement[i];
      cout<<"\n";
    }
    else
      cout<<"NO\n";
  }

}
