#!/usr/bin/python3
#
# Example program:
# Print the top ten states with the largest population in 2010.
#

import os

def read_api_key():
    filename = os.path.join(os.getenv("HOME"), ".census-api-key")
    with open(filename) as keyfile:
        key = keyfile.read().strip()
    return key

def main():
    key = read_api_key()
    print(key)

main()

