#pragma once
#include "AForm.hpp"

class Intern {
private:
public:
	Intern();
	Intern(const Intern& toCopy);
	Intern& operator=(const Intern& toCopy);
	~Intern();

	AForm* makeForm(const std::string& name, const std::string& target);
};
