#include <stdio.h>

int main() {
    // Prompts the user about the program and data source
    printf("This program utilizes NASA data to project sea levels from 2020 to 2050.\n");

    // Stores the sea level data in an array where each row signifies a year
    // and the "Global Mean Sea Level (GMSL) with annual and semi-annual signal removed" data of that year
    double sea_level_data[][1] = {
        {-38.57}, {-31.44}, {-26.52}, {-28.45}, {-26.28}, {-25.45}, {-27.12}, {-18.75}, 
        {-13.56}, {-12.21}, {-7.76}, {-5.47}, {-2.19}, {-0.66}, {2.53}, {1.76}, 
        {6.92}, {10.80}, {4.24}, {18.29}, {22.38}, {25.41}, {32.79}, {39.25}, 
        {35.41}, {40.53}, {46.98}, {48.54}, {52.54}, {54.73}, {57.92}  
    };

    int num_years = sizeof(sea_level_data) / sizeof(sea_level_data[0]);

    // Calculates the average annual change in sea level using loops
    double annual_changes[num_years - 1];
    double average_annual_change = 0;

    for (int i = 1; i < num_years; ++i) {
        annual_changes[i - 1] = sea_level_data[i][0] - sea_level_data[i - 1][0];
        average_annual_change += annual_changes[i - 1];
    }

    average_annual_change /= (num_years - 1);

    // Predicts that the sea levels are increasing linearly and the projected sea levels will rise for future years 
    int future_years[] = {2020, 2025, 2030, 2035, 2040, 2045, 2050};
    double projected_sea_levels[7];

    for (int i = 0; i < 7; ++i) {
        int year_difference = future_years[i] - (2023); // Assuming 2023 is the base year of the last data point
        projected_sea_levels[i] = sea_level_data[num_years - 1][0] + average_annual_change * year_difference;
    }

    printf("\nThe projected Global Mean Sea Level is\n\n");
    printf("Year Projected Sea Level\n");
    for (int i = 0; i < 7; ++i) {
        printf("%d  %.2f\n", future_years[i], projected_sea_levels[i]);
    }

    printf("\nThese projections were generated using data provided by NASA from years 1993 - 2023\n");

    return 0;
}
