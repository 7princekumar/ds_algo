#include <iostream>
#include <vector>
using namespace std;

struct node{
    int data;
    struct node* next;
};
typedef struct node* NODE;

NODE new_node(int data){
    NODE temp = new(struct node);
    temp->data = data;
    temp->next = NULL;
    return temp;
}

NODE insert_at_back(NODE head, int data){
    if(head == NULL) head = new_node(data);
    else{
        NODE temp = new_node(data);
        NODE p = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}


NODE create_default_ll(){
    NODE head = NULL;
    int a[] = {1,2,3,4,5};
    int n = sizeof(a)/sizeof(a[0]);
    for(int i=0; i<n; i++){
        head = insert_at_back(head, a[i]);
    }
    return head;
}

void print_sll(NODE head){
    NODE p = head;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int get_count(NODE head){
    NODE p = head;
    int count = 0;
    while(p != NULL){
        count++;
        p = p->next;
    }
    return count;
}

int main(){
    NODE head = create_default_ll();
    cout<< "SLL: "; print_sll(head);
    cout<< "Count: " << get_count(head) << endl;
    return 0;
}