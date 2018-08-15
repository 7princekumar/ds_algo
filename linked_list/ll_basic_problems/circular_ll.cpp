#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct node{
    int data;
    struct node* next;
};
typedef struct node* NODE;

void print_c_ll(NODE head){
    if(head == NULL){
        return;
    }
    NODE p = head;
    while(p->next != head){
        cout<<p->data<<"->";
        p = p->next;
    }
    cout<< p->data;
    cout<< endl;
}

NODE new_node(int data){
    NODE temp = new(struct node);
    temp->data = data;
    temp->next = NULL;
    return temp;
}

NODE insert_at_front(NODE head, int data){
    if(head == NULL){ // no list
        head = new_node(data);
        head->next = head;
    }else if(head->next == head){ //one ele
        NODE temp = new_node(data);
        temp->next = head;
        head->next = temp; 
        head = temp;
    }else{
        NODE temp = new_node(data);
        NODE p = head;
        while(p->next != head){
            p = p->next;
        }
        p->next = temp;
        temp->next = head;
        head = temp;
    }
    return head;
}


NODE delete_at_front(NODE head){
    if(head == NULL){
        return NULL;
    }else if(head->next == head){
        return NULL;
    }else{
        NODE p = head;
        while(p->next != head){
            p = p->next;
        }
        p->next = head->next;
        head = head->next;
    }
    return head;
}

int main(){
    NODE head = NULL;
    int ch;
    cout<<"1. Insert element    2. Delete element      3. Display     9. Exit\n";
    while(1){
        cout<<"Choice: "; cin>>ch;
        switch(ch){
            case 1: 
                int data; cout<<"Data: "; cin>> data;
                head = insert_at_front(head, data);
                break;
            case 2:
                head = delete_at_front(head);
                break;
            case 3:
                print_c_ll(head) ;
                break ;
            case 9:
                exit(0);
            default: cout<<"Invalid input."<<endl;
        }
    }
    return 0;
}

