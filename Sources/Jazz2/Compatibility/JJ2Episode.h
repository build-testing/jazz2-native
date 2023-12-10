﻿#pragma once

#include "../../Common.h"
#include "JJ2Level.h"

#include <functional>
#include <memory>
#include <utility>

#include <Containers/String.h>
#include <Containers/StringView.h>

using namespace Death::Containers;

namespace Jazz2::Compatibility
{
	class JJ2Episode // .j2e / .j2pe
	{
	public:
		int32_t Position;
		String Name;
		String DisplayName;
		String FirstLevel;
		String PreviousEpisode;
		String NextEpisode;
		int32_t TitleWidth;
		int32_t TitleHeight;
		std::unique_ptr<uint8_t[]> TitleData;

		JJ2Episode();
		JJ2Episode(const String& name, const String& displayName, const String& firstLevel, int32_t position);

		bool Open(const StringView& path);

		void Convert(const String& targetPath, std::function<JJ2Level::LevelToken(const StringView&)> levelTokenConversion = nullptr, std::function<String(JJ2Episode*)> episodeNameConversion = nullptr, std::function<Pair<String, String>(JJ2Episode*)> episodePrevNext = nullptr);
	};
}