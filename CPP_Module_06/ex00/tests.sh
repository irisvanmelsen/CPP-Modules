#!/bin/bash

# Function to run a single test case.
# $1 - Input literal (should include any necessary quotes for the test)
# $2 - Expected output patterns as array to allow multi-line and specific format checks
function test_case {
    echo "Testing input: $1"
    output=$(./ScalarConverter $1)
    fail=0
    for pattern in "${@:2}"; do
        if [[ ! "$output" == *"$pattern"* ]]; then
            echo "FAIL: Output '$output' does not match expected pattern '$pattern'."
            fail=1
        fi
    done
    if [ "$fail" -eq 0 ]; then
        echo "PASS: All patterns matched."
    fi
    echo ""
}

# Compile the C++ code
make all

# Define test cases with correct expectations
# Each line of expected output is passed as a separate pattern
echo "Starting the test cases..."
test_case a "char: 'a'" "int: 97" "float: 97.0f" "double: 97.0"
test_case 42 "char: '*'" "int: 42" "float: 42.0f" "double: 42.0"
test_case -42 "char: 'Non displayable'" "int: -42" "float: -42.0f" "double: -42.0"
test_case 42.0f "char: '*'" "int: 42" "float: 42.0f" "double: 42.0"
test_case 3.14 "char: 'Non displayable'" "int: 3" "float: 3.14f" "double: 3.14"
test_case -3.14 "char: 'Non displayable'" "int: -3" "float: -3.14" "double: -3.14"
test_case 0 "char: 'Non displayable'" "int: 0" "float: 0.0f" "double: 0.0"
test_case 0.0 "char: 'Non displayable'" "int: 0" "float: 0.0f" "double: 0.0"
test_case -inf "char: impossible" "int: impossible" "float: -inff" "double: -inf"
test_case +inf "char: impossible" "int: impossible" "float: inff" "double: +inf"
test_case nan "char: impossible" "int: impossible" "float: nanf" "double: nan"

echo "Tests completed."