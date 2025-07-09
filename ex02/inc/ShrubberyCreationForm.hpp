
#pragma once

#include "AForm.hpp"

class  ShrubberyCreationForm : public AForm {
private:
	std::string	target_;

	void	executeAction() const override;
public:
	ShrubberyCreationForm(const std::string& target) noexcept;
	ShrubberyCreationForm(const ShrubberyCreationForm& toCopy) noexcept;
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& toAsgn) noexcept;
	~ShrubberyCreationForm() noexcept;
	
};
