#pragma once

#include "CEvent.h"

namespace alt
{
	class CPlayerWeaponShootEvent : public CEvent
	{
	public:
		CPlayerWeaponShootEvent(uint32_t _weapon, uint16_t _totalAmmo, uint16_t _ammoInClip) :
			CEvent(Type::PLAYER_WEAPON_SHOOT_EVENT),
			weapon(_weapon),
			totalAmmo(_totalAmmo),
			ammoInClip(_ammoInClip)
		{}

		uint32_t GetWeapon() const { return weapon; }
		uint16_t GetTotalAmmo() const { return totalAmmo; }
		uint16_t GetAmmoInClip() const { return ammoInClip; }

	private:
		uint32_t weapon;
		uint16_t totalAmmo;
		uint16_t ammoInClip;
	};
}
