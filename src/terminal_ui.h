#pragma once

class TerminalUI {
private:
	static constexpr int width_terminal{ 42 };
	
	void ClearInput();

public:
	int GetNonNegativeNumber();
	void TerminalIntro();
	int TerminalMenu();
};
