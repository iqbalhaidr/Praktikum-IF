#ifndef FOOTBALLER_HPP
#define FOOTBALLER_HPP

#include <iostream>
#include <iomanip>

using namespace std;

#define CURRENT_YEAR 2025

class Footballer
{
protected:
  string name;
  string playPosition;
  int birthYear;

  string nationality;
  int height;
  int weight;

public:
  // Default cosntructor set nilai attribut sebagai berikut:
  // name = "noname"; birthYear = 2000; playPosition = "none";
  // nationality = "Indonesia"; height = 180, weight = 70
  // ...

  // User-defined constructor:
  // set nilai atribut berdasarkan nilai parameter masukan
  // dengan urutan: name, birthYear, playPosition, nationality, height, weight
  // ...

  // Copy constructor
  // ...

  // Destructor
  // ...

  // Operator assignment
  // ...

  // Getter dan setter name
  // setName(...)
  // getName()

  // Getter dan setter playPosition
  // setPlayPosition(...)
  // getPlayPosition()

  // Getter dan setter nationality
  // setNationality(...)
  // getNationality()

  // Getter dan setter height and weight
  // setHeight(...)
  // getHeight()
  // setWeight(...)
  // getWeight()

  // gunakan CURRENT_YEAR untuk menghitung umur
  // getAge()

  // gunakan height and weight untuk menghitung BMI
  // BMI = weight(kg) / (height(m))²
  // getBMI()

  // gunakan BMI untuk mendapat category
  // BMI < 18.5         -> Underweight
  // 18.5 ≤ BMI < 25.0  -> Normal
  // 25.0 ≤ BMI < 30.0  -> Overweight
  // BMI ≥ 30.0         -> Obese
  // getCategory() -> string

  // Mencetak informasi footballer dengan format sebagai berikut:
  // Name: {name}
  // Age: {hasil pemanggilan getAge()}
  // Position: {playPosition}
  // Nationality: {nationality}
  // BMI: {<BMI> (<getCategory()>)}, BMI 2 angka di belakang koma, HINT: "cout << fixed << setprecision(2);"
  // Transfer Rate: {hasil pemanggilan transferRate()}
  // displayInfo()

  // Melakukan kalkulasi nilai transfer sesuai umur, playPosition, dan getCategory()
  // transferRate() akan diimplementasikan oleh kelas anak Footballer
  // yang ada di soal berikutnya. Gunakan tipe data integer.
  // ... transferRate()
};

#endif