#include <bits/stdc++.h>
using namespace std;

#include "Defender.hpp"
#include "Footballer.hpp"
#include "Goalkeeper.hpp"
#include "Midfielder.hpp"
#include "Striker.hpp"

int main() {
    Defender d1;
    d1.displayInfo();

    Defender d2("Ramos", 1986, 45, 50);
    d2.displayInfo();

    cout << "======================" << endl;

    d2.setTackleSuccess(55);
    d2.displayInfo();

    cout << "======================" << endl;

    Goalkeeper g1;
    Goalkeeper g2("g2", 1990, 10, 10, 10);
    Goalkeeper g3;
    g3.setCleanSheets(999);
    g3.setSaves(999);
    g3.setTotalShotsOnGoal(999);

    g1.displayInfo();
    cout << "======================" << endl;
    g2.displayInfo();
    cout << "======================" << endl;
    g3.displayInfo();
    cout << "g3 getcleansheet: " << g3.getCleanSheets() << "\n"
         << "g3 saves: " << g3.getSaves() << "\n"
         << "g3 totalshot: " << g3.getTotalShotsOnGoal() << "\n"
         << "g3 transferrate: " << g3.transferRate() << "\n";

    cout << "======================" << endl;

    Midfielder m1;
    Midfielder m2("m2", 1990, 10, 10);
    Midfielder m3;
    m3.setAssist(999);
    m3.setKeyPasses(999);

    m1.displayInfo();
    cout << "======================" << endl;
    m2.displayInfo();
    cout << "======================" << endl;
    m3.displayInfo();
    cout << "m3 assist: " << m3.getAssist() << "\n"
         << "m3 keypasses: " << m3.getKeyPasses() << "\n"
         << "m3 transferrate: " << m3.transferRate() << "\n";

    cout << "======================" << endl;

    Striker s1;
    Striker s2("s2", 1990, 10, 10);
    Striker s3;
    s3.setGoalScore(999);
    s3.setShotsOnTarget(0);

    s1.displayInfo();
    cout << "======================" << endl;
    s2.displayInfo();
    cout << "======================" << endl;
    s3.displayInfo();
    cout << "s3 goalscore: " << s3.getGoalScore() << "\n"
         << "s3 keypasses: " << s3.getGoalScore() << "\n"
         << "s3 transferrate: " << s3.transferRate() << "\n";
}