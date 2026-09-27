
#include <iostream>
using namespace std;

int main() {
    long long n;
    int arr[10] = {0};
    cout<<"enter no.: ";
    cin>>n;
    if(n == 0){
        cout<< " invalid";
    }
    while(n>0){
        int rem = n%10;
        arr[rem]++;
        n /= 10;
    }
    for(int i=0 ; i<10;  i++){
        if(arr[i] != 0){
        cout<<"count of digit: "<<i<<" is "<<arr[i]<<"\n"; 
        }
    }
    
    
    

    return 0;
}
