// player.h

#include "strats.h"

// class that implements the strategy interface
// set the strategy to any concrete one we've implemented
// calls execute on whatever the current strategy is set to.
// can assignn strategy to a different strategy, 
// and the next time execute is called, it applies the different strategy function.
class Player {
public:
    Player(Strategy* strat) {
        level_strat = strat;
    }

    void SetStrat(Strategy* strat) {
        level_strat = strat;
    }

    int MeleeAttack(int base_dmg, int stat_bonus) {
        return level_strat->meleeattack(base_dmg, stat_bonus);
    }

    int RangedAttack(int base_dmg, int stat_bonus) {
        return level_strat->rangedattack(base_dmg, stat_bonus);
    }

private:

    Strategy* level_strat;
};