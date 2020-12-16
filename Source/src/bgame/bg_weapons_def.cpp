unsigned int BG_GetWeaponIndex(WeaponVariantDef *param_1) {
	if (!weapVariantDef) {
		return 0;
	}

	unsigned int weapIndex = 0;

	while (true) {
		if (bg_lastParsedWeaponIndex < weapIndex) {
			return 0;
		}

		if (weapVariantDef == (WeaponVariantDef *)(&bg_weaponVariantDefs)[weapIndex]) {
			break;
		}

		weapIndex++;
	}

	return weapIndex;
}

unsigned int BG_GetWeaponIndexForName(char *name) {
	return BG_GetWeaponIndexForName(name, NULL);
}

unsigned int BG_GetWeaponIndexForName(char *name, FuncDef36 *unknown) {
	int cmpstr;
	WeaponVariantDef *weapVariantDef;
	unsigned int weapIndex;

	if (*name == '\0' || I_stricmp(name, "none") == 0) {
		weapIndex = 0;
	} else {
		weapIndex = BG_FindWeaponIndexForName(name);

		if (!weapIndex) {
			weapVariantDef = BG_LoadWeaponVariantDef(name);

			if (!weapVariantDef) {
				Com_DPrintf("Couldn\'t find weapon \"%s\"\n", name);
				weapIndex = 0;
			} else {
				weapIndex = BG_IsDefaultWeapon(name);

				if ((weapIndex & 0xFF) == 0) {
					weapIndex = BG_SetupWeaponVariantDef(weapVariantDef, unknown);
				} else {
					weapIndex = 0;
				}
			}
		}
	}

	return weapIndex;
}
