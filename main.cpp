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
    void showdetails()
    {
        cout<<"ID:"<<vehicleId<<"Name:"<<name<<"Rate/hour:"<<rateperhour<<"Available:"<<(isAvailable ? "yes" : "No")<<endl;
    }
};
int main()
{
    vehicle v1(1,"honda city",150.0);
    v1.showdetails();
    return 0;
}