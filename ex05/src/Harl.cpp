#include "../Includes/Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
    std::cout << "DEBUG:\n";
    std::cout << "I love having extra bacon for my ";
    std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout << "INFO:\n";
    std::cout << "I cannot believe adding extra bacon costs more money. ";
    std::cout << "You didn’t putenough bacon in my burger! If you did, ";
    std::cout << "I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
    std::cout << "WARNING:\n";
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for ";
    std::cout << "years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
    std::cout << "ERROR:\n";
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level ) {
    void(Harl::*ptr[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[] = {"debug", "info", "warning", "error"};
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i]) {
            (this->*ptr[i])();
            return ;
        }
    }
    std::cout << "level not found\n" << std::endl;
}


// Pointers to member functions allow you to call a function dynamically, meaning without knowing in advance which function you’ll be calling.

// How It Works
// Instead of calling a function directly like object.function(), you store the function’s address in a pointer.
// At runtime, based on conditions, you call the function through the pointer.
// Why It's Useful?
// Flexibility: You can call different functions based on runtime conditions, without needing to know exactly which function in advance.
// Clean Code: It helps reduce conditionals (like if or switch), making your code more scalable and maintainable.