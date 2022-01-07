#include "database.classes.hpp"

void  ShowTextHowToUseProgramm(int type) {
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
  while (std::cout << "Enter command: " && std::cin >> command) {

    if (command == "EXIT") {
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
    else if (command == "SEARCH") {
      if (data.ShowContactsFromDatabase()) {
      int index_of_desired_contact;
      std::cout << "Enter index of data you want to see: ";
      std::cin >> index_of_desired_contact;
      data.ShowInfoOfDesiredContact( index_of_desired_contact );
      }
    }
    else {
      ShowTextHowToUseProgramm(2);
    }
  }
}