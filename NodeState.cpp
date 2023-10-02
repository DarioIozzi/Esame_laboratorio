//
// Created by Dario on 02/10/2023.
//

#include "StlAStar.h"

float NodeState::GoalDistanceEstimate(NodeState &nodeGoal) {
    return abs(pos.x - nodeGoal.pos.x) + abs(pos.y - nodeGoal.pos.y);
}

bool NodeState::IsGoal( NodeState &nodeGoal ){
    if( (pos.x == nodeGoal.pos.x) && (pos.y == nodeGoal.pos.y) )
    {
        return true;
    }
    return false;
}

bool NodeState::GetSuccessors( AStarSearch<NodeState> *astarsearch, NodeState *parentNode ){

    float parentX = -1;
    float parentY = -1;

    if( parentNode ){
        parentX = parentNode->pos.x;
        parentY = parentNode->pos.y;
    }

    NodeState NewNode;

    if( (map->getCosto( {pos.x - 1, pos.y} ) < 9) && !((parentX == pos.x - 1) && (parentY == pos.y))){
        NewNode = NodeState( {pos.x - 1, pos.y} );
        astarsearch->AddSuccessor( NewNode );
    }

    if( (map->getCosto( {pos.x, pos.y - 1} ) < 9) && !((parentX == pos.x) && (parentY == pos.y - 1))){
        NewNode = NodeState( {pos.x, pos.y - 1} );
        astarsearch->AddSuccessor( NewNode );
    }

    if( (map->getCosto({ pos.x + 1, pos.y }) < 9) && !((parentX == pos.x + 1) && (parentY == pos.y))){
        NewNode = NodeState( {pos.x + 1, pos.y} );
        astarsearch->AddSuccessor( NewNode );
    }

    if( (map->getCosto({ pos.x, pos.y + 1 }) < 9) && !((parentX == pos.x) && (parentY == pos.y + 1))){
        NewNode = NodeState( {pos.x, pos.y + 1} );
        astarsearch->AddSuccessor( NewNode );
    }

    return true;
}

float NodeState::GetCost(NodeState state) {
    return (float) map->getCosto({ pos.x, pos.y });
}

bool NodeState::IsSameState( NodeState &thisState ){
    if( (pos.x == thisState.pos.x) && (pos.y == thisState.pos.y) ){
        return true;
    }
    return false;
}

std::size_t NodeState::Hash() {
    size_t h1 = hash<float>{}(pos.x);
    size_t h2 = hash<float>{}(pos.y);
    return h1 ^ (h2 << 1);
}
