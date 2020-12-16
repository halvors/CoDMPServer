void BG_EmblemsClearDefaults() {
	for (int def = 0; def < 24; def++) {
		*(undefined4 *)(&DAT_00E2A7D4 + def * 0x18C) = 0xFFFFFFFF;
		*(undefined4 *)(&DAT_00E2A7D0 + def * 0x18C) = 0xFFFFFFFF;
	}
}

int BG_EmblemsGetPurchasedIconCount(int param_1) {
	return BG_EmblemsGetIconCount(param_1, 2, 0);
}

char *BG_EmblemsGetCategoryDesc(int index) {
	if (s_emblemSet == NULL) { // s_emblemSet is a global variable
		return "";
	}
	
	return ((index < 0) || (s_emblemSet->categoryCount < index) ? "" : s_emblemSet->categories[index].description);
}
