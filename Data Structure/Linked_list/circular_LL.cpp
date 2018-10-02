#include <iostream>

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
    Node* pos;

    LinkedList(){
        head = NULL;
        tail = NULL;
        pos = NULL;
    }

    void insert(int e){
        Node* insert = new Node(e);
        if(head == NULL){
            head = insert;
            tail = insert;
            tail->next = head;
        }else {
            tail->next = insert;
            insert->next = head;
            tail = insert;
        }
    }

    void remove(int M){
        int cnt = 1;
        Node* pre = NULL;
        while(M != cnt){
            cnt++;
            pre = pos;
            pos = pos->next;
        }

        cout<<pos->data;

        pre->next = pos->next;
        pos = pos->next;
    }
};

int main(){
    freopen("input.txt", "r", stdin);
    int N,M,NN;
    cin>>N>>M;
    NN = N;
    LinkedList LL;
    for(int i = 1 ; i <= N ; i++){
        LL.insert(i);
    }
    
    LL.pos = LL.head;
    int cnt = 0;
    cout<<"<";
    while(N--){
        LL.remove(M);
        cnt++;
        if(cnt!=NN)
            cout<<", ";
    }
    cout<<">";
}