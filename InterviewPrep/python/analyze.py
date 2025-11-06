import numpy as np

def determine_bit_error(expected, actual):
    total_err = 0
    total_bits = 0
    print(expected)
    for i in range(len(expected)):
        exp = expected[i]
        act = actual[i]
        for c in range(len(exp)):
            if exp[c] != act[c]:
                total_err += 1
            total_bits +=1

    return float(total_err / total_bits)
def determine_snr(expected, actual):
    diff = np.mean((np.abs(expected-actual)**2))
    exp_mean = np.mean(expected*expected)
    return 10 * np.log(exp_mean / diff)

def analyze_performance(filename):
    rx = []
    tx = []
    exp_bits = []
    recv_bits = []

    with open(filename, 'r') as f:
        for line in f:
            t, s_tx, s_rx, e_bits, r_bits = line.strip().split(',')
            rx.append(float(s_rx))
            tx.append(float(s_tx))

            exp_bits.append(e_bits)
            recv_bits.append(r_bits)
    error = np.abs(np.array(tx) - np.array(rx))
    print(determine_snr(np.array(tx), np.array(rx)))
    print(determine_bit_error(exp_bits, recv_bits))
    error_95 = np.percentile(error, 95)
    print(f"95th percentile error: {error_95: .4f}")
    return None

if __name__ == "__main__":
    analyze_performance("performance_log.csv")
