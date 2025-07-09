
#include "../inc/Intern.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include <array>
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
	try {
		Intern in;
		Bureaucrat bu("peter", HIGHEST_GRADE);

		// valid form name
		printf(BOLD YELLOW "\n\nCreate valid forms, sign them and exec them\n" RESET);
		std::array<std::string, 3> formNames = {
			"shrubbery creation", "robotomy request", "presidential pardon"
		};

		for (const auto& formName : formNames) {
			AForm* ptr = in.makeForm(formName, "<targetName>");
			if (!ptr) {
				break;
			}
			std::cout << *ptr << std::endl;
			bu.signForm(*ptr);
			bu.executeForm(*ptr);
			delete(ptr);
			std::cout << std::endl;
		}

		// invalid form name
		printf(BOLD YELLOW "\n\nTry to create invalid form (wrong name)\n" RESET);
		in.makeForm("wrong name", "<targetName>");

	} catch (std::exception &e) {
		std::cerr << "Unexpected exception caught: " << e.what() << std::endl;
	}
}
