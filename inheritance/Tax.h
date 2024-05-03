#pragma once
#include<iostream>
using namespace std;

class Tax {
public:
    float taxRate_factor1;

    Tax() : taxRate_factor1(2) {
        cout << "Selected Region Tax Rate applies" << endl;
    }

    Tax(float tr) : taxRate_factor1(tr) {}

    // Task 1: Make the required function(s) (such as taxCalc) virtual in Tax class
    virtual float taxCalc(float amount) {
        return taxRate_factor1 * amount;
    }

    virtual float amountAfterTax(float amount) {
        return (amount - taxCalc(amount));
    }
};

class UpdatedTax : public Tax {
protected:
    float taxRate_factor2;
    float taxRate_factor3;

public:
    // Task 2: Add 2 more tax factors (taxRate_factor2, taxRate_factor3 in this class)
    UpdatedTax(float tr, float tr2, float tr3) 
    {
        taxRate_factor1 = tr; 
        taxRate_factor2 = tr2; 
        taxRate_factor3 = tr3;
    }

    // Task 3: Redefine virtual function(s) in child class to incorporate all three tax factors
    float taxCalc(float amount) override {
        return (taxRate_factor1 + taxRate_factor2 + taxRate_factor3) * amount;
    }
};
//Task 4 - Add 2 regions (region 1, region 2)
class CustomizedTax : public UpdatedTax {
private:
    float region1;
    float region2;

public:
    // Constructor that takes selectedRegion as a parameter
    CustomizedTax(float tr, float tr2, float tr3, int selectedRegion)
        : UpdatedTax(tr, tr2, tr3) {
        if (selectedRegion == 1) {
            region1 = 0.07;  // Set region1 value 
            region2 = 0.0;  // region2 value is zero for when selected region is region1
        }
        else if (selectedRegion == 2) {
            region1 = 0.0;  // region1 value is zero for when selected region is region2
            region2 = 0.09;  // Set region2 value
        }
        else {
            throw invalid_argument("Invalid region selected");
        }
    }

    // Task 5: Redefine the relevant virtual function in this class to incorporate the tax factors based on regions
    float taxCalc(float amount) override {
        return (taxRate_factor1 + taxRate_factor2 + taxRate_factor3 + region1 + region2) * amount;
    }

 
};
