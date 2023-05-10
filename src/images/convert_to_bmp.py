from PIL import Image
import os

BASE_DIR = os.path.dirname(os.path.abspath(__file__))

test_image_in = "test_image.jpg"
test_image_out = "test_image.bmp"

test_image_in_path = os.path.join(BASE_DIR, test_image_in)
test_image_out_path = os.path.join(BASE_DIR, test_image_out)

tft_screen_size_pixels = (320, 240)

base = Image.open(test_image_in_path)
base = base.resize(tft_screen_size_pixels)
base.save(test_image_out_path)
