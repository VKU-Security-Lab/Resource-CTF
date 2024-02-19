from pwn import *
from hashlib import sha256

r = remote('127.0.0.1', 9000)

flag = ""

while True:
    for i in range(33, 126):
        r.recvuntil(b"$ ")
        r.sendline(b"2")
        r.recvuntil(b"$ ")
        r.sendline(flag.encode() + b"\x00")
        r.recvuntil(b"$ ")
        hashed = sha256(b"\x00" * (len(flag)) + chr(i).encode()).digest().hex()
        r.sendline(hashed.encode())
        response = r.recvline().decode()
        if "Validated" in response:
            flag += chr(i)
            print(flag)
            if "}" in flag:
                print("Flag: " + flag)
                exit()
            break