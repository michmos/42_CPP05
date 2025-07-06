
#pragma once

#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string	name_;
	bool				signed_;
	const short			signGrade_;
	const short			execGrade_;

public:
	Form(const std::string& name, short signGrade, short execGrade);
	Form(const Form& toCopy) noexcept;
	Form& operator=(const Form& toCopy) noexcept;
	~Form() noexcept;

	// getters
	const std::string& getName() const noexcept;
	bool	getSignState() const noexcept;
	short	getSignGrade() const noexcept;
	short	getExecGrade() const noexcept;

	void 	beSigned(const Bureaucrat& bToSign);

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

std::ostream& operator<<(std::ostream& os, const Form& rhs) noexcept;
