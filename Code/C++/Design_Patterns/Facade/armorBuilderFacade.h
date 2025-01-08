#include "armor.h"

class ArmorBuilderFacade
{
public:
    ArmorBuilderFacade()
    {
        heavyarmor_ = new HeavyArmor();
        mediumarmor_ = new MediumArmor();
        lightarmor_ = new LightArmor();
    }

    ~ArmorBuilderFacade()
    {
        delete heavyarmor_;
        delete mediumarmor_;
        delete lightarmor_;
    }

    // public operations that are abstracted away. We want to make automatic.
    std::string GetHeavyArmor() { return heavyarmor_->ArmorType; }
    std::string GetMediumArmor() { return mediumarmor_->ArmorType; }
    std::string GetLightArmor() { return lightarmor_->ArmorType; }

private:
    HeavyArmor* heavyarmor_;
    MediumArmor* mediumarmor_;
    LightArmor* lightarmor_;
    // Anytime we want one of these armor types, we want to call a public function from above.
};