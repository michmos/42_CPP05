
#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include <cstdio>
#include <iostream>

#define BOLD "\033[1m"
#define YELLOW	"\033[33;1m"
#define RESET "\033[0m"
#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150
#define MIDDLE_GRADE 75

int main(void) {
	// ------------ construction, operator ------------
	{
		// valid form
		try {
			printf(BOLD YELLOW "\n\nValid form creation test:\n" RESET);
			ShrubberyCreationForm sForm("ShrubTarget");
			std::cout << sForm << std::endl;
			PresidentialPardonForm pForm("pTarget");
			std::cout << pForm << std::endl;
			RobotomyRequestForm rForm("rTarget");
			std::cout << rForm << std::endl;

			printf(BOLD YELLOW "\n\nCopy constructor test:\n" RESET);
			ShrubberyCreationForm sForm2(sForm);
			std::cout << "og: " << sForm << std::endl;
			std::cout << "copy constructed: " << sForm2 << std::endl;

			printf(BOLD YELLOW "\n\nCopy assignment operator test:\n" RESET);
			PresidentialPardonForm pForm2("pTarget2");
			std::cout << "before: "<< pForm << std::endl;
			Bureaucrat b("Tom", HIGHEST_GRADE);
			b.signForm(pForm);
			pForm2 = pForm;
			std::cout << "after: "<< pForm << std::endl;
		} catch (...) {
			std::cerr << "Exception caught when attempting to create valid form" << std::endl;
		}

	// 	// invalid form - too high grade
	// 	printf(BOLD YELLOW "\n\nInvalid form creation test (too high singGrade):\n" RESET);
	// 	try {
	// 		Form form("invalidForm", 0, 100);
	// 	} catch (Form::GradeTooHighException& e) {
	// 		std::cerr << "Exception caught: " << e.what() << std::endl;
	// 	} catch (...) {
	// 		std::cerr << "General exception caught" << std::endl;
	// 	}
	//
	// 	printf(BOLD YELLOW "\n\nInvalid form creation test (too high execGrade):\n" RESET);
	// 	try {
	// 		Form form("invalidForm", 100, 0);
	// 	} catch (Form::GradeTooHighException& e) {
	// 		std::cerr << "Exception caught: " << e.what() << std::endl;
	// 	} catch (...) {
	// 		std::cerr << "General exception caught" << std::endl;
	// 	}
	//
	// 	// invalid form - too low grade
	// 	printf(BOLD YELLOW "\n\nInvalid form creation test (too low singGrade):\n" RESET);
	// 	try {
	// 		Form form("invalidForm", 151, 100);
	// 	} catch (Form::GradeTooLowException& e) {
	// 		std::cerr << "Exception caught: " << e.what() << std::endl;
	// 	} catch (...) {
	// 		std::cerr << "General exception caught" << std::endl;
	// 	}
	//
	// 	printf(BOLD YELLOW "\n\nInvalid form creation test (too low execGrade):\n" RESET);
	// 	try {
	// 		Form form("invalidForm", 100, 151);
	// 	} catch (Form::GradeTooLowException& e) {
	// 		std::cerr << "Exception caught: " << e.what() << std::endl;
	// 	} catch (...) {
	// 		std::cerr << "General exception caught" << std::endl;
	// 	}
	// }
	//
	// // ------------ getter ------------
	// {
	// 	// getters test
	// 	printf(BOLD YELLOW "\n\nGetters test:\n" RESET);
	// 	Form form("testForm", 50, 100);
	// 	std::cout << "Form name: " << form.getName() 
	// 			<< " state: " << form.getSignState()
	// 			<< " signGrade: " << form.getSignGrade()
	// 			<< " execGrade: " << form.getExecGrade()
	// 			<< std::endl;
	// }
	//
	// // ------------ Bureaucrat ------------
	// {
	// 	// Bureaucrat allowed to sign
	// 	printf(BOLD YELLOW "\n\nBureaucrat allowed to sign test:\n" RESET);
	// 	try {
	// 		Bureaucrat bureaucrat("Bureaucrat1", 50);
	// 		Form form("form1", 50, 100);
	// 		form.beSigned(bureaucrat);
	// 		Form form2("form2", 50, 100);
	// 		bureaucrat.signForm(form2);
	// 	} catch (...) {
	// 		std::cerr << "General exception caught when creating Bureaucrat or Form" << std::endl;
	// 	}
	//
	// 	// Bureaucrat not allowed to sign -- form.beSigned
	// 	printf(BOLD YELLOW "\n\nBureaucrat not allowed to sign test -- form.beSigned():\n" RESET);
	// 	try {
	// 		Bureaucrat bureaucrat("Bureaucrat1", 50);
	// 		Form form("form1", 49, 100);
	// 		form.beSigned(bureaucrat);
	// 	} catch (Form::GradeTooLowException& e) {
	// 		std::cerr << "Exception caught: " << e.what() << std::endl;
	// 	}
	// 	// Bureaucrat not allowed to sign -- Bureaucrat.signForm()
	// 	printf(BOLD YELLOW "\n\nBureaucrat not allowed to sign test -- Bureaucrat.signForm():\n" RESET);
	// 	try {
	// 		Bureaucrat bureaucrat("Bureaucrat1", 50);
	// 		Form form("form1", 49, 100);
	// 		bureaucrat.signForm(form);
	// 	} catch (...) {
	// 		std::cerr << "General exception caught when creating Bureaucrat or Form" << std::endl;
	// 	}
	//

		
	}

}
