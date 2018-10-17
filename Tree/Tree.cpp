#include <iostream>
#include <cstdio>
#include <vector>


using namespace std;

bool visited[1004];

template <typename T>
class GeneralTree;

template <typename T>
class Node{
private:
    T data;
    Node* par;
    vector<Node*> chi;

public:
    Node(){
        this->data = NULL;
        this->par = NULL;
    }
    
    Node(T data){
        this->data = data;
        this->par = NULL;
    }

    ~Node(){

    }

    void setParent(Node* par){
        this->par = par;
    }

    void insertChild(Node* chi){
        this->chi.push_back(chi);
    }

    void delChild(Node* chi){
        for(int i = 0 ; i < this->chi.size() ; i++){
            if(this->chi[i] == chi)
                this->chi.erase(this->chi.begin() + i);
        }
    }
    friend GeneralTree<T>;
};

template <typename T>
class GeneralTree{
private:
    // Node<T>* root;
    vector<Node<T>*> node_list;
    int tree_size = 0;

public:
    Node<T>* root;

    GeneralTree(){
        root = NULL;
    }

    GeneralTree(T data){
        root = new Node<T>(data);
        node_list.push_back(root);
    }

    ~GeneralTree(){}

    void insertNode(T parent_data, T data){
        Node<T>* par;
        for(auto &i : this->node_list){
            if(i->data == parent_data){
                par = i;
                Node<T>* newNode = new Node<T>(data);
                par->insertChild(newNode);
                newNode->setParent(par);
                this->node_list.push_back(newNode);
                return;
            }
        }
    }

    void delNode(T data){
        Node<T>* nowNode;
        Node<T>* par;
        for(int i = 0 ; i < this->node_list.size() ; i++){
            if(this->node_list[i]->data == data){
                nowNode = this->node_list[i];
                par = nowNode->par;
                for(auto &child : nowNode->chi){
                    par->insertChild(child);
                    child->setParent(par);
                }
                par->delChild(nowNode);
                this->node_list.erase(this->node_list.begin + i);
                delete nowNode;
            }
        }
        return;
    }

    void printfChild(T data){
        for(auto &i : this->node_list){
            if(i->data == data){
                if(i->chi.size() == 0){
                    printf("0\n");
                    return;
                }
                
                for(auto &chi : i->chi){
                    printf("%c " , chi->data);
                }
                printf("\n");
                return;
            }
        }
        cout<<"-1\n";
        return;
    }
    
    void preOrder(Node<T>* now){
        visited[now->data-'A'] = true;
        cout<<now->data;
        for(auto &i : now->chi){
            if(visited[i->data-'A'] == false)
                preOrder(i);
        }
    }

    void postOrder(Node<T>* now){
        visited[now->data-'A'] = true;
        for(auto &i : now->chi){
            if(visited[i->data-'A'] == false)
                postOrder(i);
        }
        cout<<now->data;
    }

    // void inOrder(Node<T* now){
    //     for(auto &i : now->chi){
    //         if(visited[])
    //     }
    // }
};

int N;

int main(){
    freopen("test.txt","r",stdin);
    GeneralTree<char> tree = GeneralTree<char>('A');
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        getchar();
        char a,b,c;
        scanf("%c %c %c" , &a,&b,&c);
        if(b != '.')
            tree.insertNode(a,b);
        if(c != '.')
            tree.insertNode(a,c);
    }

    memset(visited,0,sizeof(visited));
    tree.preOrder(tree.root);
    cout<<"\n";
    memset(visited,0,sizeof(visited));
    tree.postOrder(tree.root);
    cout<<"\n";

    tree.printfChild('A');
}