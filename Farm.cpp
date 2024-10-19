#include <iostream>
#include <string>

using namespace std;

class Crop {
private:
    string cropType;
    int quantity;
    static int totalCropsPlanted;  // Static variable to track total crops planted

public:
    // Mutator (setter) for cropType
    void setCropType(string type) {
        cropType = type;
    }

    // Accessor (getter) for cropType
    string getCropType() const {
        return cropType;
    }

    // Mutator (setter) for quantity
    void setQuantity(int qty) {
        quantity = qty;
    }

    // Accessor (getter) for quantity
    int getQuantity() const {
        return quantity;
    }

    // Method to plant crops (uses encapsulated data)
    void plantCrops() {
        totalCropsPlanted += quantity;
        cout << "You have planted " << quantity << " " << cropType << " crops. They will be ready to harvest in 5 days." << endl;
        cout << "Total crops planted: " << totalCropsPlanted << endl;
    }

    void allocateWater(int liters) {
        cout << "You allocated " << liters << " liters of water to your crops. The " << cropType << " is growing well." << endl;
    }

    // Static member function to access total crops planted
    static int getTotalCropsPlanted() {
        return totalCropsPlanted;
    }
};

// Initialize static variable outside the class
int Crop::totalCropsPlanted = 0;

class Animal {
private:
    string animalType;
    int quantity;
    static int totalAnimalsFed;

public:
    // Mutator (setter) for animalType
    void setAnimalType(string type) {
        animalType = type;
    }

    // Accessor (getter) for animalType
    string getAnimalType() const {
        return animalType;
    }

    // Mutator (setter) for quantity
    void setQuantity(int qty) {
        quantity = qty;
    }

    // Accessor (getter) for quantity
    int getQuantity() const {
        return quantity;
    }

    // Method to feed animals (uses encapsulated data)
    void feedAnimals() {
        totalAnimalsFed += quantity;
        cout << "You have fed " << quantity << " " << animalType << ". They will produce milk tomorrow." << endl;
        cout << "Total animals fed: " << totalAnimalsFed << endl;
    }

    void sellProduce(string produce, int qty, int pricePerUnit) {
        int totalPrice = qty * pricePerUnit;
        cout << "You sold " << qty << " " << produce << " for $" << totalPrice << ". Your total money is now $" << (totalPrice + 100) << "." << endl;
    }

    // Static member function to access total animals fed
    static int getTotalAnimalsFed() {
        return totalAnimalsFed;
    }
};

// Initialize static variable outside the class
int Animal::totalAnimalsFed = 0;

int main() {
    // Dynamically allocated memory for Crop objects
    Crop* crops = new Crop[1];
    crops[0].setCropType("wheat");
    crops[0].setQuantity(10);
    crops[0].plantCrops();
    crops[0].allocateWater(20);

    // Dynamically allocated memory for Animal objects
    Animal* animals = new Animal[1];
    animals[0].setAnimalType("cows");
    animals[0].setQuantity(5);
    animals[0].feedAnimals();
    animals[0].sellProduce("eggs", 10, 15);

    // Release dynamically allocated memory
    delete[] crops;
    delete[] animals;

    return 0;
}
