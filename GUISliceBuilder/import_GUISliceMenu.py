import os

DIRNAME = os.path.dirname(__file__)

for file in os.listdir(DIRNAME):
	if file.endswith(".h") and "GSLC" in file:
		GUI_SLICE_BUILDER_FILE = file

GUI_SLICE_BUILDER_FILEPATH = os.path.join(DIRNAME, GUI_SLICE_BUILDER_FILE)

with open(GUI_SLICE_BUILDER_FILEPATH) as f:
	contents = f.read()

# os.remove(GUI_SLICE_BUILDER_FILEPATH)


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




# TODO Import from .INO FILE INTO SOURCE FILE
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

# os.remove(GUI_SLICE_BUILDER_INO_FILEPATH)

references_start_idx = contents.find(REFERENCES_START)
references_end_idx = contents.find(REFERENCES_END)

references_content = contents[references_start_idx:references_end_idx]

REFERENCES_HEADER_FILENAME = "GUISlice_references_content.hpp"
REFERENCES_HEADER_PATH = os.path.join(DIRNAME, REFERENCES_HEADER_FILENAME)

HEADER_GUARD_START_TEXT = """#ifndef GUISLICE_REFERENCES_CONTENT_HPP
#define GUISLICE_REFERENCES_CONTENT_HPP
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

file_to_replace = find(GSLC_output_filename, INCLUDE_DIR_PATH)
try:
	os.replace(GSLC_outpath, file_to_replace)
	print(f"Succesfully replaced {GSLC_output_filename}!")
except:
	pass

file_to_replace = find(REFERENCES_HEADER_FILENAME, INCLUDE_DIR_PATH)

try:
	os.replace(REFERENCES_HEADER_PATH, file_to_replace)
	print(f"Succesfully replaced {REFERENCES_HEADER_FILENAME}!")
except:
	pass