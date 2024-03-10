//
// Created by Dario on 02/10/2023.
//

#include "StlAStar.h"

float NodeState::GoalDistanceEstimate(NodeState &nodeGoal) const {
    return abs(pos.x - nodeGoal.pos.x) + abs(pos.y - nodeGoal.pos.y);
}

bool NodeState::IsGoal( NodeState &nodeGoal ) const {
    if( (pos.x == nodeGoal.pos.x) && (pos.y == nodeGoal.pos.y) )
    {
        return true;
    }
    return false;
}

bool NodeState::GetSuccessors( AStarSearch<NodeState> *astarsearch, NodeState *parentNode ) const {

    float parentX = -1;
    float parentY = -1;

    if( parentNode ){
        parentX = parentNode->pos.x;
        parentY = parentNode->pos.y;
    }

    NodeState NewNode;

    if( (getMapCosto( {pos.x - 10, pos.y} ) < 9) && !((parentX == pos.x - 10) && (parentY == pos.y))
    && (getMapCosto({pos.x - 10, pos.y}) != 9) && (getMapCosto({pos.x - 10, pos.y + 20}) != 9)){
        NewNode = NodeState( {pos.x - 10, pos.y} );
        astarsearch->AddSuccessor( NewNode );
    }

    if( (getMapCosto( {pos.x, pos.y - 10} ) < 9) && !((parentX == pos.x) && (parentY == pos.y - 10))
    && (getMapCosto({pos.x, pos.y - 10}) != 9)  && (getMapCosto({pos.x + 20, pos.y - 10}) != 9)){
        NewNode = NodeState( {pos.x, pos.y - 10} );
        astarsearch->AddSuccessor( NewNode );
    }

    if( (getMapCosto({ pos.x + 10, pos.y }) < 9) && !((parentX == pos.x + 10) && (parentY == pos.y))
    && (getMapCosto({pos.x + 30, pos.y}) != 9)  && (getMapCosto({pos.x + 30, pos.y + 20}) != 9)){
        NewNode = NodeState( {pos.x + 10, pos.y} );
        astarsearch->AddSuccessor( NewNode );
    }

    if( (getMapCosto({ pos.x, pos.y + 10 }) < 9) && !((parentX == pos.x) && (parentY == pos.y + 10))
    && (getMapCosto({pos.x, pos.y + 30}) != 9) && (getMapCosto({pos.x + 20, pos.y + 30}) != 9)){
        NewNode = NodeState( {pos.x, pos.y + 10} );
        astarsearch->AddSuccessor( NewNode );
    }

    return true;
}

float NodeState::GetCost() const {
    return static_cast<float>(getMapCosto({pos.x, pos.y }));
}

bool NodeState::IsSameState( NodeState &goalState ) const {
    if( (pos.x == goalState.pos.x) && (pos.y == goalState.pos.y) ){
        return true;
    }
    return false;
}

std::size_t NodeState::Hash() const{
    size_t h1 = hash<float>{}(pos.x);
    size_t h2 = hash<float>{}(pos.y);
    return h1 ^ (h2 << 1);
}
