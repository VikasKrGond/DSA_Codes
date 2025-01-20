/*
A Class is a user-defined data type that has data members and member functions.
Data members are the data variables and member functions are the functions used to manipulate these variables together these data members and member
 functions define the properties and behavior of the objects in a Class.
In the above example of class Car, the data member will be speed limit, mileage, etc and member functions can apply brakes, increase speed, etc.
We can say that a Class in C++ is a blueprint representing a group of objects which shares some common properties and behaviors.
*/
#include<iostream>
using namespace std;
class Car{
    private:
    int speedLimit;
    int milage;
    int curr_Speed;
    public:
    Car()
    {
        speedLimit=0;
        curr_Speed=0;
        milage=0;
    }
    void setSpeed(int speed)
    {
        this->curr_Speed=speed;
    }
    void setMilage(int mil)
    {
        this->milage=mil;
    }
    void setSpeedLimit(int limit)
    {
        this->speedLimit=limit;
    }
    void applyBreaks()
    {
        curr_Speed=0;
    }
    void displayInfo()
    {
        cout<<"\nCurrent Speed: "<<this->curr_Speed;
        cout<<" \nMilage : "<<this->milage;
        cout<<"\nCurrent Speed Limit: "<<this->speedLimit;
    }
    void accelarate(int acc)
    {
        this->curr_Speed=curr_Speed+acc;
    }
};
int main()
{
    Car c1;
    c1.setSpeed(10);
    c1.setMilage(20);
    c1.setSpeedLimit(100);
    c1.displayInfo();
    return 0;
}