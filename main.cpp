#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Package
{
private:
    string PackageID;
    double price;
    string duration;

public:
    string getid()
    {
        return PackageID;
    }

    double getPrice()
    {
        return price;
    }

    string getDuration()
    {
        return duration;
    }

    Package(string PackageID, double price, string duration)
    {
        this->PackageID = PackageID;
        this->price = price;
        this->duration = duration;
    }

    Package()
    {
        this->PackageID = "";
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

class Session
{
public:
    string time;
    string date;
    Session(string time, string date)
    {
        this->date = date;
        this->time = time;
    }
    Session()
    {
        this->date = "";
        this->time = "";
    }
};

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
    Person(string name, int age, string address, string phone, string email, string birthday)
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
    void displayBasic()
    {
        cout << "===============================" << endl;
        cout << "Name\t: " << this->name << endl;
        cout << "Age\t: " << this->age << endl;
        cout << "Address\t: " << this->address << endl;
        cout << "Phone\t: " << this->phone << endl;
        cout << "Email\t: " << this->email << endl;
        cout << "===============================" << endl;
    }
    friend bool isBirthday(Person, string);
    void promptSetPerson()
    {
        cout << "Enter name: ";
        cin >> this->name;
        cout << "Enter age: ";
        cin >> this->age;

        cout << "Enter address: ";
        cin >> this->address;

        cout << "Enter phone: ";
        cin >> this->phone;

        cout << "Enter email: ";
        cin >> this->email;

        cout << "Enter birthday: ";
        cin >> this->birthday;
    }
};

class Manager : Person
{
    int managerID;

public:
    Manager(Person person, int managerID)
    {
        this->setName(person.getName());
        this->setAge(person.getAge());
        this->setAddress(person.getAddress());
        this->setPhone(person.getPhone());
        this->setEmail(person.getEmail());

        this->managerID = managerID;
    };
    void promptSetManager()
    {
        promptSetPerson();
        cout << "Enter Manager ID: ";
        cin >> this->managerID;
    }
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
    void promptSetCustomer()
    {
        promptSetPerson();
        cout << "Enter Customer ID: ";
        cin >> this->customerID;
    }
};

class Trainer : Person
{
private:
    int TrainerID;
    Session session[7];

public:
    Trainer(Person person, int TrainerID)
    {
        this->setName(person.getName());
        this->setAge(person.getAge());
        this->setAddress(person.getAddress());
        this->setPhone(person.getPhone());
        this->setEmail(person.getEmail());

        this->TrainerID = TrainerID;
    }

    void set_session()
    {
    }
    void print_session()
    {
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << (i + 1) << session[i].date << session[i].time << endl;
        }
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    void promptSetTrainer()
    {
        promptSetPerson();
        cout << "Enter Trainer ID: ";
        cin >> this->TrainerID;
    }
};

bool isBirthday(Person person, string today)
{
    return person.birthday == today;
}

int main()
{
    Person person[] = {
        Person("RuiPei", 20, "123 Main St", "012-123456710", "Ruipei@email.com", "01/31"),
        Person("QianDe", 25, "456 Maple Ave", "012-123456711", "QianDe@email.com", "02/28"),
        Person("Kelvin", 24, "789 Oak Dr", "012-123456712", "Kelvin@email.com", "03/21"),
        Person("YiZe", 22, "321 Pine Rd", "012-123456713", "YiZe@email.com", "08/24"),
        Person("TanKai", 23, "654 Elm Blvd", "012-123456714", "TanKai@email.com", "01/29"),
        Person("KaiZa", 30, "987 Cedar Ln", "012-123456715", "KaiZa@email.com", "06/12"),
        Person("XingHan", 23, "234 Birch Pkwy", "012-123456716", "XingHan@email.com", "02/29"),
        Person("Jason", 29, "567 Walnut Cir", "012-123456717", "Jason@email.com", "01/01"),
        Person("Danish", 25, "890 Cherry Sq", "012-123456718", "Danish@email.com", "09/21"),
        Person("Justin", 26, "1234 Peachtree Pl", "012-123456719", "Justin@email.com", "02/31"),
        Person("Herta", 32, "5678 Magnolia Ct", "012-123456720", "Herta@email.com", "11/12"),
        Person("YuanShen", 28, "9012 Willow Way", "012-123456721", "YuanShen@email.com", "08/21"),
        Person("XingQiong", 22, "3456 Spruce St", "012-123456722", "XingQiong@email.com", "05/21"),
        Person("ZeJie", 20, "7890 Redwood Ave", "012-123456723", "ZeJie@email.com", "07/27"),
        Person("ZhongRi", 19, "2345 Dogwood Dr", "012-123456725", "ZhongRi@email.com", "01/21"),
        Person("GuiZhong", 31, "6789 Aspen Rd", "012-123456727", "GuiZhong@email.com", "10/10"),
        Person("RuanMei", 21, "0123 Fir Blvd", "012-123456728", "RuanMei@email.com", "05/20"),
        Person("James", 29, "4567 Hemlock Ln", "012-123456731", "James@email.com", "09/01"),
        Person("Hina", 33, "8901 Juniper Pkwy", "012-123456736", "Hina@email.com", "12/31"),
        Person("QingRu", 34, "2348 Poplar Cir", "012-123456730", "QingRu@email.com", "07/31")};

    Package package[] = {
        Package("1", 160.00, "Monthly"),
        Package("2", 300.00, "2Month"),
        Package("3", 640.00, "6Month"),
        Package("4", 1600.00, "Annually")};
}