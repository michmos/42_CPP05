
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
		std::cout << "before: "<< pForm2 << std::endl;
		Bureaucrat b("Tom", HIGHEST_GRADE);
		b.signForm(pForm);
		pForm2 = pForm;
		std::cout << "after: "<< pForm << std::endl;

		printf(BOLD YELLOW "\n\nExecute action: ShrubberyCreationForm\n" RESET);
		b.signForm(sForm);
		sForm.execute(b);

		printf(BOLD YELLOW "\n\nExecute action: PresidentialPardonForm\n" RESET);
		b.signForm(pForm);
		pForm.execute(b);

		printf(BOLD YELLOW "\n\nExecute action: RobotomyRequestForm\n" RESET);
		b.signForm(rForm);
		rForm.execute(b);
		rForm.execute(b);
		rForm.execute(b);
		rForm.execute(b);

		printf(BOLD YELLOW "\n\nExecution through bureaucrat object\n" RESET);
		b.executeForm(sForm);
		b.executeForm(rForm);
		b.executeForm(pForm);
		
	} catch (std::exception &e) {
		std::cerr << "Unexpected exception caught: " << e.what() << std::endl;
	}

	// Bureaucrat not allowed to execute -- form.beSigned
	printf(BOLD YELLOW "\n\nBureaucrat not allowed to execute test - form not signed:\n" RESET);
	Bureaucrat bureaucrat("Bureaucrat1", HIGHEST_GRADE);
	ShrubberyCreationForm sForm("target");
	bureaucrat.executeForm(sForm);

	// Bureaucrat not allowed to execute -- insufficient grade
	printf(BOLD YELLOW "\n\nBureaucrat not allowed to exec - insufficient grade\n" RESET);
	Bureaucrat b1("bad b", LOWEST_GRADE);
	Bureaucrat b2("good b", HIGHEST_GRADE);
	b2.signForm(sForm);
	b1.executeForm(sForm);
}
