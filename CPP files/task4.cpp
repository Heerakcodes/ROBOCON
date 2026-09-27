#include <iostream>
using namespace std;

class Robot{
private:
    int speed;
    int battery;

public:

    void setSpeed(int s){
        if(s >= 0 && s <= 100){
            speed = s;
        }
        else{
            cout << "Invalid speed" << endl;
        }
    }

    void setBattery(int b){
        if(b >= 0 && b <= 100){
            battery = b;
        }
        else{
            cout << "Invalid battery" << endl;
        }
    }

    void moveForward(){
        if(battery == 0){
            cout << "No movement" << endl;
        }
        else{
            cout << "Move Forward" << endl;
            battery = battery - 5;
        }
    }

    void moveBackward(){
        if(battery == 0){
            cout << "No movement" << endl;
        }
        else{
            cout << "Move Backward" << endl;
            battery = battery - 5;
        }
    }

    void turnLeft(){
        if(battery == 0){
            cout << "No movement" << endl;
        }
        else{
            cout << "Turn Left" << endl;
            battery = battery - 5;
        }
    }

    void turnRight(){
        if(battery == 0){
            cout << "No movement" << endl;
        }
        else{
            cout << "Turn Right" << endl;
            battery = battery - 5;
        }
    }

    void displayStatus(){
        cout << "Robot Speed: " << speed << endl;
        cout << "Battery: " << battery << "%" << endl;
    }
};

int main(){
    Robot r;

    int speed;
    int battery;
    int input;

    cout << "Enter Speed: ";
    cin >> speed;

    cout << "Enter Battery: ";
    cin >> battery;

    r.setSpeed(speed);
    r.setBattery(battery);

    while(true){
        char op;

        cout << endl;
        cout << "Enter the operation (F/B/L/R): ";
        cin >> op;

        switch(op){
            case 'F':
                r.moveForward();
                break;

            case 'B':
                r.moveBackward();
                break;

            case 'R':
                r.turnRight();
                break;

            case 'L':
                r.turnLeft();
                break;

            default:
                cout << "Invalid " << endl;
        }

        r.displayStatus();

        cout << endl;
        cout << "Enter 1 to run again, 0 to terminate: ";
        cin >> input;

        if(input == 0){
            break;
        }
    }

    cout << endl;
    cout << "Final Robot Status:" << endl;
    r.displayStatus();

    return 0;
}