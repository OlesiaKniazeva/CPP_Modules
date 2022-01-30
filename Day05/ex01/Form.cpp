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
  if (is_signed_) {
     std::cout << bur.GetName() << " couldn't sign \"" << name_
              << "\" because it's already signed" << std::endl;
  }
  else if (bur.GetGrade() < grade_) {
    is_signed_ = true;
    std::cout << bur.GetName() << " signed \"" << name_ << "\"" << std::endl;
  }
  else {
    std::cout << bur.GetName() << " couldn't sign \"" << name_
              << "\" because his grade is too low" << std::endl;
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
