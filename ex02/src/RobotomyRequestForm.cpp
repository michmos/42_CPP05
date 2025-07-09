#include "../inc/RobotomyRequestForm.hpp"
#include <iostream>
#include <random>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) noexcept
	: AForm("RobotomyRequestForm", 72, 45),
	target_(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& toCopy) noexcept
	: RobotomyRequestForm(toCopy.target_)
{
	//call copy assignment operator to copy non const values (such as signed bool)
	*this = toCopy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& toAsgn) noexcept {
	if (this != &toAsgn) {
		//copy non const values (such as signed bool)
		AForm::operator=(toAsgn);
		target_ = toAsgn.target_;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() noexcept {
}

bool	randomTrueOrFalse() noexcept {
	// random device object to create random seed using hardware entropy
	std::random_device rd;
	// create random number generator based on seed
	std::mt19937 gen(rd());
	// define distribution
	std::uniform_int_distribution<> dis(0,1);
	// use generator and map numbers to desired range
	return (dis(gen));
}

void	RobotomyRequestForm::executeAction() const {
	std::cout << "This is drilling noise..." << std::endl;
	if (randomTrueOrFalse()) {
		std::cout << target_ << " has been robotomized successfully" << std::endl;
	} else {
		std::cout << "Robotomy failed" << std::endl;
	}
}
