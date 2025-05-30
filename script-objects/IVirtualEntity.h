#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include <unordered_map>

#include "../types/MValue.h"

#include "../objects/IWorldObject.h"
#include "../script-objects/IVirtualEntityGroup.h"

namespace alt
{
	class IVirtualEntity : public virtual IWorldObject
	{
	public:
		virtual ~IVirtualEntity() = default;

		virtual IVirtualEntityGroup* GetGroup() const = 0;

		virtual bool HasStreamSyncedMetaData(const std::string& key) const = 0;
		virtual MValueConst GetStreamSyncedMetaData(const std::string& key) const = 0;
		virtual std::vector<std::string> GetStreamSyncedMetaDataKeys() const = 0;

		virtual uint32_t GetStreamingDistance() const = 0;

		virtual void SetVisible(bool toggle) = 0;
		virtual bool IsVisible() const = 0;
#ifdef ALT_CLIENT_API
		virtual bool IsStreamedIn() const = 0;
#endif

#ifdef ALT_SERVER_API
		virtual void SetStreamSyncedMetaData(const std::string& key, MValue val) = 0;
		virtual void SetMultipleStreamSyncedMetaData(const std::unordered_map<std::string, alt::MValue>& values) = 0;
		virtual void DeleteStreamSyncedMetaData(const std::string& key) = 0;
#endif
	};
} // namespace alt
