
#include "../inc/ShrubberyCreationForm.hpp"
#include <cstring>
#include <fstream>
#include <stdexcept>
#include <errno.h>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) noexcept
	: AForm("ShrubberyCreationForm", 145, 137, target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& toCopy) noexcept
	: ShrubberyCreationForm(toCopy.target_)
{
	//call copy assignment operator to copy non const values (such as signed bool)
	*this = toCopy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& toAsgn) noexcept {
	if (this != &toAsgn) {
		//copy non const values (such as signed bool and target)
		AForm::operator=(toAsgn);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() noexcept {
}

void	ShrubberyCreationForm::executeAction() const {
	std::ofstream	file("./" + target_ + "_shrubbery");
	if (file.fail()) {
		throw std::runtime_error("ShrubberyCreationForm execute(): failed to create file: " 
						   + std::string(strerror(errno)));
	}

	// write tree to file stream
	file <<
"		ccee88oo\n\
    C8O8O8Q8PoOb o8oo\n\
  dOB69QO8PdUOpugoO9bD\n\
 CgggbU8OU qOp qOdoUOdcb\n\
      6OuU  /p u gcoUodpP\n\
         //  /douUP\n\
           ////\n\
            |||/|\n\
            |||||\n\
            |||||\n\
      .....//||||.....";
}

