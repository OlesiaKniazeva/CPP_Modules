#include "Bureaucrat.hpp"

void Bureaucrat::CheckGradeForException() {
  std::string err = "Grade should be from 1 to 150, but your grade is " + std::to_string(grade_);
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