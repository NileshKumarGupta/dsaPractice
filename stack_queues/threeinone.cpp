#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class three_in_one{
  private:
    int arr[100] = {0};
    int top[3];
    int curr[3];

  public:
   three_in_one(){
      top[0] = 100 / 3;
      top[1] = 2 * 100 / 3;
      top[2] = 100;
      curr[0] = 0;
      curr[1] = top[0];
      curr[2] = top[1];
    }

    bool push(int val, int stack_num){
      if(curr[stack_num] < top[stack_num]){
        arr[curr[stack_num]] = val;
        curr[stack_num]++;
        return true;
      }
      else
        return false;
    }
    
    int pop(int stack_num){
      if(stack_num == 0)
        if(curr[0] == 0)
          return -1;
        else
          return arr[curr[0]--];
      else{
        if(curr[stack_num] == top[stack_num - 1])
          return -1;
        else
          return arr[--curr[stack_num]];
      } 
    }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  three_in_one tio = three_in_one();
  tio.push(1, 1);
  cout<<tio.pop(1)<<endl;
  cout<<tio.pop(1)<<endl;
}
