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

class CarRentalSystem
{
    public:
        CarRentalSystem();
        void run();

    private:
        std::unordered_map<std::string, User> users;
        std::unordered_map<std::string, Car> carInventory;
        std::string loggedInUserEmail;

        void loadUsers();
        void saveUsers() const;
        void printCarInventory() const;
        void loginUser();
        voiid createUserAccount();
        bool isValidEmail(const std::string& email) const;
        int getUserInputInteger(const std::string& prompt) const;
        void reserveCar();
        void chargeUser(const std::string& email, double amount) const;
        void displayWelcomeMessage() const;
        void displayGoodByeMessage() const;
};

User::User(const std::string& first, const std::string& last, const std::string& password, const std::string& number)
    : firstName(first), lastName(last), password(password) {}

Car::Car(const std::string& name, int quantity, double dailyFee) : name(name), quantity(quantity), dailyFee(dailyFee) {}

CarRental::CarRental() 
{
    loadUsers();
    carInventory = {
        { "Car A", Car("Car A", 2, 50.00) },
        { "Car B", Car("Car B", 2, 50.00) },
        { "Car C", Car("Car C", 2, 70.00) },
        { "Car D", Car("Car D", 2, 70.00) }
    };
}

void CarRentalSystem()::loadUsers() 
{
    ifstream infile("Users.txt");
    if (!infile.is_open())
    {
        cout << "No user data found. Starting with an empty user database." << std::endl;
        return;
    }

    std::string line = "";
    while (getline(infile, line))
    {
        std::istringstream iss(line);
        std::string email = "", firstName = "", lastName = "", password = "";
        if (getline(iss, email, ',') && getline(iss, firstName, ',') && getline(iss, lastName, ',') && getline(iss, password))
        {
            users.emplace(email, User(firstName, lastName, password));
        }
    }

    infile.close();
}

void CarRentalSystem::saveUsers()
{
    std::ofstream outfile("Users.txt");
    if (!outfile.is_open())
    {
        std::cout << "Failed to save user data." << std::endl;
    }

    for (const auto& user : users)
    {
        outfile << user.first << "," << user.second.toString() << std::endl;
    }

    outfile.close();
}
