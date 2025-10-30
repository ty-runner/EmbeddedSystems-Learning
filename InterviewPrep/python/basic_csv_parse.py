def parse(filename):
    result = {}
    with open(filename, 'r') as f:
        for line in f:
            temp = line.strip().split(',')
            result[temp[0]] = result.get(temp[0],0) + int(temp[1])
        

    return result
# This runs only when you execute this file directly
if __name__ == "__main__":
        print(parse("scores.csv"))

