//
// Created by User1 on 1/3/2016.
//

#ifndef AGENTBASEDMODELING_AGENT_H
#define AGENTBASEDMODELING_AGENT_H

#include <string>
using namespace std;

class Agent {
public:
    Agent() ;

    // The agent's action for its turn
    virtual void turnAction( ) = 0;

    // The agent's behavior when another agent specifically is encountered
    virtual void encounter(Agent *ptr) = 0;

    //
    virtual void migrates() = 0;

    virtual string identify() = 0;

    unsigned int getId() ;

    virtual string getState() = 0;

protected:
    virtual void setState() = 0;

private:
    unsigned int m_id ;
    static unsigned int m_counter;
    float m_interaction_chance ;
    float m_movement_chance ;


};


#endif //AGENTBASEDMODELING_AGENT_H
