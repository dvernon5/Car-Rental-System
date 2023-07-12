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
    User(std::string first, std::string last, std::string password, std::string number);
    std::string getFirstName() { return firstName; }
    std::string getLastName() { return lastName; }
    std::string getPassword() { return password; }
    std::string getAccountNumber() { return AccountNumber; }
    void setEmailAddress(std::string email) { emailAddress = email; }
    void setPassword(std::string password) { this->password = password; }

    std::string toString();

    private:
        std::string firstName;
        std::string lastName;
        std::string password;
        std::string AccountNumber;
}

int main(void)
{
    return 0;
}
