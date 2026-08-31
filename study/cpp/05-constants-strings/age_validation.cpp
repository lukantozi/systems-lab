#include <iostream>
#include <string>

int person_count = { 1 };

std::string get_name() {
    std::cout << "Enter the name of person #" << person_count << ": ";
    std::string name{};
    std::getline(std::cin >> std::ws, name);
    person_count++;
    return name;
}

int get_age(std::string name) {
    std::cout << "Enter the age of " << name << ": ";
    int age{};
    std::cin >> age;
    return age;
}

void compare_two_people(std::string name1, int age1, std::string name2, int age2) {
    if (age1 > age2)
        std::cout << name1 << " (age " << age1 << ") is older than " << name2 << " (age " << age2 << ")\n";
    else if (age2 > age1)
        std::cout << name2 << " (age " << age2 << ") is older than " << name1 << " (age " << age1 << ")\n";
    else
        std::cout << name1 << " (age " << age1 << ") is same age as " << name2 << " (age " << age2 << ")\n";
}

int main() {
    const std::string name1 { get_name() };
    const int age1 {get_age(name1) };

    const std::string name2 { get_name() };
    const int age2 {get_age(name2) };

    compare_two_people(name1, age1, name2, age2);
}
