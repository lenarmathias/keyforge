#include <iostream>
#include <string>
#include <limits>

#include <vector>
#include <random>
#include <algorithm>

int width_terminal{42};

std::vector<char> letters{};
std::vector<char> digits{};
std::vector<char> symbols{};

void AssignVectors() {
	// Alphabet (uppercase and lowercase)
	for (char c = 'a'; c <= 'z'; ++c) letters.push_back(c);
	for (char c = 'A'; c <= 'Z'; ++c) letters.push_back(c);

	// Numbers
	for (char c = '0'; c <= '9'; ++c) digits.push_back(c);

	// Symbols
	symbols = {
			'!', '@', '#', '$', '%', '^', '&', '*',
			'(', ')', '-', '_', '=', '+', '[', ']',
			'{', '}', ';', ':', ',', '.', '<', '>',
			'/', '?', '|', '~'
	};
}

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

char GetRandomChar(
	const std::vector<char>& characters,
	std::mt19937& rng) {
	std::uniform_int_distribution<int> dist(
		0,
		static_cast<int>(characters.size()) - 1
	);
	
	return characters[dist(rng)];
}

void FillPasswordString(
	int characters_number,
	const std::vector<char>& characters,
	std::string& generated_password,
	std::mt19937& rng) {
	for (int i = 0; i < characters_number; ++i) {
		generated_password += GetRandomChar(characters, rng);
	}
}

std::string GeneratePassword(
	int letters_number,
	int digits_number,
	int symbols_number) {
	std::string generated_password{};

	// Initialize random generator
	std::random_device rd;
	std::mt19937 rng { rd() };

	FillPasswordString(
		letters_number,
		letters,
		generated_password,
		rng
	);
	FillPasswordString(
		digits_number,
		digits,
		generated_password,
		rng
	);
	FillPasswordString(
		symbols_number,
		symbols,
		generated_password,
		rng
	);

	std::shuffle(generated_password.begin(), generated_password.end(), rng);

	return generated_password;
}

void PasswordSetup() {
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

	std::string generated_password{
		GeneratePassword(letters_number, digits_number, symbols_number)
	};
	std::cout << "\nPassword contains "
						<< letters_number << " letters, "
						<< digits_number << " digits and "
						<< symbols_number << " symbols:\n"
						<< generated_password << "\n";
}

int main() {
	AssignVectors();
	TerminalIntro(width_terminal);
	int menu_selection{};

	do {
		menu_selection = TerminalMenu(width_terminal);
		
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
	} while (menu_selection !=2);

	return 0;
}
