//
// Created by dario on 24/09/21.
//

#ifndef ESAME_LABORATORIO_FINDPATH_H
#define ESAME_LABORATORIO_FINDPATH_H


#include "StlAStar.h" // See header for copyright and usage information

#include <iostream>
#include <cstdio>
#include <cmath>

#define DEBUG_LISTS 0
#define DEBUG_LIST_LENGTHS_ONLY 0

using namespace std;

const int MAP_WIDTH = 20;
const int MAP_HEIGHT = 20;


// map helper functions


// Definitions

class MapSearchNode
{
public:
    int x;	 // the (x,y) positions of the node
    int y;

    MapSearchNode() { x = y = 0; }
    MapSearchNode( int px, int py ) { x=px; y=py; }

    float GoalDistanceEstimate( MapSearchNode &nodeGoal ) const;
    bool IsGoal( MapSearchNode &nodeGoal ) const;
    bool GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node ) const;
    float GetCost( MapSearchNode &successor ) const;
    bool IsSameState( MapSearchNode &rhs ) const;

    void PrintNodeInfo() const;

};

#endif //ESAME_LABORATORIO_FINDPATH_H
