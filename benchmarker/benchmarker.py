import os
import sys
import argparse
import subprocess
import random
import time
import pandas as pd
import re

VERSION = "0.0.2"

parser = argparse.ArgumentParser(
    description="Benchmarking tool", prog="benchmarker", usage="%(prog)s [options]"
)
parser.add_argument(
    "--generate",
    help="Generate random test files",
    action="store_true",
)
parser.add_argument(
    "--run",
    help="Run the benchmark",
    action="store_true",
)

parser.add_argument(
    "--algorithm",
    type=str,
    help="Algorithm to run",
    default=None,
    choices=["heap", "quick"],
)

parser.add_argument(
    "--gensize", type=int, help="Size of the data to generate", default=10
)

parser.add_argument(
    "--gencount", type=int, help="Number of Arrays to generate", default=1000
)

parser.add_argument(
    "--execpath",
    type=str,
    help="Path to main.exe",
    default=os.path.join(
        os.path.dirname(__file__),
        "..",
        "cmake-build-debug",
        "executables",
        "main",
    ),
)

parser.add_argument(
    "--testspath",
    type=str,
    help="Path to folder containing testfiles",
    default=os.path.join(os.path.dirname(__file__), "..", "testfiles"),
)


parser.add_argument(
    "--seed", type=int, help="Seed for random number generator", default=42
)

parser.add_argument(
    "--output", type=str, help="Output folder name (relative)", default="output"
)


# important: actually putting the values in the range (e308), will make the RNG just print inf or -inf
DOUBLE_MIN = -10e5
DOUBLE_MAX = 10e5


def rand_double():
    return random.uniform(DOUBLE_MIN, DOUBLE_MAX)


def generate_data(size, gen_count):
    data = [
        [rand_double() + rand_double() * 1j for _ in range(size)]
        for _ in range(gen_count)
    ]

    return data


def write_data_to_file(filen, data, size, gen_count):
    with open(filen, "w") as f:
        f.write(f"{gen_count} {size}\n")
        for d in data:
            txt_form = [f"{d.real:10.2f} {d.imag:+10.2f}i" for d in d]
            f.write(", ".join(txt_form) + "\n")


def get_files_in_test_directory(dir_path):

    for _, dirs, files in os.walk(dir_path):
        for file in files:
            if file.endswith(".txt") and file.startswith("testcase_"):
                yield file


def sort(data, reverse=False):
    for i in range(len(data)):
        data[i] = sorted(data[i], key=lambda x: (abs(x), x.real, x.imag), reverse=reverse)
    return data


def run_generator(args):

    print(f"Generating {args.gencount} arrays of size {args.gensize}")
    if not os.path.exists(args.testspath):
        print("Testfiles folder was not found. Please create a folder.")
        sys.exit(1)

    data = generate_data(args.gensize, args.gencount)

    fname = os.path.join(args.testspath, f"testcase_size{args.gensize}_shuffle.txt")
    write_data_to_file(fname, data, args.gensize, args.gencount)
    print("Wrote to file: ", fname)

    fname = os.path.join(args.testspath, f"testcase_size{args.gensize}_sorted.txt")
    data = sort(data)

    write_data_to_file(fname, data, args.gensize, args.gencount)
    print("Wrote to file: ", fname)

    fname = os.path.join(args.testspath, f"testcase_size{args.gensize}_reverse.txt")
    data = sort(data, reverse=True)
    write_data_to_file(fname, data, args.gensize, args.gencount)
    print("Wrote to file: ", fname)


def run_benchmark(args):

    if not os.path.exists(args.execpath):
        print("Executable not found.")
        sys.exit(1)

    if not os.path.exists(args.testspath):
        print("Testfiles folder was not found.")
        sys.exit(1)

    if not os.path.exists(args.output):
        os.makedirs(args.output)

    if args.algorithm is None:
        print("Please specify an algorithm.")
        sys.exit(1)

    for file in get_files_in_test_directory(args.testspath):
        start = time.time()

        print(f"Running testfile {file} with {args.algorithm} algorithm")

        command = f"{args.execpath} --{args.algorithm.lower()} --time --comparecount --file {os.path.join(args.testspath, file)}"
        
        output_df = pd.DataFrame(columns=["time", "comparison_count"])

        algo_output = subprocess.run(command, shell=True, capture_output=True, text=True)

        times = re.findall(r"Time: (\d+)ns", algo_output.stdout)
        comparisons = re.findall(r"Comparisons: (\d+)", algo_output.stdout)

        output_df["time"] = times
        output_df["comparison_count"] = comparisons

        outputpath = os.path.join(args.output, f"output_{args.algorithm}_{file}.csv")

        output_df.to_csv(outputpath, index=False)
            
        end = time.time()
        print(f"Saved output to {outputpath}. Took {(end - start):.4f}seconds")


if __name__ == "__main__":
    args = parser.parse_args()

    if (args.generate and args.run) or (not args.generate and not args.run):
        print("Please specify either --generate or --run.")
        sys.exit(1)

    random.seed(args.seed)

    if args.generate:
        run_generator(args)
    elif args.run:
        run_benchmark(args)

    # avg = statistics.mean(arr)
    # maxval = max(arr)
    # minval = min(arr)
    # std_dev = statistics.stdev(arr)
    # print("=" * 80)
    # print(f"Avg: {round(avg, 2):10.2f}ns")
    # print(f"Max: {maxval:10.2f}ns")
    # print(f"Min: {minval:10.2f}ns")
    # print(f"Std: {round(std_dev, 2):10.2f}ns")
