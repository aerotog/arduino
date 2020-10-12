from pathlib import Path
import glob
import os 

dir_path = os.path.dirname(os.path.realpath(__file__))

def get_flat_code(filename):
    flat_code = []

    path = dir_path + "/" + filename
    print(f"Flattening content from {path}")
    file = open(path, "r")
    lines = file.readlines()
    flat_code.append(f"//BEGIN CONTENT FROM {filename}\n")
    flat_code.extend(lines)
    flat_code.append(f"//END CONTENT FROM {filename}\n\n")

    return flat_code


if __name__ == "__main__":
    ino_files = glob.glob(f"{dir_path}/*.ino")

    if not any(ino_files):
        raise ValueError("No .ino files found")

    for ino in ino_files:    
        output = open(ino, "r").readlines()

        flattening = True
        while flattening:
            flattening = False
            new_output = []

            for line in output:
                if line.startswith('#include "'):
                    flattening = True

                    h_filename = line.split('"')[1]
                    flat_h = get_flat_code(h_filename)
                    # Including Arduino.h interferes with Tinkercad runtime
                    flat_h = [l for l in flat_h if "Arduino.h" not in l]
                    new_output.extend(flat_h)

                    cpp_filename = h_filename.replace(".h", ".cpp")
                    flat_cpp = get_flat_code(cpp_filename)
                    # Header already included above
                    flat_cpp = [l for l in flat_cpp if h_filename not in l]
                    new_output.extend(flat_cpp)

                else:
                    new_output.append(line)
            output = new_output

        ino_out = open(ino + ".flat", "w")
        ino_out.writelines(output)