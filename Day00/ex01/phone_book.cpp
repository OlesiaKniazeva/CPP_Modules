#include "database.classes.hpp"

Database::Database( void ) {
  contacts_amount_ = 0;
  database_is_full_ = false;
  return;
}

Contact::Contact( void ) {
  return;
}

Contact::Contact( std::string first_name, std::string last_name,
                  std::string nickname, std::string phone_number,
                  std::string darkest_secret)
                  : first_name_(first_name), last_name_(last_name),
                  nickname_(nickname), phone_number_(phone_number),
                  darkest_secret_(darkest_secret)  {
}

std::string  Contact::GetFirstName( void ) const {
  return first_name_;
}

std::string  Contact::GetLastName( void ) const {
  return last_name_;
}

std::string  Contact::GetNickname( void ) const {
  return nickname_;
}

std::string  Contact::GetPhoneNumber( void ) const {
  return phone_number_;
}

std::string  Contact::GetDarkestSecret( void ) const {
  return darkest_secret_;
}

void  Database::UpdateInfoAboutDatabase ( void ) {
  if (!database_is_full_) {
    if (contacts_amount_ < 7)
      contacts_amount_++;
    else
      database_is_full_ = true;
  }
  else {
    if (contacts_amount_ > 0) {
      contacts_amount_--;
    }
    else {
      contacts_amount_ = 7;
    }
  }
}

void  Database::AddContactToDatabase( Contact new_contact) {
    database_[contacts_amount_] = new_contact;
    UpdateInfoAboutDatabase();
}

std::string  FormatString(std::string data) {
  std::string trimmed_data;
  if (data.size() > 10) {
    trimmed_data = data.substr(0, 9);
    trimmed_data+=".";
    return trimmed_data;
  }
  else {
    return data;
  }
}

std::ostream& operator<<(std::ostream& stream, const Contact contact) {
  std::cout << contact.GetFirstName() << std::endl;
  std::cout << contact.GetLastName() << std::endl;
  std::cout << contact.GetNickname() << std::endl;
  std::cout << contact.GetPhoneNumber() << std::endl;
  std::cout << contact.GetDarkestSecret();
  return (stream);
}

void  Database::ShowInfoOfDesiredContact( int index_of_desired_contact) {
  if ((!database_is_full_
          && (index_of_desired_contact >= 1
          && index_of_desired_contact <= contacts_amount_))
      || (database_is_full_
          && (index_of_desired_contact >= 1
          && index_of_desired_contact <= 8))) {
            std::cout << database_[index_of_desired_contact - 1] << std::endl;
    }
  else {
    std::cout << "Index not valid" << std::endl;
  }
}

bool  Database::ShowContactsFromDatabase( void ) const {
  int iterations;

  if (!database_is_full_)
    iterations = contacts_amount_;
  else
    iterations = 8;
  if (iterations == 0) {
    std::cout << "No contacts in PhoneBook" << std::endl;
    return false;
  }
  else {
    for (int i = 0; i < iterations; i++) {
             std::cout << std::setw(10) << i + 1 << "|"
      << std::setw(10) << FormatString(database_[i].GetFirstName()) << "|"
      << std::setw(10) << FormatString(database_[i].GetLastName())  << "|"
      << std::setw(10) << FormatString(database_[i].GetNickname())
      << std::endl;
    }
  }
  return true;
}