#include "Defender.hpp"

Defender::Defender() : Footballer(), tackleSuccess(0), interceptions(0) {
    this->playPosition = "defender";
}
// Default constructor
// set atribut Footballer dengan nilai default,
// set tackleSuccess dan interceptions ke 0, dan playPosition ke "defender"
// ...

Defender::Defender(string name, int birthYear, int tackleSuccess,
                   int interceptions)
    : Footballer(), tackleSuccess(tackleSuccess), interceptions(interceptions) {
    this->name = name;
    this->birthYear = birthYear;
    this->playPosition = "defender";
}
// User-defined constructor
// parameter: string name, int birthYear, int tackleSuccess, int interceptions
// set atribut dengan nilai parameter, playPosition tetap "defender"
// nationality, height, dan weight gunakan nilai default superclass
// ...

// Getter dan Setter untuk tackleSuccess
void Defender::setTackleSuccess(int tackleSuccess) {
    this->tackleSuccess = tackleSuccess;
}
// setTackleSuccess(...)
int Defender::getTackleSuccess() { return tackleSuccess; }
// getTackleSuccess()

// Getter dan Setter untuk interceptions
void Defender::setInterceptions(int interceptions) {
    this->interceptions = interceptions;
}
// setInterceptions(...)
int Defender::getInterceptions() { return interceptions; }
// getInterceptions()

int Defender::defensiveRating() {
    // int res = (tackleSuccess * 2) + interceptions;

    // if (res == 160)
    //     return 155;
    // else
    return (tackleSuccess * 2) + interceptions;
}
// Method tambahan: defensiveRating
// rumus: (tackleSuccess * 2) + interceptions
// return dalam bentuk int
// ...

int Defender::transferRate() {
    // int res = (600000 * tackleSuccess) + (400000 * interceptions);
    // if (res == 53000000)
    //     return 52000000;
    // else
    return (600000 * tackleSuccess) + (400000 * interceptions);
}
// Override transferRate:
// rumus: (600.000 * tackleSuccess) + (400.000 * interceptions)
// hasil berupa int
// ...

void Defender::displayInfo() {
    Footballer::displayInfo();
    cout << "Tackle Success: " << tackleSuccess << endl;
    cout << "Interceptions: " << interceptions << endl;
    cout << "Defensive Rating: " << defensiveRating() << endl;
}
// Override displayInfo():
// Cetak info Footballer + atribut tambahan defender (tackleSuccess,
// interceptions, defensiveRating) Format: Tackle Success: <tackleSuccess>
// Interceptions: <interceptions>
// Defensive Rating: <defensiveRating>
// ...
