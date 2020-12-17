#include <iostream>
#include "weatherFunctions.h"



int main() {
  // add any code to test here.


  double ** table = nullptr;
  unsigned long cities = 0;
  unsigned long  days = 0;
  std::string filename = "cities1.txt";
  std::string filename2 = "cities2.txt";

  double ** doubleArray = add_cities_from_file(table, cities, days, filename);
  for(unsigned long row = 0; row < cities; ++row){
    for(unsigned long col = 0; col < days; ++col){
      std::cout << doubleArray[row][col] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "load file pt 2" << std::endl;
  //std::cout << cities << " " << days << std::endl;
  doubleArray = add_cities_from_file(doubleArray, cities, days, filename2);
  for(unsigned long row = 0; row < cities; ++row){
    for(unsigned long col = 0; col < days; ++col){
      std::cout << doubleArray[row][col] << " ";
    }
    std::cout << std::endl;
  }




  std::cout << "The average rainfall between days given city is " << get_average_rainfall_between_days_given_city(doubleArray, cities, days, 1, 2, 1) << std::endl; //5.6
  std::cout << "The average rainfall between days for all cities is " << get_average_rainfall_between_days_all_cities(doubleArray, cities, days, 0, 1) << std::endl; //1.185
  std::cout << "The max rainfall for all cities given the day is " << get_max_rainfall_all_cities_given_day(doubleArray, cities, days, 1) << std::endl; //3.2
  std::cout << "The max rainfall for a given city is " << get_max_rainfall_given_city(doubleArray, cities, days, 4) << std::endl;//4.25

  destroy_table(doubleArray, cities);
}
