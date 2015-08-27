#!/usr/bin/python3
#
# Example program:
# Print the top ten states with the largest population in 2010.
#

import os
import urllib.request

def read_api_key():
    filename = os.path.join(os.getenv("HOME"), ".census-api-key")
    with open(filename) as keyfile:
        key = keyfile.read().strip()
    return key

def request_census_data(key):
    url = "http://api.census.gov/data/2010/sf1?key={0}&get=P0010001,NAME&for=state:*".format(key)
    request = urllib.request.urlopen(url)
    text = request.read().decode()
    return text

def main():
    key = read_api_key()
    text = request_census_data(key)
    print(text)

main()

