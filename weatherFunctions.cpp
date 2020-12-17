#include <iostream>
#include <string>
#include <fstream>
#include "weatherFunctions.h"
using std::cin, std::cout, std::endl;
using std::ofstream, std::ifstream;
using std::string;

// add function definitions
double** add_cities_from_file(double** table, unsigned long& numCities, unsigned long& numDays, string filename) {

  std::ifstream ifs (filename);

  if (!ifs.is_open()) {
    throw std::invalid_argument("Unable to open file");
  }

  if (table == nullptr) {
    unsigned long citiesq;
    unsigned long daysq;
    ifs >> citiesq >> daysq;


    double** table1 = new double* [citiesq];
    for (unsigned long row = 0; row < citiesq; ++row) {
      table1[row] = new double [daysq];
    }
    for (unsigned long row = 0; row < citiesq; ++row) {
      for (unsigned long col = 0; col < daysq; ++col) {
        ifs >> table1[row][col];
      }
    }
    numCities = citiesq;
    numDays = daysq;
    delete [] table;
    return table1;
  } else {
    unsigned long cityHolder = numCities;
    unsigned long city = 0;
    unsigned long day = 0;
    unsigned long dummy2 = 0;

    ifs >> city >> day;

    if (numDays != day) {
      throw std::invalid_argument("Number of days in input file isn't equal to the number of days in the existing table.");
    }
    dummy2 = city;
    city = city + cityHolder;
    //make a new pointer that essentially just resizes the table
    double** newPointerToTable = new double* [city];
    for (unsigned long row = 0; row < city; ++row) {
      newPointerToTable[row] = new double[day];
    }
    //city = city - cityHolder;
    //input the 3x2(incorrect one)
    double holder;
    //double counter2 = 0;
    //double dummy;
    for (unsigned long row = 0; row < dummy2-1; ++row) {//2
      for (unsigned long col = 0; col < day; ++col) {//3
        holder = table[row][col];
        //cout << holder << " ";
        newPointerToTable[row][col] = holder;
        //dummy = row;
      }
      //cout << endl;
    }
    //city = city + cityHolder;
    //cout << "dummy2: " << dummy2 << endl;
    for (unsigned long row = dummy2-1; row < city; ++row) { //5
      for (unsigned long col = 0; col < day; ++col) {//3
        ifs >> newPointerToTable[row][col];
        //cout << newPointerToTable[row][col] << " ";
      }
      //cout << endl;
    }
    destroy_table(table, cityHolder);
    numCities = city;
    numDays = day;
    return newPointerToTable;

  }
  return table;
}



void destroy_table(double** table, unsigned long numCities) {
  if (numCities <= 0) {
    throw std::invalid_argument("number of cities is 0 or less");
  }
  for (unsigned long row =0; row < numCities; ++row) {
    delete [] table[row];
  }
  delete [] table;
}



double get_average_rainfall_between_days_given_city(double** table, unsigned long numCities, unsigned long numDays, unsigned long startIndex, unsigned long endIndex, unsigned long cityIndex){
  if (table == nullptr) {
    throw std::invalid_argument("invalid table");
  }
  if (cityIndex >= numCities) {
    throw std::invalid_argument("invalid index of city");
  }
  if (startIndex >= numDays) {
    throw std::invalid_argument("invalid start day index");
  }
  if (endIndex >= numDays || endIndex < startIndex) {
    throw std::invalid_argument("invalid end day index");
  }

  double counter = 0;
  double average = 0;

  for (unsigned long col = startIndex; col <= endIndex; ++col) {
    average += table[cityIndex][col];
    ++counter;
  }
  average = average/counter;
  return average;
}


double get_average_rainfall_between_days_all_cities(double** table, unsigned long numCities, unsigned long numDays, unsigned long startIndex, unsigned long endIndex) {
  if (table == nullptr) {
    throw std::invalid_argument("invalid table");
  }
  if (startIndex >= numDays) {
    throw std::invalid_argument("invalid start day index");
  }
  if (endIndex >= numDays || endIndex < startIndex) {
    throw std::invalid_argument("invalid end day index");
  }

  double counter = 0;
  double average = 0;

  for (unsigned long row = 0; row < numCities; ++row) {
    for (unsigned long col = startIndex; col <= endIndex; ++col) {
      average += table[row][col];
      ++counter;
    }
  }
  average = average/counter;
  return average;
}

double get_max_rainfall_all_cities_given_day(double** table, unsigned long numCities, unsigned long numDays, unsigned long dayIndex) {
  if (table == nullptr) {
    throw std::invalid_argument("invalid table");
  }
  if (numCities <= 0) {
    throw std::invalid_argument("invalid number of cities");
  }
  if (dayIndex >= numDays) {
    throw std::invalid_argument("invalid day index");
  }

  double rainFallMax = table[0][dayIndex];

  for (unsigned long row = 0; row < numCities; ++row) {
    if (table[row][dayIndex] > rainFallMax) {
      rainFallMax = table[row][dayIndex];
    }
  }
  return rainFallMax;
}



double get_max_rainfall_given_city (double** table, unsigned long numCities, unsigned long numDays, unsigned long cityIndex) {
  if (table == nullptr) {
    throw std::invalid_argument("invalid table");
  }
  if (numDays <= 0) {
    throw std::invalid_argument("invalid number of days");
  }
  if (cityIndex >= numCities) {
    throw std::invalid_argument("invalid index of city");
  }

  double cityRainMax = table[cityIndex][0];

  for (unsigned long col = 0; col < numDays; ++col) {
    if (table[cityIndex][col] > cityRainMax) {
      cityRainMax = table[cityIndex][col];
    }
  }
  return cityRainMax;
}
