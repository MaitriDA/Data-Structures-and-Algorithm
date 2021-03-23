#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

template<typename T>
class Node{
    public:
    string key;
    T value;
    Node<T>*next;

    Node(string k,T val){     //Constructor
        key=k;
        value=val;
        next=NULL;
    }
    ~Node(){                    //Destructor
        if(next!=NULL){
            delete next;
        }
    }
};
template<typename T>
class Hashtable{
    Node<T>** table;        //Here double astric sign is used because it is pointing to the array of pointers.
    int current_size;
    int table_size;

    int hashFn(string key){
        int idx=0;
        int p=1;
        for(int j=0;j<key.length();j++){
            idx=idx+(key[j]*p)%table_size;
            idx=idx%table_size;
            p=(p*27)%table_size;
        }
        return idx;
    }

    public:
    Hashtable(int ts=7){
        table_size=ts;
        table=new Node<T>*[table_size];
        current_size=0;
        for(int i=0;i<table_size;i++){
            table[i]=NULL;
        }
    }

    void insert(string key,T value){
        int idx=hashFn(key);
        Node<T>*n=new Node<T>(key,value);
        //Insert at the head of the linked list with id equal to idx
        n->next=table[idx];
        table[idx]=n;
        current_size++;
    }
    void print(){
        for(int i=0;i<table_size;i++){
            cout<<"Bucket "<<i<<"->";
            Node<T>*temp=table[i];
            while(temp!=NULL){
                cout<<temp->key<<",";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
    /*
    T search(string key){
        //...
    }
    void erase(string key){
        //...
    }*/
};
int main(){
    Hashtable<int> priceMenu;
    priceMenu.insert("Burger",120);
    priceMenu.insert("Pepsi",20);
    priceMenu.insert("BurgerPizza",220);
    priceMenu.insert("Noodles",125);
    priceMenu.insert("Sandwich",80);
    priceMenu.print();
    return 0;
}