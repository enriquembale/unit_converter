#include <stdio.h>



int getChoice(const char *menu, int min, int max);
float getUnit(const char *prompt);
float convertLength(int input, int output, float unit);
float convertWeight(int input, int output, float unit);
float convertVolume(int input, int output, float unit);
float convertTime(int input, int output, float unit);
float convertTemp(int input, float unit);
void mainMenu();

//Length based funtions
void lengthMenu(void) {
    while (1) {
    char lengthOptions[] = {
        "1. Millimeters\n"
        "2. Centimeters\n"
        "3. Meters\n"
        "4. Kilometers\n"
        "5. Inches\n"
        "6. Feet\n"
        "7. Yards\n"
        "8. Miles\n"
        "0. Go back\n\n"
    
    };


    printf("Length conversion\n\n");

    //Decide what to convert from
    printf("Convert from:\n%s", lengthOptions);
    int from = getChoice("Enter your choice: ", 0, 8);

    if (from == 0) {
        return;
    }

    float unit = getUnit("Please enter a valid number: ");



    //Decide what to convert to
    printf("\nConvert to:\n%s", lengthOptions);
    int to = getChoice("Enter your choice: ", 0, 8);
    float finalUnit = convertLength(from, to, unit);

    printf("\n\n1. Another conversion\n");
    printf("0. Main menu\n");

    if (getChoice("Choice: ", 0, 1) == 0)
        return;
}



}     

float convertLength(int input, int output, float unit) {
    const char *shortLength[8] = {"mm", "cm", "m", "km", "in", "ft", "yd", "mi"};
    float finalUnit;
    // input/output units in meters
    float lengthToMeter[8] = {
        0.001,      // 1 millimeter
        0.01,       // 1 centimeter
        1.0,        // 1 meter
        1000.0,     // 1 kilometer
        0.0254,     // 1 inches
        0.3048,     // 1 foot
        0.9144,     // 1 yards
        1609.344    // 1 miles
    };
    // Convert input unit to meters then meters to output unit
    finalUnit = (unit * lengthToMeter[input - 1]) / lengthToMeter[output - 1];
    printf("%g %s = %g %s", unit, shortLength[input - 1], finalUnit, shortLength[output - 1]);
}


// Weight based funtions
void weightMenu(void) {
    while (1) {
        char weightOptions[] = {
            "1. Milligrams (mg)\n"
            "2. Grams (g)\n"
            "3. Kilograms (kg)\n"
            "4. Tonnes (t)\n"
            "5. Ounces (oz)\n"
            "6. Pounds (lb)\n"
            "7. Stones (st)\n"
            "0. Go back\n\n"
        };

        printf("Weight conversion\n\n");

        //Decide what to convert from
        printf("Convert from:\n%s", weightOptions);
        int from = getChoice("Enter your choice: ", 0, 7);

        if (from == 0) {
            return;
        }
        
        float unit = getUnit("Please enter a valid number: ");

        //Decide what to convert to
        printf("\nConvert to:\n%s", weightOptions);
        int to = getChoice("Enter your choice: ", 0, 7);
        float finalUnit = convertWeight(from, to, unit);

            printf("\n1. Another conversion\n");
            printf("0. Main menu\n");

        if (getChoice("Choice: ", 0, 1) == 0)
            return;
    }
    


}

float convertWeight(int input, int output, float unit) {
    const char *shortWeight[7] = {"mg", "g", "kg", "t", "oz", "lb", "st"};
    float finalUnit;
    // input/output units in kilo
    float massToKilo[] = {
        0.000001,       // 1 milligram
        0.001,          // 1 gram
        1.0,            // 1 kilogram
        1000.0,         // 1 tonne
        0.028349523125, // 1 ounce
        0.45359237,     // 1 pound
        6.35029318      // 1 stone
    };  
    // Convert input unit to meters then meters to output unit
    finalUnit = (unit * massToKilo[input - 1]) / massToKilo[output - 1];
    printf("%g %s = %g %s", unit, shortWeight[input - 1], finalUnit, shortWeight[output - 1]);
}


// Volume based functions
void volumeMenu(void) {
    while (1) {

        char volumeOptions[] = {
            "1. Milliliters (mL)\n"
            "2. Liters (L)\n"
            "3. Cubic Meters (m³)\n"
            "4. Teaspoons (tsp)\n"
            "5. Tablespoons (tbsp)\n"
            "6. Fluid Ounces (fl oz)\n"
            "7. Cups (cup)\n"
            "8. Pints (pt)\n"
            "9. Quarts (qt)\n"
            "10. Gallons (gal)\n"
            "0. Go back\n\n"
        };


        printf("Volume conversion\n\n");

        //Decide what to convert from
        printf("Convert from:\n%s", volumeOptions);
        int from = getChoice("Enter your choice: ", 0, 10);

        if (from == 0)
            return; 

        float unit = getUnit("Please enter a valid number: ");

        //Decide what to convert to
        printf("\nConvert to:\n%s", volumeOptions);
        int to = getChoice("Enter your choice: ", 0, 10);
        float finalUnit = convertVolume(from, to, unit);

        

        printf("\n1. Another conversion\n");
        printf("0. Main menu\n");

        if (getChoice("Choice: ", 0, 1) == 0)
            return;}

}     

float convertVolume(int input, int output, float unit) {
    const char *shortVolume[10] = {"mL", "L", "m³", "tsp", "tbsp", "fl oz", "cup", "pt", "qt", "gal"};
    float finalUnit;
    // input/output units in meters
    double volumeToLiters[] = {
        0.001,         // 1 milliliter 
        1.0,           // 1 liter 
        1000.0,        // 1 cubic meter
        0.00492892159, // 1 teaspoon
        0.0147867648,  // 1 tablespoon
        0.0295735296,  // 1 fluid ounce
        0.236588237,   // 1 cup
        0.473176473,   // 1 pint
        0.946352946,   // 1 quart 
        3.785411784    // 1 gallon
    };
    // Convert input unit to meters then meters to output unit
    finalUnit = (unit * volumeToLiters[input - 1]) / volumeToLiters[output - 1];
    printf("%g %s = %g %s", unit, shortVolume[input - 1], finalUnit, shortVolume[output - 1]);
}

// Time based functions

void timeMenu(void) {
    while (1) {
        char timeOptions[] = {
            "1. Milliseconds (ms)\n"
            "2. Seconds (s)\n"
            "3. Minutes (min)\n"
            "4. Hours (hr)\n"
            "5. Days (day)\n"
            "6. Weeks (wk)\n"
            "7. Go back\n\n"
        };


        printf("Time conversion\n\n");

        //Decide what to convert from
        printf("Convert from:\n%s", timeOptions);
        int from = getChoice("Enter your choice: ", 0, 6);

        if (from == 0)
            return; 

        float unit = getUnit("Please enter a valid number: ");

        //Decide what to convert to
        printf("\nConvert to:\n%s", timeOptions);
        int to = getChoice("Enter your choice: ", 0, 6);
        float finalUnit = convertTime(from, to, unit);

        printf("\n1. Another conversion\n");
        printf("0. Main menu\n");

        if (getChoice("Choice: ", 0, 1) == 0)
            return;}


    

}     

float convertTime(int input, int output, float unit) {
    const char *shortTime[6] = {"ms", "s", "min", "hr", "day", "wk"};
    float finalUnit;
    // input/output units in meters
    float timeToSecond[6] = {
        0.001,      // 1 millisecond 
        1.0,        // 1 second
        60.0,       // 1 minute
        3600.0,     // 1 hour
        86400.0,    // 1 day 
        604800.0    // 1 week 
    };
    // Convert input unit then output unit
    finalUnit = (unit * timeToSecond[input - 1]) / timeToSecond[output - 1];
    printf("%.2f %s = %.2f %s", unit, shortTime[input - 1], finalUnit, shortTime[output - 1]);
}

// Temperature based functions

void tempMenu(void) {
    while (1) {
        char tempOptions[] = {
            "1. Celsius (°C) to Fahrenheit (°F)\n"
            "2. Fahrenheit (°F) to Celsius (°C)\n"
            "Go back\n\n"
        };


        printf("Temperature conversion\n\n");

        //Decide what to convert from
        printf("Convert from:\n%s", tempOptions);
        int from = getChoice("Enter your choice: ", 0, 2);

        if (from == 0)
            return; 

        float unit = getUnit("Please enter a valid number: ");

        float finalUnit = convertTemp(from, unit);

        printf("\n1. Another conversion\n");
        printf("0. Main menu\n");

        if (getChoice("Choice: ", 0, 1) == 0)
            return;}


    

}     

float convertTemp(int input, float unit) {
    const char *shortTemp[2] = {"°F", "°C"};
    float finalUnit;
    
    switch(input) {
        case 1: 
            finalUnit = (unit * 9/5) + 32;
            printf("%g °C = %g °F", unit, finalUnit);
            break; 
        case 2:  
            finalUnit = (unit - 32) * 5/9;
            printf("%g °F = %g °C", unit, finalUnit);
            break;
    }

}












float getUnit(const char *prompt) {
    float value;

    while (1) {

        printf("%s", prompt);
        if (scanf("%f", &value) == 1) {
            while (getchar() != '\n');
            return value;
        }
        while (getchar() != '\n');
        printf("%s", prompt);
    }

}

int getChoice(const char *menu, int min, int max) {
    int choice;
    printf("%s", menu);
    while(1) { 
        if (scanf("%d", &choice) != 1 || choice > max || choice  < min) { 
            while (getchar() != '\n');
            printf("Please select a valid option. \n"); 
            printf("%s", menu);
            continue;
        }
        break;
    }


    return choice;
}

void mainMenu(void) {
    while (1) {

    printf("=========================\n"
            "      UNIT CONVERTER\n"
            "=========================\n\n"
            "1. Length\n2. Weight\n3. Time\n4. Volume\n5. Temperature\n0. Exit\n\n");
    int whichMenu = getChoice("Enter your choice: ", 0, 5);

    switch(whichMenu){
        case 1:
                lengthMenu();
                break;
        case 2:
                weightMenu();
                break;
        case 3:
                timeMenu();
                break;
        case 4:
                volumeMenu();
                break;
        case 5: 
                tempMenu();
                break;
        case 0:
                printf("Thank you for using my unit converter — Brought to you by Enrique");
                return;
    }
}
    
}

    
int main(void) {
    mainMenu();
    return 0;
}