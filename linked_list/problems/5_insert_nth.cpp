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

//4 cases
//handle case -> head == null and n == 0, n != 0
//handle case -> head != null and n == 0, n != 0
NODE insert_nth(NODE head, int n, int data){
    if(head == NULL && n == 0){
        head = new_node(data);
    }else if(head == NULL && n!=0){
        return head;
    }else if(head != NULL && n==0){
        NODE temp = new_node(data);
        temp->next = head;
        head = temp;
    }else{
        NODE p = head;
        int count = 0; //head ka index is zero
        while(p != NULL){
            if(count == n-1) break;
            count++; //first check then increment count
            p = p->next;
        }
        if(p != NULL){
            NODE temp = new_node(data);
            temp->next = p->next;
            p->next = temp;
        }
    }
    return head;
}

int main(){
    NODE head1 = create_default_ll();
    cout<< "SLL: "; print_sll(head1);
    head1 = insert_nth(head1, 2, 22);
    cout<< "SLL: "; print_sll(head1);

    NODE head2 = NULL; //should insert
    cout<< "SLL: "; print_sll(head2);
    head2 = insert_nth(head2, 0, 99);
    cout<< "SLL: "; print_sll(head2);

    NODE head3 = NULL; //should not insert
    cout<< "SLL: "; print_sll(head3);
    head3 = insert_nth(head3, 1, 999);
    cout<< "SLL: "; print_sll(head3);

    NODE head4 = create_default_ll(); //should not insert
    cout<< "SLL: "; print_sll(head4);
    head4 = insert_nth(head4, 10, 100);
    cout<< "SLL: "; print_sll(head4);

    NODE head6 = create_default_ll(); //should insert
    cout<< "SLL: "; print_sll(head6);
    head6 = insert_nth(head6, 0, -87);
    cout<< "SLL: "; print_sll(head6);
    return 0;
}