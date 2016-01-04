//
// Created by User1 on 1/3/2016.
//

#include "Agent.h"
#include <iostream>

using namespace std;

// Set the counter for agent IDs
unsigned int Agent::m_counter = 0;

Agent::Agent() {
    // Set the agent's ID
    m_id = ++m_counter;
}

unsigned int Agent::getId() {
    return m_id;
}