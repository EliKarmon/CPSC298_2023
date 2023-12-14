#include <iostream>
#include <stdexcept>
#include <string>
unsigned long sigma(unsigned long n)
{
    unsigned long sum = 0;
    try
    {
        if(n < 1)
        {
            throw std::runtime_error("Precondition n >= 1 violated; invalid value of n: " + std::to_string(n) + " (LOC: " + __FILE__ + ", " + std::to_string(__LINE__) + ")");
        }
        for(int i = 1; i <= n; i++)
        {
            sum = sum + i;
        }
        if(sum != (n * (n+1)/2))
        {
            throw std::runtime_error("Postcondition sum = n*(n+1)/2 violated; invalid value for sum: " + std::to_string(n) + " (LOC: " + __FILE__ + ", " + std::to_string(__LINE__) + ")");
        }

    }
    catch(std::runtime_error & ex)
    {
        std::cout << "Exception: " << ex.what() << std::endl;
        std::cout << "Cannot compute sum; returning 0" << std::endl;
        sum = 0;
    }
    return sum;
}
int main()
{
    int sum = sigma(5);
    std::cout << "sigma(5) = " << sum << std::endl;
    sum = sigma(0);
    std::cout << "sigma(0) = " << sum << std::endl;

    return 0;
}