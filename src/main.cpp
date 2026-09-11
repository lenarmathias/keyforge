#include <iostream>
#include <string>
#include <limits>

int width_terminal{42};

void TerminalIntro(int number) {
	int padding{ (number - 8) / 2 };

	std::cout << std::string(number, '=') << "\n\n";
	std::cout << std::string(padding, ' ') << "KeyForge\n\n";
	std::cout << std::string(number, '=') << "\n\n";
}

int TerminalMenu(int number) {
	std::cout << "1. Generate Password\n";
	std::cout << "2. Exit\n";
	std::cout << std::string(number, '-') << "\n";
	
	int input{};
	
	std::cin >> input;
	if (std::cin.fail()) {
		std::cin.clear();
		// Discard the invalid input so the next read starts with a clean line
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return 0;
	}

	return input;
}

int main() {

	TerminalIntro(width_terminal);
	int menu_selection{};

	do {
		menu_selection = TerminalMenu(width_terminal);
		
		switch (menu_selection) {
		case 1:
			std::cout << "\nPlaceholder for password\n";
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
