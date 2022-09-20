#!/bin/bash
run() {
    clear
    gcc $1 -o output
    shift
    ./output $@
}