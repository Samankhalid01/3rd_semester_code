#include <iostream>
using namespace std;
void add_car();
void display_add_cars();
void display_type2_cars();
void add_ride();

// car data structure
struct CarData
{
    string driver_name;
    string car_name;
    long reg_no;
    int car_type; // 1 for 1 km type and 2 for 2 km type
    double total_earning;
    CarData *next = NULL;
    CarData *prev = NULL;
};
struct RideData
{
    string rider_name;
    float km;

    double charges;
    RideData *next = NULL;
    RideData *prev = NULL;
};
CarData *headCar = NULL;
RideData = NULL;
void add_car()
{
    CarData *curr = new CarData;
    cout << "Enter the car's name: \n";
    cin >> curr->car_name;
    cout << "Enter the driver's name: \n";
    cin >> curr->driver_name;
    cout << "Enter the reg no.: \n";
    cin >> curr->reg_no;
    cout << "Enter the car's type: \n";
    cin >> curr->car_type;
    cout << "Enter the total earning of this car: \n";
    cin >> curr->total_earning;
    if (headCar != nullptr)
    {
        headCar->prev = curr;
    }
    headCar = curr;
}
void display_add_cars()
{
    if (headCar == NULL)
    {
        cout << "No car is present. \n";
        return;
    }
    cout << "Registered cars are as follows: \n";
    CarData *curr = headCar;
    while (curr != NULL)
    {
        cout << "Driver's name: " << curr->driver_name << endl;
        cout << "Car's name: " << curr->car_name << endl;
        cout << "Reg no.: " << curr->reg_no << endl;
        cout << "Car's type: " << curr->car_type << endl;
        cout << "Total Earning: " << curr->total_earning << endl;
    }
    curr = curr->next;
}
void display_type2_cars()
{
    if (headCar == NULL)
    {
        cout << "Nothing is registered yet. \n";
        return;
    }
    cout << "Type 2 Cars: \n";
    while (curr != NULL)
    {
        CarData *curr = headCar;
        if (curr->car_type = 2)
        {
            cout << "Driver's name: " << curr->driver_name << endl;
            cout << "Car's name: " << curr->car_name << endl;
            cout << "Reg no.: " << curr->reg_no << endl;
            cout << "Car's type: " << curr->car_type << endl;
            cout << "Total Earning: " << curr->total_earning << endl;
        }
        curr = curr->next;
    }
}
void add_ride()
{
}
