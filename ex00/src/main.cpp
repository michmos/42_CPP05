
#include "../inc/Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main(void) {
	// ------------ construction ------------
	{
		// valid bureaucrat
		try {
			Bureaucrat peter("peter", 12);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		// invalid bureaucrats (too high and too low)
		try {
			Bureaucrat invalid("name", 0);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			Bureaucrat invalid("name", 151);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	// ------------ getter ------------
	{
		try {
			Bureaucrat peter("peter", 12);
			std::cout << "name: " << peter.getName() << " " << "grade: " << peter.getGrade() << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	// ------------ inc / decr ------------
	{
		// incrementing valid bureaucrat
		try {
			Bureaucrat jon("jon", 2);
			jon.incrementGrade();
			jon.incrementGrade();
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cerr << e.what() << std::endl;
		}

		// decrementing valid bureaucrat
		try {
			Bureaucrat peer("peer", 149);
			peer.decrementGrade();
			peer.decrementGrade();
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	// ------------ << op ------------
	{
		try {
			Bureaucrat jon("jon", 2);
			std::cout << jon << std::endl;
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

}
