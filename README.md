# Car Rental System

The Car Rental System is a C++ application that allows users to reserve cars for rent. It provides a user-friendly interface for managing user accounts, car inventory, and rental reservations. 

## Features

- User Registration and Login: Users can create an account and log in to the system. Existing users can log in with their email address and password.
- Car Inventory Management: The system maintains a list of available cars for rent. Each car has a name, quantity, and daily rental fee.
- Car Reservation: Users can select a car from the inventory, specify the number of rental days, and make a reservation.
- Rental Cost Calculation: The system calculates the rental cost based on the number of rental days and the daily fee for the selected car.
- Account Persistence: User account information is stored in a text file (`Users.txt`) for persistence across application runs.
- Error Handling and Input Validation: The system includes error handling and input validation to ensure reliable and correct operation.
- Simple and Intuitive User Interface: The application provides clear prompts and messages for smooth user interaction.

## Getting Started

To run the Car Rental System, follow these steps:

1. Clone the repository to your local machine.
2. Open the project in your C++ IDE or editor.
3. Build and compile the code.
4. Run the executable.

## Usage

1. Upon launching the application, you will be presented with a menu that offers different options, such as login, account creation, and car reservation.
2. If you are a new user, select the option to create an account and provide the required information.
3. If you are an existing user, select the login option and enter your email address and password.
4. Once logged in, you can choose the option to reserve a car.
5. The system will display the available cars with their details, including the quantity and daily rental fee.
6. Select a car by entering its name, specify the number of rental days, and confirm the reservation.
7. The system will calculate the rental cost and display it. Confirm the reservation to complete the process.
8. The system will charge the user and display a success message.
9. To exit the application, choose the appropriate option from the main menu.
