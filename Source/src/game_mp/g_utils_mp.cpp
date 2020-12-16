int G_ShellShockIndex(char *name) {
	if (!name) {
		return 0;
	}
	
	return G_FindConfigstringIndex(name, 0x9E4, 16, 1, NULL);
}
