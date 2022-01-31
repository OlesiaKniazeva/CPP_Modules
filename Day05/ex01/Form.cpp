#include "Form.hpp"

void Form::CheckGradeForException() {
  std::string err = "Grade should be from 1 to 150, but your grade is " + std::to_string(grade_);
  if (grade_ > 150) {
    throw GradeTooLowException(err);
  }
  if (grade_ < 1) {
    throw GradeTooHighException(err);
  }
}

Form::Form(const std::string name, int grade)
      : name_(name), is_signed_(false), grade_(grade) {
  CheckGradeForException();
}

Form::~Form() {
}

Form::Form(const Form & rhs)
    : name_(rhs.name_), grade_(rhs.grade_) {
    *this = rhs;
}

Form & Form::operator=(const Form & rhs) {
  is_signed_ = rhs.is_signed_;
  return *this;
}

const std::string Form::getName() const {
  return name_;
}

int Form::getGrade() const {
  return grade_;
}

bool Form::getSign() const {
  return is_signed_;
}


void Form::beSigned(const Bureaucrat & bur) {
  if (bur.GetGrade() > grade_) {
    std::string error = "Form couldn't be signed, bureaucrat grade is "
        + std::to_string(bur.GetGrade()) + " but requested grade is "
        + std::to_string(grade_);
    throw GradeTooLowException(error);
  }
  else {
    is_signed_ = true;
  }
}

Form::GradeTooHighException::GradeTooHighException(std::string& error) : error_(error.c_str()) {
}

const char * Form::GradeTooHighException::what() const throw() {
  return (error_);
}

Form::GradeTooLowException::GradeTooLowException(std::string& error) : error_(error.c_str()) {
}

const char * Form::GradeTooLowException::what() const throw() {
  return (error_);
}

std::ostream& operator<<(std::ostream& output, const Form& f) {
  output << "Form is named: \"" << f.getName()
            << "\" it could be signed by Bureaucrats with grade: "
            << f.getGrade() << std::endl
            << "Now it ";
  if (f.getSign()) {
      output << "signed";
  }
  else {
    output << "isn't signed";
  }
  return output;
}
