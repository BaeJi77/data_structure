#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int number){
        data = number;
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

    void push(int e){
        Node* insert = new Node(e);
        if(head == NULL){
            head = insert;
            tail = insert;
            insert->next = tail;
        }else{
            tail->next = insert;
            tail = insert;
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

    int back(){
        return tail->data;
    }
};

class queue{
public:
    int n;
    LinkedList* L;
    
    queue(){
        n = 0;
        L = new LinkedList();
    }

    int size(){
        return n;
    }

    bool empty(){
        return n==0;
    }

    void push(int e){
        L->push(e);
        n++;
    }

    int front(){
        if(empty()) return -1;
        return L->front();
    }

    int pop(){
        if(empty()) return -1;
        int ret = front();
        L->remove();
        n--;
        return ret;
    }

    int back(){
        if(empty()) return -1;
        int ret = L->back();
        return ret;
    }
};



int main(){
    freopen("input.txt", "r", stdin);  
    queue Q;
    int N;
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        string input;
        cin>>input;
        if ( input == "push" )
        {
            int a;
            cin >> a;
            Q.push(a);
        }
        else if ( input == "pop" )
        {
            cout << Q.pop() << endl;
        }
        else if ( input == "front" )
        {
            cout << Q.front() << endl;
        }
        else if ( input == "size" )
        {
            cout << Q.size() << endl;
        }
        else if ( input == "back" )
        {
            cout << Q.back() << endl;
        }
        else if ( input == "empty" )
        {
            if ( Q.empty() == true ){
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
    }
}