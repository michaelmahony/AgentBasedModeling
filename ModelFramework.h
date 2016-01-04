//
// Created by User1 on 12/31/2015.
//

#ifndef _MODEL_FRAMEWORK_
#define _MODEL_FRAMEWORK_

using namespace std ;

class Model {
public:
    Model() ;
    Model(unsigned int x_dimension, unsigned int y_dimension, long seed) ;
    ~Model() ;

    void createMap(unsigned int x_dimension, unsigned int y_dimension) ;
    void advanceOneRound() ;

    unsigned int numRooms ;

    void display() ;

private:
    unsigned int m_numRooms ;

};

#endif