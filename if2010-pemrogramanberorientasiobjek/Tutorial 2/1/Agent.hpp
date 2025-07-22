#ifndef _AGENT_HPP_
#define _AGENT_HPP_

#include <iostream>
using namespace std;

class Agent {
   public:
    void getID() {
        cout << "Agent P is on a mission, my agent ID is " << agentID << endl;
    }

    void setID(int x) { agentID = x; }

   private:
    int agentID;
};

#endif