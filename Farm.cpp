#include <iostream>
#include <string>

using namespace std;

class Crop {
public:
    string cropType;
    int quantity;

    void plantCrops(string type, int qty) {
        cropType = type;
        quantity = qty;
        cout << "You have planted " << quantity << " " << cropType << " crops. They will be ready to harvest in 5 days." << endl;
    }

    void allocateWater(int liters) {
        cout << "You allocated " << liters << " liters of water to your crops. The " << cropType << " is growing well." << endl;
    }
};

class Animal {
public:
    string animalType;
    int quantity;

    void feedAnimals(string type, int qty) {
        animalType = type;
        quantity = qty;
        cout << "You have fed " << quantity << " " << animalType << ". They will produce milk tomorrow." << endl;
    }

    void sellProduce(string produce, int qty, int pricePerUnit) {
        int totalPrice = qty * pricePerUnit;
        cout << "You sold " << qty << " " << produce << " for Rs. " << totalPrice << ". Your total money is now Rs. " << (totalPrice + 100) << "." << endl;
    }
};

int main() {
    Crop wheatCrop;
    Animal cow;

    wheatCrop.plantCrops("wheat", 10);
    cow.feedAnimals("cows", 5);
    wheatCrop.allocateWater(20);
    cow.sellProduce("eggs", 10, 15);

    return 0;
}