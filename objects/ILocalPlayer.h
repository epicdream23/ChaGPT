#pragma once

#include "IPlayer.h"
#include "../script-objects/IWeaponData.h"

namespace alt
{
    class ILocalPlayer : public virtual IPlayer
    {
    protected:
        virtual ~ILocalPlayer() = default;

    public:
#ifdef ALT_CLIENT_API
        virtual uint16_t GetCurrentAmmo() const = 0;

        virtual uint16_t GetWeaponAmmo(uint32_t weaponHash) const = 0;
        virtual bool HasWeapon(uint32_t weaponHash) const = 0;
        virtual std::vector<alt::Weapon> GetWeapons() const = 0;
        virtual std::vector<uint32_t> GetWeaponComponents(uint32_t weaponHash) const = 0;

        virtual std::shared_ptr<alt::IWeaponData> GetCurrentWeaponData() const = 0;

        virtual float GetStamina() const = 0;
        virtual void SetStamina(float value) = 0;
        virtual float GetMaxStamina() const = 0;
        virtual void SetMaxStamina(float value) = 0;
#endif
    };
} // namespace alt
