#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int data;
    struct node* next;
};
typedef struct node* NODE;
NODE head = NULL;

void insert_front();
void insert_rear();
void insert_pos();
// void delete_front();
// void delete_rear();
// void delete_pos();
void display();
void print_menu();

int main(){
    int ch;
    print_menu();
    while(true){
        cout<<"\nChoice: ";
        cin>> ch;
        switch(ch){
            case 1: insert_front(); break;
            case 2: insert_rear();  break;
            case 3: insert_pos();   break;
            // case 4: delete_front(); break;
            // case 5: delete_rear();  break;
            // case 6: delete_pos();   break;
            case 7: display();      break;
            case 8: print_menu();   break;
            case 9: exit(0);
            default: cout<<"Invalid Input."<<endl;
        }
    }
    return 0;
}

void print_menu(){
    cout<<"1. Insert at front." <<endl;
    cout<<"2. Insert at rear."  <<endl;
    cout<<"3. Insert at specific position."<<endl;
    // cout<<"4. Delete at front." <<endl;
    // cout<<"5. Delete at rear."  <<endl;
    // cout<<"6. Delete at specific position."<<endl;
    cout<<"7. Display List."    <<endl;
    cout<<"8. Print Menu."      <<endl;
    cout<<"9. Exit."            <<endl<<endl;;
}

void display(){
    NODE p = head;
    while(p != NULL){
        cout<<'['<< p->data <<"]-> ";
        p = p->next;
    }
    cout<<endl;
}

void insert_front(){
    NODE temp;
    temp = NODE(malloc(sizeof(struct node)));
    temp->next = NULL;
    cout<<"Data: "; cin>> temp->data;
    
    if(head == NULL){
        head = temp;
    }else{
        temp->next = head;
        head = temp;
    }
}


void insert_rear(){
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->next = NULL;
    cout<<"Data: "; cin>> temp->data;

    if(head == NULL){
        head = temp;
    }else{
        NODE p = head;
        while( p->next != NULL ){
            p = p->next;
        }
        p->next = temp;
    }
}

void insert_pos(){
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->next = NULL;
    cout<<"Data: "; cin>> temp->data;

    int pos; cout<<"Pos: "; cin>> pos;
    if(pos == 0){
        if(head == NULL){
            head = temp;
        } else {
            temp->next = head;
            head = temp;
        }  
    } else {
        NODE f = head; //front pointer
        NODE r = head; //rear pointer
        int count = 0;
        while(count != pos && f->next != NULL){
            r = f;
            f = f->next;
            count++;
        }
        if(count != pos){
            cout<<"Invalid position."<<endl;
            cout<<"List: "; display();
        } else {
            r->next = temp;
            temp->next = f;
        }
    }
    
}
