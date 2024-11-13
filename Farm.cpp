#include <iostream>
#include <string>

using namespace std;

// Abstract class using a pure virtual function
class FarmEntity {
public:
    virtual void performActivity() const = 0;  // Pure virtual function making FarmEntity an abstract class
};

class Crop : public FarmEntity {
private:
    string cropType;
    int quantity;
    static int totalCropsPlanted;

public:
    Crop(string type, int qty) : cropType(type), quantity(qty) {}

    void plantCrops() {
        totalCropsPlanted += quantity;
        cout << "You have planted " << quantity << " " << cropType
             << " crops. They will be ready to harvest in 5 days." << endl;
        cout << "Total crops planted: " << totalCropsPlanted << endl;
    }

    string getCropType() const {
        return cropType;
    }

    // SRP: Crop class is only responsible for crop-specific activities
    void performActivity() const override {
        cout << "The crop activity: Planting " << cropType << " crops." << endl;
    }
};

int Crop::totalCropsPlanted = 0;

// New class for crop water allocation, following SRP
class CropWaterManager {
public:
    void allocateWater(const Crop &crop, int liters) const {
        cout << "You allocated " << liters << " liters of water to your crops. "
             << "The " << crop.getCropType() << " is growing well." << endl;
    }
};

// Class to handle animal-related data and feeding responsibility
class Animal : public FarmEntity {
private:
    string animalType;
    int quantity;
    static int totalAnimalsFed;

public:
    Animal(string type, int qty) : animalType(type), quantity(qty) {}

    void feedAnimals() {
        totalAnimalsFed += quantity;
        cout << "You have fed " << quantity << " " << animalType
             << ". They will produce in 1 day(s)." << endl;
        cout << "Total animals fed: " << totalAnimalsFed << endl;
    }

    // SRP: Animal class is only responsible for animal-specific activities
    void performActivity() const override {
        cout << "The animal activity: Feeding " << animalType << " animals." << endl;
    }
};

int Animal::totalAnimalsFed = 0;

// New class for handling animal produce sales, following SRP
class AnimalProduceManager {
public:
    void sellProduce(const Animal &animal, string produce, int qty, int pricePerUnit) const {
        int totalPrice = qty * pricePerUnit;
        cout << "You sold " << qty << " " << produce << " for $" << totalPrice
             << ". Your total money is now $" << (totalPrice + 100) << "." << endl;
    }
};

int main() {
    Crop crop("wheat", 10);
    crop.plantCrops();
    crop.performActivity();  // Demonstrates the overridden performActivity method for Crop

    // CropWaterManager handles the responsibility of watering the crop
    CropWaterManager waterManager;
    waterManager.allocateWater(crop, 20);

    Animal animal("cows", 5);
    animal.feedAnimals();
    animal.performActivity();  // Demonstrates the overridden performActivity method for Animal

    // AnimalProduceManager handles the responsibility of selling produce
    AnimalProduceManager produceManager;
    produceManager.sellProduce(animal, "milk", 10, 15);

    return 0;
}
