#pragma once

#include "CEvent.h"

namespace alt
{
	class CPlayerConnectDeniedEvent : public CEvent
	{
	public:
		enum Reason: uint8_t
		{
			WRONG_VERSION,
			WRONG_BRANCH,
			DEBUG_NOT_ALLOWED,
			WRONG_PASSWORD,
			WRONG_CDN_URL
		};
		
		CPlayerConnectDeniedEvent(Reason _reason, const std::string& _name, const std::string& _ip, uint64_t _passwordHash, bool _isDebug, const std::string& _branch, uint16_t _versionMajor, uint16_t _versionMinor, const std::string& _cdnUrl, int64_t _discordId) :
			CEvent(Type::PLAYER_CONNECT_DENIED), reason(_reason), name(_name), ip(_ip), passwordHash(_passwordHash), isDebug(_isDebug), branch(_branch), versionMajor(_versionMajor), versionMinor(_versionMinor), cdnUrl(_cdnUrl), discordId(_discordId)
		{
		}

		Reason GetReason() const { return reason; }
		const std::string& GetName() const { return name; }
		const std::string& GetIp() const { return ip; }
		uint64_t GetPasswordHash() const { return passwordHash; }
		bool IsDebug() const { return isDebug; }
		const std::string& GetBranch() const { return branch; }
		uint16_t GetVersionMajor() const { return versionMajor; }
		uint16_t GetVersionMinor() const { return versionMinor; }
		const std::string& GetCdnUrl() const { return cdnUrl; }
		int64_t GetDiscordId() const { return discordId; }

	private:
		Reason reason;
		std::string name;
		std::string ip;
		uint64_t passwordHash;
		bool isDebug;
		std::string branch;
		uint16_t versionMajor;
		uint16_t versionMinor;
		std::string cdnUrl;
		int64_t discordId;
	};
}
