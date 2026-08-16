#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
class vehicle
{
    protected:
    int vehicleId;
    string name;
    double rateperhour;
    bool isAvailable;
    int rentedHours;
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
    string getName()
    {
        return name;
    }
    double getRate()
    {
        return rateperhour;
    }
    bool operator<(vehicle &other){
        return rateperhour<other.rateperhour;
    }
    bool operator>(vehicle &other){
        return rateperhour>other.rateperhour;
    }
    void rent()
    {
        if(isAvailable){
            isAvailable=false;
            cout<<name<<"has been rented."<<endl;
        }
        else{
            cout<<name<<"is not available right now."<<endl;
        }
    }
    double returnVehicle(int hours){
        if(!isAvailable){
            isAvailable=true;
            double bill=calculateRent(hours);
            cout<<name<<"returned.hours used:"<<hours<< ".total bill:"<<bill<<endl;
            return bill;
        }else{
            cout<<name<<"was  not rented."<<endl;
            return 0;
        }
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
    void rentVehicle(int index)
    {
        if(index>=0 && index<vehicles.size()){
vehicles[index]->rent();
        }else{
            cout<<"Invalid vehicle selection."<<endl;
        }
    }
    void returnVehicle(int index,int hours){
        if(index>=0 && index<vehicles.size()){
            vehicles[index]->returnVehicle(hours);
        }else{
            cout<<"Invalid vehicle selection."<<endl;

        }
    }
    void saveToFile()
    {
        ofstream outFile("fleet_data.txt");
        for(int i=0;i<vehicles.size();i++)
        {
            outFile<<vehicles[i]->getName()<<"rate:"<<vehicles[i]->getRate()<<endl;
        }
        outFile.close();
        cout<<"fleet data saved to file."<<endl;
    }
        void loadFromFile()
        {
            ifstream inFile("fleet_data.txt");
            if(!inFile){
                cout<<"No saved data found."<<endl;
                return;
            }
            string line;
            cout<<"\n--Loaded Fleet Data--"<<endl;
            while(getline(inFile,line))
            {
                cout<<line<<endl;
            }
            inFile.close();
        }
};
int main()
{
    fleet f1;
    f1.loadFromFile();
    Car c1(1,"Honda City",150.0);
    Bike b1(2,"Royal Enfield",80.0);
    Truck t1(3,"Tata 407",200.0);
    f1.addvehicle(&c1);
    f1.addvehicle(&b1);
    f1.addvehicle(&t1);
    f1.showAllvehicles();
    f1.rentVehicle(0);
    f1.returnVehicle(0,5);
    f1.showAllvehicles();
    if(c1<t1){
        cout<<c1.getName()<<"is cheaper to rent then"<<t1.getName()<<endl;
    }else{
        cout<<t1.getName()<<"is cheaper to rent then"<<c1.getName()<<endl;
    }
    f1.saveToFile();
    return 0;
}