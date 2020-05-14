int StringTable_ColumnCount(StringTable *table)
{
	if (table == NULL)
	{
		return 0;
	}
	return table->columnCount;
}
