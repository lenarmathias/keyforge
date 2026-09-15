#include "application.h"

#include <iostream>
#include <string>

void Application::PasswordSetup() {
	std::cout << "\nHow many letters?\n";
	int letters_number{ terminal_ui.GetNonNegativeNumber() };

	std::cout << "\nHow many digits?\n";
	int digits_number{ terminal_ui.GetNonNegativeNumber() };

	std::cout << "\nHow many symbols?\n";
	int symbols_number{ terminal_ui.GetNonNegativeNumber() };

	int password_length{ letters_number + digits_number + symbols_number };

	if (letters_number == 0 &&
		digits_number == 0 &&
		symbols_number == 0) {
		std::cout << "\nPassword can't be generated with no options.\n";
		return;
	}

	if (password_length > password_generator.GetMaxPasswordLength()) {
		std::cout << "\nPassword too long, can't exceed "
			<< password_generator.GetMaxPasswordLength()
			<< " characters.\n";
		return;
	}

	std::string generated_password{
		password_generator.GeneratePassword(
			letters_number, digits_number, symbols_number
		)
	};
	std::cout << "\nPassword contains "
		<< letters_number << " letters, "
		<< digits_number << " digits and "
		<< symbols_number << " symbols:\n"
		<< generated_password << "\n";
}

void Application::Run() {
	terminal_ui.TerminalIntro();
	int menu_selection{};

	do {
		menu_selection = terminal_ui.TerminalMenu();

		switch (menu_selection) {
		case 1:
			PasswordSetup();
			break;
		case 2:
			std::cout << "\nGoodbye\n";
			break;
		default:
			std::cout << "\nInvalid choice\n";
			break;
		}
	} while (menu_selection != 2);
}
