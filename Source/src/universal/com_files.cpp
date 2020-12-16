int FS_CreatePath(char *path) {
	if (_strstr(path, "..") == NULL && _strstr(path, "::") == NULL) {
		char *ofs = path + 1;

		while (*ofs != '\0') {
			if (*ofs == '\\') {
				*ofs = '\0';
				Sys_Mkdir(path);
				*ofs = '\\';
			}

			ofs++;
		}

		return 0;
	}

	Com_PrintWarning("WARNING: refusing to create relative path \"%s\"\n", path);
	return 1;
}
