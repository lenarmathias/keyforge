#include "terminal_ui.h"

#include <iostream>
#include <limits>
#include <string>

void TerminalUI::ClearInput() {
	std::cin.clear();
	// Discard the invalid input so the next read starts with a clean line
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int TerminalUI::GetNonNegativeNumber() {
	int input{};

	while (!(std::cin >> input) || input < 0) {
		ClearInput();

		std::cout << "\nPlease enter a non-negative number: ";
	}

	return input;
}

void TerminalUI::TerminalIntro() {
	int padding{ (width_terminal - 8) / 2 };

	std::cout << std::string(width_terminal, '=') << "\n\n";
	std::cout << std::string(padding, ' ') << "KeyForge\n\n";
	std::cout << std::string(width_terminal, '=') << "\n";
}

int TerminalUI::TerminalMenu() {
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
