#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {

  public:

    Contact ( void );
    Contact ( std::string first_name, std::string last_name,
              std::string nickname, std::string phone_number,
              std::string darkest_secret );

    std::string  GetFirstName( void ) const;
    std::string  GetLastName( void ) const;
    std::string  GetNickname( void ) const;
    std::string  GetPhoneNumber( void ) const;
    std::string  GetDarkestSecret( void ) const;

  private:

    std::string first_name_;
    std::string last_name_;
    std::string nickname_;
    std::string phone_number_;
    std::string darkest_secret_;
};

#endif