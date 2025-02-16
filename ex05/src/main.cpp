#include "../Includes/Harl.hpp"

int main()
{
    Harl init;

    init.complain("debug");
    init.complain("info");
    init.complain("warning");
    init.complain("error");

    return 0;
}
