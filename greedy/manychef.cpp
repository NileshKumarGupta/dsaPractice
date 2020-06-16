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
    string s;
    cin >> s;

    int len = s.length();

    for(int i = len; i >=  0; i--){
      
      int curr_index = i;
      bool chef_possible = true;

      switch(s[i]){

        case 'F':

          curr_index = i;
          chef_possible = true;

          if(curr_index - 3 < 0)
            break;

          curr_index--;
          if(!(s[curr_index] == 'E' || s[curr_index] == '?'))
            chef_possible = false;

          curr_index--;
          if(!(s[curr_index] == 'H' || s[curr_index] == '?'))
            chef_possible = false;

          curr_index--;
          if(!(s[curr_index] == 'C' || s[curr_index] == '?'))
            chef_possible = false;

          if(chef_possible){
            s[i - 1] = 'E';
            s[i - 2] = 'H';
            s[i - 3] = 'C';
            i = i - 4;
          }
          break;

        case 'E':

          curr_index = i;
          chef_possible = true;

          if(curr_index - 2 < 0 && curr_index + 1 >= len)
            break;

          if(s[curr_index + 1] != '?')
            chef_possible = false;

          curr_index--;
          if(!(s[curr_index] == 'H' || s[curr_index] == '?'))
            chef_possible = false;

          curr_index--;
          if(!(s[curr_index] == 'C' || s[curr_index] == '?'))
            chef_possible = false;

          if(chef_possible){
            s[i + 1] = 'F';
            s[i - 1] = 'H';
            s[i - 2] = 'C';
            i = i - 3;
          }
          break;

        case 'H':
          
          curr_index = i;
          chef_possible = true;

          if(curr_index - 1 < 0 && curr_index + 2 >= len)
            break;

          if(s[curr_index + 1] != '?')
            chef_possible = false;

          if(s[curr_index + 2] != '?')
            chef_possible = false;

          curr_index--;
          if(!(s[curr_index] == 'C' || s[curr_index] == '?'))
            chef_possible = false;

          if(chef_possible){
            s[i + 2] = 'F';
            s[i + 1] = 'E';
            s[i - 1] = 'C';
            i = i - 2;
          }
          break;

        case 'C':
          
          curr_index = i;
          chef_possible = true;

          if(curr_index + 3 >= len)
            break;

          if(s[curr_index + 1] != '?')
            chef_possible = false;

          if(s[curr_index + 2] != '?')
            chef_possible = false;

          if(s[curr_index + 3] != '?')
            chef_possible = false;

          if(chef_possible){
            s[i + 3] = 'F';
            s[i + 2] = 'E';
            s[i + 1] = 'H';
            i--;
          }
          break;

      }
    }

    //handle question marks now, to make it lexicographically smallest string
    int qmark_counter = 1;
    for(int i = len - 2;  i >= 0; i--){
      if(s[i] == '?'){
        if(s[i + 1] == '?')
          qmark_counter++;
        if(qmark_counter == 4){
          s[i] = 'C';
          s[i + 1] = 'H';
          s[i + 2] = 'E';
          s[i + 3] = 'F';
          qmark_counter = 1;
        }
      }
      else{
        qmark_counter = 1;
      }
    }
    
    for(int i = 0; i < len; i++)
      if(s[i] == '?')
        s[i] = 'A';

    cout<<s<<'\n';

  }
}
