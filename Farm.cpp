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
        return 5; 
    }

public:
    Crop() : cropType("unknown"), quantity(0) {}  // Default constructor

    Crop(string type, int qty) : cropType(type), quantity(qty) {}  // Parameterized constructor

    virtual void plantCrops() {
        totalCropsPlanted += quantity;
        cout << "You have planted " << quantity << " " << cropType
             << " crops. They will be ready to harvest in "
             << calculateHarvestTime() << " days." << endl;
        cout << "Total crops planted: " << totalCropsPlanted << endl;
    }

    virtual void allocateWater(int liters) {
        cout << "You allocated " << liters << " liters of water to your crops. "
             << "The " << cropType << " is growing well." << endl;
    }

    static int getTotalCropsPlanted() {
        return totalCropsPlanted;
    }
};

int Crop::totalCropsPlanted = 0;

// Liskov Substitution Principle (LSP) for crops
class VegetableCrop : public Crop {
public:
    VegetableCrop(string type, int qty) : Crop(type, qty) {}

    void plantCrops() override {
        Crop::plantCrops();  // Using the base class's plant functionality
    }
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
    Animal() : animalType("unknown"), quantity(0) {}  // Default constructor

    Animal(string type, int qty) : animalType(type), quantity(qty) {}  // Parameterized constructor

    virtual void feedAnimals() {
        totalAnimalsFed += quantity;
        cout << "You have fed " << quantity << " " << animalType
             << ". They will produce in " << calculateProductionTime()
             << " day(s)." << endl;
        cout << "Total animals fed: " << totalAnimalsFed << endl;
    }

    virtual void sellProduce(string produce, int qty, int pricePerUnit) {
        int totalPrice = qty * pricePerUnit;
        cout << "You sold " << qty << " " << produce << " for $" << totalPrice
             << ". Your total money is now $" << (totalPrice + 100) << "." << endl;
    }

    static int getTotalAnimalsFed() {
        return totalAnimalsFed;
    }
};

int Animal::totalAnimalsFed = 0;

// Liskov Substitution Principle (LSP) for animals
class Livestock : public Animal {
public:
    Livestock(string type, int qty) : Animal(type, qty) {}

    void feedAnimals() override {
        Animal::feedAnimals();  
    }

    void sellProduce(string produce, int qty, int pricePerUnit) override {
        Animal::sellProduce(produce, qty, pricePerUnit);  
    }
};

int main() {

    // Using VegetableCrop and Livestock objects as substitutes for Crop and Animal

    Crop* crop = new VegetableCrop("wheat", 10);  
    crop->plantCrops();
    crop->allocateWater(20);

    Animal* animal = new Livestock("cows", 5);  
    animal->feedAnimals();
    animal->sellProduce("milk", 10, 15);

    delete crop;
    delete animal;

    return 0;
}
