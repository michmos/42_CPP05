
#pragma once

#include <exception>
#include <ostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat {
private:
	const std::string	name_;
	short				grade_;

public:
	Bureaucrat(const std::string& name, short grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();


	const std::string& getName() const noexcept;
	short getGrade() const noexcept;

	void	incrementGrade();
	void	decrementGrade();
	void	signForm(Form& fToSign);
	
	class GradeTooHighException : public std::exception {
	public:
		const char *what() const noexcept override;
	};

	class GradeTooLowException : public std::exception {
	public:
		const char *what() const noexcept override;
	};

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);
