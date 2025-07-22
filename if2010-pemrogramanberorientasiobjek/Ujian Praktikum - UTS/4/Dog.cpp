#include "Dog.hpp"
#include <iostream>

Dog::Dog(const std::string& name, int age, const std::string& breed, bool trained)
    : Pet(name, age), breed(breed), trainedStatus(trained) {
}

Dog::~Dog() {
}

std::string Dog::getBreed() const {
    return breed;
}

bool Dog::isTrained() const {
    return trainedStatus;
}

void Dog::setBreed(const std::string& breed) {
    this->breed = breed;
}

void Dog::setTrainedStatus(bool status) {
    this->trainedStatus = status;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

std::string Dog::getSpecies() const {
    return "Dog";
}

void Dog::eat() const {
    std::cout << name << " munches on dog food." << std::endl;
}

void Dog::play() const {
    std::cout << name << " plays fetch and runs around excitedly!" << std::endl;
}

void Dog::train() {
    std::cout << name << " is being trained..." << std::endl;
    trainedStatus = true;
    std::cout << name << " is now trained!" << std::endl;
}

void Dog::fetch() const {
    if (trainedStatus) {
        std::cout << name << " fetches the ball and brings it back!" << std::endl;
    } else {
        std::cout << name << " looks confused and doesn't fetch the ball." << std::endl;
    }
}

void Dog::displayInfo() const {
    Pet::displayInfo();
    std::cout << "Breed: " << breed << std::endl;
    std::cout << "Trained: " << (trainedStatus ? "Yes" : "No") << std::endl;
}