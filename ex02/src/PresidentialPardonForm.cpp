#include "../inc/PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5),
	target_(target)
{}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& toCopy) noexcept
	: PresidentialPardonForm(toCopy.target_)
{
	//call copy assignment operator to copy non const values (such as signed bool)
	*this = toCopy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& toAsgn) noexcept {
	if (this != &toAsgn) {
		//copy non const values (such as signed bool)
		AForm::operator=(toAsgn);
		target_ = toAsgn.target_;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() noexcept {}

void PresidentialPardonForm::executeAction() const {
	std::cout << target_ << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
