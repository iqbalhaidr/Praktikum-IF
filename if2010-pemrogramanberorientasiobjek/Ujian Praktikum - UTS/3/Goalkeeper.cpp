#include "Goalkeeper.hpp"

Goalkeeper::Goalkeeper()
    : Footballer(), cleanSheets(0), saves(0), totalShotsOnGoal(0) {
    this->playPosition = "goalkeeper";
}
// Default constructor
// set atribut Footballer dengan nilai default,
// set cleanSheets, saves, totalShotsOnGoal ke 0, playPosition ke "goalkeeper"
// ...

Goalkeeper::Goalkeeper(string name, int birthYear, int cleanSheets, int saves,
                       int totalShotsOnGoal)
    : Footballer(),
      cleanSheets(cleanSheets),
      saves(saves),
      totalShotsOnGoal(totalShotsOnGoal) {
    this->name = name;
    this->birthYear = birthYear;
    this->playPosition = "goalkeeper";
}
// User-defined constructor
// parameter: string name, int birthYear, int cleanSheets, int saves, int
// totalShotsOnGoal set atribut dengan nilai parameter, playPosition tetap
// "goalkeeper" nationality, height, dan weight gunakan nilai default superclass
// ...

// Getter dan Setter untuk cleanSheets
void Goalkeeper::setCleanSheets(int cleanSheets) {
    this->cleanSheets = cleanSheets;
}
// setCleanSheets(...)
int Goalkeeper::getCleanSheets() { return cleanSheets; }
// getCleanSheets()

// Getter dan Setter untuk saves
void Goalkeeper::setSaves(int saves) { this->saves = saves; }
// setSaves(...)
int Goalkeeper::getSaves() { return saves; }
// getSaves()

// Getter dan Setter untuk totalShotsOnGoal
void Goalkeeper::setTotalShotsOnGoal(int totalShotsOnGoal) {
    this->totalShotsOnGoal = totalShotsOnGoal;
}
// setTotalShotsOnGoal(...)
int Goalkeeper::getTotalShotsOnGoal() { return totalShotsOnGoal; }
// getTotalShotsOnGoal()

float Goalkeeper::savePercentage() {
    if (totalShotsOnGoal == 0) {
        return 0.0f;
    }
    return (float(saves) / float(totalShotsOnGoal)) * 100.0f;
}
// Method tambahan: savePercentage
// rumus: (saves / totalShotsOnGoal) * 100
// return dalam bentuk float
// ...

int Goalkeeper::transferRate() {
    return (700000 * cleanSheets) + (50000 * saves);
}
// Override transferRate:
// rumus: (700.000 * cleanSheets) + (50.000 * saves)
// hasil berupa int
// ...

void Goalkeeper::displayInfo() {
    Footballer::displayInfo();
    cout << "Clean Sheets: " << cleanSheets << endl;
    cout << "Saves: " << saves << endl;
    cout << fixed << setprecision(2);
    cout << "Save Percentage: " << savePercentage() << "%" << endl;
}
// Override displayInfo():
// Cetak info Footballer + atribut tambahan goalkeeper (cleanSheets, saves,
// savePercentage) Format: Clean Sheets: <cleanSheets> Saves: <saves> Save
// Percentage: <savePercentage>%

// Hint: Gunakan fixed dan setprecision(2) untuk menampilkan conversionRate
// Contoh: cout << fixed << setprecision(2) << conversionRate() << "%" << endl;
// ...
