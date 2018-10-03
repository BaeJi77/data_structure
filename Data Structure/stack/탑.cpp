#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int e){
        data = e;
        next = NULL;
    }
};

class LinkedList{
public:
    Node* head;
    Node* tail;
    
    LinkedList(){
        head = NULL;
        tail = NULL;
    }

    void insert(int e){
        Node* insert = new Node(e);
        if(head == NULL){
            head = insert;
            tail = insert;
            insert->next = tail;
        }else{
            insert->next = head;
            head = insert;
        }
    }

    void remove(){
        Node* temp = head;
        head = head->next;

        delete temp;
    }

    int front(){
        return head->data;
    }
};

class stack{
public:
    int n;
    LinkedList* LL;
    
    stack(){
        n = 0;
        LL = new LinkedList();
    }

    int size(){
        return n;
    }

    bool empty(){
        return n==0;
    }

    void push(int e){
        n++;
        LL->insert(e);
    }

    int top(){
        if(empty()) return -1;
        return LL->front();
    }

    int pop(){
        if(empty()) return -1;
        int ret = top();
        n--;
        LL->remove();
        return ret;
    }
};

int N;

int main(){
    freopen("input.txt", "r", stdin);  
    stack st;
    stack index;
    cin>>N;
    for(int i = 1 ; i <= N ; i++){
        
        int in;
        cin>>in;

        while(!st.empty()){
            if(st.top() > in){
                cout<<index.top()<<" ";
                index.push(i);
                st.push(in);
                break;
            }
            index.pop();
            st.pop();
        }

        if(st.empty()){
            cout<<0<<" ";
            index.push(i);
            st.push(in);
        }
    }
}