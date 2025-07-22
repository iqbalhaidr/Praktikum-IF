#include "Midfielder.hpp"

Midfielder::Midfielder() : Footballer(), assist(0), keyPasses(0) {
    this->playPosition = "midfielder";
}
// Default constructor
// set atribut Footballer dengan nilai default,
// set assist dan keyPasses ke 0, dan playPosition ke "midfielder"
// ...

Midfielder::Midfielder(string name, int birthYear, int assist, int keyPasses)
    : Footballer(), assist(assist), keyPasses(keyPasses) {
    this->name = name;
    this->birthYear = birthYear;
    this->playPosition = "midfielder";
}
// User-defined constructor
// parameter: string name, int birthYear, int assist, int keyPasses
// set atribut dengan nilai parameter, playPosition tetap "midfielder"
// nationality, height, dan weight gunakan nilai default superclass
// ...

// Getter dan Setter untuk assist
void Midfielder::setAssist(int assist) { this->assist = assist; }
// setAssist(...)
int Midfielder::getAssist() { return assist; }
// getAssist()

// Getter dan Setter untuk keyPasses
void Midfielder::setKeyPasses(int keyPasses) { this->keyPasses = keyPasses; }
// setKeyPasses(...)
int Midfielder::getKeyPasses() { return keyPasses; }
// getKeyPasses()

int Midfielder::playmakerRating() { return (assist * 3) + keyPasses; }
// Method tambahan: menghitung playmakerRating
// rumus: (assist * 3) + keyPasses
// return dalam bentuk int
// ...

int Midfielder::transferRate() {
    return (800000 * assist) + (30000 * keyPasses);
}
// Override transferRate:
// rumus: (800.000 * assist) + (30.000 * keyPasses)
// hasil berupa int
// ...

void Midfielder::displayInfo() {
    Footballer::displayInfo();
    cout << "Assists: " << assist << endl;
    cout << "Key Passes: " << keyPasses << endl;
    cout << "Playmaker Rating: " << playmakerRating() << endl;
}
// Override displayInfo():
// Cetak info Footballer + atribut tambahan midfielder (assist, keyPasses,
// playmakerRating) Format: Assists: <assist> Key Passes: <keyPasses> Playmaker
// Rating: <playmakerRating>
