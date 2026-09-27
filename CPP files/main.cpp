#include<iostream>
using namespace std ;
int main(){
    int a = 2 ;
    int b = 3;
    char op ;
    cin>>op;


    switch(op){
        case '+' :
          cout<< a+b;
          break;
        case '-' :
          cout<< a-b;
          break;
        case '*' :
          cout<< a*b;
          break;
        case '/' :
         cout << a/b;
         break;
        default :
        cout<< "invalid op";    
      
           

    }
}