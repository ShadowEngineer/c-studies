#!/bin/bash
run() {
    if [[ -e $1 ]]; then
        clear
        gcc $1 -o output
        shift
        if [[ $1 == "-c" ]]; then
            ./output $@
        else
            cat test_input.txt | ./output $@
        fi
    fi
}