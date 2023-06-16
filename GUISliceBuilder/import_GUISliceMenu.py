# **********************************************
# 		EE3L11: Bachelor Graduation Project
#		GROUP M: UVC SEED STERILIZATION
#		SUBGROUP: SOFTWARE AND CONTROL
# 		MEMBERS: Erman Ergül, Erik van Weelderen
# 		
# 		BY ERIK VAN WEELDEREN
# 		DATE: 16-6-2023
# **********************************************

import os, shutil

DIRNAME = os.path.dirname(__file__)
GUI_SLICE_BUILDER_FILE = None

headers = list()

for file in os.listdir(DIRNAME):
	if file.endswith(".h"):
		if "GSLC" in file:
			GUI_SLICE_BUILDER_FILE = file
		else:
			headers.append(file)

if not GUI_SLICE_BUILDER_FILE:
	raise Exception("Please generate new code within GUISLiceBuilder")

GUI_SLICE_BUILDER_FILEPATH = os.path.join(DIRNAME, GUI_SLICE_BUILDER_FILE)

with open(GUI_SLICE_BUILDER_FILEPATH) as f:
	contents = f.read()


os.remove(GUI_SLICE_BUILDER_FILEPATH)
print(f"Removed {GUI_SLICE_BUILDER_FILE}")

# Replace function
FUNC_DEF = "void InitGUIslice_gen()"
FUNC_REDEF = "inline " + FUNC_DEF

contents = contents.replace(FUNC_DEF, FUNC_REDEF)

# replace the defines in the definitions part
DEFINES_START = """// ------------------------------------------------
// Create element storage
// ------------------------------------------------"""

DEFINES_END = """// ------------------------------------------------
// Program Globals
// ------------------------------------------------
"""

DEFINES_IDENTIFIER = "gslc_ts"
DEFINES_REDEF = "inline " + DEFINES_IDENTIFIER

defines_start_idx = contents.find(DEFINES_START)
defines_end_idx = contents.find(DEFINES_END)

part_in_which_to_replace = contents[defines_start_idx:defines_end_idx]
replaced_parts = part_in_which_to_replace.replace(DEFINES_IDENTIFIER, DEFINES_REDEF)
contents = contents.replace(part_in_which_to_replace, replaced_parts)

GSLC_output_filename = GUI_SLICE_BUILDER_FILE.replace(".h", ".hpp")

GSLC_outpath = os.path.join(DIRNAME, GSLC_output_filename)
with open(GSLC_outpath, "w+") as f:
	f.write(contents)




###########################################################
#
#					IMPORT INO FILE
#
###########################################################

REFERENCES_START = """// ------------------------------------------------
// Program Globals
// ------------------------------------------------
"""
REFERENCES_END = "//<Tick Callback !End!>"

for file in os.listdir(DIRNAME):
	if file.endswith(".ino"):
		GUI_SLICE_BUILDER_INO = file


GUI_SLICE_BUILDER_INO_FILEPATH = os.path.join(DIRNAME, GUI_SLICE_BUILDER_INO)

with open(GUI_SLICE_BUILDER_INO_FILEPATH) as f:
	contents = f.read()

os.remove(GUI_SLICE_BUILDER_INO_FILEPATH)
print(f"Removed {GUI_SLICE_BUILDER_INO}")



references_start_idx = contents.find(REFERENCES_START)
references_end_idx = contents.find(REFERENCES_END)

references_content = contents[references_start_idx:references_end_idx]

REFERENCES_HEADER_FILENAME = "GUISlice_references_content.hpp"
REFERENCES_HEADER_PATH = os.path.join(DIRNAME, REFERENCES_HEADER_FILENAME)

HEADER_GUARD_START_TEXT = """#ifndef _GUISLICE_REFERENCES_CONTENT_HPP
#define _GUISLICE_REFERENCES_CONTENT_HPP
"""

HEADER_GUARD_END_TEXT = """
#endif"""

with open(REFERENCES_HEADER_PATH, "w+") as f:
	f.write(HEADER_GUARD_START_TEXT)
	f.write(references_content)
	f.write(HEADER_GUARD_END_TEXT)

def find(name, path):
	for root, dirs, files in os.walk(path):
		if name in files:
			return os.path.join(root, name)
	

INCLUDE_DIR = "include"
INCLUDE_DIR_PATH = os.path.abspath(os.path.join(DIRNAME, os.pardir, INCLUDE_DIR))

def replace(filename, search_directory):
	file_to_replace = find(filename, search_directory)
	try:
		outpath = os.path.join(DIRNAME, filename)
		os.replace(outpath, file_to_replace)
		print(f"Succesfully replaced {outpath}!")
	except:
		print(f"Failed to replace {outpath}!")

replace(GSLC_output_filename, INCLUDE_DIR_PATH)

replace(REFERENCES_HEADER_FILENAME, INCLUDE_DIR_PATH)

for header in headers:
	replace(header, INCLUDE_DIR_PATH)

# TODO Export everything with same _SETUP_ into cpp array with said name
