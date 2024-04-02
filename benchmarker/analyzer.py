import os
import pandas as pd
import re
from rich.console import Console
from rich.table import Table
import math
import plotly.express as px
console = Console()

def pretty_print_data(dfs, size):

    table = Table(title=f"Size {size} | n log n: {round(size * math.log(size, 2), 4)} | 1.5 n log n: {round(size * 1.5 * math.log(size, 2), 4)}")
    table.add_column("")
    table.add_column("Sorted")
    table.add_column("Reverse")
    table.add_column("Random Shuffle")
    table.add_row("Comparisons", str(dfs[size]['sorted']["comparison_count"].mean()), str(dfs[size]['reverse']["comparison_count"].mean()), str(dfs[size]['shuffle']["comparison_count"].mean()))
    table.add_row("Time", str(dfs[size]['sorted']["time"].mean()), str(dfs[size]['reverse']["time"].mean()), str(dfs[size]['shuffle']["time"].mean()))

    console.print(table)

outfile_loc = "output"

heapdfs = {}
quickdfs = {}

for _, _, files in os.walk(outfile_loc):
    for file in files:

        size = int(re.findall(r'size(\d+)', file)[0])
        manip_type = re.findall(r'\d_(\w+).txt', file)[0]

        if "_heap_" in file:
            if size not in heapdfs:
                heapdfs[size] = {}
                heapdfs[size][manip_type] = pd.read_csv(outfile_loc + "/" + file)
            else:
                heapdfs[size][manip_type] = pd.read_csv(outfile_loc + "/" + file)

        elif "_quick_" in file:
            
            if size not in quickdfs:
                quickdfs[size] = {}
                quickdfs[size][manip_type] = pd.read_csv(outfile_loc + "/" + file)
            else:
                quickdfs[size][manip_type] = pd.read_csv(outfile_loc + "/" + file)
                

print("HEAP")
pretty_print_data(heapdfs, 10)
pretty_print_data(heapdfs, 100)
pretty_print_data(heapdfs, 1000)
pretty_print_data(heapdfs, 10000)

print("QUICK")
pretty_print_data(quickdfs, 10)
pretty_print_data(quickdfs, 100)
pretty_print_data(quickdfs, 1000)
pretty_print_data(quickdfs, 10000)

def get_summarized_data(dfs):
    data = pd.DataFrame(columns=["Size", "Type", "Time", "Comparisons"])

    for size in dfs:
        for manip_type in dfs[size]:
            
            tempdf = pd.DataFrame({"Size": size, "Type": manip_type, "Time": dfs[size][manip_type]["time"].mean(), "Comparisons": dfs[size][manip_type]["comparison_count"].mean()}, index=[0])

            data = pd.concat([data, tempdf], ignore_index=True)

    return data

heap_data = get_summarized_data(heapdfs)
quick_data = get_summarized_data(quickdfs)

heap_data["Algorithm"] = "heap"
quick_data["Algorithm"] = "quick"

data = pd.concat([heap_data, quick_data])

# Graph of Time Taken -> Worst, Best, Average vs. Size for heap sort
