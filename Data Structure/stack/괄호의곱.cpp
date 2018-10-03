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
    string str;
    cin>>str;

    int mul = 1;
    int sum = 0;
    bool check = false;
    

    for(int i = 0 ; i < str.size(); i++){
        char in = str[i];
        
        if(in == '('){
            mul *= 2;
            st.push(1);
            // cout<<mul<<endl;
            if(i+1<str.size() && str[i+1] == ')')
                sum += mul;
        }else if(in == '['){
            mul *= 3;
            st.push(2);
            if(i+1 < str.size() && str[i+1] == ']')
                sum += mul;
        }
        
        if(st.empty()){
            if(in == ')' || in == ']')
            check = true;
        }else{
            if(in == ')'){
                mul = mul / 2;
                if(st.top() == 1) st.pop();
                else check = true;
            }else if(in == ']'){
                mul = mul / 3;
                if(st.top() == 2 )st.pop();
                else check = true;
            }
        }
    }
    if(!st.empty())
        check = true;
    
    if(check == true)
        cout<<0<<endl;
    else
        cout<<sum<<endl;
}