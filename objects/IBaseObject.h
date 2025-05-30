#pragma once

#include "../types/MValue.h"
#include <vector>
#include <unordered_map>

namespace alt
{
	class IBaseObject: public std::enable_shared_from_this<IBaseObject>
	{
	protected:
		virtual ~IBaseObject() = default;

	public:
		enum class Type : uint8_t
		{
			PLAYER,
			VEHICLE,
			PED,
			OBJECT,
			BLIP,
			WEBVIEW,
			VOICE_CHANNEL,
			COLSHAPE,
			CHECKPOINT,
			WEBSOCKET_CLIENT,
			HTTP_CLIENT,
			AUDIO,
			AUDIO_OUTPUT,
			AUDIO_OUTPUT_WORLD,
			AUDIO_OUTPUT_ATTACHED,
			AUDIO_OUTPUT_FRONTEND,
			RML_ELEMENT,
			RML_DOCUMENT,
			LOCAL_PLAYER,
			LOCAL_OBJECT,
			VIRTUAL_ENTITY,
			VIRTUAL_ENTITY_GROUP,
			MARKER,
			TEXT_LABEL,
			LOCAL_PED,
			LOCAL_VEHICLE,
			AUDIO_FILTER,
			CONNECTION_INFO,
			CUSTOM_TEXTURE,
			FONT,
			SIZE
		};

		virtual Type GetType() const = 0;

		virtual uint32_t GetID() const = 0;

		virtual bool HasMetaData(const std::string& key) const = 0;
		virtual MValueConst GetMetaData(const std::string& key) const = 0;
		virtual void SetMetaData(const std::string& key, MValue val) = 0;
		virtual void SetMultipleMetaData(const std::unordered_map<std::string, MValue>& values) = 0;
		virtual void DeleteMetaData(const std::string& key) = 0;
		virtual std::vector<std::string> GetMetaDataKeys() const = 0;

		virtual bool HasSyncedMetaData(const std::string& key) const = 0;
		virtual MValueConst GetSyncedMetaData(const std::string& key) const = 0;
		virtual std::vector<std::string> GetSyncedMetaDataKeys() const = 0;

#ifdef ALT_SERVER_API
		virtual void SetSyncedMetaData(const std::string& key, MValue val) = 0;
		virtual void SetMultipleSyncedMetaData(const std::unordered_map<std::string, MValue>& values) = 0;
		virtual void DeleteSyncedMetaData(const std::string& key) = 0;
#endif
#ifdef ALT_CLIENT_API
		virtual uint32_t GetRemoteID() const = 0;
		virtual bool IsRemote() const = 0;
#endif // ALT_CLIENT_API

		virtual bool IsRemoved() const = 0;

		template <typename Derived>
		std::shared_ptr<Derived> SharedAs()
		{
			try
			{
				Derived* derived = dynamic_cast<Derived*>(this);
				if (!derived)
				{
					static std::shared_ptr<Derived> empty;
					return empty;
				}
				std::shared_ptr<IBaseObject> shared = derived->shared_from_this();
				return std::dynamic_pointer_cast<Derived>(shared);
			}
			catch (std::bad_weak_ptr&)
			{
				static std::shared_ptr<Derived> empty;
				return empty;
			}
		}

        template <typename Derived>
        Derived* As()
        {
            return dynamic_cast<Derived*>(this);
        }
	};
} // namespace alt
