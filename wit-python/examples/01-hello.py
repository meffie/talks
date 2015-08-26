#!/usr/bin/python3

import time

def release_the_cats():
    pass

print("Commencing countdown!")
for countdown in range(10, 0, -1):
    print(countdown)
    if countdown == 3:
        print("almost there!")
    time.sleep(1)

print("RELEASE THE CATS!")
release_the_cats()


