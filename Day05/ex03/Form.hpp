#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cmath>

class Bureaucrat;

class Form {
  public:
      class FormNotSigned: public std::exception {
      public:
        virtual const char* what() const throw();
    };

      class GradeTooLowException: public std::exception {
        public:
          GradeTooLowException(std::string& error);
          virtual const char* what() const throw();
          virtual ~GradeTooLowException();
        private:
        const char * error_;
    };

    bool getSign() const;
    const std::string getTarget() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(const Bureaucrat & bur);

    virtual void execute(Bureaucrat const & executor) const = 0;
    void CheckExecution(Bureaucrat const & executor) const;

    virtual ~Form();

  protected:
    Form();
    Form(const std::string target, const int grade_to_sign, const int grade_to_exec);
    Form(const Form & rhs);
    Form & operator=(const Form & rhs);

  private:
    const std::string target_;
    bool is_signed_;
    const int grade_to_sign_;
    const int grade_to_exec_;
    void CheckGradeForException();
};

std::ostream& operator<<(std::ostream& output, const Form& f);

#endif