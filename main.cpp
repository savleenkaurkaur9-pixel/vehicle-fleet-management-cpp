#include<iostream>
#include<string>
#include<vector>
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
class fleet 
{
    private:
    vector<vehicle*>vehicles;
    public:
    void addvehicle(vehicle*v)
    {
        vehicles.push_back(v);
        cout<<"vehicle added to fleet."<<endl;
    }
    void showAllvehicles()
    {
        cout<<"\n----fleet inventory----"<<endl;
   for(int i=0;i<vehicles.size();i++)
   {
    vehicles[i]->showdetails();
   }
    }
};
int main()
{
    fleet f1;
    Car c1(1,"Honda City",150.0);
    Bike b1(2,"Royal Enfield",80.0);
    Truck t1(3,"Tata 407",200.0);
    f1.addvehicle(&c1);
    f1.addvehicle(&b1);
    f1.addvehicle(&t1);
    f1.showAllvehicles();
    return 0;
}