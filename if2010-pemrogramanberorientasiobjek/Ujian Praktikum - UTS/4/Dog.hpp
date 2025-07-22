#ifndef DOG_HPP
#define DOG_HPP

#include "Pet.hpp"

class Dog : public Pet {
private:
    std::string breed;
    bool trainedStatus;
    
public:
    // Constructor
    Dog(const std::string& name, int age, const std::string& breed, bool trained = false);
    
    // Destructor
    ~Dog() override;
    
    // Getters and setters for Dog-specific attributes
    std::string getBreed() const;
    bool isTrained() const;
    void setBreed(const std::string& breed);
    void setTrainedStatus(bool status);
    
    // Override pure virtual methods
    void makeSound() const override;
    std::string getSpecies() const override;
    
    // Override virtual methods
    void eat() const override;
    void play() const override;
    
    // Dog-specific methods
    void train();
    void fetch() const;
    
    // Override displayInfo to show dog-specific attributes
    void displayInfo() const override;
};

#endif // DOG_HPP