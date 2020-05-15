int GetCurrentMapIndex() {
	StringTable *mapTable;
	char *mapname;
	StringTable_GetAsset("mp/mapsTable.csv", &mapTable);
	if (IsBadReadPtr(mapTable)) {
		return -1;
	}
	int index = StringTable_LookupRowNumForValue(mapTable, 0, Dvar_GetString("mapname"));
	if (index < 0) {
		return -1;
	} else {
		return _atoi(StringTable_GetColumnValueForRow(mapTable, index, 5));
	}
	return -1;
}
