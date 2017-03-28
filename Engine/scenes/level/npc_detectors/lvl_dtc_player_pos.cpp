#include "lvl_dtc_player_pos.h"
#include "../../scene_level.h"

PlayerPosDetector::PlayerPosDetector(LVL_Npc *parent):
    BasicDetector(parent)
{
    _directedTo=0.0;
    _playersDirection=0;
    _plrptr=NULL;
    _plr_id=0;
    _plr_state=0;
}

PlayerPosDetector::PlayerPosDetector(const PlayerPosDetector &dtc):
    BasicDetector(dtc)
{
    pos = dtc.pos;
    _directedTo=dtc._directedTo;
    _playersDirection=dtc._playersDirection;
    _plrptr=dtc._plrptr;
    _plr_id=dtc._plr_id;
    _plr_state=dtc._plr_state;
}

PlayerPosDetector::~PlayerPosDetector()
{}

void PlayerPosDetector::processDetector()
{
    if(!_parentNPC)
        return;

    double d = 0.0;
    for(size_t i = 0; i < _scene->m_itemsPlayers.size(); i++)
    {
        LVL_Player *p = _scene->m_itemsPlayers[i];
        double d1 = distance(p);
        if((d1 < d) || (i == 0))
        {
            d = d1;
            pos.setPoint(p->m_momentum.centerX(), p->m_momentum.centerY());
            _playersDirection=p->direction();
            if(_parentNPC->posCenterX() < pos.x())
                _directedTo = 1;
            else
            if(_parentNPC->posCenterX() > pos.x())
                _directedTo = -1;
            _plrptr = p;
            _plr_id = p->characterID;
            _plr_state = p->stateID;
        }
    }

}

int PlayerPosDetector::directedTo()
{
    return _directedTo;
}

int PlayerPosDetector::playersDirection()
{
    return _playersDirection;
}

PGE_PointF PlayerPosDetector::position()
{
    return pos;
}

float PlayerPosDetector::positionX()
{
    return pos.x();
}

float PlayerPosDetector::positionY()
{
    return pos.y();
}

int PlayerPosDetector::playersCharID()
{
    return _plr_id;
}

int PlayerPosDetector::playersStateID()
{
    return _plr_state;
}

LVL_Player *PlayerPosDetector::playerPtr()
{
    return _plrptr;
}

double PlayerPosDetector::distance(LVL_Player *plr)
{
    //distance between player and parent NPC
    return sqrt(pow(_parentNPC->posCenterX()-plr->posCenterX(), 2.0)+
    pow(_parentNPC->posCenterY()-plr->posCenterY(), 2.0));
}



