int StringTable_ColumnCount(StringTable *table) {
	if (!table) {
		return 0;
	}
	
	return table->columnCount;
}
