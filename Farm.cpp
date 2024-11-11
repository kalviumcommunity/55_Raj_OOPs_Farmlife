#include <iostream>
#include <string>

using namespace std;

class Crop {
private:
    string cropType;       // Private data members to store crop details
    int quantity;
    static int totalCropsPlanted;  // Static variable to track total crops planted

protected:
    // Protected method to calculate time to harvest (hidden from outside access)
    int calculateHarvestTime() const {
        return 5;  // Harvest time in days
    }

public:
    // Public setter and getter methods to control access to private data
    void setCropType(string type) {
        cropType = type;
    }

    string getCropType() const {
        return cropType;
    }

    void setQuantity(int qty) {
        quantity = qty;
    }

    int getQuantity() const {
        return quantity;
    }

    // Public method to plant crops, which uses internal data and logic
    void plantCrops() {
        totalCropsPlanted += quantity;
        cout << "You have planted " << quantity << " " << cropType 
             << " crops. They will be ready to harvest in " 
             << calculateHarvestTime() << " days." << endl;
        cout << "Total crops planted: " << totalCropsPlanted << endl;
    }

    void allocateWater(int liters) {
        cout << "You allocated " << liters << " liters of water to your crops. "
             << "The " << cropType << " is growing well." << endl;
    }

    static int getTotalCropsPlanted() {
        return totalCropsPlanted;
    }
};

// Initialize static variable outside the class
int Crop::totalCropsPlanted = 0;

class Animal {
private:
    string animalType;     // Private data members to store animal details
    int quantity;
    static int totalAnimalsFed;

protected:
    // Protected method to calculate production time (hidden from outside access)
    int calculateProductionTime() const {
        return 1;  // Production time in days
    }

public:
    // Public setter and getter methods for private data
    void setAnimalType(string type) {
        animalType = type;
    }

    string getAnimalType() const {
        return animalType;
    }

    void setQuantity(int qty) {
        quantity = qty;
    }

    int getQuantity() const {
        return quantity;
    }

    // Public method to feed animals, which uses private and protected data
    void feedAnimals() {
        totalAnimalsFed += quantity;
        cout << "You have fed " << quantity << " " << animalType 
             << ". They will produce in " << calculateProductionTime() 
             << " day(s)." << endl;
        cout << "Total animals fed: " << totalAnimalsFed << endl;
    }

    void sellProduce(string produce, int qty, int pricePerUnit) {
        int totalPrice = qty * pricePerUnit;
        cout << "You sold " << qty << " " << produce << " for $" << totalPrice 
             << ". Your total money is now $" << (totalPrice + 100) << "." << endl;
    }

    static int getTotalAnimalsFed() {
        return totalAnimalsFed;
    }
};

// Initialize static variable outside the class
int Animal::totalAnimalsFed = 0;

int main() {
    // Create and use Crop object
    Crop crop;
    crop.setCropType("wheat");
    crop.setQuantity(10);
    crop.plantCrops();
    crop.allocateWater(20);

    // Create and use Animal object
    Animal animal;
    animal.setAnimalType("cows");
    animal.setQuantity(5);
    animal.feedAnimals();
    animal.sellProduce("milk", 10, 15);

    return 0;
}
