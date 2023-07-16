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

User::toString()
{
    std::stringstream ss;
    ss << firstName << "," << lastName << "," << password;
    return ss;
}

Car::Car(const std::string& name, int quantity, double dailyFee) : name(name), quantity(quantity), dailyFee(dailyFee) {}

bool Car::reserve()
{
    if (quantity > 0)
    {
        --quantity;
        return true;
    }
    
    return false;
}

double Car::calculateRentalCost(int days) const;
{
    return dailyFee * days;
}

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

void CarRentalSystem::loadUsers() 
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

void CarRentalSystem::saveUsers() const
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

void CarRentalSystem::printCarInventory() const
{
    for (const auto& car : carInventory)
    {
        std::cout << car.second.getName() << "(Quantity: " << car.second.getQuantity() << ")" << std::endl;
    }
}

void CarRentalSystem::loginUser()
{
    std::string email;
    std::cout << "Enter your email: ";
    getline(std::cin, email);

    if (!isValidEmail(email))
    {
        std::cout << "Invalid email address. Please enter a valid email." << std::endl;
        return;
    }

    auto itr = users.find(email);

    if (itr != users.end())
    {
        std::string password;
        std::cout << "Enter your password: ";
        getline(std::cin, password);
        
        if (itr->second.getPassword() == password)
        {
            loggedInUserEmail = email;
            std::cout << "Login successful. Welcome, " << itr->second.getFirstName() << " " << itr->second.LastName << "!" << std::endl;
        }
        else
        {
            std::cout << "Incorrect password." << std::endl;
        }
    }
    else
    {
        std::cout << "Email is not found. Do you want to create an account? (y/n): ";
        std::string response;
        getline(std::cin, response);

        if (response == "y" || response == "Y")
        {
            createUserAccount();
        }
    }
}

void createUserAccount()
{
    std::string email;
    std::cout << "Enter your email: ";
    getline(std::cin, email);

    if (!isValidEmail(email))
    {
        std::cout << "Invalid email address. Please enter an valid email." << std::endl;
        return;
    }

    auto itr = users.find(email);
    if (itr != users.end())
    {
        std::cout << "Email already exists." << std::endl;
        return;
    }

    std::string firstName;
    std::cout << "Enter your first name: ";
    getline(std::cin, firstName);

    std::string lastName;
    std::cout << "Enter your last name: ";
    getline(std::cin, lastName);

    std::string password;
    std::cout << "Enter a password: ";
    getline(std::cin, password);

    users.emplace(email, User(firstName, lastName, password));

    std::cout << "Your account has been successfully added." << std::endl;
    std::cout << "Welcome " << firstName << " " << lastName << std::endl;

    saveUsers();
}

bool CarRentalSystem::isValidEmail(const std::string& email) const
{
    const std::regex pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return std::regex_match(email, pattern);
}

int CarRentalSystem::getUserInputInteger(const std::string& prompt) const
{
    int value = 0;

    while (true)
    {
        std::cout << prompt;
        if (std::cin >> value)
        {
            std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        else
        {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear();
            std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return value;
}

void CarRentalSystem::reserveCar()
{
    printCarInventory();
    
    std::string carName = "";
    std::cout << "\nEnter the name of the car you want to reserve (or type 'q' to quit): ";
    getline(std::cin, carName);

    if (carName == 'q' || carName == 'Q') { return; }

    auto itr = carInventory.find(carName);
    if (itr != carInventory.end())
    {
        Car& selectedCar = itr->second();
        if (selectedCar.reserve())
        {
            int rentalDays = getUserInputInteger("Enter how many days you want to rent?");
            double rentalCost = selectedCar.calculateRentalDays();

            std::cout << "Total Rental Cost $" << std::fixed << std::setprecision(2) << rentalCost << std::endl;

            std::string confirmation = "";
            while (true)
            {
                std::cout << "Confirm your order (y/n): ";
                std::getline(std::cin, confirmation);

                if (confirmation == "y" || confirmaion == "Y")
                {
                    chargeUser(loggedInUserEmail, rentalCost);
                    std::cout << "Car reserved successfully. Enjoy your ride!" << std::endl;
                    break;
                }
                else if (confirmation == "n" || confirmation == "N")
                {
                    std::cout << "Order canceled." << std::endl;
                    selectedCar.reserve();  // Cancel the reservation and make the car available again
                    break;
                }
                else 
                {
                    std::cout << "Invalid input. Please enter 'y' or 'n'." << std::endl;
                }

            }
        }
        else 
        {
            std::cout << "Invalid car selection or no cars available. Please try again." << std::endl;
        }
    }
    else 
    {
        std::cout << "Car not found. Please enter a valid car name." << std::endl;
    }
}
