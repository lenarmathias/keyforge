#include <iostream>
#include <string>
#include <limits>

#include "password_generator.h"

constexpr int width_terminal{ 42 };

void ClearInput() {
	std::cin.clear();
	// Discard the invalid input so the next read starts with a clean line
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int GetNonNegativeNumber() {
	int input{};

	while (!(std::cin >> input) || input < 0) {
		ClearInput();

		std::cout << "\nPlease enter a non-negative number: ";
	}

	return input;
}

void TerminalIntro(int width_terminal) {
	int padding{ (width_terminal - 8) / 2 };

	std::cout << std::string(width_terminal, '=') << "\n\n";
	std::cout << std::string(padding, ' ') << "KeyForge\n\n";
	std::cout << std::string(width_terminal, '=') << "\n";
}

int TerminalMenu(int width_terminal) {
	std::cout << "\n" << std::string(width_terminal, '-') << "\n";
	std::cout << "1. Generate Password\n";
	std::cout << "2. Exit\n";
	std::cout << std::string(width_terminal, '-') << "\n";

	int input{};

	std::cin >> input;
	if (std::cin.fail()) {
		ClearInput();
		return 0;
	}

	return input;
}

void PasswordSetup(
	PasswordGenerator& password_generator) {
	std::cout << "\nHow many letters?\n";
	int letters_number{ GetNonNegativeNumber() };

	std::cout << "\nHow many digits?\n";
	int digits_number{ GetNonNegativeNumber() };

	std::cout << "\nHow many symbols?\n";
	int symbols_number{ GetNonNegativeNumber() };

	int password_length{ letters_number + digits_number + symbols_number };

	if (letters_number == 0 &&
		digits_number == 0 &&
		symbols_number == 0) {
		std::cout << "\nPassword can't be generated with no options.\n";
		return;
	}
	else if (
		password_length > password_generator.GetMaxPasswordLength()) {
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

int main() {
	PasswordGenerator password_generator;

	TerminalIntro(width_terminal);
	int menu_selection{};

	do {
		menu_selection = TerminalMenu(width_terminal);

		switch (menu_selection) {
		case 1:
			PasswordSetup(password_generator);
			break;
		case 2:
			std::cout << "\nGoodbye\n";
			break;
		default:
			std::cout << "\nInvalid choice\n";
			break;
		}
	} while (menu_selection != 2);

	return 0;
}
