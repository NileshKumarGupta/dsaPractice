#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Stack{
  private:
    int max_size;
    vector<int> stack_data;

  public:
    Stack(int max_size){
      this->max_size = max_size;
    }

    bool push(int val){
      if(stack_data.size() >= max_size)
        return false;
      stack_data.push_back(val);
      return true;
    }
    
    int pop(){
      int return_val = stack_data.back();
      stack_data.pop_back();
      return return_val;
    }
    
    bool empty(){
      return !stack_data.size();
    }
};

class setOfStacks{
  private:
    vector<Stack> stack_list;
    int max_size;
  public:
    setOfStacks(int max_size){
      this->max_size = max_size;
      Stack s = Stack(max_size);
      stack_list.push_back(s);
    }

    void push(int val){
      if(stack_list[stack_list.size() - 1].push(val))
        return;
      Stack s = Stack(max_size);
      s.push(val);
      stack_list.push_back(s);
    }

    int pop(){
      if(!stack_list[stack_list.size() - 1].empty())
        return stack_list[stack_list.size() - 1].pop();
      stack_list.pop_back();
      return stack_list[stack_list.size() - 1].pop();
    }

    int popAt(int index){
      if(index >= stack_list.size() - 1)
        return -1;
      int return_val = stack_list[index].pop();
      if(stack_list[stack_list.size() - 1].empty()){
        stack_list.erase(stack_list.begin() + index);
      }
    }
};


int main(){
  cout<<"Hello World\n";
  setOfStacks s = setOfStacks(3);
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  s.push(6);

  cout<<s.pop()<<"\n"; 
  cout<<s.pop()<<"\n"; 
  cout<<s.pop()<<"\n"; 
  cout<<s.pop()<<"\n"; 
  cout<<s.pop()<<"\n"; 
  cout<<s.pop()<<"\n"; 
  cout<<s.pop()<<"\n"; 
}
