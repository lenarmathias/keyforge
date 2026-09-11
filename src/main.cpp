#include <iostream>
#include <string>
#include <limits>

int width_terminal{42};

void ClearInput() {
	std::cin.clear();
	// Discard the invalid input so the next read starts with a clean line
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

int GetNonNegativeNumber() {
	int input{};

	while (!(std::cin >> input) || input < 0) {
		ClearInput();

		std::cout << "\nPlease enter a non-negative number: ";
	}

	return input;
}

void GeneratePassword() {
	std::cout << "\nHow many letters?\n";
	int letters_number{ GetNonNegativeNumber() };

	std::cout << "\nHow many digits?\n";
	int digits_number{ GetNonNegativeNumber() };

	std::cout << "\nHow many symbols?\n";
	int symbols_number{ GetNonNegativeNumber() };

	if (letters_number == 0 &&
		digits_number == 0 &&
		symbols_number == 0) {
		std::cout << "\nPassword can't be generated with no options.\n";
		return;
	}

	std::cout << "\nPassword contains "
						<< letters_number << " letters, "
						<< digits_number << " digits and "
						<< symbols_number << " symbols:\n";
}

int main() {

	TerminalIntro(width_terminal);
	int menu_selection{};

	do {
		menu_selection = TerminalMenu(width_terminal);
		
		switch (menu_selection) {
		case 1:
			GeneratePassword();
			break;
		case 2:
			std::cout << "\nGoodbye\n";
			break;
		default:
			std::cout << "\nInvalid choice\n";
			break;
		}
	} while (menu_selection !=2);

	return 0;
}
