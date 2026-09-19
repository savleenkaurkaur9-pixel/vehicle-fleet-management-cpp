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
    fleet myFleet;
    myFleet.loadFromFile();

    Car c1(1, "Honda City", 150.0);
    Bike b1(2, "Royal Enfield", 80.0);
    Truck t1(3, "Tata 407", 200.0);

    myFleet.addvehicle(&c1);
    myFleet.addvehicle(&b1);
    myFleet.addvehicle(&t1);

    int choice;
    do {
        cout << "\n===== Vehicle Fleet Management System =====" << endl;
        cout << "1. View Fleet" << endl;
        cout << "2. Rent a Vehicle" << endl;
        cout << "3. Return a Vehicle" << endl;
        cout << "4. Save Fleet Data" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            myFleet.showAllvehicles();
        }
        else if (choice == 2) {
            int index;
            cout << "Enter vehicle index to rent (0,1,2...): ";
            cin >> index;
            myFleet.rentVehicle(index);
        }
        else if (choice == 3) {
            int index, hours;
            cout << "Enter vehicle index to return: ";
            cin >> index;
            cout << "Enter hours used: ";
            cin >> hours;
            myFleet.returnVehicle(index, hours);
        }
        else if (choice == 4) {
            myFleet.saveToFile();
        }
        else if (choice == 5) {
            cout << "Exiting... Saving data first." << endl;
            myFleet.saveToFile();
        }
        else {
            cout << "Invalid choice, try again." << endl;
        }

    } while (choice != 5);

    return 0;
}