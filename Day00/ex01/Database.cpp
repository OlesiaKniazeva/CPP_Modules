#include "Database.hpp"

Database::Database( void ) {
  contacts_amount_ = 0;
  database_is_full_ = false;
  return;
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
  std::cout << std::setw(20) << "First name: " << contact.GetFirstName() << std::endl;
  std::cout << std::setw(20) << "Last name: " << contact.GetLastName() << std::endl;
  std::cout << std::setw(20) << "Nickname: " << contact.GetNickname() << std::endl;
  std::cout << std::setw(20) << "Phone number: " << contact.GetPhoneNumber() << std::endl;
  std::cout << std::setw(20) << "Secret word: " << contact.GetDarkestSecret();
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
    std::cout << "    Index not valid" << std::endl;
  }
}

bool  Database::ShowContactsFromDatabase( void ) const {
  int iterations;

  if (!database_is_full_)
    iterations = contacts_amount_;
  else
    iterations = 8;
  if (iterations == 0) {
    std::cout  <<"    No contacts in PhoneBook" << std::endl;
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