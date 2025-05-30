#pragma once

#include <cstdint>

#include "CEvent.h"

namespace alt
{
	class IPlayer;
	class IEntity;

	class CPlayerDamageEvent : public CEvent
	{
	public:
		CPlayerDamageEvent(const std::shared_ptr<IPlayer>& _target, const std::shared_ptr<IEntity>& _attacker, uint16_t _healthDamage, uint16_t _armourDamage, uint32_t _weapon) :
			CEvent(Type::PLAYER_DAMAGE),
			target(_target),
			attacker(_attacker),
			healthDamage(_healthDamage),
			armourDamage(_armourDamage),
			weapon(_weapon)
		{

		}

		IPlayer* GetTarget() const { return target.get(); }
		IEntity* GetAttacker() const { return attacker.get(); }
		uint16_t GetHealthDamage() const { return healthDamage; }
		uint16_t GetArmourDamage() const { return armourDamage; }
		uint32_t GetWeapon() const { return weapon; }

	private:
		std::shared_ptr<IPlayer> target;
		std::shared_ptr<IEntity> attacker;
		uint16_t healthDamage;
		uint16_t armourDamage;
		uint32_t weapon;
	};
}
