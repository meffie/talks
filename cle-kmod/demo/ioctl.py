#!/usr/bin/python3
#
# ioctl demo
#
# usage: ioctl.py [<number>]
#

import sys
from fcntl import ioctl
from struct import pack, unpack

PASSWORD_GET_LENGTH = 0x80047000
PASSWORD_SET_LENGTH = 0x40047001


def get_length():
    value = 0
    buffer = bytearray(pack('i', value))
    with open('/dev/password', 'rb') as f:
       ioctl(f.fileno(), PASSWORD_GET_LENGTH, buffer)
    value, = unpack('i', buffer)
    print("password length is", value)


def set_length(value):
    print("setting password length to", value)
    buffer = bytearray(pack('i', value))
    with open('/dev/password', 'wb') as f:
       ioctl(f.fileno(), PASSWORD_SET_LENGTH, buffer)


def main():
    args = sys.argv[1:]
    if len(args) == 0:
        get_length()
    elif len(args) == 1:
        set_length(int(args[0]))
    else:
        print("usage: ioctl.py [<number>]")


main()
