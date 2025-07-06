
#pragma once

#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string	name_;
	bool				signed_;
	const short			signGrade_;
	const short			execGrade_;

public:
	AForm(const std::string& name, short signGrade, short execGrade);
	AForm(const AForm& toCopy) noexcept;
	AForm& operator=(const AForm& toCopy) noexcept;
	virtual ~AForm() noexcept;

	// getters
	const std::string& getName() const noexcept;
	bool	getSignState() const noexcept;
	short	getSignGrade() const noexcept;
	short	getExecGrade() const noexcept;

	void 	beSigned(const Bureaucrat& bToSign);
	// pure virtual function to be implemented by derived classes
	virtual void	execute(const Bureaucrat& executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		GradeTooHighException(const std::string& messsage) noexcept;
		const char* what() const noexcept override;
	private:
		std::string message_;
	};
 	class GradeTooLowException : public std::exception {
	public:
		GradeTooLowException(const std::string& messsage) noexcept;
		const char* what() const noexcept override;
	private:
		std::string message_;
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& rhs) noexcept;
