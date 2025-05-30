#pragma once

#include <cstdint>
#include "../objects/IWorldObject.h"

namespace alt
{
	class IEntity;
	class IPlayer;

	class IBlip : public virtual IWorldObject
	{
	public:
		enum class BlipType
		{
			VEHICLE = 1,
			PED = 2,
			OBJECT = 3,
			DESTINATION = 4,
			CONT = 5,
			PICKUP_UNK = 6,
			RADIUS = 7,
			PICKUP = 8,
			COP = 9,
			AREA = 11,
			GALLERY = 12,
			PICKUP_OBJECT = 13
		};

		virtual ~IBlip() = default;

		virtual void SetVisible(bool toggle) = 0;
		virtual bool IsVisible() const = 0;
		
		virtual bool IsGlobal() const = 0;
		virtual bool IsAttached() const = 0;
		virtual IEntity* AttachedTo() const = 0;
		virtual void AttachTo(IEntity* entity) = 0;
		virtual BlipType GetBlipType() const = 0;
		virtual void SetBlipType(BlipType blipType) = 0;

		virtual Vector2f GetScaleXY() const = 0;
		virtual void SetScaleXY(Vector2f scale) = 0;
		virtual uint32_t GetDisplay() const = 0;
		virtual void SetDisplay(uint32_t display) = 0;
		virtual uint32_t GetSprite() const = 0;
		virtual uint32_t GetColor() const = 0;
		virtual alt::RGBA GetSecondaryColor() const = 0;
		virtual uint32_t GetAlpha() const = 0;
		virtual int GetFlashTimer() const = 0;
		virtual int GetFlashInterval() const = 0;
		virtual bool GetAsFriendly() const = 0;
		virtual bool GetRoute() const = 0;
		virtual bool GetBright() const = 0;
		virtual int GetNumber() const = 0;
		virtual bool GetShowCone() const = 0;
		virtual bool GetFlashes() const = 0;
		virtual bool GetFlashesAlternate() const = 0;
		virtual bool GetAsShortRange() const = 0;
		virtual uint32_t GetPriority() const = 0;
		virtual float GetRotation() const = 0;
		virtual std::string GetGxtName() const = 0;
		virtual std::string GetName() const = 0;
		virtual alt::RGBA GetRouteColor() const = 0;
		virtual bool GetPulse() const = 0;
		virtual bool GetAsMissionCreator() const = 0;
		virtual bool GetTickVisible() const = 0;
		virtual bool GetHeadingIndicatorVisible() const = 0;
		virtual bool GetOutlineIndicatorVisible() const = 0;
		virtual bool GetFriendIndicatorVisible() const = 0;
		virtual bool GetCrewIndicatorVisible() const = 0;
		virtual uint32_t GetCategory() const = 0;
		virtual bool GetAsHighDetail() const = 0;
		virtual bool GetShrinked() const = 0;
#ifdef ALT_CLIENT_API
		virtual uint32_t GetGameID() const = 0;
		virtual bool IsStreamedIn() const = 0;
#endif

#ifdef ALT_SERVER_API
		virtual void SetGlobal(bool state) = 0;
		virtual void AddTargetPlayer(IPlayer* player) = 0;
		virtual void RemoveTargetPlayer(IPlayer* player) = 0;
		virtual std::vector<IPlayer*> GetTargets() const = 0;
#endif

		virtual void SetSprite(uint32_t sprite) = 0;
		virtual void SetColor(uint32_t color) = 0;
		virtual void SetRoute(bool state) = 0;
		virtual void SetRouteColor(alt::RGBA color) = 0;
		virtual void SetSecondaryColor(alt::RGBA color) = 0;
		virtual void SetAlpha(uint32_t alpha) = 0;
		virtual void SetFlashTimer(int timer) = 0;
		virtual void SetFlashInterval(int interval) = 0;
		virtual void SetAsFriendly(bool friendly) = 0;
		virtual void SetBright(bool bright) = 0;
		virtual void SetNumber(int number) = 0;
		virtual void SetShowCone(bool state) = 0;
		virtual void SetFlashes(bool state) = 0;
		virtual void SetFlashesAlternate(bool state) = 0;
		virtual void SetAsShortRange(bool state) = 0;
		virtual void SetPriority(uint32_t state) = 0;
		virtual void SetRotation(float rot) = 0;
		virtual void SetGxtName(const std::string& name) = 0;
		virtual void SetName(const std::string& name) = 0;
		virtual void SetPulse(bool val) = 0;
		virtual void SetAsMissionCreator(bool val) = 0;
		virtual void SetTickVisible(bool val) = 0;
		virtual void SetHeadingIndicatorVisible(bool val) = 0;
		virtual void SetOutlineIndicatorVisible(bool val) = 0;
		virtual void SetFriendIndicatorVisible(bool val) = 0;
		virtual void SetCrewIndicatorVisible(bool val) = 0;
		virtual void SetCategory(uint32_t val) = 0;
		virtual void SetAsHighDetail(bool val) = 0;
		virtual void SetShrinked(bool val) = 0;
		virtual void Fade(uint32_t opacity, uint32_t duration) = 0;

		virtual bool IsHiddenOnLegend() const = 0;
		virtual void SetHiddenOnLegend(bool state) = 0;

		virtual bool IsMinimalOnEdge() const = 0;
		virtual void SetMinimalOnEdge(bool state) = 0;

		virtual bool IsUseHeightIndicatorOnEdge() const = 0;
		virtual void SetUseHeightIndicatorOnEdge(bool state) = 0;

		virtual bool IsShortHeightThreshold() const = 0;
		virtual void SetShortHeightThreshold(bool state) = 0;
	};
} // namespace alt
