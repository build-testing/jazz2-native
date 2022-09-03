﻿#pragma once

#include "ShotBase.h"

namespace Jazz2::Actors::Weapons
{
	class SeekerShot : public ShotBase
	{
	public:
		SeekerShot();

		void OnFire(const std::shared_ptr<ActorBase>& owner, Vector2f gunspotPos, Vector2f speed, float angle, bool isFacingLeft);

		WeaponType GetWeaponType() override {
			return WeaponType::Seeker;
		}

	protected:
		Task<bool> OnActivatedAsync(const ActorActivationDetails& details) override;
		void OnUpdate(float timeMult) override;
		void OnEmitLights(SmallVectorImpl<LightEmitter>& lights) override;
		bool OnPerish(ActorBase* collider) override;
		void OnHitWall() override;
		void OnRicochet() override;

	private:
		Vector2f _gunspotPos;
		bool _fired;
		float _defaultRecomputeTime;
		float _followRecomputeTime;

		void FollowNeareastEnemy(float timeMult);
	};
}