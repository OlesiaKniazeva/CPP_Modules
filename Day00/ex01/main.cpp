#include "Database.hpp"

static void  ShowTextHowToUseProgramm(int type) {
  if (type == 1) {
    std::cout << "Input a command: " << std::endl;
  }
  else {
      std::cout << "Allowed commands: " << std::endl;
  }
  std::cout << "    ADD - to add new person in PhoneBook" << std::endl
            << "    SEARCH - to see persons in PhoneBook" << std::endl
            << "    EXIT - to stop programm" << std::endl;
}

int main( void ) {
  std::string command;
  Database data;

  ShowTextHowToUseProgramm(1);
  while (true) {
    std::cout << "Enter command: ";
    std::cin >> command;
    if (std::cin.peek() != '\n'
         || !(command == "SEARCH" || command == "EXIT" || command == "ADD")) {
      ShowTextHowToUseProgramm(2);
      std::cin.ignore(30000, '\n');
    }
    else if (command == "EXIT") {
      exit(0);
    }
    else if (command == "ADD") {
      std::string first_name;
      std::cout << std::setw(20) << std::right << "First Name: ";
      std::cin >> first_name;

      std::cout << std::setw(20) << std::right << "Last Name: ";
      std::string last_name;
      std::cin >> last_name;

      std::cout << std::setw(20) << std::right << "Nickname: ";
      std::string nickname;
      std::cin >> nickname;

      std::cout << std::setw(20) << std::right << "Phone Number: ";
      std::string phone_number;
      std::cin >> phone_number;

      std::cout << std::setw(20) << std::right << "Darkest Secret: ";
      std::string darkest_secret;
      std::cin >> darkest_secret;

      Contact new_contact(first_name, last_name, nickname, phone_number, darkest_secret);
      data.AddContactToDatabase(new_contact);
    }
    else { //if (command == "SEARCH")
      if (data.ShowContactsFromDatabase()) {
        int index_of_desired_contact;
        std::cout << "Enter index of contact you want to see: ";
        std::cin >> index_of_desired_contact;
        if (std::cin.fail()) {
          std::cout << "    Wrong input" << std::endl;
          std::cin.clear();
          std::cin.ignore(30000, '\n');
        }
        else {
          data.ShowInfoOfDesiredContact( index_of_desired_contact );
        }
      }
    }
  }
}