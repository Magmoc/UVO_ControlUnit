from PIL import Image
import os
import numpy as np

BASE_DIR = os.path.dirname(os.path.abspath(__file__))

test_image_in = "monke.jpg"
test_image_out = "test_image.jpg"
test_image_array_out = "monke.h"
image_header_out = "monke.txt"

test_image_in_path = os.path.join(BASE_DIR, test_image_in)
test_header_out_path = os.path.join(BASE_DIR, image_header_out)
test_image_out_path = os.path.join(BASE_DIR, test_image_out)
# test_image_arr_out_path = os.path.join(BASE_DIR, test_image_array_out)

tft_screen_size_pixels = np.array([320, 240])
resolution_scale = 0.25

base = Image.open(test_image_in_path)
base_resized = base.resize((480,320))
base_resized.save(test_image_out_path)
# base.save(image_header_out)

# base.save(test_image_out_path, bitmap_format="bmp")
# base.save(test_image_out_jpg_path, bitmap_format="jpg")
bmp_arr = np.array(base_resized)

def rgb_to_hex(rgb):
    r, g, b = rgb
    return f"0x{r:02x}{g:02x}{b:02x}"


def convert_to_bmp():
	with open(test_image_arr_out_path, "w+") as f:
		string = '''#ifndef IMAGE_HEADER_H\n#define IMAGE_HEADER_H\n\n'''
		string += " const int image[] = { \n"
		
		for row in range(bmp_arr.shape[0]):
			rgb_row = np.array(bmp_arr[row,:,:])		
			rgb_row_hex = np.array([rgb_to_hex(x) for x in rgb_row])
			string += r"{" + ",".join(rgb_row_hex) + r"},"
		
		# remove last ,
		string = string[:-1] 
		string += "\n };"
		string += '\n #endif'
		f.write(string)

def convert_jpg_to_headerfile():
	import io
	from PIL import Image

	img = base_resized

	img_byte_arr = io.BytesIO()
	img.save(img_byte_arr, format='JPEG')
	img_byte_arr = img_byte_arr.getvalue()
	print(img_byte_arr)
	# split = img_byte_arr.split(r"\x")
	
	# print(img_byte_arr)
	
	# with open(test_image_arr_out_path, "w+") as f:
	# 	string = '''#ifndef IMAGE_HEADER_H\n#define IMAGE_HEADER_H\n\n'''

	# 	f.write(string)


def convert_to_bmp_stream():
	with open(test_image_arr_out_path, "w+") as f:
		# string = '''#ifndef IMAGE_HEADER_H\n#define IMAGE_HEADER_H\n\n'''
		# string += " const int image[] = { \n"
		string = ""
		for row in range(bmp_arr.shape[0]):
			for col in range(bmp_arr.shape[1]):
				rgb = np.array(bmp_arr[row,col,:])		
				string += f"{rgb_to_hex(rgb)},\n"
		
		# # remove last ,
		# string = string[:-1] 
		# string += "\n };"
		# string += '\n #endif'
		f.write(string)

convert_jpg_to_headerfile()

# convert_to_bmp_stream()

