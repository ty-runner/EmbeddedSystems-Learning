
from parse_logs import parse_log_file

def test_basic_count(tmp_path):
    log_file = tmp_path / "log.csv"
    log_file.write_text("INFO,ok\nERROR,disk\nERROR,net\n")
    result = parse_log_file(str(log_file))
    assert result["ERROR"] == 2
    assert result["INFO"] == 1
    print("Parse Logs tests passed.")

test_basic_count(__import__("pathlib").Path("."))
