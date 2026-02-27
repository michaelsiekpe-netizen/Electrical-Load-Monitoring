# Smart Energy System (C++)

A simple console-based C++ program that helps users register electrical appliances, calculate daily energy consumption, and estimate electricity bills.

---

## Overview

This project allows a user to:

- Register appliances with power rating and daily usage hours
- View all registered appliances
- Automatically calculate energy consumption (kWh)
- Calculate total electricity cost based on a tariff
- Save and load appliance data from a file

The system stores data in a file called `appliances.txt` so that information is not lost when the program closes.

---

## How Energy Is Calculated

Energy consumption is calculated using:

Energy (kWh) = (Power in Watts × Usage Hours) / 1000

Example:
If a device uses 100W for 5 hours per day:

Energy = (100 × 5) / 1000  
Energy = 0.5 kWh

---

## Features

- Register appliances
- View appliance list in formatted table
- Calculate total energy consumption
- Calculate billing using user-defined tariff
- Automatic file saving and loading

---

## Project Structure

- main.cpp
- appliances.txt (created automatically)
- README.md

---

## How to Compile and Run

Using g++:

Compile:
g++ main.cpp -o energy

Run (Linux / Mac):
./energy

Run (Windows):
energy.exe

---

## Menu Options

1. Register Appliance
2. View Appliances
3. Calculate Total Energy
4. Calculate Billing
5. Exit

When you choose Exit, all appliances are saved automatically.

---

## Sample Output

Appliance List

Name Power(W) Hours Energy(kWh)
Fan 100 5 0.5
TV 200 4 0.8

---

## Possible Improvements

- Add delete appliance option
- Support appliance names with spaces
- Add monthly energy calculation
- Add better input validation
- Build a graphical interface version

---

Author: Michael Siekpe
Program: Electrical Engineering  
Institution: Accra Technical University
