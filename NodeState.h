//
// Created by Dario on 02/10/2023.
//

#ifndef ESAME_LABORATORIO_NODESTATE_H
#define ESAME_LABORATORIO_NODESTATE_H

#include "StlAStar.h"
#include "WorldMap.h"

class NodeState {
public:
    NodeState() {}
    explicit NodeState(sf::Vector2f p) : pos(p) {}
    ~NodeState() {}

    float GoalDistanceEstimate( NodeState &nodeGoal );
    bool IsGoal( NodeState &nodeGoal );
    bool GetSuccessors( AStarSearch <NodeState> *astarsearch, NodeState *parentNode );
    float GetCost(NodeState state);
    bool IsSameState( NodeState &AS );
    std::size_t Hash();

private:
    sf::Vector2f pos;
    WorldMap* map;
};

#endif //ESAME_LABORATORIO_NODESTATE_H
