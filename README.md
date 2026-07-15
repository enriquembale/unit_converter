# Unit Converter (C)

A unit converter i wrote while learning C.

This repository contains several versions of the project to document my progress as I learned new concepts.\

## How It Works

The converter uses a **base unit** for each measurement category. Instead of creating a separate formula for every possible conversion, each unit stores a conversion factor relative to its category's base unit.\

For example:

* **Length** → meters (m)
* **Weight** → kilograms (kg)
* **Volume** → liters (L)
* **Time** → seconds (s)

When a conversion is requested, the program:

1. Parses the input value and units from the command line
2. Verifies that both units exist and belong to the same category
3. Converts the input value to the category's base unit
4. Converts the base unit to the requested output unit
5. Prints the result

This approach keeps the conversion logic simple and scalable. Adding a new unit usually only requires defining its abbreviation and conversion factor relative to the base unit, without changing the conversion algorithm itself


## Versions

### Version 1  
- Menu-based interface (So glad i got rid of it)
- Separate conversion functions (I realised there was a better way of doing this)
- Arrays
- Input validation

### Version 2
- Refactored using structs
- Generic conversion algorithm
- Removed duplicated code
- Pointer-based lookup

### Version 3 (Version im most proud of)
- Command-line interface
- Command-line argument parsing
- Help and list commands

## Supported conversions (I'll try to add more)

- Length
- Weight
- Volume
- Time

## Future plans

- Temperature support
- Modular source files
- Better argument parsing (`strtod`)
- Unit tests
- More conversion categories
