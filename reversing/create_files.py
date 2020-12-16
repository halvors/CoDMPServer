#!/usr/bin/env python3
import os

def get_file_list():
	files = [] # list of files to append to

	with open("files.txt", "r") as files_txt:
		for file in files_txt:
			files.append(file[:-1]) # remove the newline

	return files

def get_directory_list():
	files = get_file_list()
	found_directories = []
	directory_list = []

	for i in range(len(files)):
		if len(files[i]) == 0:
			continue

		# Check against duplicates
		if files[i].split('/')[:-1] in found_directories:
			continue

		found_directories.append(files[i].split('/')[:-1])
		directory_list.append(files[i].split('/')[:-1])

	return directory_list

def main():
	directories = get_directory_list()

	for i in range(len(directories)):
		print(directories[i])

if __name__ == '__main__':
	main()
