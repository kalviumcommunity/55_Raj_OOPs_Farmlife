# 🌾 Farm Life Simulation

A simple yet powerful OOP-based Farm Life Simulation written in C++ that demonstrates core Object-Oriented Programming principles and the Liskov Substitution Principle (LSP) through the simulation of crop planting and animal care on a farm.

## 📌 Project Overview
The Farm Life Simulation models a small farm environment where:

Crops can be planted and watered.

Animals can be fed and their produce sold.

The total number of crops planted and animals fed is tracked.

Polymorphism and inheritance are used for flexibility and scalability.

This simulation emphasizes good software design practices, especially the Liskov Substitution Principle (LSP) — ensuring that derived classes can substitute their base classes without affecting the correctness of the program.

## 🚜 Features

🌱 Crop Management: Plant different crops and allocate water.

🐄 Animal Management: Feed livestock and sell animal produce.

🔁 LSP Implementation: Derived classes like VegetableCrop and Livestock behave seamlessly as their respective base types.

📈 Tracking: Keeps count of total crops planted and animals fed.

## 🧠 OOP Concepts:

Encapsulation

Inheritance

Polymorphism (Virtual Functions)

Static Members

## 🏗️ Code Structure

Crop Class
plantCrops() – Simulates planting

allocateWater(int) – Waters the crop

Static counter for total crops planted

VegetableCrop Class (inherits from Crop)
Demonstrates LSP: behaves like a Crop

Animal Class
feedAnimals() – Feeds livestock

sellProduce() – Sells produce from animals

Static counter for total animals fed

Livestock Class (inherits from Animal)
Demonstrates LSP: behaves like an Animal

## 🛠️ How to Build & Run
🔹 Prerequisites
C++ Compiler (e.g., g++, clang++)

🔹 Compilation
`
g++ -o farm_simulation farm_simulation.cpp
`
🔹 Execution
`
./farm_simulation
`

##📌 Sample Output

`
You have planted 10 wheat crops. They will be ready to harvest in 5 days.
Total crops planted: 10
You allocated 20 liters of water to your crops. The wheat is growing well.
You have fed 5 cows. They will produce in 1 day(s).
Total animals fed: 5
You sold 10 milk for $150. Your total money is now $250.
`
## 💡 OOP Principle Highlight: Liskov Substitution Principle
This project uses LSP to allow:

VegetableCrop to be used where Crop is expected

Livestock to be used where Animal is expected

This ensures code reusability and maintainability by programming to interfaces rather than implementations.

## 📁 Project Use Cases
Academic OOP assignments

Software Design Principle demonstrations

Practice for polymorphism, inheritance, and virtual functions

Quick prototype for simulation-based logic in C++

