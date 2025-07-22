#ifndef CAT_HPP
#define CAT_HPP

#include "Pet.hpp"

class Cat : public Pet {
private:
    std::string color;
    bool isIndoor;
    
public:
    // Constructor
    Cat(const std::string& name, int age, const std::string& color, bool indoor = true);
    
    // Destructor
    ~Cat() override;
    
    // Getters and setters for Cat-specific attributes
    std::string getColor() const;
    bool getIsIndoor() const;
    void setColor(const std::string& color);
    void setIsIndoor(bool indoor);
    
    // Override pure virtual methods
    void makeSound() const override;
    std::string getSpecies() const override;
    
    // Override virtual methods
    void eat() const override;
    void sleep() const override;
    
    // Cat-specific methods
    void purr() const;
    void scratch() const;
    
    // Override displayInfo to show cat-specific attributes
    void displayInfo() const override;
};

#endif // CAT_HPP