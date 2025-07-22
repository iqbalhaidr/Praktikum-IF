#include "Pet.hpp"
#include <iostream>

// Constructor
Pet::Pet(const std::string& name, int age) : name(name), age(age), healthStatus("Healthy") {
}

// Destructor
Pet::~Pet() {
}

// Getters
std::string Pet::getName() const {
    return name;
}

int Pet::getAge() const {
    return age;
}

std::string Pet::getHealthStatus() const {
    return healthStatus;
}

std::string Pet::getId() const {
    return id;
}

// Setters
void Pet::setName(const std::string& name) {
    this->name = name;
}

void Pet::setAge(int age) {
    this->age = age;
}

void Pet::setHealthStatus(const std::string& status) {
    this->healthStatus = status;
}

void Pet::setId(const std::string& id) {
    this->id = id;
}

// Virtual methods with implementation
void Pet::eat() const {
    std::cout << name << " is eating." << std::endl;
}

void Pet::sleep() const {
    std::cout << name << " is sleeping peacefully." << std::endl;
}

void Pet::play() const {
    std::cout << name << " is playing." << std::endl;
}

// Display pet information
void Pet::displayInfo() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Species: " << getSpecies() << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Health Status: " << healthStatus << std::endl;
}