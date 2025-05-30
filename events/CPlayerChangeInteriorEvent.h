#pragma once

#pragma once

#include "CEvent.h"
#include "../objects/IPlayer.h"

namespace alt
{
	class CPlayerChangeInteriorEvent : public CEvent
	{
	public:
		CPlayerChangeInteriorEvent(const std::shared_ptr<IPlayer>& _target, uint32_t _oldInteriorLocation, uint32_t _newInteriorLocation) :
			CEvent(Type::PLAYER_CHANGE_INTERIOR_EVENT),
			target(_target),
			oldInteriorLocation(_oldInteriorLocation),
			newInteriorLocation(_newInteriorLocation)
		{}

		IPlayer* GetTarget() const { return target.get(); }
		uint32_t GetOldInteriorLocation() const { return oldInteriorLocation; }
		uint32_t GetNewInteriorLocation() const { return newInteriorLocation; }

	private:
		std::shared_ptr<IPlayer> target;
		uint32_t oldInteriorLocation;
		uint32_t newInteriorLocation;
	};
}

