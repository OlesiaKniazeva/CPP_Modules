#include "Bureaucrat.hpp"

void Bureaucrat::CheckGradeForException() {
  std::string err = "Grade of bureaucrat " + GetName() +
    " should be from 1 to 150, but your grade is " + std::to_string(grade_);
  if (grade_ > 150) {
    throw GradeTooLowException(err);
  }
  if (grade_ < 1) {
    throw GradeTooHighException(err);
  }
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name_(name), grade_(grade)
{
  CheckGradeForException();
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat::Bureaucrat(const Bureaucrat & rhs) : name_(rhs.name_) {
  *this = rhs;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & rhs) {
  grade_ = rhs.grade_;
  return *this;
}

const std::string Bureaucrat::GetName() const {
  return name_;
}

int Bureaucrat::GetGrade() const {
  return grade_;
}

void Bureaucrat::SetGrade(int grade) {
  CheckGradeForException();
  grade_ = grade;
}


void Bureaucrat::IncrementGrade() {
  --grade_;
  CheckGradeForException();
}

void Bureaucrat::DecrementGrade() {
  ++grade_;
  CheckGradeForException();
}

void Bureaucrat::signForm(Form& form) {
 if (grade_ > form.getGradeToSign()) {
    std::cout << "Bureaucrat " << name_ << " couldn't sign form \"" << form.getTarget()
              << "\" his grade is " << grade_ << " but requested grade is "
              << form.getGradeToSign() << std::endl;
  }
  else {
    std::cout << "Bureaucrat " << name_
              << " signed form \"" << form.getTarget() << "\"" << std::endl;
    form.beSigned(*this);
  }
}

void Bureaucrat::executeForm(Form const & form) {
  if (!form.getSign()) {
    std::cout << "Bureaucrat " << name_
              << " couldn't execute form \""
              << form.getTarget() << "\" , it isn't signed!" << std::endl;
  }
  else if (grade_ > form.getGradeToExecute()) {
    std::cout << "Bureaucrat " << name_ << " couldn't execute form \""
              << form.getTarget()  << "\" , his grade is "
              << grade_ << " requested grade is "
              << form.getGradeToExecute() << std::endl;
  }
  else {
    std::cout << "Bureaucrat " << name_
              << " executed form \"" << form.getTarget() << "\"" << std::endl;
    form.execute(*this);
  }
}


Bureaucrat::GradeTooHighException::GradeTooHighException(std::string& error) : error_(error.c_str()) {
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
  return (error_);
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string& error) : error_(error.c_str()) {
}


const char * Bureaucrat::GradeTooLowException::what() const throw() {
  return (error_);
}

std::ostream& operator<<(std::ostream& output, const Bureaucrat& b) {
  output << "Bureaucrat " << b.GetName() << " has grade " << b.GetGrade();
  return output;
}