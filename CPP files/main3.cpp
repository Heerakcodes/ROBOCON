#include<iostream>
using namespace std ;
class robot{
    private :
    int speed;
    public:
    void forward(int speed){
    this->speed=speed;    
    cout << "robot is moving forward"<<endl;
    cout << "at speed: "<<speed<<endl;
}
void backward(int speed){
    cout << "robot is moving backward"<<endl;
    this->speed=speed;    
    
    cout << "at speed: "<<speed<<endl;
}
void left(int speed){
    cout << "robot is moving left"<<endl;
    this->speed=speed;    
    
    cout << "at speed: "<<speed<<endl;
}
void right(int speed){
    cout << "robot is moving right"<<endl;
    this->speed=speed;    
    
    cout << "at speed: "<<speed <<endl;
}

};


int main(){
    char op ;
    bool input = true ;
    int speed;
    robot r;

    while(input){
    cout<<"enter the op: "<<endl;
    cin >> op;
    cout<<"enter the speed: ";
    cin>> speed;
    switch(op){
        case 'F':
           r.forward(speed);
           break;
        case 'B':
           r.backward(speed);
           break; 
        case 'R':
           r.right(speed);
           break;
        case 'L':
           r.left(speed);  
           break;
        default :
           cout<< "invalid"<<endl;      
    } 
    cout<<"enter 1 for run again , 0 for terminate: ";
    cin>> input ;

    
}

    return 0;

    }