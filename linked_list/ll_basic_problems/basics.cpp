#include <iostream>
#include <cstdbool>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    int data;
    struct node* next;
};
typedef struct node* NODE;

NODE new_node(int data){
    NODE temp = new(struct node); //use 'delete', not 'free' to deallocate
    temp->data = data;
    temp->next = NULL;

    return temp;
}

NODE insert_at_front(NODE head, int data){
    if(head == NULL){
        head = new_node(data);
    }else{
        NODE temp = new_node(data);
        temp->next = head;
        head = temp;
    }
    return head;
}

NODE insert_at_back(NODE head, int data){
    if(head == NULL){
        head = new_node(data);
    }else{
        NODE temp = new_node(data);
        NODE curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = temp;
    }
    return head;
}

NODE create_default_list(){
    NODE head = new struct node();
    //int ele[] = {1,2,3,4};
    
    vector<int> v{4,3,2,1};
    //reverse(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        head = insert_at_front(head, v[i]);
        cout<<head->data<<"\n";
    }
    return head;
}

void print_list(NODE head){
    NODE curr = head;
    while(curr != nullptr){
        cout<<curr->data<<"->";
        curr = curr->next;
    }
    cout<<endl;
}

int length_of_list(NODE head){
    int count = 0;
    NODE curr = head;
    while(curr != NULL){
        count++;
        curr = curr->next;
    }
    return count;
}


int getNth(NODE head, int index){
    NODE p = head;
    while(p != NULL && index>0){
        p = p->next;
        index--;
    }
    if(index == 0){
        return p->data;
    }else{
        return -999;
    }
}

void delete_list(NODE head){
    if(head == NULL){
        return;
    }else{
        delete_list(head->next);
        delete head;
    }
}

int pop(NODE head){
    int data;
    if(head == NULL){  //no list
        data = -999;
    }else if(head->next == NULL){ //only 1 node
        data = head->data;
        head = NULL ;
    }
    else{
        NODE curr = head; NODE previous = NULL;
        while(curr->next != NULL){
            previous = curr; //previous to p
            curr = curr->next;
        }
        data = curr->data;
        previous->next = NULL;
        delete curr;
    }
    return data;
}

int main(){
    NODE head = create_default_list();
    print_list(head);
    cout<<"Popped: "<<pop(head)<<endl;
    cout<<"Popped: "<<pop(head)<<endl;
    cout<<"Popped: "<<pop(head)<<endl;
    cout<<"Popped: "<<pop(head)<<endl;
    cout<<"Popped: "<<pop(head)<<endl;
    cout<<"Popped: "<<pop(head)<<endl;
    print_list(head);
    return 0;
}