#include "Battle.h"

#include "../Util.h"

Player *Battle::getPlayer() const {
    return player;
}

Enemy *Battle::getEnemy() const {
    return enemy;
}

void Battle::start() {
    Util::print("Initiated a battle against " + enemy->getName());
    Battler *current = player->getStats().getSpeed() >= enemy->getStats().getSpeed() ? player : (Battler *) enemy;
    Battler *other = current != player ? player : (Battler *) enemy;
    while (true) {
        if (current == player) {
            Util::print("It's your turn! The enemy " + enemy->getName() + " is at " + std::to_string(enemy->getHealth()) + "hp");
        }
        current->attack(other);
        if (player->getHealth() == 0) {
            return; //Update method will case death
        } else if (enemy->getHealth() == 0) {
            Util::print("You defeated " + enemy->getName() + "!");
            return;
        }
        current = other;
        other = current != player ? player : (Battler *) enemy;
    }
}