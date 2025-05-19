
#include "../inc/Bureaucrat.hpp"
#include <iostream>
#include <ostream>

Bureaucrat::Bureaucrat(const std::string& name, short grade) : name_(name), grade_(grade) {
	#ifdef DEBUG
	std::cerr << "Bureaucrat constructor called: " << name << " " << grade << std::endl;
	#endif
	if (grade < 1) {
		throw GradeTooHighException();
	}
	if (grade > 150) {
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& toCopy) : name_(toCopy.name_) {
	#ifdef DEBUG
	std::cerr << "Bureaucrat copy constructor called" << std::endl;
	#endif
	*this = toCopy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& toCopy) {
	#ifdef DEBUG
	std::cerr << "Bureaucrat copy assignment operator called" << std::endl;
	#endif
	if (this != &toCopy) {
		grade_ = toCopy.grade_;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const noexcept {
	return (name_);
}

short Bureaucrat::getGrade() const noexcept {
	return(grade_);
}

void	Bureaucrat::incrementGrade() {
	#ifdef DEBUG
	std::cerr << name_ << " trying to increment grade. Current grade: " << grade_ << std::endl;
	#endif
	if (grade_ <= 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	grade_--;
	#ifdef DEBUG
	std::cerr << name_ << " incremented grade. New grade: " << grade_ << std::endl;
	#endif
}

void	Bureaucrat::decrementGrade() {
	#ifdef DEBUG
	std::cerr << name_ << " trying to decrement grade. Current grade: " << grade_ << std::endl;
	#endif
	if (grade_ >= 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	grade_++;
	#ifdef DEBUG
	std::cerr << name_ << " decremented grade. New grade: " << grade_ << std::endl;
	#endif
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs) {
	os << rhs.getName() << ", bureaucrat grade " << std::to_string(rhs.getGrade());
	return (os);
}

// ---------------------- Exceptions ----------------------
const char *Bureaucrat::GradeTooHighException::what() const noexcept {
	return("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept {
	return("Grade is too low");
}
