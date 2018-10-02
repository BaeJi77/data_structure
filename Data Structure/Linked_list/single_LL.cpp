#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int num){
        data = num;
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

    void addFront(int number){
        Node* insert = new Node(number);
        if(head == NULL){
            head = insert;
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
    LinkedList* L;

    stack(){
        this->n = 0;
        this->L = new LinkedList();
    }

    int size(){
        return n;
    }
    
    bool empty(){
        return n==0;
    }

    int top(){
        if(n==0) return -1;
        return L->front();
    }

    void push(int number){
        L->addFront(number);
        n++;
    }

    int pop(){
        if(n==0) return -1;
        int ret = top();
        L->remove();
        n--;
        return ret;
    }
};

int N;

int main(){
    // freopen("input.txt", "r", stdin);  
    scanf("%d" , &N);
    stack st;
    for(int i = 0 ; i < N ; i++){
        string str;
        cin >> str;
        if ( str == "push" )
        {
            int a;
            cin >> a;
            //cout << str <<" "<< a<< endl;
            st.push(a);
        }
        else if ( str == "top")
        {
            cout << st.top() << endl;
        }
        else if ( str == "size")
        {
            cout << st.size() << endl;
        }
        else if ( str == "empty")
        {
            bool result = st.empty();
            if ( result == true )
            {
                cout << "1" << endl;
            }
            else
            {
                cout << "0" << endl;
            }
        }
        else if(str=="pop")// pop
        {
            cout << st.pop() << endl;
        }
    }  
}