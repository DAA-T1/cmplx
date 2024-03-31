import os
import sys
import argparse
import subprocess
import random
import statistics

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

parser.add_argument(
    "--repeat", type=int, help="Number of times to repeat the benchmark", default=1
)
parser.add_argument(
    "--algorithm",
    type=str,
    help="Algorithm to run",
    default=None,
    choices=["heap", "quick"],
)
parser.add_argument(
    "--output-raw",
    type=str,
    help="Output raw data",
)

parser.add_argument("--size", type=int, help="Size of the input data", default=100)

DOUBLE_MIN = -1.79769e308
DOUBLE_MAX = 1.79769e308


def rand_double():
    return random.uniform(DOUBLE_MIN, DOUBLE_MAX)


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

    if args.specific:
        filename = os.path.join(base_testfile_folder, args.specific)
    else:
        print(f"Size: {args.size}")
        filename = os.path.join(base_testfile_folder, "dyn_testfile.txt")

    if args.algorithm is None:
        print("Please specify an algorithm.")
        sys.exit(1)
    else:
        print(f"Algorithm: {args.algorithm}")
        command = f"{path_to_main} --{args.algorithm.lower()} --time --file {filename}"

    arr = []

    for _ in range(args.repeat):
        if args.random:
            generate_data(filename, args.size)

        output = subprocess.run(command, shell=True, capture_output=True, text=True)
        time_taken_nanoseconds = output.stdout.split("\n")[0].split(" ")[-1].strip("ns")
        arr += [int(time_taken_nanoseconds)]

    if args.output_raw:
        with open(args.output_raw, "w") as f:
            str_arr = map(str, arr)
            f.write("\n".join(str_arr) + "\n")

    avg = statistics.mean(arr)
    maxval = max(arr)
    minval = min(arr)
    std_dev = statistics.stdev(arr)
    print("=" * 80)
    print(f"Avg: {round(avg, 2):10.2f}ns")
    print(f"Max: {maxval:10.2f}ns")
    print(f"Min: {minval:10.2f}ns")
    print(f"Std: {round(std_dev, 2):10.2f}ns")
