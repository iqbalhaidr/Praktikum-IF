#ifndef PET_SHELTER_HPP
#define PET_SHELTER_HPP

#include <string>
#include <iostream>
#include "Pet.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define MAX_SHELTER_CAPACITY 20 // Maximum capacity for the shelter

template <typename T>
class PetShelter {
private:
    Pet* pets[MAX_SHELTER_CAPACITY]; // Array to store pets in the shelter
    std::string shelterName; // Name of the shelter
    int dogCapacity; // Maximum capacity for dogs
    int catCapacity; // Maximum capacity for cats
    int petCount; // Total number of pets in the shelter
    int currentDogs; // Current number of dogs in the shelter
    int currentCats; // Current number of cats in the shelter

public:
    PetShelter(std::string shelterName);
    /* Default constructor:
     * - Creates a shelter with the given name.
     * - Default capacity: 8 dogs, 12 cats.
     * - No pets in the shelter initially.
     */

    PetShelter(std::string shelterName, int dogCapacity, int catCapacity);
    /* Constructor with specified capacities:
     * - Creates a shelter with custom capacities for dogs and cats.
     * - If total capacity exceeds MAX_SHELTER_CAPACITY, prints:
     *   "The total capacity you construct is <total>, meanwhile the shelter capacity is 20"
     */

    ~PetShelter();
    /* Destructor:
     * - Cleans up all dynamically allocated pets.
     * - Sets pet pointers to nullptr after deletion.
     */

    std::string getShelterName() const;
    /* Returns the name of the shelter.
     * Output: Shelter name as a string.
     */

    void addPet(const std::string &petName, int age, bool isDog, const std::string &extraInfo);
    /* Adds a pet to the shelter.
    * Input:
    * - petName: Name of the pet.
    * - age: Age of the pet in years.
    * - isDog: If true, adds a dog; if false, adds a cat.
    * - extraInfo: For dogs, this is the breed; for cats, this is the color.
    *
    * Process:
    * - If shelter is full, prints "Error: Shelter is at full capacity!".
    * - If dog capacity is full, prints "Error: No space for more dogs!".
    * - If cat capacity is full, prints "Error: No space for more cats!".
    *
    * - If addition is successful, system will create a **unique pet ID** based on pet type:
    *   - If dog, ID will be "D" followed by the dog's sequential number. Ex: "D1", "D2", etc.
    *   - If cat, ID will be "C" followed by the cat's sequential number. Ex: "C1", "C2", etc.
    *
    * - If addition is successful, prints:
    *   "Success: <petName> has been added as a <Dog/Cat>! Pet ID: <petID>"
    */

    T* findPet(const std::string &petID) const;
    /* Checks if a pet with the given ID exists in the shelter.
     * Input:
     * - petID: ID of the pet to check.
     *
     * Output:
     * - If found, prints pet details using the displayInfo() method.
     * - If not found, prints "Pet ID is invalid!".
     * Note: Uses dynamic_cast to safely convert from Pet* to T* when returning.
     */

    void listAllPets() const;
    /* Displays a list of all pets in the shelter.
     * Output:
     * - If no pets in the shelter, prints "No pets in the shelter yet!".
     * - If pets exist, prints in the format:
     *   "<number>. <pet.displayInfo()>"
     *
     * - Numbering in output starts from 1.
     */

    int calculateCost() const;
    /* Calculates total cost of maintaining all pets in the shelter.
     * - Dogs cost 75 per day.
     * - Cats cost 60 per day.
     * 
     * Output: Total daily maintenance cost as an integer.
     * Note: Uses dynamic_cast to determine the type of pet (Dog or Cat) 
     * to apply the correct maintenance cost.
     * Example:
     *   if (dynamic_cast<Dog*>(pets[i])) { cost += 75; }
     *   else if (dynamic_cast<Cat*>(pets[i])) { cost += 60; }
     */
    
    void removePet(const std::string &petID);
    /* Removes a pet with the given ID from the shelter.
     * Input:
     * - petID: ID of the pet to remove.
     *
     * Output:
     * - If found and removed, prints "<petName> has been removed from the shelter."
     * - If not found, prints "Pet ID is invalid!"
     * Note: Uses dynamic_cast to determine pet type when updating counters:
     *   if (dynamic_cast<Dog*>(pets[i])) { currentDogs--; }
     *   else if (dynamic_cast<Cat*>(pets[i])) { currentCats--; }
     */
};

#endif // PET_SHELTER_HPP