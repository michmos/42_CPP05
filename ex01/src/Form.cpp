
#include "../inc/Form.hpp"

// constructors, operators, destructors
Form::Form(const std::string& name, short signGrade, short execGrade) 
	: name_(name), signed_(false), signGrade_(signGrade), execGrade_(execGrade)
{
	if (signGrade < 1) {
		throw GradeTooHighException("Sign grade too high");
	} else if (execGrade < 1) {
		throw GradeTooHighException("Execution grade too high");
	} else if (signGrade > 150) {
		throw GradeTooLowException("Sign grade too low");
	} else if (execGrade > 150) {
		throw GradeTooLowException("Execution grade too low");
	}
}

Form::Form(const Form& toCopy) noexcept
	: name_(toCopy.name_), signGrade_(toCopy.signGrade_), execGrade_(toCopy.execGrade_)
{
	*this = toCopy;
}

Form& Form::operator=(const Form& toCopy) noexcept {
	if (this != &toCopy) {
		signed_ = toCopy.signed_;
	}
	return (*this);
}

Form::~Form() noexcept {
}

std::ostream& operator<<(std::ostream& os, const Form& rhs) noexcept {
	return (os << "Form name: " << rhs.getName()
		 		<< ", state: " << rhs.getSignState()
		 		<< ", sign grade: " << rhs.getSignGrade()
		 		<< ", exec grade: " << rhs.getExecGrade());
}



// getters
const std::string& Form::getName() const noexcept {
	return (name_);
}

bool	Form::getSignState() const noexcept {
	return (signed_);
}

short	Form::getSignGrade() const noexcept {
	return (signGrade_);
}

short	Form::getExecGrade() const noexcept {
		return (execGrade_);
}



// other functions
void	Form::beSigned(const Bureaucrat& bToSign) {
	if (bToSign.getGrade() <= signGrade_) {
		signed_ = true;
	} else {
		throw GradeTooLowException("Sign grade too low");
	}
}



// exceptions
Form::GradeTooHighException::GradeTooHighException(const std::string& message) noexcept
	: message_(message) {}

const char* Form::GradeTooHighException::what() const noexcept {
	return (message_.c_str());
}

Form::GradeTooLowException::GradeTooLowException(const std::string& message) noexcept
	: message_(message) {}

const char* Form::GradeTooLowException::what() const noexcept {
	return (message_.c_str());
}
