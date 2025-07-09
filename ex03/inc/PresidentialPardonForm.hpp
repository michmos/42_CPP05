
#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	void	executeAction() const override;
public:
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& toCopy) noexcept;
	PresidentialPardonForm& operator=(const PresidentialPardonForm& toAsgn) noexcept;
	~PresidentialPardonForm() noexcept;
	
};
