#include<iostream>
using namespace std;

class Shop{
    int itemId[100];
    int itemPrice[100];
    int counter;
public:
    void initCounter(void){
        counter=0;
    }
    void setPrice(void);
    void display(void);
};

void Shop::setPrice(void){
    cout<<"Enter Id of your "<<counter<<" item: ";
    cin>>itemId[counter];
    cout<<"Enter Price of your "<<counter<<" item: ";
    cin>>itemPrice[counter];
    counter++;
}

void Shop::display(void){
    for(int i=0;i<counter;i++){
        cout<<"Id: "<<itemId[i]<<" Price: "<<itemPrice[i]<<endl;
    }
}

int main(){
    Shop s;
    int n;
    cout<<"Enter the number of items: ";
    s.initCounter();
    cin>>n;
    for(int i=0;i<n;i++){
        s.setPrice();
    }
    s.display();
    return 0;
}