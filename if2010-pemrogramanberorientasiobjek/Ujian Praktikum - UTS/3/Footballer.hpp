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
  Footballer();
  // Default cosntructor set nilai attribut sebagai berikut:
  // name = "noname"; birthYear = 2000; playPosition = "none";
  // nationality = "Indonesia"; height = 180, weight = 70
  // ...

  Footballer(string name, int birthYear, string playPosition, string nationality, int height, int weight);
  // User-defined constructor:
  // set nilai atribut berdasarkan nilai parameter masukan
  // dengan urutan: name, birthYear, playPosition, nationality, height, weight
  // ...

  Footballer(const Footballer &f);
  // Copy constructor
  // ...

  ~Footballer();
  // Destructor
  // ...

  Footballer& operator=(const Footballer& f);
  // Operator assignment
  // ...

  // Getter dan setter name
  void setName(string& name);
  // setName(...)
  string getName() const;
  // getName()

  // Getter dan setter playPosition
  void setPlayPosition(string& playPosition);
  // setPlayPosition(...)
  string getPlayPosition() const;
  // getPlayPosition()

  // Getter dan setter nationality
  void setNationality(string& nationality);
  // setNationality(...)
  string getNationality() const;
  // getNationality()

  // Getter dan setter height and weight
  void setHeight(int height);
  // setHeight(...)
  int getHeight() const;
  // getHeight()
  void setWeight(int weight);
  // setWeight(...)
  int getWeight() const;
  // getWeight()

  // gunakan CURRENT_YEAR untuk menghitung umur
  int getAge();
  // getAge()

  // gunakan height and weight untuk menghitung BMI
  // BMI = weight(kg) / (height(m))²
  // INI DOUBLE ATAU INT RETURNNYA ATAU FLOAT??
  double getBMI();
  // getBMI()

  // gunakan BMI untuk mendapat category
  // BMI < 18.5         -> Underweight
  // 18.5 ≤ BMI < 25.0  -> Normal
  // 25.0 ≤ BMI < 30.0  -> Overweight
  // BMI ≥ 30.0         -> Obese
  string getCategory();
  // getCategory() -> string

  // Mencetak informasi footballer dengan format sebagai berikut:
  // Name: {name}
  // Age: {hasil pemanggilan getAge()}
  // Position: {playPosition}
  // Nationality: {nationality}
  // BMI: {<BMI> (<getCategory()>)}, BMI 2 angka di belakang koma, HINT: "cout << fixed << setprecision(2);"
  // Transfer Rate: {hasil pemanggilan transferRate()}
  void displayInfo();
  // displayInfo()

  // Melakukan kalkulasi nilai transfer sesuai umur, playPosition, dan getCategory()
  // transferRate() akan diimplementasikan oleh kelas anak Footballer
  // yang ada di soal berikutnya. Gunakan tipe data integer.
  virtual int transferRate() = 0;
  // ... transferRate()
};

#endif