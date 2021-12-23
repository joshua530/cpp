#include <ctime>
#include <iostream>
#include <memory>
#include <stdexcept>

template <typename... Args>
std::string stringFormat(const std::string &format, Args... args)
{
    int sizeS = std::snprintf(nullptr, 0, format.c_str(), args...) +
                1; // extra space for '\0'
    if (sizeS <= 0)
        throw std::runtime_error("Error during formatting.");
    auto size = static_cast<size_t>(sizeS);
    auto buf = std::make_unique<char[]>(size);
    std::snprintf(buf.get(), size, format.c_str(), args...);
    return std::string(buf.get(),
                       buf.get() + size - 1); // we dont want the '\0' inside
}

int currentYear()
{
    std::time_t time = std::time(NULL);
    const std::tm *pTInfo = std::localtime(&time);
    int currentYear = 1900 + pTInfo->tm_year;
    return currentYear;
}

int main(int argc, char const *argv[])
{
    std::string firstName = "Joshua";
    std::string lastName = "Omari";
    int age = 23;
    // TODO
    std::cout << stringFormat("%d %s %s - %d", 3, firstName, lastName, age)
              << "\n"; // outputs gibberish
    std::cout << stringFormat("%d %s %s - %d", 3, "Joshua", "Omari", age)
              << "\n"; // outputs expected string
}
