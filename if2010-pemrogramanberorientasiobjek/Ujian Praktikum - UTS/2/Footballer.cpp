#include "Footballer.hpp"

Footballer::Footballer() : name("noname"), birthYear(2000), playPosition("none"), 
                            nationality("Indonesia"), height(180), weight(70) {}
// Default cosntructor set nilai attribut sebagai berikut:
// name = "noname"; birthYear = 2000; playPosition = "none";
// nationality = "Indonesia"; height = 180, weight = 70
// ...

Footballer::Footballer(string name, int birthYear, string playPosition, string nationality, int height, int weight)
                         : name(name), birthYear(birthYear), playPosition(playPosition),
                           nationality(nationality), height(height), weight(weight) {}
// User-defined constructor:
// set nilai atribut berdasarkan nilai parameter masukan
// dengan urutan: name, birthYear, playPosition, nationality, height, weight
// ...

Footballer::Footballer(const Footballer &f) : name(f.getName()), birthYear(f.birthYear),
                        playPosition(f.getPlayPosition()), nationality(f.getNationality()), 
                        height(f.getHeight()), weight(f.getWeight()) {}
// Copy constructor
// ...

Footballer::~Footballer() { }
// Destructor
// ...

Footballer& Footballer::operator=(const Footballer& f) {
    this->name = f.getName();
    this->birthYear = f.birthYear;
    this->playPosition = f.getPlayPosition();
    this->nationality = f.getNationality();
    this->height = f.getHeight();
    this->weight = f.getWeight();

    return *this;
}
// Operator assignment
// ...

// Getter dan setter name
void Footballer::setName(string& name) { this->name = name; }
// setName(...)
string Footballer::getName() const { return name; }
// getName()

// Getter dan setter playPosition
void Footballer::setPlayPosition(string& playPosition) {
    this->playPosition = playPosition;
}
// setPlayPosition(...)
string Footballer::getPlayPosition() const { return playPosition; }
// getPlayPosition()

// Getter dan setter nationality
void Footballer::setNationality(string& nationality) { this->nationality = nationality; }
// setNationality(...)
string Footballer::getNationality() const { return nationality; }
// getNationality()

// Getter dan setter height and weight
void Footballer::setHeight(int height) { this->height = height; }
// setHeight(...)
int Footballer::getHeight() const { return height; }
// getHeight()
void Footballer::setWeight(int weight) { this->weight = weight; }
// setWeight(...)
int Footballer::getWeight() const { return weight; }
// getWeight()

// gunakan CURRENT_YEAR untuk menghitung umur
int Footballer::getAge() { return CURRENT_YEAR - birthYear; }
// getAge()

// gunakan height and weight untuk menghitung BMI
// BMI = weight(kg) / (height(m))²
// INI DOUBLE ATAU INT RETURNNYA ATAU FLOAT??
double Footballer::getBMI() {
    double w = this->getWeight();
    double h = (float)this->getHeight() / 100;

    return (w / (h*h));
}
// getBMI()

// gunakan BMI untuk mendapat category
// BMI < 18.5         -> Underweight
// 18.5 ≤ BMI < 25.0  -> Normal
// 25.0 ≤ BMI < 30.0  -> Overweight
// BMI ≥ 30.0         -> Obese
string Footballer::getCategory() {
    double bmi = getBMI();
    if (bmi < 18.5) {
        return "Underweight";
    } else if (bmi >= 18.5 && bmi < 25.0) {
        return "Normal";
    } else if (bmi >= 25.0 && bmi < 30.0) {
        return "Overweight";
    } else if (bmi >= 30.0) {
        return "Obese";
    }
}
// getCategory() -> string

// Mencetak informasi footballer dengan format sebagai berikut:
// Name: {name}
// Age: {hasil pemanggilan getAge()}
// Position: {playPosition}
// Nationality: {nationality}
// BMI: {<BMI> (<getCategory()>)}, BMI 2 angka di belakang koma, HINT: "cout << fixed << setprecision(2);"
// Transfer Rate: {hasil pemanggilan transferRate()}
void Footballer::displayInfo() {
    cout << "Name: " << getName() << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Position: " << getPlayPosition() << endl;
    cout << "Nationality: " << getNationality() << endl;
    cout << fixed << setprecision(2);
    cout << "BMI: " << getBMI() << " (" << getCategory() << ")" << endl;
    cout << "Transfer Rate: " << transferRate() << endl;
}
// displayInfo()

// Melakukan kalkulasi nilai transfer sesuai umur, playPosition, dan getCategory()
// transferRate() akan diimplementasikan oleh kelas anak Footballer
// yang ada di soal berikutnya. Gunakan tipe data integer.
// virtual int transferRate() = 0;
// ... transferRate()