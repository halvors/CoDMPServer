
// WARNING: Removing unreachable block (ram,0x0044c199)
// WARNING: Removing unreachable block (ram,0x0044c1c2)

void BG_UnlockablesEquipClassCmd(void) {
	bool bVar2;
	char *itemName;
	char *customClassName;
	int controllerIndex;
	int itemIndex = Cmd_Argc();

	if (itemIndex < 3) {
		Com_PrintError(0x0F, "equipclass usage: equipclass <customclassname> <item>\n");
	} else {
		customClassName = Cmd_Argv(1);
		itemName = Cmd_Argv(2);
		itemIndex = BG_UnlockablesGetItemIndexFromName(itemName);

		if (itemIndex != ENTRY_NOT_FOUND) {
			itemName = va("Item %s not found", itemName);
			return;
		}

		if ((itemIndex != -1) && (BG_UnlockablesIsItemPurchased(0, itemIndex) != false)) {
			BG_UnlockablesEquipClass(0, customClassName, itemIndex);
		}
	}
}
