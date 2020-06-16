#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class MyQueue{
  private:
    stack<int> forward;
    stack<int> backward;
  public:

    void enqueue(int val){

      if(forward.empty()){
        int stack_size = backward.size();
        for(int i = 0; i < stack_size; i++){
          int top_val = backward.top();
          forward.push(top_val);
          backward.pop();
        }
      }

      forward.push(val);

    }
    

    int dequeue(){

      if(backward.empty()){
        int stack_size = forward.size();
        
        if(!stack_size)
          return -1;

        for(int i = 0; i < stack_size; i++){
          int top_val = forward.top();
          backward.push(top_val);
          forward.pop();
        } 

      }

      int return_val = backward.top();
      backward.pop();
      return return_val;
    }

};

int main(){
  cout<<"Hello World\n";
  MyQueue myqueue = MyQueue();
  myqueue.enqueue(1);
  myqueue.enqueue(2);
  cout<<myqueue.dequeue()<<endl;
  myqueue.enqueue(3);
  myqueue.enqueue(4);
  cout<<myqueue.dequeue()<<endl;
  myqueue.enqueue(5);
  myqueue.enqueue(6);
  cout<<myqueue.dequeue()<<endl;
  cout<<myqueue.dequeue()<<endl;
  myqueue.enqueue(7);
  cout<<myqueue.dequeue()<<endl;
  cout<<myqueue.dequeue()<<endl;
  myqueue.enqueue(8);
  cout<<myqueue.dequeue()<<endl;
  cout<<myqueue.dequeue()<<endl;
  cout<<myqueue.dequeue()<<endl;
  myqueue.enqueue(9);
  cout<<myqueue.dequeue()<<endl;
  myqueue.enqueue(3);
  myqueue.enqueue(0);
  cout<<myqueue.dequeue()<<endl;
}

