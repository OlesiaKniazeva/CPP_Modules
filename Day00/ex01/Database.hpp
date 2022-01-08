#ifndef DATABADE_CLASSSES_HPP
# define DATABADE_CLASSSES_HPP

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "Contact.hpp"

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