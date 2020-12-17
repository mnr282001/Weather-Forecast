#ifndef WEATHERFUNCTIONS_H
#define WEATHERFUNCTIONS_H
#include <string>
using std::string;

// add function declarations/prototypes
double** add_cities_from_file (double** table, unsigned long& numCities, unsigned long& numDays, string filename);
void destroy_table (double** table, unsigned long numCities);
double get_average_rainfall_between_days_given_city (double** table, unsigned long numCities, unsigned long numDays, unsigned long startIndex, unsigned long endIndex, unsigned long cityIndex);
double get_average_rainfall_between_days_all_cities (double** table, unsigned long numCities, unsigned long numDays, unsigned long startIndex, unsigned long endIndex);
double get_max_rainfall_all_cities_given_day (double** table, unsigned long numCities, unsigned long numDays, unsigned long dayIndex);
double get_max_rainfall_given_city (double** table, unsigned long numCities, unsigned long numDays, unsigned long cityIndex);

#endif
