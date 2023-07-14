#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <regex>

class User
{
    public:
        User() = default;
        User(const std::string& first, const std::string& last, const std::string& password, const std::string& number);
        std::string getFirstName() const { return firstName; }
        std::string getLastName() const { return lastName; }
        std::string getEmailAddress() const { return emailAddress; }
        std::string getPassword() const { return password; }
        void setEmailAddress(const std::string& email) { emailAddress = email; }
        void setPassword(const std::string& password) { this->password = password; }
        std::string getAccountNumber() const { return AccountNumber; }
        
        std::string toString() const;
    
    private:
        std::string firstName;
        std::string lastName;
        std::string emailAddress;
        std::string password;
};

class Car
{
    public:
        Car() = default;
        Car(const std::string& name, int quantity, double dailyFee);
        std::string getName() const { return name; }
        int getQuantity() const { return quantity; }
        double getDailyFee() const { return dailyFee; }
        bool reserve();
        double calculateRentalCost(int days) const;
    
    private:
        std::string name;
        int quantity;
        double dailyFee;
};

User::User(const std::string& first, const std::string& last, const std::string& password, const std::string& number)
    : firstName(first), lastName(last), password(password) {}

Car::Car(const std::string& name, int quantity, double dailyFee) : name(name), quantity(quantity), dailyFee(dailyFee) {}
