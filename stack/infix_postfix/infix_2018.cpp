#include <iostream>
#include <string>
#include <stack>
using namespace std;

int prec(char c){
    switch(c){
        case '#' : case '(' : return 0;
        case '+' : case '-' : return 1;
        case '*' : case '/' : case '%' : return 2;
        case '^' : case '$' : return 3;

        default  : 
            cout<<"Something went wrong."<< endl;
            exit(1);
    }
}

string convert_to_postfix(string infix){
    char ch;
    string postfix;
    
    stack<char> s;
    s.push('#');

    //traverse the whole string
    for(int i=0; i<infix.length(); i++){
        ch = infix[i];
        switch(ch){
            case '(': s.push('('); break;
            case ')':
                      while(s.top() != '('){
                          postfix.push_back(s.top());
                          s.pop(); 
                      } 
                      s.pop(); //pop '(' as well.
                      break;
            default: 
                      if(isalnum(ch)){
                          postfix.push_back(ch);
                      }else{ 
                          //operator found + - * / ^ %
                          while(prec(s.top()) >= prec(ch)){
                              if(ch=='^' && s.top()=='^'){ //be careful here.
                                  break;
                              }
                              postfix.push_back(s.top());
                              s.pop();
                          }
                          s.push(ch); //now push it to the stack
                      }
        }
    }
    //push everything from stack to postfix
    while(s.top() != '#'){
        postfix.push_back(s.top());
        s.pop();
    }
    return postfix;
}

int main(){
    string infix;
    cout<<"Infix: "; cin>> infix;
    
    cout<< "Postfix: "<< convert_to_postfix(infix)<< endl;
    return 0;
}