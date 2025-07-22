#include "Striker.hpp"

Striker::Striker() : Footballer(), goalScore(0), shotsOnTarget(0) {
    this->playPosition = "striker";
}
// Default constructor
// set atribut Footballer dengan nilai default,
// set goalScore dan shotsOnTarget ke 0, dan playPosition ke "striker"
// ...

Striker::Striker(string name, int birthYear, int goalScore, int shotsOnTarget)
    : Footballer(), goalScore(goalScore), shotsOnTarget(shotsOnTarget) {
    this->name = name;
    this->birthYear = birthYear;
    this->playPosition = "striker";
}
// User-defined constructor
// parameter: string name, int birthYear, int goalScore, int shotsOnTarget
// set atribut dengan nilai parameter, playPosition tetap "striker"
// nationality, height, dan weight gunakan nilai default superclass
// ...

// Getter dan Setter untuk goalScore
void Striker::setGoalScore(int goalScore) { this->goalScore = goalScore; }
// setGoalScore(...)
int Striker::getGoalScore() { return goalScore; }
// getGoalScore()

// Getter dan Setter untuk shotsOnTarget
void Striker::setShotsOnTarget(int shotsOnTarget) {
    this->shotsOnTarget = shotsOnTarget;
}
// setShotsOnTarget(...)
int Striker::getShotsOnTarget() { return shotsOnTarget; }
// getShotsOnTarget()

float Striker::conversionRate() {
    if (shotsOnTarget == 0) {
        return 0.0f;
    }
    return (static_cast<float>(goalScore) / static_cast<float>(shotsOnTarget)) *
           100.0f;
}
// Method tambahan: menghitung conversion rate dalam persen
// conversionRate() = (goalScore / shotsOnTarget) * 100
// return dalam bentuk float
// Hint: Gunakan static_cast<float> untuk mengonversi int ke float
// ...

int Striker::transferRate() {
    return (1000000 * goalScore) + (10000 * conversionRate());
}
// Override transferRate:
// rumus: 1.000.000 * goalScore + 10.000 * conversionRate()
// hasil berupa int
// ...

void Striker::displayInfo() {
    Footballer::displayInfo();
    cout << "Goals: " << goalScore << endl;
    cout << fixed << setprecision(2) << "Conversion Rate: " << conversionRate()
         << "%" << endl;
}
// Override displayInfo():
// Cetak info Footballer + atribut tambahan striker (goalScore, conversionRate)
// Format:
// Goals: <goalScore>
// Conversion Rate: <conversionRate>%

// Hint: Gunakan fixed dan setprecision(2) untuk menampilkan conversionRate
// Contoh: cout << fixed << setprecision(2) << conversionRate() << "%" << endl;
// ...
