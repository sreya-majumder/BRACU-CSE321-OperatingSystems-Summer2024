#include <stdio.h>

//Defining paratha as a structure
struct orderParatha {
   int parathaQuantity ;
   int parathaPrice ;
};

//Defining vegetable as a structure
struct orderVegetable {
   int vegetableQuantity ;
   int vegetablePrice ;
};

//Defining mineral water as a structure
struct orderMineralWater {
   int mineralWaterQuantity ;
   int mineralWaterPrice ;
};

int main(){

    //Declaring variable for paratha structure
    struct orderParatha breakfastItemParatha;

    //Taking inputs for paratha
    printf("Quantity Of Paratha: ");
    scanf("%d", &breakfastItemParatha.parathaQuantity);

    printf("Unit Price: ");
    scanf("%d", &breakfastItemParatha.parathaPrice);

    //Declaring variable for vegetable structure
    struct orderVegetable breakfastItemVegetable;
    
    //Taking inputs for vegetable
    printf("Quantity Of Vegetables: ");
    scanf("%d", &breakfastItemVegetable.vegetableQuantity);

    printf("Unit Price: ");
    scanf("%d", &breakfastItemVegetable.vegetablePrice);

    //Declaring variable for meneral water structure
    struct orderMineralWater breakfastItemMineralWater;

    //Taking inputs for Mineral Water
    printf("Quantity Of Mineral Water: ");
    scanf("%d", &breakfastItemMineralWater.mineralWaterQuantity);

    printf("Unit Price: ");
    scanf("%d", &breakfastItemMineralWater.mineralWaterPrice);

    //Calculating the bill of individual item
    int parathaBill = breakfastItemParatha.parathaQuantity * breakfastItemParatha.parathaPrice;
    int vegetableBill = breakfastItemVegetable.vegetableQuantity * breakfastItemVegetable.vegetablePrice;
    int mineralWaterBill = breakfastItemMineralWater.mineralWaterQuantity * breakfastItemMineralWater.mineralWaterPrice;

    //Calculating the total bill
    int totalBill = parathaBill + vegetableBill + mineralWaterBill;

    //Taking input for total person
    float totalPeople;
    printf("Number of People: ");
    scanf("%f", &totalPeople);

    //Calculating the bill that each person needs to pay
    float individualBill = totalBill/totalPeople;

    //Printing statement
    printf("Individual people will pay: %.2f tk\n", individualBill);

    return 0;
}
