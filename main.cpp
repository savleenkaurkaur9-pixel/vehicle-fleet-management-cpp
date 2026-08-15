#include<iostream>
#include<string>
using namespace std;
class vehicle
{
    protected:
    int vehicleId;
    string name;
    double rateperhour;
    bool isAvailable;
    public:
    vehicle(int id,string vname,double rate)
    {
        vehicleId=id;
        name=vname;
        rateperhour=rate;
        isAvailable=true;
        cout<<"vehicle created:"<<name<<endl;
    }
    ~vehicle()
    {
        cout<<"vehicle removed:"<<name<<endl;
    }
    virtual double calculateRent(int hours)
    {
        return rateperhour*hours;
    }
    void showdetails()
    {
        cout<<"ID:"<<vehicleId<<"Name:"<<name<<"Rate/hour:"<<rateperhour<<"Available:"<<(isAvailable ? "yes" : "No")<<endl;
    }
};
class Car:public vehicle
{
public:
Car(int Id,string vname,double rate):vehicle(Id,vname,rate)
{}
double calculateRent(int hours) override{
    return rateperhour*hours+100;
}
};
class Bike:public vehicle
{
public:
Bike(int Id,string vname,double rate):vehicle(Id,vname,rate)
{}
double calculateRent(int hours) override{
    return rateperhour*hours+100;
}
};
class Truck:public vehicle{
 public:
Truck(int Id,string vname,double rate):vehicle(Id,vname,rate)
{}
double calculateRent(int hours) override{
        return rateperhour*hours+300;
    }

};
int main()
{
    Car c1(1,"Honda City",150.0);
    Bike b1(2,"Royal Enfield",80.0);
    Truck t1(3,"Tata 407",200.0);
   c1.showdetails();
   cout<<"car rent for 5 hours:"<<c1.calculateRent(5)<<endl;
   b1.showdetails();
   cout<<"bike rent for 5 hours:"<<b1.calculateRent(5)<<endl;
   t1.showdetails();
   cout<<"truck rent for 5 hours:"<<t1.calculateRent(5)<<endl;
    return 0;
}