#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
  public:
    Form(const std::string name, int grade);
    ~Form();
    Form(const Form & rhs);
    Form & operator=(const Form & rhs);
    bool getSign() const;

    const std::string getName() const;
    int getGrade() const;
    void beSigned(const Bureaucrat & bur);

     class GradeTooHighException: public std::exception
    {
      public:
        GradeTooHighException(std::string& error);
        virtual const char* what() const throw();
      private:
        const char *error_;
    };

    class GradeTooLowException: public std::exception {
      public:
        GradeTooLowException(std::string& error);
        virtual const char* what() const throw();
      private:
       const char * error_;
    };

  private:
    const std::string name_;
    bool is_signed_;
    const int grade_;
    void CheckGradeForException();
};

std::ostream& operator<<(std::ostream& output, const Form& f);

#endif