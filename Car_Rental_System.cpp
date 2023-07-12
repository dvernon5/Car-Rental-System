#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

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
