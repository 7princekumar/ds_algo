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


NODE reverse_itr(NODE head){
    if(head == NULL) NULL;
    NODE prev = NULL; NODE curr = head; NODE front = head->next;
    while(front != NULL){
        curr->next = prev; //1        
        prev = curr; //2
        curr = front; //3
        front = curr->next; //4
    }
    curr->next = prev;
    return curr;
}

void reverse_rec(NODE curr, NODE prev, NODE& new_head){
    if(curr == NULL) return; 
    if(curr->next == NULL){ //last node, this is the new_head
        new_head = curr;
        // curr->next = prev; //don't, cuz we are calling reverse_rec with curr->next again
    }
    reverse_rec(curr->next, curr, new_head);
    curr->next = prev;
}

int main(){
    NODE head = create_default_ll();
    cout<< "SLL: "; print_sll(head);
    
    NODE head2 = reverse_itr(head);
    cout<< "SLL: "; print_sll(head2);

    head = create_default_ll();
    NODE head3 = NULL;
    NODE prev = NULL;
    reverse_rec(head, prev, head3);
    cout<< "SLL: "; print_sll(head3);
    return 0;
}