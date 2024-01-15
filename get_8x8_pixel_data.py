from PIL import Image
import os, sys


COLOR_MAP = {
    "155615": "0",
    "489848": "1",
    "13917215": "2",
    "15518815": "3"
}

def image_to_matrix(filename) -> list[str]:
    """
    Takes a PNG file and returns a list of strings representing the 8x8 pixel data
    based on the COLOR_MAP
    """
    im = Image.open(filename, 'r')
    rgb_im = im.convert('RGB')
    width, height = im.size

    img_matrix = []

    for w in range(width):
        row = ""
        for h in range(height):
            r, g, b = rgb_im.getpixel((w, h))
            if r: # If transparent, then assume black
                row += COLOR_MAP.get(str(r) + str(g) + str(b))
            else:
                row += "0"

        img_matrix.append(row)


    return img_matrix

if __name__ == '__main__':
    
    directory = sys.argv[1]

    print("String imgs[] = {")

    # Get directory listing and sort in alphabetical order
    # Should you be seeking some kind of animation
    dir = os.listdir(directory)
    dir = sorted(dir)

    for filename in dir:
        if filename.endswith(".png"):
            fname = directory + "/" + filename

            f = image_to_matrix(fname)
            space_name = " ".join(f)

            if len(space_name) < 64:
                continue

            print(f'"{space_name}",')

            continue
        else:
            continue

    print("};")

