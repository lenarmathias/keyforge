#pragma once

#include <random>
#include <string>
#include <vector>

class PasswordGenerator {
private:
	std::mt19937 rng;	// Random generator

	static constexpr int max_password_length{ 128 };

	std::vector<char> letters{};
	std::vector<char> digits{};
	std::vector<char> symbols{};

	char GetRandomChar(const std::vector<char>& characters);
	void FillPasswordString(
		int characters_number,
		const std::vector<char>& characters,
		std::string& generated_password
	);

public:
	PasswordGenerator();

	std::string GeneratePassword(
		int letters_number,
		int digits_number,
		int symbols_number
	);

	int GetMaxPasswordLength() const;
};
