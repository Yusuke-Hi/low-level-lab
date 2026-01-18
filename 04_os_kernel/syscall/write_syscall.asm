
write_syscall:     file format elf64-x86-64


Disassembly of section .text:

0000000000401000 <main>:
  401000:	f3 0f 1e fa          	endbr64 
  401004:	55                   	push   %rbp
  401005:	48 89 e5             	mov    %rsp,%rbp
  401008:	c7 45 f1 68 65 6c 6c 	movl   $0x6c6c6568,-0xf(%rbp)
  40100f:	66 c7 45 f5 6f 0a    	movw   $0xa6f,-0xb(%rbp)
  401015:	c6 45 f7 00          	movb   $0x0,-0x9(%rbp)
  401019:	4c 8d 45 f1          	lea    -0xf(%rbp),%r8
  40101d:	41 b9 06 00 00 00    	mov    $0x6,%r9d
  401023:	48 c7 c0 01 00 00 00 	mov    $0x1,%rax
  40102a:	48 c7 c7 01 00 00 00 	mov    $0x1,%rdi
  401031:	4c 89 c6             	mov    %r8,%rsi
  401034:	4c 89 ca             	mov    %r9,%rdx
  401037:	0f 05                	syscall 
  401039:	49 89 c0             	mov    %rax,%r8
  40103c:	4c 89 45 f8          	mov    %r8,-0x8(%rbp)
  401040:	b8 00 00 00 00       	mov    $0x0,%eax
  401045:	5d                   	pop    %rbp
  401046:	c3                   	ret    
