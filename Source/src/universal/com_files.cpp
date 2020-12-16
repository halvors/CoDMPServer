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

int FS_WriteFile(const char *filename, const void *buffer, int size) {
	int result;		// eax
	int actualSize;	// ST18_4
	int f;			// [esp+0h] [ebp-8h]

	FS_CheckFileSystemStarted();

	ASSERT(filename);
	ASSERT(buffer);

	f = FS_FOpenFileWrite(filename);

	if (f) {
		actualSize = FS_Write(buffer, size, f);
		FS_FCloseFile(f);
		if (actualSize == size) {
			result = 1;
		} else {
			FS_Delete(filename);
			result = 0;
		}
	} else {
		Com_Printf(10, "Failed to open %s\n", filename);
		result = 0;
	}

	return result;
}
