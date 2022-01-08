#ifndef DATABADE_CLASSSES_HPP
# define DATABADE_CLASSSES_HPP

#include <iostream>
#include <iomanip>
#include <stdlib.h>

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

class Database {

  public:
    Database( void );

    void  AddContactToDatabase( Contact new_contact );
    bool  ShowContactsFromDatabase( void ) const;
    void  ShowInfoOfDesiredContact( int index_of_desired_contact );

  private:

    Contact database_[8];
    int     contacts_amount_;
    bool    database_is_full_;
    void    UpdateInfoAboutDatabase ( void );
};

#endif