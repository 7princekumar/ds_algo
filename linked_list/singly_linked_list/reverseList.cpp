#include <iostream>
#include <vector>
#include <cstdbool>
using namespace std;

struct node{
    int data;
    struct node* next;
};
typedef struct node* NODE;

NODE createNewList(int);
void printList(NODE);
NODE reverseListItr(NODE);
NODE reverseListRec(NODE, NODE) ;



int main(){
    int numOfNodes = 5;
    NODE head = createNewList(numOfNodes);
    cout<<"Original list: "; printList(head);

    head = reverseListRec(head, NULL);
    cout<<"Reversed list(Rec): "; printList(head);

    head = reverseListItr(head);
    cout<<"Reversed list(Itr): "; printList(head);

    return 0;
}

NODE createNewList(int n){
    //create head
    NODE head;
    head = (NODE)malloc(sizeof(struct node));
    head->data = 1;
    head->next = NULL;

    NODE p = head ;

    //create other nodes;
    for(int i=1; i<n; i++){
        NODE temp;
        temp = (NODE)malloc(sizeof(struct node));
        temp->data = i+1;
        temp->next = NULL;

        p->next = temp;
        p = temp ;
    }

    return head;
}

void printList(NODE head){
    NODE p = head;
    while(p){
        cout<<"["<<p->data<<"]->";
        p = p->next;
    }
    cout<<endl;
}


NODE reverseListItr(NODE head){
    if(!head || !head->next){
        return head;
    }

    NODE p = head;
    NODE temp = NULL;
    NODE previous = NULL;

    while(p){
        temp = p->next;
        p->next = previous;
        previous = p;
        p = temp;
    }

    return previous;
}

NODE reverseListRec(NODE curr, NODE previous){
    NODE newHead;
    if(curr == NULL){ //empty list
        return curr;
    }else if(curr->next == NULL){ //last node, make this head
        curr->next = previous ;
        return curr; //this is the new-head
    }else{
        newHead = reverseListRec(curr->next, curr);  //note: newHead ref doesn't change.
        //once it gets the newHead ref, keep returning it to all recursive returns
        curr->next = previous; //actually, inverses the list
        return newHead;
    }
}