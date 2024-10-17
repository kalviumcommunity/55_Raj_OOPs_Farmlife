#include <iostream>
#include <string>

using namespace std;

class Crop {
public:
    string cropType;
    int quantity;
    static int totalCropsPlanted;  // Static variable to track total crops planted

    void plantCrops(string cropType, int quantity) {
        this->cropType = cropType;
        this->quantity = quantity;
        totalCropsPlanted += quantity;  // Increment the total crops planted
        cout << "You have planted " << this->quantity << " " << this->cropType << " crops. They will be ready to harvest in 5 days." << endl;
        cout << "Total crops planted: " << totalCropsPlanted << endl;
    }

    void allocateWater(int liters) {
        cout << "You allocated " << liters << " liters of water to your crops. The " << this->cropType << " is growing well." << endl;
    }
};

// Initialize static variable outside the class
int Crop::totalCropsPlanted = 0;  // Starting with 0 crops

class Animal {
public:
    string animalType;
    int quantity;
    static int totalAnimalsFed;  // Static variable to track total animals fed

    void feedAnimals(string animalType, int quantity) {
        this->animalType = animalType;
        this->quantity = quantity;
        totalAnimalsFed += quantity;  // Increment the total animals fed
        cout << "You have fed " << this->quantity << " " << this->animalType << ". They will produce milk tomorrow." << endl;
        cout << "Total animals fed: " << totalAnimalsFed << endl;
    }

    void sellProduce(string produce, int qty, int pricePerUnit) {
        int totalPrice = qty * pricePerUnit;
        cout << "You sold " << qty << " " << produce << " for $" << totalPrice << ". Your total money is now $" << (totalPrice + 100) << "." << endl;
    }
};

// Initialize static variable outside the class
int Animal::totalAnimalsFed = 0;  // Starting with 0 animals fed

int main() {
    // dynamically allocated memory for Crop objects
    Crop* crops = new Crop[1];  
    crops[0].plantCrops("wheat", 10);   
    crops[0].allocateWater(20);

    // dynamically allocated memory for Animal objects
    Animal* animals = new Animal[1]; 
    animals[0].feedAnimals("cows", 5);          
    animals[0].sellProduce("eggs", 10, 15);

    // Release dynamically allocated memory
    delete[] crops;
    delete[] animals;

    return 0;
}
