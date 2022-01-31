#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
  : Form(target, 145, 137) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & rhs) {
  *this = rhs;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & rhs) {
  Form::operator=(rhs);
  return *this;
}

const std::string ShrubberyCreationForm::tree_[3] = {
"                &&& &&  & &&                 \n"
"              && &\\/&\\|& ()|/ @, &&          \n"
"              &\\/(/&/&||/& /_/)_&/_&         \n"
"          &() &\\/&|()|/&\\/ '%\" & ()         \n"
"          &_\\_&&_\\ |& |&&/&__%_/_& &&        \n"
"        &&   && & &| &| /& & % ()& /&& .     \n"
"        ()&_---()&\\&\\|&&-&&--%---()~         \n"
"            &&     \\|||                      \n"
"                    |||                      \n"
"                    |||                      \n"
"                    |||                      \n"
"              , -=-~  .-^- _                 \n"

,

"                ccee88oo                    \n"
"              C8O8O8Q8PoOb o8oo             \n"
"            dOB69QO8PdUOpugoO9bD            \n"
"            CgggbU8OU qOp qOdoUOdcb         \n"
"                6OuU  /p u gcoUodpP         \n"
"                  \\\\//  /douUP             \n"
"                    \\\\////                 \n"
"                    |||/\\                   \n"
"                    |||\\/                   \n"
"                    |||||                   \n"
"              .....//||||\\....              \n"
,

"                      ,@@@@@@@,                 \n"
"          ,,,.   ,@@@@@@/@@,  .oo8888o.         \n"
"        ,&%'%&%&&%,@@@@@/@@@@@@,8888\\88/8o       \n"
"      ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'       \n"
"      %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'       \n"
"      %&&%/ %&%'%&&@@\\ V /@@' `888 `/88'        \n"
"      `&%\\ ` /%&'    |.|        \\ '|8'          \n"
"          |o|        | |         | |            \n"
"          |.|        | |         | |            \n"
"        \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_   \n"

       };

int ShrubberyCreationForm::getRandomNumber(int min, int max) const {
  max++;
  return abs(rand()%(max-min))+min;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {

    Form::CheckExecution(executor);

    srand(static_cast<unsigned int>(time(0)));
    int num = getRandomNumber(1, 3);
    std::ofstream file_for_tree(getTarget() + "_shrubbery");
    if (!file_for_tree) {
      throw std::runtime_error("File couldn't be created");
    }
    std::cout << "    File with ASCII tree was created!" << std::endl;
    if (num == 1) {
      file_for_tree << tree_[0] << std::endl;
    }
    else if (num == 2) {
      file_for_tree << tree_[1] << std::endl;
    }
    else {
      file_for_tree << tree_[2] << std::endl;
    }
    file_for_tree.close();
}