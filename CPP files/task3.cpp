#include<iostream>
using namespace std ;
void sensorReading(int array[]){
    for(int i = 0 ; i < 8 ; i++){
        cout<<"enter the sensor reading(0-white,1-black) "<< i+1<<":" ;
        cin>>array[i];

}
}
int linePosition(int array[]){
    int sum=0;
    int count=0;
    for(int i =0 ; i < 8 ; i++){
        if(array[i] == 1){
            sum += i;
            count++;
        }

    }
    if(count ==0 ){
        return -1;
    }
    return sum/count;
}
void movement(int position){
    if( position == -1){
        cout<<"line position : lost"<<endl;
        cout<<"action: stop";
    }
    else if(position < 3 ){
        cout<<"line position: left"<<endl;
        cout<<"action: move left";
    }
    else if(position > 4){
        cout<<"line position: right"<<endl;
        cout<<"action: move right";

    }
    else{
        cout<<"line position: center"<<endl;
        cout<<"action: move forward";
    }
}



int main(){
    int array[8];
    cout << "taking input of sensors: ";
    sensorReading(array);
    int position = linePosition(array);
    cout <<"position: "<< position<<endl;
    movement(position);
    return 0; 
    
    }

    

    
