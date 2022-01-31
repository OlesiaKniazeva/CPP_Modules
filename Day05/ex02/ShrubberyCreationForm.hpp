#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{

	public:

		ShrubberyCreationForm(const std::string target);
		virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm & rhs);
    ShrubberyCreationForm & operator=(const ShrubberyCreationForm & rhs);

    virtual void execute(Bureaucrat const & executor) const;

    private:
      const static std::string tree_[3];
      int getRandomNumber(int min, int max) const ;


};

#endif