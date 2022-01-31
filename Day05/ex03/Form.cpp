#include "Form.hpp"

Form::Form(const std::string target, const int grade_to_sign, const int grade_to_exec)
: target_(target), is_signed_(false), grade_to_sign_(grade_to_sign), grade_to_exec_(grade_to_exec) {
}

Form::Form()
 : target_("no target"), is_signed_(false),
  grade_to_sign_(1), grade_to_exec_(1) {
}

Form::~Form() {
}

Form::Form(const Form & rhs)
 : target_(rhs.target_), grade_to_sign_(rhs.grade_to_sign_),
    grade_to_exec_(rhs.grade_to_exec_) {
    *this = rhs;
}

Form & Form::operator=(const Form & rhs) {
  is_signed_ = rhs.is_signed_;
  return *this;
}

const std::string Form::getTarget() const {
  return target_;
}

int Form::getGradeToSign() const {
  return grade_to_sign_;
}

int Form::getGradeToExecute() const {
  return grade_to_exec_;
}

bool Form::getSign() const {
  return is_signed_;
}


void Form::beSigned(const Bureaucrat & bur) {
if (bur.GetGrade() > grade_to_sign_) {
    std::string error = "Form \"" + target_
        + "\" couldn't be signed, bureaucrat grade is "
        + std::to_string(bur.GetGrade()) + " but requested grade is "
        + std::to_string(grade_to_sign_);
    throw GradeTooLowException(error);
  }
  else {
    is_signed_ = true;
  }
}

const char * Form::FormNotSigned::what() const throw() {
  return ("Form isn't signed");
}

std::ostream& operator<<(std::ostream& output, const Form& f) {
  output << "Form is named: \"" << f.getTarget()
            << "\" it could be signed by Bureaucrats with grade: "
            << f.getGradeToSign() << std::endl
            << "Now it ";
  if (f.getSign()) {
      output << "signed";
  }
  else {
    output << "isn't signed";
  }
  return output;
}

void Form::CheckExecution(Bureaucrat const & executor) const {
  if (!is_signed_) {
    throw FormNotSigned();
  }
  else if (executor.GetGrade() > grade_to_sign_) {
    std::string error = executor.GetName()
      + " couldn't execute form \"" + target_ + "\" , his grade is too low! Executor grade - "
      + std::to_string(executor.GetGrade())
      + " requested grade - " + std::to_string(grade_to_exec_);
    throw GradeTooLowException(error);
  }
}

Form::GradeTooLowException::GradeTooLowException(std::string& error) : error_(error.c_str()) {
}

const char * Form::GradeTooLowException::what() const throw() {
  return (error_);
}