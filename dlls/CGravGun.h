#pragma once

class CGravGun : public CBasePlayerWeapon
{
public:
	void Spawn() override;
	void Precache() override;
	int iItemSlot() override { return 1; }
	bool GetItemInfo(ItemInfo* p) override;

	void PrimaryAttack() override;
	void SecondaryAttack() override;
	bool Deploy() override;
	void Holster() override;

	void ItemPostFrame() override;
	void WeaponIdle() override;

	CBaseEntity* GetEntity(float dist, bool m_bTakeDamage = false);

	#ifdef CLIENT_DLL
	CBaseEntity* m_pCurrentEntity;
	#else
	EHANDLE m_pCurrentEntity;
	#endif
	float m_flNextIdleTime;

	bool m_bResetIdle;
	bool m_bFoundPotentialTarget;

	bool UseDecrement() override
	{
#if defined(CLIENT_WEAPONS)
		return true;
#else
		return false;
#endif
	}

private:
	unsigned short m_usGravGun;
};
