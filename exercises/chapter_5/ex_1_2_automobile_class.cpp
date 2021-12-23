#include <ctime>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

using std::string;

class Automobile {
public:
    Automobile();
    Automobile(string manufacturer, string model, int modelYear);

    string manufacturer();
    string modelName();
    int modelYear();

    void setManufacturer(string manufacturer);
    void setModelName(string name);
    void setModelYear(int year);

    string description();
    int age();

private:
    string _manufacturer;
    string _modelName;
    int _modelYear;

    int currentYear();
    template <typename... Args>
    std::string stringFormat(const std::string &format, Args... args);
};

Automobile::Automobile()
{
    setManufacturer("");
    setModelName("");
    setModelYear(-1);
}

Automobile::Automobile(string manufacturer, string model, int modelYear)
{
    setManufacturer(manufacturer);
    setModelName(model);
    setModelYear(modelYear);
}

string Automobile::manufacturer()
{
    return _manufacturer;
}

string Automobile::modelName()
{
    return _modelName;
}

int Automobile::modelYear()
{
    return _modelYear;
}

void Automobile::setManufacturer(string manufacturer)
{
    _manufacturer = manufacturer;
}

void Automobile::setModelName(string name)
{
    _modelName = name;
}

void Automobile::setModelYear(int year)
{
    if (year >= 1950 && year <= currentYear())
        _modelYear = year;
    else
        _modelYear = -1;
}

int Automobile::currentYear()
{
    std::time_t time = std::time(NULL);
    const std::tm *pTInfo = std::localtime(&time);
    int currentYear = 1900 + pTInfo->tm_year;
    return currentYear;
}

string Automobile::description()
{
    // return stringFormat("%d %s %s", _modelYear, _manufacturer,
    //                     _modelName); //TODO produces gibberish?
    return stringFormat("%d %s %s", _modelYear, _manufacturer.c_str(),
                        _modelName.c_str());
}

template <typename... Args>
std::string Automobile::stringFormat(const std::string &format, Args... args)
{
    int size_s = std::snprintf(nullptr, 0, format.c_str(),
                               args...) +
                 1; // extra space for \0
    if (size_s <= 0)
        throw std::runtime_error("Error during formatting");

    // size_t size = static_cast<size_t>(size_s);
    auto size = static_cast<size_t>(size_s);
    // std::unique_ptr<char[]> buf = std::make_unique<char[]>(size);
    auto buf = std::make_unique<char[]>(size);
    std::snprintf(buf.get(), size, format.c_str(), args...);
    return std::string(buf.get(), buf.get() + size - 1); // remove \0
}

int Automobile::age()
{
    return currentYear() - _modelYear;
}
