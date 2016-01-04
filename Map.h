//
// Created by User1 on 1/1/2016.
//

#ifndef AGENTBASEDMODELING_MAP_H
#define AGENTBASEDMODELING_MAP_H

#include <vector>
using namespace std;

class Map {
public:
    Map() ;
    Map(unsigned int x_dimension, unsigned int y_dimension) ;

    // Adds a connection if not already present and returns true
    // Returns false if unable to make a connection due to bounds violations
    bool addConnection(unsigned int room1, unsigned int room2) ;

    // Removes a connection if present and returns true
    // Returns false if unable to remove a connection due to bounds violations
    bool removeConnection(unsigned int room1, unsigned int room2) ;

    // Returns the matrix that shows room layout
    const vector<unsigned int> getMap( ) ;

    // Returns the adjacency list
    const vector<vector<unsigned int>> getAdjacencies() ;

    // Returns the number of rooms
    const unsigned int getNumRooms() ;

private:
    vector<unsigned int> m_map ;
    vector<vector<unsigned int> > m_adjacencies ;

    void generateMap(unsigned int x_dimension, unsigned int y_dimension) ;
};


#endif //AGENTBASEDMODELING_MAP_H
