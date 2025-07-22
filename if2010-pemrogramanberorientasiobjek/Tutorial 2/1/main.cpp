#include "Agent.hpp"
#include "SuperAgent.hpp"

void fn(Agent &a) { a.setID(1337); }

int main() {
    SuperAgent agentX;

    fn(agentX);
    agentX.setID(9999);

    agentX.print();
    return 0;
}

// Agent P is on a mission, my agent ID is 1337
// That agent ID looks classified, but mine is 9999