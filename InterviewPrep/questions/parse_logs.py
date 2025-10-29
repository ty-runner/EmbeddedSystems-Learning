
def parse_log_file(log_file_str):
    print(log_file_str)
    res = {}
    with open(log_file_str, "r") as f:
        for line in f:
            print(line.split(','))
            spl = line.split(',')
            res[spl[0]] = res.get(spl[0], 0) + 1
    return res
