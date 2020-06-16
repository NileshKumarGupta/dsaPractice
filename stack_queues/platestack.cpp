#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Stack{
  private:
    int max_size;
    vector<int> stack_data;

  public:
    Stack(int max_size){
      this -> max_size = max_size;
    }

    bool push(int val){
      if(stack_data.size() >= max_size)
        return false;
      
      stack_data.push_back(val);
      return true;
    }

    int pop(){
      if(stack_data.empty())
        return -1;
      int return_val = stack_data.back();
      stack_data.pop_back();
      return return_val;
    }
};

class VectorStacks{
  private:
    vector<Stack> stack_list;
    int curr_index = 0;
    int max_size;

  public:
    VectorStacks(int max_size){
      this->max_size = max_size;
      Stack s = Stack(this->max_size);
      stack_list.push_back(s);
    }

    void push(int val){
      if(stack_list[curr_index].push(val))
        return;
      Stack s = Stack(max_size);
      s.push(val);
      stack_list.push_back(s);
      curr_index++;
    }
    
    int pop(){
      int return_val = stack_list[curr_index].pop();
      if(return_val == -1){
        stack_list.pop_back();
        if(stack_list.empty())
          return -1;
        return_val = stack_list[--curr_index].pop();
      }
      return return_val;
    }
};

/**
 * To do
 * add pop at index function
 * will cause problems for a stack in between being empty
**/

int main(){
  VectorStacks vs = VectorStacks(2);

  vs.push(3);
  vs.push(4);
  vs.push(5);
  vs.push(6);
  vs.push(7);
  vs.push(8);
  vs.push(9);
  vs.push(10);

  cout<<vs.pop()<<"\n";
  cout<<vs.pop()<<"\n";
  cout<<vs.pop()<<"\n";
  cout<<vs.pop()<<"\n";
  cout<<vs.pop()<<"\n";
  cout<<vs.pop()<<"\n";
}
