void BG_WeaponNameToComponentList(char *weaponName, WeaponComponentList *componentList) {
	// _memset(componentList, 0, 0x138);
	char *in = weaponName;
	int charIdx = 0;
	while (true) {
		if (*in == '\0') {
			componentList->components[componentList->numComponents].name[charIdx] = '\0';
			componentList->numComponents++;
			if (componentList->numComponents <= MAX_WEAPON_COMPONENTS) {
				return;
			}
			return;
		}
		if (*in == '_') {
			componentList->components[componentList->numComponents].name[charIdx] = '\0';
			componentList->numComponents++;
			charIdx = 0;
			if (componentList->numComponents < MAX_WEAPON_COMPONENTS) {
				return;
			}
		} else {
			componentList->components[componentList->numComponents].name[charIdx] = *in;
			charIdx++;
			if (charIdx < MAX_WEAPON_COMPONENT_LEN) {
				return;
			}
		}
		in++;
	}
}
