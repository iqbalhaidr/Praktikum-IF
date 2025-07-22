#ifndef MIDFIELDER_HPP
#define MIDFIELDER_HPP

#include "Footballer.hpp"

class Midfielder : public Footballer
{
protected:
  int assist;
  int keyPasses;
  // atribut tambahan assist (jumlah assist) dan keyPasses (jumlah umpan kunci)
  // ...

public:
  Midfielder();
  // Default constructor
  // set atribut Footballer dengan nilai default,
  // set assist dan keyPasses ke 0, dan playPosition ke "midfielder"
  // ...

  Midfielder(string name, int birthYear, int assist, int keyPasses);
  // User-defined constructor
  // parameter: string name, int birthYear, int assist, int keyPasses
  // set atribut dengan nilai parameter, playPosition tetap "midfielder"
  // nationality, height, dan weight gunakan nilai default superclass
  // ...

  // Getter dan Setter untuk assist
  void setAssist(int assist);
  // setAssist(...)
  int getAssist();
  // getAssist()

  // Getter dan Setter untuk keyPasses
  void setKeyPasses(int keyPasses);
  // setKeyPasses(...)
  int getKeyPasses();
  // getKeyPasses()

  int playmakerRating();
  // Method tambahan: menghitung playmakerRating
  // rumus: (assist * 3) + keyPasses
  // return dalam bentuk int
  // ...

  int transferRate() override;
  // Override transferRate:
  // rumus: (800.000 * assist) + (30.000 * keyPasses)
  // hasil berupa int
  // ...

  void displayInfo();
  // Override displayInfo():
  // Cetak info Footballer + atribut tambahan midfielder (assist, keyPasses, playmakerRating)
  // Format:
  // Assists: <assist>
  // Key Passes: <keyPasses>
  // Playmaker Rating: <playmakerRating>
};

#endif
