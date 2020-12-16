#!/usr/bin/env python3

# Returns a list of strings built off every line in files.txt.
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
		# save our current file
		current_file = files[file]

		# it's an empty string, ignore it.
		if len(current_file) == 0:
			continue

		for i in range(len(files)):
			# make sure it isn't the same iteration
			if file != i:
				if files[i] == current_file:
					# append it in a form that can be easily parsed. (it's formatted like this: "[file_string]|[iteration]")
					duplicates.append(f"{files[i]}|{i}")
			else:
				continue

		# after we've finished our checks, append it so we can store the file's that were already checked.
		files_checked.append(current_file)

	return duplicates

# This is just a very hacky way of fixing the duplicate list since I'm too lazy to actually
# do this in check_for_duplicates().
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
		# print all duplicate entries found.
		for i in range(len(duplicates)):
			duplicate, line = duplicates[i].split("|")
			print(f"Duplicate file found: {duplicate} (line: {str(int(line) + 1)})")
	else:
		print("No duplicates found.")

if __name__ == '__main__':
	main()
