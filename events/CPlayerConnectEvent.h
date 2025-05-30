#pragma once

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CPlayerConnectEvent : public CCancellableEvent
	{
	public:
		CPlayerConnectEvent(const std::shared_ptr<IPlayer>& _target) :
			CCancellableEvent(Type::PLAYER_CONNECT),
			target(_target)
		{
		}

		IPlayer* GetTarget() const { return target.get(); }
		const std::string& GetReason() const { return reason; }

		void Cancel(const std::string& _reason)
		{
			reason = _reason;
			CCancellableEvent::Cancel();
		}

	private:
		std::shared_ptr<IPlayer> target;
		std::string reason;
	};
}
