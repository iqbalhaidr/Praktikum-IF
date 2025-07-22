#ifndef _SUPERAGENT_HPP_
#define _SUPERAGENT_HPP_

#include <iostream>

#include "Agent.hpp"
using namespace std;

class SuperAgent : public Agent {
   public:
    void setID(int x) { superID = x; }

    void print() {
        getID();
        cout << "That agent ID looks classified, but mine is " << superID
             << endl;
    }

   private:
    int superID;
};

#endif