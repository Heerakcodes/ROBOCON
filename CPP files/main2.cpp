#include<iostream>
using namespace std ;
void forward(){
    cout << "robot is moving forward"<<endl;

}
void backward(){
    cout << "robot is moving backward"<<endl;

}
void left(){
    cout << "robot is moving left"<<endl;

}
void right(){
    cout << "robot is moving right"<<endl;

}

int main(){
    char op ;
    bool input = true ;

    while(input){
    cout<<"enter the op: ";
    cin >> op;
    
    switch(op){
        case 'F':
           forward();
           break;
        case 'B':
           backward();
           break; 
        case 'R':
           right();
           break;
        case 'L':
           left();  
           break;
        default :
           cout<< "invalid"<<endl;      
    } 
    cout<<"enter 1 for run again , 0 for terminate: ";
    cin>> input ;

    
}

    return 0;

    }