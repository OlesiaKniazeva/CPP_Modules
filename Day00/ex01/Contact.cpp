#include "Contact.hpp"

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