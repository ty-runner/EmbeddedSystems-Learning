def parse_config(filename):
    result = {}
    with open(filename,'r') as f:
        for line in f:
            key, value = line.strip().split('=')
            result[key.strip()] = value.strip()

    return result

if __name__ == "__main__":
    print(parse_config("config.txt"))
