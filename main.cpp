#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
class Person
{
private:
    string name;
    int age;
    string address;
    string phone;
    string email;
    string birthday;

public:
    string getName()
    {
        return this->name;
    }
    int getAge()
    {
        return this->age;
    }
    string getAddress()
    {
        return this->address;
    }
    string getPhone()
    {
        return this->phone;
    }
    string getEmail()
    {
        return this->email;
    }
    string getBirthday()
    {
        return this->birthday;
    }
    void setName(string name)
    {
        this->name = name;
    }
    int setAge(int age)
    {
        this->age = age;
    }
    void setAddress(string address)
    {
        this->address = address;
    }
    void setPhone(string phone)
    {
        this->phone = phone;
    }
    void setEmail(string email)
    {
        this->email = email;
    }
    void setBirthday(string birthday)
    {
        this->birthday = birthday;
    }

    Person()
    {
        this->name = "";
        this->age = 0;
        this->address = "";
        this->phone = "";
        this->email = "";
        this->birthday = "";
    }
    Person(string name, int age, string address, string phone, string emai, string birthdayl)
    {
        this->name = name;
        this->age = age;
        this->address = address;
        this->phone = phone;
        this->email = email;
        this->birthday = birthday;
    }
    Person(string name, int age, string birthday)
    {
        this->name = name;
        this->age = age;
        this->address = "";
        this->phone = "";
        this->email = "";
        this->birthday = birthday;
    }
    void display()
    {
        cout << "===============================" << endl;
        cout << "Name\t: " << this->name << endl;
        cout << "Age\t: " << this->age << endl;
        cout << "Address\t: " << this->address << endl;
        cout << "Phone\t: " << this->phone << endl;
        cout << "Email\t: " << this->email << endl;
        cout << "===============================" << endl;
    }
};

class Manager : Person
{
    int managerID;
};

class Customer : Person
{
    int customerID;
    float weight;
    float height;
    Package currentPackage;

public:

    float calculateBMI()
    {
        float bmi = weight / (height * height);
        return bmi;
    };
    Customer(Person person, int customerID)
    {
        this->currentPackage = Package();
        this->setName(person.getName());
        this->setAge(person.getAge());
        this->setAddress(person.getAddress());
        this->setPhone(person.getPhone());
        this->setEmail(person.getEmail());

        this->customerID = customerID;
    }
};

class Trainer : Person
{
private:
string Trainer_Id;
};

class Package
{
private:
    string Package_Id;
    double price;
    string duration;

public:
    string getid()
    {
        return Package_Id;
    }

    double getPrice()
    {
        return price;
    }

    string getDuration()
    {
        return duration;
    }

    Package(string Package_Id, double price, string duration)
    {
        this->Package_Id = Package_Id;
        this->price = price;
        this->duration = duration;
    }

    Package()
    {
        this->Package_Id = "";
        this->price = 0.00;
        this->duration = "";
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