
#pragma once

#include "AForm.hpp"

class  RobotomyRequestForm : public AForm {
private:
	std::string	target_;

	void	executeAction() const override;

public:
	RobotomyRequestForm(const std::string& target) noexcept;
	RobotomyRequestForm(const RobotomyRequestForm& toCopy) noexcept;
	RobotomyRequestForm& operator=(const RobotomyRequestForm& toAsgn) noexcept;
	~RobotomyRequestForm() noexcept;
};
