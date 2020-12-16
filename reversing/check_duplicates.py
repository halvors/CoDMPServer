#!/usr/bin/env python3

def get_file_list():
	files = [] # list of files to append to

	with open("files.txt", "r") as files_txt:
		for file in files_txt:
			files.append(file[:-1]) # remove the newline

	return files

def check_for_duplicates():
	files = get_file_list()

	duplicates = [] # a list for us to label any duplicates if any are found
	files_checked = [] # a list of files we've checked

	for file in range(len(files)):
		current_file = files[file] # save our current file

		if len(current_file) == 0:
			continue

		for i in range(len(files)):
			if file != i: # make sure it isn't the same iteration
				if files[i] == current_file:
					duplicates.append(f"{files[i]}|{i}") # append it in a form that can be easily parsed. (it's formatted like this: "[file_string]|[iteration]")
			else:
				continue

		files_checked.append(current_file) # after we've finished our checks, append it so we can store the file's that were already checked.

	return duplicates

def fix_duplicates_list(list):
	duplicates_fixed = []

	if len(list) != 0:
		for i in range(len(list)):
			duplicate, line = list[i].split("|")

			for x in range(len(list)):
				duplicate_check, line_check = list[x].split("|")

				if duplicate == duplicate_check:
					if int(line) < int(line_check):
						duplicates_fixed.append(list[x])
					else:
						continue

	return duplicates_fixed

def main():
	duplicates = fix_duplicates_list(check_for_duplicates())

	if len(duplicates) != 0:
		for i in range(len(duplicates)): # for every duplicate found, print it.
			duplicate, line = duplicates[i].split("|")
			print(f"Duplicate file found: {duplicate} (line: {str(int(line) + 1)})")
	else:
		print("No duplicates found.")

if __name__ == '__main__':
	main()
