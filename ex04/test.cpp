#include <iostream>
#include <string>

int main() {
    std::string text = "Hello mohamed ait lahssen, welcome to C++ programming!";
    
    // Search for the word "world"
    size_t found = text.find("ait lahssen");
    
    if (found != std::string::npos) {
        std::cout << "'world' found at position: " << found << std::endl;
    } else {
        std::cout << "'world' not found" << std::endl;
    }
    
    return 0;
}
