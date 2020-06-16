#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node{
  public:
    int val;
    int min;
    Node *prev;
};

class MinStack{

  private:
    Node* top = new Node();

  public:
    MinStack(){
      top -> prev = NULL;
      top -> min = INT_MAX;
      top -> val = INT_MAX;
    }

    void push(int val){
      Node* to_add = new Node();
      to_add -> val = val;
      to_add -> prev = top;

      if(val < top -> min)
        to_add -> min = val;
      else
        to_add -> min = top -> min;
      top = to_add;
    }

    int pop(){
      int return_val = top -> val;
      top = top -> prev;
      
      return return_val;
    }

    int min(){
      return top -> min;
    }
};

int main(){

  MinStack minstack = MinStack();
  minstack.push(3);
  minstack.push(5);
  minstack.push(1);
  minstack.push(4);
  minstack.push(2);

  cout<<minstack.min()<<"\n";
  minstack.pop();
  cout<<minstack.min()<<"\n";
  minstack.pop();
  cout<<minstack.min()<<"\n";
  minstack.pop();
  cout<<minstack.min()<<"\n";
  minstack.pop();
  cout<<minstack.min()<<"\n";
}
