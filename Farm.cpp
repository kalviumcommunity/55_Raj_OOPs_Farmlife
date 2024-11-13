#include <iostream>
#include <string>

using namespace std;

// Abstract class using a pure virtual function
class FarmActivity {
public:
    virtual void performActivity() const = 0;  // Pure virtual function making FarmEntity an abstract class
};

class Crop : public FarmActivity {
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

    // OCP: Implementing the performActivity method 
    void performActivity() const override {
        cout << "Planting " << quantity << " " << cropType << " crops." << endl;
    }
};

int Crop::totalCropsPlanted = 0;

class CropWaterManager : public FarmActivity {
private:
    int liters;
    string cropType;

public:
    CropWaterManager(string type, int lit) : cropType(type), liters(lit) {}

    void allocateWater() {
        cout << "You allocated " << liters << " liters of water to your crops. "
             << "The " << cropType << " is growing well." << endl;
    }

    // OCP: Implementing the performActivity method 
    void performActivity() const override {
        cout << "Allocating " << liters << " liters of water to " << cropType << " crops." << endl;
    }
};

class Animal : public FarmActivity {
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

    // OCP: Implementing the performActivity method
    void performActivity() const override {
        cout << "Feeding " << quantity << " " << animalType << "." << endl;
    }
};

int Animal::totalAnimalsFed = 0;

class AnimalProduceManager : public FarmActivity {
private:
    int qty;
    int pricePerUnit;

public:
    AnimalProduceManager(int quantity, int price) : qty(quantity), pricePerUnit(price) {}

    void sellProduce() {
        int totalPrice = qty * pricePerUnit;
        cout << "You sold " << qty << " milk for $" << totalPrice
             << ". Your total money is now $" << (totalPrice + 100) << "." << endl;
    }

    // OCP: Implementing the performActivity method 
    void performActivity() const override {
        cout << "Selling " << qty << " units of produce at $" << pricePerUnit << " per unit." << endl;
    }
};

int main() {
    // Demonstrating OCP
    Crop crop("wheat", 10);
    CropWaterManager cropWater("wheat", 20);
    Animal animal("cows", 5);
    AnimalProduceManager produceManager(10, 15);

    // Using the performActivity method polymorphically
    FarmActivity* activities[] = {&crop, &cropWater, &animal, &produceManager};
    for (const auto& activity : activities) {
        activity->performActivity();
    }

    crop.plantCrops();
    cropWater.allocateWater();
    animal.feedAnimals();
    produceManager.sellProduce();

    return 0;
}
