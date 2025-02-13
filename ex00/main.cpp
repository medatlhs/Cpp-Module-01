#include "./Zombie.hpp"

int main()
{
    Zombie *z = newZombie("programmer");
    z->announce();
    delete z;

    randomChump("3chiri");
    return (0);
}
