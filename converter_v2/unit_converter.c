#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h> 
#define CATEGORY_COUNT 4

// These structures contain the unit abbreviations, count of units and factors in which the base unit is equal to
// e.g Length: Base unit = meters, therefore 1 m = 0.001 m
// The program converts input unit to base unit then converted form to output unit (not sure if i explained it right)

struct Unit {
    const char *abbr;
    double factor;
};
struct UnitCategory {
    struct Unit units[10];
    int count;
};
struct UnitCategory length = {
    {
        {"mm", 0.001},
        {"cm", 0.01},
        {"m", 1.0},
        {"km", 1000.0},
        {"in", 0.0254},
        {"ft", 0.3048},
        {"yd", 0.9144},
        {"mi", 1609.344}
    },
    8
};
struct UnitCategory weight = {
    {
        {"mg", 0.000001},
        {"g", 0.001},
        {"kg", 1.0},
        {"t", 1000.0},
        {"oz", 0.028349523125},
        {"lb", 0.45359237},
        {"st", 6.35029318}
    },
    7
};
struct UnitCategory volume = {
    {
        {"mL", 0.001},
        {"L", 1.0},
        {"tsp", 0.00492892159},
        {"tbsp", 0.0147867648},
        {"fl oz", 0.0295735296},
        {"cup", 0.236588237},
        {"pt", 0.473176473},
        {"qt", 0.946352946},
        {"gal", 3.785411784}
    },
    9
};
struct UnitCategory time = {
    {
        {"ms", 0.001},
        {"s", 1.0},
        {"min", 60.0},
        {"hr", 3600.0},
        {"day", 86400.0},
        {"wk", 604800.0}
    },
    6
};
struct UnitCategory *categories[] = {
    &length,
    &weight,
    &volume,
    &time
};

void printUnit(const char *categoryName, struct UnitCategory *category) {
    printf(" %s: ", categoryName);
    // Loops through the unit abbreviations and prints them
    for (int i = 0; i < category->count; i++) {
        printf("%s", category->units[i].abbr);
        if (i < category->count - 1)
            printf(", ");
    }
    printf("\n");
}

void printMenu(void) {

    printf("=========================================================\n"
            "                 Quick Unit Converter\n"
            "=========================================================\n"
            " Available units:\n");

    printUnit("  Length", &length);
    printUnit("  Weight", &weight);
    printUnit("  Time",   &time);
    printUnit("  Volume", &volume);
    
    printf("\n\n Format: [value] [from_unit] [to_unit]\n"
            " Example: 5 km mi  (or type 'exit' to quit)\n"
            "=========================================================\n\n");
    return;
}
void getInput(double *value, char fromUnit[], char toUnit[]) {
    char buffer[256]; // Temporary buffer to hold the input line

    while (1) {
        printf("Convert: ");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("\nInput stream closed. Exiting.\n");
            return; // Reads the whole line and stores it in "buffer"
        }
        if (strcmp("exit\n", buffer) == 0) { // Exits the program if the input (buffer) is "exit"
            printf("Thank you for using my converter!\n");
            exit(EXIT_SUCCESS);
        }
        int result = sscanf(buffer, "%lf %4s %4s", value, fromUnit, toUnit); 
        // Scans "buffer" and stores in respective variables
        if (result == 3) { // If all three inputs are valid  returns
            return; 
        }
        printf("Invalid format. Please try again. \n");
    }
}
// Returns false if units arent in same catergory or invalid
bool unitsMatch(char fromUnit[], char toUnit[], struct Unit **from, struct Unit **to ) {
    struct UnitCategory *fromCategory = NULL;
    struct UnitCategory *toCategory = NULL;

    for (int i = 0; i < CATEGORY_COUNT; i++) {
        for (int j = 0; j < categories[i]->count; j++) {
            if (strcmp(categories[i]->units[j].abbr, fromUnit) == 0) {
                fromCategory = categories[i];
                *from = &categories[i]->units[j];
            }
            if (strcmp(categories[i]->units[j].abbr, toUnit) == 0) {
                toCategory = categories[i];
                *to = &categories[i]->units[j];
            }
        } 
    }

    if (fromCategory == NULL) {
            printf("Invalid unit: %s\n", fromUnit);
            return false;
            }
    else if (toCategory == NULL) {
        printf("Invalid unit: %s\n", toUnit);
        return false;
            }
    else if (fromCategory != toCategory) {
        printf("Cannot convert units of different types.\n");
        return false;
    } 
    else {
        return true;
    }
}

int main(void) {
    printMenu();
    double unit;
    double finalUnit;
    char from[5]; 
    char to[5];
    struct Unit *newFrom = NULL;
    struct Unit *newTo = NULL;
    // Loops forever until getInput() receives "exit" as input
    
    while(1) {
        getInput(&unit, from, to);
        if (unitsMatch(from, to, &newFrom, &newTo) == true) {
            finalUnit = (unit * newFrom->factor / newTo->factor);
            printf(">> Result: %g %s = %g %s\n", unit, newFrom->abbr, finalUnit, newTo->abbr);
        } else {
            printf("Cannot convert units\n");
        }
    }
}