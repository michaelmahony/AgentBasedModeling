//
// Created by User1 on 1/1/2016.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include "Map.h"

using namespace std;

Map::Map() {
    generateMap(3, 3);
}

Map::Map(unsigned int x_dimension, unsigned int y_dimension) {
    generateMap(x_dimension, y_dimension);
}


void Map::generateMap(unsigned int x_dimension, unsigned int y_dimension) {

    // A matrix containing room numbers
    unsigned int room_number = 0;
    vector<vector<unsigned int> > m_map(x_dimension, vector<unsigned int>(y_dimension));
    // Increment room number for each room; move left to right, then down
    for (unsigned int row_index = 0; row_index < x_dimension; row_index++) {
        for (unsigned int col_index = 0; col_index < y_dimension; col_index++) {
            m_map[row_index][col_index] = room_number++;
        }
    }

    // Create the adjacency list... should refer to room number, not coordinite
    // An adjacency list is more appropriate than a matrix because the data will be sparse
    vector<vector<unsigned int> > m_adjacencies(x_dimension * y_dimension, vector<unsigned int>(0));



    // Fill in adjacency data; If row or columns are equal AND the elements
    // are only one index away in the other dimension, there is a connection
    for (unsigned int room_num = 0; room_num < m_adjacencies.size(); room_num++) {
        // Each room should be connected to the one before it and the one after it
        // PROVIDED that they are on the same row.

        // If it is not the last room in a row
        if ((room_num + 1) % x_dimension != 0) {
            m_adjacencies[room_num].push_back((room_num + 1));
        }
        // If it is not the first room in a row
        if (room_num % x_dimension != 0) {
            m_adjacencies[room_num].push_back((room_num - 1));
        }
        // If it is not in the top row
        if (room_num >= x_dimension) {
            m_adjacencies[room_num].push_back((room_num - x_dimension));
        }
        // If it is not in the bottom row
        if (room_num < (y_dimension - 1) * x_dimension) {
            m_adjacencies[room_num].push_back((room_num + x_dimension));
        }

        cout << room_num << ":" ;
        for (unsigned int i = 0; i < m_adjacencies[room_num].size(); i++) {
            cout << " " << m_adjacencies[room_num][i];
        }
        cout << endl;

    }
}

const vector<unsigned int> Map::getMap( ) {
    return m_map;
}

const vector<vector<unsigned int>> Map::getAdjacencies( ) {
    return m_adjacencies;
}

bool Map::addConnection(unsigned int room1, unsigned int room2) {
    // If the rooms are the same or if a room is out of bounds
    if (room1 == room2 || room1 > m_adjacencies.size() || room2 > m_adjacencies.size() ) {
        return false;
    }
    // If the connection is not already made, add it in both directions
    if (find(m_adjacencies[room1].begin(), m_adjacencies[room1].end(), room2) == m_adjacencies[room1].end() ) {
        m_adjacencies[room1].push_back(room2);
        m_adjacencies[room2].push_back(room1);
    }
    return true;
}

bool Map::removeConnection(unsigned int room1, unsigned int room2) {
    // If a room is out of range
    if (room1 > m_adjacencies.size() || room2 > m_adjacencies.size()) {
        return false;
    }
    // If the connection is present, remove it in both directions
    if (find(m_adjacencies[room1].begin(), m_adjacencies[room1].end(), room2) != m_adjacencies[room1].end() ) {
        m_adjacencies[room1].erase(remove(m_adjacencies[room1].begin(), m_adjacencies[room1].end(), room2)) ;
        m_adjacencies[room2].erase(remove(m_adjacencies[room2].begin(), m_adjacencies[room2].end(), room1)) ;
    }
    return true;
}

const unsigned int Map::getNumRooms() {
    return m_adjacencies.size();
}