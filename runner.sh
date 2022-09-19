#!/bin/bash
run() {
    gcc $1 -o output
    shift
    ./output $@
}