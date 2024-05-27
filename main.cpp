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

    friend void package_display(Package);
};

void package_display(Package package)
{
    cout << "=========================================" << endl;
    cout << "ID" << "       : " << package.getid() << endl;
    cout << "Price" << "    : " << fixed << setprecision(2) << package.getPrice() << endl;
    cout << "Duration" << " : " << package.getDuration() << endl;
    cout << "=========================================" << endl;
}

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
    void setAge(int age)
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
        cout << "Name\t: " << this->name << endl;
        cout << "Age\t: " << this->age << endl;
        cout << "Address\t: " << this->address << endl;
        cout << "Phone\t: " << this->phone << endl;
        cout << "Email\t: " << this->email << endl;
        cout << "=========================================" << endl;
    }
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
    Trainer()
    {
        this->setName(" ");
        this->setAge(0);
        this->setAddress(" ");
        this->setPhone(" ");
        this->setEmail(" ");
        this->TrainerID = 0;
    }

    string getsName()
    {
        string name = getName();
        return name;
    }
    void initSession(Session *session, int count)
    {
        for (int i = 0; i < count; i++)
        {
            this->session[i] = session[i];
        }
    }
    void set_session()
    {
        cout << "How many session you want to set?";
        int count;
        cin >> count;
        for (int i = 0; i < count; i++)
        {
            cout << "Enter Date for Session " << i + 1 << ": ";
            cin >> session[i].date;
            cout << "Enter Time for Session " << i + 1 << ": ";
            cin >> session[i].time;
        }
    }
    void print_session()
    {
        cout << "---------- Session Infomation -----------" << endl;
        cout << "Trainer\t: " << this->getName() << endl;
        cout << "Trainer ID\t: " << this->TrainerID << endl;
        for (int i = 0; i < 7; i++)
        {
            cout << "Session " << (i + 1) << "\t: " << session[i].date << " - " << session[i].time << endl;
        }

    }
    void promptSetTrainer()
    {
        promptSetPerson();
        cout << "Enter Trainer ID: ";
        cin >> this->TrainerID;
    }
    void displayInfo()
    {
        displayBasic();
        cout << "Customer ID\t: " << this->TrainerID << endl;
        print_session();
        cout << "=========================================" << endl;
    }
};

class Customer : Person
{
    int customerID;
    float weight;
    float height;
    Package currentPackage;
    Trainer assignedTrainer;

public:
    float calculateBMI()
    {
        float bmi = weight / ((height * 0.01) * (height * 0.01));
        return bmi;
    };
    Customer()
    {
        this->setName("");
        this->setAge(0);
        this->setAddress("");
        this->setPhone("");
        this->setEmail("");
        this->customerID = 0;
        this->weight = 0;
        this->height = 0;
        this->currentPackage = Package();
        this->assignedTrainer = Trainer();
    }
    Customer(Person person, int customerID,int weight,int height)
    {
        this->weight = weight;
        this->height = height;
        this->currentPackage = Package();
        this->setName(person.getName());
        this->setAge(person.getAge());
        this->setAddress(person.getAddress());
        this->setPhone(person.getPhone());
        this->setEmail(person.getEmail());
        this->customerID = customerID;
    }
    void assignPackage(Package package)
    {
        this->currentPackage = package;
    }
    void promptSetCustomer()
    {
        promptSetPerson();
        cout << "Enter Customer ID: ";
        cin >> this->customerID;
    }
    void displayInfo()
    {
        displayBasic();
        cout << "Customer ID\t: " << this->customerID << endl;
        cout << "Weight\t        : " << this->weight << endl;
        cout << "Height\t        : " << this->height << endl;
        cout << "BMI\t        : " << calculateBMI() << endl;
        cout << "Assigned Trainer:\t" << this->assignedTrainer.getsName() << endl;
        cout << "Current Package :\t" << this->currentPackage.getDuration() << endl;
        cout << "=========================================" << endl;
    }
};
// 3，4，5，8 broken
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
    Customer customer[] = {
        Customer(person[0], 1, 42, 140),
        Customer(person[1], 2, 42, 151),
        Customer(person[2], 3, 70, 185),
        Customer(person[3], 4, 60, 175),
        Customer(person[4], 5, 60, 184),
        Customer(person[5], 6, 32, 162),
        Customer(person[6], 7, 54, 182),
        Customer(person[7], 8, 62, 161),
        Customer(person[8], 9, 63, 162),
        Customer(person[9], 1, 62, 160),
        Customer(person[10], 1, 62, 171),
        Customer(person[11], 1, 72, 172),
        Customer(person[12], 1, 42, 173),
        Customer(person[13], 1, 52, 174),
        Customer(person[14], 1, 82, 175),

    };
    Trainer trainer[] = {
        Trainer(person[15], 1),
        Trainer(person[16], 2),
        Trainer(person[17], 3),
        Trainer(person[18], 4),
        Trainer(person[19], 5),
    };
    Session session1[] = {
        Session("10:00-11:00", "Monday"),
        Session("10:00-12:00", "Tuesday"),
        Session("8:00-11:00", "Wednesday"),
        Session("9:00-11:00", "Thursday"),
        Session("22:00-23:00", "Friday"),
        Session("4:00-7:00", "Saturday"),
        Session("8:00-9:00", "Sunday")};
    Session session2[] = {
        Session("8:00-11:00", "Monday"),
        Session("9:00-12:00", "Tuesday"),
        Session("8:00-11:00", "Wednesday"),
        Session("9:00-11:00", "Thursday"),
        Session("22:00-23:00", "Friday"),
        Session("4:00-7:00", "Saturday"),
        Session("8:00-9:00", "Sunday")};
    Session session3[] = {
        Session("7:00-11:00", "Monday"),
        Session("10:00-12:00", "Tuesday"),
        Session("8:00-11:00", "Wednesday"),
        Session("9:00-11:00", "Thursday"),
        Session("22:00-23:00", "Friday"),
        Session("4:00-7:00", "Saturday"),
        Session("8:00-9:00", "Sunday")};
    Session session4[] = {
        Session("10:00-11:00", "Monday"),
        Session("10:00-12:00", "Tuesday"),
        Session("8:00-11:00", "Wednesday"),
        Session("9:00-11:00", "Thursday"),
        Session("7:00-23:00", "Friday"),
        Session("4:00-7:00", "Saturday"),
        Session("8:00-9:00", "Sunday")};
    Session session5[] = {
        Session("10:00-11:00", "Monday"),
        Session("3:00-12:00", "Tuesday"),
        Session("8:00-11:00", "Wednesday"),
        Session("9:00-11:00", "Thursday"),
        Session("12:00-23:00", "Friday"),
        Session("4:00-7:00", "Saturday"),
        Session("8:00-9:00", "Sunday")};
    trainer[0].initSession(session1, 7);
    trainer[1].initSession(session2, 7);
    trainer[2].initSession(session3, 7);
    trainer[3].initSession(session4, 7);
    trainer[4].initSession(session5, 7);
    Package package[] = {
        Package("1", 30.00, "Monthly Package"),
        Package("2", 60.00, "3 Months Package"),
        Package("3", 90.00, "6 Month Package"),
        Package("4", 160.00, "1 Year Package")};
    Person *persons = person;
    Customer *customers = customer;
    Trainer *trainers = trainer;
    int count = 20;
    int customerCount = 15;
    int trainerCount = 5;
    int SystemChoice = -1;
    while (SystemChoice != 0)
    {
        cout << "Welcome to the Gym Management System" << endl
             << endl;
        cout << "1. Initialize System" << endl;
        cout << "2. Display All Person" << endl;
        cout << "3. Display All Customer" << endl;
        cout << "4. Display All Trainer" << endl;
        cout << "5. Display All Package" << endl;
        cout << "6. Query Person" << endl;
        cout << "7. Query Customer" << endl;
        cout << "8. Query Trainer" << endl;
        cout << "9. Assign Package" << endl;
        cout << "Enter your choice: " << endl;
        cout << "0 to exit" << endl;
        cin >> SystemChoice;
        if (SystemChoice == 1)
        {
            
            cout << "How many person you want to initialize?";
            cin >> count;
            persons = new Person[count];
            customers = new Customer[count];
            trainers = new Trainer[count];

            for (int i = 0; i < count; i++)
            {
                persons[i].promptSetPerson();
                int choice;
                cout << "Choose 1 If It was a Customer,Choose 2 if it was a Trainer: ";
                cin >> choice;
                if (choice == 1)
                {
                    cout << "Enter Height and Weight ";
                    int h = 0;
                    int w = 0;
                    cin >> h >> w;
                    customers[customerCount] = Customer(persons[i], customerCount + 1,w,h);
                    customerCount++;
                }
                else if (choice == 2)
                {
                    trainers[trainerCount] = Trainer(persons[i], trainerCount + 1);
                    trainers[trainerCount].set_session();
                    trainerCount++;
                }
            }
        }
        else if (SystemChoice == 2)
        {
            for (int i = 0; i < count; i++)
            {
                cout << "=========================================" << endl;
                cout << "\t Person " << i + 1 << "" << endl;
                persons[i].displayBasic();
            }
        }
        else if (SystemChoice == 3)
        {
            for (int i = 0; i < customerCount; i++)
            {

                cout << "=========================================" << endl;
                cout << "\t Customer " << i + 1 << "" << endl;
                customers[i].displayInfo();
            }
        }
        else if (SystemChoice == 4)
        {
            for (int i = 0; i < trainerCount; i++)
            {
                cout << "=========================================" << endl;
                cout << "\t Trainer " << i + 1 << "" << endl;
                trainers[i].displayInfo();
            }
        }
        else if (SystemChoice == 5)
        {
            cout << "=========================================" << endl;
            for (int i = 0; i < 4; i++)
            {
                cout << "\t Package " << i + 1 << "" << endl;
                package_display(package[i]);
            }
        }
        else if (SystemChoice == 6)
        {
            cout << "=========================================" << endl;
            cout << "Enter persons ID: ";
            int id;
            cin >> id;
            persons[id - 1].displayBasic();
        }
        else if (SystemChoice == 7)
        {
            cout << "=========================================" << endl;
            cout << "Enter Customer ID: ";
            int id;
            cin >> id;
            customers[id - 1].displayInfo();
        }
        else if (SystemChoice == 8)
        {
            cout << "=========================================" << endl;
            cout << "Enter Trainer ID: ";
            int id;
            cin >> id;
            trainers[id - 1].displayInfo();
        }
        else if (SystemChoice == 9)
        {
            cout << "=========================================" << endl;
            cout << "Enter Customer ID: ";
            int id;
            cin >> id;
            for (int i = 0; i < 4; i++)
            {
                cout << "=========================================" << endl;
                cout << "\t Package " << i + 1 << "" << endl;
                package_display(package[i]);
            }
            cout << "Enter Package ID: " << endl;
            int packageID;
            cin >> packageID;
            customers[id].assignPackage(package[packageID]);
        }
    }
}