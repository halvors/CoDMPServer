bool BG_ThrowingBackGrenade(playerState_s *ps)
{
	if (IsBadReadPtr(ps))
	{
		return false;
	}
	return ps->throwBackGrenadeOwner != 1024;
}

unsigned int BG_GetNumWeapons()
{
	return bg_lastParsedWeaponIndex + 1;
}

void BG_CalculateWeaponMovement(weaponState_t *ws, float *origin, float *angles)
{
	BG_CalculateWeaponMovement_Base(ws);
	BG_CalculateWeaponMovement_Sway(ws);
	BG_CalculateWeaponMovement_Recoil(ws);
	BG_CalculateWeaponMovement_Bob(ws);
	if (!IsBadReadPtr(angles))
	{
		BG_SetWeaponMovementAngles(ws, angles);
	}
	if (!IsBadReadPtr(origin))
	{
		BG_SetWeaponMovementOrigin(ws, origin);
	}
}

bool BG_ValidateWeaponNumber(unsigned int index)
{
	return index < BG_GetNumWeapons();
}

bool BG_WeaponBlocksProne(unsigned int index)
{
	WeaponDef *weapDef = BG_GetWeaponDef(index);
	return weapDef->blocksProne != false;
}

bool BG_PlayerHasCompatibleWeapon(playerState_s *ps, unsigned int weaponIndex)
{
	int ammoIndex;
	unsigned int weapIndex;
	WeaponVariantDef *weapon;
	int ammo;
	if (IsBadReadPtr(ps))
	{
		return false;
	}
	weapon = BG_GetWeaponVariantDef(weaponIndex);
	ammoIndex = weapon->iAmmoIndex;
	// PDB: Start of Block
	int i = 0;
	while (true)
	{
		if (i > 14)
		{
			return false;
		}
		weapIndex = ps->heldWeapons[i].weapon;
		if ((weapIndex != 0) && (ammo = BG_AmmoForWeapon(weapIndex), ammo == ammoIndex))
		{
			break;
		}
		i++;
	}
	return true;
}
