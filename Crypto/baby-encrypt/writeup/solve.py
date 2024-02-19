def decryption(ct):
    # Find the modular multiplicative inverse of 123 modulo 256
    inv = 0
    for i in range(256):
        if (123 * i) % 256 == 1:
            inv = i
            break
    pt = []
    for char in ct:
        pt.append((inv * (char - 18)) % 256)
    return bytes(pt)

f = open('./msg.enc','r')
ct = bytes.fromhex(f.read())
f.close()
flag = decryption(ct)
print(flag)