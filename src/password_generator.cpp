#include "password_generator.h"
#include <algorithm>

PasswordGenerator::PasswordGenerator()
	: rng(std::random_device{}()) {	// Initialize random generator
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

char PasswordGenerator::GetRandomChar(
	const std::vector<char>& characters) {
	std::uniform_int_distribution<int> dist(
		0,
		static_cast<int>(characters.size()) - 1
	);

	return characters[dist(rng)];
}

void PasswordGenerator::FillPasswordString(
	int characters_number,
	const std::vector<char>& characters,
	std::string& generated_password) {
	for (int i = 0; i < characters_number; ++i) {
		generated_password += GetRandomChar(characters);
	}
}

std::string PasswordGenerator::GeneratePassword(
	int letters_number,
	int digits_number,
	int symbols_number) {
	std::string generated_password{};

	FillPasswordString(
		letters_number,
		letters,
		generated_password
	);
	FillPasswordString(
		digits_number,
		digits,
		generated_password
	);
	FillPasswordString(
		symbols_number,
		symbols,
		generated_password
	);

	std::shuffle(generated_password.begin(), generated_password.end(), rng);

	return generated_password;
}

int PasswordGenerator::GetMaxPasswordLength() const {
	return max_password_length;
}
