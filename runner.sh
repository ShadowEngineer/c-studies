#!/bin/bash

# compiles and executes the given C source file.
run_file() {
    if [[ -e $1 ]]; then
        clear
        gcc $1 -o output
        shift

        # test inputs can be given to the file to test various features if the test inputs are massive.
        if [[ $1 == "-c" ]]; then
            ./output $@
        else
            cat test_input.txt | ./output $@
        fi
    fi
}
