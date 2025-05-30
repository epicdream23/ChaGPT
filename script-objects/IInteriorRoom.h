﻿#pragma once
#include <string>

#include "IInterior.h"

namespace alt
{	
	class IInteriorRoom
	{
	protected:
		virtual ~IInteriorRoom() = default;
	public:
		virtual uint32_t GetIndex() const = 0;
		virtual std::string GetName() const = 0;
		virtual uint32_t GetNameHash() const = 0;
		virtual int32_t GetFlag() const = 0;
		virtual uint32_t GetTimecycle() const = 0;
		virtual alt::AABB GetExtents() const = 0;

		virtual void SetFlag(uint32_t flag) = 0;
		virtual void SetTimecycle(uint32_t timecycleHash) = 0;
		virtual void SetExtents(alt::AABB aabb) = 0;
	};
}