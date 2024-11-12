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

int main() {
    // Using parameterized constructors
    Crop crop("wheat", 10);
    crop.plantCrops();
    crop.allocateWater(20);

    Animal animal("cows", 5);
    animal.feedAnimals();
    animal.sellProduce("milk", 10, 15);

    return 0;
}
