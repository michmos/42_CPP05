
#include "../inc/Intern.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include <functional>
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern& toCopy) {
	(void) toCopy;
}
Intern& Intern::operator=(const Intern& toCopy) { 
	(void) toCopy;
	return *this; 
}
Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
	struct Form {
		std::string name;
		std::function<AForm*(const std::string&)> allocator;
	}; 

	Form forms[] = {
		"shrubbery creation", [](const std::string& target) {
			return(new ShrubberyCreationForm(target));
		},
		"robotomy request", [](const std::string& target) {
			return (new RobotomyRequestForm(target));
		},
		"presidential pardon", [](const std::string& target) {
			return (new PresidentialPardonForm(target));
		}
	};

	for (const Form& form : forms) {
		if (form.name == name) {
			std::cout << "Intern creates " << name << std::endl;
			return (form.allocator(target));
		}
	}
	std::cerr << "form name: \'" << name << "\' not recognized." << std::endl;
	return (nullptr);
}
