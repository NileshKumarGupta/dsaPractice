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
    
    int num_clean = 0;
    int tables_occupied = 0;
    int customers[401] = {false};
    int order[orders];

    for(int order_num = 0; order_num < orders; order_num++){
      cin >> order[order_num];
    }


    for(int order_num = 0; order_num < orders; order_num++){

      if(!customers[order[order_num]]){

        if(tables_occupied < tables){
          num_clean++;
          customers[order[order_num]] = true;
          tables_occupied++;
        }

        else{
          int farthest_length = 0;
          int farthest_customer = 0;

          for(int i = 0; i < 400; i++){

            if(customers[i] == true){
              int j = order_num;

              for(j = order_num; j < orders; j++){
                if(order[j] == i){
                  int length = j - order_num;
                  if(length > farthest_length){
                    farthest_length = length;
                    farthest_customer = i;
                  }
                  break;
                }
              }
             
              if(j == orders){
                farthest_customer = i;
                break;
              }

            }

          }

          customers[farthest_customer] = false;
          customers[order[order_num]] = true;
          num_clean++;
        }
      }
    }

    cout<<num_clean<<endl;
  }
}
