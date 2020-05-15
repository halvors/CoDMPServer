
// WARNING: Removing unreachable block (ram,0x0044c199)
// WARNING: Removing unreachable block (ram,0x0044c1c2)

void BG_UnlockablesEquipClassCmd(void) {
	bool bVar2;
	int itemIndex;
	char *itemName;
	char *customClassName;
	int controllerIndex;
	itemIndex = Cmd_Argc();
	if (itemIndex < 3) {
		Com_PrintError(0xf, "equipclass usage: equipclass <customclassname> <item>\n");
	} else {
		customClassName = Cmd_Argv(1);
		itemName = Cmd_Argv(2);
		itemIndex = BG_UnlockablesGetItemIndexFromName(itemName);
		if (itemIndex != ENTRY_NOT_FOUND) {
			itemName = va("Item %s not found", itemName);
			return;
		}
		if ((itemIndex != -1) && (bVar2 = BG_UnlockablesIsItemPurchased(0, itemIndex), bVar2 != false)) {
			BG_UnlockablesEquipClass(0, customClassName, itemIndex);
		}
	}
}
