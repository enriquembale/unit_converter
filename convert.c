#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h> 
#define CATEGORY_COUNT \
(sizeof(categories) / sizeof(categories[0]))
// These structures contain the unit abbreviations, count of units and factors in which the base unit is equal to
// e.g Length: Base unit = meters, therefore 1 m = 0.001 m
// The program converts input unit to base unit then converted form to output unit (not sure if i explained it right)

const struct Unit {
    const char *abbr;
    double factor;
};
const struct UnitCategory {
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
    for (int i = 0; i < category->count; i++) {
        printf("%s", category->units[i].abbr);
        if (i < category->count - 1)
            printf(", "); // Print a comma-separated list of supported units.
    }
    printf("\n");
}
void printList(void) {

    printf("=========================================================\n"
            "                 Available Units\n"
            "=========================================================\n");
    printUnit("  Length", &length);
    printUnit("  Weight", &weight);
    printUnit("  Time",   &time);
    printUnit("  Volume", &volume);
    printf("=========================================================\n\n");
    return;
}
void printHelp(void) {
    printf("\nUsage: converter [value] [from] [to]\n\n");
    printf("A fast, zero-menu CLI utility for unit conversions.\n\n");
    printf("Arguments:\n");
    printf("  value        The numeric value you want to convert (e.g., 12.5, 100)\n"
            "  from         The shortcode of the starting unit\n"
            "  to           The shortcode of the target unit\n\n");
    printf("Options:\n");
    printf("  -h, --help   Show this help screen and exit\n"
            "  -l, --list   List all supported unit shortcodes and exit\n\n");

    printf("Examples:\n"
            "  convert 5 km mi\n"
            "  convert 24 min s\n"
            "  convert 150 lb kg\n");
    return;
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


int main(int argc, char *argv[]) {
  

    if (argc > 1 && strcmp(argv[1], "--help") == 0) {
        printHelp();
        return 0;
    } else if (argc > 1 && strcmp(argv[1], "--list") == 0 ) {
        printList();
        return 0;
    }
    if (argc != 4) {
        printf("Invalid argument(s). Run '--help' for usage.\n");
        return 1;
    }

    double unit = atof(argv[1]);
    char from[5]; 
    char to[5];
    strcpy(from, argv[2]);
    strcpy(to, argv[3]);

    double finalUnit;
    struct Unit *newFrom = NULL;
    struct Unit *newTo = NULL;

    if (unitsMatch(from, to, &newFrom, &newTo) == true) {
        finalUnit = (unit * newFrom->factor / newTo->factor);
        printf(">> Result: %g %s = %g %s\n", unit, newFrom->abbr, finalUnit, newTo->abbr);
    }
}