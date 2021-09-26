#include <hello.h>
#include <iostream>

void DisplayMessage(std::string *message)
{
    std::cout << *message << '\n';
}

int main()
{
    std::string message = "Hello World";
    DisplayMessage(&message);
    return 0;
}