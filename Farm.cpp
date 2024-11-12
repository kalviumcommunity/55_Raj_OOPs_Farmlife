#include <iostream>
#include <string>

using namespace std;

class Crop {
private:
    string cropType;
    int quantity;
    static int totalCropsPlanted;

protected:
    int calculateHarvestTime() const {
        return 5;  // Harvest time in days
    }

public:
    // Default constructor
    Crop() : cropType("unknown"), quantity(0) {}

    // Parameterized constructor
    Crop(string type, int qty) : cropType(type), quantity(qty) {}

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

int Crop::totalCropsPlanted = 0;

// Derived class demonstrating single inheritance
class VegetableCrop : public Crop {
public:
    // Constructor for VegetableCrop calling the base class constructor
    VegetableCrop(string type, int qty) : Crop(type, qty) {}
};

class Animal {
private:
    string animalType;
    int quantity;
    static int totalAnimalsFed;

protected:
    int calculateProductionTime() const {
        return 1;  // Production time in days
    }

public:
    // Default constructor
    Animal() : animalType("unknown"), quantity(0) {}

    // Parameterized constructor
    Animal(string type, int qty) : animalType(type), quantity(qty) {}

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

int Animal::totalAnimalsFed = 0;

// Derived class demonstrating multilevel inheritance
class Livestock : public Animal {
public:
    // Constructor for Livestock calling the base class constructor
    Livestock(string type, int qty) : Animal(type, qty) {}
};

int main() {
    // Using parameterized constructors with inheritance
    VegetableCrop vegetable("wheat", 10);
    vegetable.plantCrops();
    vegetable.allocateWater(20);

    Livestock livestock("cows", 5);
    livestock.feedAnimals();
    livestock.sellProduce("milk", 10, 15);

    return 0;
}
