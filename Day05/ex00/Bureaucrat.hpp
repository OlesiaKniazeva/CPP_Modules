#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <sstream>
#include <stdexcept>

class Bureaucrat {
  public:
    Bureaucrat(const std::string name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat & rhs);
    Bureaucrat & operator=(const Bureaucrat & rhs);

    const std::string GetName() const;
    int GetGrade() const;
    void SetGrade(int grade);
    void IncrementGrade();
    void DecrementGrade();

    class GradeTooHighException: public std::exception
    {
      public:
        GradeTooHighException(std::string& error);
        virtual const char* what() const throw();
        virtual ~GradeTooHighException();
      private:
        const char *error_;
    };

    class GradeTooLowException: public std::exception {
      public:
        GradeTooLowException(std::string& error);
        virtual const char* what() const throw();
        virtual ~GradeTooLowException();

      private:
       const char * error_;
    };

  private:
    void CheckGradeForException();
    const std::string name_;
    int grade_;
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& b);

#endif