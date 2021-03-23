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
    int currentSize;
    int tableSize;

    int hashFn(string key){
        int idx=0;
        int p=1;
        for(int j=0;j<key.length();j++){
            idx=idx+(key[j]*p)%tableSize;
            idx=idx%tableSize;
            p=(p*27)%tableSize;
        }
        return idx;
    }
    void rehash(){
        Node<T>** oldTable=table;
        int oldTableSize=tableSize;
        tableSize=2*tableSize;
        table=new Node<T>*[tableSize];
        for(int i=0;i<tableSize;i++){
            table[i]=NULL;
        }
        currentSize=0;

        //shift the elemetns from old table to new table
        for(int i=0;i<oldTableSize;i++){
            Node<T>*temp=oldTable[i];
            while(temp!=NULL){
                insert(temp->key,temp->value);
                temp=temp->next;
            }
            if(oldTable[i]!=NULL){
                delete oldTable[i];
            }
        } 
        delete [] oldTable;
    }

    public:
    Hashtable(int ts=7){
        tableSize=ts;
        table=new Node<T>*[tableSize];
        currentSize=0;
        for(int i=0;i<tableSize;i++){
            table[i]=NULL;
        }
    }

    void insert(string key,T value){
        int idx=hashFn(key);
        Node<T>*n=new Node<T>(key,value);
        //Insert at the head of the linked list with id equal to idx
        n->next=table[idx];
        table[idx]=n;
        currentSize++;

        float loadFactor=currentSize/tableSize;
        if(loadFactor>0.7){
            rehash();
        }
    }
    void print(){
        for(int i=0;i<tableSize;i++){
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
    priceMenu.insert("BurgerNoodles",120);
    priceMenu.insert("PepsiCoke",20);
    priceMenu.insert("BurgerCoke",220);
    priceMenu.insert("NoodlesCake",125);
    priceMenu.insert("VegSandwich",80);
    priceMenu.print();
    return 0;
}