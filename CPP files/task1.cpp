
#include <iostream>
using namespace std;

int main() {
    int distance[10];
    int count =0;
    float avg=0 ;
    for(int i =0 ; i < 10 ; i++){
        cout<<"enter the distance: " ; 
        cin>>distance[i];
    }
    int max = distance[0] , min = distance[0];
    for(int i=0 ; i< 10 ; i++){
        if(max < distance[i]){
            max= distance[i];
        }
        if(min > distance[i]){
            min = distance[i];
        }
        if(distance[i] < 20 || distance[i] > 100) {
            count++;
        }
        avg += distance[i];
    }
    avg /= 10;
    cout<<"maximum: "<<max <<"\n";
    cout<<"minimum: "<<min << "\n";
    cout<<"average: "<<avg << "\n";
    cout<<"count: "<< count << "\n";
    
    

    return 0;
}
