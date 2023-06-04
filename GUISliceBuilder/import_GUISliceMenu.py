import os

DIRNAME = os.path.dirname(__file__)

for file in os.listdir(DIRNAME):
	if file.endswith(".h") and "GSLC" in file:
		GUI_SLICE_BUILDER_FILE = file

GUI_SLICE_BUILDER_FILEPATH = os.path.join(DIRNAME, GUI_SLICE_BUILDER_FILE)

with open(GUI_SLICE_BUILDER_FILEPATH) as f:
	contents = f.read()

os.remove(GUI_SLICE_BUILDER_FILEPATH)


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

output_filename = GUI_SLICE_BUILDER_FILE.replace(".h", ".hpp")

outpath = os.path.join(DIRNAME, output_filename)
with open(outpath, "w+") as f:
	f.write(contents)

# TODO Import from .INO FILE INTO SOURCE FILE