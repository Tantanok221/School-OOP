#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
class Person
{
};

class Manager
{
};

class Customer
{
};

class Trainer
{
};

class Package
{
private:
    string id;
    double price;
    string duration;

public:
    string getid()
    {
        return id;
    }

    double getPrice()
    {
        return price;
    }

    string getDuration()
    {
        return duration;
    }

    Package(string id, double price, string duration)
    {
        this->id = id;
        this->price = price;
        this->duration = duration;
    }

    void package_display()
    {
        cout << "========================================" << endl;
        cout << "             Package Details" << endl;
        cout << "========================================" << endl;
        cout << "ID" << ": " << getid() << endl;
        cout << "Price" << ": " << fixed << setprecision(2) << getPrice() << endl;
        cout << "Duration" << ": " << getDuration() << endl;
    }
};

int main()
{
    Package package[] = {
        Package("1", 160.00, "Monthly"),
        Package("2", 300.00, "2Month"),
        Package("3", 640.00, "6Month"),
        Package("4", 1600.00, "Annually")};
    package->package_display();
}