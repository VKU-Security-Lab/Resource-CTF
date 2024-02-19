import string

MSG = b"VSL{H1_Th3r3_1_4m_4_B4bY_3ncrypt10n_4lgor1thm}"

def encryption(msg):
    ct = []
    for char in msg:
        ct.append((123 * char + 18) % 256)
    return bytes(ct)

ct = encryption(MSG)
f = open('./msg.enc','w')
f.write(ct.hex())
f.close()
