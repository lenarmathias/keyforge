#pragma once

#include "terminal_ui.h"
#include "password_generator.h"

class Application {
private:
	TerminalUI terminal_ui;
	PasswordGenerator password_generator;

	void PasswordSetup();

public:
	void Run();
};
