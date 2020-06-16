#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Sort_Stack{
  private:
    stack<int> main_stack;
  public:
    
    void push(int val){
      if(main_stack.empty()){
        main_stack.push(val);
      }
      
      if(main_stack.top() >= val)
        main_stack.push(val);
      else{
        stack<int> temp_stack;
        while(!main_stack.empty() && val > main_stack.top()){
          int top_val = main_stack.top();
          temp_stack.push(top_val);
          main_stack.pop();
        }
        cout<<temp_stack.top()<<endl;
        cout<<temp_stack.size()<<endl;
        main_stack.push(val);
        while(!temp_stack.empty()){
          int top_val = temp_stack.top();
          main_stack.push(top_val);
          temp_stack.pop();
        }
      }
    }

    int peek(){
      return main_stack.top();
    }

    int pop(){
      if(main_stack.empty())
        return -1;
      int return_val = main_stack.top();
      main_stack.pop();
      return return_val;
    }

    bool isEmpty(){
      return main_stack.empty();
    }
};


int main(){
  Sort_Stack s = Sort_Stack();

  s.push(3);
  s.push(4);
  s.push(9);
  s.push(2);
  s.push(8);
  s.push(7);
  s.push(1);
  s.push(0);
  s.push(0);
  /*
  cout<<s.pop()<<endl;
  cout<<s.pop()<<endl;
  cout<<s.pop()<<endl;
  cout<<s.pop()<<endl;
  cout<<s.pop()<<endl;
  cout<<s.pop()<<endl;
  */
}
