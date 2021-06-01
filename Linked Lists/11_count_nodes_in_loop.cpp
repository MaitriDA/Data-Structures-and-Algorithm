#include <iostream>
using namespace std;
class node{
public:
    int data;
    node *next;
    node(int d){
        data = d;
        next = NULL;
    }
};

void insert_at_tail(node *&head, int d){
    if (head == NULL){
        head = new node(d);
        return;
    }
    node *temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    node *n = new node(d);
    temp->next = n;
    return;
}

void print(node *head){
    while (head->next != NULL){
        cout << "Data: " << head->data << "  Next: " << head->next->data << endl;
        head = head->next;
    }
}

bool detect_loop(node *head){
    node *slow = head;
    node *fast = head;
    while (slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
            return true;
        }
    }
    return false;
}

int count_nodes(node *head){
    node *slow = head;
    node *fast = head;
    int count = 0;
    while (slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
            node *temp = slow;
            int count = 1;
            while (temp->next != slow){
                count++;
                temp = temp->next;
            }
            return count;
        }
    }
}

int main(){
    node *head = NULL;
    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 3);
    insert_at_tail(head, 4);
    insert_at_tail(head, 5);
    print(head);
    cout << endl;
    //Creating loop
    head->next->next->next->next->next = head->next->next;
    if (detect_loop(head) == 1){
        cout << "Loop detected"<<endl;
        cout << "No of Nodes in loop: "<<count_nodes(head);
    }
    else{
        cout << "No loop detected";
    }
}