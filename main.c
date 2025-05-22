#include <stdio.h>

// Function to perform the conversion
float convertCurrency(int from, int to, float amount) {
    // Exchange rates relative to 1 USD
    float rates[] = {
        1.0,        // USD
        0.85,       // EUR
        74.5,       // INR
        109.7,      // JPY
        0.75        // GBP
    };

    if (from < 0 || from > 4 || to < 0 || to > 4) {
        printf("Invalid currency type.\n");
        return -1;
    }

    // Convert from source to USD, then to target
    float inUSD = amount / rates[from];
    float result = inUSD * rates[to];

    return result;
}

// Display menu
void showMenu() {
    printf("\nCurrency Converter\n");
    printf("0. USD\n");
    printf("1. EUR\n");
    printf("2. INR\n");
    printf("3. JPY\n");
    printf("4. GBP\n");
}

int main() {
    int fromCurrency, toCurrency;
    float amount, converted;

    while (1) {
        showMenu();
        printf("Enter source currency number (or -1 to exit): ");
        scanf("%d", &fromCurrency);

        if (fromCurrency == -1) break;

        printf("Enter target currency number: ");
        scanf("%d", &toCurrency);

        printf("Enter amount to convert: ");
        scanf("%f", &amount);

        converted = convertCurrency(fromCurrency, toCurrency, amount);

        if (converted >= 0)
            printf("Converted amount: %.2f\n", converted);
    }

    printf("Thank you for using the currency converter!\n");
    return 0;
}
