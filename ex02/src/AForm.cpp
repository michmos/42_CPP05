
#include "../inc/AForm.hpp"

// constructors, operators, destructors
AForm::AForm(const std::string& name, short signGrade, short execGrade) 
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

AForm::AForm(const AForm& toCopy) noexcept
	: name_(toCopy.name_), signGrade_(toCopy.signGrade_), execGrade_(toCopy.execGrade_)
{
	*this = toCopy;
}

AForm& AForm::operator=(const AForm& toCopy) noexcept {
	if (this != &toCopy) {
		signed_ = toCopy.signed_;
	}
	return (*this);
}

AForm::~AForm() noexcept {
}

std::ostream& operator<<(std::ostream& os, const AForm& rhs) noexcept {
	return (os << "Form name: " << rhs.getName()
		 		<< ", state: " << rhs.getSignState()
		 		<< ", sign grade: " << rhs.getSignGrade()
		 		<< ", exec grade: " << rhs.getExecGrade());
}



// getters
const std::string& AForm::getName() const noexcept {
	return (name_);
}

bool	AForm::getSignState() const noexcept {
	return (signed_);
}

short	AForm::getSignGrade() const noexcept {
	return (signGrade_);
}

short	AForm::getExecGrade() const noexcept {
		return (execGrade_);
}



// other functions
void	AForm::beSigned(const Bureaucrat& bToSign) {
	if (bToSign.getGrade() <= signGrade_) {
		signed_ = true;
	} else {
		throw GradeTooLowException("Sign grade too low");
	}
}



// exceptions
AForm::GradeTooHighException::GradeTooHighException(const std::string& message) noexcept
	: message_(message) {}

const char* AForm::GradeTooHighException::what() const noexcept {
	return (message_.c_str());
}

AForm::GradeTooLowException::GradeTooLowException(const std::string& message) noexcept
	: message_(message) {}

const char* AForm::GradeTooLowException::what() const noexcept {
	return (message_.c_str());
}
