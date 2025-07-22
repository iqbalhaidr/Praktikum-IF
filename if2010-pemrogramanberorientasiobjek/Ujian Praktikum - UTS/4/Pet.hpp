#ifndef PET_HPP
#define PET_HPP

#include <string>

class Pet {
protected:
    std::string name;
    int age;
    std::string healthStatus;
    std::string id;
    
public:
    // Constructor
    Pet(const std::string& name, int age);
    
    // Virtual destructor
    virtual ~Pet();
    
    // Getters
    std::string getName() const;
    int getAge() const;
    std::string getHealthStatus() const;
    std::string getId() const;
    
    // Setters
    void setName(const std::string& name);
    void setAge(int age);
    void setHealthStatus(const std::string& status);
    void setId(const std::string& id);
    
    // Pure virtual methods
    virtual void makeSound() const = 0;
    virtual std::string getSpecies() const = 0;
    
    // Virtual methods with implementation
    virtual void eat() const;
    virtual void sleep() const;
    virtual void play() const;
    
    // Display pet information
    virtual void displayInfo() const;
};

#endif // PET_HPP