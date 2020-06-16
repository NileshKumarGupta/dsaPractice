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
    int tables, orders;
    cin >> tables >> orders;

    bool customers[400] = {false};

    int num_cleans = 0;
    int tables_occupied = 0;
    for(int order_num = 0; order_num < orders; order_num++){
      int order;
      cin >> order;

      if(!customers[order - 1]){
        for(int i = 0; i < 400; i++)
          if(customers[i]){
            customers[i] == false;
            break;
          }

        customers[order - 1] = true;
        num_cleans++;
      }
    }

    cout<<num_cleans<<"\n";

  }

}
