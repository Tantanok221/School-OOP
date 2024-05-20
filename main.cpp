#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
class Person {
  private: 
  string name;
  int age;
  string address;
  string phone;
  string email;
  string birthday;
  public:
  string getName(){
    return this->name;
  }
  int getAge(){
    return this->age;
  }
  string getAddress(){
    return this->address;
  }
  string getPhone(){
    return this->phone;
  }
  string getEmail(){
    return this->email;
  }
  string getBirthday(){
    return this->birthday;
  }
  void setName(string name){
    this->name = name;
  }
  int setAge(int age){
    this->age = age;
  }
  void setAddress(string address){
    this->address = address;
  }
  void setPhone(string phone){
    this->phone = phone;
  }
  void setEmail(string email){
    this->email = email;
  }
  void setBirthday(string birthday){
    this->birthday = birthday;
  }

  Person(){
    this->name = "";
    this->age = 0;
    this->address = "";
    this->phone = "";
    this->email = "";
    this->birthday = "";
  }
  Person(string name, int age, string address, string phone, string emai,string birthdayl){
    this->name = name;
    this->age = age;
    this->address = address;
    this->phone = phone;
    this->email = email;
    this->birthday = birthday;
  }
  Person(string name, int age,string birthday){
    this->name = name;
    this->age = age;
    this->address = "";
    this->phone = "";
    this->email = "";
    this->birthday = birthday;
  }
  void display(){
    cout << "===============================" << endl;
    cout << "Name\t: " << this->name<< endl;
    cout << "Age\t: " << this->age<< endl;
    cout << "Address\t: " << this->address<< endl;
    cout << "Phone\t: " << this->phone<< endl;
    cout << "Email\t: " << this->email<< endl;
    cout << "===============================" << endl;
  }
  
};

class Manager: Person {
  int managerID;

};

class Customer : Person {
  int customerID;
  float weight;
  float height;


  public: 
  float calculateBMI(){
    float bmi = weight / (height * height);
    return bmi;
  };
  Customer(Person person,int customerID){
    this->setName(person.getName());
    this->setAge(person.getAge());
    this->setAddress(person.getAddress());
    this->setPhone(person.getPhone());
    this->setEmail(person.getEmail());
    this->customerID = customerID;
  }
};

class Trainer{

};

class Package{

};


int main(){
  Person p[] = {
    Person("John Doe", 30, "123 Main St", "123-456-7890","example@gmail.com"),
    Person("Jane Doe", 25, "456 Main St", "123-456-7891","example1@gmail.com"),
    Person("Jim Doe", 20, "789 Main St", "123-456-7892","example2@gmail.com")
};

  p[0].display();
    
    
  
}