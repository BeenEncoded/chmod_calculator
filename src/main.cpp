#include <iostream>

int main(int c __attribute__((unused)), char** v __attribute__((unused)))
{
    std::cout<< "Hello World!"<< std::endl;
    if(c > 0)
    {
        std::cout<< "C = "<< c<< std::endl;
    }
}