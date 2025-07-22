#include "Cat.hpp"
#include <iostream>

Cat::Cat(const std::string& name, int age, const std::string& color, bool indoor)
    : Pet(name, age), color(color), isIndoor(indoor) {
}

Cat::~Cat() {
}

std::string Cat::getColor() const {
    return color;
}

bool Cat::getIsIndoor() const {
    return isIndoor;
}

void Cat::setColor(const std::string& color) {
    this->color = color;
}

void Cat::setIsIndoor(bool indoor) {
    this->isIndoor = indoor;
}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}

std::string Cat::getSpecies() const {
    return "Cat";
}

void Cat::eat() const {
    std::cout << name << " nibbles on cat food delicately." << std::endl;
}

void Cat::sleep() const {
    std::cout << name << " curls up and sleeps for hours." << std::endl;
}

void Cat::purr() const {
    std::cout << name << " purrs contentedly." << std::endl;
}

void Cat::scratch() const {
    std::cout << name << " scratches the furniture." << std::endl;
}

void Cat::displayInfo() const {
    Pet::displayInfo();
    std::cout << "Color: " << color << std::endl;
    std::cout << "Indoor Cat: " << (isIndoor ? "Yes" : "No") << std::endl;
}