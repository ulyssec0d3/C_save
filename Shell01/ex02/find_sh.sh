#!/bin/bash

find . -type f -name "*.sh" -printf "%f\n" | sed -e 's/\.sh$//'
