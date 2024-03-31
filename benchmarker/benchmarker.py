import os
import sys
import argparse
import subprocess
import random

VERSION = "0.0.1"

parser = argparse.ArgumentParser(
    description="Benchmarking tool", prog="benchmarker", usage="%(prog)s [options]"
)
parser.add_argument(
    "--random",
    help="Randomize the input data",
    default=False,
    action="store_true",
)
parser.add_argument(
    "--specific",
    type=str,
    help="Specific input data",
)

# TODO: Add a flag to specify number of times the benchmark should run
# TODO: Add a flag to know which algorithm to run (heap or quick)
# TODO: Add a flag to specify the output file with raw data if required

parser.add_argument("--size", type=int, help="Size of the input data", default=100)

DOUBLE_MIN = -1000
DOUBLE_MAX = 1000


def rand_double():
    random.uniform(DOUBLE_MIN, DOUBLE_MAX)


def generate_data(filen, size):
    with open(filen, "w") as f:
        for _ in range(size - 1):
            f.write(f"{rand_double()} {rand_double():+f}i, ")
        f.write(f"{rand_double()} {rand_double():+f}i")


if __name__ == "__main__":
    args = parser.parse_args()
    if (args.random and args.specific) or (not args.random and not args.specific):
        print("Please specify either --random or --specific.")
        sys.exit(1)

    print(f"Benchmarker v{VERSION}")

    path_to_main = os.path.join(
        os.path.dirname(__file__),
        "..",
        "cmake-build-debug",
        "executables",
        "main",
    )

    if not os.path.exists(path_to_main):
        print("Executable not found.")
        sys.exit(1)

    base_testfile_folder = os.path.join(os.path.dirname(__file__), "..", "testfiles")
    filename = os.path.join(base_testfile_folder, "dyn_testfile.txt")

    if args.specific:
        print("Using specific file. Ignoring --random and --size.")
        filename = os.path.join(base_testfile_folder, args.specific)
    else:
        print(f"Using random data. The random data size is {args.size}.")
        generate_data(filename, args.size)

    command = f"{path_to_main} --heap --time --file {filename}"

    output = subprocess.run(command, shell=True, capture_output=True, text=True)
    time_taken_nanoseconds = output.stdout.split("\n")[0].split(" ")[-1].strip("ns")
    print(time_taken_nanoseconds)
