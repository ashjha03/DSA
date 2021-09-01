#include<iostream>
#include<stack>
using namespace std;

stack<int> s1, s2;

class Queue{
    public:
        void Enqueue(int data){
            s1.push(data);
        }

        int Dequeue(){
            int x = -1;
            if(s2.empty()){
                if(s1.empty())
                    cout<<"Queue Underflow"<<endl;
                else
                    while(!s1.empty()){
                        s2.push(s1.top());
                        s1.pop();
                    }
            }
            x = s2.top();
            s2.pop();
            return x;
        }

        void display(){
            stack<int> s3 = s1, s4 = s2;
            while(!s4.empty()){
                cout<<s4.top()<<" ";
                s4.pop();
            }
            while(!s3.empty()){
                s4.push(s3.top());
                s3.pop();
            }
            while(!s4.empty()){
                cout<<s4.top()<<" ";
                s4.pop();
            }
            cout<<endl;
        }
};

int main(){
    Queue q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    q.display();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.display();
    return 0;
}