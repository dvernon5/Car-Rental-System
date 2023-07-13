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
    User(std::string first, std::string last, std::string password, std::string id);
    std::string getFirstName() { return firstName; }
    std::string getLastName() { return lastName; }
    std::string getPassword() { return password; }
    std::string getAccountNumber() { return AccountID; }
    void setEmailAddress(std::string email) { emailAddress = email; }
    void setPassword(std::string password) { this->password = password; }

    std::string toString();

    private:
        std::string firstName;
        std::string lastName;
        std::string password;
        std::string AccountID;
}

bool isValid(std::string& email);

int main(void)
{
    return 0;
}

User::User(std::string first, std::string last, std::string password, std::string id) 
{
    firstName = first;
    lastName = last;
    this->password = password;
    AccountNumber = number;
}

bool isValid(std::string& email)
{
    const std::regex pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return std::regex_match(email, pattern);
}

int checkAccountExistance(std::map<std::string, User> users, std::string email)
{
    if (users.find(email) != users.end())
    {
        // Email already exist
        return 1;
    }

    return -1;
}

void addUser(std::map<std::string, User>& users)
{
    std::string email;
    std::cout << "Enter your Email Address: ";
    std::cin  >> email;

    if (!isValid(email)
    {
        std::cout << "Invalid email address. Pleae enter a valid email." << std::endl;
        return;
    }

    int emailFound = checkAccountExistence(users, email);
    if (emailFound != -1)
    {
        std::cout << "Email address already exist." << std::endl;
        return;
    }

    std::string firstName;
    std::cout << "Enter your First Name: ";
    std::cin  >> firstName;

    std::string lastName;
    std::cout << "Enter your Last Name: ";
    std::cin  >> lastName;

    std::string password;
    std::cout << "Enter a password: ";
    std::cin  >> password;

    std::string accountID;
    std::cout << "Enter an accountID ";
    std::cin  >> accountID;
    
    users.insert(std::make_pair(email, User(firstName, lastName, password, AccountID)));   
}
