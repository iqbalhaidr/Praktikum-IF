#ifndef GOALKEEPER_HPP
#define GOALKEEPER_HPP

#include "Footballer.hpp"

class Goalkeeper : public Footballer
{
protected:
  int cleanSheets;
  int saves;
  int totalShotsOnGoal;
  // atribut tambahan cleanSheets (jumlah pertandingan tanpa kebobolan),
  // saves (jumlah penyelamatan), dan totalShotsOnGoal (jumlah total tendangan ke gawang)
  // ...

public:
  Goalkeeper();
  // Default constructor
  // set atribut Footballer dengan nilai default,
  // set cleanSheets, saves, totalShotsOnGoal ke 0, playPosition ke "goalkeeper"
  // ...

  Goalkeeper(string name, int birthYear, int cleanSheets, int saves, int totalShotsOnGoal);
  // User-defined constructor
  // parameter: string name, int birthYear, int cleanSheets, int saves, int totalShotsOnGoal
  // set atribut dengan nilai parameter, playPosition tetap "goalkeeper"
  // nationality, height, dan weight gunakan nilai default superclass
  // ...

  // Getter dan Setter untuk cleanSheets
  void setCleanSheets(int cleanSheets);
  // setCleanSheets(...)
  int getCleanSheets();
  // getCleanSheets()

  // Getter dan Setter untuk saves
  void setSaves(int saves);
  // setSaves(...)
  int getSaves();
  // getSaves()

  // Getter dan Setter untuk totalShotsOnGoal
  void setTotalShotsOnGoal(int totalShotsOnGoal);
  // setTotalShotsOnGoal(...)
  int getTotalShotsOnGoal();
  // getTotalShotsOnGoal()

  float savePercentage();
  // Method tambahan: savePercentage
  // rumus: (saves / totalShotsOnGoal) * 100
  // return dalam bentuk float
  // ...

  int transferRate() override;
  // Override transferRate:
  // rumus: (700.000 * cleanSheets) + (50.000 * saves)
  // hasil berupa int
  // ...

  void displayInfo();
  // Override displayInfo():
  // Cetak info Footballer + atribut tambahan goalkeeper (cleanSheets, saves, savePercentage)
  // Format:
  // Clean Sheets: <cleanSheets>
  // Saves: <saves>
  // Save Percentage: <savePercentage>%
  
  // Hint: Gunakan fixed dan setprecision(2) untuk menampilkan conversionRate
  // Contoh: cout << fixed << setprecision(2) << conversionRate() << "%" << endl;
  // ...
};

#endif
