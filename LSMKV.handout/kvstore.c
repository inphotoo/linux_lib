
kvstore.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <_ZN5utilsL6_mkdirERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE>:
     * Create directory
     * @param path directory to be created.
     * @return 0 if directory is created successfully, -1 otherwise.
     */
    static inline int _mkdir(const std::string &path)
    {
       0:	55                   	push   %rbp
       1:	48 89 e5             	mov    %rsp,%rbp
       4:	48 83 ec 10          	sub    $0x10,%rsp
       8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
        return ::mkdir(path.c_str(), 0775);
       c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
      10:	48 89 c7             	mov    %rax,%rdi
      13:	e8 00 00 00 00       	call   18 <_ZN5utilsL6_mkdirERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x18>
      18:	be fd 01 00 00       	mov    $0x1fd,%esi
      1d:	48 89 c7             	mov    %rax,%rdi
      20:	e8 00 00 00 00       	call   25 <_ZN5utilsL6_mkdirERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x25>
    }
      25:	c9                   	leave  
      26:	c3                   	ret    

0000000000000027 <_ZL19MurmurHash3_x64_128PKvijPv>:
  unsigned int hash[4] = {0};
  MurmurHash3_x64_128(&key, sizeof(key), 1, hash);
*/
static inline void MurmurHash3_x64_128 ( const void * key, const int len,
                           const uint32_t seed, void * out )
{
      27:	55                   	push   %rbp
      28:	48 89 e5             	mov    %rsp,%rbp
      2b:	48 81 ec b0 00 00 00 	sub    $0xb0,%rsp
      32:	48 89 bd 68 ff ff ff 	mov    %rdi,-0x98(%rbp)
      39:	89 b5 64 ff ff ff    	mov    %esi,-0x9c(%rbp)
      3f:	89 95 60 ff ff ff    	mov    %edx,-0xa0(%rbp)
      45:	48 89 8d 58 ff ff ff 	mov    %rcx,-0xa8(%rbp)
  const uint8_t * data = (const uint8_t*)key;
      4c:	48 8b 85 68 ff ff ff 	mov    -0x98(%rbp),%rax
      53:	48 89 45 a8          	mov    %rax,-0x58(%rbp)
  const int nblocks = len / 16;
      57:	8b 85 64 ff ff ff    	mov    -0x9c(%rbp),%eax
      5d:	8d 50 0f             	lea    0xf(%rax),%edx
      60:	85 c0                	test   %eax,%eax
      62:	0f 48 c2             	cmovs  %edx,%eax
      65:	c1 f8 04             	sar    $0x4,%eax
      68:	89 85 7c ff ff ff    	mov    %eax,-0x84(%rbp)

  uint64_t h1 = seed;
      6e:	8b 85 60 ff ff ff    	mov    -0xa0(%rbp),%eax
      74:	48 89 45 88          	mov    %rax,-0x78(%rbp)
  uint64_t h2 = seed;
      78:	8b 85 60 ff ff ff    	mov    -0xa0(%rbp),%eax
      7e:	48 89 45 90          	mov    %rax,-0x70(%rbp)

  const uint64_t c1 = BIG_CONSTANT(0x87c37b91114253d5);
      82:	48 b8 d5 53 42 11 91 	movabs $0x87c37b91114253d5,%rax
      89:	7b c3 87 
      8c:	48 89 45 b0          	mov    %rax,-0x50(%rbp)
  const uint64_t c2 = BIG_CONSTANT(0x4cf5ad432745937f);
      90:	48 b8 7f 93 45 27 43 	movabs $0x4cf5ad432745937f,%rax
      97:	ad f5 4c 
      9a:	48 89 45 b8          	mov    %rax,-0x48(%rbp)

  const uint64_t * blocks = (const uint64_t *)(data);
      9e:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
      a2:	48 89 45 c0          	mov    %rax,-0x40(%rbp)

  for(int i = 0; i < nblocks; i++)
      a6:	c7 85 78 ff ff ff 00 	movl   $0x0,-0x88(%rbp)
      ad:	00 00 00 
      b0:	e9 63 01 00 00       	jmp    218 <_ZL19MurmurHash3_x64_128PKvijPv+0x1f1>
  {
    uint64_t k1 = getblock64(blocks,i*2+0);
      b5:	8b 85 78 ff ff ff    	mov    -0x88(%rbp),%eax
      bb:	8d 14 00             	lea    (%rax,%rax,1),%edx
      be:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
      c2:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
      c6:	89 55 84             	mov    %edx,-0x7c(%rbp)
  return p[i];
      c9:	8b 45 84             	mov    -0x7c(%rbp),%eax
      cc:	48 98                	cltq   
      ce:	48 8d 14 c5 00 00 00 	lea    0x0(,%rax,8),%rdx
      d5:	00 
      d6:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
      da:	48 01 d0             	add    %rdx,%rax
      dd:	48 8b 00             	mov    (%rax),%rax
    uint64_t k1 = getblock64(blocks,i*2+0);
      e0:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
    uint64_t k2 = getblock64(blocks,i*2+1);
      e4:	8b 85 78 ff ff ff    	mov    -0x88(%rbp),%eax
      ea:	01 c0                	add    %eax,%eax
      ec:	8d 50 01             	lea    0x1(%rax),%edx
      ef:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
      f3:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
      f7:	89 55 80             	mov    %edx,-0x80(%rbp)
  return p[i];
      fa:	8b 45 80             	mov    -0x80(%rbp),%eax
      fd:	48 98                	cltq   
      ff:	48 8d 14 c5 00 00 00 	lea    0x0(,%rax,8),%rdx
     106:	00 
     107:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
     10b:	48 01 d0             	add    %rdx,%rax
     10e:	48 8b 00             	mov    (%rax),%rax
    uint64_t k2 = getblock64(blocks,i*2+1);
     111:	48 89 45 d8          	mov    %rax,-0x28(%rbp)

    k1 *= c1; k1  = ROTL64(k1,31); k1 *= c2; h1 ^= k1;
     115:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
     119:	48 ba d5 53 42 11 91 	movabs $0x87c37b91114253d5,%rdx
     120:	7b c3 87 
     123:	48 0f af c2          	imul   %rdx,%rax
     127:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
     12b:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
     12f:	be 1f 00 00 00       	mov    $0x1f,%esi
     134:	48 89 c7             	mov    %rax,%rdi
     137:	e8 00 00 00 00       	call   13c <_ZL19MurmurHash3_x64_128PKvijPv+0x115>
     13c:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
     140:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
     144:	48 ba 7f 93 45 27 43 	movabs $0x4cf5ad432745937f,%rdx
     14b:	ad f5 4c 
     14e:	48 0f af c2          	imul   %rdx,%rax
     152:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
     156:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
     15a:	48 31 45 88          	xor    %rax,-0x78(%rbp)

    h1 = ROTL64(h1,27); h1 += h2; h1 = h1*5+0x52dce729;
     15e:	48 8b 45 88          	mov    -0x78(%rbp),%rax
     162:	be 1b 00 00 00       	mov    $0x1b,%esi
     167:	48 89 c7             	mov    %rax,%rdi
     16a:	e8 00 00 00 00       	call   16f <_ZL19MurmurHash3_x64_128PKvijPv+0x148>
     16f:	48 89 45 88          	mov    %rax,-0x78(%rbp)
     173:	48 8b 45 90          	mov    -0x70(%rbp),%rax
     177:	48 01 45 88          	add    %rax,-0x78(%rbp)
     17b:	48 8b 55 88          	mov    -0x78(%rbp),%rdx
     17f:	48 89 d0             	mov    %rdx,%rax
     182:	48 c1 e0 02          	shl    $0x2,%rax
     186:	48 01 d0             	add    %rdx,%rax
     189:	48 05 29 e7 dc 52    	add    $0x52dce729,%rax
     18f:	48 89 45 88          	mov    %rax,-0x78(%rbp)

    k2 *= c2; k2  = ROTL64(k2,33); k2 *= c1; h2 ^= k2;
     193:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
     197:	48 ba 7f 93 45 27 43 	movabs $0x4cf5ad432745937f,%rdx
     19e:	ad f5 4c 
     1a1:	48 0f af c2          	imul   %rdx,%rax
     1a5:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
     1a9:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
     1ad:	be 21 00 00 00       	mov    $0x21,%esi
     1b2:	48 89 c7             	mov    %rax,%rdi
     1b5:	e8 00 00 00 00       	call   1ba <_ZL19MurmurHash3_x64_128PKvijPv+0x193>
     1ba:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
     1be:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
     1c2:	48 ba d5 53 42 11 91 	movabs $0x87c37b91114253d5,%rdx
     1c9:	7b c3 87 
     1cc:	48 0f af c2          	imul   %rdx,%rax
     1d0:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
     1d4:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
     1d8:	48 31 45 90          	xor    %rax,-0x70(%rbp)

    h2 = ROTL64(h2,31); h2 += h1; h2 = h2*5+0x38495ab5;
     1dc:	48 8b 45 90          	mov    -0x70(%rbp),%rax
     1e0:	be 1f 00 00 00       	mov    $0x1f,%esi
     1e5:	48 89 c7             	mov    %rax,%rdi
     1e8:	e8 00 00 00 00       	call   1ed <_ZL19MurmurHash3_x64_128PKvijPv+0x1c6>
     1ed:	48 89 45 90          	mov    %rax,-0x70(%rbp)
     1f1:	48 8b 45 88          	mov    -0x78(%rbp),%rax
     1f5:	48 01 45 90          	add    %rax,-0x70(%rbp)
     1f9:	48 8b 55 90          	mov    -0x70(%rbp),%rdx
     1fd:	48 89 d0             	mov    %rdx,%rax
     200:	48 c1 e0 02          	shl    $0x2,%rax
     204:	48 01 d0             	add    %rdx,%rax
     207:	48 05 b5 5a 49 38    	add    $0x38495ab5,%rax
     20d:	48 89 45 90          	mov    %rax,-0x70(%rbp)
  for(int i = 0; i < nblocks; i++)
     211:	83 85 78 ff ff ff 01 	addl   $0x1,-0x88(%rbp)
     218:	8b 85 78 ff ff ff    	mov    -0x88(%rbp),%eax
     21e:	3b 85 7c ff ff ff    	cmp    -0x84(%rbp),%eax
     224:	0f 8c 8b fe ff ff    	jl     b5 <_ZL19MurmurHash3_x64_128PKvijPv+0x8e>
  }

  const uint8_t * tail = (const uint8_t*)(data + nblocks*16);
     22a:	8b 85 7c ff ff ff    	mov    -0x84(%rbp),%eax
     230:	c1 e0 04             	shl    $0x4,%eax
     233:	48 63 d0             	movslq %eax,%rdx
     236:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
     23a:	48 01 d0             	add    %rdx,%rax
     23d:	48 89 45 c8          	mov    %rax,-0x38(%rbp)

  uint64_t k1 = 0;
     241:	48 c7 45 98 00 00 00 	movq   $0x0,-0x68(%rbp)
     248:	00 
  uint64_t k2 = 0;
     249:	48 c7 45 a0 00 00 00 	movq   $0x0,-0x60(%rbp)
     250:	00 

  switch(len & 15)
     251:	8b 85 64 ff ff ff    	mov    -0x9c(%rbp),%eax
     257:	83 e0 0f             	and    $0xf,%eax
     25a:	83 f8 0f             	cmp    $0xf,%eax
     25d:	0f 87 f3 01 00 00    	ja     456 <_ZL19MurmurHash3_x64_128PKvijPv+0x42f>
     263:	89 c0                	mov    %eax,%eax
     265:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
     26c:	00 
     26d:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 274 <_ZL19MurmurHash3_x64_128PKvijPv+0x24d>
     274:	8b 04 02             	mov    (%rdx,%rax,1),%eax
     277:	48 98                	cltq   
     279:	48 8d 15 00 00 00 00 	lea    0x0(%rip),%rdx        # 280 <_ZL19MurmurHash3_x64_128PKvijPv+0x259>
     280:	48 01 d0             	add    %rdx,%rax
     283:	3e ff e0             	notrack jmp *%rax
  {
  case 15: k2 ^= ((uint64_t)tail[14]) << 48;
     286:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
     28a:	48 83 c0 0e          	add    $0xe,%rax
     28e:	0f b6 00             	movzbl (%rax),%eax
     291:	0f b6 c0             	movzbl %al,%eax
     294:	48 c1 e0 30          	shl    $0x30,%rax
     298:	48 31 45 a0          	xor    %rax,-0x60(%rbp)
  case 14: k2 ^= ((uint64_t)tail[13]) << 40;
     29c:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
     2a0:	48 83 c0 0d          	add    $0xd,%rax
     2a4:	0f b6 00             	movzbl (%rax),%eax
     2a7:	0f b6 c0             	movzbl %al,%eax
     2aa:	48 c1 e0 28          	shl    $0x28,%rax
     2ae:	48 31 45 a0          	xor    %rax,-0x60(%rbp)
  case 13: k2 ^= ((uint64_t)tail[12]) << 32;
     2b2:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
     2b6:	48 83 c0 0c          	add    $0xc,%rax
     2ba:	0f b6 00             	movzbl (%rax),%eax
     2bd:	0f b6 c0             	movzbl %al,%eax
     2c0:	48 c1 e0 20          	shl    $0x20,%rax
     2c4:	48 31 45 a0          	xor    %rax,-0x60(%rbp)
  case 12: k2 ^= ((uint64_t)tail[11]) << 24;
     2c8:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
     2cc:	48 83 c0 0b          	add    $0xb,%rax
     2d0:	0f b6 00             	movzbl (%rax),%eax
     2d3:	0f b6 c0             	movzbl %al,%eax
     2d6:	48 c1 e0 18          	shl    $0x18,%rax
     2da:	48 31 45 a0          	xor    %rax,-0x60(%rbp)
  case 11: k2 ^= ((uint64_t)tail[10]) << 16;
     2de:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
     2e2:	48 83 c0 0a          	add    $0xa,%rax
     2e6:	0f b6 00             	movzbl (%rax),%eax
     2e9:	0f b6 c0             	movzbl %al,%eax
     2ec:	48 c1 e0 10          	shl    $0x10,%rax
     2f0:	48 31 45 a0          	xor    %rax,-0x60(%rbp)
  case 10: k2 ^= ((uint64_t)tail[ 9]) << 8;
     2f4:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
     2f8:	48 83 c0 09          	add    $0x9,%rax
     2fc:	0f b6 00             	movzbl (%rax),%eax
     2ff:	0f b6 c0             	movzbl %al,%eax
     302:	48 c1 e0 08          	shl    $0x8,%rax
     306:	48 31 45 a0          	xor    %rax,-0x60(%rbp)
  case  9: k2 ^= ((uint64_t)tail[ 8]) << 0;
     30a:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
     30e:	48 83 c0 08          	add    $0x8,%rax
     312:	0f b6 00             	movzbl (%rax),%eax
     315:	0f b6 c0             	movzbl %al,%eax
     318:	48 31 45 a0          	xor    %rax,-0x60(%rbp)
           k2 *= c2; k2  = ROTL64(k2,33); k2 *= c1; h2 ^= k2;
     31c:	48 8b 45 a0          	mov    -0x60(%rbp),%rax
     320:	48 ba 7f 93 45 27 43 	movabs $0x4cf5ad432745937f,%rdx
     327:	ad f5 4c 
     32a:	48 0f af c2          	imul   %rdx,%rax
     32e:	48 89 45 a0          	mov    %rax,-0x60(%rbp)
     332:	48 8b 45 a0          	mov    -0x60(%rbp),%rax
     336:	be 21 00 00 00       	mov    $0x21,%esi
     33b:	48 89 c7             	mov    %rax,%rdi
     33e:	e8 00 00 00 00       	call   343 <_ZL19MurmurHash3_x64_128PKvijPv+0x31c>
     343:	48 89 45 a0          	mov    %rax,-0x60(%rbp)
     347:	48 8b 45 a0          	mov    -0x60(%rbp),%rax
     34b:	48 ba d5 53 42 11 91 	movabs $0x87c37b91114253d5,%rdx
     352:	7b c3 87 
     355:	48 0f af c2          	imul   %rdx,%rax
     359:	48 89 45 a0          	mov    %rax,-0x60(%rbp)
     35d:	48 8b 45 a0          	mov    -0x60(%rbp),%rax
     361:	48 31 45 90          	xor    %rax,-0x70(%rbp)

  case  8: k1 ^= ((uint64_t)tail[ 7]) << 56;
     365:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
     369:	48 83 c0 07          	add    $0x7,%rax
     36d:	0f b6 00             	movzbl (%rax),%eax
     370:	0f b6 c0             	movzbl %al,%eax
     373:	48 c1 e0 38          	shl    $0x38,%rax
     377:	48 31 45 98          	xor    %rax,-0x68(%rbp)
  case  7: k1 ^= ((uint64_t)tail[ 6]) << 48;
     37b:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
     37f:	48 83 c0 06          	add    $0x6,%rax
     383:	0f b6 00             	movzbl (%rax),%eax
     386:	0f b6 c0             	movzbl %al,%eax
     389:	48 c1 e0 30          	shl    $0x30,%rax
     38d:	48 31 45 98          	xor    %rax,-0x68(%rbp)
  case  6: k1 ^= ((uint64_t)tail[ 5]) << 40;
     391:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
     395:	48 83 c0 05          	add    $0x5,%rax
     399:	0f b6 00             	movzbl (%rax),%eax
     39c:	0f b6 c0             	movzbl %al,%eax
     39f:	48 c1 e0 28          	shl    $0x28,%rax
     3a3:	48 31 45 98          	xor    %rax,-0x68(%rbp)
  case  5: k1 ^= ((uint64_t)tail[ 4]) << 32;
     3a7:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
     3ab:	48 83 c0 04          	add    $0x4,%rax
     3af:	0f b6 00             	movzbl (%rax),%eax
     3b2:	0f b6 c0             	movzbl %al,%eax
     3b5:	48 c1 e0 20          	shl    $0x20,%rax
     3b9:	48 31 45 98          	xor    %rax,-0x68(%rbp)
  case  4: k1 ^= ((uint64_t)tail[ 3]) << 24;
     3bd:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
     3c1:	48 83 c0 03          	add    $0x3,%rax
     3c5:	0f b6 00             	movzbl (%rax),%eax
     3c8:	0f b6 c0             	movzbl %al,%eax
     3cb:	48 c1 e0 18          	shl    $0x18,%rax
     3cf:	48 31 45 98          	xor    %rax,-0x68(%rbp)
  case  3: k1 ^= ((uint64_t)tail[ 2]) << 16;
     3d3:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
     3d7:	48 83 c0 02          	add    $0x2,%rax
     3db:	0f b6 00             	movzbl (%rax),%eax
     3de:	0f b6 c0             	movzbl %al,%eax
     3e1:	48 c1 e0 10          	shl    $0x10,%rax
     3e5:	48 31 45 98          	xor    %rax,-0x68(%rbp)
  case  2: k1 ^= ((uint64_t)tail[ 1]) << 8;
     3e9:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
     3ed:	48 83 c0 01          	add    $0x1,%rax
     3f1:	0f b6 00             	movzbl (%rax),%eax
     3f4:	0f b6 c0             	movzbl %al,%eax
     3f7:	48 c1 e0 08          	shl    $0x8,%rax
     3fb:	48 31 45 98          	xor    %rax,-0x68(%rbp)
  case  1: k1 ^= ((uint64_t)tail[ 0]) << 0;
     3ff:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
     403:	0f b6 00             	movzbl (%rax),%eax
     406:	0f b6 c0             	movzbl %al,%eax
     409:	48 31 45 98          	xor    %rax,-0x68(%rbp)
           k1 *= c1; k1  = ROTL64(k1,31); k1 *= c2; h1 ^= k1;
     40d:	48 8b 45 98          	mov    -0x68(%rbp),%rax
     411:	48 ba d5 53 42 11 91 	movabs $0x87c37b91114253d5,%rdx
     418:	7b c3 87 
     41b:	48 0f af c2          	imul   %rdx,%rax
     41f:	48 89 45 98          	mov    %rax,-0x68(%rbp)
     423:	48 8b 45 98          	mov    -0x68(%rbp),%rax
     427:	be 1f 00 00 00       	mov    $0x1f,%esi
     42c:	48 89 c7             	mov    %rax,%rdi
     42f:	e8 00 00 00 00       	call   434 <_ZL19MurmurHash3_x64_128PKvijPv+0x40d>
     434:	48 89 45 98          	mov    %rax,-0x68(%rbp)
     438:	48 8b 45 98          	mov    -0x68(%rbp),%rax
     43c:	48 ba 7f 93 45 27 43 	movabs $0x4cf5ad432745937f,%rdx
     443:	ad f5 4c 
     446:	48 0f af c2          	imul   %rdx,%rax
     44a:	48 89 45 98          	mov    %rax,-0x68(%rbp)
     44e:	48 8b 45 98          	mov    -0x68(%rbp),%rax
     452:	48 31 45 88          	xor    %rax,-0x78(%rbp)
  };

  h1 ^= len; h2 ^= len;
     456:	8b 85 64 ff ff ff    	mov    -0x9c(%rbp),%eax
     45c:	48 98                	cltq   
     45e:	48 31 45 88          	xor    %rax,-0x78(%rbp)
     462:	8b 85 64 ff ff ff    	mov    -0x9c(%rbp),%eax
     468:	48 98                	cltq   
     46a:	48 31 45 90          	xor    %rax,-0x70(%rbp)

  h1 += h2;
     46e:	48 8b 45 90          	mov    -0x70(%rbp),%rax
     472:	48 01 45 88          	add    %rax,-0x78(%rbp)
  h2 += h1;
     476:	48 8b 45 88          	mov    -0x78(%rbp),%rax
     47a:	48 01 45 90          	add    %rax,-0x70(%rbp)
     47e:	48 8b 45 88          	mov    -0x78(%rbp),%rax
     482:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  k ^= k >> 33;
     486:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
     48a:	48 c1 e8 21          	shr    $0x21,%rax
     48e:	48 31 45 f8          	xor    %rax,-0x8(%rbp)
  k *= BIG_CONSTANT(0xff51afd7ed558ccd);
     492:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
     496:	48 ba cd 8c 55 ed d7 	movabs $0xff51afd7ed558ccd,%rdx
     49d:	af 51 ff 
     4a0:	48 0f af c2          	imul   %rdx,%rax
     4a4:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  k ^= k >> 33;
     4a8:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
     4ac:	48 c1 e8 21          	shr    $0x21,%rax
     4b0:	48 31 45 f8          	xor    %rax,-0x8(%rbp)
  k *= BIG_CONSTANT(0xc4ceb9fe1a85ec53);
     4b4:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
     4b8:	48 ba 53 ec 85 1a fe 	movabs $0xc4ceb9fe1a85ec53,%rdx
     4bf:	b9 ce c4 
     4c2:	48 0f af c2          	imul   %rdx,%rax
     4c6:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  k ^= k >> 33;
     4ca:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
     4ce:	48 c1 e8 21          	shr    $0x21,%rax
     4d2:	48 31 45 f8          	xor    %rax,-0x8(%rbp)
  return k;
     4d6:	48 8b 45 f8          	mov    -0x8(%rbp),%rax

  h1 = fmix64(h1);
     4da:	48 89 45 88          	mov    %rax,-0x78(%rbp)
     4de:	48 8b 45 90          	mov    -0x70(%rbp),%rax
     4e2:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
  k ^= k >> 33;
     4e6:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
     4ea:	48 c1 e8 21          	shr    $0x21,%rax
     4ee:	48 31 45 f0          	xor    %rax,-0x10(%rbp)
  k *= BIG_CONSTANT(0xff51afd7ed558ccd);
     4f2:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
     4f6:	48 ba cd 8c 55 ed d7 	movabs $0xff51afd7ed558ccd,%rdx
     4fd:	af 51 ff 
     500:	48 0f af c2          	imul   %rdx,%rax
     504:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
  k ^= k >> 33;
     508:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
     50c:	48 c1 e8 21          	shr    $0x21,%rax
     510:	48 31 45 f0          	xor    %rax,-0x10(%rbp)
  k *= BIG_CONSTANT(0xc4ceb9fe1a85ec53);
     514:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
     518:	48 ba 53 ec 85 1a fe 	movabs $0xc4ceb9fe1a85ec53,%rdx
     51f:	b9 ce c4 
     522:	48 0f af c2          	imul   %rdx,%rax
     526:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
  k ^= k >> 33;
     52a:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
     52e:	48 c1 e8 21          	shr    $0x21,%rax
     532:	48 31 45 f0          	xor    %rax,-0x10(%rbp)
  return k;
     536:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  h2 = fmix64(h2);
     53a:	48 89 45 90          	mov    %rax,-0x70(%rbp)

  h1 += h2;
     53e:	48 8b 45 90          	mov    -0x70(%rbp),%rax
     542:	48 01 45 88          	add    %rax,-0x78(%rbp)
  h2 += h1;
     546:	48 8b 45 88          	mov    -0x78(%rbp),%rax
     54a:	48 01 45 90          	add    %rax,-0x70(%rbp)

  ((uint64_t*)out)[0] = h1;
     54e:	48 8b 85 58 ff ff ff 	mov    -0xa8(%rbp),%rax
     555:	48 8b 55 88          	mov    -0x78(%rbp),%rdx
     559:	48 89 10             	mov    %rdx,(%rax)
  ((uint64_t*)out)[1] = h2;
     55c:	48 8b 85 58 ff ff ff 	mov    -0xa8(%rbp),%rax
     563:	48 8d 50 08          	lea    0x8(%rax),%rdx
     567:	48 8b 45 90          	mov    -0x70(%rbp),%rax
     56b:	48 89 02             	mov    %rax,(%rdx)
     56e:	90                   	nop
     56f:	c9                   	leave  
     570:	c3                   	ret    
     571:	90                   	nop

0000000000000572 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE>:
/**
 * Insert/Update the key-value pair.
 * No return values for simplicity.
 */
void MemTable::put(uint64_t key, const std::string &val)
{
     572:	f3 0f 1e fa          	endbr64 
     576:	55                   	push   %rbp
     577:	48 89 e5             	mov    %rsp,%rbp
     57a:	41 54                	push   %r12
     57c:	53                   	push   %rbx
     57d:	48 81 ec 00 10 00 00 	sub    $0x1000,%rsp
     584:	48 83 0c 24 00       	orq    $0x0,(%rsp)
     589:	48 81 ec 00 10 00 00 	sub    $0x1000,%rsp
     590:	48 83 0c 24 00       	orq    $0x0,(%rsp)
     595:	48 81 ec b0 07 00 00 	sub    $0x7b0,%rsp
     59c:	48 89 bd 58 d8 ff ff 	mov    %rdi,-0x27a8(%rbp)
     5a3:	48 89 b5 50 d8 ff ff 	mov    %rsi,-0x27b0(%rbp)
     5aa:	48 89 95 48 d8 ff ff 	mov    %rdx,-0x27b8(%rbp)
     5b1:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
     5b8:	00 00 
     5ba:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
     5be:	31 c0                	xor    %eax,%eax
	Quadlist *f = frist();
     5c0:	48 8b 85 58 d8 ff ff 	mov    -0x27a8(%rbp),%rax
     5c7:	48 89 c7             	mov    %rax,%rdi
     5ca:	e8 00 00 00 00       	call   5cf <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x5d>
     5cf:	48 89 85 80 d8 ff ff 	mov    %rax,-0x2780(%rbp)
        QuadlistNode *p = f->frist();
     5d6:	48 8b 85 80 d8 ff ff 	mov    -0x2780(%rbp),%rax
     5dd:	48 89 c7             	mov    %rax,%rdi
     5e0:	e8 00 00 00 00       	call   5e5 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x73>
     5e5:	48 89 85 70 d8 ff ff 	mov    %rax,-0x2790(%rbp)
        while(p != nullptr)
     5ec:	e9 e4 00 00 00       	jmp    6d5 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x163>
        {
            //go to the next
            while(p->succ && (key >= p->key))
                p = p->succ;
     5f1:	48 8b 85 70 d8 ff ff 	mov    -0x2790(%rbp),%rax
     5f8:	48 8b 40 30          	mov    0x30(%rax),%rax
     5fc:	48 89 85 70 d8 ff ff 	mov    %rax,-0x2790(%rbp)
            while(p->succ && (key >= p->key))
     603:	48 8b 85 70 d8 ff ff 	mov    -0x2790(%rbp),%rax
     60a:	48 8b 40 30          	mov    0x30(%rax),%rax
     60e:	48 85 c0             	test   %rax,%rax
     611:	74 14                	je     627 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0xb5>
     613:	48 8b 85 70 d8 ff ff 	mov    -0x2790(%rbp),%rax
     61a:	48 8b 40 20          	mov    0x20(%rax),%rax
     61e:	48 39 85 50 d8 ff ff 	cmp    %rax,-0x27b0(%rbp)
     625:	73 ca                	jae    5f1 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x7f>
            //come back
            p = p->prev;
     627:	48 8b 85 70 d8 ff ff 	mov    -0x2790(%rbp),%rax
     62e:	48 8b 40 28          	mov    0x28(%rax),%rax
     632:	48 89 85 70 d8 ff ff 	mov    %rax,-0x2790(%rbp)
            if(p->key == key)
     639:	48 8b 85 70 d8 ff ff 	mov    -0x2790(%rbp),%rax
     640:	48 8b 40 20          	mov    0x20(%rax),%rax
     644:	48 39 85 50 d8 ff ff 	cmp    %rax,-0x27b0(%rbp)
     64b:	75 66                	jne    6b3 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x141>
            {
                //find bottom
                while(p->below != nullptr)
     64d:	eb 12                	jmp    661 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0xef>
                    p = p->below;
     64f:	48 8b 85 70 d8 ff ff 	mov    -0x2790(%rbp),%rax
     656:	48 8b 40 40          	mov    0x40(%rax),%rax
     65a:	48 89 85 70 d8 ff ff 	mov    %rax,-0x2790(%rbp)
                while(p->below != nullptr)
     661:	48 8b 85 70 d8 ff ff 	mov    -0x2790(%rbp),%rax
     668:	48 8b 40 40          	mov    0x40(%rax),%rax
     66c:	48 85 c0             	test   %rax,%rax
     66f:	75 de                	jne    64f <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0xdd>
                //change the value
                while(p->above != nullptr)
     671:	eb 2b                	jmp    69e <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x12c>
                    {
                        p->entry = val;
     673:	48 8b 85 70 d8 ff ff 	mov    -0x2790(%rbp),%rax
     67a:	48 8b 95 48 d8 ff ff 	mov    -0x27b8(%rbp),%rdx
     681:	48 89 d6             	mov    %rdx,%rsi
     684:	48 89 c7             	mov    %rax,%rdi
     687:	e8 00 00 00 00       	call   68c <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x11a>
                         p = p->above;
     68c:	48 8b 85 70 d8 ff ff 	mov    -0x2790(%rbp),%rax
     693:	48 8b 40 38          	mov    0x38(%rax),%rax
     697:	48 89 85 70 d8 ff ff 	mov    %rax,-0x2790(%rbp)
                while(p->above != nullptr)
     69e:	48 8b 85 70 d8 ff ff 	mov    -0x2790(%rbp),%rax
     6a5:	48 8b 40 38          	mov    0x38(%rax),%rax
     6a9:	48 85 c0             	test   %rax,%rax
     6ac:	75 c5                	jne    673 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x101>
                    }
                return;
     6ae:	e9 33 04 00 00       	jmp    ae6 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x574>
            }
            else
            {
                if(p->below == nullptr) break;
     6b3:	48 8b 85 70 d8 ff ff 	mov    -0x2790(%rbp),%rax
     6ba:	48 8b 40 40          	mov    0x40(%rax),%rax
     6be:	48 85 c0             	test   %rax,%rax
     6c1:	74 22                	je     6e5 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x173>
                else p = p->below;
     6c3:	48 8b 85 70 d8 ff ff 	mov    -0x2790(%rbp),%rax
     6ca:	48 8b 40 40          	mov    0x40(%rax),%rax
     6ce:	48 89 85 70 d8 ff ff 	mov    %rax,-0x2790(%rbp)
        while(p != nullptr)
     6d5:	48 83 bd 70 d8 ff ff 	cmpq   $0x0,-0x2790(%rbp)
     6dc:	00 
     6dd:	0f 85 20 ff ff ff    	jne    603 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x91>
     6e3:	eb 01                	jmp    6e6 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x174>
                if(p->below == nullptr) break;
     6e5:	90                   	nop
            }
        }// find the place of insert
        

        Quadlist *listlast = this->last();
     6e6:	48 8b 85 58 d8 ff ff 	mov    -0x27a8(%rbp),%rax
     6ed:	48 89 c7             	mov    %rax,%rdi
     6f0:	e8 00 00 00 00       	call   6f5 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x183>
     6f5:	48 89 85 88 d8 ff ff 	mov    %rax,-0x2778(%rbp)
        listlast->insertAfterAbove(key , val ,p , nullptr);
     6fc:	48 8b 9d 88 d8 ff ff 	mov    -0x2778(%rbp),%rbx
     703:	48 8b 95 48 d8 ff ff 	mov    -0x27b8(%rbp),%rdx
     70a:	48 8d 85 60 ec ff ff 	lea    -0x13a0(%rbp),%rax
     711:	48 89 d6             	mov    %rdx,%rsi
     714:	48 89 c7             	mov    %rax,%rdi
     717:	e8 00 00 00 00       	call   71c <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x1aa>
     71c:	48 8b 8d 70 d8 ff ff 	mov    -0x2790(%rbp),%rcx
     723:	48 8d 95 60 ec ff ff 	lea    -0x13a0(%rbp),%rdx
     72a:	48 8b 85 50 d8 ff ff 	mov    -0x27b0(%rbp),%rax
     731:	41 b8 00 00 00 00    	mov    $0x0,%r8d
     737:	48 89 c6             	mov    %rax,%rsi
     73a:	48 89 df             	mov    %rbx,%rdi
     73d:	e8 00 00 00 00       	call   742 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x1d0>
     742:	48 8d 85 60 ec ff ff 	lea    -0x13a0(%rbp),%rax
     749:	48 89 c7             	mov    %rax,%rdi
     74c:	e8 00 00 00 00       	call   751 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x1df>

        // 创建随机数
        std::random_device rd;
     751:	48 8d 85 d0 d8 ff ff 	lea    -0x2730(%rbp),%rax
     758:	48 89 c7             	mov    %rax,%rdi
     75b:	e8 00 00 00 00       	call   760 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x1ee>
        std::mt19937 gen(rd());
     760:	48 8d 85 d0 d8 ff ff 	lea    -0x2730(%rbp),%rax
     767:	48 89 c7             	mov    %rax,%rdi
     76a:	e8 00 00 00 00       	call   76f <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x1fd>
     76f:	89 c2                	mov    %eax,%edx
     771:	48 8d 85 60 ec ff ff 	lea    -0x13a0(%rbp),%rax
     778:	48 89 d6             	mov    %rdx,%rsi
     77b:	48 89 c7             	mov    %rax,%rdi
     77e:	e8 00 00 00 00       	call   783 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x211>
        std::uniform_real_distribution<double> dis(0.0, 1.0);
     783:	f2 0f 10 05 00 00 00 	movsd  0x0(%rip),%xmm0        # 78b <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x219>
     78a:	00 
     78b:	48 8d 85 a0 d8 ff ff 	lea    -0x2760(%rbp),%rax
     792:	66 0f 28 c8          	movapd %xmm0,%xmm1
     796:	48 8b 15 00 00 00 00 	mov    0x0(%rip),%rdx        # 79d <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x22b>
     79d:	66 48 0f 6e c2       	movq   %rdx,%xmm0
     7a2:	48 89 c7             	mov    %rax,%rdi
     7a5:	e8 00 00 00 00       	call   7aa <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x238>
        int height = 0;
     7aa:	c7 85 64 d8 ff ff 00 	movl   $0x0,-0x279c(%rbp)
     7b1:	00 00 00 
        p = p->succ;
     7b4:	48 8b 85 70 d8 ff ff 	mov    -0x2790(%rbp),%rax
     7bb:	48 8b 40 30          	mov    0x30(%rax),%rax
     7bf:	48 89 85 70 d8 ff ff 	mov    %rax,-0x2790(%rbp)
        while(true)
        {
            double randNum = dis(gen);
     7c6:	48 8d 95 60 ec ff ff 	lea    -0x13a0(%rbp),%rdx
     7cd:	48 8d 85 a0 d8 ff ff 	lea    -0x2760(%rbp),%rax
     7d4:	48 89 d6             	mov    %rdx,%rsi
     7d7:	48 89 c7             	mov    %rax,%rdi
     7da:	e8 00 00 00 00       	call   7df <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x26d>
     7df:	66 48 0f 7e c0       	movq   %xmm0,%rax
     7e4:	48 89 85 90 d8 ff ff 	mov    %rax,-0x2770(%rbp)
            if(randNum >= this->p) return;
     7eb:	48 8b 85 58 d8 ff ff 	mov    -0x27a8(%rbp),%rax
     7f2:	f2 0f 10 08          	movsd  (%rax),%xmm1
     7f6:	f2 0f 10 85 90 d8 ff 	movsd  -0x2770(%rbp),%xmm0
     7fd:	ff 
     7fe:	66 0f 2f c1          	comisd %xmm1,%xmm0
     802:	72 14                	jb     818 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x2a6>
                pre = pre->succ;
            qlist->insertAfterAbove(key , val , pre , p);
            p = p->above;
            height ++;
        }
}
     804:	48 8d 85 d0 d8 ff ff 	lea    -0x2730(%rbp),%rax
     80b:	48 89 c7             	mov    %rax,%rdi
     80e:	e8 00 00 00 00       	call   813 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x2a1>
     813:	e9 ce 02 00 00       	jmp    ae6 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x574>
            if(list.size() <= height + 1)            
     818:	48 8b 85 58 d8 ff ff 	mov    -0x27a8(%rbp),%rax
     81f:	48 83 c0 08          	add    $0x8,%rax
     823:	48 89 c7             	mov    %rax,%rdi
     826:	e8 00 00 00 00       	call   82b <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x2b9>
     82b:	8b 95 64 d8 ff ff    	mov    -0x279c(%rbp),%edx
     831:	83 c2 01             	add    $0x1,%edx
     834:	48 63 d2             	movslq %edx,%rdx
     837:	48 39 d0             	cmp    %rdx,%rax
     83a:	0f 96 c0             	setbe  %al
     83d:	84 c0                	test   %al,%al
     83f:	0f 84 1c 01 00 00    	je     961 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x3ef>
                Quadlist *qlist = new Quadlist();
     845:	bf 18 00 00 00       	mov    $0x18,%edi
     84a:	e8 00 00 00 00       	call   84f <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x2dd>
     84f:	48 89 c3             	mov    %rax,%rbx
     852:	48 89 df             	mov    %rbx,%rdi
     855:	e8 00 00 00 00       	call   85a <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x2e8>
     85a:	48 89 9d 68 d8 ff ff 	mov    %rbx,-0x2798(%rbp)
                qlist->header->below = list[height]->header;
     861:	48 8b 85 58 d8 ff ff 	mov    -0x27a8(%rbp),%rax
     868:	48 8d 50 08          	lea    0x8(%rax),%rdx
     86c:	8b 85 64 d8 ff ff    	mov    -0x279c(%rbp),%eax
     872:	48 98                	cltq   
     874:	48 89 c6             	mov    %rax,%rsi
     877:	48 89 d7             	mov    %rdx,%rdi
     87a:	e8 00 00 00 00       	call   87f <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x30d>
     87f:	48 8b 10             	mov    (%rax),%rdx
     882:	48 8b 85 68 d8 ff ff 	mov    -0x2798(%rbp),%rax
     889:	48 8b 00             	mov    (%rax),%rax
     88c:	48 8b 12             	mov    (%rdx),%rdx
     88f:	48 89 50 40          	mov    %rdx,0x40(%rax)
                qlist->trailer->below = list[height]->trailer;
     893:	48 8b 85 58 d8 ff ff 	mov    -0x27a8(%rbp),%rax
     89a:	48 8d 50 08          	lea    0x8(%rax),%rdx
     89e:	8b 85 64 d8 ff ff    	mov    -0x279c(%rbp),%eax
     8a4:	48 98                	cltq   
     8a6:	48 89 c6             	mov    %rax,%rsi
     8a9:	48 89 d7             	mov    %rdx,%rdi
     8ac:	e8 00 00 00 00       	call   8b1 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x33f>
     8b1:	48 8b 10             	mov    (%rax),%rdx
     8b4:	48 8b 85 68 d8 ff ff 	mov    -0x2798(%rbp),%rax
     8bb:	48 8b 40 08          	mov    0x8(%rax),%rax
     8bf:	48 8b 52 08          	mov    0x8(%rdx),%rdx
     8c3:	48 89 50 40          	mov    %rdx,0x40(%rax)
                qlist->insertAfterAbove(key , val , qlist->header , p);
     8c7:	48 8b 9d 68 d8 ff ff 	mov    -0x2798(%rbp),%rbx
     8ce:	48 8b 85 68 d8 ff ff 	mov    -0x2798(%rbp),%rax
     8d5:	4c 8b 20             	mov    (%rax),%r12
     8d8:	48 8b 95 48 d8 ff ff 	mov    -0x27b8(%rbp),%rdx
     8df:	48 8d 85 b0 d8 ff ff 	lea    -0x2750(%rbp),%rax
     8e6:	48 89 d6             	mov    %rdx,%rsi
     8e9:	48 89 c7             	mov    %rax,%rdi
     8ec:	e8 00 00 00 00       	call   8f1 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x37f>
     8f1:	48 8b 8d 70 d8 ff ff 	mov    -0x2790(%rbp),%rcx
     8f8:	48 8d 95 b0 d8 ff ff 	lea    -0x2750(%rbp),%rdx
     8ff:	48 8b 85 50 d8 ff ff 	mov    -0x27b0(%rbp),%rax
     906:	49 89 c8             	mov    %rcx,%r8
     909:	4c 89 e1             	mov    %r12,%rcx
     90c:	48 89 c6             	mov    %rax,%rsi
     90f:	48 89 df             	mov    %rbx,%rdi
     912:	e8 00 00 00 00       	call   917 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x3a5>
     917:	48 8d 85 b0 d8 ff ff 	lea    -0x2750(%rbp),%rax
     91e:	48 89 c7             	mov    %rax,%rdi
     921:	e8 00 00 00 00       	call   926 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x3b4>
                p = p->above;
     926:	48 8b 85 70 d8 ff ff 	mov    -0x2790(%rbp),%rax
     92d:	48 8b 40 38          	mov    0x38(%rax),%rax
     931:	48 89 85 70 d8 ff ff 	mov    %rax,-0x2790(%rbp)
                list.push_back(qlist);
     938:	48 8b 85 58 d8 ff ff 	mov    -0x27a8(%rbp),%rax
     93f:	48 8d 50 08          	lea    0x8(%rax),%rdx
     943:	48 8d 85 68 d8 ff ff 	lea    -0x2798(%rbp),%rax
     94a:	48 89 c6             	mov    %rax,%rsi
     94d:	48 89 d7             	mov    %rdx,%rdi
     950:	e8 00 00 00 00       	call   955 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x3e3>
                height ++;
     955:	83 85 64 d8 ff ff 01 	addl   $0x1,-0x279c(%rbp)
                continue;
     95c:	e9 f5 00 00 00       	jmp    a56 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x4e4>
            Quadlist *qlist = list[height + 1];
     961:	48 8b 85 58 d8 ff ff 	mov    -0x27a8(%rbp),%rax
     968:	48 8d 50 08          	lea    0x8(%rax),%rdx
     96c:	8b 85 64 d8 ff ff    	mov    -0x279c(%rbp),%eax
     972:	83 c0 01             	add    $0x1,%eax
     975:	48 98                	cltq   
     977:	48 89 c6             	mov    %rax,%rsi
     97a:	48 89 d7             	mov    %rdx,%rdi
     97d:	e8 00 00 00 00       	call   982 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x410>
     982:	48 8b 00             	mov    (%rax),%rax
     985:	48 89 85 98 d8 ff ff 	mov    %rax,-0x2768(%rbp)
            QuadlistNode *pre = qlist->header;
     98c:	48 8b 85 98 d8 ff ff 	mov    -0x2768(%rbp),%rax
     993:	48 8b 00             	mov    (%rax),%rax
     996:	48 89 85 78 d8 ff ff 	mov    %rax,-0x2788(%rbp)
            while(pre->succ != qlist->trailer && key > pre->succ->key )
     99d:	eb 12                	jmp    9b1 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x43f>
                pre = pre->succ;
     99f:	48 8b 85 78 d8 ff ff 	mov    -0x2788(%rbp),%rax
     9a6:	48 8b 40 30          	mov    0x30(%rax),%rax
     9aa:	48 89 85 78 d8 ff ff 	mov    %rax,-0x2788(%rbp)
            while(pre->succ != qlist->trailer && key > pre->succ->key )
     9b1:	48 8b 85 78 d8 ff ff 	mov    -0x2788(%rbp),%rax
     9b8:	48 8b 50 30          	mov    0x30(%rax),%rdx
     9bc:	48 8b 85 98 d8 ff ff 	mov    -0x2768(%rbp),%rax
     9c3:	48 8b 40 08          	mov    0x8(%rax),%rax
     9c7:	48 39 c2             	cmp    %rax,%rdx
     9ca:	74 18                	je     9e4 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x472>
     9cc:	48 8b 85 78 d8 ff ff 	mov    -0x2788(%rbp),%rax
     9d3:	48 8b 40 30          	mov    0x30(%rax),%rax
     9d7:	48 8b 40 20          	mov    0x20(%rax),%rax
     9db:	48 39 85 50 d8 ff ff 	cmp    %rax,-0x27b0(%rbp)
     9e2:	77 bb                	ja     99f <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x42d>
            qlist->insertAfterAbove(key , val , pre , p);
     9e4:	48 8b 9d 98 d8 ff ff 	mov    -0x2768(%rbp),%rbx
     9eb:	48 8b 95 48 d8 ff ff 	mov    -0x27b8(%rbp),%rdx
     9f2:	48 8d 85 b0 d8 ff ff 	lea    -0x2750(%rbp),%rax
     9f9:	48 89 d6             	mov    %rdx,%rsi
     9fc:	48 89 c7             	mov    %rax,%rdi
     9ff:	e8 00 00 00 00       	call   a04 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x492>
     a04:	48 8b b5 70 d8 ff ff 	mov    -0x2790(%rbp),%rsi
     a0b:	48 8b 8d 78 d8 ff ff 	mov    -0x2788(%rbp),%rcx
     a12:	48 8d 95 b0 d8 ff ff 	lea    -0x2750(%rbp),%rdx
     a19:	48 8b 85 50 d8 ff ff 	mov    -0x27b0(%rbp),%rax
     a20:	49 89 f0             	mov    %rsi,%r8
     a23:	48 89 c6             	mov    %rax,%rsi
     a26:	48 89 df             	mov    %rbx,%rdi
     a29:	e8 00 00 00 00       	call   a2e <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x4bc>
     a2e:	48 8d 85 b0 d8 ff ff 	lea    -0x2750(%rbp),%rax
     a35:	48 89 c7             	mov    %rax,%rdi
     a38:	e8 00 00 00 00       	call   a3d <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x4cb>
            p = p->above;
     a3d:	48 8b 85 70 d8 ff ff 	mov    -0x2790(%rbp),%rax
     a44:	48 8b 40 38          	mov    0x38(%rax),%rax
     a48:	48 89 85 70 d8 ff ff 	mov    %rax,-0x2790(%rbp)
            height ++;
     a4f:	83 85 64 d8 ff ff 01 	addl   $0x1,-0x279c(%rbp)
        }
     a56:	e9 6b fd ff ff       	jmp    7c6 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x254>
     a5b:	f3 0f 1e fa          	endbr64 
        listlast->insertAfterAbove(key , val ,p , nullptr);
     a5f:	48 89 c3             	mov    %rax,%rbx
     a62:	48 8d 85 60 ec ff ff 	lea    -0x13a0(%rbp),%rax
     a69:	48 89 c7             	mov    %rax,%rdi
     a6c:	e8 00 00 00 00       	call   a71 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x4ff>
     a71:	48 89 d8             	mov    %rbx,%rax
     a74:	48 89 c7             	mov    %rax,%rdi
     a77:	e8 00 00 00 00       	call   a7c <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x50a>
     a7c:	f3 0f 1e fa          	endbr64 
                Quadlist *qlist = new Quadlist();
     a80:	49 89 c4             	mov    %rax,%r12
     a83:	be 18 00 00 00       	mov    $0x18,%esi
     a88:	48 89 df             	mov    %rbx,%rdi
     a8b:	e8 00 00 00 00       	call   a90 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x51e>
     a90:	4c 89 e3             	mov    %r12,%rbx
     a93:	eb 37                	jmp    acc <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x55a>
     a95:	f3 0f 1e fa          	endbr64 
                qlist->insertAfterAbove(key , val , qlist->header , p);
     a99:	48 89 c3             	mov    %rax,%rbx
     a9c:	48 8d 85 b0 d8 ff ff 	lea    -0x2750(%rbp),%rax
     aa3:	48 89 c7             	mov    %rax,%rdi
     aa6:	e8 00 00 00 00       	call   aab <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x539>
     aab:	eb 1f                	jmp    acc <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x55a>
     aad:	f3 0f 1e fa          	endbr64 
            qlist->insertAfterAbove(key , val , pre , p);
     ab1:	48 89 c3             	mov    %rax,%rbx
     ab4:	48 8d 85 b0 d8 ff ff 	lea    -0x2750(%rbp),%rax
     abb:	48 89 c7             	mov    %rax,%rdi
     abe:	e8 00 00 00 00       	call   ac3 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x551>
     ac3:	eb 07                	jmp    acc <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x55a>
     ac5:	f3 0f 1e fa          	endbr64 
}
     ac9:	48 89 c3             	mov    %rax,%rbx
     acc:	48 8d 85 d0 d8 ff ff 	lea    -0x2730(%rbp),%rax
     ad3:	48 89 c7             	mov    %rax,%rdi
     ad6:	e8 00 00 00 00       	call   adb <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x569>
     adb:	48 89 d8             	mov    %rbx,%rax
     ade:	48 89 c7             	mov    %rax,%rdi
     ae1:	e8 00 00 00 00       	call   ae6 <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x574>
     ae6:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
     aea:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
     af1:	00 00 
     af3:	74 05                	je     afa <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x588>
     af5:	e8 00 00 00 00       	call   afa <_ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x588>
     afa:	48 81 c4 b0 27 00 00 	add    $0x27b0,%rsp
     b01:	5b                   	pop    %rbx
     b02:	41 5c                	pop    %r12
     b04:	5d                   	pop    %rbp
     b05:	c3                   	ret    

0000000000000b06 <_ZN8MemTable3getB5cxx11EmRb>:
/**
 * Returns the (string) value of the given key.
 * An empty string indicates not found.
 */
std::string MemTable::get(uint64_t key , bool &isFind )
{
     b06:	f3 0f 1e fa          	endbr64 
     b0a:	55                   	push   %rbp
     b0b:	48 89 e5             	mov    %rsp,%rbp
     b0e:	53                   	push   %rbx
     b0f:	48 83 ec 48          	sub    $0x48,%rsp
     b13:	48 89 7d c8          	mov    %rdi,-0x38(%rbp)
     b17:	48 89 75 c0          	mov    %rsi,-0x40(%rbp)
     b1b:	48 89 55 b8          	mov    %rdx,-0x48(%rbp)
     b1f:	48 89 4d b0          	mov    %rcx,-0x50(%rbp)
     b23:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
     b2a:	00 00 
     b2c:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
     b30:	31 c0                	xor    %eax,%eax
	Quadlist *li = frist();
     b32:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
     b36:	48 89 c7             	mov    %rax,%rdi
     b39:	e8 00 00 00 00       	call   b3e <_ZN8MemTable3getB5cxx11EmRb+0x38>
     b3e:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    QuadlistNode * p = li->frist();
     b42:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
     b46:	48 89 c7             	mov    %rax,%rdi
     b49:	e8 00 00 00 00       	call   b4e <_ZN8MemTable3getB5cxx11EmRb+0x48>
     b4e:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
    if(p == nullptr) return "";
     b52:	48 83 7d d8 00       	cmpq   $0x0,-0x28(%rbp)
     b57:	75 43                	jne    b9c <_ZN8MemTable3getB5cxx11EmRb+0x96>
     b59:	48 8d 45 d7          	lea    -0x29(%rbp),%rax
     b5d:	48 89 c7             	mov    %rax,%rdi
     b60:	e8 00 00 00 00       	call   b65 <_ZN8MemTable3getB5cxx11EmRb+0x5f>
     b65:	48 8d 55 d7          	lea    -0x29(%rbp),%rdx
     b69:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
     b6d:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # b74 <_ZN8MemTable3getB5cxx11EmRb+0x6e>
     b74:	48 89 ce             	mov    %rcx,%rsi
     b77:	48 89 c7             	mov    %rax,%rdi
     b7a:	e8 00 00 00 00       	call   b7f <_ZN8MemTable3getB5cxx11EmRb+0x79>
     b7f:	48 8d 45 d7          	lea    -0x29(%rbp),%rax
     b83:	48 89 c7             	mov    %rax,%rdi
     b86:	e8 00 00 00 00       	call   b8b <_ZN8MemTable3getB5cxx11EmRb+0x85>
        {
            if(p->below == nullptr) return "";
            else p = p->below;
        }
    }
}
     b8b:	e9 f5 00 00 00       	jmp    c85 <_ZN8MemTable3getB5cxx11EmRb+0x17f>
            p = p->succ;
     b90:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
     b94:	48 8b 40 30          	mov    0x30(%rax),%rax
     b98:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
        while(p->succ && (p->key <= key))
     b9c:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
     ba0:	48 8b 40 30          	mov    0x30(%rax),%rax
     ba4:	48 85 c0             	test   %rax,%rax
     ba7:	74 0e                	je     bb7 <_ZN8MemTable3getB5cxx11EmRb+0xb1>
     ba9:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
     bad:	48 8b 40 20          	mov    0x20(%rax),%rax
     bb1:	48 39 45 b8          	cmp    %rax,-0x48(%rbp)
     bb5:	73 d9                	jae    b90 <_ZN8MemTable3getB5cxx11EmRb+0x8a>
        p = p->prev;
     bb7:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
     bbb:	48 8b 40 28          	mov    0x28(%rax),%rax
     bbf:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
        if(p && p->key == key)
     bc3:	48 83 7d d8 00       	cmpq   $0x0,-0x28(%rbp)
     bc8:	74 2d                	je     bf7 <_ZN8MemTable3getB5cxx11EmRb+0xf1>
     bca:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
     bce:	48 8b 40 20          	mov    0x20(%rax),%rax
     bd2:	48 39 45 b8          	cmp    %rax,-0x48(%rbp)
     bd6:	75 1f                	jne    bf7 <_ZN8MemTable3getB5cxx11EmRb+0xf1>
            isFind = true;
     bd8:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
     bdc:	c6 00 01             	movb   $0x1,(%rax)
            return p->entry;
     bdf:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
     be3:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
     be7:	48 89 d6             	mov    %rdx,%rsi
     bea:	48 89 c7             	mov    %rax,%rdi
     bed:	e8 00 00 00 00       	call   bf2 <_ZN8MemTable3getB5cxx11EmRb+0xec>
     bf2:	e9 8e 00 00 00       	jmp    c85 <_ZN8MemTable3getB5cxx11EmRb+0x17f>
            if(p->below == nullptr) return "";
     bf7:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
     bfb:	48 8b 40 40          	mov    0x40(%rax),%rax
     bff:	48 85 c0             	test   %rax,%rax
     c02:	75 34                	jne    c38 <_ZN8MemTable3getB5cxx11EmRb+0x132>
     c04:	48 8d 45 d7          	lea    -0x29(%rbp),%rax
     c08:	48 89 c7             	mov    %rax,%rdi
     c0b:	e8 00 00 00 00       	call   c10 <_ZN8MemTable3getB5cxx11EmRb+0x10a>
     c10:	48 8d 55 d7          	lea    -0x29(%rbp),%rdx
     c14:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
     c18:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # c1f <_ZN8MemTable3getB5cxx11EmRb+0x119>
     c1f:	48 89 ce             	mov    %rcx,%rsi
     c22:	48 89 c7             	mov    %rax,%rdi
     c25:	e8 00 00 00 00       	call   c2a <_ZN8MemTable3getB5cxx11EmRb+0x124>
     c2a:	48 8d 45 d7          	lea    -0x29(%rbp),%rax
     c2e:	48 89 c7             	mov    %rax,%rdi
     c31:	e8 00 00 00 00       	call   c36 <_ZN8MemTable3getB5cxx11EmRb+0x130>
}
     c36:	eb 4d                	jmp    c85 <_ZN8MemTable3getB5cxx11EmRb+0x17f>
            else p = p->below;
     c38:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
     c3c:	48 8b 40 40          	mov    0x40(%rax),%rax
     c40:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
        while(p->succ && (p->key <= key))
     c44:	e9 53 ff ff ff       	jmp    b9c <_ZN8MemTable3getB5cxx11EmRb+0x96>
     c49:	f3 0f 1e fa          	endbr64 
    if(p == nullptr) return "";
     c4d:	48 89 c3             	mov    %rax,%rbx
     c50:	48 8d 45 d7          	lea    -0x29(%rbp),%rax
     c54:	48 89 c7             	mov    %rax,%rdi
     c57:	e8 00 00 00 00       	call   c5c <_ZN8MemTable3getB5cxx11EmRb+0x156>
     c5c:	48 89 d8             	mov    %rbx,%rax
     c5f:	48 89 c7             	mov    %rax,%rdi
     c62:	e8 00 00 00 00       	call   c67 <_ZN8MemTable3getB5cxx11EmRb+0x161>
     c67:	f3 0f 1e fa          	endbr64 
            if(p->below == nullptr) return "";
     c6b:	48 89 c3             	mov    %rax,%rbx
     c6e:	48 8d 45 d7          	lea    -0x29(%rbp),%rax
     c72:	48 89 c7             	mov    %rax,%rdi
     c75:	e8 00 00 00 00       	call   c7a <_ZN8MemTable3getB5cxx11EmRb+0x174>
     c7a:	48 89 d8             	mov    %rbx,%rax
     c7d:	48 89 c7             	mov    %rax,%rdi
     c80:	e8 00 00 00 00       	call   c85 <_ZN8MemTable3getB5cxx11EmRb+0x17f>
}
     c85:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
     c89:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
     c90:	00 00 
     c92:	74 05                	je     c99 <_ZN8MemTable3getB5cxx11EmRb+0x193>
     c94:	e8 00 00 00 00       	call   c99 <_ZN8MemTable3getB5cxx11EmRb+0x193>
     c99:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
     c9d:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
     ca1:	c9                   	leave  
     ca2:	c3                   	ret    
     ca3:	90                   	nop

0000000000000ca4 <_ZN8MemTable7getSizeEv>:

int MemTable::getSize()
{
     ca4:	f3 0f 1e fa          	endbr64 
     ca8:	55                   	push   %rbp
     ca9:	48 89 e5             	mov    %rsp,%rbp
     cac:	48 83 ec 10          	sub    $0x10,%rsp
     cb0:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    return this->frist()->frist()->key;
     cb4:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
     cb8:	48 89 c7             	mov    %rax,%rdi
     cbb:	e8 00 00 00 00       	call   cc0 <_ZN8MemTable7getSizeEv+0x1c>
     cc0:	48 89 c7             	mov    %rax,%rdi
     cc3:	e8 00 00 00 00       	call   cc8 <_ZN8MemTable7getSizeEv+0x24>
     cc8:	48 8b 40 20          	mov    0x20(%rax),%rax
}
     ccc:	c9                   	leave  
     ccd:	c3                   	ret    

0000000000000cce <_ZN7KVStoreC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_>:
KVStore::KVStore(const std::string &dir, const std::string &vlog) : KVStoreAPI(dir, vlog)
     cce:	f3 0f 1e fa          	endbr64 
     cd2:	55                   	push   %rbp
     cd3:	48 89 e5             	mov    %rsp,%rbp
     cd6:	53                   	push   %rbx
     cd7:	48 83 ec 68          	sub    $0x68,%rsp
     cdb:	48 89 7d a8          	mov    %rdi,-0x58(%rbp)
     cdf:	48 89 75 a0          	mov    %rsi,-0x60(%rbp)
     ce3:	48 89 55 98          	mov    %rdx,-0x68(%rbp)
     ce7:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
     cee:	00 00 
     cf0:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
     cf4:	31 c0                	xor    %eax,%eax
     cf6:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
     cfa:	48 8b 55 98          	mov    -0x68(%rbp),%rdx
     cfe:	48 8b 4d a0          	mov    -0x60(%rbp),%rcx
     d02:	48 89 ce             	mov    %rcx,%rsi
     d05:	48 89 c7             	mov    %rax,%rdi
     d08:	e8 00 00 00 00       	call   d0d <_ZN7KVStoreC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_+0x3f>
     d0d:	48 8d 15 00 00 00 00 	lea    0x0(%rip),%rdx        # d14 <_ZN7KVStoreC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_+0x46>
     d14:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
     d18:	48 89 10             	mov    %rdx,(%rax)
     d1b:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
     d1f:	48 83 c0 08          	add    $0x8,%rax
     d23:	48 89 c7             	mov    %rax,%rdi
     d26:	e8 00 00 00 00       	call   d2b <_ZN7KVStoreC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_+0x5d>
     d2b:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
     d2f:	48 83 c0 20          	add    $0x20,%rax
     d33:	48 89 c7             	mov    %rax,%rdi
     d36:	e8 00 00 00 00       	call   d3b <_ZN7KVStoreC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_+0x6d>
     d3b:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
     d3f:	48 83 c0 40          	add    $0x40,%rax
     d43:	48 89 c7             	mov    %rax,%rdi
     d46:	e8 00 00 00 00       	call   d4b <_ZN7KVStoreC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_+0x7d>
     d4b:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
     d4f:	48 83 c0 60          	add    $0x60,%rax
     d53:	48 89 c7             	mov    %rax,%rdi
     d56:	e8 00 00 00 00       	call   d5b <_ZN7KVStoreC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_+0x8d>
     d5b:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
     d5f:	48 83 e8 80          	sub    $0xffffffffffffff80,%rax
     d63:	48 89 c7             	mov    %rax,%rdi
     d66:	e8 00 00 00 00       	call   d6b <_ZN7KVStoreC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_+0x9d>
{
    this->dataDir = dir;
     d6b:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
     d6f:	48 8d 50 60          	lea    0x60(%rax),%rdx
     d73:	48 8b 45 a0          	mov    -0x60(%rbp),%rax
     d77:	48 89 c6             	mov    %rax,%rsi
     d7a:	48 89 d7             	mov    %rdx,%rdi
     d7d:	e8 00 00 00 00       	call   d82 <_ZN7KVStoreC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_+0xb4>
    this->vlogDir = vlog;
     d82:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
     d86:	48 8d 90 80 00 00 00 	lea    0x80(%rax),%rdx
     d8d:	48 8b 45 98          	mov    -0x68(%rbp),%rax
     d91:	48 89 c6             	mov    %rax,%rsi
     d94:	48 89 d7             	mov    %rdx,%rdi
     d97:	e8 00 00 00 00       	call   d9c <_ZN7KVStoreC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_+0xce>
    utils::_mkdir("./data/vlog");
     d9c:	48 8d 45 bf          	lea    -0x41(%rbp),%rax
     da0:	48 89 c7             	mov    %rax,%rdi
     da3:	e8 00 00 00 00       	call   da8 <_ZN7KVStoreC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_+0xda>
     da8:	48 8d 55 bf          	lea    -0x41(%rbp),%rdx
     dac:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
     db0:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # db7 <_ZN7KVStoreC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_+0xe9>
     db7:	48 89 ce             	mov    %rcx,%rsi
     dba:	48 89 c7             	mov    %rax,%rdi
     dbd:	e8 00 00 00 00       	call   dc2 <_ZN7KVStoreC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_+0xf4>
     dc2:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
     dc6:	48 89 c7             	mov    %rax,%rdi
     dc9:	e8 32 f2 ff ff       	call   0 <_ZN5utilsL6_mkdirERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE>
     dce:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
     dd2:	48 89 c7             	mov    %rax,%rdi
     dd5:	e8 00 00 00 00       	call   dda <_ZN7KVStoreC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_+0x10c>
     dda:	48 8d 45 bf          	lea    -0x41(%rbp),%rax
     dde:	48 89 c7             	mov    %rax,%rdi
     de1:	e8 00 00 00 00       	call   de6 <_ZN7KVStoreC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_+0x118>
}
     de6:	90                   	nop
     de7:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
     deb:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
     df2:	00 00 
     df4:	74 7e                	je     e74 <_ZN7KVStoreC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_+0x1a6>
     df6:	eb 77                	jmp    e6f <_ZN7KVStoreC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_+0x1a1>
     df8:	f3 0f 1e fa          	endbr64 
    utils::_mkdir("./data/vlog");
     dfc:	48 89 c3             	mov    %rax,%rbx
     dff:	48 8d 45 bf          	lea    -0x41(%rbp),%rax
     e03:	48 89 c7             	mov    %rax,%rdi
     e06:	e8 00 00 00 00       	call   e0b <_ZN7KVStoreC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_+0x13d>
     e0b:	eb 07                	jmp    e14 <_ZN7KVStoreC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_+0x146>
     e0d:	f3 0f 1e fa          	endbr64 
}
     e11:	48 89 c3             	mov    %rax,%rbx
     e14:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
     e18:	48 83 e8 80          	sub    $0xffffffffffffff80,%rax
     e1c:	48 89 c7             	mov    %rax,%rdi
     e1f:	e8 00 00 00 00       	call   e24 <_ZN7KVStoreC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_+0x156>
     e24:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
     e28:	48 83 c0 60          	add    $0x60,%rax
     e2c:	48 89 c7             	mov    %rax,%rdi
     e2f:	e8 00 00 00 00       	call   e34 <_ZN7KVStoreC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_+0x166>
     e34:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
     e38:	48 83 c0 40          	add    $0x40,%rax
     e3c:	48 89 c7             	mov    %rax,%rdi
     e3f:	e8 00 00 00 00       	call   e44 <_ZN7KVStoreC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_+0x176>
     e44:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
     e48:	48 83 c0 20          	add    $0x20,%rax
     e4c:	48 89 c7             	mov    %rax,%rdi
     e4f:	e8 00 00 00 00       	call   e54 <_ZN7KVStoreC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_+0x186>
     e54:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
     e58:	48 83 c0 08          	add    $0x8,%rax
     e5c:	48 89 c7             	mov    %rax,%rdi
     e5f:	e8 00 00 00 00       	call   e64 <_ZN7KVStoreC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_+0x196>
     e64:	48 89 d8             	mov    %rbx,%rax
     e67:	48 89 c7             	mov    %rax,%rdi
     e6a:	e8 00 00 00 00       	call   e6f <_ZN7KVStoreC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_+0x1a1>
     e6f:	e8 00 00 00 00       	call   e74 <_ZN7KVStoreC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_+0x1a6>
     e74:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
     e78:	c9                   	leave  
     e79:	c3                   	ret    

0000000000000e7a <_ZN7KVStoreD1Ev>:

KVStore::~KVStore()
     e7a:	f3 0f 1e fa          	endbr64 
     e7e:	55                   	push   %rbp
     e7f:	48 89 e5             	mov    %rsp,%rbp
     e82:	48 83 ec 10          	sub    $0x10,%rsp
     e86:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
     e8a:	48 8d 15 00 00 00 00 	lea    0x0(%rip),%rdx        # e91 <_ZN7KVStoreD1Ev+0x17>
     e91:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
     e95:	48 89 10             	mov    %rdx,(%rax)
{
}
     e98:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
     e9c:	48 83 e8 80          	sub    $0xffffffffffffff80,%rax
     ea0:	48 89 c7             	mov    %rax,%rdi
     ea3:	e8 00 00 00 00       	call   ea8 <_ZN7KVStoreD1Ev+0x2e>
     ea8:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
     eac:	48 83 c0 60          	add    $0x60,%rax
     eb0:	48 89 c7             	mov    %rax,%rdi
     eb3:	e8 00 00 00 00       	call   eb8 <_ZN7KVStoreD1Ev+0x3e>
     eb8:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
     ebc:	48 83 c0 40          	add    $0x40,%rax
     ec0:	48 89 c7             	mov    %rax,%rdi
     ec3:	e8 00 00 00 00       	call   ec8 <_ZN7KVStoreD1Ev+0x4e>
     ec8:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
     ecc:	48 83 c0 20          	add    $0x20,%rax
     ed0:	48 89 c7             	mov    %rax,%rdi
     ed3:	e8 00 00 00 00       	call   ed8 <_ZN7KVStoreD1Ev+0x5e>
     ed8:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
     edc:	48 83 c0 08          	add    $0x8,%rax
     ee0:	48 89 c7             	mov    %rax,%rdi
     ee3:	e8 00 00 00 00       	call   ee8 <_ZN7KVStoreD1Ev+0x6e>
     ee8:	90                   	nop
     ee9:	c9                   	leave  
     eea:	c3                   	ret    
     eeb:	90                   	nop

0000000000000eec <_ZN8MemTable9getMinKeyEv>:

int MemTable::getMinKey()
{
     eec:	f3 0f 1e fa          	endbr64 
     ef0:	55                   	push   %rbp
     ef1:	48 89 e5             	mov    %rsp,%rbp
     ef4:	48 83 ec 10          	sub    $0x10,%rsp
     ef8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    return this->last()->frist()->key;
     efc:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
     f00:	48 89 c7             	mov    %rax,%rdi
     f03:	e8 00 00 00 00       	call   f08 <_ZN8MemTable9getMinKeyEv+0x1c>
     f08:	48 89 c7             	mov    %rax,%rdi
     f0b:	e8 00 00 00 00       	call   f10 <_ZN8MemTable9getMinKeyEv+0x24>
     f10:	48 8b 40 20          	mov    0x20(%rax),%rax
}
     f14:	c9                   	leave  
     f15:	c3                   	ret    

0000000000000f16 <_ZN8MemTable9getMaxKeyEv>:
int MemTable::getMaxKey()
{
     f16:	f3 0f 1e fa          	endbr64 
     f1a:	55                   	push   %rbp
     f1b:	48 89 e5             	mov    %rsp,%rbp
     f1e:	48 83 ec 10          	sub    $0x10,%rsp
     f22:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    return this->last()->last()->key;
     f26:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
     f2a:	48 89 c7             	mov    %rax,%rdi
     f2d:	e8 00 00 00 00       	call   f32 <_ZN8MemTable9getMaxKeyEv+0x1c>
     f32:	48 89 c7             	mov    %rax,%rdi
     f35:	e8 00 00 00 00       	call   f3a <_ZN8MemTable9getMaxKeyEv+0x24>
     f3a:	48 8b 40 20          	mov    0x20(%rax),%rax
}
     f3e:	c9                   	leave  
     f3f:	c3                   	ret    

0000000000000f40 <_ZN7KVStore3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE>:
/**
 * Insert/Update the key-value pair.
 * No return values for simplicity.
 */
void KVStore::put(uint64_t key, const std::string &val)
{
     f40:	f3 0f 1e fa          	endbr64 
     f44:	55                   	push   %rbp
     f45:	48 89 e5             	mov    %rsp,%rbp
     f48:	53                   	push   %rbx
     f49:	48 83 ec 68          	sub    $0x68,%rsp
     f4d:	48 89 7d a8          	mov    %rdi,-0x58(%rbp)
     f51:	48 89 75 a0          	mov    %rsi,-0x60(%rbp)
     f55:	48 89 55 98          	mov    %rdx,-0x68(%rbp)
     f59:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
     f60:	00 00 
     f62:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
     f66:	31 c0                	xor    %eax,%eax
    //we get the val frist
    //isFind is to know is the value exist
    bool isFind = false;
     f68:	c6 45 bf 00          	movb   $0x0,-0x41(%rbp)
    std::string v = memTable.get(key , isFind);
     f6c:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
     f70:	48 8d 70 20          	lea    0x20(%rax),%rsi
     f74:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
     f78:	48 8d 4d bf          	lea    -0x41(%rbp),%rcx
     f7c:	48 8b 55 a0          	mov    -0x60(%rbp),%rdx
     f80:	48 89 c7             	mov    %rax,%rdi
     f83:	e8 00 00 00 00       	call   f88 <_ZN7KVStore3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x48>

    //if not out of range, we insert a key.
    if(memTable.getSize() < 408)
     f88:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
     f8c:	48 83 c0 20          	add    $0x20,%rax
     f90:	48 89 c7             	mov    %rax,%rdi
     f93:	e8 00 00 00 00       	call   f98 <_ZN7KVStore3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x58>
     f98:	3d 97 01 00 00       	cmp    $0x197,%eax
     f9d:	0f 9e c0             	setle  %al
     fa0:	84 c0                	test   %al,%al
     fa2:	74 22                	je     fc6 <_ZN7KVStore3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x86>
    {
        memTable.put(key , val);
     fa4:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
     fa8:	48 8d 48 20          	lea    0x20(%rax),%rcx
     fac:	48 8b 55 98          	mov    -0x68(%rbp),%rdx
     fb0:	48 8b 45 a0          	mov    -0x60(%rbp),%rax
     fb4:	48 89 c6             	mov    %rax,%rsi
     fb7:	48 89 cf             	mov    %rcx,%rdi
     fba:	e8 00 00 00 00       	call   fbf <_ZN7KVStore3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x7f>
        return;
     fbf:	bb 00 00 00 00       	mov    $0x0,%ebx
     fc4:	eb 05                	jmp    fcb <_ZN7KVStore3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x8b>
    }

    //if out of range ,we build ssTable frist; 
    buildSSTable();

    //then we input again
     fc6:	bb 01 00 00 00       	mov    $0x1,%ebx
     fcb:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
     fcf:	48 89 c7             	mov    %rax,%rdi
     fd2:	e8 00 00 00 00       	call   fd7 <_ZN7KVStore3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x97>
     fd7:	83 fb 01             	cmp    $0x1,%ebx
     fda:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
     fde:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
     fe5:	00 00 
     fe7:	74 25                	je     100e <_ZN7KVStore3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0xce>
     fe9:	eb 1e                	jmp    1009 <_ZN7KVStore3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0xc9>
     feb:	f3 0f 1e fa          	endbr64 
     fef:	48 89 c3             	mov    %rax,%rbx
     ff2:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
     ff6:	48 89 c7             	mov    %rax,%rdi
     ff9:	e8 00 00 00 00       	call   ffe <_ZN7KVStore3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0xbe>
     ffe:	48 89 d8             	mov    %rbx,%rax
    1001:	48 89 c7             	mov    %rax,%rdi
    1004:	e8 00 00 00 00       	call   1009 <_ZN7KVStore3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0xc9>
    1009:	e8 00 00 00 00       	call   100e <_ZN7KVStore3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0xce>
    100e:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
    1012:	c9                   	leave  
    1013:	c3                   	ret    

0000000000001014 <_ZN7KVStore3getB5cxx11Em>:
    memTable.put(key , val);

}
/**
 * Returns the (string) value of the given key.
 * An empty string indicates not found.
    1014:	f3 0f 1e fa          	endbr64 
    1018:	55                   	push   %rbp
    1019:	48 89 e5             	mov    %rsp,%rbp
    101c:	53                   	push   %rbx
    101d:	48 81 ec c8 02 00 00 	sub    $0x2c8,%rsp
    1024:	48 89 bd 48 fd ff ff 	mov    %rdi,-0x2b8(%rbp)
    102b:	48 89 b5 40 fd ff ff 	mov    %rsi,-0x2c0(%rbp)
    1032:	48 89 95 38 fd ff ff 	mov    %rdx,-0x2c8(%rbp)
    1039:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1040:	00 00 
    1042:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    1046:	31 c0                	xor    %eax,%eax
 */
std::string KVStore::get(uint64_t key)
    1048:	c6 85 56 fd ff ff 00 	movb   $0x0,-0x2aa(%rbp)
{
    104f:	48 8b 85 40 fd ff ff 	mov    -0x2c0(%rbp),%rax
    1056:	48 8d 70 20          	lea    0x20(%rax),%rsi
    105a:	48 8d 85 60 fd ff ff 	lea    -0x2a0(%rbp),%rax
    1061:	48 8d 8d 56 fd ff ff 	lea    -0x2aa(%rbp),%rcx
    1068:	48 8b 95 38 fd ff ff 	mov    -0x2c8(%rbp),%rdx
    106f:	48 89 c7             	mov    %rax,%rdi
    1072:	e8 00 00 00 00       	call   1077 <_ZN7KVStore3getB5cxx11Em+0x63>
    //Frist , we get data from memTable
    bool isFind = false;
    1077:	0f b6 85 56 fd ff ff 	movzbl -0x2aa(%rbp),%eax
    107e:	84 c0                	test   %al,%al
    1080:	74 1e                	je     10a0 <_ZN7KVStore3getB5cxx11Em+0x8c>
    std::string v = memTable.get(key , isFind);
    1082:	48 8d 95 60 fd ff ff 	lea    -0x2a0(%rbp),%rdx
    1089:	48 8b 85 48 fd ff ff 	mov    -0x2b8(%rbp),%rax
    1090:	48 89 d6             	mov    %rdx,%rsi
    1093:	48 89 c7             	mov    %rax,%rdi
    1096:	e8 00 00 00 00       	call   109b <_ZN7KVStore3getB5cxx11Em+0x87>
    109b:	e9 97 01 00 00       	jmp    1237 <_ZN7KVStore3getB5cxx11Em+0x223>

    if(isFind)
        return v;
    10a0:	c7 85 58 fd ff ff 00 	movl   $0x0,-0x2a8(%rbp)
    10a7:	00 00 00 
    10aa:	e9 07 01 00 00       	jmp    11b6 <_ZN7KVStore3getB5cxx11Em+0x1a2>
    else
    {
    10af:	c7 85 5c fd ff ff 00 	movl   $0x0,-0x2a4(%rbp)
    10b6:	00 00 00 
    10b9:	e9 bf 00 00 00       	jmp    117d <_ZN7KVStore3getB5cxx11Em+0x169>
        for(int i = 0 ; i < this->sslevel.size() ; i++)
        {
    10be:	48 8d 85 a0 fd ff ff 	lea    -0x260(%rbp),%rax
    10c5:	8b 95 5c fd ff ff    	mov    -0x2a4(%rbp),%edx
    10cb:	89 d6                	mov    %edx,%esi
    10cd:	48 89 c7             	mov    %rax,%rdi
    10d0:	e8 00 00 00 00       	call   10d5 <_ZN7KVStore3getB5cxx11Em+0xc1>
    10d5:	48 8b 85 40 fd ff ff 	mov    -0x2c0(%rbp),%rax
    10dc:	48 8d 88 80 00 00 00 	lea    0x80(%rax),%rcx
    10e3:	48 8d 85 80 fd ff ff 	lea    -0x280(%rbp),%rax
    10ea:	48 8d 15 00 00 00 00 	lea    0x0(%rip),%rdx        # 10f1 <_ZN7KVStore3getB5cxx11Em+0xdd>
    10f1:	48 89 ce             	mov    %rcx,%rsi
    10f4:	48 89 c7             	mov    %rax,%rdi
    10f7:	e8 00 00 00 00       	call   10fc <_ZN7KVStore3getB5cxx11Em+0xe8>
    10fc:	48 8d 85 c0 fd ff ff 	lea    -0x240(%rbp),%rax
    1103:	48 8d 95 a0 fd ff ff 	lea    -0x260(%rbp),%rdx
    110a:	48 8d 8d 80 fd ff ff 	lea    -0x280(%rbp),%rcx
    1111:	48 89 ce             	mov    %rcx,%rsi
    1114:	48 89 c7             	mov    %rax,%rdi
    1117:	e8 00 00 00 00       	call   111c <_ZN7KVStore3getB5cxx11Em+0x108>
    111c:	48 8d 8d c0 fd ff ff 	lea    -0x240(%rbp),%rcx
    1123:	48 8d 85 e0 fd ff ff 	lea    -0x220(%rbp),%rax
    112a:	ba 08 00 00 00       	mov    $0x8,%edx
    112f:	48 89 ce             	mov    %rcx,%rsi
    1132:	48 89 c7             	mov    %rax,%rdi
    1135:	e8 00 00 00 00       	call   113a <_ZN7KVStore3getB5cxx11Em+0x126>
    113a:	48 8d 85 e0 fd ff ff 	lea    -0x220(%rbp),%rax
    1141:	48 89 c7             	mov    %rax,%rdi
    1144:	e8 00 00 00 00       	call   1149 <_ZN7KVStore3getB5cxx11Em+0x135>
    1149:	48 8d 85 c0 fd ff ff 	lea    -0x240(%rbp),%rax
    1150:	48 89 c7             	mov    %rax,%rdi
    1153:	e8 00 00 00 00       	call   1158 <_ZN7KVStore3getB5cxx11Em+0x144>
    1158:	48 8d 85 80 fd ff ff 	lea    -0x280(%rbp),%rax
    115f:	48 89 c7             	mov    %rax,%rdi
    1162:	e8 00 00 00 00       	call   1167 <_ZN7KVStore3getB5cxx11Em+0x153>
    1167:	48 8d 85 a0 fd ff ff 	lea    -0x260(%rbp),%rax
    116e:	48 89 c7             	mov    %rax,%rdi
    1171:	e8 00 00 00 00       	call   1176 <_ZN7KVStore3getB5cxx11Em+0x162>
    {
    1176:	83 85 5c fd ff ff 01 	addl   $0x1,-0x2a4(%rbp)
    117d:	48 8b 85 40 fd ff ff 	mov    -0x2c0(%rbp),%rax
    1184:	48 8d 50 08          	lea    0x8(%rax),%rdx
    1188:	8b 85 58 fd ff ff    	mov    -0x2a8(%rbp),%eax
    118e:	48 98                	cltq   
    1190:	48 89 c6             	mov    %rax,%rsi
    1193:	48 89 d7             	mov    %rdx,%rdi
    1196:	e8 00 00 00 00       	call   119b <_ZN7KVStore3getB5cxx11Em+0x187>
    119b:	8b 40 04             	mov    0x4(%rax),%eax
    119e:	39 85 5c fd ff ff    	cmp    %eax,-0x2a4(%rbp)
    11a4:	0f 9c c0             	setl   %al
    11a7:	84 c0                	test   %al,%al
    11a9:	0f 85 0f ff ff ff    	jne    10be <_ZN7KVStore3getB5cxx11Em+0xaa>
        return v;
    11af:	83 85 58 fd ff ff 01 	addl   $0x1,-0x2a8(%rbp)
    11b6:	8b 85 58 fd ff ff    	mov    -0x2a8(%rbp),%eax
    11bc:	48 63 d8             	movslq %eax,%rbx
    11bf:	48 8b 85 40 fd ff ff 	mov    -0x2c0(%rbp),%rax
    11c6:	48 83 c0 08          	add    $0x8,%rax
    11ca:	48 89 c7             	mov    %rax,%rdi
    11cd:	e8 00 00 00 00       	call   11d2 <_ZN7KVStore3getB5cxx11Em+0x1be>
    11d2:	48 39 c3             	cmp    %rax,%rbx
    11d5:	0f 92 c0             	setb   %al
    11d8:	84 c0                	test   %al,%al
    11da:	0f 85 cf fe ff ff    	jne    10af <_ZN7KVStore3getB5cxx11Em+0x9b>
            for(int j = 0 ; j < this->sslevel[i].currentNum ; j++)
            {
                std::ifstream(vlogDir + "/Level" + std::to_string(j));
    11e0:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 11e7 <_ZN7KVStore3getB5cxx11Em+0x1d3>
    11e7:	48 89 c6             	mov    %rax,%rsi
    11ea:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 11f1 <_ZN7KVStore3getB5cxx11Em+0x1dd>
    11f1:	48 89 c7             	mov    %rax,%rdi
    11f4:	e8 00 00 00 00       	call   11f9 <_ZN7KVStore3getB5cxx11Em+0x1e5>
            }
        }
    }
    11f9:	48 8d 85 57 fd ff ff 	lea    -0x2a9(%rbp),%rax
    1200:	48 89 c7             	mov    %rax,%rdi
    1203:	e8 00 00 00 00       	call   1208 <_ZN7KVStore3getB5cxx11Em+0x1f4>
    1208:	48 8d 95 57 fd ff ff 	lea    -0x2a9(%rbp),%rdx
    120f:	48 8b 85 48 fd ff ff 	mov    -0x2b8(%rbp),%rax
    1216:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # 121d <_ZN7KVStore3getB5cxx11Em+0x209>
    121d:	48 89 ce             	mov    %rcx,%rsi
    1220:	48 89 c7             	mov    %rax,%rdi
    1223:	e8 00 00 00 00       	call   1228 <_ZN7KVStore3getB5cxx11Em+0x214>
    1228:	48 8d 85 57 fd ff ff 	lea    -0x2a9(%rbp),%rax
    122f:	48 89 c7             	mov    %rax,%rdi
    1232:	e8 00 00 00 00       	call   1237 <_ZN7KVStore3getB5cxx11Em+0x223>
    return "";
    1237:	48 8d 85 60 fd ff ff 	lea    -0x2a0(%rbp),%rax
    123e:	48 89 c7             	mov    %rax,%rdi
    1241:	e8 00 00 00 00       	call   1246 <_ZN7KVStore3getB5cxx11Em+0x232>
    1246:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    124a:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    1251:	00 00 
    1253:	0f 84 8b 00 00 00    	je     12e4 <_ZN7KVStore3getB5cxx11Em+0x2d0>
    1259:	e9 81 00 00 00       	jmp    12df <_ZN7KVStore3getB5cxx11Em+0x2cb>
    125e:	f3 0f 1e fa          	endbr64 
        {
    1262:	48 89 c3             	mov    %rax,%rbx
    1265:	48 8d 85 c0 fd ff ff 	lea    -0x240(%rbp),%rax
    126c:	48 89 c7             	mov    %rax,%rdi
    126f:	e8 00 00 00 00       	call   1274 <_ZN7KVStore3getB5cxx11Em+0x260>
    1274:	eb 07                	jmp    127d <_ZN7KVStore3getB5cxx11Em+0x269>
    1276:	f3 0f 1e fa          	endbr64 
    127a:	48 89 c3             	mov    %rax,%rbx
    127d:	48 8d 85 80 fd ff ff 	lea    -0x280(%rbp),%rax
    1284:	48 89 c7             	mov    %rax,%rdi
    1287:	e8 00 00 00 00       	call   128c <_ZN7KVStore3getB5cxx11Em+0x278>
    128c:	eb 07                	jmp    1295 <_ZN7KVStore3getB5cxx11Em+0x281>
    128e:	f3 0f 1e fa          	endbr64 
    1292:	48 89 c3             	mov    %rax,%rbx
    1295:	48 8d 85 a0 fd ff ff 	lea    -0x260(%rbp),%rax
    129c:	48 89 c7             	mov    %rax,%rdi
    129f:	e8 00 00 00 00       	call   12a4 <_ZN7KVStore3getB5cxx11Em+0x290>
    12a4:	eb 1f                	jmp    12c5 <_ZN7KVStore3getB5cxx11Em+0x2b1>
    12a6:	f3 0f 1e fa          	endbr64 
    }
    12aa:	48 89 c3             	mov    %rax,%rbx
    12ad:	48 8d 85 57 fd ff ff 	lea    -0x2a9(%rbp),%rax
    12b4:	48 89 c7             	mov    %rax,%rdi
    12b7:	e8 00 00 00 00       	call   12bc <_ZN7KVStore3getB5cxx11Em+0x2a8>
    12bc:	eb 07                	jmp    12c5 <_ZN7KVStore3getB5cxx11Em+0x2b1>
    12be:	f3 0f 1e fa          	endbr64 
    return "";
    12c2:	48 89 c3             	mov    %rax,%rbx
    12c5:	48 8d 85 60 fd ff ff 	lea    -0x2a0(%rbp),%rax
    12cc:	48 89 c7             	mov    %rax,%rdi
    12cf:	e8 00 00 00 00       	call   12d4 <_ZN7KVStore3getB5cxx11Em+0x2c0>
    12d4:	48 89 d8             	mov    %rbx,%rax
    12d7:	48 89 c7             	mov    %rax,%rdi
    12da:	e8 00 00 00 00       	call   12df <_ZN7KVStore3getB5cxx11Em+0x2cb>
    12df:	e8 00 00 00 00       	call   12e4 <_ZN7KVStore3getB5cxx11Em+0x2d0>
    12e4:	48 8b 85 48 fd ff ff 	mov    -0x2b8(%rbp),%rax
    12eb:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
    12ef:	c9                   	leave  
    12f0:	c3                   	ret    
    12f1:	90                   	nop

00000000000012f2 <_ZN7KVStore3delEm>:

/**
 * Delete the given key-value pair if it exists.
 * Returns false iff the key is not found.
 */
bool KVStore::del(uint64_t key)
    12f2:	f3 0f 1e fa          	endbr64 
    12f6:	55                   	push   %rbp
    12f7:	48 89 e5             	mov    %rsp,%rbp
    12fa:	53                   	push   %rbx
    12fb:	48 83 ec 78          	sub    $0x78,%rsp
    12ff:	48 89 7d 88          	mov    %rdi,-0x78(%rbp)
    1303:	48 89 75 80          	mov    %rsi,-0x80(%rbp)
    1307:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    130e:	00 00 
    1310:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    1314:	31 c0                	xor    %eax,%eax
{
    1316:	c6 45 9e 00          	movb   $0x0,-0x62(%rbp)
    bool isFind = false;
    131a:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    131e:	48 8d 70 20          	lea    0x20(%rax),%rsi
    1322:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
    1326:	48 8d 4d 9e          	lea    -0x62(%rbp),%rcx
    132a:	48 8b 55 80          	mov    -0x80(%rbp),%rdx
    132e:	48 89 c7             	mov    %rax,%rdi
    1331:	e8 00 00 00 00       	call   1336 <_ZN7KVStore3delEm+0x44>
    // frist , we find in memTable
    std::string v = memTable.get(key , isFind);
    1336:	0f b6 45 9e          	movzbl -0x62(%rbp),%eax
    133a:	83 f0 01             	xor    $0x1,%eax
    133d:	84 c0                	test   %al,%al
    133f:	74 07                	je     1348 <_ZN7KVStore3delEm+0x56>

    1341:	bb 00 00 00 00       	mov    $0x0,%ebx
    1346:	eb 5e                	jmp    13a6 <_ZN7KVStore3delEm+0xb4>
    //Then , we find it in ssTable
    1348:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    134c:	48 8d 58 20          	lea    0x20(%rax),%rbx
    1350:	48 8d 45 9f          	lea    -0x61(%rbp),%rax
    1354:	48 89 c7             	mov    %rax,%rdi
    1357:	e8 00 00 00 00       	call   135c <_ZN7KVStore3delEm+0x6a>
    135c:	48 8d 55 9f          	lea    -0x61(%rbp),%rdx
    1360:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
    1364:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # 136b <_ZN7KVStore3delEm+0x79>
    136b:	48 89 ce             	mov    %rcx,%rsi
    136e:	48 89 c7             	mov    %rax,%rdi
    1371:	e8 00 00 00 00       	call   1376 <_ZN7KVStore3delEm+0x84>
    1376:	48 8d 55 c0          	lea    -0x40(%rbp),%rdx
    137a:	48 8b 45 80          	mov    -0x80(%rbp),%rax
    137e:	48 89 c6             	mov    %rax,%rsi
    1381:	48 89 df             	mov    %rbx,%rdi
    1384:	e8 00 00 00 00       	call   1389 <_ZN7KVStore3delEm+0x97>
    1389:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
    138d:	48 89 c7             	mov    %rax,%rdi
    1390:	e8 00 00 00 00       	call   1395 <_ZN7KVStore3delEm+0xa3>
    1395:	48 8d 45 9f          	lea    -0x61(%rbp),%rax
    1399:	48 89 c7             	mov    %rax,%rdi
    139c:	e8 00 00 00 00       	call   13a1 <_ZN7KVStore3delEm+0xaf>
    if(!isFind)
    13a1:	bb 01 00 00 00       	mov    $0x1,%ebx
	{
    13a6:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
    13aa:	48 89 c7             	mov    %rax,%rdi
    13ad:	e8 00 00 00 00       	call   13b2 <_ZN7KVStore3delEm+0xc0>
    13b2:	89 d8                	mov    %ebx,%eax
    13b4:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    13b8:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
    13bf:	00 00 
    13c1:	74 46                	je     1409 <_ZN7KVStore3delEm+0x117>
    13c3:	eb 3f                	jmp    1404 <_ZN7KVStore3delEm+0x112>
    13c5:	f3 0f 1e fa          	endbr64 
    //Then , we find it in ssTable
    13c9:	48 89 c3             	mov    %rax,%rbx
    13cc:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
    13d0:	48 89 c7             	mov    %rax,%rdi
    13d3:	e8 00 00 00 00       	call   13d8 <_ZN7KVStore3delEm+0xe6>
    13d8:	eb 07                	jmp    13e1 <_ZN7KVStore3delEm+0xef>
    13da:	f3 0f 1e fa          	endbr64 
    13de:	48 89 c3             	mov    %rax,%rbx
    13e1:	48 8d 45 9f          	lea    -0x61(%rbp),%rax
    13e5:	48 89 c7             	mov    %rax,%rdi
    13e8:	e8 00 00 00 00       	call   13ed <_ZN7KVStore3delEm+0xfb>
	{
    13ed:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
    13f1:	48 89 c7             	mov    %rax,%rdi
    13f4:	e8 00 00 00 00       	call   13f9 <_ZN7KVStore3delEm+0x107>
    13f9:	48 89 d8             	mov    %rbx,%rax
    13fc:	48 89 c7             	mov    %rax,%rdi
    13ff:	e8 00 00 00 00       	call   1404 <_ZN7KVStore3delEm+0x112>
    1404:	e8 00 00 00 00       	call   1409 <_ZN7KVStore3delEm+0x117>
    1409:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
    140d:	c9                   	leave  
    140e:	c3                   	ret    
    140f:	90                   	nop

0000000000001410 <_ZN7KVStore5resetEv>:
    }
    memTable.put(key , "~DELETED~");
    return true;
}

/**
    1410:	f3 0f 1e fa          	endbr64 
    1414:	55                   	push   %rbp
    1415:	48 89 e5             	mov    %rsp,%rbp
    1418:	53                   	push   %rbx
    1419:	48 81 ec 98 00 00 00 	sub    $0x98,%rsp
    1420:	48 89 bd 68 ff ff ff 	mov    %rdi,-0x98(%rbp)
    1427:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    142e:	00 00 
    1430:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    1434:	31 c0                	xor    %eax,%eax
 * This resets the kvstore. All key-value pairs should be removed,
    1436:	c7 85 7c ff ff ff 00 	movl   $0x0,-0x84(%rbp)
    143d:	00 00 00 
    1440:	eb 7a                	jmp    14bc <_ZN7KVStore5resetEv+0xac>
 * including memtable and all sstables files.
 */
    1442:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
    1446:	8b 95 7c ff ff ff    	mov    -0x84(%rbp),%edx
    144c:	89 d6                	mov    %edx,%esi
    144e:	48 89 c7             	mov    %rax,%rdi
    1451:	e8 00 00 00 00       	call   1456 <_ZN7KVStore5resetEv+0x46>
    1456:	48 8b 85 68 ff ff ff 	mov    -0x98(%rbp),%rax
    145d:	48 8d 88 80 00 00 00 	lea    0x80(%rax),%rcx
    1464:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
    1468:	48 8d 15 00 00 00 00 	lea    0x0(%rip),%rdx        # 146f <_ZN7KVStore5resetEv+0x5f>
    146f:	48 89 ce             	mov    %rcx,%rsi
    1472:	48 89 c7             	mov    %rax,%rdi
    1475:	e8 00 00 00 00       	call   147a <_ZN7KVStore5resetEv+0x6a>
    147a:	48 8d 45 80          	lea    -0x80(%rbp),%rax
    147e:	48 8d 55 c0          	lea    -0x40(%rbp),%rdx
    1482:	48 8d 4d a0          	lea    -0x60(%rbp),%rcx
    1486:	48 89 ce             	mov    %rcx,%rsi
    1489:	48 89 c7             	mov    %rax,%rdi
    148c:	e8 00 00 00 00       	call   1491 <_ZN7KVStore5resetEv+0x81>
    1491:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
    1495:	48 89 c7             	mov    %rax,%rdi
    1498:	e8 00 00 00 00       	call   149d <_ZN7KVStore5resetEv+0x8d>
    149d:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
    14a1:	48 89 c7             	mov    %rax,%rdi
    14a4:	e8 00 00 00 00       	call   14a9 <_ZN7KVStore5resetEv+0x99>
void KVStore::reset()
    14a9:	48 8d 45 80          	lea    -0x80(%rbp),%rax
    14ad:	48 89 c7             	mov    %rax,%rdi
    14b0:	e8 00 00 00 00       	call   14b5 <_ZN7KVStore5resetEv+0xa5>
 * This resets the kvstore. All key-value pairs should be removed,
    14b5:	83 85 7c ff ff ff 01 	addl   $0x1,-0x84(%rbp)
    14bc:	8b 85 7c ff ff ff    	mov    -0x84(%rbp),%eax
    14c2:	48 63 d8             	movslq %eax,%rbx
    14c5:	48 8b 85 68 ff ff ff 	mov    -0x98(%rbp),%rax
    14cc:	48 83 c0 08          	add    $0x8,%rax
    14d0:	48 89 c7             	mov    %rax,%rdi
    14d3:	e8 00 00 00 00       	call   14d8 <_ZN7KVStore5resetEv+0xc8>
    14d8:	48 39 c3             	cmp    %rax,%rbx
    14db:	0f 96 c0             	setbe  %al
    14de:	84 c0                	test   %al,%al
    14e0:	0f 85 5c ff ff ff    	jne    1442 <_ZN7KVStore5resetEv+0x32>
{
    14e6:	eb 33                	jmp    151b <_ZN7KVStore5resetEv+0x10b>
    14e8:	f3 0f 1e fa          	endbr64 
    14ec:	48 89 c3             	mov    %rax,%rbx
    14ef:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
    14f3:	48 89 c7             	mov    %rax,%rdi
    14f6:	e8 00 00 00 00       	call   14fb <_ZN7KVStore5resetEv+0xeb>
    14fb:	eb 07                	jmp    1504 <_ZN7KVStore5resetEv+0xf4>
    14fd:	f3 0f 1e fa          	endbr64 
    1501:	48 89 c3             	mov    %rax,%rbx
    1504:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
    1508:	48 89 c7             	mov    %rax,%rdi
    150b:	e8 00 00 00 00       	call   1510 <_ZN7KVStore5resetEv+0x100>
    1510:	48 89 d8             	mov    %rbx,%rax
    1513:	48 89 c7             	mov    %rax,%rdi
    1516:	e8 00 00 00 00       	call   151b <_ZN7KVStore5resetEv+0x10b>
    151b:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    151f:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    1526:	00 00 
    1528:	74 05                	je     152f <_ZN7KVStore5resetEv+0x11f>
    152a:	e8 00 00 00 00       	call   152f <_ZN7KVStore5resetEv+0x11f>
    152f:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
    1533:	c9                   	leave  
    1534:	c3                   	ret    
    1535:	90                   	nop

0000000000001536 <_ZN7KVStore4scanEmmRNSt7__cxx114listISt4pairImNS0_12basic_stringIcSt11char_traitsIcESaIcEEEESaIS8_EEE>:
        std::string rmName = vlogDir + "/Level" + std::to_string(i);
    }
}

/**
 * Return a list including all the key-value pair between key1 and key2.
    1536:	f3 0f 1e fa          	endbr64 
    153a:	55                   	push   %rbp
    153b:	48 89 e5             	mov    %rsp,%rbp
    153e:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1542:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    1546:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
    154a:	48 89 4d e0          	mov    %rcx,-0x20(%rbp)
 * keys in the list should be in an ascending order.
    154e:	90                   	nop
    154f:	5d                   	pop    %rbp
    1550:	c3                   	ret    
    1551:	90                   	nop

0000000000001552 <_ZN7KVStore2gcEm>:
 */
void KVStore::scan(uint64_t key1, uint64_t key2, std::list<std::pair<uint64_t, std::string>> &list)
{
    
}

    1552:	f3 0f 1e fa          	endbr64 
    1556:	55                   	push   %rbp
    1557:	48 89 e5             	mov    %rsp,%rbp
    155a:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    155e:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
/**
    1562:	90                   	nop
    1563:	5d                   	pop    %rbp
    1564:	c3                   	ret    

0000000000001565 <_Z7to8BitsB5cxx11m>:
 * This reclaims space from vLog by moving valid value and discarding invalid value.
 * chunk_size is the size in byte you should AT LEAST recycle.
 */
    1565:	f3 0f 1e fa          	endbr64 
    1569:	55                   	push   %rbp
    156a:	48 89 e5             	mov    %rsp,%rbp
    156d:	53                   	push   %rbx
    156e:	48 83 ec 28          	sub    $0x28,%rsp
    1572:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
    1576:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
void KVStore::gc(uint64_t chunk_size)
    157a:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    157e:	48 89 c7             	mov    %rax,%rdi
    1581:	e8 00 00 00 00       	call   1586 <_Z7to8BitsB5cxx11m+0x21>
{
    1586:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    158a:	be 40 00 00 00       	mov    $0x40,%esi
    158f:	48 89 c7             	mov    %rax,%rdi
    1592:	e8 00 00 00 00       	call   1597 <_Z7to8BitsB5cxx11m+0x32>
}

    1597:	c7 45 ec 00 00 00 00 	movl   $0x0,-0x14(%rbp)
    159e:	eb 22                	jmp    15c2 <_Z7to8BitsB5cxx11m+0x5d>
std::string to8Bits(uint64_t value)
    15a0:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    15a4:	88 45 eb             	mov    %al,-0x15(%rbp)
{
    15a7:	48 c1 6d d0 03       	shrq   $0x3,-0x30(%rbp)
    std::string binaryString;
    15ac:	0f be 55 eb          	movsbl -0x15(%rbp),%edx
    15b0:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    15b4:	89 d6                	mov    %edx,%esi
    15b6:	48 89 c7             	mov    %rax,%rdi
    15b9:	e8 00 00 00 00       	call   15be <_Z7to8BitsB5cxx11m+0x59>

    15be:	83 45 ec 01          	addl   $0x1,-0x14(%rbp)
    15c2:	83 7d ec 07          	cmpl   $0x7,-0x14(%rbp)
    15c6:	7e d8                	jle    15a0 <_Z7to8BitsB5cxx11m+0x3b>
    binaryString.reserve(64);

    for (int i = 0; i < 8; i++) {
    15c8:	eb 1e                	jmp    15e8 <_Z7to8BitsB5cxx11m+0x83>
    15ca:	f3 0f 1e fa          	endbr64 
        char byte = (value % 256);
    15ce:	48 89 c3             	mov    %rax,%rbx
    15d1:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    15d5:	48 89 c7             	mov    %rax,%rdi
    15d8:	e8 00 00 00 00       	call   15dd <_Z7to8BitsB5cxx11m+0x78>
    15dd:	48 89 d8             	mov    %rbx,%rax
    15e0:	48 89 c7             	mov    %rax,%rdi
    15e3:	e8 00 00 00 00       	call   15e8 <_Z7to8BitsB5cxx11m+0x83>
    15e8:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    15ec:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
    15f0:	c9                   	leave  
    15f1:	c3                   	ret    

00000000000015f2 <_Z7to4BitsB5cxx11j>:
        value >>= 3;
        binaryString.push_back(byte);
    }
    15f2:	f3 0f 1e fa          	endbr64 
    15f6:	55                   	push   %rbp
    15f7:	48 89 e5             	mov    %rsp,%rbp
    15fa:	53                   	push   %rbx
    15fb:	48 83 ec 28          	sub    $0x28,%rsp
    15ff:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
    1603:	89 75 d4             	mov    %esi,-0x2c(%rbp)

    1606:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    160a:	48 89 c7             	mov    %rax,%rdi
    160d:	e8 00 00 00 00       	call   1612 <_Z7to4BitsB5cxx11j+0x20>
    return binaryString;
    1612:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    1616:	be 20 00 00 00       	mov    $0x20,%esi
    161b:	48 89 c7             	mov    %rax,%rdi
    161e:	e8 00 00 00 00       	call   1623 <_Z7to4BitsB5cxx11j+0x31>
}

    1623:	c7 45 ec 00 00 00 00 	movl   $0x0,-0x14(%rbp)
    162a:	eb 20                	jmp    164c <_Z7to4BitsB5cxx11j+0x5a>
std::string to4Bits(unsigned int  value)
    162c:	8b 45 d4             	mov    -0x2c(%rbp),%eax
    162f:	88 45 eb             	mov    %al,-0x15(%rbp)
{
    1632:	c1 6d d4 03          	shrl   $0x3,-0x2c(%rbp)
    std::string binaryString;
    1636:	0f be 55 eb          	movsbl -0x15(%rbp),%edx
    163a:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    163e:	89 d6                	mov    %edx,%esi
    1640:	48 89 c7             	mov    %rax,%rdi
    1643:	e8 00 00 00 00       	call   1648 <_Z7to4BitsB5cxx11j+0x56>

    1648:	83 45 ec 01          	addl   $0x1,-0x14(%rbp)
    164c:	83 7d ec 03          	cmpl   $0x3,-0x14(%rbp)
    1650:	7e da                	jle    162c <_Z7to4BitsB5cxx11j+0x3a>
    binaryString.reserve(32);

    for (int i = 0; i < 4; i++) {
    1652:	eb 1e                	jmp    1672 <_Z7to4BitsB5cxx11j+0x80>
    1654:	f3 0f 1e fa          	endbr64 
        char byte = (value % 256);
    1658:	48 89 c3             	mov    %rax,%rbx
    165b:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    165f:	48 89 c7             	mov    %rax,%rdi
    1662:	e8 00 00 00 00       	call   1667 <_Z7to4BitsB5cxx11j+0x75>
    1667:	48 89 d8             	mov    %rbx,%rax
    166a:	48 89 c7             	mov    %rax,%rdi
    166d:	e8 00 00 00 00       	call   1672 <_Z7to4BitsB5cxx11j+0x80>
    1672:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    1676:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
    167a:	c9                   	leave  
    167b:	c3                   	ret    

000000000000167c <_ZN7KVStore12buildSSTableEv>:
        value >>= 3;
        binaryString.push_back(byte);
    }
    167c:	f3 0f 1e fa          	endbr64 
    1680:	55                   	push   %rbp
    1681:	48 89 e5             	mov    %rsp,%rbp
    1684:	53                   	push   %rbx
    1685:	48 81 ec 00 10 00 00 	sub    $0x1000,%rsp
    168c:	48 83 0c 24 00       	orq    $0x0,(%rsp)
    1691:	48 81 ec 00 10 00 00 	sub    $0x1000,%rsp
    1698:	48 83 0c 24 00       	orq    $0x0,(%rsp)
    169d:	48 81 ec 38 03 00 00 	sub    $0x338,%rsp
    16a4:	48 89 bd c8 dc ff ff 	mov    %rdi,-0x2338(%rbp)
    16ab:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    16b2:	00 00 
    16b4:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    16b8:	31 c0                	xor    %eax,%eax

    return binaryString;
}

void KVStore::buildSSTable()
    16ba:	e8 00 00 00 00       	call   16bf <_ZN7KVStore12buildSSTableEv+0x43>
    16bf:	48 89 85 f0 dc ff ff 	mov    %rax,-0x2310(%rbp)
{
    16c6:	48 8d 85 f0 dc ff ff 	lea    -0x2310(%rbp),%rax
    16cd:	48 89 c7             	mov    %rax,%rdi
    16d0:	e8 00 00 00 00       	call   16d5 <_ZN7KVStore12buildSSTableEv+0x59>
    16d5:	48 89 85 f8 dc ff ff 	mov    %rax,-0x2308(%rbp)
    16dc:	48 8d 85 f8 dc ff ff 	lea    -0x2308(%rbp),%rax
    16e3:	48 89 c7             	mov    %rax,%rdi
    16e6:	e8 00 00 00 00       	call   16eb <_ZN7KVStore12buildSSTableEv+0x6f>
    16eb:	48 89 85 38 dd ff ff 	mov    %rax,-0x22c8(%rbp)
    16f2:	48 8d 85 38 dd ff ff 	lea    -0x22c8(%rbp),%rax
    16f9:	48 89 c7             	mov    %rax,%rdi
    16fc:	e8 00 00 00 00       	call   1701 <_ZN7KVStore12buildSSTableEv+0x85>
    1701:	48 89 85 10 dd ff ff 	mov    %rax,-0x22f0(%rbp)
    // bool isExist = utils::dirExists("");
    1708:	48 8b 85 c8 dc ff ff 	mov    -0x2338(%rbp),%rax
    170f:	48 83 c0 20          	add    $0x20,%rax
    1713:	48 89 c7             	mov    %rax,%rdi
    1716:	e8 00 00 00 00       	call   171b <_ZN7KVStore12buildSSTableEv+0x9f>
    171b:	48 98                	cltq   
    171d:	48 89 85 18 dd ff ff 	mov    %rax,-0x22e8(%rbp)
    //build ssTable
    1724:	48 8b 85 c8 dc ff ff 	mov    -0x2338(%rbp),%rax
    172b:	48 83 c0 20          	add    $0x20,%rax
    172f:	48 89 c7             	mov    %rax,%rdi
    1732:	e8 00 00 00 00       	call   1737 <_ZN7KVStore12buildSSTableEv+0xbb>
    1737:	48 98                	cltq   
    1739:	48 89 85 20 dd ff ff 	mov    %rax,-0x22e0(%rbp)

    1740:	48 8b 85 c8 dc ff ff 	mov    -0x2338(%rbp),%rax
    1747:	48 83 c0 20          	add    $0x20,%rax
    174b:	48 89 c7             	mov    %rax,%rdi
    174e:	e8 00 00 00 00       	call   1753 <_ZN7KVStore12buildSSTableEv+0xd7>
    1753:	48 98                	cltq   
    1755:	48 89 85 28 dd ff ff 	mov    %rax,-0x22d8(%rbp)
    // 获取当前时间戳
    auto now = std::chrono::system_clock::now();
    175c:	48 8d 85 e0 dd ff ff 	lea    -0x2220(%rbp),%rax
    1763:	48 8b 95 28 dd ff ff 	mov    -0x22d8(%rbp),%rdx
    176a:	48 89 d6             	mov    %rdx,%rsi
    176d:	48 89 c7             	mov    %rax,%rdi
    1770:	e8 00 00 00 00       	call   1775 <_ZN7KVStore12buildSSTableEv+0xf9>
    1775:	48 8d 85 a0 dd ff ff 	lea    -0x2260(%rbp),%rax
    177c:	48 8b 95 20 dd ff ff 	mov    -0x22e0(%rbp),%rdx
    1783:	48 89 d6             	mov    %rdx,%rsi
    1786:	48 89 c7             	mov    %rax,%rdi
    1789:	e8 00 00 00 00       	call   178e <_ZN7KVStore12buildSSTableEv+0x112>
    178e:	48 8d 85 60 dd ff ff 	lea    -0x22a0(%rbp),%rax
    1795:	48 8b 95 18 dd ff ff 	mov    -0x22e8(%rbp),%rdx
    179c:	48 89 d6             	mov    %rdx,%rsi
    179f:	48 89 c7             	mov    %rax,%rdi
    17a2:	e8 00 00 00 00       	call   17a7 <_ZN7KVStore12buildSSTableEv+0x12b>
    17a7:	48 8d 85 40 dd ff ff 	lea    -0x22c0(%rbp),%rax
    17ae:	48 8b 95 10 dd ff ff 	mov    -0x22f0(%rbp),%rdx
    17b5:	48 89 d6             	mov    %rdx,%rsi
    17b8:	48 89 c7             	mov    %rax,%rdi
    17bb:	e8 00 00 00 00       	call   17c0 <_ZN7KVStore12buildSSTableEv+0x144>
    17c0:	48 8d 85 80 dd ff ff 	lea    -0x2280(%rbp),%rax
    17c7:	48 8d 95 60 dd ff ff 	lea    -0x22a0(%rbp),%rdx
    17ce:	48 8d 8d 40 dd ff ff 	lea    -0x22c0(%rbp),%rcx
    17d5:	48 89 ce             	mov    %rcx,%rsi
    17d8:	48 89 c7             	mov    %rax,%rdi
    17db:	e8 00 00 00 00       	call   17e0 <_ZN7KVStore12buildSSTableEv+0x164>
    17e0:	48 8d 85 c0 dd ff ff 	lea    -0x2240(%rbp),%rax
    17e7:	48 8d 95 a0 dd ff ff 	lea    -0x2260(%rbp),%rdx
    17ee:	48 8d 8d 80 dd ff ff 	lea    -0x2280(%rbp),%rcx
    17f5:	48 89 ce             	mov    %rcx,%rsi
    17f8:	48 89 c7             	mov    %rax,%rdi
    17fb:	e8 00 00 00 00       	call   1800 <_ZN7KVStore12buildSSTableEv+0x184>
    1800:	48 8d 85 e0 df ff ff 	lea    -0x2020(%rbp),%rax
    1807:	48 8d 95 e0 dd ff ff 	lea    -0x2220(%rbp),%rdx
    180e:	48 8d 8d c0 dd ff ff 	lea    -0x2240(%rbp),%rcx
    1815:	48 89 ce             	mov    %rcx,%rsi
    1818:	48 89 c7             	mov    %rax,%rdi
    181b:	e8 00 00 00 00       	call   1820 <_ZN7KVStore12buildSSTableEv+0x1a4>
    1820:	48 8b 85 c8 dc ff ff 	mov    -0x2338(%rbp),%rax
    1827:	48 8d 50 40          	lea    0x40(%rax),%rdx
    182b:	48 8d 85 e0 df ff ff 	lea    -0x2020(%rbp),%rax
    1832:	48 89 c6             	mov    %rax,%rsi
    1835:	48 89 d7             	mov    %rdx,%rdi
    1838:	e8 00 00 00 00       	call   183d <_ZN7KVStore12buildSSTableEv+0x1c1>
    183d:	48 8d 85 e0 df ff ff 	lea    -0x2020(%rbp),%rax
    1844:	48 89 c7             	mov    %rax,%rdi
    1847:	e8 00 00 00 00       	call   184c <_ZN7KVStore12buildSSTableEv+0x1d0>
    184c:	48 8d 85 c0 dd ff ff 	lea    -0x2240(%rbp),%rax
    1853:	48 89 c7             	mov    %rax,%rdi
    1856:	e8 00 00 00 00       	call   185b <_ZN7KVStore12buildSSTableEv+0x1df>
    185b:	48 8d 85 80 dd ff ff 	lea    -0x2280(%rbp),%rax
    1862:	48 89 c7             	mov    %rax,%rdi
    1865:	e8 00 00 00 00       	call   186a <_ZN7KVStore12buildSSTableEv+0x1ee>
    186a:	48 8d 85 40 dd ff ff 	lea    -0x22c0(%rbp),%rax
    1871:	48 89 c7             	mov    %rax,%rdi
    1874:	e8 00 00 00 00       	call   1879 <_ZN7KVStore12buildSSTableEv+0x1fd>
    1879:	48 8d 85 60 dd ff ff 	lea    -0x22a0(%rbp),%rax
    1880:	48 89 c7             	mov    %rax,%rdi
    1883:	e8 00 00 00 00       	call   1888 <_ZN7KVStore12buildSSTableEv+0x20c>
    1888:	48 8d 85 a0 dd ff ff 	lea    -0x2260(%rbp),%rax
    188f:	48 89 c7             	mov    %rax,%rdi
    1892:	e8 00 00 00 00       	call   1897 <_ZN7KVStore12buildSSTableEv+0x21b>
    1897:	48 8d 85 e0 dd ff ff 	lea    -0x2220(%rbp),%rax
    189e:	48 89 c7             	mov    %rax,%rdi
    18a1:	e8 00 00 00 00       	call   18a6 <_ZN7KVStore12buildSSTableEv+0x22a>
    uint64_t timestamp = std::chrono::time_point_cast<std::chrono::milliseconds>(now).time_since_epoch().count();
    uint64_t num_of_key = memTable.getSize();
    18a6:	48 8b 85 c8 dc ff ff 	mov    -0x2338(%rbp),%rax
    18ad:	48 83 c0 28          	add    $0x28,%rax
    18b1:	be 00 00 00 00       	mov    $0x0,%esi
    18b6:	48 89 c7             	mov    %rax,%rdi
    18b9:	e8 00 00 00 00       	call   18be <_ZN7KVStore12buildSSTableEv+0x242>
    18be:	48 8b 00             	mov    (%rax),%rax
    18c1:	48 89 c7             	mov    %rax,%rdi
    18c4:	e8 00 00 00 00       	call   18c9 <_ZN7KVStore12buildSSTableEv+0x24d>
    18c9:	48 89 85 00 dd ff ff 	mov    %rax,-0x2300(%rbp)
    uint64_t min_key = memTable.getMinKey();
    18d0:	48 8d 95 e0 df ff ff 	lea    -0x2020(%rbp),%rdx
    18d7:	b8 00 00 00 00       	mov    $0x0,%eax
    18dc:	b9 00 04 00 00       	mov    $0x400,%ecx
    18e1:	48 89 d7             	mov    %rdx,%rdi
    18e4:	f3 48 ab             	rep stos %rax,%es:(%rdi)
    uint64_t max_key = memTable.getMaxKey();
    18e7:	e9 f2 00 00 00       	jmp    19de <_ZN7KVStore12buildSSTableEv+0x362>

    ssTable += to8Bits(timestamp) + to8Bits(num_of_key) + to8Bits(min_key) + to8Bits(max_key);
    18ec:	48 c7 85 38 dd ff ff 	movq   $0x192d2,-0x22c8(%rbp)
    18f3:	d2 92 01 00 

    18f7:	48 c7 85 e0 dd ff ff 	movq   $0x0,-0x2220(%rbp)
    18fe:	00 00 00 00 
    1902:	48 c7 85 e8 dd ff ff 	movq   $0x0,-0x2218(%rbp)
    1909:	00 00 00 00 
    auto node = this->memTable.list[0]->frist();
    190d:	48 8d 95 e0 dd ff ff 	lea    -0x2220(%rbp),%rdx
    1914:	48 8d 85 38 dd ff ff 	lea    -0x22c8(%rbp),%rax
    191b:	48 89 d1             	mov    %rdx,%rcx
    191e:	ba 01 00 00 00       	mov    $0x1,%edx
    1923:	be 08 00 00 00       	mov    $0x8,%esi
    1928:	48 89 c7             	mov    %rax,%rdi
    192b:	e8 f7 e6 ff ff       	call   27 <_ZL19MurmurHash3_x64_128PKvijPv>
    unsigned int vec[2048] = {0};
    1930:	c7 85 d8 dc ff ff 00 	movl   $0x0,-0x2328(%rbp)
    1937:	00 00 00 
    193a:	e9 80 00 00 00       	jmp    19bf <_ZN7KVStore12buildSSTableEv+0x343>
    while(node != nullptr)
    {
    193f:	8b 85 d8 dc ff ff    	mov    -0x2328(%rbp),%eax
    1945:	48 98                	cltq   
    1947:	8b 84 85 e0 dd ff ff 	mov    -0x2220(%rbp,%rax,4),%eax
    194e:	25 ff ff 00 00       	and    $0xffff,%eax
    1953:	89 85 e4 dc ff ff    	mov    %eax,-0x231c(%rbp)
        long long key = 103122;
    1959:	8b 85 e4 dc ff ff    	mov    -0x231c(%rbp),%eax
    195f:	8d 50 1f             	lea    0x1f(%rax),%edx
    1962:	85 c0                	test   %eax,%eax
    1964:	0f 48 c2             	cmovs  %edx,%eax
    1967:	c1 f8 05             	sar    $0x5,%eax
    196a:	89 85 e8 dc ff ff    	mov    %eax,-0x2318(%rbp)
        unsigned int hash[4] = {0};
    1970:	8b 85 e4 dc ff ff    	mov    -0x231c(%rbp),%eax
    1976:	99                   	cltd   
    1977:	c1 ea 1b             	shr    $0x1b,%edx
    197a:	01 d0                	add    %edx,%eax
    197c:	83 e0 1f             	and    $0x1f,%eax
    197f:	29 d0                	sub    %edx,%eax
    1981:	89 85 ec dc ff ff    	mov    %eax,-0x2314(%rbp)
        MurmurHash3_x64_128(&key, sizeof(key), 1, hash);
    1987:	8b 85 e8 dc ff ff    	mov    -0x2318(%rbp),%eax
    198d:	48 98                	cltq   
    198f:	8b 94 85 e0 df ff ff 	mov    -0x2020(%rbp,%rax,4),%edx
    1996:	8b 85 ec dc ff ff    	mov    -0x2314(%rbp),%eax
    199c:	be 01 00 00 00       	mov    $0x1,%esi
    19a1:	89 c1                	mov    %eax,%ecx
    19a3:	d3 e6                	shl    %cl,%esi
    19a5:	89 f0                	mov    %esi,%eax
    19a7:	09 c2                	or     %eax,%edx
    19a9:	8b 85 e8 dc ff ff    	mov    -0x2318(%rbp),%eax
    19af:	48 98                	cltq   
    19b1:	89 94 85 e0 df ff ff 	mov    %edx,-0x2020(%rbp,%rax,4)
    unsigned int vec[2048] = {0};
    19b8:	83 85 d8 dc ff ff 01 	addl   $0x1,-0x2328(%rbp)
    19bf:	83 bd d8 dc ff ff 03 	cmpl   $0x3,-0x2328(%rbp)
    19c6:	0f 8e 73 ff ff ff    	jle    193f <_ZN7KVStore12buildSSTableEv+0x2c3>
        for(int i = 0 ; i < 4 ; i++)
        {
    19cc:	48 8b 85 00 dd ff ff 	mov    -0x2300(%rbp),%rax
    19d3:	48 8b 40 30          	mov    0x30(%rax),%rax
    19d7:	48 89 85 00 dd ff ff 	mov    %rax,-0x2300(%rbp)
    uint64_t max_key = memTable.getMaxKey();
    19de:	48 83 bd 00 dd ff ff 	cmpq   $0x0,-0x2300(%rbp)
    19e5:	00 
    19e6:	0f 85 00 ff ff ff    	jne    18ec <_ZN7KVStore12buildSSTableEv+0x270>
            int val = hash[i] % 65536 ;
            int k = val / 32;
    19ec:	c7 85 dc dc ff ff 00 	movl   $0x0,-0x2324(%rbp)
    19f3:	00 00 00 
    19f6:	eb 53                	jmp    1a4b <_ZN7KVStore12buildSSTableEv+0x3cf>
            int j = val % 32;
    19f8:	8b 85 dc dc ff ff    	mov    -0x2324(%rbp),%eax
    19fe:	48 98                	cltq   
    1a00:	8b 94 85 e0 df ff ff 	mov    -0x2020(%rbp,%rax,4),%edx
    1a07:	48 8d 85 e0 dd ff ff 	lea    -0x2220(%rbp),%rax
    1a0e:	89 d6                	mov    %edx,%esi
    1a10:	48 89 c7             	mov    %rax,%rdi
    1a13:	e8 00 00 00 00       	call   1a18 <_ZN7KVStore12buildSSTableEv+0x39c>
    1a18:	48 8b 85 c8 dc ff ff 	mov    -0x2338(%rbp),%rax
    1a1f:	48 8d 50 40          	lea    0x40(%rax),%rdx
    1a23:	48 8d 85 e0 dd ff ff 	lea    -0x2220(%rbp),%rax
    1a2a:	48 89 c6             	mov    %rax,%rsi
    1a2d:	48 89 d7             	mov    %rdx,%rdi
    1a30:	e8 00 00 00 00       	call   1a35 <_ZN7KVStore12buildSSTableEv+0x3b9>
    1a35:	48 8d 85 e0 dd ff ff 	lea    -0x2220(%rbp),%rax
    1a3c:	48 89 c7             	mov    %rax,%rdi
    1a3f:	e8 00 00 00 00       	call   1a44 <_ZN7KVStore12buildSSTableEv+0x3c8>
            int k = val / 32;
    1a44:	83 85 dc dc ff ff 01 	addl   $0x1,-0x2324(%rbp)
    1a4b:	81 bd dc dc ff ff ff 	cmpl   $0x7ff,-0x2324(%rbp)
    1a52:	07 00 00 
    1a55:	7e a1                	jle    19f8 <_ZN7KVStore12buildSSTableEv+0x37c>
            vec[k] |= (1 << j);
        }
        node = node->succ;
    1a57:	48 c7 85 08 dd ff ff 	movq   $0x0,-0x22f8(%rbp)
    1a5e:	00 00 00 00 
    }
    1a62:	48 c7 85 30 dd ff ff 	movq   $0x0,-0x22d0(%rbp)
    1a69:	00 00 00 00 
    for(int i = 0 ; i < 2048 ; i++)
    1a6d:	c7 85 e0 dc ff ff 00 	movl   $0x0,-0x2320(%rbp)
    1a74:	00 00 00 
        ssTable += to4Bits(vec[i]);
    1a77:	e9 f9 00 00 00       	jmp    1b75 <_ZN7KVStore12buildSSTableEv+0x4f9>
    

    1a7c:	48 8d 85 c0 dd ff ff 	lea    -0x2240(%rbp),%rax
    1a83:	8b 95 e0 dc ff ff    	mov    -0x2320(%rbp),%edx
    1a89:	89 d6                	mov    %edx,%esi
    1a8b:	48 89 c7             	mov    %rax,%rdi
    1a8e:	e8 00 00 00 00       	call   1a93 <_ZN7KVStore12buildSSTableEv+0x417>
    1a93:	48 8d 85 80 dd ff ff 	lea    -0x2280(%rbp),%rax
    1a9a:	48 8b 95 30 dd ff ff 	mov    -0x22d0(%rbp),%rdx
    1aa1:	48 89 d6             	mov    %rdx,%rsi
    1aa4:	48 89 c7             	mov    %rax,%rdi
    1aa7:	e8 00 00 00 00       	call   1aac <_ZN7KVStore12buildSSTableEv+0x430>
    1aac:	48 8d 85 60 dd ff ff 	lea    -0x22a0(%rbp),%rax
    1ab3:	48 8b 95 08 dd ff ff 	mov    -0x22f8(%rbp),%rdx
    1aba:	48 89 d6             	mov    %rdx,%rsi
    1abd:	48 89 c7             	mov    %rax,%rdi
    1ac0:	e8 00 00 00 00       	call   1ac5 <_ZN7KVStore12buildSSTableEv+0x449>
    1ac5:	48 8d 85 a0 dd ff ff 	lea    -0x2260(%rbp),%rax
    1acc:	48 8d 95 80 dd ff ff 	lea    -0x2280(%rbp),%rdx
    1ad3:	48 8d 8d 60 dd ff ff 	lea    -0x22a0(%rbp),%rcx
    1ada:	48 89 ce             	mov    %rcx,%rsi
    1add:	48 89 c7             	mov    %rax,%rdi
    1ae0:	e8 00 00 00 00       	call   1ae5 <_ZN7KVStore12buildSSTableEv+0x469>
    1ae5:	48 8d 85 e0 dd ff ff 	lea    -0x2220(%rbp),%rax
    1aec:	48 8d 95 c0 dd ff ff 	lea    -0x2240(%rbp),%rdx
    1af3:	48 8d 8d a0 dd ff ff 	lea    -0x2260(%rbp),%rcx
    1afa:	48 89 ce             	mov    %rcx,%rsi
    1afd:	48 89 c7             	mov    %rax,%rdi
    1b00:	e8 00 00 00 00       	call   1b05 <_ZN7KVStore12buildSSTableEv+0x489>
    1b05:	48 8b 85 c8 dc ff ff 	mov    -0x2338(%rbp),%rax
    1b0c:	48 8d 50 40          	lea    0x40(%rax),%rdx
    1b10:	48 8d 85 e0 dd ff ff 	lea    -0x2220(%rbp),%rax
    1b17:	48 89 c6             	mov    %rax,%rsi
    1b1a:	48 89 d7             	mov    %rdx,%rdi
    1b1d:	e8 00 00 00 00       	call   1b22 <_ZN7KVStore12buildSSTableEv+0x4a6>
    1b22:	48 8d 85 e0 dd ff ff 	lea    -0x2220(%rbp),%rax
    1b29:	48 89 c7             	mov    %rax,%rdi
    1b2c:	e8 00 00 00 00       	call   1b31 <_ZN7KVStore12buildSSTableEv+0x4b5>
    1b31:	48 8d 85 a0 dd ff ff 	lea    -0x2260(%rbp),%rax
    1b38:	48 89 c7             	mov    %rax,%rdi
    1b3b:	e8 00 00 00 00       	call   1b40 <_ZN7KVStore12buildSSTableEv+0x4c4>
    1b40:	48 8d 85 60 dd ff ff 	lea    -0x22a0(%rbp),%rax
    1b47:	48 89 c7             	mov    %rax,%rdi
    1b4a:	e8 00 00 00 00       	call   1b4f <_ZN7KVStore12buildSSTableEv+0x4d3>
    1b4f:	48 8d 85 80 dd ff ff 	lea    -0x2280(%rbp),%rax
    1b56:	48 89 c7             	mov    %rax,%rdi
    1b59:	e8 00 00 00 00       	call   1b5e <_ZN7KVStore12buildSSTableEv+0x4e2>
    1b5e:	48 8d 85 c0 dd ff ff 	lea    -0x2240(%rbp),%rax
    1b65:	48 89 c7             	mov    %rax,%rdi
    1b68:	e8 00 00 00 00       	call   1b6d <_ZN7KVStore12buildSSTableEv+0x4f1>
    uint64_t current_key = 0;
    1b6d:	48 83 85 08 dd ff ff 	addq   $0x1,-0x22f8(%rbp)
    1b74:	01 
        ssTable += to4Bits(vec[i]);
    1b75:	48 8b 85 c8 dc ff ff 	mov    -0x2338(%rbp),%rax
    1b7c:	48 83 c0 40          	add    $0x40,%rax
    1b80:	48 89 c7             	mov    %rax,%rdi
    1b83:	e8 00 00 00 00       	call   1b88 <_ZN7KVStore12buildSSTableEv+0x50c>
    1b88:	48 83 c0 14          	add    $0x14,%rax
    1b8c:	48 3d 00 40 00 00    	cmp    $0x4000,%rax
    1b92:	0f 96 c0             	setbe  %al
    1b95:	84 c0                	test   %al,%al
    1b97:	0f 85 df fe ff ff    	jne    1a7c <_ZN7KVStore12buildSSTableEv+0x400>
    uint64_t offset = 0;
    unsigned int vlen = 0;
    1b9d:	48 8b 85 c8 dc ff ff 	mov    -0x2338(%rbp),%rax
    1ba4:	48 83 c0 40          	add    $0x40,%rax
    1ba8:	48 89 c7             	mov    %rax,%rdi
    1bab:	e8 00 00 00 00       	call   1bb0 <_ZN7KVStore12buildSSTableEv+0x534>
    1bb0:	48 89 c6             	mov    %rax,%rsi
    1bb3:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 1bba <_ZN7KVStore12buildSSTableEv+0x53e>
    1bba:	48 89 c7             	mov    %rax,%rdi
    1bbd:	e8 00 00 00 00       	call   1bc2 <_ZN7KVStore12buildSSTableEv+0x546>
    1bc2:	48 8b 15 00 00 00 00 	mov    0x0(%rip),%rdx        # 1bc9 <_ZN7KVStore12buildSSTableEv+0x54d>
    1bc9:	48 89 d6             	mov    %rdx,%rsi
    1bcc:	48 89 c7             	mov    %rax,%rdi
    1bcf:	e8 00 00 00 00       	call   1bd4 <_ZN7KVStore12buildSSTableEv+0x558>
    while( ssTable.length() + 20 <= 16 * 1024)
    1bd4:	48 8b 85 08 dd ff ff 	mov    -0x22f8(%rbp),%rax
    1bdb:	48 89 c6             	mov    %rax,%rsi
    1bde:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 1be5 <_ZN7KVStore12buildSSTableEv+0x569>
    1be5:	48 89 c7             	mov    %rax,%rdi
    1be8:	e8 00 00 00 00       	call   1bed <_ZN7KVStore12buildSSTableEv+0x571>
    {
        ssTable += to8Bits(current_key) + to8Bits(offset) + to4Bits(vlen);
    1bed:	48 8d 85 80 dd ff ff 	lea    -0x2280(%rbp),%rax
    1bf4:	48 89 c7             	mov    %rax,%rdi
    1bf7:	e8 00 00 00 00       	call   1bfc <_ZN7KVStore12buildSSTableEv+0x580>
        current_key++;
    1bfc:	48 8b 85 c8 dc ff ff 	mov    -0x2338(%rbp),%rax
    1c03:	48 83 c0 08          	add    $0x8,%rax
    1c07:	48 89 c7             	mov    %rax,%rdi
    1c0a:	e8 00 00 00 00       	call   1c0f <_ZN7KVStore12buildSSTableEv+0x593>
    1c0f:	48 85 c0             	test   %rax,%rax
    1c12:	0f 94 c0             	sete   %al
    1c15:	84 c0                	test   %al,%al
    1c17:	0f 84 87 00 00 00    	je     1ca4 <_ZN7KVStore12buildSSTableEv+0x628>
    }
    std::cout << ssTable.length() << std::endl;
    std::cout << current_key;
    1c1d:	c7 85 3c dd ff ff 00 	movl   $0x0,-0x22c4(%rbp)
    1c24:	00 00 00 

    1c27:	c7 85 38 dd ff ff 00 	movl   $0x0,-0x22c8(%rbp)
    1c2e:	00 00 00 
    std::string fileName ;
    1c31:	48 8b 85 c8 dc ff ff 	mov    -0x2338(%rbp),%rax
    1c38:	48 8d 50 08          	lea    0x8(%rax),%rdx
    1c3c:	48 8d 85 38 dd ff ff 	lea    -0x22c8(%rbp),%rax
    1c43:	48 89 c6             	mov    %rax,%rsi
    1c46:	48 89 d7             	mov    %rdx,%rdi
    1c49:	e8 00 00 00 00       	call   1c4e <_ZN7KVStore12buildSSTableEv+0x5d2>
    if(this->sslevel.size() == 0)
    1c4e:	48 8b 85 c8 dc ff ff 	mov    -0x2338(%rbp),%rax
    1c55:	48 8d 88 80 00 00 00 	lea    0x80(%rax),%rcx
    1c5c:	48 8d 85 e0 dd ff ff 	lea    -0x2220(%rbp),%rax
    1c63:	48 8d 15 00 00 00 00 	lea    0x0(%rip),%rdx        # 1c6a <_ZN7KVStore12buildSSTableEv+0x5ee>
    1c6a:	48 89 ce             	mov    %rcx,%rsi
    1c6d:	48 89 c7             	mov    %rax,%rdi
    1c70:	e8 00 00 00 00       	call   1c75 <_ZN7KVStore12buildSSTableEv+0x5f9>
    1c75:	48 8d 85 e0 dd ff ff 	lea    -0x2220(%rbp),%rax
    1c7c:	48 89 c7             	mov    %rax,%rdi
    1c7f:	e8 7c e3 ff ff       	call   0 <_ZN5utilsL6_mkdirERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE>
    1c84:	89 c6                	mov    %eax,%esi
    1c86:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 1c8d <_ZN7KVStore12buildSSTableEv+0x611>
    1c8d:	48 89 c7             	mov    %rax,%rdi
    1c90:	e8 00 00 00 00       	call   1c95 <_ZN7KVStore12buildSSTableEv+0x619>
    1c95:	48 8d 85 e0 dd ff ff 	lea    -0x2220(%rbp),%rax
    1c9c:	48 89 c7             	mov    %rax,%rdi
    1c9f:	e8 00 00 00 00       	call   1ca4 <_ZN7KVStore12buildSSTableEv+0x628>
    {
        ssLevel s0;
    1ca4:	48 8b 85 c8 dc ff ff 	mov    -0x2338(%rbp),%rax
    1cab:	48 83 c0 08          	add    $0x8,%rax
    1caf:	be 00 00 00 00       	mov    $0x0,%esi
    1cb4:	48 89 c7             	mov    %rax,%rdi
    1cb7:	e8 00 00 00 00       	call   1cbc <_ZN7KVStore12buildSSTableEv+0x640>
    1cbc:	8b 50 04             	mov    0x4(%rax),%edx
    1cbf:	83 c2 01             	add    $0x1,%edx
    1cc2:	89 50 04             	mov    %edx,0x4(%rax)
        s0.currentNum = 0;
    1cc5:	48 8b 85 c8 dc ff ff 	mov    -0x2338(%rbp),%rax
    1ccc:	48 83 c0 08          	add    $0x8,%rax
    1cd0:	be 00 00 00 00       	mov    $0x0,%esi
    1cd5:	48 89 c7             	mov    %rax,%rdi
    1cd8:	e8 00 00 00 00       	call   1cdd <_ZN7KVStore12buildSSTableEv+0x661>
    1cdd:	8b 50 04             	mov    0x4(%rax),%edx
    1ce0:	48 8d 85 e0 dd ff ff 	lea    -0x2220(%rbp),%rax
    1ce7:	89 d6                	mov    %edx,%esi
    1ce9:	48 89 c7             	mov    %rax,%rdi
    1cec:	e8 00 00 00 00       	call   1cf1 <_ZN7KVStore12buildSSTableEv+0x675>
    1cf1:	48 8b 85 c8 dc ff ff 	mov    -0x2338(%rbp),%rax
    1cf8:	48 8d 88 80 00 00 00 	lea    0x80(%rax),%rcx
    1cff:	48 8d 85 a0 dd ff ff 	lea    -0x2260(%rbp),%rax
    1d06:	48 8d 15 00 00 00 00 	lea    0x0(%rip),%rdx        # 1d0d <_ZN7KVStore12buildSSTableEv+0x691>
    1d0d:	48 89 ce             	mov    %rcx,%rsi
    1d10:	48 89 c7             	mov    %rax,%rdi
    1d13:	e8 00 00 00 00       	call   1d18 <_ZN7KVStore12buildSSTableEv+0x69c>
    1d18:	48 8d 85 c0 dd ff ff 	lea    -0x2240(%rbp),%rax
    1d1f:	48 8d 95 e0 dd ff ff 	lea    -0x2220(%rbp),%rdx
    1d26:	48 8d 8d a0 dd ff ff 	lea    -0x2260(%rbp),%rcx
    1d2d:	48 89 ce             	mov    %rcx,%rsi
    1d30:	48 89 c7             	mov    %rax,%rdi
    1d33:	e8 00 00 00 00       	call   1d38 <_ZN7KVStore12buildSSTableEv+0x6bc>
    1d38:	48 8d 95 c0 dd ff ff 	lea    -0x2240(%rbp),%rdx
    1d3f:	48 8d 85 80 dd ff ff 	lea    -0x2280(%rbp),%rax
    1d46:	48 89 d6             	mov    %rdx,%rsi
    1d49:	48 89 c7             	mov    %rax,%rdi
    1d4c:	e8 00 00 00 00       	call   1d51 <_ZN7KVStore12buildSSTableEv+0x6d5>
    1d51:	48 8d 85 c0 dd ff ff 	lea    -0x2240(%rbp),%rax
    1d58:	48 89 c7             	mov    %rax,%rdi
    1d5b:	e8 00 00 00 00       	call   1d60 <_ZN7KVStore12buildSSTableEv+0x6e4>
    1d60:	48 8d 85 a0 dd ff ff 	lea    -0x2260(%rbp),%rax
    1d67:	48 89 c7             	mov    %rax,%rdi
    1d6a:	e8 00 00 00 00       	call   1d6f <_ZN7KVStore12buildSSTableEv+0x6f3>
    1d6f:	48 8d 85 e0 dd ff ff 	lea    -0x2220(%rbp),%rax
    1d76:	48 89 c7             	mov    %rax,%rdi
    1d79:	e8 00 00 00 00       	call   1d7e <_ZN7KVStore12buildSSTableEv+0x702>
        s0.level = 0;
        sslevel.push_back(s0);
    1d7e:	48 8d 8d 80 dd ff ff 	lea    -0x2280(%rbp),%rcx
    1d85:	48 8d 85 e0 dd ff ff 	lea    -0x2220(%rbp),%rax
    1d8c:	ba 10 00 00 00       	mov    $0x10,%edx
    1d91:	48 89 ce             	mov    %rcx,%rsi
    1d94:	48 89 c7             	mov    %rax,%rdi
    1d97:	e8 00 00 00 00       	call   1d9c <_ZN7KVStore12buildSSTableEv+0x720>
        std::cout << utils::_mkdir( vlogDir + "/Level0" );
    1d9c:	48 8d 85 e0 dd ff ff 	lea    -0x2220(%rbp),%rax
    1da3:	48 89 c7             	mov    %rax,%rdi
    1da6:	e8 00 00 00 00       	call   1dab <_ZN7KVStore12buildSSTableEv+0x72f>
    1dab:	0f b6 c0             	movzbl %al,%eax
    1dae:	89 c6                	mov    %eax,%esi
    1db0:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 1db7 <_ZN7KVStore12buildSSTableEv+0x73b>
    1db7:	48 89 c7             	mov    %rax,%rdi
    1dba:	e8 00 00 00 00       	call   1dbf <_ZN7KVStore12buildSSTableEv+0x743>
    }
    1dbf:	48 8b 85 c8 dc ff ff 	mov    -0x2338(%rbp),%rax
    1dc6:	48 8d 50 40          	lea    0x40(%rax),%rdx
    1dca:	48 8d 85 e0 dd ff ff 	lea    -0x2220(%rbp),%rax
    1dd1:	48 89 d6             	mov    %rdx,%rsi
    1dd4:	48 89 c7             	mov    %rax,%rdi
    1dd7:	e8 00 00 00 00       	call   1ddc <_ZN7KVStore12buildSSTableEv+0x760>
    sslevel[0].currentNum ++;
    1ddc:	48 8d 85 e0 dd ff ff 	lea    -0x2220(%rbp),%rax
    1de3:	48 89 c7             	mov    %rax,%rdi
    1de6:	e8 00 00 00 00       	call   1deb <_ZN7KVStore12buildSSTableEv+0x76f>
    fileName = vlogDir + "/Level0/ssTable" + std::to_string(sslevel[0].currentNum );

    1deb:	48 8b 85 c8 dc ff ff 	mov    -0x2338(%rbp),%rax
    1df2:	48 83 c0 08          	add    $0x8,%rax
    1df6:	be 00 00 00 00       	mov    $0x0,%esi
    1dfb:	48 89 c7             	mov    %rax,%rdi
    1dfe:	e8 00 00 00 00       	call   1e03 <_ZN7KVStore12buildSSTableEv+0x787>
    1e03:	8b 40 04             	mov    0x4(%rax),%eax
    1e06:	83 f8 02             	cmp    $0x2,%eax
    1e09:	0f 9f c0             	setg   %al
    1e0c:	84 c0                	test   %al,%al
    1e0e:	74 0f                	je     1e1f <_ZN7KVStore12buildSSTableEv+0x7a3>
    std::ofstream file(fileName);
    std::cout << file.is_open();
    file << ssTable;
    1e10:	48 8b 85 c8 dc ff ff 	mov    -0x2338(%rbp),%rax
    1e17:	48 89 c7             	mov    %rax,%rdi
    1e1a:	e8 00 00 00 00       	call   1e1f <_ZN7KVStore12buildSSTableEv+0x7a3>
    file.close();
    // TODO: Your code here
    1e1f:	48 8d 85 e0 dd ff ff 	lea    -0x2220(%rbp),%rax
    1e26:	48 89 c7             	mov    %rax,%rdi
    1e29:	e8 00 00 00 00       	call   1e2e <_ZN7KVStore12buildSSTableEv+0x7b2>
    1e2e:	48 8d 85 80 dd ff ff 	lea    -0x2280(%rbp),%rax
    1e35:	48 89 c7             	mov    %rax,%rdi
    1e38:	e8 00 00 00 00       	call   1e3d <_ZN7KVStore12buildSSTableEv+0x7c1>
    1e3d:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1e41:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    1e48:	00 00 
    1e4a:	0f 84 de 01 00 00    	je     202e <_ZN7KVStore12buildSSTableEv+0x9b2>
    1e50:	e9 d4 01 00 00       	jmp    2029 <_ZN7KVStore12buildSSTableEv+0x9ad>
    1e55:	f3 0f 1e fa          	endbr64 
    auto now = std::chrono::system_clock::now();
    1e59:	48 89 c3             	mov    %rax,%rbx
    1e5c:	48 8d 85 e0 df ff ff 	lea    -0x2020(%rbp),%rax
    1e63:	48 89 c7             	mov    %rax,%rdi
    1e66:	e8 00 00 00 00       	call   1e6b <_ZN7KVStore12buildSSTableEv+0x7ef>
    1e6b:	eb 07                	jmp    1e74 <_ZN7KVStore12buildSSTableEv+0x7f8>
    1e6d:	f3 0f 1e fa          	endbr64 
    1e71:	48 89 c3             	mov    %rax,%rbx
    1e74:	48 8d 85 c0 dd ff ff 	lea    -0x2240(%rbp),%rax
    1e7b:	48 89 c7             	mov    %rax,%rdi
    1e7e:	e8 00 00 00 00       	call   1e83 <_ZN7KVStore12buildSSTableEv+0x807>
    1e83:	eb 07                	jmp    1e8c <_ZN7KVStore12buildSSTableEv+0x810>
    1e85:	f3 0f 1e fa          	endbr64 
    1e89:	48 89 c3             	mov    %rax,%rbx
    1e8c:	48 8d 85 80 dd ff ff 	lea    -0x2280(%rbp),%rax
    1e93:	48 89 c7             	mov    %rax,%rdi
    1e96:	e8 00 00 00 00       	call   1e9b <_ZN7KVStore12buildSSTableEv+0x81f>
    1e9b:	eb 07                	jmp    1ea4 <_ZN7KVStore12buildSSTableEv+0x828>
    1e9d:	f3 0f 1e fa          	endbr64 
    1ea1:	48 89 c3             	mov    %rax,%rbx
    1ea4:	48 8d 85 40 dd ff ff 	lea    -0x22c0(%rbp),%rax
    1eab:	48 89 c7             	mov    %rax,%rdi
    1eae:	e8 00 00 00 00       	call   1eb3 <_ZN7KVStore12buildSSTableEv+0x837>
    1eb3:	eb 07                	jmp    1ebc <_ZN7KVStore12buildSSTableEv+0x840>
    1eb5:	f3 0f 1e fa          	endbr64 
    1eb9:	48 89 c3             	mov    %rax,%rbx
    1ebc:	48 8d 85 60 dd ff ff 	lea    -0x22a0(%rbp),%rax
    1ec3:	48 89 c7             	mov    %rax,%rdi
    1ec6:	e8 00 00 00 00       	call   1ecb <_ZN7KVStore12buildSSTableEv+0x84f>
    1ecb:	eb 07                	jmp    1ed4 <_ZN7KVStore12buildSSTableEv+0x858>
    1ecd:	f3 0f 1e fa          	endbr64 
    1ed1:	48 89 c3             	mov    %rax,%rbx
    1ed4:	48 8d 85 a0 dd ff ff 	lea    -0x2260(%rbp),%rax
    1edb:	48 89 c7             	mov    %rax,%rdi
    1ede:	e8 00 00 00 00       	call   1ee3 <_ZN7KVStore12buildSSTableEv+0x867>
    1ee3:	eb 07                	jmp    1eec <_ZN7KVStore12buildSSTableEv+0x870>
    1ee5:	f3 0f 1e fa          	endbr64 
    1ee9:	48 89 c3             	mov    %rax,%rbx
    1eec:	48 8d 85 e0 dd ff ff 	lea    -0x2220(%rbp),%rax
    1ef3:	48 89 c7             	mov    %rax,%rdi
    1ef6:	e8 00 00 00 00       	call   1efb <_ZN7KVStore12buildSSTableEv+0x87f>
    1efb:	48 89 d8             	mov    %rbx,%rax
    1efe:	48 89 c7             	mov    %rax,%rdi
    1f01:	e8 00 00 00 00       	call   1f06 <_ZN7KVStore12buildSSTableEv+0x88a>
    1f06:	f3 0f 1e fa          	endbr64 
            int j = val % 32;
    1f0a:	48 89 c3             	mov    %rax,%rbx
    1f0d:	48 8d 85 e0 dd ff ff 	lea    -0x2220(%rbp),%rax
    1f14:	48 89 c7             	mov    %rax,%rdi
    1f17:	e8 00 00 00 00       	call   1f1c <_ZN7KVStore12buildSSTableEv+0x8a0>
    1f1c:	48 89 d8             	mov    %rbx,%rax
    1f1f:	48 89 c7             	mov    %rax,%rdi
    1f22:	e8 00 00 00 00       	call   1f27 <_ZN7KVStore12buildSSTableEv+0x8ab>
    1f27:	f3 0f 1e fa          	endbr64 

    1f2b:	48 89 c3             	mov    %rax,%rbx
    1f2e:	48 8d 85 e0 dd ff ff 	lea    -0x2220(%rbp),%rax
    1f35:	48 89 c7             	mov    %rax,%rdi
    1f38:	e8 00 00 00 00       	call   1f3d <_ZN7KVStore12buildSSTableEv+0x8c1>
    1f3d:	eb 07                	jmp    1f46 <_ZN7KVStore12buildSSTableEv+0x8ca>
    1f3f:	f3 0f 1e fa          	endbr64 
    1f43:	48 89 c3             	mov    %rax,%rbx
    1f46:	48 8d 85 a0 dd ff ff 	lea    -0x2260(%rbp),%rax
    1f4d:	48 89 c7             	mov    %rax,%rdi
    1f50:	e8 00 00 00 00       	call   1f55 <_ZN7KVStore12buildSSTableEv+0x8d9>
    1f55:	eb 07                	jmp    1f5e <_ZN7KVStore12buildSSTableEv+0x8e2>
    1f57:	f3 0f 1e fa          	endbr64 
    1f5b:	48 89 c3             	mov    %rax,%rbx
    1f5e:	48 8d 85 60 dd ff ff 	lea    -0x22a0(%rbp),%rax
    1f65:	48 89 c7             	mov    %rax,%rdi
    1f68:	e8 00 00 00 00       	call   1f6d <_ZN7KVStore12buildSSTableEv+0x8f1>
    1f6d:	eb 07                	jmp    1f76 <_ZN7KVStore12buildSSTableEv+0x8fa>
    1f6f:	f3 0f 1e fa          	endbr64 
    1f73:	48 89 c3             	mov    %rax,%rbx
    1f76:	48 8d 85 80 dd ff ff 	lea    -0x2280(%rbp),%rax
    1f7d:	48 89 c7             	mov    %rax,%rdi
    1f80:	e8 00 00 00 00       	call   1f85 <_ZN7KVStore12buildSSTableEv+0x909>
    1f85:	eb 07                	jmp    1f8e <_ZN7KVStore12buildSSTableEv+0x912>
    1f87:	f3 0f 1e fa          	endbr64 
    1f8b:	48 89 c3             	mov    %rax,%rbx
    1f8e:	48 8d 85 c0 dd ff ff 	lea    -0x2240(%rbp),%rax
    1f95:	48 89 c7             	mov    %rax,%rdi
    1f98:	e8 00 00 00 00       	call   1f9d <_ZN7KVStore12buildSSTableEv+0x921>
    1f9d:	48 89 d8             	mov    %rbx,%rax
    1fa0:	48 89 c7             	mov    %rax,%rdi
    1fa3:	e8 00 00 00 00       	call   1fa8 <_ZN7KVStore12buildSSTableEv+0x92c>
    1fa8:	f3 0f 1e fa          	endbr64 
    if(this->sslevel.size() == 0)
    1fac:	48 89 c3             	mov    %rax,%rbx
    1faf:	48 8d 85 e0 dd ff ff 	lea    -0x2220(%rbp),%rax
    1fb6:	48 89 c7             	mov    %rax,%rdi
    1fb9:	e8 00 00 00 00       	call   1fbe <_ZN7KVStore12buildSSTableEv+0x942>
    1fbe:	eb 4f                	jmp    200f <_ZN7KVStore12buildSSTableEv+0x993>
    1fc0:	f3 0f 1e fa          	endbr64 
        s0.currentNum = 0;
    1fc4:	48 89 c3             	mov    %rax,%rbx
    1fc7:	48 8d 85 a0 dd ff ff 	lea    -0x2260(%rbp),%rax
    1fce:	48 89 c7             	mov    %rax,%rdi
    1fd1:	e8 00 00 00 00       	call   1fd6 <_ZN7KVStore12buildSSTableEv+0x95a>
    1fd6:	eb 07                	jmp    1fdf <_ZN7KVStore12buildSSTableEv+0x963>
    1fd8:	f3 0f 1e fa          	endbr64 
    1fdc:	48 89 c3             	mov    %rax,%rbx
    1fdf:	48 8d 85 e0 dd ff ff 	lea    -0x2220(%rbp),%rax
    1fe6:	48 89 c7             	mov    %rax,%rdi
    1fe9:	e8 00 00 00 00       	call   1fee <_ZN7KVStore12buildSSTableEv+0x972>
    1fee:	eb 1f                	jmp    200f <_ZN7KVStore12buildSSTableEv+0x993>
    1ff0:	f3 0f 1e fa          	endbr64 
    // TODO: Your code here
    1ff4:	48 89 c3             	mov    %rax,%rbx
    1ff7:	48 8d 85 e0 dd ff ff 	lea    -0x2220(%rbp),%rax
    1ffe:	48 89 c7             	mov    %rax,%rdi
    2001:	e8 00 00 00 00       	call   2006 <_ZN7KVStore12buildSSTableEv+0x98a>
    2006:	eb 07                	jmp    200f <_ZN7KVStore12buildSSTableEv+0x993>
    2008:	f3 0f 1e fa          	endbr64 
    200c:	48 89 c3             	mov    %rax,%rbx
    200f:	48 8d 85 80 dd ff ff 	lea    -0x2280(%rbp),%rax
    2016:	48 89 c7             	mov    %rax,%rdi
    2019:	e8 00 00 00 00       	call   201e <_ZN7KVStore12buildSSTableEv+0x9a2>
    201e:	48 89 d8             	mov    %rbx,%rax
    2021:	48 89 c7             	mov    %rax,%rdi
    2024:	e8 00 00 00 00       	call   2029 <_ZN7KVStore12buildSSTableEv+0x9ad>
    2029:	e8 00 00 00 00       	call   202e <_ZN7KVStore12buildSSTableEv+0x9b2>
    202e:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
    2032:	c9                   	leave  
    2033:	c3                   	ret    

0000000000002034 <_ZN7KVStore17SSTableCOmpactionEv>:
    if(sslevel[0].currentNum >= 3)
    {
        //compaction
    2034:	f3 0f 1e fa          	endbr64 
    2038:	55                   	push   %rbp
    2039:	48 89 e5             	mov    %rsp,%rbp
    203c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
        SSTableCOmpaction();
    }
    2040:	90                   	nop
    2041:	5d                   	pop    %rbp
    2042:	c3                   	ret    

0000000000002043 <_Z41__static_initialization_and_destruction_0ii>:
    2043:	f3 0f 1e fa          	endbr64 
    2047:	55                   	push   %rbp
    2048:	48 89 e5             	mov    %rsp,%rbp
    204b:	48 83 ec 10          	sub    $0x10,%rsp
    204f:	89 7d fc             	mov    %edi,-0x4(%rbp)
    2052:	89 75 f8             	mov    %esi,-0x8(%rbp)
    2055:	83 7d fc 01          	cmpl   $0x1,-0x4(%rbp)
    2059:	75 3b                	jne    2096 <_Z41__static_initialization_and_destruction_0ii+0x53>
    205b:	81 7d f8 ff ff 00 00 	cmpl   $0xffff,-0x8(%rbp)
    2062:	75 32                	jne    2096 <_Z41__static_initialization_and_destruction_0ii+0x53>
  extern wostream wclog;	/// Linked to standard error (buffered)
#endif
  ///@}

  // For construction of filebuffers for cout, cin, cerr, clog et. al.
  static ios_base::Init __ioinit;
    2064:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 206b <_Z41__static_initialization_and_destruction_0ii+0x28>
    206b:	48 89 c7             	mov    %rax,%rdi
    206e:	e8 00 00 00 00       	call   2073 <_Z41__static_initialization_and_destruction_0ii+0x30>
    2073:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 207a <_Z41__static_initialization_and_destruction_0ii+0x37>
    207a:	48 89 c2             	mov    %rax,%rdx
    207d:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 2084 <_Z41__static_initialization_and_destruction_0ii+0x41>
    2084:	48 89 c6             	mov    %rax,%rsi
    2087:	48 8b 05 00 00 00 00 	mov    0x0(%rip),%rax        # 208e <_Z41__static_initialization_and_destruction_0ii+0x4b>
    208e:	48 89 c7             	mov    %rax,%rdi
    2091:	e8 00 00 00 00       	call   2096 <_Z41__static_initialization_and_destruction_0ii+0x53>
    2096:	90                   	nop
    2097:	c9                   	leave  
    2098:	c3                   	ret    

0000000000002099 <_GLOBAL__sub_I__ZN8MemTable3putEmRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE>:
    2099:	f3 0f 1e fa          	endbr64 
    209d:	55                   	push   %rbp
    209e:	48 89 e5             	mov    %rsp,%rbp
    20a1:	be ff ff 00 00       	mov    $0xffff,%esi
    20a6:	bf 01 00 00 00       	mov    $0x1,%edi
    20ab:	e8 93 ff ff ff       	call   2043 <_Z41__static_initialization_and_destruction_0ii>
    20b0:	5d                   	pop    %rbp
    20b1:	c3                   	ret    

Disassembly of section .text._ZSt21is_constant_evaluatedv:

0000000000000000 <_ZSt21is_constant_evaluatedv>:
#define __cpp_lib_is_constant_evaluated 201811L

  /// Returns true only when called during constant evaluation.
  constexpr inline bool
  is_constant_evaluated() noexcept
  { return __builtin_is_constant_evaluated(); }
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	b8 00 00 00 00       	mov    $0x0,%eax
   d:	5d                   	pop    %rbp
   e:	c3                   	ret    

Disassembly of section .text._ZnwmPv:

0000000000000000 <_ZnwmPv>:
#endif // __cpp_sized_deallocation
#endif // __cpp_aligned_new

// Default placement versions of operator new.
_GLIBCXX_NODISCARD inline void* operator new(std::size_t, void* __p) _GLIBCXX_USE_NOEXCEPT
{ return __p; }
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  10:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  14:	5d                   	pop    %rbp
  15:	c3                   	ret    

Disassembly of section .text._ZSt17__size_to_integerm:

0000000000000000 <_ZSt17__size_to_integerm>:
  inline _GLIBCXX_CONSTEXPR unsigned
  __size_to_integer(unsigned __n) { return __n; }
  inline _GLIBCXX_CONSTEXPR long
  __size_to_integer(long __n) { return __n; }
  inline _GLIBCXX_CONSTEXPR unsigned long
  __size_to_integer(unsigned long __n) { return __n; }
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	5d                   	pop    %rbp
  11:	c3                   	ret    

Disassembly of section .text._ZNSt11char_traitsIcE6assignERcRKc:

0000000000000000 <_ZNSt11char_traitsIcE6assignERcRKc>:
#if __cpp_lib_three_way_comparison
      using comparison_category = strong_ordering;
#endif

      static _GLIBCXX17_CONSTEXPR void
      assign(char_type& __c1, const char_type& __c2) _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
      { __c1 = __c2; }
  10:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  14:	0f b6 10             	movzbl (%rax),%edx
  17:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  1b:	88 10                	mov    %dl,(%rax)
  1d:	90                   	nop
  1e:	5d                   	pop    %rbp
  1f:	c3                   	ret    

Disassembly of section .text._ZNSt11char_traitsIcE6lengthEPKc:

0000000000000000 <_ZNSt11char_traitsIcE6lengthEPKc>:
#endif
	return __builtin_memcmp(__s1, __s2, __n);
      }

      static _GLIBCXX17_CONSTEXPR size_t
      length(const char_type* __s)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  10:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  14:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
      return __builtin_is_constant_evaluated();
  18:	b8 00 00 00 00       	mov    $0x0,%eax
      {
#if __cplusplus >= 201703L
	if (__constant_string_p(__s))
  1d:	84 c0                	test   %al,%al
  1f:	74 0e                	je     2f <_ZNSt11char_traitsIcE6lengthEPKc+0x2f>
	  return __gnu_cxx::char_traits<char_type>::length(__s);
  21:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  25:	48 89 c7             	mov    %rax,%rdi
  28:	e8 00 00 00 00       	call   2d <_ZNSt11char_traitsIcE6lengthEPKc+0x2d>
  2d:	eb 0d                	jmp    3c <_ZNSt11char_traitsIcE6lengthEPKc+0x3c>
#endif
	return __builtin_strlen(__s);
  2f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  33:	48 89 c7             	mov    %rax,%rdi
  36:	e8 00 00 00 00       	call   3b <_ZNSt11char_traitsIcE6lengthEPKc+0x3b>
  3b:	90                   	nop
      }
  3c:	c9                   	leave  
  3d:	c3                   	ret    

Disassembly of section .text._ZNSt11char_traitsIcE4moveEPcPKcm:

0000000000000000 <_ZNSt11char_traitsIcE4moveEPcPKcm>:
#endif
	return static_cast<const char_type*>(__builtin_memchr(__s, __a, __n));
      }

      static _GLIBCXX20_CONSTEXPR char_type*
      move(char_type* __s1, const char_type* __s2, size_t __n)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
      {
	if (__n == 0)
  18:	48 83 7d e8 00       	cmpq   $0x0,-0x18(%rbp)
  1d:	75 06                	jne    25 <_ZNSt11char_traitsIcE4moveEPcPKcm+0x25>
	  return __s1;
  1f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  23:	eb 3a                	jmp    5f <_ZNSt11char_traitsIcE4moveEPcPKcm+0x5f>
#ifdef __cpp_lib_is_constant_evaluated
	if (std::is_constant_evaluated())
  25:	e8 00 00 00 00       	call   2a <_ZNSt11char_traitsIcE4moveEPcPKcm+0x2a>
  2a:	84 c0                	test   %al,%al
  2c:	74 19                	je     47 <_ZNSt11char_traitsIcE4moveEPcPKcm+0x47>
	  return __gnu_cxx::char_traits<char_type>::move(__s1, __s2, __n);
  2e:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  32:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
  36:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  3a:	48 89 ce             	mov    %rcx,%rsi
  3d:	48 89 c7             	mov    %rax,%rdi
  40:	e8 00 00 00 00       	call   45 <_ZNSt11char_traitsIcE4moveEPcPKcm+0x45>
  45:	eb 18                	jmp    5f <_ZNSt11char_traitsIcE4moveEPcPKcm+0x5f>
#endif
	return static_cast<char_type*>(__builtin_memmove(__s1, __s2, __n));
  47:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  4b:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
  4f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  53:	48 89 ce             	mov    %rcx,%rsi
  56:	48 89 c7             	mov    %rax,%rdi
  59:	e8 00 00 00 00       	call   5e <_ZNSt11char_traitsIcE4moveEPcPKcm+0x5e>
  5e:	90                   	nop
      }
  5f:	c9                   	leave  
  60:	c3                   	ret    

Disassembly of section .text._ZNSt11char_traitsIcE4copyEPcPKcm:

0000000000000000 <_ZNSt11char_traitsIcE4copyEPcPKcm>:

      static _GLIBCXX20_CONSTEXPR char_type*
      copy(char_type* __s1, const char_type* __s2, size_t __n)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
      {
	if (__n == 0)
  18:	48 83 7d e8 00       	cmpq   $0x0,-0x18(%rbp)
  1d:	75 06                	jne    25 <_ZNSt11char_traitsIcE4copyEPcPKcm+0x25>
	  return __s1;
  1f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  23:	eb 40                	jmp    65 <_ZNSt11char_traitsIcE4copyEPcPKcm+0x65>
#ifdef __cpp_lib_is_constant_evaluated
	if (std::is_constant_evaluated())
  25:	e8 00 00 00 00       	call   2a <_ZNSt11char_traitsIcE4copyEPcPKcm+0x2a>
  2a:	84 c0                	test   %al,%al
  2c:	74 19                	je     47 <_ZNSt11char_traitsIcE4copyEPcPKcm+0x47>
	  return __gnu_cxx::char_traits<char_type>::copy(__s1, __s2, __n);
  2e:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  32:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
  36:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  3a:	48 89 ce             	mov    %rcx,%rsi
  3d:	48 89 c7             	mov    %rax,%rdi
  40:	e8 00 00 00 00       	call   45 <_ZNSt11char_traitsIcE4copyEPcPKcm+0x45>
  45:	eb 1e                	jmp    65 <_ZNSt11char_traitsIcE4copyEPcPKcm+0x65>
#endif
	return static_cast<char_type*>(__builtin_memcpy(__s1, __s2, __n));
  47:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  4b:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  4f:	48 89 d1             	mov    %rdx,%rcx
  52:	48 89 c6             	mov    %rax,%rsi
  55:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  59:	48 89 c2             	mov    %rax,%rdx
  5c:	48 89 cf             	mov    %rcx,%rdi
  5f:	e8 00 00 00 00       	call   64 <_ZNSt11char_traitsIcE4copyEPcPKcm+0x64>
  64:	90                   	nop
      }
  65:	c9                   	leave  
  66:	c3                   	ret    

Disassembly of section .text._ZNSt11char_traitsIcE6assignEPcmc:

0000000000000000 <_ZNSt11char_traitsIcE6assignEPcmc>:

      static _GLIBCXX20_CONSTEXPR char_type*
      assign(char_type* __s, size_t __n, char_type __a)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	89 d0                	mov    %edx,%eax
  16:	88 45 ec             	mov    %al,-0x14(%rbp)
      {
	if (__n == 0)
  19:	48 83 7d f0 00       	cmpq   $0x0,-0x10(%rbp)
  1e:	75 06                	jne    26 <_ZNSt11char_traitsIcE6assignEPcmc+0x26>
	  return __s;
  20:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  24:	eb 39                	jmp    5f <_ZNSt11char_traitsIcE6assignEPcmc+0x5f>
#ifdef __cpp_lib_is_constant_evaluated
	if (std::is_constant_evaluated())
  26:	e8 00 00 00 00       	call   2b <_ZNSt11char_traitsIcE6assignEPcmc+0x2b>
  2b:	84 c0                	test   %al,%al
  2d:	74 19                	je     48 <_ZNSt11char_traitsIcE6assignEPcmc+0x48>
	  return __gnu_cxx::char_traits<char_type>::assign(__s, __n, __a);
  2f:	0f be 55 ec          	movsbl -0x14(%rbp),%edx
  33:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
  37:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  3b:	48 89 ce             	mov    %rcx,%rsi
  3e:	48 89 c7             	mov    %rax,%rdi
  41:	e8 00 00 00 00       	call   46 <_ZNSt11char_traitsIcE6assignEPcmc+0x46>
  46:	eb 17                	jmp    5f <_ZNSt11char_traitsIcE6assignEPcmc+0x5f>
#endif
	return static_cast<char_type*>(__builtin_memset(__s, __a, __n));
  48:	0f be 4d ec          	movsbl -0x14(%rbp),%ecx
  4c:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  50:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  54:	89 ce                	mov    %ecx,%esi
  56:	48 89 c7             	mov    %rax,%rdi
  59:	e8 00 00 00 00       	call   5e <_ZNSt11char_traitsIcE6assignEPcmc+0x5e>
  5e:	90                   	nop
      }
  5f:	c9                   	leave  
  60:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx119to_stringEi:

0000000000000000 <_ZNSt7__cxx119to_stringEi>:

  // DR 1261. Insufficent overloads for to_string / to_wstring

  inline string
  to_string(int __val)
  {
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 38          	sub    $0x38,%rsp
   d:	48 89 7d c8          	mov    %rdi,-0x38(%rbp)
  11:	89 75 c4             	mov    %esi,-0x3c(%rbp)
  14:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  1b:	00 00 
  1d:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  21:	31 c0                	xor    %eax,%eax
    const bool __neg = __val < 0;
  23:	8b 45 c4             	mov    -0x3c(%rbp),%eax
  26:	c1 e8 1f             	shr    $0x1f,%eax
  29:	88 45 df             	mov    %al,-0x21(%rbp)
    const unsigned __uval = __neg ? (unsigned)~__val + 1u : __val;
  2c:	80 7d df 00          	cmpb   $0x0,-0x21(%rbp)
  30:	74 07                	je     39 <_ZNSt7__cxx119to_stringEi+0x39>
  32:	8b 45 c4             	mov    -0x3c(%rbp),%eax
  35:	f7 d8                	neg    %eax
  37:	eb 03                	jmp    3c <_ZNSt7__cxx119to_stringEi+0x3c>
  39:	8b 45 c4             	mov    -0x3c(%rbp),%eax
  3c:	89 45 e0             	mov    %eax,-0x20(%rbp)
    const auto __len = __detail::__to_chars_len(__uval);
  3f:	8b 45 e0             	mov    -0x20(%rbp),%eax
  42:	be 0a 00 00 00       	mov    $0xa,%esi
  47:	89 c7                	mov    %eax,%edi
  49:	e8 00 00 00 00       	call   4e <_ZNSt7__cxx119to_stringEi+0x4e>
  4e:	89 45 e4             	mov    %eax,-0x1c(%rbp)
    string __str(__neg + __len, '-');
  51:	48 8d 45 de          	lea    -0x22(%rbp),%rax
  55:	48 89 c7             	mov    %rax,%rdi
  58:	e8 00 00 00 00       	call   5d <_ZNSt7__cxx119to_stringEi+0x5d>
  5d:	0f b6 55 df          	movzbl -0x21(%rbp),%edx
  61:	8b 45 e4             	mov    -0x1c(%rbp),%eax
  64:	01 d0                	add    %edx,%eax
  66:	89 c6                	mov    %eax,%esi
  68:	48 8d 55 de          	lea    -0x22(%rbp),%rdx
  6c:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  70:	48 89 d1             	mov    %rdx,%rcx
  73:	ba 2d 00 00 00       	mov    $0x2d,%edx
  78:	48 89 c7             	mov    %rax,%rdi
  7b:	e8 00 00 00 00       	call   80 <_ZNSt7__cxx119to_stringEi+0x80>
  80:	48 8d 45 de          	lea    -0x22(%rbp),%rax
  84:	48 89 c7             	mov    %rax,%rdi
  87:	e8 00 00 00 00       	call   8c <_ZNSt7__cxx119to_stringEi+0x8c>
    __detail::__to_chars_10_impl(&__str[__neg], __len, __uval);
  8c:	0f b6 55 df          	movzbl -0x21(%rbp),%edx
  90:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  94:	48 89 d6             	mov    %rdx,%rsi
  97:	48 89 c7             	mov    %rax,%rdi
  9a:	e8 00 00 00 00       	call   9f <_ZNSt7__cxx119to_stringEi+0x9f>
  9f:	48 89 c1             	mov    %rax,%rcx
  a2:	8b 55 e0             	mov    -0x20(%rbp),%edx
  a5:	8b 45 e4             	mov    -0x1c(%rbp),%eax
  a8:	89 c6                	mov    %eax,%esi
  aa:	48 89 cf             	mov    %rcx,%rdi
  ad:	e8 00 00 00 00       	call   b2 <_ZNSt7__cxx119to_stringEi+0xb2>
    return __str;
  b2:	90                   	nop
  }
  b3:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  b7:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
  be:	00 00 
  c0:	74 43                	je     105 <_ZNSt7__cxx119to_stringEi+0x105>
  c2:	eb 3c                	jmp    100 <_ZNSt7__cxx119to_stringEi+0x100>
  c4:	f3 0f 1e fa          	endbr64 
  c8:	48 89 c3             	mov    %rax,%rbx
  cb:	48 8d 45 de          	lea    -0x22(%rbp),%rax
  cf:	48 89 c7             	mov    %rax,%rdi
  d2:	e8 00 00 00 00       	call   d7 <_ZNSt7__cxx119to_stringEi+0xd7>
  d7:	48 89 d8             	mov    %rbx,%rax
  da:	48 89 c7             	mov    %rax,%rdi
  dd:	e8 00 00 00 00       	call   e2 <_ZNSt7__cxx119to_stringEi+0xe2>
  e2:	f3 0f 1e fa          	endbr64 
  e6:	48 89 c3             	mov    %rax,%rbx
  e9:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  ed:	48 89 c7             	mov    %rax,%rdi
  f0:	e8 00 00 00 00       	call   f5 <_ZNSt7__cxx119to_stringEi+0xf5>
  f5:	48 89 d8             	mov    %rbx,%rax
  f8:	48 89 c7             	mov    %rax,%rdi
  fb:	e8 00 00 00 00       	call   100 <_ZNSt7__cxx119to_stringEi+0x100>
 100:	e8 00 00 00 00       	call   105 <_ZNSt7__cxx119to_stringEi+0x105>
 105:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
 109:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
 10d:	c9                   	leave  
 10e:	c3                   	ret    

Disassembly of section .text._ZNSt8__detail14__to_chars_lenIjEEjT_i:

0000000000000000 <_ZNSt8__detail14__to_chars_lenIjEEjT_i>:
namespace __detail
{
  // Generic implementation for arbitrary bases.
  template<typename _Tp>
    _GLIBCXX14_CONSTEXPR unsigned
    __to_chars_len(_Tp __value, int __base = 10) noexcept
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	89 7d dc             	mov    %edi,-0x24(%rbp)
   b:	89 75 d8             	mov    %esi,-0x28(%rbp)
    {
      static_assert(is_integral<_Tp>::value, "implementation bug");
      static_assert(is_unsigned<_Tp>::value, "implementation bug");

      unsigned __n = 1;
   e:	c7 45 ec 01 00 00 00 	movl   $0x1,-0x14(%rbp)
      const unsigned __b2 = __base  * __base;
  15:	8b 45 d8             	mov    -0x28(%rbp),%eax
  18:	0f af c0             	imul   %eax,%eax
  1b:	89 45 f0             	mov    %eax,-0x10(%rbp)
      const unsigned __b3 = __b2 * __base;
  1e:	8b 45 d8             	mov    -0x28(%rbp),%eax
  21:	8b 55 f0             	mov    -0x10(%rbp),%edx
  24:	0f af c2             	imul   %edx,%eax
  27:	89 45 f4             	mov    %eax,-0xc(%rbp)
      const unsigned long __b4 = __b3 * __base;
  2a:	8b 45 d8             	mov    -0x28(%rbp),%eax
  2d:	0f af 45 f4          	imul   -0xc(%rbp),%eax
  31:	89 c0                	mov    %eax,%eax
  33:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
      for (;;)
	{
	  if (__value < (unsigned)__base) return __n;
  37:	8b 45 d8             	mov    -0x28(%rbp),%eax
  3a:	39 45 dc             	cmp    %eax,-0x24(%rbp)
  3d:	73 05                	jae    44 <_ZNSt8__detail14__to_chars_lenIjEEjT_i+0x44>
  3f:	8b 45 ec             	mov    -0x14(%rbp),%eax
  42:	eb 46                	jmp    8a <_ZNSt8__detail14__to_chars_lenIjEEjT_i+0x8a>
	  if (__value < __b2) return __n + 1;
  44:	8b 45 dc             	mov    -0x24(%rbp),%eax
  47:	3b 45 f0             	cmp    -0x10(%rbp),%eax
  4a:	73 08                	jae    54 <_ZNSt8__detail14__to_chars_lenIjEEjT_i+0x54>
  4c:	8b 45 ec             	mov    -0x14(%rbp),%eax
  4f:	83 c0 01             	add    $0x1,%eax
  52:	eb 36                	jmp    8a <_ZNSt8__detail14__to_chars_lenIjEEjT_i+0x8a>
	  if (__value < __b3) return __n + 2;
  54:	8b 45 dc             	mov    -0x24(%rbp),%eax
  57:	3b 45 f4             	cmp    -0xc(%rbp),%eax
  5a:	73 08                	jae    64 <_ZNSt8__detail14__to_chars_lenIjEEjT_i+0x64>
  5c:	8b 45 ec             	mov    -0x14(%rbp),%eax
  5f:	83 c0 02             	add    $0x2,%eax
  62:	eb 26                	jmp    8a <_ZNSt8__detail14__to_chars_lenIjEEjT_i+0x8a>
	  if (__value < __b4) return __n + 3;
  64:	8b 45 dc             	mov    -0x24(%rbp),%eax
  67:	48 39 45 f8          	cmp    %rax,-0x8(%rbp)
  6b:	76 08                	jbe    75 <_ZNSt8__detail14__to_chars_lenIjEEjT_i+0x75>
  6d:	8b 45 ec             	mov    -0x14(%rbp),%eax
  70:	83 c0 03             	add    $0x3,%eax
  73:	eb 15                	jmp    8a <_ZNSt8__detail14__to_chars_lenIjEEjT_i+0x8a>
	  __value /= __b4;
  75:	8b 45 dc             	mov    -0x24(%rbp),%eax
  78:	ba 00 00 00 00       	mov    $0x0,%edx
  7d:	48 f7 75 f8          	divq   -0x8(%rbp)
  81:	89 45 dc             	mov    %eax,-0x24(%rbp)
	  __n += 4;
  84:	83 45 ec 04          	addl   $0x4,-0x14(%rbp)
	  if (__value < (unsigned)__base) return __n;
  88:	eb ad                	jmp    37 <_ZNSt8__detail14__to_chars_lenIjEEjT_i+0x37>
	}
    }
  8a:	5d                   	pop    %rbp
  8b:	c3                   	ret    

Disassembly of section .text._ZN10KVStoreAPIC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_:

0000000000000000 <_ZN10KVStoreAPIC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_>:
	 * You should put all sstables under `dir`, and all value pairs in `vlog`.
	 * Please create one sub-directory for each level, and put sstables
	 * there. Please refer to the c++ filesystem library
	 * (https://en.cppreference.com/w/cpp/filesystem).
	 */
	KVStoreAPI(const std::string &dir, const std::string &vlog) {}
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  10:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
  14:	48 8d 15 00 00 00 00 	lea    0x0(%rip),%rdx        # 1b <_ZN10KVStoreAPIC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_+0x1b>
  1b:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  1f:	48 89 10             	mov    %rdx,(%rax)
  22:	90                   	nop
  23:	5d                   	pop    %rbp
  24:	c3                   	ret    

Disassembly of section .text._Z6rotl64ma:

0000000000000000 <_Z6rotl64ma>:
{
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	89 f0                	mov    %esi,%eax
   e:	88 45 f4             	mov    %al,-0xc(%rbp)
  return (x << r) | (x >> (64 - r));
  11:	0f be 45 f4          	movsbl -0xc(%rbp),%eax
  15:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  19:	89 c1                	mov    %eax,%ecx
  1b:	48 d3 c2             	rol    %cl,%rdx
  1e:	48 89 d0             	mov    %rdx,%rax
}
  21:	5d                   	pop    %rbp
  22:	c3                   	ret    

Disassembly of section .text._ZN8MemTable12QuadlistNodeC2EmNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPS0_S7_S7_S7_:

0000000000000000 <_ZN8MemTable12QuadlistNodeC1EmNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPS0_S7_S7_S7_>:
public:
	KVStore(const std::string &dir, const std::string &vlog);

	~KVStore();

	void put(uint64_t key, const std::string &s) override;
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 30          	sub    $0x30,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
  18:	48 89 4d e0          	mov    %rcx,-0x20(%rbp)
  1c:	4c 89 45 d8          	mov    %r8,-0x28(%rbp)
  20:	4c 89 4d d0          	mov    %r9,-0x30(%rbp)

  24:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  28:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  2c:	48 89 d6             	mov    %rdx,%rsi
  2f:	48 89 c7             	mov    %rax,%rdi
  32:	e8 00 00 00 00       	call   37 <_ZN8MemTable12QuadlistNodeC1EmNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPS0_S7_S7_S7_+0x37>
  37:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  3b:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  3f:	48 89 50 20          	mov    %rdx,0x20(%rax)
  43:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  47:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
  4b:	48 89 50 28          	mov    %rdx,0x28(%rax)
  4f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  53:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
  57:	48 89 50 30          	mov    %rdx,0x30(%rax)
  5b:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  5f:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
  63:	48 89 50 38          	mov    %rdx,0x38(%rax)
  67:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  6b:	48 8b 55 10          	mov    0x10(%rbp),%rdx
  6f:	48 89 50 40          	mov    %rdx,0x40(%rax)
	std::string get(uint64_t key) override;
  73:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  77:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  7b:	48 89 50 20          	mov    %rdx,0x20(%rax)

  7f:	90                   	nop
  80:	c9                   	leave  
  81:	c3                   	ret    

Disassembly of section .text._ZN8MemTable12QuadlistNode17insertAsSuccAboveEmNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPS0_:

0000000000000000 <_ZN8MemTable12QuadlistNode17insertAsSuccAboveEmNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPS0_>:
	bool del(uint64_t key) override;
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	41 54                	push   %r12
   a:	53                   	push   %rbx
   b:	48 83 ec 60          	sub    $0x60,%rsp
   f:	48 89 7d a8          	mov    %rdi,-0x58(%rbp)
  13:	48 89 75 a0          	mov    %rsi,-0x60(%rbp)
  17:	48 89 55 98          	mov    %rdx,-0x68(%rbp)
  1b:	48 89 4d 90          	mov    %rcx,-0x70(%rbp)
  1f:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  26:	00 00 
  28:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  2c:	31 c0                	xor    %eax,%eax

	void reset() override;
  2e:	48 8b 55 98          	mov    -0x68(%rbp),%rdx
  32:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
  36:	48 89 d6             	mov    %rdx,%rsi
  39:	48 89 c7             	mov    %rax,%rdi
  3c:	e8 00 00 00 00       	call   41 <_ZN8MemTable12QuadlistNode17insertAsSuccAboveEmNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPS0_+0x41>
  41:	4c 8d 65 c0          	lea    -0x40(%rbp),%r12
  45:	bf 48 00 00 00       	mov    $0x48,%edi
  4a:	e8 00 00 00 00       	call   4f <_ZN8MemTable12QuadlistNode17insertAsSuccAboveEmNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPS0_+0x4f>
  4f:	48 89 c3             	mov    %rax,%rbx
  52:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  56:	48 8b 48 30          	mov    0x30(%rax),%rcx
  5a:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
  5e:	48 8b 45 a0          	mov    -0x60(%rbp),%rax
  62:	48 83 ec 08          	sub    $0x8,%rsp
  66:	ff 75 90             	push   -0x70(%rbp)
  69:	41 b9 00 00 00 00    	mov    $0x0,%r9d
  6f:	49 89 c8             	mov    %rcx,%r8
  72:	48 89 d1             	mov    %rdx,%rcx
  75:	4c 89 e2             	mov    %r12,%rdx
  78:	48 89 c6             	mov    %rax,%rsi
  7b:	48 89 df             	mov    %rbx,%rdi
  7e:	e8 00 00 00 00       	call   83 <_ZN8MemTable12QuadlistNode17insertAsSuccAboveEmNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPS0_+0x83>
  83:	48 83 c4 10          	add    $0x10,%rsp
  87:	48 89 5d b8          	mov    %rbx,-0x48(%rbp)
  8b:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
  8f:	48 89 c7             	mov    %rax,%rdi
  92:	e8 00 00 00 00       	call   97 <_ZN8MemTable12QuadlistNode17insertAsSuccAboveEmNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPS0_+0x97>

  97:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  9b:	48 8b 40 30          	mov    0x30(%rax),%rax
  9f:	48 8b 55 b8          	mov    -0x48(%rbp),%rdx
  a3:	48 89 50 28          	mov    %rdx,0x28(%rax)
	void scan(uint64_t key1, uint64_t key2, std::list<std::pair<uint64_t, std::string>> &list) override;
  a7:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  ab:	48 8b 55 b8          	mov    -0x48(%rbp),%rdx
  af:	48 89 50 30          	mov    %rdx,0x30(%rax)

  b3:	48 83 7d 90 00       	cmpq   $0x0,-0x70(%rbp)
  b8:	74 0c                	je     c6 <_ZN8MemTable12QuadlistNode17insertAsSuccAboveEmNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPS0_+0xc6>
  ba:	48 8b 45 90          	mov    -0x70(%rbp),%rax
  be:	48 8b 55 b8          	mov    -0x48(%rbp),%rdx
  c2:	48 89 50 38          	mov    %rdx,0x38(%rax)
	void gc(uint64_t chunk_size) override;
  c6:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  ca:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  ce:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
  d5:	00 00 
  d7:	74 3e                	je     117 <_ZN8MemTable12QuadlistNode17insertAsSuccAboveEmNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPS0_+0x117>
  d9:	eb 37                	jmp    112 <_ZN8MemTable12QuadlistNode17insertAsSuccAboveEmNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPS0_+0x112>
  db:	f3 0f 1e fa          	endbr64 
	void reset() override;
  df:	49 89 c4             	mov    %rax,%r12
  e2:	be 48 00 00 00       	mov    $0x48,%esi
  e7:	48 89 df             	mov    %rbx,%rdi
  ea:	e8 00 00 00 00       	call   ef <_ZN8MemTable12QuadlistNode17insertAsSuccAboveEmNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPS0_+0xef>
  ef:	4c 89 e3             	mov    %r12,%rbx
  f2:	eb 07                	jmp    fb <_ZN8MemTable12QuadlistNode17insertAsSuccAboveEmNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPS0_+0xfb>
  f4:	f3 0f 1e fa          	endbr64 
  f8:	48 89 c3             	mov    %rax,%rbx
  fb:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
  ff:	48 89 c7             	mov    %rax,%rdi
 102:	e8 00 00 00 00       	call   107 <_ZN8MemTable12QuadlistNode17insertAsSuccAboveEmNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPS0_+0x107>
 107:	48 89 d8             	mov    %rbx,%rax
 10a:	48 89 c7             	mov    %rax,%rdi
 10d:	e8 00 00 00 00       	call   112 <_ZN8MemTable12QuadlistNode17insertAsSuccAboveEmNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPS0_+0x112>
 112:	e8 00 00 00 00       	call   117 <_ZN8MemTable12QuadlistNode17insertAsSuccAboveEmNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPS0_+0x117>
 117:	48 8d 65 f0          	lea    -0x10(%rbp),%rsp
 11b:	5b                   	pop    %rbx
 11c:	41 5c                	pop    %r12
 11e:	5d                   	pop    %rbp
 11f:	c3                   	ret    

Disassembly of section .text._ZN8MemTable8QuadlistC2Ev:

0000000000000000 <_ZN8MemTable8QuadlistC1Ev>:
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	41 54                	push   %r12
   a:	53                   	push   %rbx
   b:	48 83 ec 50          	sub    $0x50,%rsp
   f:	48 89 7d a8          	mov    %rdi,-0x58(%rbp)
  13:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  1a:	00 00 
  1c:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  20:	31 c0                	xor    %eax,%eax
  22:	48 8d 45 bf          	lea    -0x41(%rbp),%rax
  26:	48 89 c7             	mov    %rax,%rdi
  29:	e8 00 00 00 00       	call   2e <_ZN8MemTable8QuadlistC1Ev+0x2e>
  2e:	48 8d 55 bf          	lea    -0x41(%rbp),%rdx
  32:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
  36:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # 3d <_ZN8MemTable8QuadlistC1Ev+0x3d>
  3d:	48 89 ce             	mov    %rcx,%rsi
  40:	48 89 c7             	mov    %rax,%rdi
  43:	e8 00 00 00 00       	call   48 <_ZN8MemTable8QuadlistC1Ev+0x48>
  48:	4c 8d 65 c0          	lea    -0x40(%rbp),%r12
  4c:	bf 48 00 00 00       	mov    $0x48,%edi
  51:	e8 00 00 00 00       	call   56 <_ZN8MemTable8QuadlistC1Ev+0x56>
  56:	48 89 c3             	mov    %rax,%rbx
  59:	48 83 ec 08          	sub    $0x8,%rsp
  5d:	6a 00                	push   $0x0
  5f:	41 b9 00 00 00 00    	mov    $0x0,%r9d
  65:	41 b8 00 00 00 00    	mov    $0x0,%r8d
  6b:	b9 00 00 00 00       	mov    $0x0,%ecx
  70:	4c 89 e2             	mov    %r12,%rdx
  73:	be 00 00 00 00       	mov    $0x0,%esi
  78:	48 89 df             	mov    %rbx,%rdi
  7b:	e8 00 00 00 00       	call   80 <_ZN8MemTable8QuadlistC1Ev+0x80>
  80:	48 83 c4 10          	add    $0x10,%rsp
  84:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  88:	48 89 18             	mov    %rbx,(%rax)
  8b:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
  8f:	48 89 c7             	mov    %rax,%rdi
  92:	e8 00 00 00 00       	call   97 <_ZN8MemTable8QuadlistC1Ev+0x97>
  97:	48 8d 45 bf          	lea    -0x41(%rbp),%rax
  9b:	48 89 c7             	mov    %rax,%rdi
  9e:	e8 00 00 00 00       	call   a3 <_ZN8MemTable8QuadlistC1Ev+0xa3>
  a3:	48 8d 45 bf          	lea    -0x41(%rbp),%rax
  a7:	48 89 c7             	mov    %rax,%rdi
  aa:	e8 00 00 00 00       	call   af <_ZN8MemTable8QuadlistC1Ev+0xaf>
  af:	48 8d 55 bf          	lea    -0x41(%rbp),%rdx
  b3:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
  b7:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # be <_ZN8MemTable8QuadlistC1Ev+0xbe>
  be:	48 89 ce             	mov    %rcx,%rsi
  c1:	48 89 c7             	mov    %rax,%rdi
  c4:	e8 00 00 00 00       	call   c9 <_ZN8MemTable8QuadlistC1Ev+0xc9>
  c9:	4c 8d 65 c0          	lea    -0x40(%rbp),%r12
  cd:	bf 48 00 00 00       	mov    $0x48,%edi
  d2:	e8 00 00 00 00       	call   d7 <_ZN8MemTable8QuadlistC1Ev+0xd7>
  d7:	48 89 c3             	mov    %rax,%rbx
  da:	48 83 ec 08          	sub    $0x8,%rsp
  de:	6a 00                	push   $0x0
  e0:	41 b9 00 00 00 00    	mov    $0x0,%r9d
  e6:	41 b8 00 00 00 00    	mov    $0x0,%r8d
  ec:	b9 00 00 00 00       	mov    $0x0,%ecx
  f1:	4c 89 e2             	mov    %r12,%rdx
  f4:	48 b8 f8 ff ff ff ff 	movabs $0x7ffffffffffffff8,%rax
  fb:	ff ff 7f 
  fe:	48 89 c6             	mov    %rax,%rsi
 101:	48 89 df             	mov    %rbx,%rdi
 104:	e8 00 00 00 00       	call   109 <_ZN8MemTable8QuadlistC1Ev+0x109>
 109:	48 83 c4 10          	add    $0x10,%rsp
 10d:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
 111:	48 89 58 08          	mov    %rbx,0x8(%rax)
 115:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
 119:	48 89 c7             	mov    %rax,%rdi
 11c:	e8 00 00 00 00       	call   121 <_ZN8MemTable8QuadlistC1Ev+0x121>
 121:	48 8d 45 bf          	lea    -0x41(%rbp),%rax
 125:	48 89 c7             	mov    %rax,%rdi
 128:	e8 00 00 00 00       	call   12d <_ZN8MemTable8QuadlistC1Ev+0x12d>
 12d:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
 131:	48 8b 40 08          	mov    0x8(%rax),%rax
 135:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
 139:	48 8b 12             	mov    (%rdx),%rdx
 13c:	48 89 50 28          	mov    %rdx,0x28(%rax)
 140:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
 144:	48 8b 00             	mov    (%rax),%rax
 147:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
 14b:	48 8b 52 08          	mov    0x8(%rdx),%rdx
 14f:	48 89 50 30          	mov    %rdx,0x30(%rax)
 153:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
 157:	48 8b 10             	mov    (%rax),%rdx
 15a:	48 c7 42 40 00 00 00 	movq   $0x0,0x40(%rdx)
 161:	00 
 162:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
 166:	48 8b 00             	mov    (%rax),%rax
 169:	48 8b 52 40          	mov    0x40(%rdx),%rdx
 16d:	48 89 50 38          	mov    %rdx,0x38(%rax)
 171:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
 175:	48 8b 12             	mov    (%rdx),%rdx
 178:	48 8b 40 38          	mov    0x38(%rax),%rax
 17c:	48 89 42 28          	mov    %rax,0x28(%rdx)
 180:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
 184:	48 8b 50 08          	mov    0x8(%rax),%rdx
 188:	48 c7 42 30 00 00 00 	movq   $0x0,0x30(%rdx)
 18f:	00 
 190:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
 194:	48 8b 40 08          	mov    0x8(%rax),%rax
 198:	48 8b 52 30          	mov    0x30(%rdx),%rdx
 19c:	48 89 50 40          	mov    %rdx,0x40(%rax)
 1a0:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
 1a4:	48 8b 52 08          	mov    0x8(%rdx),%rdx
 1a8:	48 8b 40 40          	mov    0x40(%rax),%rax
 1ac:	48 89 42 38          	mov    %rax,0x38(%rdx)
 1b0:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
 1b4:	c7 40 10 00 00 00 00 	movl   $0x0,0x10(%rax)
 1bb:	90                   	nop
 1bc:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
 1c0:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
 1c7:	00 00 
 1c9:	0f 84 a2 00 00 00    	je     271 <_ZN8MemTable8QuadlistC1Ev+0x271>
 1cf:	e9 98 00 00 00       	jmp    26c <_ZN8MemTable8QuadlistC1Ev+0x26c>
 1d4:	f3 0f 1e fa          	endbr64 
 1d8:	49 89 c4             	mov    %rax,%r12
 1db:	be 48 00 00 00       	mov    $0x48,%esi
 1e0:	48 89 df             	mov    %rbx,%rdi
 1e3:	e8 00 00 00 00       	call   1e8 <_ZN8MemTable8QuadlistC1Ev+0x1e8>
 1e8:	4c 89 e3             	mov    %r12,%rbx
 1eb:	eb 07                	jmp    1f4 <_ZN8MemTable8QuadlistC1Ev+0x1f4>
 1ed:	f3 0f 1e fa          	endbr64 
 1f1:	48 89 c3             	mov    %rax,%rbx
 1f4:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
 1f8:	48 89 c7             	mov    %rax,%rdi
 1fb:	e8 00 00 00 00       	call   200 <_ZN8MemTable8QuadlistC1Ev+0x200>
 200:	eb 07                	jmp    209 <_ZN8MemTable8QuadlistC1Ev+0x209>
 202:	f3 0f 1e fa          	endbr64 
 206:	48 89 c3             	mov    %rax,%rbx
 209:	48 8d 45 bf          	lea    -0x41(%rbp),%rax
 20d:	48 89 c7             	mov    %rax,%rdi
 210:	e8 00 00 00 00       	call   215 <_ZN8MemTable8QuadlistC1Ev+0x215>
 215:	48 89 d8             	mov    %rbx,%rax
 218:	48 89 c7             	mov    %rax,%rdi
 21b:	e8 00 00 00 00       	call   220 <_ZN8MemTable8QuadlistC1Ev+0x220>
 220:	f3 0f 1e fa          	endbr64 
 224:	49 89 c4             	mov    %rax,%r12
 227:	be 48 00 00 00       	mov    $0x48,%esi
 22c:	48 89 df             	mov    %rbx,%rdi
 22f:	e8 00 00 00 00       	call   234 <_ZN8MemTable8QuadlistC1Ev+0x234>
 234:	4c 89 e3             	mov    %r12,%rbx
 237:	eb 07                	jmp    240 <_ZN8MemTable8QuadlistC1Ev+0x240>
 239:	f3 0f 1e fa          	endbr64 
 23d:	48 89 c3             	mov    %rax,%rbx
 240:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
 244:	48 89 c7             	mov    %rax,%rdi
 247:	e8 00 00 00 00       	call   24c <_ZN8MemTable8QuadlistC1Ev+0x24c>
 24c:	eb 07                	jmp    255 <_ZN8MemTable8QuadlistC1Ev+0x255>
 24e:	f3 0f 1e fa          	endbr64 
 252:	48 89 c3             	mov    %rax,%rbx
 255:	48 8d 45 bf          	lea    -0x41(%rbp),%rax
 259:	48 89 c7             	mov    %rax,%rdi
 25c:	e8 00 00 00 00       	call   261 <_ZN8MemTable8QuadlistC1Ev+0x261>
 261:	48 89 d8             	mov    %rbx,%rax
 264:	48 89 c7             	mov    %rax,%rdi
 267:	e8 00 00 00 00       	call   26c <_ZN8MemTable8QuadlistC1Ev+0x26c>
 26c:	e8 00 00 00 00       	call   271 <_ZN8MemTable8QuadlistC1Ev+0x271>
 271:	48 8d 65 f0          	lea    -0x10(%rbp),%rsp
 275:	5b                   	pop    %rbx
 276:	41 5c                	pop    %r12
 278:	5d                   	pop    %rbp
 279:	c3                   	ret    

Disassembly of section .text._ZN8MemTable8Quadlist5fristEv:

0000000000000000 <_ZN8MemTable8Quadlist5fristEv>:
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	48 8b 00             	mov    (%rax),%rax
  13:	48 8b 40 30          	mov    0x30(%rax),%rax
  17:	5d                   	pop    %rbp
  18:	c3                   	ret    

Disassembly of section .text._ZN8MemTable8Quadlist4lastEv:

0000000000000000 <_ZN8MemTable8Quadlist4lastEv>:
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	48 8b 40 08          	mov    0x8(%rax),%rax
  14:	48 8b 40 28          	mov    0x28(%rax),%rax
  18:	5d                   	pop    %rbp
  19:	c3                   	ret    

Disassembly of section .text._ZN8MemTable8Quadlist16insertAfterAboveEmNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS_12QuadlistNodeES8_:

0000000000000000 <_ZN8MemTable8Quadlist16insertAfterAboveEmNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS_12QuadlistNodeES8_>:
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 68          	sub    $0x68,%rsp
   d:	48 89 7d b8          	mov    %rdi,-0x48(%rbp)
  11:	48 89 75 b0          	mov    %rsi,-0x50(%rbp)
  15:	48 89 55 a8          	mov    %rdx,-0x58(%rbp)
  19:	48 89 4d a0          	mov    %rcx,-0x60(%rbp)
  1d:	4c 89 45 98          	mov    %r8,-0x68(%rbp)
  21:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  28:	00 00 
  2a:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  2e:	31 c0                	xor    %eax,%eax
  30:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  34:	8b 40 10             	mov    0x10(%rax),%eax
  37:	8d 50 01             	lea    0x1(%rax),%edx
  3a:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  3e:	89 50 10             	mov    %edx,0x10(%rax)
  41:	48 8b 5d a0          	mov    -0x60(%rbp),%rbx
  45:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
  49:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
  4d:	48 89 d6             	mov    %rdx,%rsi
  50:	48 89 c7             	mov    %rax,%rdi
  53:	e8 00 00 00 00       	call   58 <_ZN8MemTable8Quadlist16insertAfterAboveEmNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS_12QuadlistNodeES8_+0x58>
  58:	48 8b 4d 98          	mov    -0x68(%rbp),%rcx
  5c:	48 8d 55 c0          	lea    -0x40(%rbp),%rdx
  60:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
  64:	48 89 c6             	mov    %rax,%rsi
  67:	48 89 df             	mov    %rbx,%rdi
  6a:	e8 00 00 00 00       	call   6f <_ZN8MemTable8Quadlist16insertAfterAboveEmNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS_12QuadlistNodeES8_+0x6f>
  6f:	48 89 c3             	mov    %rax,%rbx
  72:	90                   	nop
  73:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
  77:	48 89 c7             	mov    %rax,%rdi
  7a:	e8 00 00 00 00       	call   7f <_ZN8MemTable8Quadlist16insertAfterAboveEmNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS_12QuadlistNodeES8_+0x7f>
  7f:	48 89 d8             	mov    %rbx,%rax
  82:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  86:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
  8d:	00 00 
  8f:	74 25                	je     b6 <_ZN8MemTable8Quadlist16insertAfterAboveEmNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS_12QuadlistNodeES8_+0xb6>
  91:	eb 1e                	jmp    b1 <_ZN8MemTable8Quadlist16insertAfterAboveEmNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS_12QuadlistNodeES8_+0xb1>
  93:	f3 0f 1e fa          	endbr64 
  97:	48 89 c3             	mov    %rax,%rbx
  9a:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
  9e:	48 89 c7             	mov    %rax,%rdi
  a1:	e8 00 00 00 00       	call   a6 <_ZN8MemTable8Quadlist16insertAfterAboveEmNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS_12QuadlistNodeES8_+0xa6>
  a6:	48 89 d8             	mov    %rbx,%rax
  a9:	48 89 c7             	mov    %rax,%rdi
  ac:	e8 00 00 00 00       	call   b1 <_ZN8MemTable8Quadlist16insertAfterAboveEmNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS_12QuadlistNodeES8_+0xb1>
  b1:	e8 00 00 00 00       	call   b6 <_ZN8MemTable8Quadlist16insertAfterAboveEmNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPNS_12QuadlistNodeES8_+0xb6>
  b6:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  ba:	c9                   	leave  
  bb:	c3                   	ret    

Disassembly of section .text._ZN8MemTable5fristEv:

0000000000000000 <_ZN8MemTable5fristEv>:
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	41 54                	push   %r12
   a:	53                   	push   %rbx
   b:	48 83 ec 20          	sub    $0x20,%rsp
   f:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  13:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  1a:	00 00 
  1c:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  20:	31 c0                	xor    %eax,%eax
  22:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  26:	48 83 c0 08          	add    $0x8,%rax
  2a:	48 89 c7             	mov    %rax,%rdi
  2d:	e8 00 00 00 00       	call   32 <_ZN8MemTable5fristEv+0x32>
  32:	48 85 c0             	test   %rax,%rax
  35:	0f 94 c0             	sete   %al
  38:	84 c0                	test   %al,%al
  3a:	74 30                	je     6c <_ZN8MemTable5fristEv+0x6c>
  3c:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  40:	4c 8d 60 08          	lea    0x8(%rax),%r12
  44:	bf 18 00 00 00       	mov    $0x18,%edi
  49:	e8 00 00 00 00       	call   4e <_ZN8MemTable5fristEv+0x4e>
  4e:	48 89 c3             	mov    %rax,%rbx
  51:	48 89 df             	mov    %rbx,%rdi
  54:	e8 00 00 00 00       	call   59 <_ZN8MemTable5fristEv+0x59>
  59:	48 89 5d e0          	mov    %rbx,-0x20(%rbp)
  5d:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  61:	48 89 c6             	mov    %rax,%rsi
  64:	4c 89 e7             	mov    %r12,%rdi
  67:	e8 00 00 00 00       	call   6c <_ZN8MemTable5fristEv+0x6c>
  6c:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  70:	48 8d 58 08          	lea    0x8(%rax),%rbx
  74:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  78:	48 83 c0 08          	add    $0x8,%rax
  7c:	48 89 c7             	mov    %rax,%rdi
  7f:	e8 00 00 00 00       	call   84 <_ZN8MemTable5fristEv+0x84>
  84:	48 83 e8 01          	sub    $0x1,%rax
  88:	48 89 c6             	mov    %rax,%rsi
  8b:	48 89 df             	mov    %rbx,%rdi
  8e:	e8 00 00 00 00       	call   93 <_ZN8MemTable5fristEv+0x93>
  93:	48 8b 00             	mov    (%rax),%rax
  96:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  9a:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
  a1:	00 00 
  a3:	74 26                	je     cb <_ZN8MemTable5fristEv+0xcb>
  a5:	eb 1f                	jmp    c6 <_ZN8MemTable5fristEv+0xc6>
  a7:	f3 0f 1e fa          	endbr64 
  ab:	49 89 c4             	mov    %rax,%r12
  ae:	be 18 00 00 00       	mov    $0x18,%esi
  b3:	48 89 df             	mov    %rbx,%rdi
  b6:	e8 00 00 00 00       	call   bb <_ZN8MemTable5fristEv+0xbb>
  bb:	4c 89 e0             	mov    %r12,%rax
  be:	48 89 c7             	mov    %rax,%rdi
  c1:	e8 00 00 00 00       	call   c6 <_ZN8MemTable5fristEv+0xc6>
  c6:	e8 00 00 00 00       	call   cb <_ZN8MemTable5fristEv+0xcb>
  cb:	48 83 c4 20          	add    $0x20,%rsp
  cf:	5b                   	pop    %rbx
  d0:	41 5c                	pop    %r12
  d2:	5d                   	pop    %rbp
  d3:	c3                   	ret    

Disassembly of section .text._ZN8MemTable4lastEv:

0000000000000000 <_ZN8MemTable4lastEv>:
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	41 54                	push   %r12
   a:	53                   	push   %rbx
   b:	48 83 ec 20          	sub    $0x20,%rsp
   f:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  13:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  1a:	00 00 
  1c:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  20:	31 c0                	xor    %eax,%eax
  22:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  26:	48 83 c0 08          	add    $0x8,%rax
  2a:	48 89 c7             	mov    %rax,%rdi
  2d:	e8 00 00 00 00       	call   32 <_ZN8MemTable4lastEv+0x32>
  32:	48 85 c0             	test   %rax,%rax
  35:	0f 94 c0             	sete   %al
  38:	84 c0                	test   %al,%al
  3a:	74 30                	je     6c <_ZN8MemTable4lastEv+0x6c>
  3c:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  40:	4c 8d 60 08          	lea    0x8(%rax),%r12
  44:	bf 18 00 00 00       	mov    $0x18,%edi
  49:	e8 00 00 00 00       	call   4e <_ZN8MemTable4lastEv+0x4e>
  4e:	48 89 c3             	mov    %rax,%rbx
  51:	48 89 df             	mov    %rbx,%rdi
  54:	e8 00 00 00 00       	call   59 <_ZN8MemTable4lastEv+0x59>
  59:	48 89 5d e0          	mov    %rbx,-0x20(%rbp)
  5d:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  61:	48 89 c6             	mov    %rax,%rsi
  64:	4c 89 e7             	mov    %r12,%rdi
  67:	e8 00 00 00 00       	call   6c <_ZN8MemTable4lastEv+0x6c>
  6c:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  70:	48 83 c0 08          	add    $0x8,%rax
  74:	be 00 00 00 00       	mov    $0x0,%esi
  79:	48 89 c7             	mov    %rax,%rdi
  7c:	e8 00 00 00 00       	call   81 <_ZN8MemTable4lastEv+0x81>
  81:	48 8b 00             	mov    (%rax),%rax
  84:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  88:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
  8f:	00 00 
  91:	74 26                	je     b9 <_ZN8MemTable4lastEv+0xb9>
  93:	eb 1f                	jmp    b4 <_ZN8MemTable4lastEv+0xb4>
  95:	f3 0f 1e fa          	endbr64 
  99:	49 89 c4             	mov    %rax,%r12
  9c:	be 18 00 00 00       	mov    $0x18,%esi
  a1:	48 89 df             	mov    %rbx,%rdi
  a4:	e8 00 00 00 00       	call   a9 <_ZN8MemTable4lastEv+0xa9>
  a9:	4c 89 e0             	mov    %r12,%rax
  ac:	48 89 c7             	mov    %rax,%rdi
  af:	e8 00 00 00 00       	call   b4 <_ZN8MemTable4lastEv+0xb4>
  b4:	e8 00 00 00 00       	call   b9 <_ZN8MemTable4lastEv+0xb9>
  b9:	48 83 c4 20          	add    $0x20,%rsp
  bd:	5b                   	pop    %rbx
  be:	41 5c                	pop    %r12
  c0:	5d                   	pop    %rbp
  c1:	c3                   	ret    

Disassembly of section .text._ZNSt13random_deviceC2Ev:

0000000000000000 <_ZNSt13random_deviceC1Ev>:
    /** The type of the generated random value. */
    typedef unsigned int result_type;

    // constructors, destructors and member functions

    random_device() { _M_init("default"); }
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 58          	sub    $0x58,%rsp
   d:	48 89 7d a8          	mov    %rdi,-0x58(%rbp)
  11:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  18:	00 00 
  1a:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  1e:	31 c0                	xor    %eax,%eax
  20:	48 8d 45 bf          	lea    -0x41(%rbp),%rax
  24:	48 89 c7             	mov    %rax,%rdi
  27:	e8 00 00 00 00       	call   2c <_ZNSt13random_deviceC1Ev+0x2c>
  2c:	48 8d 55 bf          	lea    -0x41(%rbp),%rdx
  30:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
  34:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # 3b <_ZNSt13random_deviceC1Ev+0x3b>
  3b:	48 89 ce             	mov    %rcx,%rsi
  3e:	48 89 c7             	mov    %rax,%rdi
  41:	e8 00 00 00 00       	call   46 <_ZNSt13random_deviceC1Ev+0x46>
  46:	48 8d 55 c0          	lea    -0x40(%rbp),%rdx
  4a:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  4e:	48 89 d6             	mov    %rdx,%rsi
  51:	48 89 c7             	mov    %rax,%rdi
  54:	e8 00 00 00 00       	call   59 <_ZNSt13random_deviceC1Ev+0x59>
  59:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
  5d:	48 89 c7             	mov    %rax,%rdi
  60:	e8 00 00 00 00       	call   65 <_ZNSt13random_deviceC1Ev+0x65>
  65:	48 8d 45 bf          	lea    -0x41(%rbp),%rax
  69:	48 89 c7             	mov    %rax,%rdi
  6c:	e8 00 00 00 00       	call   71 <_ZNSt13random_deviceC1Ev+0x71>
  71:	90                   	nop
  72:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  76:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
  7d:	00 00 
  7f:	74 3a                	je     bb <_ZNSt13random_deviceC1Ev+0xbb>
  81:	eb 33                	jmp    b6 <_ZNSt13random_deviceC1Ev+0xb6>
  83:	f3 0f 1e fa          	endbr64 
  87:	48 89 c3             	mov    %rax,%rbx
  8a:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
  8e:	48 89 c7             	mov    %rax,%rdi
  91:	e8 00 00 00 00       	call   96 <_ZNSt13random_deviceC1Ev+0x96>
  96:	eb 07                	jmp    9f <_ZNSt13random_deviceC1Ev+0x9f>
  98:	f3 0f 1e fa          	endbr64 
  9c:	48 89 c3             	mov    %rax,%rbx
  9f:	48 8d 45 bf          	lea    -0x41(%rbp),%rax
  a3:	48 89 c7             	mov    %rax,%rdi
  a6:	e8 00 00 00 00       	call   ab <_ZNSt13random_deviceC1Ev+0xab>
  ab:	48 89 d8             	mov    %rbx,%rax
  ae:	48 89 c7             	mov    %rax,%rdi
  b1:	e8 00 00 00 00       	call   b6 <_ZNSt13random_deviceC1Ev+0xb6>
  b6:	e8 00 00 00 00       	call   bb <_ZNSt13random_deviceC1Ev+0xbb>
  bb:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  bf:	c9                   	leave  
  c0:	c3                   	ret    

Disassembly of section .text._ZNSt13random_deviceD2Ev:

0000000000000000 <_ZNSt13random_deviceD1Ev>:

    explicit
    random_device(const std::string& __token) { _M_init(__token); }

#if defined _GLIBCXX_USE_DEV_RANDOM
    ~random_device()
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    { _M_fini(); }
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZNSt13random_deviceD1Ev+0x1c>
  1c:	90                   	nop
  1d:	c9                   	leave  
  1e:	c3                   	ret    

Disassembly of section .text._ZNSt13random_deviceclEv:

0000000000000000 <_ZNSt13random_deviceclEv>:
      return 0.0;
#endif
    }

    result_type
    operator()()
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    { return this->_M_getval(); }
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZNSt13random_deviceclEv+0x1c>
  1c:	c9                   	leave  
  1d:	c3                   	ret    

Disassembly of section .text._ZNKSt6chrono8durationIlSt5ratioILl1ELl1000000000EEE5countEv:

0000000000000000 <_ZNKSt6chrono8durationIlSt5ratioILl1ELl1000000000EEE5countEv>:
	~duration() = default;
	duration& operator=(const duration&) = default;

	// 20.11.5.2 observer
	constexpr rep
	count() const
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
	{ return __r; }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	48 8b 00             	mov    (%rax),%rax
  13:	5d                   	pop    %rbp
  14:	c3                   	ret    

Disassembly of section .text._ZNSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EE12_Vector_implD2Ev:

0000000000000000 <_ZNSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EE12_Vector_implD1Ev>:
	  _M_copy_data(__x);
	  __x._M_copy_data(__tmp);
	}
      };

      struct _Vector_impl
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZNSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EE12_Vector_implD1Ev+0x1c>
  1c:	90                   	nop
  1d:	c9                   	leave  
  1e:	c3                   	ret    

Disassembly of section .text._ZNSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EEC2Ev:

0000000000000000 <_ZNSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EEC1Ev>:
      allocator_type
      get_allocator() const _GLIBCXX_NOEXCEPT
      { return allocator_type(_M_get_Tp_allocator()); }

#if __cplusplus >= 201103L
      _Vector_base() = default;
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZNSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EEC1Ev+0x1c>
  1c:	90                   	nop
  1d:	c9                   	leave  
  1e:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIN7KVStore7ssLevelESaIS1_EEC2Ev:

0000000000000000 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EEC1Ev>:

      /**
       *  @brief  Creates a %vector with no elements.
       */
#if __cplusplus >= 201103L
      vector() = default;
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EEC1Ev+0x1c>
  1c:	90                   	nop
  1d:	c9                   	leave  
  1e:	c3                   	ret    

Disassembly of section .text._ZNSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EE12_Vector_implD2Ev:

0000000000000000 <_ZNSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EE12_Vector_implD1Ev>:
      struct _Vector_impl
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZNSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EE12_Vector_implD1Ev+0x1c>
  1c:	90                   	nop
  1d:	c9                   	leave  
  1e:	c3                   	ret    

Disassembly of section .text._ZNSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EEC2Ev:

0000000000000000 <_ZNSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EEC1Ev>:
      _Vector_base() = default;
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZNSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EEC1Ev+0x1c>
  1c:	90                   	nop
  1d:	c9                   	leave  
  1e:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EEC2Ev:

0000000000000000 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EEC1Ev>:
      vector() = default;
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EEC1Ev+0x1c>
  1c:	90                   	nop
  1d:	c9                   	leave  
  1e:	c3                   	ret    

Disassembly of section .text._ZN8MemTableC2Ev:

0000000000000000 <_ZN8MemTableC1Ev>:
}
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	f2 0f 10 05 00 00 00 	movsd  0x0(%rip),%xmm0        # 1c <_ZN8MemTableC1Ev+0x1c>
  1b:	00 
  1c:	f2 0f 11 00          	movsd  %xmm0,(%rax)
  20:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  24:	48 83 c0 08          	add    $0x8,%rax
  28:	48 89 c7             	mov    %rax,%rdi
  2b:	e8 00 00 00 00       	call   30 <_ZN8MemTableC1Ev+0x30>
  30:	90                   	nop
  31:	c9                   	leave  
  32:	c3                   	ret    

Disassembly of section .text._ZN8MemTableD2Ev:

0000000000000000 <_ZN8MemTableD1Ev>:
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 83 c0 08          	add    $0x8,%rax
  18:	48 89 c7             	mov    %rax,%rdi
  1b:	e8 00 00 00 00       	call   20 <_ZN8MemTableD1Ev+0x20>
  20:	90                   	nop
  21:	c9                   	leave  
  22:	c3                   	ret    

Disassembly of section .text._ZNKSt6chrono8durationIlSt5ratioILl1ELl1000EEE5countEv:

0000000000000000 <_ZNKSt6chrono8durationIlSt5ratioILl1ELl1000EEE5countEv>:
	count() const
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
	{ return __r; }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	48 8b 00             	mov    (%rax),%rax
  13:	5d                   	pop    %rbp
  14:	c3                   	ret    

Disassembly of section .text._ZNKSt6chrono10time_pointINS_3_V212system_clockENS_8durationIlSt5ratioILl1ELl1000EEEEE16time_since_epochEv:

0000000000000000 <_ZNKSt6chrono10time_pointINS_3_V212system_clockENS_8durationIlSt5ratioILl1ELl1000EEEEE16time_since_epochEv>:
	  : __d(__t.time_since_epoch())
	  { }

	// observer
	constexpr duration
	time_since_epoch() const
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
	{ return __d; }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	48 8b 00             	mov    (%rax),%rax
  13:	5d                   	pop    %rbp
  14:	c3                   	ret    

Disassembly of section .text._ZNSt6chrono15time_point_castINS_8durationIlSt5ratioILl1ELl1000EEEENS_3_V212system_clockENS1_IlS2_ILl1ELl1000000000EEEEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueENS_10time_pointIT0_SB_EEE4typeERKNSD_ISE_T1_EE:

0000000000000000 <_ZNSt6chrono15time_point_castINS_8durationIlSt5ratioILl1ELl1000EEEENS_3_V212system_clockENS1_IlS2_ILl1ELl1000000000EEEEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueENS_10time_pointIT0_SB_EEE4typeERKNSD_ISE_T1_EE>:

    /// time_point_cast
    template<typename _ToDur, typename _Clock, typename _Dur>
      constexpr typename enable_if<__is_duration<_ToDur>::value,
				   time_point<_Clock, _ToDur>>::type
      time_point_cast(const time_point<_Clock, _Dur>& __t)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 30          	sub    $0x30,%rsp
   c:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  10:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  17:	00 00 
  19:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  1d:	31 c0                	xor    %eax,%eax
      {
	typedef time_point<_Clock, _ToDur>			__time_point;
	return __time_point(duration_cast<_ToDur>(__t.time_since_epoch()));
  1f:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  23:	48 89 c7             	mov    %rax,%rdi
  26:	e8 00 00 00 00       	call   2b <_ZNSt6chrono15time_point_castINS_8durationIlSt5ratioILl1ELl1000EEEENS_3_V212system_clockENS1_IlS2_ILl1ELl1000000000EEEEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueENS_10time_pointIT0_SB_EEE4typeERKNSD_ISE_T1_EE+0x2b>
  2b:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
  2f:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  33:	48 89 c7             	mov    %rax,%rdi
  36:	e8 00 00 00 00       	call   3b <_ZNSt6chrono15time_point_castINS_8durationIlSt5ratioILl1ELl1000EEEENS_3_V212system_clockENS1_IlS2_ILl1ELl1000000000EEEEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueENS_10time_pointIT0_SB_EEE4typeERKNSD_ISE_T1_EE+0x3b>
  3b:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  3f:	48 8d 55 e8          	lea    -0x18(%rbp),%rdx
  43:	48 8d 45 f0          	lea    -0x10(%rbp),%rax
  47:	48 89 d6             	mov    %rdx,%rsi
  4a:	48 89 c7             	mov    %rax,%rdi
  4d:	e8 00 00 00 00       	call   52 <_ZNSt6chrono15time_point_castINS_8durationIlSt5ratioILl1ELl1000EEEENS_3_V212system_clockENS1_IlS2_ILl1ELl1000000000EEEEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueENS_10time_pointIT0_SB_EEE4typeERKNSD_ISE_T1_EE+0x52>
  52:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
      }
  56:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  5a:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
  61:	00 00 
  63:	74 05                	je     6a <_ZNSt6chrono15time_point_castINS_8durationIlSt5ratioILl1ELl1000EEEENS_3_V212system_clockENS1_IlS2_ILl1ELl1000000000EEEEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueENS_10time_pointIT0_SB_EEE4typeERKNSD_ISE_T1_EE+0x6a>
  65:	e8 00 00 00 00       	call   6a <_ZNSt6chrono15time_point_castINS_8durationIlSt5ratioILl1ELl1000EEEENS_3_V212system_clockENS1_IlS2_ILl1ELl1000000000EEEEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueENS_10time_pointIT0_SB_EEE4typeERKNSD_ISE_T1_EE+0x6a>
  6a:	c9                   	leave  
  6b:	c3                   	ret    

Disassembly of section .text._ZNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIlSt5ratioILl1ELl1000EEEEEC1ERKS6_:

0000000000000000 <_ZNSt6chrono10time_pointINS_3_V212system_clockENS_8durationIlSt5ratioILl1ELl1000EEEEEC1ERKS6_>:
	constexpr explicit time_point(const duration& __dur)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
	: __d(__dur)
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  18:	48 8b 12             	mov    (%rdx),%rdx
  1b:	48 89 10             	mov    %rdx,(%rax)
	{ }
  1e:	90                   	nop
  1f:	5d                   	pop    %rbp
  20:	c3                   	ret    

Disassembly of section .text._ZNSt6chrono13duration_castINS_8durationIlSt5ratioILl1ELl1000EEEElS2_ILl1ELl1000000000EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE:

0000000000000000 <_ZNSt6chrono13duration_castINS_8durationIlSt5ratioILl1ELl1000EEEElS2_ILl1ELl1000000000EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE>:
      duration_cast(const duration<_Rep, _Period>& __d)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
	return __dc::__cast(__d);
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZNSt6chrono13duration_castINS_8durationIlSt5ratioILl1ELl1000EEEElS2_ILl1ELl1000000000EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE+0x1c>
      }
  1c:	c9                   	leave  
  1d:	c3                   	ret    

Disassembly of section .text._ZNKSt6chrono10time_pointINS_3_V212system_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEEE16time_since_epochEv:

0000000000000000 <_ZNKSt6chrono10time_pointINS_3_V212system_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEEE16time_since_epochEv>:
	time_since_epoch() const
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
	{ return __d; }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	48 8b 00             	mov    (%rax),%rax
  13:	5d                   	pop    %rbp
  14:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx14__alloc_traitsISaIcEcE27_S_propagate_on_move_assignEv:

0000000000000000 <_ZN9__gnu_cxx14__alloc_traitsISaIcEcE27_S_propagate_on_move_assignEv>:
    { std::__alloc_on_swap(__a, __b); }

    static constexpr bool _S_propagate_on_copy_assign()
    { return _Base_type::propagate_on_container_copy_assignment::value; }

    static constexpr bool _S_propagate_on_move_assign()
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
    { return _Base_type::propagate_on_container_move_assignment::value; }
   8:	b8 01 00 00 00       	mov    $0x1,%eax
   d:	5d                   	pop    %rbp
   e:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx14__alloc_traitsISaIcEcE15_S_always_equalEv:

0000000000000000 <_ZN9__gnu_cxx14__alloc_traitsISaIcEcE15_S_always_equalEv>:

    static constexpr bool _S_propagate_on_swap()
    { return _Base_type::propagate_on_container_swap::value; }

    static constexpr bool _S_always_equal()
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
    { return _Base_type::is_always_equal::value; }
   8:	b8 01 00 00 00       	mov    $0x1,%eax
   d:	5d                   	pop    %rbp
   e:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx11char_traitsIcE2eqERKcS3_:

0000000000000000 <_ZN9__gnu_cxx11char_traitsIcE2eqERKcS3_>:
      eq(const char_type& __c1, const char_type& __c2)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
      { return __c1 == __c2; }
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	0f b6 10             	movzbl (%rax),%edx
  17:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  1b:	0f b6 00             	movzbl (%rax),%eax
  1e:	38 c2                	cmp    %al,%dl
  20:	0f 94 c0             	sete   %al
  23:	5d                   	pop    %rbp
  24:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx11char_traitsIcE6lengthEPKc:

0000000000000000 <_ZN9__gnu_cxx11char_traitsIcE6lengthEPKc>:
    char_traits<_CharT>::
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 30          	sub    $0x30,%rsp
   c:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  10:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  17:	00 00 
  19:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  1d:	31 c0                	xor    %eax,%eax
      std::size_t __i = 0;
  1f:	48 c7 45 f0 00 00 00 	movq   $0x0,-0x10(%rbp)
  26:	00 
      while (!eq(__p[__i], char_type()))
  27:	eb 05                	jmp    2e <_ZN9__gnu_cxx11char_traitsIcE6lengthEPKc+0x2e>
        ++__i;
  29:	48 83 45 f0 01       	addq   $0x1,-0x10(%rbp)
      while (!eq(__p[__i], char_type()))
  2e:	c6 45 ef 00          	movb   $0x0,-0x11(%rbp)
  32:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
  36:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  3a:	48 01 c2             	add    %rax,%rdx
  3d:	48 8d 45 ef          	lea    -0x11(%rbp),%rax
  41:	48 89 c6             	mov    %rax,%rsi
  44:	48 89 d7             	mov    %rdx,%rdi
  47:	e8 00 00 00 00       	call   4c <_ZN9__gnu_cxx11char_traitsIcE6lengthEPKc+0x4c>
  4c:	83 f0 01             	xor    $0x1,%eax
  4f:	84 c0                	test   %al,%al
  51:	75 d6                	jne    29 <_ZN9__gnu_cxx11char_traitsIcE6lengthEPKc+0x29>
      return __i;
  53:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    }
  57:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  5b:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
  62:	00 00 
  64:	74 05                	je     6b <_ZN9__gnu_cxx11char_traitsIcE6lengthEPKc+0x6b>
  66:	e8 00 00 00 00       	call   6b <_ZN9__gnu_cxx11char_traitsIcE6lengthEPKc+0x6b>
  6b:	c9                   	leave  
  6c:	c3                   	ret    

Disassembly of section .text._ZSt4copyIPKcPcET0_T_S4_S3_:

0000000000000000 <_ZSt4copyIPKcPcET0_T_S4_S3_>:
    copy(_II __first, _II __last, _OI __result)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 28          	sub    $0x28,%rsp
   d:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  11:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  15:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
	     (std::__miter_base(__first), std::__miter_base(__last), __result);
  19:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  1d:	48 89 c7             	mov    %rax,%rdi
  20:	e8 00 00 00 00       	call   25 <_ZSt4copyIPKcPcET0_T_S4_S3_+0x25>
  25:	48 89 c3             	mov    %rax,%rbx
  28:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  2c:	48 89 c7             	mov    %rax,%rdi
  2f:	e8 00 00 00 00       	call   34 <_ZSt4copyIPKcPcET0_T_S4_S3_+0x34>
  34:	48 89 c1             	mov    %rax,%rcx
  37:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  3b:	48 89 c2             	mov    %rax,%rdx
  3e:	48 89 de             	mov    %rbx,%rsi
  41:	48 89 cf             	mov    %rcx,%rdi
  44:	e8 00 00 00 00       	call   49 <_ZSt4copyIPKcPcET0_T_S4_S3_+0x49>
    }
  49:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  4d:	c9                   	leave  
  4e:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx11char_traitsIcE4copyEPcPKcm:

0000000000000000 <_ZN9__gnu_cxx11char_traitsIcE4copyEPcPKcm>:
    char_traits<_CharT>::
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
      std::copy(__s2, __s2 + __n, __s1);
  18:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  1c:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  20:	48 8d 0c 02          	lea    (%rdx,%rax,1),%rcx
  24:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  28:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  2c:	48 89 ce             	mov    %rcx,%rsi
  2f:	48 89 c7             	mov    %rax,%rdi
  32:	e8 00 00 00 00       	call   37 <_ZN9__gnu_cxx11char_traitsIcE4copyEPcPKcm+0x37>
      return __s1;
  37:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    }
  3b:	c9                   	leave  
  3c:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx11char_traitsIcE4moveEPcPKcm:

0000000000000000 <_ZN9__gnu_cxx11char_traitsIcE4moveEPcPKcm>:
    char_traits<_CharT>::
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 30          	sub    $0x30,%rsp
   c:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  10:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  14:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
      if (__n == 0)
  18:	48 83 7d d8 00       	cmpq   $0x0,-0x28(%rbp)
  1d:	75 09                	jne    28 <_ZN9__gnu_cxx11char_traitsIcE4moveEPcPKcm+0x28>
	return __s1;
  1f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  23:	e9 8b 00 00 00       	jmp    b3 <_ZN9__gnu_cxx11char_traitsIcE4moveEPcPKcm+0xb3>
      if (std::is_constant_evaluated())
  28:	e8 00 00 00 00       	call   2d <_ZN9__gnu_cxx11char_traitsIcE4moveEPcPKcm+0x2d>
  2d:	84 c0                	test   %al,%al
  2f:	74 67                	je     98 <_ZN9__gnu_cxx11char_traitsIcE4moveEPcPKcm+0x98>
	  if (__s1 == __s2) // unlikely, but saves a lot of work
  31:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  35:	48 3b 45 e0          	cmp    -0x20(%rbp),%rax
  39:	75 06                	jne    41 <_ZN9__gnu_cxx11char_traitsIcE4moveEPcPKcm+0x41>
	    return __s1;
  3b:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  3f:	eb 72                	jmp    b3 <_ZN9__gnu_cxx11char_traitsIcE4moveEPcPKcm+0xb3>
	  char_type* __tmp = new char_type[__n];
  41:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  45:	48 89 c7             	mov    %rax,%rdi
  48:	e8 00 00 00 00       	call   4d <_ZN9__gnu_cxx11char_traitsIcE4moveEPcPKcm+0x4d>
  4d:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
	  copy(__tmp, __s2, __n);
  51:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
  55:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
  59:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  5d:	48 89 ce             	mov    %rcx,%rsi
  60:	48 89 c7             	mov    %rax,%rdi
  63:	e8 00 00 00 00       	call   68 <_ZN9__gnu_cxx11char_traitsIcE4moveEPcPKcm+0x68>
	  copy(__s1, __tmp, __n);
  68:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
  6c:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
  70:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  74:	48 89 ce             	mov    %rcx,%rsi
  77:	48 89 c7             	mov    %rax,%rdi
  7a:	e8 00 00 00 00       	call   7f <_ZN9__gnu_cxx11char_traitsIcE4moveEPcPKcm+0x7f>
	  delete[] __tmp;
  7f:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
  84:	74 0c                	je     92 <_ZN9__gnu_cxx11char_traitsIcE4moveEPcPKcm+0x92>
  86:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  8a:	48 89 c7             	mov    %rax,%rdi
  8d:	e8 00 00 00 00       	call   92 <_ZN9__gnu_cxx11char_traitsIcE4moveEPcPKcm+0x92>
	  return __s1;
  92:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  96:	eb 1b                	jmp    b3 <_ZN9__gnu_cxx11char_traitsIcE4moveEPcPKcm+0xb3>
      __builtin_memmove(__s1, __s2, __n * sizeof(char_type));
  98:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
  9c:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
  a0:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  a4:	48 89 ce             	mov    %rcx,%rsi
  a7:	48 89 c7             	mov    %rax,%rdi
  aa:	e8 00 00 00 00       	call   af <_ZN9__gnu_cxx11char_traitsIcE4moveEPcPKcm+0xaf>
      return __s1;
  af:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    }
  b3:	c9                   	leave  
  b4:	c3                   	ret    

Disassembly of section .text._ZSt6fill_nIPcmcET_S1_T0_RKT1_:

0000000000000000 <_ZSt6fill_nIPcmcET_S1_T0_RKT1_>:
  // DR 865. More algorithms that throw away information
  // DR 426. search_n(), fill_n(), and generate_n() with negative n
  template<typename _OI, typename _Size, typename _Tp>
    _GLIBCXX20_CONSTEXPR
    inline _OI
    fill_n(_OI __first, _Size __n, const _Tp& __value)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
    {
      // concept requirements
      __glibcxx_function_requires(_OutputIteratorConcept<_OI, _Tp>)

      return std::__fill_n_a(__first, std::__size_to_integer(__n), __value,
			       std::__iterator_category(__first));
  18:	48 8d 45 f8          	lea    -0x8(%rbp),%rax
  1c:	48 89 c7             	mov    %rax,%rdi
  1f:	e8 00 00 00 00       	call   24 <_ZSt6fill_nIPcmcET_S1_T0_RKT1_+0x24>
      return std::__fill_n_a(__first, std::__size_to_integer(__n), __value,
  24:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  28:	48 89 c7             	mov    %rax,%rdi
  2b:	e8 00 00 00 00       	call   30 <_ZSt6fill_nIPcmcET_S1_T0_RKT1_+0x30>
  30:	48 89 c1             	mov    %rax,%rcx
  33:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  37:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  3b:	48 89 ce             	mov    %rcx,%rsi
  3e:	48 89 c7             	mov    %rax,%rdi
  41:	e8 00 00 00 00       	call   46 <_ZSt6fill_nIPcmcET_S1_T0_RKT1_+0x46>
    }
  46:	c9                   	leave  
  47:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx11char_traitsIcE6assignEPcmc:

0000000000000000 <_ZN9__gnu_cxx11char_traitsIcE6assignEPcmc>:
    char_traits<_CharT>::
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	89 d0                	mov    %edx,%eax
  16:	88 45 ec             	mov    %al,-0x14(%rbp)
      std::fill_n(__s, __n, __a);
  19:	48 8d 55 ec          	lea    -0x14(%rbp),%rdx
  1d:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
  21:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  25:	48 89 ce             	mov    %rcx,%rsi
  28:	48 89 c7             	mov    %rax,%rdi
  2b:	e8 00 00 00 00       	call   30 <_ZN9__gnu_cxx11char_traitsIcE6assignEPcmc+0x30>
      return __s;
  30:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    }
  34:	c9                   	leave  
  35:	c3                   	ret    

Disassembly of section .text._ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv:

0000000000000000 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv>:
      c_str() const _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
      { return _M_data(); }
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv+0x1c>
  1c:	c9                   	leave  
  1d:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD1Ev>:
      struct _Alloc_hider : allocator_type // TODO check __is_final
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD1Ev+0x1c>
  1c:	90                   	nop
  1d:	c9                   	leave  
  1e:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEmcRKS3_:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEmcRKS3_>:
      basic_string(size_type __n, _CharT __c, const _Alloc& __a = _Alloc())
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 28          	sub    $0x28,%rsp
   d:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  11:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  15:	89 d0                	mov    %edx,%eax
  17:	48 89 4d d0          	mov    %rcx,-0x30(%rbp)
  1b:	88 45 dc             	mov    %al,-0x24(%rbp)
      : _M_dataplus(_M_local_data(), __a)
  1e:	48 8b 5d e8          	mov    -0x18(%rbp),%rbx
  22:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  26:	48 89 c7             	mov    %rax,%rdi
  29:	e8 00 00 00 00       	call   2e <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEmcRKS3_+0x2e>
  2e:	48 89 c1             	mov    %rax,%rcx
  31:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  35:	48 89 c2             	mov    %rax,%rdx
  38:	48 89 ce             	mov    %rcx,%rsi
  3b:	48 89 df             	mov    %rbx,%rdi
  3e:	e8 00 00 00 00       	call   43 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEmcRKS3_+0x43>
      { _M_construct(__n, __c); }
  43:	0f be 55 dc          	movsbl -0x24(%rbp),%edx
  47:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
  4b:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  4f:	48 89 ce             	mov    %rcx,%rsi
  52:	48 89 c7             	mov    %rax,%rdi
  55:	e8 00 00 00 00       	call   5a <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEmcRKS3_+0x5a>
  5a:	eb 1e                	jmp    7a <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEmcRKS3_+0x7a>
  5c:	f3 0f 1e fa          	endbr64 
  60:	48 89 c3             	mov    %rax,%rbx
  63:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  67:	48 89 c7             	mov    %rax,%rdi
  6a:	e8 00 00 00 00       	call   6f <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEmcRKS3_+0x6f>
  6f:	48 89 d8             	mov    %rbx,%rax
  72:	48 89 c7             	mov    %rax,%rdi
  75:	e8 00 00 00 00       	call   7a <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEmcRKS3_+0x7a>
  7a:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  7e:	c9                   	leave  
  7f:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev>:
      ~basic_string()
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
      { _M_dispose(); }
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev+0x1c>
  1c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  20:	48 89 c7             	mov    %rax,%rdi
  23:	e8 00 00 00 00       	call   28 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev+0x28>
  28:	90                   	nop
  29:	c9                   	leave  
  2a:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm>:
      operator[](size_type __pos)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
	__glibcxx_assert(__pos <= size());
  14:	b8 00 00 00 00       	mov    $0x0,%eax
  19:	84 c0                	test   %al,%al
	return _M_data()[__pos];
  1b:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  1f:	48 89 c7             	mov    %rax,%rdi
  22:	e8 00 00 00 00       	call   27 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm+0x27>
  27:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  2b:	48 01 d0             	add    %rdx,%rax
      }
  2e:	c9                   	leave  
  2f:	c3                   	ret    

Disassembly of section .text._ZNSt8__detail18__to_chars_10_implIjEEvPcjT_:

0000000000000000 <_ZNSt8__detail18__to_chars_10_implIjEEvPcjT_>:
  // Write an unsigned integer value to the range [first,first+len).
  // The caller is required to provide a buffer of exactly the right size
  // (which can be determined by the __to_chars_len function).
  template<typename _Tp>
    void
    __to_chars_10_impl(char* __first, unsigned __len, _Tp __val) noexcept
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
   c:	89 75 e4             	mov    %esi,-0x1c(%rbp)
   f:	89 55 e0             	mov    %edx,-0x20(%rbp)
	"0001020304050607080910111213141516171819"
	"2021222324252627282930313233343536373839"
	"4041424344454647484950515253545556575859"
	"6061626364656667686970717273747576777879"
	"8081828384858687888990919293949596979899";
      unsigned __pos = __len - 1;
  12:	8b 45 e4             	mov    -0x1c(%rbp),%eax
  15:	83 e8 01             	sub    $0x1,%eax
  18:	89 45 f4             	mov    %eax,-0xc(%rbp)
      while (__val >= 100)
  1b:	eb 77                	jmp    94 <_ZNSt8__detail18__to_chars_10_implIjEEvPcjT_+0x94>
	{
	  auto const __num = (__val % 100) * 2;
  1d:	8b 55 e0             	mov    -0x20(%rbp),%edx
  20:	89 d0                	mov    %edx,%eax
  22:	48 69 c0 1f 85 eb 51 	imul   $0x51eb851f,%rax,%rax
  29:	48 c1 e8 20          	shr    $0x20,%rax
  2d:	c1 e8 05             	shr    $0x5,%eax
  30:	6b c8 64             	imul   $0x64,%eax,%ecx
  33:	89 d0                	mov    %edx,%eax
  35:	29 c8                	sub    %ecx,%eax
  37:	01 c0                	add    %eax,%eax
  39:	89 45 fc             	mov    %eax,-0x4(%rbp)
	  __val /= 100;
  3c:	8b 45 e0             	mov    -0x20(%rbp),%eax
  3f:	89 c0                	mov    %eax,%eax
  41:	48 69 c0 1f 85 eb 51 	imul   $0x51eb851f,%rax,%rax
  48:	48 c1 e8 20          	shr    $0x20,%rax
  4c:	c1 e8 05             	shr    $0x5,%eax
  4f:	89 45 e0             	mov    %eax,-0x20(%rbp)
	  __first[__pos] = __digits[__num + 1];
  52:	8b 45 fc             	mov    -0x4(%rbp),%eax
  55:	8d 48 01             	lea    0x1(%rax),%ecx
  58:	8b 55 f4             	mov    -0xc(%rbp),%edx
  5b:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  5f:	48 01 c2             	add    %rax,%rdx
  62:	89 c9                	mov    %ecx,%ecx
  64:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 6b <_ZNSt8__detail18__to_chars_10_implIjEEvPcjT_+0x6b>
  6b:	0f b6 04 01          	movzbl (%rcx,%rax,1),%eax
  6f:	88 02                	mov    %al,(%rdx)
	  __first[__pos - 1] = __digits[__num];
  71:	8b 45 f4             	mov    -0xc(%rbp),%eax
  74:	83 e8 01             	sub    $0x1,%eax
  77:	89 c2                	mov    %eax,%edx
  79:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  7d:	48 01 c2             	add    %rax,%rdx
  80:	8b 45 fc             	mov    -0x4(%rbp),%eax
  83:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # 8a <_ZNSt8__detail18__to_chars_10_implIjEEvPcjT_+0x8a>
  8a:	0f b6 04 08          	movzbl (%rax,%rcx,1),%eax
  8e:	88 02                	mov    %al,(%rdx)
	  __pos -= 2;
  90:	83 6d f4 02          	subl   $0x2,-0xc(%rbp)
      while (__val >= 100)
  94:	83 7d e0 63          	cmpl   $0x63,-0x20(%rbp)
  98:	77 83                	ja     1d <_ZNSt8__detail18__to_chars_10_implIjEEvPcjT_+0x1d>
	}
      if (__val >= 10)
  9a:	83 7d e0 09          	cmpl   $0x9,-0x20(%rbp)
  9e:	76 3b                	jbe    db <_ZNSt8__detail18__to_chars_10_implIjEEvPcjT_+0xdb>
	{
	  auto const __num = __val * 2;
  a0:	8b 45 e0             	mov    -0x20(%rbp),%eax
  a3:	01 c0                	add    %eax,%eax
  a5:	89 45 f8             	mov    %eax,-0x8(%rbp)
	  __first[1] = __digits[__num + 1];
  a8:	8b 45 f8             	mov    -0x8(%rbp),%eax
  ab:	8d 48 01             	lea    0x1(%rax),%ecx
  ae:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  b2:	48 8d 50 01          	lea    0x1(%rax),%rdx
  b6:	89 c9                	mov    %ecx,%ecx
  b8:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # bf <_ZNSt8__detail18__to_chars_10_implIjEEvPcjT_+0xbf>
  bf:	0f b6 04 01          	movzbl (%rcx,%rax,1),%eax
  c3:	88 02                	mov    %al,(%rdx)
	  __first[0] = __digits[__num];
  c5:	8b 45 f8             	mov    -0x8(%rbp),%eax
  c8:	48 8d 15 00 00 00 00 	lea    0x0(%rip),%rdx        # cf <_ZNSt8__detail18__to_chars_10_implIjEEvPcjT_+0xcf>
  cf:	0f b6 14 10          	movzbl (%rax,%rdx,1),%edx
  d3:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  d7:	88 10                	mov    %dl,(%rax)
	}
      else
	__first[0] = '0' + __val;
    }
  d9:	eb 0e                	jmp    e9 <_ZNSt8__detail18__to_chars_10_implIjEEvPcjT_+0xe9>
	__first[0] = '0' + __val;
  db:	8b 45 e0             	mov    -0x20(%rbp),%eax
  de:	83 c0 30             	add    $0x30,%eax
  e1:	89 c2                	mov    %eax,%edx
  e3:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  e7:	88 10                	mov    %dl,(%rax)
    }
  e9:	90                   	nop
  ea:	5d                   	pop    %rbp
  eb:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EOS4_:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_>:
      basic_string(basic_string&& __str) noexcept
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	41 54                	push   %r12
   a:	53                   	push   %rbx
   b:	48 83 ec 10          	sub    $0x10,%rsp
   f:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  13:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
      : _M_dataplus(_M_local_data(), std::move(__str._M_get_allocator()))
  17:	48 8b 5d e8          	mov    -0x18(%rbp),%rbx
  1b:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  1f:	48 89 c7             	mov    %rax,%rdi
  22:	e8 00 00 00 00       	call   27 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_+0x27>
  27:	48 89 c7             	mov    %rax,%rdi
  2a:	e8 00 00 00 00       	call   2f <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_+0x2f>
  2f:	49 89 c4             	mov    %rax,%r12
  32:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  36:	48 89 c7             	mov    %rax,%rdi
  39:	e8 00 00 00 00       	call   3e <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_+0x3e>
  3e:	4c 89 e2             	mov    %r12,%rdx
  41:	48 89 c6             	mov    %rax,%rsi
  44:	48 89 df             	mov    %rbx,%rdi
  47:	e8 00 00 00 00       	call   4c <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_+0x4c>
	if (__str._M_is_local())
  4c:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  50:	48 89 c7             	mov    %rax,%rdi
  53:	e8 00 00 00 00       	call   58 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_+0x58>
  58:	84 c0                	test   %al,%al
  5a:	74 22                	je     7e <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_+0x7e>
	    traits_type::copy(_M_local_buf, __str._M_local_buf,
  5c:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  60:	48 8d 48 10          	lea    0x10(%rax),%rcx
  64:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  68:	48 83 c0 10          	add    $0x10,%rax
  6c:	ba 10 00 00 00       	mov    $0x10,%edx
  71:	48 89 ce             	mov    %rcx,%rsi
  74:	48 89 c7             	mov    %rax,%rdi
  77:	e8 00 00 00 00       	call   7c <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_+0x7c>
  7c:	eb 35                	jmp    b3 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_+0xb3>
	    _M_data(__str._M_data());
  7e:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  82:	48 89 c7             	mov    %rax,%rdi
  85:	e8 00 00 00 00       	call   8a <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_+0x8a>
  8a:	48 89 c2             	mov    %rax,%rdx
  8d:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  91:	48 89 d6             	mov    %rdx,%rsi
  94:	48 89 c7             	mov    %rax,%rdi
  97:	e8 00 00 00 00       	call   9c <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_+0x9c>
	    _M_capacity(__str._M_allocated_capacity);
  9c:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  a0:	48 8b 50 10          	mov    0x10(%rax),%rdx
  a4:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  a8:	48 89 d6             	mov    %rdx,%rsi
  ab:	48 89 c7             	mov    %rax,%rdi
  ae:	e8 00 00 00 00       	call   b3 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_+0xb3>
	_M_length(__str.length());
  b3:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  b7:	48 89 c7             	mov    %rax,%rdi
  ba:	e8 00 00 00 00       	call   bf <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_+0xbf>
  bf:	48 89 c2             	mov    %rax,%rdx
  c2:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  c6:	48 89 d6             	mov    %rdx,%rsi
  c9:	48 89 c7             	mov    %rax,%rdi
  cc:	e8 00 00 00 00       	call   d1 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_+0xd1>
	__str._M_data(__str._M_local_data());
  d1:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  d5:	48 89 c7             	mov    %rax,%rdi
  d8:	e8 00 00 00 00       	call   dd <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_+0xdd>
  dd:	48 89 c2             	mov    %rax,%rdx
  e0:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  e4:	48 89 d6             	mov    %rdx,%rsi
  e7:	48 89 c7             	mov    %rax,%rdi
  ea:	e8 00 00 00 00       	call   ef <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_+0xef>
	__str._M_set_length(0);
  ef:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  f3:	be 00 00 00 00       	mov    $0x0,%esi
  f8:	48 89 c7             	mov    %rax,%rdi
  fb:	e8 00 00 00 00       	call   100 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_+0x100>
      }
 100:	90                   	nop
 101:	48 83 c4 10          	add    $0x10,%rsp
 105:	5b                   	pop    %rbx
 106:	41 5c                	pop    %r12
 108:	5d                   	pop    %rbp
 109:	c3                   	ret    

Disassembly of section .text._ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv:

0000000000000000 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv>:
      size() const _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
      { return _M_string_length; }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	48 8b 40 08          	mov    0x8(%rax),%rax
  14:	5d                   	pop    %rbp
  15:	c3                   	ret    

Disassembly of section .text._ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6lengthEv:

0000000000000000 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6lengthEv>:
      length() const _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
      { return _M_string_length; }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	48 8b 40 08          	mov    0x8(%rax),%rax
  14:	5d                   	pop    %rbp
  15:	c3                   	ret    

Disassembly of section .text._ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EERKS8_PKS5_:

0000000000000000 <_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EERKS8_PKS5_>:
    operator+(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 28          	sub    $0x28,%rsp
   d:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  11:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  15:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
      basic_string<_CharT, _Traits, _Alloc> __str(__lhs);
  19:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
  1d:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  21:	48 89 d6             	mov    %rdx,%rsi
  24:	48 89 c7             	mov    %rax,%rdi
  27:	e8 00 00 00 00       	call   2c <_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EERKS8_PKS5_+0x2c>
      __str.append(__rhs);
  2c:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
  30:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  34:	48 89 d6             	mov    %rdx,%rsi
  37:	48 89 c7             	mov    %rax,%rdi
  3a:	e8 00 00 00 00       	call   3f <_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EERKS8_PKS5_+0x3f>
      return __str;
  3f:	eb 1e                	jmp    5f <_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EERKS8_PKS5_+0x5f>
  41:	f3 0f 1e fa          	endbr64 
    }
  45:	48 89 c3             	mov    %rax,%rbx
  48:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  4c:	48 89 c7             	mov    %rax,%rdi
  4f:	e8 00 00 00 00       	call   54 <_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EERKS8_PKS5_+0x54>
  54:	48 89 d8             	mov    %rbx,%rax
  57:	48 89 c7             	mov    %rax,%rdi
  5a:	e8 00 00 00 00       	call   5f <_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EERKS8_PKS5_+0x5f>
  5f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  63:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  67:	c9                   	leave  
  68:	c3                   	ret    

Disassembly of section .text._ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_:

0000000000000000 <_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_>:
    operator+(basic_string<_CharT, _Traits, _Alloc>&& __lhs,
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 38          	sub    $0x38,%rsp
   d:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  11:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
  15:	48 89 55 c8          	mov    %rdx,-0x38(%rbp)
      bool __use_rhs = false;
  19:	c6 45 e7 00          	movb   $0x0,-0x19(%rbp)
	__use_rhs = true;
  1d:	c6 45 e7 01          	movb   $0x1,-0x19(%rbp)
      if (__use_rhs)
  21:	80 7d e7 00          	cmpb   $0x0,-0x19(%rbp)
  25:	0f 84 87 00 00 00    	je     b2 <_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_+0xb2>
	  const auto __size = __lhs.size() + __rhs.size();
  2b:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  2f:	48 89 c7             	mov    %rax,%rdi
  32:	e8 00 00 00 00       	call   37 <_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_+0x37>
  37:	48 89 c3             	mov    %rax,%rbx
  3a:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  3e:	48 89 c7             	mov    %rax,%rdi
  41:	e8 00 00 00 00       	call   46 <_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_+0x46>
  46:	48 01 d8             	add    %rbx,%rax
  49:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
	  if (__size > __lhs.capacity() && __size <= __rhs.capacity())
  4d:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  51:	48 89 c7             	mov    %rax,%rdi
  54:	e8 00 00 00 00       	call   59 <_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_+0x59>
  59:	48 39 45 e8          	cmp    %rax,-0x18(%rbp)
  5d:	76 19                	jbe    78 <_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_+0x78>
  5f:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  63:	48 89 c7             	mov    %rax,%rdi
  66:	e8 00 00 00 00       	call   6b <_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_+0x6b>
  6b:	48 39 45 e8          	cmp    %rax,-0x18(%rbp)
  6f:	77 07                	ja     78 <_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_+0x78>
  71:	b8 01 00 00 00       	mov    $0x1,%eax
  76:	eb 05                	jmp    7d <_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_+0x7d>
  78:	b8 00 00 00 00       	mov    $0x0,%eax
  7d:	84 c0                	test   %al,%al
  7f:	74 31                	je     b2 <_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_+0xb2>
	    return std::move(__rhs.insert(0, __lhs));
  81:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
  85:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  89:	be 00 00 00 00       	mov    $0x0,%esi
  8e:	48 89 c7             	mov    %rax,%rdi
  91:	e8 00 00 00 00       	call   96 <_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_+0x96>
  96:	48 89 c7             	mov    %rax,%rdi
  99:	e8 00 00 00 00       	call   9e <_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_+0x9e>
  9e:	48 89 c2             	mov    %rax,%rdx
  a1:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  a5:	48 89 d6             	mov    %rdx,%rsi
  a8:	48 89 c7             	mov    %rax,%rdi
  ab:	e8 00 00 00 00       	call   b0 <_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_+0xb0>
  b0:	eb 2d                	jmp    df <_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_+0xdf>
      return std::move(__lhs.append(__rhs));
  b2:	48 8b 55 c8          	mov    -0x38(%rbp),%rdx
  b6:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  ba:	48 89 d6             	mov    %rdx,%rsi
  bd:	48 89 c7             	mov    %rax,%rdi
  c0:	e8 00 00 00 00       	call   c5 <_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_+0xc5>
  c5:	48 89 c7             	mov    %rax,%rdi
  c8:	e8 00 00 00 00       	call   cd <_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_+0xcd>
  cd:	48 89 c2             	mov    %rax,%rdx
  d0:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  d4:	48 89 d6             	mov    %rdx,%rsi
  d7:	48 89 c7             	mov    %rax,%rdi
  da:	e8 00 00 00 00       	call   df <_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_+0xdf>
    }
  df:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  e3:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  e7:	c9                   	leave  
  e8:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEPKcRKS3_:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_>:
      basic_string(const _CharT* __s, const _Alloc& __a = _Alloc())
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 48          	sub    $0x48,%rsp
   d:	48 89 7d c8          	mov    %rdi,-0x38(%rbp)
  11:	48 89 75 c0          	mov    %rsi,-0x40(%rbp)
  15:	48 89 55 b8          	mov    %rdx,-0x48(%rbp)
  19:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  20:	00 00 
  22:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  26:	31 c0                	xor    %eax,%eax
      : _M_dataplus(_M_local_data(), __a)
  28:	48 8b 5d c8          	mov    -0x38(%rbp),%rbx
  2c:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  30:	48 89 c7             	mov    %rax,%rdi
  33:	e8 00 00 00 00       	call   38 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_+0x38>
  38:	48 89 c1             	mov    %rax,%rcx
  3b:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  3f:	48 89 c2             	mov    %rax,%rdx
  42:	48 89 ce             	mov    %rcx,%rsi
  45:	48 89 df             	mov    %rbx,%rdi
  48:	e8 00 00 00 00       	call   4d <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_+0x4d>
	const _CharT* __end = __s ? __s + traits_type::length(__s)
  4d:	48 83 7d c0 00       	cmpq   $0x0,-0x40(%rbp)
  52:	74 15                	je     69 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_+0x69>
  54:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
  58:	48 89 c7             	mov    %rax,%rdi
  5b:	e8 00 00 00 00       	call   60 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_+0x60>
  60:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
  64:	48 01 d0             	add    %rdx,%rax
  67:	eb 05                	jmp    6e <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_+0x6e>
  69:	b8 01 00 00 00       	mov    $0x1,%eax
  6e:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
	_M_construct(__s, __end, random_access_iterator_tag());
  72:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
  76:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
  7a:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  7e:	48 89 ce             	mov    %rcx,%rsi
  81:	48 89 c7             	mov    %rax,%rdi
  84:	e8 00 00 00 00       	call   89 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_+0x89>
      }
  89:	eb 1e                	jmp    a9 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_+0xa9>
  8b:	f3 0f 1e fa          	endbr64 
  8f:	48 89 c3             	mov    %rax,%rbx
  92:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  96:	48 89 c7             	mov    %rax,%rdi
  99:	e8 00 00 00 00       	call   9e <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_+0x9e>
  9e:	48 89 d8             	mov    %rbx,%rax
  a1:	48 89 c7             	mov    %rax,%rdi
  a4:	e8 00 00 00 00       	call   a9 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_+0xa9>
  a9:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  ad:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
  b4:	00 00 
  b6:	74 05                	je     bd <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_+0xbd>
  b8:	e8 00 00 00 00       	call   bd <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEPKcRKS3_+0xbd>
  bd:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  c1:	c9                   	leave  
  c2:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2Ev:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev>:
      basic_string()
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 28          	sub    $0x28,%rsp
   d:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  11:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  18:	00 00 
  1a:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  1e:	31 c0                	xor    %eax,%eax
      : _M_dataplus(_M_local_data())
  20:	48 8b 5d d8          	mov    -0x28(%rbp),%rbx
  24:	48 8d 45 e7          	lea    -0x19(%rbp),%rax
  28:	48 89 c7             	mov    %rax,%rdi
  2b:	e8 00 00 00 00       	call   30 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev+0x30>
  30:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  34:	48 89 c7             	mov    %rax,%rdi
  37:	e8 00 00 00 00       	call   3c <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev+0x3c>
  3c:	48 89 c1             	mov    %rax,%rcx
  3f:	48 8d 45 e7          	lea    -0x19(%rbp),%rax
  43:	48 89 c2             	mov    %rax,%rdx
  46:	48 89 ce             	mov    %rcx,%rsi
  49:	48 89 df             	mov    %rbx,%rdi
  4c:	e8 00 00 00 00       	call   51 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev+0x51>
  51:	48 8d 45 e7          	lea    -0x19(%rbp),%rax
  55:	48 89 c7             	mov    %rax,%rdi
  58:	e8 00 00 00 00       	call   5d <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev+0x5d>
      { _M_set_length(0); }
  5d:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  61:	be 00 00 00 00       	mov    $0x0,%esi
  66:	48 89 c7             	mov    %rax,%rdi
  69:	e8 00 00 00 00       	call   6e <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev+0x6e>
  6e:	90                   	nop
  6f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  73:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
  7a:	00 00 
  7c:	74 05                	je     83 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev+0x83>
  7e:	e8 00 00 00 00       	call   83 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev+0x83>
  83:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  87:	c9                   	leave  
  88:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEpLERKS4_:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEpLERKS4_>:
      operator+=(const basic_string& __str)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
      { return this->append(__str); }
  14:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  18:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  1c:	48 89 d6             	mov    %rdx,%rsi
  1f:	48 89 c7             	mov    %rax,%rdi
  22:	e8 00 00 00 00       	call   27 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEpLERKS4_+0x27>
  27:	c9                   	leave  
  28:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2ERKS4_:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_>:
      basic_string(const basic_string& __str)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 28          	sub    $0x28,%rsp
   d:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  11:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
  15:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  1c:	00 00 
  1e:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  22:	31 c0                	xor    %eax,%eax
      : _M_dataplus(_M_local_data(),
  24:	48 8b 5d d8          	mov    -0x28(%rbp),%rbx
		    _Alloc_traits::_S_select_on_copy(__str._M_get_allocator()))
  28:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  2c:	48 89 c7             	mov    %rax,%rdi
  2f:	e8 00 00 00 00       	call   34 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_+0x34>
  34:	48 89 c2             	mov    %rax,%rdx
      : _M_dataplus(_M_local_data(),
  37:	48 8d 45 e7          	lea    -0x19(%rbp),%rax
  3b:	48 89 d6             	mov    %rdx,%rsi
  3e:	48 89 c7             	mov    %rax,%rdi
  41:	e8 00 00 00 00       	call   46 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_+0x46>
  46:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  4a:	48 89 c7             	mov    %rax,%rdi
  4d:	e8 00 00 00 00       	call   52 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_+0x52>
  52:	48 89 c1             	mov    %rax,%rcx
  55:	48 8d 45 e7          	lea    -0x19(%rbp),%rax
  59:	48 89 c2             	mov    %rax,%rdx
  5c:	48 89 ce             	mov    %rcx,%rsi
  5f:	48 89 df             	mov    %rbx,%rdi
  62:	e8 00 00 00 00       	call   67 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_+0x67>
  67:	48 8d 45 e7          	lea    -0x19(%rbp),%rax
  6b:	48 89 c7             	mov    %rax,%rdi
  6e:	e8 00 00 00 00       	call   73 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_+0x73>
      { _M_construct(__str._M_data(), __str._M_data() + __str.length()); }
  73:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  77:	48 89 c7             	mov    %rax,%rdi
  7a:	e8 00 00 00 00       	call   7f <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_+0x7f>
  7f:	48 89 c3             	mov    %rax,%rbx
  82:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  86:	48 89 c7             	mov    %rax,%rdi
  89:	e8 00 00 00 00       	call   8e <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_+0x8e>
  8e:	48 01 c3             	add    %rax,%rbx
  91:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  95:	48 89 c7             	mov    %rax,%rdi
  98:	e8 00 00 00 00       	call   9d <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_+0x9d>
  9d:	48 89 c1             	mov    %rax,%rcx
  a0:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  a4:	48 89 da             	mov    %rbx,%rdx
  a7:	48 89 ce             	mov    %rcx,%rsi
  aa:	48 89 c7             	mov    %rax,%rdi
  ad:	e8 00 00 00 00       	call   b2 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_+0xb2>
  b2:	eb 1e                	jmp    d2 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_+0xd2>
  b4:	f3 0f 1e fa          	endbr64 
  b8:	48 89 c3             	mov    %rax,%rbx
  bb:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  bf:	48 89 c7             	mov    %rax,%rdi
  c2:	e8 00 00 00 00       	call   c7 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_+0xc7>
  c7:	48 89 d8             	mov    %rbx,%rax
  ca:	48 89 c7             	mov    %rax,%rdi
  cd:	e8 00 00 00 00       	call   d2 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_+0xd2>
  d2:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  d6:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
  dd:	00 00 
  df:	74 05                	je     e6 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_+0xe6>
  e1:	e8 00 00 00 00       	call   e6 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_+0xe6>
  e6:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  ea:	c9                   	leave  
  eb:	c3                   	ret    

Disassembly of section .text._ZNKSt6vectorIPN8MemTable8QuadlistESaIS2_EE4sizeEv:

0000000000000000 <_ZNKSt6vectorIPN8MemTable8QuadlistESaIS2_EE4sizeEv>:
#endif

      // [23.2.4.2] capacity
      /**  Returns the number of elements in the %vector.  */
      size_type
      size() const _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
      { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	48 8b 50 08          	mov    0x8(%rax),%rdx
  14:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  18:	48 8b 08             	mov    (%rax),%rcx
  1b:	48 89 d0             	mov    %rdx,%rax
  1e:	48 29 c8             	sub    %rcx,%rax
  21:	48 c1 f8 03          	sar    $0x3,%rax
  25:	5d                   	pop    %rbp
  26:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE9push_backEOS2_:

0000000000000000 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE9push_backEOS2_>:
	  _M_realloc_insert(end(), __x);
      }

#if __cplusplus >= 201103L
      void
      push_back(value_type&& __x)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
      { emplace_back(std::move(__x)); }
  14:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  18:	48 89 c7             	mov    %rax,%rdi
  1b:	e8 00 00 00 00       	call   20 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE9push_backEOS2_+0x20>
  20:	48 89 c2             	mov    %rax,%rdx
  23:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  27:	48 89 d6             	mov    %rdx,%rsi
  2a:	48 89 c7             	mov    %rax,%rdi
  2d:	e8 00 00 00 00       	call   32 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE9push_backEOS2_+0x32>
  32:	90                   	nop
  33:	c9                   	leave  
  34:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EEixEm:

0000000000000000 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EEixEm>:
      operator[](size_type __n) _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
	return *(this->_M_impl._M_start + __n);
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 8b 10             	mov    (%rax),%rdx
  17:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  1b:	48 c1 e0 03          	shl    $0x3,%rax
  1f:	48 01 d0             	add    %rdx,%rax
      }
  22:	5d                   	pop    %rbp
  23:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSERKS4_:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSERKS4_>:
      operator=(const basic_string& __str)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
	return this->assign(__str);
  14:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  18:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  1c:	48 89 d6             	mov    %rdx,%rsi
  1f:	48 89 c7             	mov    %rax,%rdi
  22:	e8 00 00 00 00       	call   27 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSERKS4_+0x27>
      }
  27:	c9                   	leave  
  28:	c3                   	ret    

Disassembly of section .text._ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEC2Em:

0000000000000000 <_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEC1Em>:
      mersenne_twister_engine(result_type __sd)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
      { seed(__sd); }
  14:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  18:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  1c:	48 89 d6             	mov    %rdx,%rsi
  1f:	48 89 c7             	mov    %rax,%rdi
  22:	e8 00 00 00 00       	call   27 <_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEC1Em+0x27>
  27:	90                   	nop
  28:	c9                   	leave  
  29:	c3                   	ret    

Disassembly of section .text._ZNSt25uniform_real_distributionIdEC2Edd:

0000000000000000 <_ZNSt25uniform_real_distributionIdEC1Edd>:
       *
       * @param __a [IN]  The lower bound of the distribution.
       * @param __b [IN]  The upper bound of the distribution.
       */
      explicit
      uniform_real_distribution(_RealType __a, _RealType __b = _RealType(1))
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	f2 0f 11 45 f0       	movsd  %xmm0,-0x10(%rbp)
  15:	f2 0f 11 4d e8       	movsd  %xmm1,-0x18(%rbp)
      : _M_param(__a, __b)
  1a:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  1e:	f2 0f 10 45 e8       	movsd  -0x18(%rbp),%xmm0
  23:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  27:	66 0f 28 c8          	movapd %xmm0,%xmm1
  2b:	66 48 0f 6e c2       	movq   %rdx,%xmm0
  30:	48 89 c7             	mov    %rax,%rdi
  33:	e8 00 00 00 00       	call   38 <_ZNSt25uniform_real_distributionIdEC1Edd+0x38>
      { }
  38:	90                   	nop
  39:	c9                   	leave  
  3a:	c3                   	ret    

Disassembly of section .text._ZNSt25uniform_real_distributionIdEclISt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEEEdRT_:

0000000000000000 <_ZNSt25uniform_real_distributionIdEclISt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEEEdRT_>:
      /**
       * @brief Generating functions.
       */
      template<typename _UniformRandomNumberGenerator>
	result_type
	operator()(_UniformRandomNumberGenerator& __urng)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
        { return this->operator()(__urng, _M_param); }
  14:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  18:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
  1c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  20:	48 89 ce             	mov    %rcx,%rsi
  23:	48 89 c7             	mov    %rax,%rdi
  26:	e8 00 00 00 00       	call   2b <_ZNSt25uniform_real_distributionIdEclISt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEEEdRT_+0x2b>
  2b:	66 48 0f 7e c0       	movq   %xmm0,%rax
  30:	66 48 0f 6e c0       	movq   %rax,%xmm0
  35:	c9                   	leave  
  36:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE9push_backERKS2_:

0000000000000000 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE9push_backERKS2_>:
      push_back(const value_type& __x)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
	if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
  14:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  18:	48 8b 50 08          	mov    0x8(%rax),%rdx
  1c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  20:	48 8b 40 10          	mov    0x10(%rax),%rax
  24:	48 39 c2             	cmp    %rax,%rdx
  27:	74 31                	je     5a <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE9push_backERKS2_+0x5a>
	    _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish,
  29:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  2d:	48 8b 48 08          	mov    0x8(%rax),%rcx
  31:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  35:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  39:	48 89 ce             	mov    %rcx,%rsi
  3c:	48 89 c7             	mov    %rax,%rdi
  3f:	e8 00 00 00 00       	call   44 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE9push_backERKS2_+0x44>
	    ++this->_M_impl._M_finish;
  44:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  48:	48 8b 40 08          	mov    0x8(%rax),%rax
  4c:	48 8d 50 08          	lea    0x8(%rax),%rdx
  50:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  54:	48 89 50 08          	mov    %rdx,0x8(%rax)
      }
  58:	eb 22                	jmp    7c <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE9push_backERKS2_+0x7c>
	  _M_realloc_insert(end(), __x);
  5a:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  5e:	48 89 c7             	mov    %rax,%rdi
  61:	e8 00 00 00 00       	call   66 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE9push_backERKS2_+0x66>
  66:	48 89 c1             	mov    %rax,%rcx
  69:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  6d:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  71:	48 89 ce             	mov    %rcx,%rsi
  74:	48 89 c7             	mov    %rax,%rdi
  77:	e8 00 00 00 00       	call   7c <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE9push_backERKS2_+0x7c>
      }
  7c:	90                   	nop
  7d:	c9                   	leave  
  7e:	c3                   	ret    

Disassembly of section .text._ZNSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EE12_Vector_implC2Ev:

0000000000000000 <_ZNSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EE12_Vector_implC1Ev>:
	_Vector_impl() _GLIBCXX_NOEXCEPT_IF(
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
	: _Tp_alloc_type()
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZNSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EE12_Vector_implC1Ev+0x1c>
  1c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  20:	48 89 c7             	mov    %rax,%rdi
  23:	e8 00 00 00 00       	call   28 <_ZNSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EE12_Vector_implC1Ev+0x28>
	{ }
  28:	90                   	nop
  29:	c9                   	leave  
  2a:	c3                   	ret    

Disassembly of section .text._ZNSaIN7KVStore7ssLevelEED2Ev:

0000000000000000 <_ZNSaIN7KVStore7ssLevelEED1Ev>:
	allocator(const allocator<_Tp1>&) _GLIBCXX_NOTHROW { }

#if __cpp_constexpr_dynamic_alloc
      constexpr
#endif
      ~allocator() _GLIBCXX_NOTHROW { }
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	90                   	nop
   d:	5d                   	pop    %rbp
   e:	c3                   	ret    

Disassembly of section .text._ZNSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EED2Ev:

0000000000000000 <_ZNSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EED1Ev>:
      ~_Vector_base() _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
		      _M_impl._M_end_of_storage - _M_impl._M_start);
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 8b 50 10          	mov    0x10(%rax),%rdx
  18:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  1c:	48 8b 08             	mov    (%rax),%rcx
  1f:	48 89 d0             	mov    %rdx,%rax
  22:	48 29 c8             	sub    %rcx,%rax
  25:	48 c1 f8 03          	sar    $0x3,%rax
	_M_deallocate(_M_impl._M_start,
  29:	48 89 c2             	mov    %rax,%rdx
  2c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  30:	48 8b 08             	mov    (%rax),%rcx
  33:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  37:	48 89 ce             	mov    %rcx,%rsi
  3a:	48 89 c7             	mov    %rax,%rdi
  3d:	e8 00 00 00 00       	call   42 <_ZNSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EED1Ev+0x42>
      }
  42:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  46:	48 89 c7             	mov    %rax,%rdi
  49:	e8 00 00 00 00       	call   4e <_ZNSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EED1Ev+0x4e>
  4e:	90                   	nop
  4f:	c9                   	leave  
  50:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIN7KVStore7ssLevelESaIS1_EED2Ev:

0000000000000000 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EED1Ev>:
      ~vector() _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
		      _M_get_Tp_allocator());
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EED1Ev+0x1c>
  1c:	48 89 c2             	mov    %rax,%rdx
	std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
  1f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  23:	48 8b 48 08          	mov    0x8(%rax),%rcx
  27:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  2b:	48 8b 00             	mov    (%rax),%rax
  2e:	48 89 ce             	mov    %rcx,%rsi
  31:	48 89 c7             	mov    %rax,%rdi
  34:	e8 00 00 00 00       	call   39 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EED1Ev+0x39>
      }
  39:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  3d:	48 89 c7             	mov    %rax,%rdi
  40:	e8 00 00 00 00       	call   45 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EED1Ev+0x45>
  45:	90                   	nop
  46:	c9                   	leave  
  47:	c3                   	ret    

Disassembly of section .text._ZNSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EE12_Vector_implC2Ev:

0000000000000000 <_ZNSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EE12_Vector_implC1Ev>:
	_Vector_impl() _GLIBCXX_NOEXCEPT_IF(
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
	: _Tp_alloc_type()
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZNSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EE12_Vector_implC1Ev+0x1c>
  1c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  20:	48 89 c7             	mov    %rax,%rdi
  23:	e8 00 00 00 00       	call   28 <_ZNSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EE12_Vector_implC1Ev+0x28>
	{ }
  28:	90                   	nop
  29:	c9                   	leave  
  2a:	c3                   	ret    

Disassembly of section .text._ZNSaIPN8MemTable8QuadlistEED2Ev:

0000000000000000 <_ZNSaIPN8MemTable8QuadlistEED1Ev>:
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	90                   	nop
   d:	5d                   	pop    %rbp
   e:	c3                   	ret    

Disassembly of section .text._ZNSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EED2Ev:

0000000000000000 <_ZNSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EED1Ev>:
      ~_Vector_base() _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
		      _M_impl._M_end_of_storage - _M_impl._M_start);
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 8b 50 10          	mov    0x10(%rax),%rdx
  18:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  1c:	48 8b 08             	mov    (%rax),%rcx
  1f:	48 89 d0             	mov    %rdx,%rax
  22:	48 29 c8             	sub    %rcx,%rax
  25:	48 c1 f8 03          	sar    $0x3,%rax
	_M_deallocate(_M_impl._M_start,
  29:	48 89 c2             	mov    %rax,%rdx
  2c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  30:	48 8b 08             	mov    (%rax),%rcx
  33:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  37:	48 89 ce             	mov    %rcx,%rsi
  3a:	48 89 c7             	mov    %rax,%rdi
  3d:	e8 00 00 00 00       	call   42 <_ZNSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EED1Ev+0x42>
      }
  42:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  46:	48 89 c7             	mov    %rax,%rdi
  49:	e8 00 00 00 00       	call   4e <_ZNSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EED1Ev+0x4e>
  4e:	90                   	nop
  4f:	c9                   	leave  
  50:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EED2Ev:

0000000000000000 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EED1Ev>:
      ~vector() _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
		      _M_get_Tp_allocator());
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EED1Ev+0x1c>
  1c:	48 89 c2             	mov    %rax,%rdx
	std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
  1f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  23:	48 8b 48 08          	mov    0x8(%rax),%rcx
  27:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  2b:	48 8b 00             	mov    (%rax),%rax
  2e:	48 89 ce             	mov    %rcx,%rsi
  31:	48 89 c7             	mov    %rax,%rdi
  34:	e8 00 00 00 00       	call   39 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EED1Ev+0x39>
      }
  39:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  3d:	48 89 c7             	mov    %rax,%rdi
  40:	e8 00 00 00 00       	call   45 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EED1Ev+0x45>
  45:	90                   	nop
  46:	c9                   	leave  
  47:	c3                   	ret    

Disassembly of section .text._ZNKSt6vectorIN7KVStore7ssLevelESaIS1_EE4sizeEv:

0000000000000000 <_ZNKSt6vectorIN7KVStore7ssLevelESaIS1_EE4sizeEv>:
      size() const _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
      { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	48 8b 50 08          	mov    0x8(%rax),%rdx
  14:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  18:	48 8b 08             	mov    (%rax),%rcx
  1b:	48 89 d0             	mov    %rdx,%rax
  1e:	48 29 c8             	sub    %rcx,%rax
  21:	48 c1 f8 03          	sar    $0x3,%rax
  25:	5d                   	pop    %rbp
  26:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIN7KVStore7ssLevelESaIS1_EEixEm:

0000000000000000 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EEixEm>:
      operator[](size_type __n) _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
	return *(this->_M_impl._M_start + __n);
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 8b 10             	mov    (%rax),%rdx
  17:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  1b:	48 c1 e0 03          	shl    $0x3,%rax
  1f:	48 01 d0             	add    %rdx,%rax
      }
  22:	5d                   	pop    %rbp
  23:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7reserveEm:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7reserveEm>:
	}
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    void
    basic_string<_CharT, _Traits, _Alloc>::
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 28          	sub    $0x28,%rsp
   d:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  11:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
    reserve(size_type __res)
    {
      const size_type __capacity = capacity();
  15:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  19:	48 89 c7             	mov    %rax,%rdi
  1c:	e8 00 00 00 00       	call   21 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7reserveEm+0x21>
  21:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
      // _GLIBCXX_RESOLVE_LIB_DEFECTS
      // 2968. Inconsistencies between basic_string reserve and
      // vector/unordered_map/unordered_set reserve functions
      // P0966 reserve should not shrink
      if (__res <= __capacity)
  25:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  29:	48 39 45 e0          	cmp    %rax,-0x20(%rbp)
  2d:	0f 83 80 00 00 00    	jae    b3 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7reserveEm+0xb3>
	return;

      pointer __tmp = _M_create(__res, __capacity);
  33:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
  37:	48 8d 4d d0          	lea    -0x30(%rbp),%rcx
  3b:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  3f:	48 89 ce             	mov    %rcx,%rsi
  42:	48 89 c7             	mov    %rax,%rdi
  45:	e8 00 00 00 00       	call   4a <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7reserveEm+0x4a>
  4a:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
      this->_S_copy(__tmp, _M_data(), length() + 1);
  4e:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  52:	48 89 c7             	mov    %rax,%rdi
  55:	e8 00 00 00 00       	call   5a <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7reserveEm+0x5a>
  5a:	48 8d 58 01          	lea    0x1(%rax),%rbx
  5e:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  62:	48 89 c7             	mov    %rax,%rdi
  65:	e8 00 00 00 00       	call   6a <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7reserveEm+0x6a>
  6a:	48 89 c1             	mov    %rax,%rcx
  6d:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  71:	48 89 da             	mov    %rbx,%rdx
  74:	48 89 ce             	mov    %rcx,%rsi
  77:	48 89 c7             	mov    %rax,%rdi
  7a:	e8 00 00 00 00       	call   7f <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7reserveEm+0x7f>
      _M_dispose();
  7f:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  83:	48 89 c7             	mov    %rax,%rdi
  86:	e8 00 00 00 00       	call   8b <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7reserveEm+0x8b>
      _M_data(__tmp);
  8b:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  8f:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  93:	48 89 d6             	mov    %rdx,%rsi
  96:	48 89 c7             	mov    %rax,%rdi
  99:	e8 00 00 00 00       	call   9e <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7reserveEm+0x9e>
      _M_capacity(__res);
  9e:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
  a2:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  a6:	48 89 d6             	mov    %rdx,%rsi
  a9:	48 89 c7             	mov    %rax,%rdi
  ac:	e8 00 00 00 00       	call   b1 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7reserveEm+0xb1>
  b1:	eb 01                	jmp    b4 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7reserveEm+0xb4>
	return;
  b3:	90                   	nop
    }
  b4:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  b8:	c9                   	leave  
  b9:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9push_backEc:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9push_backEc>:
      push_back(_CharT __c)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 28          	sub    $0x28,%rsp
   d:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  11:	89 f0                	mov    %esi,%eax
  13:	88 45 d4             	mov    %al,-0x2c(%rbp)
	const size_type __size = this->size();
  16:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  1a:	48 89 c7             	mov    %rax,%rdi
  1d:	e8 00 00 00 00       	call   22 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9push_backEc+0x22>
  22:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
	if (__size + 1 > this->capacity())
  26:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  2a:	48 8d 58 01          	lea    0x1(%rax),%rbx
  2e:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  32:	48 89 c7             	mov    %rax,%rdi
  35:	e8 00 00 00 00       	call   3a <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9push_backEc+0x3a>
  3a:	48 39 c3             	cmp    %rax,%rbx
  3d:	0f 97 c0             	seta   %al
  40:	84 c0                	test   %al,%al
  42:	74 20                	je     64 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9push_backEc+0x64>
	  this->_M_mutate(__size, size_type(0), 0, size_type(1));
  44:	48 8b 75 e8          	mov    -0x18(%rbp),%rsi
  48:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  4c:	41 b8 01 00 00 00    	mov    $0x1,%r8d
  52:	b9 00 00 00 00       	mov    $0x0,%ecx
  57:	ba 00 00 00 00       	mov    $0x0,%edx
  5c:	48 89 c7             	mov    %rax,%rdi
  5f:	e8 00 00 00 00       	call   64 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9push_backEc+0x64>
	traits_type::assign(this->_M_data()[__size], __c);
  64:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  68:	48 89 c7             	mov    %rax,%rdi
  6b:	e8 00 00 00 00       	call   70 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9push_backEc+0x70>
  70:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  74:	48 01 c2             	add    %rax,%rdx
  77:	48 8d 45 d4          	lea    -0x2c(%rbp),%rax
  7b:	48 89 c6             	mov    %rax,%rsi
  7e:	48 89 d7             	mov    %rdx,%rdi
  81:	e8 00 00 00 00       	call   86 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9push_backEc+0x86>
	this->_M_set_length(__size + 1);
  86:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  8a:	48 8d 50 01          	lea    0x1(%rax),%rdx
  8e:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  92:	48 89 d6             	mov    %rdx,%rsi
  95:	48 89 c7             	mov    %rax,%rdi
  98:	e8 00 00 00 00       	call   9d <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9push_backEc+0x9d>
      }
  9d:	90                   	nop
  9e:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  a2:	c9                   	leave  
  a3:	c3                   	ret    

Disassembly of section .text._ZNSt6chrono20__duration_cast_implINS_8durationIlSt5ratioILl1ELl1000EEEES2_ILl1ELl1000000EElLb1ELb0EE6__castIlS2_ILl1ELl1000000000EEEES4_RKNS1_IT_T0_EE:

0000000000000000 <_ZNSt6chrono20__duration_cast_implINS_8durationIlSt5ratioILl1ELl1000EEEES2_ILl1ELl1000000EElLb1ELb0EE6__castIlS2_ILl1ELl1000000000EEEES4_RKNS1_IT_T0_EE>:
	  __cast(const duration<_Rep, _Period>& __d)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 30          	sub    $0x30,%rsp
   c:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  10:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  17:	00 00 
  19:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  1d:	31 c0                	xor    %eax,%eax
	      static_cast<_CR>(__d.count()) / static_cast<_CR>(_CF::den)));
  1f:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  23:	48 89 c7             	mov    %rax,%rdi
  26:	e8 00 00 00 00       	call   2b <_ZNSt6chrono20__duration_cast_implINS_8durationIlSt5ratioILl1ELl1000EEEES2_ILl1ELl1000000EElLb1ELb0EE6__castIlS2_ILl1ELl1000000000EEEES4_RKNS1_IT_T0_EE+0x2b>
  2b:	48 89 c1             	mov    %rax,%rcx
  2e:	48 ba db 34 b6 d7 82 	movabs $0x431bde82d7b634db,%rdx
  35:	de 1b 43 
  38:	48 89 c8             	mov    %rcx,%rax
  3b:	48 f7 ea             	imul   %rdx
  3e:	48 89 d0             	mov    %rdx,%rax
  41:	48 c1 f8 12          	sar    $0x12,%rax
  45:	48 c1 f9 3f          	sar    $0x3f,%rcx
  49:	48 89 ca             	mov    %rcx,%rdx
  4c:	48 29 d0             	sub    %rdx,%rax
	    return _ToDur(static_cast<__to_rep>(
  4f:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  53:	48 8d 55 e8          	lea    -0x18(%rbp),%rdx
  57:	48 8d 45 f0          	lea    -0x10(%rbp),%rax
  5b:	48 89 d6             	mov    %rdx,%rsi
  5e:	48 89 c7             	mov    %rax,%rdi
  61:	e8 00 00 00 00       	call   66 <_ZNSt6chrono20__duration_cast_implINS_8durationIlSt5ratioILl1ELl1000EEEES2_ILl1ELl1000000EElLb1ELb0EE6__castIlS2_ILl1ELl1000000000EEEES4_RKNS1_IT_T0_EE+0x66>
	      static_cast<_CR>(__d.count()) / static_cast<_CR>(_CF::den)));
  66:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
	  }
  6a:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  6e:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
  75:	00 00 
  77:	74 05                	je     7e <_ZNSt6chrono20__duration_cast_implINS_8durationIlSt5ratioILl1ELl1000EEEES2_ILl1ELl1000000EElLb1ELb0EE6__castIlS2_ILl1ELl1000000000EEEES4_RKNS1_IT_T0_EE+0x7e>
  79:	e8 00 00 00 00       	call   7e <_ZNSt6chrono20__duration_cast_implINS_8durationIlSt5ratioILl1ELl1000EEEES2_ILl1ELl1000000EElLb1ELb0EE6__castIlS2_ILl1ELl1000000000EEEES4_RKNS1_IT_T0_EE+0x7e>
  7e:	c9                   	leave  
  7f:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE9push_backERKS1_:

0000000000000000 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE9push_backERKS1_>:
      push_back(const value_type& __x)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
	if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
  14:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  18:	48 8b 50 08          	mov    0x8(%rax),%rdx
  1c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  20:	48 8b 40 10          	mov    0x10(%rax),%rax
  24:	48 39 c2             	cmp    %rax,%rdx
  27:	74 31                	je     5a <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE9push_backERKS1_+0x5a>
	    _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish,
  29:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  2d:	48 8b 48 08          	mov    0x8(%rax),%rcx
  31:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  35:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  39:	48 89 ce             	mov    %rcx,%rsi
  3c:	48 89 c7             	mov    %rax,%rdi
  3f:	e8 00 00 00 00       	call   44 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE9push_backERKS1_+0x44>
	    ++this->_M_impl._M_finish;
  44:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  48:	48 8b 40 08          	mov    0x8(%rax),%rax
  4c:	48 8d 50 08          	lea    0x8(%rax),%rdx
  50:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  54:	48 89 50 08          	mov    %rdx,0x8(%rax)
      }
  58:	eb 22                	jmp    7c <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE9push_backERKS1_+0x7c>
	  _M_realloc_insert(end(), __x);
  5a:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  5e:	48 89 c7             	mov    %rax,%rdi
  61:	e8 00 00 00 00       	call   66 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE9push_backERKS1_+0x66>
  66:	48 89 c1             	mov    %rax,%rcx
  69:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  6d:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  71:	48 89 ce             	mov    %rcx,%rsi
  74:	48 89 c7             	mov    %rax,%rdi
  77:	e8 00 00 00 00       	call   7c <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE9push_backERKS1_+0x7c>
      }
  7c:	90                   	nop
  7d:	c9                   	leave  
  7e:	c3                   	ret    

Disassembly of section .text._ZSt11__addressofINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEPT_RS6_:

0000000000000000 <_ZSt11__addressofINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEPT_RS6_>:
   *  @brief Same as C++11 std::addressof
   *  @ingroup utilities
   */
  template<typename _Tp>
    inline _GLIBCXX_CONSTEXPR _Tp*
    __addressof(_Tp& __r) _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    { return __builtin_addressof(__r); }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	5d                   	pop    %rbp
  11:	c3                   	ret    

Disassembly of section .text._ZSteqRKSaIcES1_:

0000000000000000 <_ZSteqRKSaIcES1_>:
	__allocator_base<_Tp>::deallocate(__p, __n);
      }
#endif // C++20

      friend _GLIBCXX20_CONSTEXPR bool
      operator==(const allocator&, const allocator&) _GLIBCXX_NOTHROW
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
      { return true; }
  10:	b8 01 00 00 00       	mov    $0x1,%eax
  15:	5d                   	pop    %rbp
  16:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_>:
      operator=(basic_string&& __str)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	41 54                	push   %r12
   a:	53                   	push   %rbx
   b:	48 83 ec 20          	sub    $0x20,%rsp
   f:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  13:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
	if (!_M_is_local() && _Alloc_traits::_S_propagate_on_move_assign()
  17:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  1b:	48 89 c7             	mov    %rax,%rdi
  1e:	e8 00 00 00 00       	call   23 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x23>
  23:	83 f0 01             	xor    $0x1,%eax
	    && _M_get_allocator() != __str._M_get_allocator())
  26:	84 c0                	test   %al,%al
  28:	74 49                	je     73 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x73>
	if (!_M_is_local() && _Alloc_traits::_S_propagate_on_move_assign()
  2a:	e8 00 00 00 00       	call   2f <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x2f>
  2f:	84 c0                	test   %al,%al
  31:	74 40                	je     73 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x73>
	    && !_Alloc_traits::_S_always_equal()
  33:	e8 00 00 00 00       	call   38 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x38>
  38:	83 f0 01             	xor    $0x1,%eax
  3b:	84 c0                	test   %al,%al
  3d:	74 34                	je     73 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x73>
	    && _M_get_allocator() != __str._M_get_allocator())
  3f:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  43:	48 89 c7             	mov    %rax,%rdi
  46:	e8 00 00 00 00       	call   4b <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x4b>
  4b:	48 89 c3             	mov    %rax,%rbx
  4e:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  52:	48 89 c7             	mov    %rax,%rdi
  55:	e8 00 00 00 00       	call   5a <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x5a>
  5a:	48 89 de             	mov    %rbx,%rsi
  5d:	48 89 c7             	mov    %rax,%rdi
  60:	e8 00 00 00 00       	call   65 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x65>
  65:	83 f0 01             	xor    $0x1,%eax
  68:	84 c0                	test   %al,%al
  6a:	74 07                	je     73 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x73>
  6c:	b8 01 00 00 00       	mov    $0x1,%eax
  71:	eb 05                	jmp    78 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x78>
  73:	b8 00 00 00 00       	mov    $0x0,%eax
	if (!_M_is_local() && _Alloc_traits::_S_propagate_on_move_assign()
  78:	84 c0                	test   %al,%al
  7a:	74 46                	je     c2 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0xc2>
	    _M_destroy(_M_allocated_capacity);
  7c:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  80:	48 8b 50 10          	mov    0x10(%rax),%rdx
  84:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  88:	48 89 d6             	mov    %rdx,%rsi
  8b:	48 89 c7             	mov    %rax,%rdi
  8e:	e8 00 00 00 00       	call   93 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x93>
	    _M_data(_M_local_data());
  93:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  97:	48 89 c7             	mov    %rax,%rdi
  9a:	e8 00 00 00 00       	call   9f <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x9f>
  9f:	48 89 c2             	mov    %rax,%rdx
  a2:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  a6:	48 89 d6             	mov    %rdx,%rsi
  a9:	48 89 c7             	mov    %rax,%rdi
  ac:	e8 00 00 00 00       	call   b1 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0xb1>
	    _M_set_length(0);
  b1:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  b5:	be 00 00 00 00       	mov    $0x0,%esi
  ba:	48 89 c7             	mov    %rax,%rdi
  bd:	e8 00 00 00 00       	call   c2 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0xc2>
	std::__alloc_on_move(_M_get_allocator(), __str._M_get_allocator());
  c2:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  c6:	48 89 c7             	mov    %rax,%rdi
  c9:	e8 00 00 00 00       	call   ce <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0xce>
  ce:	48 89 c3             	mov    %rax,%rbx
  d1:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  d5:	48 89 c7             	mov    %rax,%rdi
  d8:	e8 00 00 00 00       	call   dd <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0xdd>
  dd:	48 89 de             	mov    %rbx,%rsi
  e0:	48 89 c7             	mov    %rax,%rdi
  e3:	e8 00 00 00 00       	call   e8 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0xe8>
	if (__str._M_is_local())
  e8:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  ec:	48 89 c7             	mov    %rax,%rdi
  ef:	e8 00 00 00 00       	call   f4 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0xf4>
  f4:	84 c0                	test   %al,%al
  f6:	0f 84 95 00 00 00    	je     191 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x191>
	    if (__builtin_expect(std::__addressof(__str) != this, true))
  fc:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
 100:	48 89 c7             	mov    %rax,%rdi
 103:	e8 00 00 00 00       	call   108 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x108>
 108:	48 39 45 d8          	cmp    %rax,-0x28(%rbp)
 10c:	0f 95 c0             	setne  %al
 10f:	0f b6 c0             	movzbl %al,%eax
 112:	48 85 c0             	test   %rax,%rax
 115:	0f 95 c0             	setne  %al
 118:	84 c0                	test   %al,%al
 11a:	0f 84 c8 01 00 00    	je     2e8 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x2e8>
		if (__str.size())
 120:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
 124:	48 89 c7             	mov    %rax,%rdi
 127:	e8 00 00 00 00       	call   12c <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x12c>
 12c:	48 85 c0             	test   %rax,%rax
 12f:	0f 95 c0             	setne  %al
 132:	84 c0                	test   %al,%al
 134:	74 38                	je     16e <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x16e>
		  this->_S_copy(_M_data(), __str._M_data(), __str.size());
 136:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
 13a:	48 89 c7             	mov    %rax,%rdi
 13d:	e8 00 00 00 00       	call   142 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x142>
 142:	49 89 c4             	mov    %rax,%r12
 145:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
 149:	48 89 c7             	mov    %rax,%rdi
 14c:	e8 00 00 00 00       	call   151 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x151>
 151:	48 89 c3             	mov    %rax,%rbx
 154:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 158:	48 89 c7             	mov    %rax,%rdi
 15b:	e8 00 00 00 00       	call   160 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x160>
 160:	4c 89 e2             	mov    %r12,%rdx
 163:	48 89 de             	mov    %rbx,%rsi
 166:	48 89 c7             	mov    %rax,%rdi
 169:	e8 00 00 00 00       	call   16e <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x16e>
		_M_set_length(__str.size());
 16e:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
 172:	48 89 c7             	mov    %rax,%rdi
 175:	e8 00 00 00 00       	call   17a <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x17a>
 17a:	48 89 c2             	mov    %rax,%rdx
 17d:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 181:	48 89 d6             	mov    %rdx,%rsi
 184:	48 89 c7             	mov    %rax,%rdi
 187:	e8 00 00 00 00       	call   18c <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x18c>
 18c:	e9 57 01 00 00       	jmp    2e8 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x2e8>
	else if (_Alloc_traits::_S_propagate_on_move_assign()
 191:	e8 00 00 00 00       	call   196 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x196>
	    || _M_get_allocator() == __str._M_get_allocator())
 196:	84 c0                	test   %al,%al
 198:	75 33                	jne    1cd <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x1cd>
	    || _Alloc_traits::_S_always_equal()
 19a:	e8 00 00 00 00       	call   19f <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x19f>
 19f:	84 c0                	test   %al,%al
 1a1:	75 2a                	jne    1cd <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x1cd>
	    || _M_get_allocator() == __str._M_get_allocator())
 1a3:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
 1a7:	48 89 c7             	mov    %rax,%rdi
 1aa:	e8 00 00 00 00       	call   1af <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x1af>
 1af:	48 89 c3             	mov    %rax,%rbx
 1b2:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 1b6:	48 89 c7             	mov    %rax,%rdi
 1b9:	e8 00 00 00 00       	call   1be <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x1be>
 1be:	48 89 de             	mov    %rbx,%rsi
 1c1:	48 89 c7             	mov    %rax,%rdi
 1c4:	e8 00 00 00 00       	call   1c9 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x1c9>
 1c9:	84 c0                	test   %al,%al
 1cb:	74 07                	je     1d4 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x1d4>
 1cd:	b8 01 00 00 00       	mov    $0x1,%eax
 1d2:	eb 05                	jmp    1d9 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x1d9>
 1d4:	b8 00 00 00 00       	mov    $0x0,%eax
	else if (_Alloc_traits::_S_propagate_on_move_assign()
 1d9:	84 c0                	test   %al,%al
 1db:	0f 84 f4 00 00 00    	je     2d5 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x2d5>
	    pointer __data = nullptr;
 1e1:	48 c7 45 e0 00 00 00 	movq   $0x0,-0x20(%rbp)
 1e8:	00 
	    if (!_M_is_local())
 1e9:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 1ed:	48 89 c7             	mov    %rax,%rdi
 1f0:	e8 00 00 00 00       	call   1f5 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x1f5>
 1f5:	83 f0 01             	xor    $0x1,%eax
 1f8:	84 c0                	test   %al,%al
 1fa:	74 3e                	je     23a <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x23a>
		if (_Alloc_traits::_S_always_equal())
 1fc:	e8 00 00 00 00       	call   201 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x201>
 201:	84 c0                	test   %al,%al
 203:	74 1e                	je     223 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x223>
		    __data = _M_data();
 205:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 209:	48 89 c7             	mov    %rax,%rdi
 20c:	e8 00 00 00 00       	call   211 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x211>
 211:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
		    __capacity = _M_allocated_capacity;
 215:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 219:	48 8b 40 10          	mov    0x10(%rax),%rax
 21d:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
 221:	eb 17                	jmp    23a <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x23a>
		  _M_destroy(_M_allocated_capacity);
 223:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 227:	48 8b 50 10          	mov    0x10(%rax),%rdx
 22b:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 22f:	48 89 d6             	mov    %rdx,%rsi
 232:	48 89 c7             	mov    %rax,%rdi
 235:	e8 00 00 00 00       	call   23a <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x23a>
	    _M_data(__str._M_data());
 23a:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
 23e:	48 89 c7             	mov    %rax,%rdi
 241:	e8 00 00 00 00       	call   246 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x246>
 246:	48 89 c2             	mov    %rax,%rdx
 249:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 24d:	48 89 d6             	mov    %rdx,%rsi
 250:	48 89 c7             	mov    %rax,%rdi
 253:	e8 00 00 00 00       	call   258 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x258>
	    _M_length(__str.length());
 258:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
 25c:	48 89 c7             	mov    %rax,%rdi
 25f:	e8 00 00 00 00       	call   264 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x264>
 264:	48 89 c2             	mov    %rax,%rdx
 267:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 26b:	48 89 d6             	mov    %rdx,%rsi
 26e:	48 89 c7             	mov    %rax,%rdi
 271:	e8 00 00 00 00       	call   276 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x276>
	    _M_capacity(__str._M_allocated_capacity);
 276:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
 27a:	48 8b 50 10          	mov    0x10(%rax),%rdx
 27e:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 282:	48 89 d6             	mov    %rdx,%rsi
 285:	48 89 c7             	mov    %rax,%rdi
 288:	e8 00 00 00 00       	call   28d <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x28d>
	    if (__data)
 28d:	48 83 7d e0 00       	cmpq   $0x0,-0x20(%rbp)
 292:	74 28                	je     2bc <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x2bc>
		__str._M_data(__data);
 294:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
 298:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
 29c:	48 89 d6             	mov    %rdx,%rsi
 29f:	48 89 c7             	mov    %rax,%rdi
 2a2:	e8 00 00 00 00       	call   2a7 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x2a7>
		__str._M_capacity(__capacity);
 2a7:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
 2ab:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
 2af:	48 89 d6             	mov    %rdx,%rsi
 2b2:	48 89 c7             	mov    %rax,%rdi
 2b5:	e8 00 00 00 00       	call   2ba <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x2ba>
 2ba:	eb 2c                	jmp    2e8 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x2e8>
	      __str._M_data(__str._M_local_buf);
 2bc:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
 2c0:	48 8d 50 10          	lea    0x10(%rax),%rdx
 2c4:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
 2c8:	48 89 d6             	mov    %rdx,%rsi
 2cb:	48 89 c7             	mov    %rax,%rdi
 2ce:	e8 00 00 00 00       	call   2d3 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x2d3>
 2d3:	eb 13                	jmp    2e8 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x2e8>
	  assign(__str);
 2d5:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
 2d9:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 2dd:	48 89 d6             	mov    %rdx,%rsi
 2e0:	48 89 c7             	mov    %rax,%rdi
 2e3:	e8 00 00 00 00       	call   2e8 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x2e8>
	__str.clear();
 2e8:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
 2ec:	48 89 c7             	mov    %rax,%rdi
 2ef:	e8 00 00 00 00       	call   2f4 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_+0x2f4>
	return *this;
 2f4:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
      }
 2f8:	48 83 c4 20          	add    $0x20,%rsp
 2fc:	5b                   	pop    %rbx
 2fd:	41 5c                	pop    %r12
 2ff:	5d                   	pop    %rbp
 300:	c3                   	ret    

Disassembly of section .text._ZSt12__miter_baseIPKcET_S2_:

0000000000000000 <_ZSt12__miter_baseIPKcET_S2_>:
  // Fallback implementation of the function in bits/stl_iterator.h used to
  // remove the move_iterator wrapper.
  template<typename _Iterator>
    _GLIBCXX20_CONSTEXPR
    inline _Iterator
    __miter_base(_Iterator __it)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    { return __it; }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	5d                   	pop    %rbp
  11:	c3                   	ret    

Disassembly of section .text._ZSt13__copy_move_aILb0EPKcPcET1_T0_S4_S3_:

0000000000000000 <_ZSt13__copy_move_aILb0EPKcPcET1_T0_S4_S3_>:
    __copy_move_a(_II __first, _II __last, _OI __result)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	41 54                	push   %r12
   a:	53                   	push   %rbx
   b:	48 83 ec 20          	sub    $0x20,%rsp
   f:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  13:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  17:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
      return std::__niter_wrap(__result,
  1b:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  1f:	48 89 c7             	mov    %rax,%rdi
  22:	e8 00 00 00 00       	call   27 <_ZSt13__copy_move_aILb0EPKcPcET1_T0_S4_S3_+0x27>
  27:	49 89 c4             	mov    %rax,%r12
  2a:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  2e:	48 89 c7             	mov    %rax,%rdi
  31:	e8 00 00 00 00       	call   36 <_ZSt13__copy_move_aILb0EPKcPcET1_T0_S4_S3_+0x36>
  36:	48 89 c3             	mov    %rax,%rbx
  39:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  3d:	48 89 c7             	mov    %rax,%rdi
  40:	e8 00 00 00 00       	call   45 <_ZSt13__copy_move_aILb0EPKcPcET1_T0_S4_S3_+0x45>
  45:	4c 89 e2             	mov    %r12,%rdx
  48:	48 89 de             	mov    %rbx,%rsi
  4b:	48 89 c7             	mov    %rax,%rdi
  4e:	e8 00 00 00 00       	call   53 <_ZSt13__copy_move_aILb0EPKcPcET1_T0_S4_S3_+0x53>
  53:	48 89 c2             	mov    %rax,%rdx
  56:	48 8d 45 d8          	lea    -0x28(%rbp),%rax
  5a:	48 89 d6             	mov    %rdx,%rsi
  5d:	48 89 c7             	mov    %rax,%rdi
  60:	e8 00 00 00 00       	call   65 <_ZSt13__copy_move_aILb0EPKcPcET1_T0_S4_S3_+0x65>
    }
  65:	48 83 c4 20          	add    $0x20,%rsp
  69:	5b                   	pop    %rbx
  6a:	41 5c                	pop    %r12
  6c:	5d                   	pop    %rbp
  6d:	c3                   	ret    

Disassembly of section .text._ZSt19__iterator_categoryIPcENSt15iterator_traitsIT_E17iterator_categoryERKS2_:

0000000000000000 <_ZSt19__iterator_categoryIPcENSt15iterator_traitsIT_E17iterator_categoryERKS2_>:
   *  sugar for internal library use only.
  */
  template<typename _Iter>
    inline _GLIBCXX_CONSTEXPR
    typename iterator_traits<_Iter>::iterator_category
    __iterator_category(const _Iter&)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    { return typename iterator_traits<_Iter>::iterator_category(); }
   c:	5d                   	pop    %rbp
   d:	c3                   	ret    

Disassembly of section .text._ZSt10__fill_n_aIPcmcET_S1_T0_RKT1_St26random_access_iterator_tag:

0000000000000000 <_ZSt10__fill_n_aIPcmcET_S1_T0_RKT1_St26random_access_iterator_tag>:
    __fill_n_a(_OutputIterator __first, _Size __n, const _Tp& __value,
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
      if (__n <= 0)
  18:	48 83 7d f0 00       	cmpq   $0x0,-0x10(%rbp)
  1d:	75 06                	jne    25 <_ZSt10__fill_n_aIPcmcET_S1_T0_RKT1_St26random_access_iterator_tag+0x25>
	return __first;
  1f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  23:	eb 2a                	jmp    4f <_ZSt10__fill_n_aIPcmcET_S1_T0_RKT1_St26random_access_iterator_tag+0x4f>
      std::__fill_a(__first, __first + __n, __value);
  25:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  29:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  2d:	48 8d 0c 02          	lea    (%rdx,%rax,1),%rcx
  31:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  35:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  39:	48 89 ce             	mov    %rcx,%rsi
  3c:	48 89 c7             	mov    %rax,%rdi
  3f:	e8 00 00 00 00       	call   44 <_ZSt10__fill_n_aIPcmcET_S1_T0_RKT1_St26random_access_iterator_tag+0x44>
      return __first + __n;
  44:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  48:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  4c:	48 01 d0             	add    %rdx,%rax
    }
  4f:	c9                   	leave  
  50:	c3                   	ret    

Disassembly of section .text._ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv:

0000000000000000 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv>:
      _M_data() const
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
      { return _M_dataplus._M_p; }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	48 8b 00             	mov    (%rax),%rax
  13:	5d                   	pop    %rbp
  14:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv>:
      _M_local_data()
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
	return std::pointer_traits<pointer>::pointer_to(*_M_local_buf);
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 83 c0 10          	add    $0x10,%rax
  18:	48 89 c7             	mov    %rax,%rdi
  1b:	e8 00 00 00 00       	call   20 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv+0x20>
      }
  20:	c9                   	leave  
  21:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC2EPcRKS3_:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC1EPcRKS3_>:
	_Alloc_hider(pointer __dat, const _Alloc& __a)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
	: allocator_type(__a), _M_p(__dat) { }
  18:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  1c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  20:	48 89 d6             	mov    %rdx,%rsi
  23:	48 89 c7             	mov    %rax,%rdi
  26:	e8 00 00 00 00       	call   2b <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC1EPcRKS3_+0x2b>
  2b:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  2f:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  33:	48 89 10             	mov    %rdx,(%rax)
  36:	90                   	nop
  37:	c9                   	leave  
  38:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructEmc:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructEmc>:
    basic_string<_CharT, _Traits, _Alloc>::
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	41 54                	push   %r12
   a:	53                   	push   %rbx
   b:	48 83 ec 20          	sub    $0x20,%rsp
   f:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  13:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  17:	89 d0                	mov    %edx,%eax
  19:	88 45 dc             	mov    %al,-0x24(%rbp)
      if (__n > size_type(_S_local_capacity))
  1c:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  20:	48 83 f8 0f          	cmp    $0xf,%rax
  24:	76 3d                	jbe    63 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructEmc+0x63>
	  _M_data(_M_create(__n, size_type(0)));
  26:	48 8d 4d e0          	lea    -0x20(%rbp),%rcx
  2a:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  2e:	ba 00 00 00 00       	mov    $0x0,%edx
  33:	48 89 ce             	mov    %rcx,%rsi
  36:	48 89 c7             	mov    %rax,%rdi
  39:	e8 00 00 00 00       	call   3e <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructEmc+0x3e>
  3e:	48 89 c2             	mov    %rax,%rdx
  41:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  45:	48 89 d6             	mov    %rdx,%rsi
  48:	48 89 c7             	mov    %rax,%rdi
  4b:	e8 00 00 00 00       	call   50 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructEmc+0x50>
	  _M_capacity(__n);
  50:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
  54:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  58:	48 89 d6             	mov    %rdx,%rsi
  5b:	48 89 c7             	mov    %rax,%rdi
  5e:	e8 00 00 00 00       	call   63 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructEmc+0x63>
      if (__n)
  63:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  67:	48 85 c0             	test   %rax,%rax
  6a:	74 23                	je     8f <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructEmc+0x8f>
	this->_S_assign(_M_data(), __n, __c);
  6c:	44 0f be 65 dc       	movsbl -0x24(%rbp),%r12d
  71:	48 8b 5d e0          	mov    -0x20(%rbp),%rbx
  75:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  79:	48 89 c7             	mov    %rax,%rdi
  7c:	e8 00 00 00 00       	call   81 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructEmc+0x81>
  81:	44 89 e2             	mov    %r12d,%edx
  84:	48 89 de             	mov    %rbx,%rsi
  87:	48 89 c7             	mov    %rax,%rdi
  8a:	e8 00 00 00 00       	call   8f <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructEmc+0x8f>
      _M_set_length(__n);
  8f:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
  93:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  97:	48 89 d6             	mov    %rdx,%rsi
  9a:	48 89 c7             	mov    %rax,%rdi
  9d:	e8 00 00 00 00       	call   a2 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructEmc+0xa2>
    }
  a2:	90                   	nop
  a3:	48 83 c4 20          	add    $0x20,%rsp
  a7:	5b                   	pop    %rbx
  a8:	41 5c                	pop    %r12
  aa:	5d                   	pop    %rbp
  ab:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv>:
      _M_dispose()
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
	if (!_M_is_local())
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv+0x1c>
  1c:	83 f0 01             	xor    $0x1,%eax
  1f:	84 c0                	test   %al,%al
  21:	74 17                	je     3a <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv+0x3a>
	  _M_destroy(_M_allocated_capacity);
  23:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  27:	48 8b 50 10          	mov    0x10(%rax),%rdx
  2b:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  2f:	48 89 d6             	mov    %rdx,%rsi
  32:	48 89 c7             	mov    %rax,%rdi
  35:	e8 00 00 00 00       	call   3a <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv+0x3a>
      }
  3a:	90                   	nop
  3b:	c9                   	leave  
  3c:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv>:
      _M_get_allocator()
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
      { return _M_dataplus; }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	5d                   	pop    %rbp
  11:	c3                   	ret    

Disassembly of section .text._ZSt4moveIRSaIcEEONSt16remove_referenceIT_E4typeEOS3_:

0000000000000000 <_ZSt4moveIRSaIcEEONSt16remove_referenceIT_E4typeEOS3_>:
   *  @return The parameter cast to an rvalue-reference to allow moving it.
  */
  template<typename _Tp>
    _GLIBCXX_NODISCARD
    constexpr typename std::remove_reference<_Tp>::type&&
    move(_Tp&& __t) noexcept
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    { return static_cast<typename std::remove_reference<_Tp>::type&&>(__t); }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	5d                   	pop    %rbp
  11:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC2EPcOS3_:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC1EPcOS3_>:
	_Alloc_hider(pointer __dat, _Alloc&& __a = _Alloc())
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
	: allocator_type(std::move(__a)), _M_p(__dat) { }
  18:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  1c:	48 89 c7             	mov    %rax,%rdi
  1f:	e8 00 00 00 00       	call   24 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC1EPcOS3_+0x24>
  24:	48 89 c2             	mov    %rax,%rdx
  27:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  2b:	48 89 d6             	mov    %rdx,%rsi
  2e:	48 89 c7             	mov    %rax,%rdi
  31:	e8 00 00 00 00       	call   36 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC1EPcOS3_+0x36>
  36:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  3a:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  3e:	48 89 10             	mov    %rdx,(%rax)
  41:	90                   	nop
  42:	c9                   	leave  
  43:	c3                   	ret    

Disassembly of section .text._ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_is_localEv:

0000000000000000 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_is_localEv>:
      _M_is_local() const
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 18          	sub    $0x18,%rsp
   d:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
      { return _M_data() == _M_local_data(); }
  11:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  15:	48 89 c7             	mov    %rax,%rdi
  18:	e8 00 00 00 00       	call   1d <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_is_localEv+0x1d>
  1d:	48 89 c3             	mov    %rax,%rbx
  20:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  24:	48 89 c7             	mov    %rax,%rdi
  27:	e8 00 00 00 00       	call   2c <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_is_localEv+0x2c>
  2c:	48 39 c3             	cmp    %rax,%rbx
  2f:	0f 94 c0             	sete   %al
  32:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  36:	c9                   	leave  
  37:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc>:
      _M_data(pointer __p)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
      { _M_dataplus._M_p = __p; }
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  18:	48 89 10             	mov    %rdx,(%rax)
  1b:	90                   	nop
  1c:	5d                   	pop    %rbp
  1d:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEm:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEm>:
      _M_capacity(size_type __capacity)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
      { _M_allocated_capacity = __capacity; }
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  18:	48 89 50 10          	mov    %rdx,0x10(%rax)
  1c:	90                   	nop
  1d:	5d                   	pop    %rbp
  1e:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_lengthEm:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_lengthEm>:
      _M_length(size_type __length)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
      { _M_string_length = __length; }
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  18:	48 89 50 08          	mov    %rdx,0x8(%rax)
  1c:	90                   	nop
  1d:	5d                   	pop    %rbp
  1e:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEm:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEm>:
      _M_set_length(size_type __n)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  10:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  14:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  1b:	00 00 
  1d:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  21:	31 c0                	xor    %eax,%eax
	_M_length(__n);
  23:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
  27:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  2b:	48 89 d6             	mov    %rdx,%rsi
  2e:	48 89 c7             	mov    %rax,%rdi
  31:	e8 00 00 00 00       	call   36 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEm+0x36>
	traits_type::assign(_M_data()[__n], _CharT());
  36:	c6 45 f7 00          	movb   $0x0,-0x9(%rbp)
  3a:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  3e:	48 89 c7             	mov    %rax,%rdi
  41:	e8 00 00 00 00       	call   46 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEm+0x46>
  46:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
  4a:	48 01 c2             	add    %rax,%rdx
  4d:	48 8d 45 f7          	lea    -0x9(%rbp),%rax
  51:	48 89 c6             	mov    %rax,%rsi
  54:	48 89 d7             	mov    %rdx,%rdi
  57:	e8 00 00 00 00       	call   5c <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEm+0x5c>
      }
  5c:	90                   	nop
  5d:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  61:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
  68:	00 00 
  6a:	74 05                	je     71 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEm+0x71>
  6c:	e8 00 00 00 00       	call   71 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEm+0x71>
  71:	c9                   	leave  
  72:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendEPKc:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendEPKc>:
      append(const _CharT* __s)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  10:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
	const size_type __n = traits_type::length(__s);
  14:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  18:	48 89 c7             	mov    %rax,%rdi
  1b:	e8 00 00 00 00       	call   20 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendEPKc+0x20>
  20:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
	_M_check_length(size_type(0), __n, "basic_string::append");
  24:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  28:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  2c:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # 33 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendEPKc+0x33>
  33:	be 00 00 00 00       	mov    $0x0,%esi
  38:	48 89 c7             	mov    %rax,%rdi
  3b:	e8 00 00 00 00       	call   40 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendEPKc+0x40>
	return _M_append(__s, __n);
  40:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  44:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
  48:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  4c:	48 89 ce             	mov    %rcx,%rsi
  4f:	48 89 c7             	mov    %rax,%rdi
  52:	e8 00 00 00 00       	call   57 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendEPKc+0x57>
      }
  57:	c9                   	leave  
  58:	c3                   	ret    

Disassembly of section .text._ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8capacityEv:

0000000000000000 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8capacityEv>:
      capacity() const _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
	return _M_is_local() ? size_type(_S_local_capacity)
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8capacityEv+0x1c>
  1c:	84 c0                	test   %al,%al
  1e:	74 07                	je     27 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8capacityEv+0x27>
  20:	b8 0f 00 00 00       	mov    $0xf,%eax
	                     : _M_allocated_capacity;
  25:	eb 08                	jmp    2f <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8capacityEv+0x2f>
	return _M_is_local() ? size_type(_S_local_capacity)
  27:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  2b:	48 8b 40 10          	mov    0x10(%rax),%rax
      }
  2f:	c9                   	leave  
  30:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6insertEmRKS4_:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6insertEmRKS4_>:
      insert(size_type __pos1, const basic_string& __str)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 28          	sub    $0x28,%rsp
   d:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  11:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  15:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
      { return this->replace(__pos1, size_type(0),
  19:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  1d:	48 89 c7             	mov    %rax,%rdi
  20:	e8 00 00 00 00       	call   25 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6insertEmRKS4_+0x25>
  25:	48 89 c3             	mov    %rax,%rbx
			     __str._M_data(), __str.size()); }
  28:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  2c:	48 89 c7             	mov    %rax,%rdi
  2f:	e8 00 00 00 00       	call   34 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6insertEmRKS4_+0x34>
  34:	48 89 c2             	mov    %rax,%rdx
      { return this->replace(__pos1, size_type(0),
  37:	48 8b 75 e0          	mov    -0x20(%rbp),%rsi
  3b:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  3f:	49 89 d8             	mov    %rbx,%r8
  42:	48 89 d1             	mov    %rdx,%rcx
  45:	ba 00 00 00 00       	mov    $0x0,%edx
  4a:	48 89 c7             	mov    %rax,%rdi
  4d:	e8 00 00 00 00       	call   52 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6insertEmRKS4_+0x52>
			     __str._M_data(), __str.size()); }
  52:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  56:	c9                   	leave  
  57:	c3                   	ret    

Disassembly of section .text._ZSt4moveIRNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEONSt16remove_referenceIT_E4typeEOS8_:

0000000000000000 <_ZSt4moveIRNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEONSt16remove_referenceIT_E4typeEOS8_>:
    move(_Tp&& __t) noexcept
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    { return static_cast<typename std::remove_reference<_Tp>::type&&>(__t); }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	5d                   	pop    %rbp
  11:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendERKS4_:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendERKS4_>:
      append(const basic_string& __str)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 18          	sub    $0x18,%rsp
   d:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  11:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
      { return _M_append(__str._M_data(), __str.size()); }
  15:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  19:	48 89 c7             	mov    %rax,%rdi
  1c:	e8 00 00 00 00       	call   21 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendERKS4_+0x21>
  21:	48 89 c3             	mov    %rax,%rbx
  24:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  28:	48 89 c7             	mov    %rax,%rdi
  2b:	e8 00 00 00 00       	call   30 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendERKS4_+0x30>
  30:	48 89 c1             	mov    %rax,%rcx
  33:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  37:	48 89 da             	mov    %rbx,%rdx
  3a:	48 89 ce             	mov    %rcx,%rsi
  3d:	48 89 c7             	mov    %rax,%rdi
  40:	e8 00 00 00 00       	call   45 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendERKS4_+0x45>
  45:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  49:	c9                   	leave  
  4a:	c3                   	ret    

Disassembly of section .text._ZSt8distanceIPKcENSt15iterator_traitsIT_E15difference_typeES3_S3_:

0000000000000000 <_ZSt8distanceIPKcENSt15iterator_traitsIT_E15difference_typeES3_S3_>:
   *  and are constant time.  For other %iterator classes they are linear time.
  */
  template<typename _InputIterator>
    inline _GLIBCXX17_CONSTEXPR
    typename iterator_traits<_InputIterator>::difference_type
    distance(_InputIterator __first, _InputIterator __last)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    {
      // concept requirements -- taken care of in __distance
      return std::__distance(__first, __last,
			     std::__iterator_category(__first));
  14:	48 8d 45 f8          	lea    -0x8(%rbp),%rax
  18:	48 89 c7             	mov    %rax,%rdi
  1b:	e8 00 00 00 00       	call   20 <_ZSt8distanceIPKcENSt15iterator_traitsIT_E15difference_typeES3_S3_+0x20>
      return std::__distance(__first, __last,
  20:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  24:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  28:	48 89 d6             	mov    %rdx,%rsi
  2b:	48 89 c7             	mov    %rax,%rdi
  2e:	e8 00 00 00 00       	call   33 <_ZSt8distanceIPKcENSt15iterator_traitsIT_E15difference_typeES3_S3_+0x33>
    }
  33:	c9                   	leave  
  34:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag>:
      basic_string<_CharT, _Traits, _Alloc>::
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 30          	sub    $0x30,%rsp
   c:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  10:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  14:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
  18:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  1f:	00 00 
  21:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  25:	31 c0                	xor    %eax,%eax
	if (__gnu_cxx::__is_null_pointer(__beg) && __beg != __end)
  27:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  2b:	48 89 c7             	mov    %rax,%rdi
  2e:	e8 00 00 00 00       	call   33 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag+0x33>
  33:	84 c0                	test   %al,%al
  35:	74 11                	je     48 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag+0x48>
  37:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  3b:	48 3b 45 d8          	cmp    -0x28(%rbp),%rax
  3f:	74 07                	je     48 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag+0x48>
  41:	b8 01 00 00 00       	mov    $0x1,%eax
  46:	eb 05                	jmp    4d <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag+0x4d>
  48:	b8 00 00 00 00       	mov    $0x0,%eax
  4d:	84 c0                	test   %al,%al
  4f:	74 0f                	je     60 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag+0x60>
	  std::__throw_logic_error(__N("basic_string::"
  51:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 58 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag+0x58>
  58:	48 89 c7             	mov    %rax,%rdi
  5b:	e8 00 00 00 00       	call   60 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag+0x60>
	size_type __dnew = static_cast<size_type>(std::distance(__beg, __end));
  60:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
  64:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  68:	48 89 d6             	mov    %rdx,%rsi
  6b:	48 89 c7             	mov    %rax,%rdi
  6e:	e8 00 00 00 00       	call   73 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag+0x73>
  73:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
	if (__dnew > size_type(_S_local_capacity))
  77:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  7b:	48 83 f8 0f          	cmp    $0xf,%rax
  7f:	76 3d                	jbe    be <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag+0xbe>
	    _M_data(_M_create(__dnew, size_type(0)));
  81:	48 8d 4d f0          	lea    -0x10(%rbp),%rcx
  85:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  89:	ba 00 00 00 00       	mov    $0x0,%edx
  8e:	48 89 ce             	mov    %rcx,%rsi
  91:	48 89 c7             	mov    %rax,%rdi
  94:	e8 00 00 00 00       	call   99 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag+0x99>
  99:	48 89 c2             	mov    %rax,%rdx
  9c:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  a0:	48 89 d6             	mov    %rdx,%rsi
  a3:	48 89 c7             	mov    %rax,%rdi
  a6:	e8 00 00 00 00       	call   ab <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag+0xab>
	    _M_capacity(__dnew);
  ab:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  af:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  b3:	48 89 d6             	mov    %rdx,%rsi
  b6:	48 89 c7             	mov    %rax,%rdi
  b9:	e8 00 00 00 00       	call   be <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag+0xbe>
	  { this->_S_copy_chars(_M_data(), __beg, __end); }
  be:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  c2:	48 89 c7             	mov    %rax,%rdi
  c5:	e8 00 00 00 00       	call   ca <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag+0xca>
  ca:	48 89 c1             	mov    %rax,%rcx
  cd:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
  d1:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  d5:	48 89 c6             	mov    %rax,%rsi
  d8:	48 89 cf             	mov    %rcx,%rdi
  db:	e8 00 00 00 00       	call   e0 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag+0xe0>
	_M_set_length(__dnew);
  e0:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  e4:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  e8:	48 89 d6             	mov    %rdx,%rsi
  eb:	48 89 c7             	mov    %rax,%rdi
  ee:	e8 00 00 00 00       	call   f3 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag+0xf3>
      }
  f3:	90                   	nop
  f4:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  f8:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
  ff:	00 00 
 101:	74 05                	je     108 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag+0x108>
 103:	e8 00 00 00 00       	call   108 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag+0x108>
 108:	c9                   	leave  
 109:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx14__alloc_traitsISaIcEcE17_S_select_on_copyERKS1_:

0000000000000000 <_ZN9__gnu_cxx14__alloc_traitsISaIcEcE17_S_select_on_copyERKS1_>:
    static constexpr _Alloc _S_select_on_copy(const _Alloc& __a)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  10:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  14:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  1b:	00 00 
  1d:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  21:	31 c0                	xor    %eax,%eax
    { return _Base_type::select_on_container_copy_construction(__a); }
  23:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  27:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
  2b:	48 89 d6             	mov    %rdx,%rsi
  2e:	48 89 c7             	mov    %rax,%rdi
  31:	e8 00 00 00 00       	call   36 <_ZN9__gnu_cxx14__alloc_traitsISaIcEcE17_S_select_on_copyERKS1_+0x36>
  36:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  3a:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
  41:	00 00 
  43:	74 05                	je     4a <_ZN9__gnu_cxx14__alloc_traitsISaIcEcE17_S_select_on_copyERKS1_+0x4a>
  45:	e8 00 00 00 00       	call   4a <_ZN9__gnu_cxx14__alloc_traitsISaIcEcE17_S_select_on_copyERKS1_+0x4a>
  4a:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  4e:	c9                   	leave  
  4f:	c3                   	ret    

Disassembly of section .text._ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv:

0000000000000000 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv>:
      _M_get_allocator() const
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
      { return _M_dataplus; }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	5d                   	pop    %rbp
  11:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_>:
        _M_construct(_InIterator __beg, _InIterator __end)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
	  _M_construct_aux(__beg, __end, _Integral());
  18:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  1c:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
  20:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  24:	48 89 ce             	mov    %rcx,%rsi
  27:	48 89 c7             	mov    %rax,%rdi
  2a:	e8 00 00 00 00       	call   2f <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_+0x2f>
        }
  2f:	90                   	nop
  30:	c9                   	leave  
  31:	c3                   	ret    

Disassembly of section .text._ZSt4moveIRPN8MemTable8QuadlistEEONSt16remove_referenceIT_E4typeEOS5_:

0000000000000000 <_ZSt4moveIRPN8MemTable8QuadlistEEONSt16remove_referenceIT_E4typeEOS5_>:
    move(_Tp&& __t) noexcept
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    { return static_cast<typename std::remove_reference<_Tp>::type&&>(__t); }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	5d                   	pop    %rbp
  11:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE12emplace_backIJS2_EEERS2_DpOT_:

0000000000000000 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE12emplace_backIJS2_EEERS2_DpOT_>:
#if __cplusplus > 201402L
      typename vector<_Tp, _Alloc>::reference
#else
      void
#endif
      vector<_Tp, _Alloc>::
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 18          	sub    $0x18,%rsp
   d:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  11:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
      emplace_back(_Args&&... __args)
      {
	if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
  15:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  19:	48 8b 50 08          	mov    0x8(%rax),%rdx
  1d:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  21:	48 8b 40 10          	mov    0x10(%rax),%rax
  25:	48 39 c2             	cmp    %rax,%rdx
  28:	74 3c                	je     66 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE12emplace_backIJS2_EEERS2_DpOT_+0x66>
	  {
	    _GLIBCXX_ASAN_ANNOTATE_GROW(1);
	    _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish,
  2a:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  2e:	48 89 c7             	mov    %rax,%rdi
  31:	e8 00 00 00 00       	call   36 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE12emplace_backIJS2_EEERS2_DpOT_+0x36>
  36:	48 89 c2             	mov    %rax,%rdx
  39:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  3d:	48 8b 48 08          	mov    0x8(%rax),%rcx
  41:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  45:	48 89 ce             	mov    %rcx,%rsi
  48:	48 89 c7             	mov    %rax,%rdi
  4b:	e8 00 00 00 00       	call   50 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE12emplace_backIJS2_EEERS2_DpOT_+0x50>
				     std::forward<_Args>(__args)...);
	    ++this->_M_impl._M_finish;
  50:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  54:	48 8b 40 08          	mov    0x8(%rax),%rax
  58:	48 8d 50 08          	lea    0x8(%rax),%rdx
  5c:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  60:	48 89 50 08          	mov    %rdx,0x8(%rax)
  64:	eb 30                	jmp    96 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE12emplace_backIJS2_EEERS2_DpOT_+0x96>
	    _GLIBCXX_ASAN_ANNOTATE_GREW(1);
	  }
	else
	  _M_realloc_insert(end(), std::forward<_Args>(__args)...);
  66:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  6a:	48 89 c7             	mov    %rax,%rdi
  6d:	e8 00 00 00 00       	call   72 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE12emplace_backIJS2_EEERS2_DpOT_+0x72>
  72:	48 89 c3             	mov    %rax,%rbx
  75:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  79:	48 89 c7             	mov    %rax,%rdi
  7c:	e8 00 00 00 00       	call   81 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE12emplace_backIJS2_EEERS2_DpOT_+0x81>
  81:	48 89 c1             	mov    %rax,%rcx
  84:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  88:	48 89 da             	mov    %rbx,%rdx
  8b:	48 89 ce             	mov    %rcx,%rsi
  8e:	48 89 c7             	mov    %rax,%rdi
  91:	e8 00 00 00 00       	call   96 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE12emplace_backIJS2_EEERS2_DpOT_+0x96>
#if __cplusplus > 201402L
	return back();
  96:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  9a:	48 89 c7             	mov    %rax,%rdi
  9d:	e8 00 00 00 00       	call   a2 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE12emplace_backIJS2_EEERS2_DpOT_+0xa2>
#endif
      }
  a2:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  a6:	c9                   	leave  
  a7:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx14__alloc_traitsISaIcEcE27_S_propagate_on_copy_assignEv:

0000000000000000 <_ZN9__gnu_cxx14__alloc_traitsISaIcEcE27_S_propagate_on_copy_assignEv>:
    static constexpr bool _S_propagate_on_copy_assign()
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
    { return _Base_type::propagate_on_container_copy_assignment::value; }
   8:	b8 00 00 00 00       	mov    $0x0,%eax
   d:	5d                   	pop    %rbp
   e:	c3                   	ret    

Disassembly of section .text._ZNSt16allocator_traitsISaIcEE8allocateERS0_m:

0000000000000000 <_ZNSt16allocator_traitsISaIcEE8allocateERS0_m>:
       *  @param  __n  The number of objects to allocate space for.
       *
       *  Calls @c a.allocate(n)
      */
      _GLIBCXX_NODISCARD static _GLIBCXX20_CONSTEXPR pointer
      allocate(allocator_type& __a, size_type __n)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  10:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  14:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  18:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
  1c:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  20:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
	if (std::is_constant_evaluated())
  24:	e8 00 00 00 00       	call   29 <_ZNSt16allocator_traitsISaIcEE8allocateERS0_m+0x29>
  29:	84 c0                	test   %al,%al
  2b:	74 0e                	je     3b <_ZNSt16allocator_traitsISaIcEE8allocateERS0_m+0x3b>
	  return static_cast<_Tp*>(::operator new(__n * sizeof(_Tp)));
  2d:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  31:	48 89 c7             	mov    %rax,%rdi
  34:	e8 00 00 00 00       	call   39 <_ZNSt16allocator_traitsISaIcEE8allocateERS0_m+0x39>
  39:	eb 19                	jmp    54 <_ZNSt16allocator_traitsISaIcEE8allocateERS0_m+0x54>
	return __allocator_base<_Tp>::allocate(__n, 0);
  3b:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
  3f:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  43:	ba 00 00 00 00       	mov    $0x0,%edx
  48:	48 89 ce             	mov    %rcx,%rsi
  4b:	48 89 c7             	mov    %rax,%rdi
  4e:	e8 00 00 00 00       	call   53 <_ZNSt16allocator_traitsISaIcEE8allocateERS0_m+0x53>
  53:	90                   	nop
      { return __a.allocate(__n); }
  54:	c9                   	leave  
  55:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_>:
      assign(const basic_string& __str)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 38          	sub    $0x38,%rsp
   d:	48 89 7d c8          	mov    %rdi,-0x38(%rbp)
  11:	48 89 75 c0          	mov    %rsi,-0x40(%rbp)
  15:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  1c:	00 00 
  1e:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  22:	31 c0                	xor    %eax,%eax
	if (_Alloc_traits::_S_propagate_on_copy_assign())
  24:	e8 00 00 00 00       	call   29 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x29>
  29:	84 c0                	test   %al,%al
  2b:	0f 84 8d 01 00 00    	je     1be <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x1be>
	    if (!_Alloc_traits::_S_always_equal() && !_M_is_local()
  31:	e8 00 00 00 00       	call   36 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x36>
  36:	83 f0 01             	xor    $0x1,%eax
		&& _M_get_allocator() != __str._M_get_allocator())
  39:	84 c0                	test   %al,%al
  3b:	74 47                	je     84 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x84>
	    if (!_Alloc_traits::_S_always_equal() && !_M_is_local()
  3d:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  41:	48 89 c7             	mov    %rax,%rdi
  44:	e8 00 00 00 00       	call   49 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x49>
  49:	83 f0 01             	xor    $0x1,%eax
  4c:	84 c0                	test   %al,%al
  4e:	74 34                	je     84 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x84>
		&& _M_get_allocator() != __str._M_get_allocator())
  50:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
  54:	48 89 c7             	mov    %rax,%rdi
  57:	e8 00 00 00 00       	call   5c <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x5c>
  5c:	48 89 c3             	mov    %rax,%rbx
  5f:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  63:	48 89 c7             	mov    %rax,%rdi
  66:	e8 00 00 00 00       	call   6b <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x6b>
  6b:	48 89 de             	mov    %rbx,%rsi
  6e:	48 89 c7             	mov    %rax,%rdi
  71:	e8 00 00 00 00       	call   76 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x76>
  76:	83 f0 01             	xor    $0x1,%eax
  79:	84 c0                	test   %al,%al
  7b:	74 07                	je     84 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x84>
  7d:	b8 01 00 00 00       	mov    $0x1,%eax
  82:	eb 05                	jmp    89 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x89>
  84:	b8 00 00 00 00       	mov    $0x0,%eax
	    if (!_Alloc_traits::_S_always_equal() && !_M_is_local()
  89:	84 c0                	test   %al,%al
  8b:	0f 84 07 01 00 00    	je     198 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x198>
		if (__str.size() <= _S_local_capacity)
  91:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
  95:	48 89 c7             	mov    %rax,%rdi
  98:	e8 00 00 00 00       	call   9d <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x9d>
  9d:	48 83 f8 0f          	cmp    $0xf,%rax
  a1:	0f 96 c0             	setbe  %al
  a4:	84 c0                	test   %al,%al
  a6:	74 4b                	je     f3 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0xf3>
		    _M_destroy(_M_allocated_capacity);
  a8:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  ac:	48 8b 50 10          	mov    0x10(%rax),%rdx
  b0:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  b4:	48 89 d6             	mov    %rdx,%rsi
  b7:	48 89 c7             	mov    %rax,%rdi
  ba:	e8 00 00 00 00       	call   bf <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0xbf>
		    _M_data(_M_local_data());
  bf:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  c3:	48 89 c7             	mov    %rax,%rdi
  c6:	e8 00 00 00 00       	call   cb <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0xcb>
  cb:	48 89 c2             	mov    %rax,%rdx
  ce:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  d2:	48 89 d6             	mov    %rdx,%rsi
  d5:	48 89 c7             	mov    %rax,%rdi
  d8:	e8 00 00 00 00       	call   dd <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0xdd>
		    _M_set_length(0);
  dd:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  e1:	be 00 00 00 00       	mov    $0x0,%esi
  e6:	48 89 c7             	mov    %rax,%rdi
  e9:	e8 00 00 00 00       	call   ee <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0xee>
  ee:	e9 a5 00 00 00       	jmp    198 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x198>
		    const auto __len = __str.size();
  f3:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
  f7:	48 89 c7             	mov    %rax,%rdi
  fa:	e8 00 00 00 00       	call   ff <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0xff>
  ff:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
		    auto __alloc = __str._M_get_allocator();
 103:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
 107:	48 89 c7             	mov    %rax,%rdi
 10a:	e8 00 00 00 00       	call   10f <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x10f>
 10f:	48 89 c2             	mov    %rax,%rdx
 112:	48 8d 45 d7          	lea    -0x29(%rbp),%rax
 116:	48 89 d6             	mov    %rdx,%rsi
 119:	48 89 c7             	mov    %rax,%rdi
 11c:	e8 00 00 00 00       	call   121 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x121>
		    auto __ptr = _Alloc_traits::allocate(__alloc, __len + 1);
 121:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 125:	48 8d 50 01          	lea    0x1(%rax),%rdx
 129:	48 8d 45 d7          	lea    -0x29(%rbp),%rax
 12d:	48 89 d6             	mov    %rdx,%rsi
 130:	48 89 c7             	mov    %rax,%rdi
 133:	e8 00 00 00 00       	call   138 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x138>
 138:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
		    _M_destroy(_M_allocated_capacity);
 13c:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
 140:	48 8b 50 10          	mov    0x10(%rax),%rdx
 144:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
 148:	48 89 d6             	mov    %rdx,%rsi
 14b:	48 89 c7             	mov    %rax,%rdi
 14e:	e8 00 00 00 00       	call   153 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x153>
		    _M_data(__ptr);
 153:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
 157:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
 15b:	48 89 d6             	mov    %rdx,%rsi
 15e:	48 89 c7             	mov    %rax,%rdi
 161:	e8 00 00 00 00       	call   166 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x166>
		    _M_capacity(__len);
 166:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
 16a:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
 16e:	48 89 d6             	mov    %rdx,%rsi
 171:	48 89 c7             	mov    %rax,%rdi
 174:	e8 00 00 00 00       	call   179 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x179>
		    _M_set_length(__len);
 179:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
 17d:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
 181:	48 89 d6             	mov    %rdx,%rsi
 184:	48 89 c7             	mov    %rax,%rdi
 187:	e8 00 00 00 00       	call   18c <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x18c>
		  }
 18c:	48 8d 45 d7          	lea    -0x29(%rbp),%rax
 190:	48 89 c7             	mov    %rax,%rdi
 193:	e8 00 00 00 00       	call   198 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x198>
	    std::__alloc_on_copy(_M_get_allocator(), __str._M_get_allocator());
 198:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
 19c:	48 89 c7             	mov    %rax,%rdi
 19f:	e8 00 00 00 00       	call   1a4 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x1a4>
 1a4:	48 89 c3             	mov    %rax,%rbx
 1a7:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
 1ab:	48 89 c7             	mov    %rax,%rdi
 1ae:	e8 00 00 00 00       	call   1b3 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x1b3>
 1b3:	48 89 de             	mov    %rbx,%rsi
 1b6:	48 89 c7             	mov    %rax,%rdi
 1b9:	e8 00 00 00 00       	call   1be <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x1be>
	this->_M_assign(__str);
 1be:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
 1c2:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
 1c6:	48 89 d6             	mov    %rdx,%rsi
 1c9:	48 89 c7             	mov    %rax,%rdi
 1cc:	e8 00 00 00 00       	call   1d1 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x1d1>
	return *this;
 1d1:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
      }
 1d5:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
 1d9:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
 1e0:	00 00 
 1e2:	74 25                	je     209 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x209>
 1e4:	eb 1e                	jmp    204 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x204>
 1e6:	f3 0f 1e fa          	endbr64 
		  }
 1ea:	48 89 c3             	mov    %rax,%rbx
 1ed:	48 8d 45 d7          	lea    -0x29(%rbp),%rax
 1f1:	48 89 c7             	mov    %rax,%rdi
 1f4:	e8 00 00 00 00       	call   1f9 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x1f9>
 1f9:	48 89 d8             	mov    %rbx,%rax
 1fc:	48 89 c7             	mov    %rax,%rdi
 1ff:	e8 00 00 00 00       	call   204 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x204>
      }
 204:	e8 00 00 00 00       	call   209 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_+0x209>
 209:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
 20d:	c9                   	leave  
 20e:	c3                   	ret    

Disassembly of section .text._ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE4seedEm:

0000000000000000 <_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE4seedEm>:
	   size_t __w, size_t __n, size_t __m, size_t __r,
	   _UIntType __a, size_t __u, _UIntType __d, size_t __s,
	   _UIntType __b, size_t __t, _UIntType __c, size_t __l,
	   _UIntType __f>
    void
    mersenne_twister_engine<_UIntType, __w, __n, __m, __r, __a, __u, __d,
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  10:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
			    __s, __b, __t, __c, __l, __f>::
    seed(result_type __sd)
    {
      _M_x[0] = __detail::__mod<_UIntType,
	__detail::_Shift<_UIntType, __w>::__value>(__sd);
  14:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  18:	48 89 c7             	mov    %rax,%rdi
  1b:	e8 00 00 00 00       	call   20 <_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE4seedEm+0x20>
      _M_x[0] = __detail::__mod<_UIntType,
  20:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  24:	48 89 02             	mov    %rax,(%rdx)

      for (size_t __i = 1; __i < state_size; ++__i)
  27:	48 c7 45 f0 01 00 00 	movq   $0x1,-0x10(%rbp)
  2e:	00 
  2f:	eb 5c                	jmp    8d <_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE4seedEm+0x8d>
	{
	  _UIntType __x = _M_x[__i - 1];
  31:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  35:	48 8d 50 ff          	lea    -0x1(%rax),%rdx
  39:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  3d:	48 8b 04 d0          	mov    (%rax,%rdx,8),%rax
  41:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
	  __x ^= __x >> (__w - 2);
  45:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  49:	48 c1 e8 1e          	shr    $0x1e,%rax
  4d:	48 31 45 f8          	xor    %rax,-0x8(%rbp)
	  __x *= __f;
  51:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  55:	48 69 c0 65 89 07 6c 	imul   $0x6c078965,%rax,%rax
  5c:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
	  __x += __detail::__mod<_UIntType, __n>(__i);
  60:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  64:	48 89 c7             	mov    %rax,%rdi
  67:	e8 00 00 00 00       	call   6c <_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE4seedEm+0x6c>
  6c:	48 01 45 f8          	add    %rax,-0x8(%rbp)
	  _M_x[__i] = __detail::__mod<_UIntType,
	    __detail::_Shift<_UIntType, __w>::__value>(__x);
  70:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  74:	48 89 c7             	mov    %rax,%rdi
  77:	e8 00 00 00 00       	call   7c <_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE4seedEm+0x7c>
	  _M_x[__i] = __detail::__mod<_UIntType,
  7c:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  80:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
  84:	48 89 04 ca          	mov    %rax,(%rdx,%rcx,8)
      for (size_t __i = 1; __i < state_size; ++__i)
  88:	48 83 45 f0 01       	addq   $0x1,-0x10(%rbp)
  8d:	48 81 7d f0 6f 02 00 	cmpq   $0x26f,-0x10(%rbp)
  94:	00 
  95:	76 9a                	jbe    31 <_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE4seedEm+0x31>
	}
      _M_p = state_size;
  97:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  9b:	48 c7 80 80 13 00 00 	movq   $0x270,0x1380(%rax)
  a2:	70 02 00 00 
    }
  a6:	90                   	nop
  a7:	c9                   	leave  
  a8:	c3                   	ret    

Disassembly of section .text._ZNSt25uniform_real_distributionIdE10param_typeC2Edd:

0000000000000000 <_ZNSt25uniform_real_distributionIdE10param_typeC1Edd>:
	param_type(_RealType __a, _RealType __b = _RealType(1))
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	f2 0f 11 45 f0       	movsd  %xmm0,-0x10(%rbp)
  11:	f2 0f 11 4d e8       	movsd  %xmm1,-0x18(%rbp)
	: _M_a(__a), _M_b(__b)
  16:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  1a:	f2 0f 10 45 f0       	movsd  -0x10(%rbp),%xmm0
  1f:	f2 0f 11 00          	movsd  %xmm0,(%rax)
  23:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  27:	f2 0f 10 45 e8       	movsd  -0x18(%rbp),%xmm0
  2c:	f2 0f 11 40 08       	movsd  %xmm0,0x8(%rax)
	}
  31:	90                   	nop
  32:	5d                   	pop    %rbp
  33:	c3                   	ret    

Disassembly of section .text._ZNSt25uniform_real_distributionIdEclISt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEEEdRT_RKNS0_10param_typeE:

0000000000000000 <_ZNSt25uniform_real_distributionIdEclISt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEEEdRT_RKNS0_10param_typeE>:

      template<typename _UniformRandomNumberGenerator>
	result_type
	operator()(_UniformRandomNumberGenerator& __urng,
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 38          	sub    $0x38,%rsp
   d:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  11:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
  15:	48 89 55 c8          	mov    %rdx,-0x38(%rbp)
  19:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  20:	00 00 
  22:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  26:	31 c0                	xor    %eax,%eax
		   const param_type& __p)
	{
	  __detail::_Adaptor<_UniformRandomNumberGenerator, result_type>
	    __aurng(__urng);
  28:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
  2c:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  30:	48 89 d6             	mov    %rdx,%rsi
  33:	48 89 c7             	mov    %rax,%rdi
  36:	e8 00 00 00 00       	call   3b <_ZNSt25uniform_real_distributionIdEclISt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEEEdRT_RKNS0_10param_typeE+0x3b>
	  return (__aurng() * (__p.b() - __p.a())) + __p.a();
  3b:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  3f:	48 89 c7             	mov    %rax,%rdi
  42:	e8 00 00 00 00       	call   47 <_ZNSt25uniform_real_distributionIdEclISt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEEEdRT_RKNS0_10param_typeE+0x47>
  47:	f2 0f 11 45 c0       	movsd  %xmm0,-0x40(%rbp)
  4c:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  50:	48 89 c7             	mov    %rax,%rdi
  53:	e8 00 00 00 00       	call   58 <_ZNSt25uniform_real_distributionIdEclISt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEEEdRT_RKNS0_10param_typeE+0x58>
  58:	66 48 0f 7e c3       	movq   %xmm0,%rbx
  5d:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  61:	48 89 c7             	mov    %rax,%rdi
  64:	e8 00 00 00 00       	call   69 <_ZNSt25uniform_real_distributionIdEclISt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEEEdRT_RKNS0_10param_typeE+0x69>
  69:	66 48 0f 6e cb       	movq   %rbx,%xmm1
  6e:	f2 0f 5c c8          	subsd  %xmm0,%xmm1
  72:	f2 0f 59 4d c0       	mulsd  -0x40(%rbp),%xmm1
  77:	f2 0f 11 4d c0       	movsd  %xmm1,-0x40(%rbp)
  7c:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  80:	48 89 c7             	mov    %rax,%rdi
  83:	e8 00 00 00 00       	call   88 <_ZNSt25uniform_real_distributionIdEclISt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEEEdRT_RKNS0_10param_typeE+0x88>
  88:	f2 0f 58 45 c0       	addsd  -0x40(%rbp),%xmm0
  8d:	66 48 0f 7e c0       	movq   %xmm0,%rax
	}
  92:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  96:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
  9d:	00 00 
  9f:	74 05                	je     a6 <_ZNSt25uniform_real_distributionIdEclISt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEEEdRT_RKNS0_10param_typeE+0xa6>
  a1:	e8 00 00 00 00       	call   a6 <_ZNSt25uniform_real_distributionIdEclISt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEEEdRT_RKNS0_10param_typeE+0xa6>
  a6:	66 48 0f 6e c0       	movq   %rax,%xmm0
  ab:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  af:	c9                   	leave  
  b0:	c3                   	ret    

Disassembly of section .text._ZSt12construct_atIPN8MemTable8QuadlistEJRKS2_EEDTgsnwcvPvLi0E_T_pispcl7declvalIT0_EEEEPS6_DpOS7_:

0000000000000000 <_ZSt12construct_atIPN8MemTable8QuadlistEJRKS2_EEDTgsnwcvPvLi0E_T_pispcl7declvalIT0_EEEEPS6_DpOS7_>:
    }

#if __cplusplus >= 202002L
  template<typename _Tp, typename... _Args>
    constexpr auto
    construct_at(_Tp* __location, _Args&&... __args)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 18          	sub    $0x18,%rsp
   d:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  11:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    noexcept(noexcept(::new((void*)0) _Tp(std::declval<_Args>()...)))
    -> decltype(::new((void*)0) _Tp(std::declval<_Args>()...))
    { return ::new((void*)__location) _Tp(std::forward<_Args>(__args)...); }
  15:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  19:	48 89 c7             	mov    %rax,%rdi
  1c:	e8 00 00 00 00       	call   21 <_ZSt12construct_atIPN8MemTable8QuadlistEJRKS2_EEDTgsnwcvPvLi0E_T_pispcl7declvalIT0_EEEEPS6_DpOS7_+0x21>
  21:	48 8b 18             	mov    (%rax),%rbx
  24:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  28:	48 89 c6             	mov    %rax,%rsi
  2b:	bf 08 00 00 00       	mov    $0x8,%edi
  30:	e8 00 00 00 00       	call   35 <_ZSt12construct_atIPN8MemTable8QuadlistEJRKS2_EEDTgsnwcvPvLi0E_T_pispcl7declvalIT0_EEEEPS6_DpOS7_+0x35>
  35:	48 89 18             	mov    %rbx,(%rax)
  38:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  3c:	c9                   	leave  
  3d:	c3                   	ret    

Disassembly of section .text._ZNSt16allocator_traitsISaIPN8MemTable8QuadlistEEE9constructIS2_JRKS2_EEEvRS3_PT_DpOT0_:

0000000000000000 <_ZNSt16allocator_traitsISaIPN8MemTable8QuadlistEEE9constructIS2_JRKS2_EEEvRS3_PT_DpOT0_>:
       *  in C++11, C++14 and C++17. Changed in C++20 to call
       *  `std::construct_at(__p, std::forward<_Args>(__args)...)` instead.
      */
      template<typename _Up, typename... _Args>
	static _GLIBCXX20_CONSTEXPR void
	construct(allocator_type& __a __attribute__((__unused__)), _Up* __p,
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
	noexcept(std::is_nothrow_constructible<_Up, _Args...>::value)
	{
#if __cplusplus <= 201703L
	  __a.construct(__p, std::forward<_Args>(__args)...);
#else
	  std::construct_at(__p, std::forward<_Args>(__args)...);
  18:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  1c:	48 89 c7             	mov    %rax,%rdi
  1f:	e8 00 00 00 00       	call   24 <_ZNSt16allocator_traitsISaIPN8MemTable8QuadlistEEE9constructIS2_JRKS2_EEEvRS3_PT_DpOT0_+0x24>
  24:	48 89 c2             	mov    %rax,%rdx
  27:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  2b:	48 89 d6             	mov    %rdx,%rsi
  2e:	48 89 c7             	mov    %rax,%rdi
  31:	e8 00 00 00 00       	call   36 <_ZNSt16allocator_traitsISaIPN8MemTable8QuadlistEEE9constructIS2_JRKS2_EEEvRS3_PT_DpOT0_+0x36>
#endif
	}
  36:	90                   	nop
  37:	c9                   	leave  
  38:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE3endEv:

0000000000000000 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE3endEv>:
      end() _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  10:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  17:	00 00 
  19:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  1d:	31 c0                	xor    %eax,%eax
      { return iterator(this->_M_impl._M_finish); }
  1f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  23:	48 8d 50 08          	lea    0x8(%rax),%rdx
  27:	48 8d 45 f0          	lea    -0x10(%rbp),%rax
  2b:	48 89 d6             	mov    %rdx,%rsi
  2e:	48 89 c7             	mov    %rax,%rdi
  31:	e8 00 00 00 00       	call   36 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE3endEv+0x36>
  36:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  3a:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  3e:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
  45:	00 00 
  47:	74 05                	je     4e <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE3endEv+0x4e>
  49:	e8 00 00 00 00       	call   4e <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE3endEv+0x4e>
  4e:	c9                   	leave  
  4f:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJRKS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_:

0000000000000000 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJRKS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_>:

#if __cplusplus >= 201103L
  template<typename _Tp, typename _Alloc>
    template<typename... _Args>
      void
      vector<_Tp, _Alloc>::
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 68          	sub    $0x68,%rsp
   d:	48 89 7d a8          	mov    %rdi,-0x58(%rbp)
  11:	48 89 75 a0          	mov    %rsi,-0x60(%rbp)
  15:	48 89 55 98          	mov    %rdx,-0x68(%rbp)
  19:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  20:	00 00 
  22:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  26:	31 c0                	xor    %eax,%eax
    vector<_Tp, _Alloc>::
    _M_realloc_insert(iterator __position, const _Tp& __x)
#endif
    {
      const size_type __len =
	_M_check_len(size_type(1), "vector::_M_realloc_insert");
  28:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  2c:	48 8d 15 00 00 00 00 	lea    0x0(%rip),%rdx        # 33 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJRKS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0x33>
  33:	be 01 00 00 00       	mov    $0x1,%esi
  38:	48 89 c7             	mov    %rax,%rdi
  3b:	e8 00 00 00 00       	call   40 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJRKS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0x40>
  40:	48 89 45 b8          	mov    %rax,-0x48(%rbp)
      pointer __old_start = this->_M_impl._M_start;
  44:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  48:	48 8b 00             	mov    (%rax),%rax
  4b:	48 89 45 c0          	mov    %rax,-0x40(%rbp)
      pointer __old_finish = this->_M_impl._M_finish;
  4f:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  53:	48 8b 40 08          	mov    0x8(%rax),%rax
  57:	48 89 45 c8          	mov    %rax,-0x38(%rbp)
      const size_type __elems_before = __position - begin();
  5b:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  5f:	48 89 c7             	mov    %rax,%rdi
  62:	e8 00 00 00 00       	call   67 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJRKS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0x67>
  67:	48 89 45 b0          	mov    %rax,-0x50(%rbp)
  6b:	48 8d 55 b0          	lea    -0x50(%rbp),%rdx
  6f:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
  73:	48 89 d6             	mov    %rdx,%rsi
  76:	48 89 c7             	mov    %rax,%rdi
  79:	e8 00 00 00 00       	call   7e <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJRKS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0x7e>
  7e:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
      pointer __new_start(this->_M_allocate(__len));
  82:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  86:	48 8b 55 b8          	mov    -0x48(%rbp),%rdx
  8a:	48 89 d6             	mov    %rdx,%rsi
  8d:	48 89 c7             	mov    %rax,%rdi
  90:	e8 00 00 00 00       	call   95 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJRKS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0x95>
  95:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
      pointer __new_finish(__new_start);
  99:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  9d:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
	  // The order of the three operations is dictated by the C++11
	  // case, where the moves could alter a new element belonging
	  // to the existing vector.  This is an issue only for callers
	  // taking the element by lvalue ref (see last bullet of C++11
	  // [res.on.arguments]).
	  _Alloc_traits::construct(this->_M_impl,
  a1:	48 8b 45 98          	mov    -0x68(%rbp),%rax
  a5:	48 89 c7             	mov    %rax,%rdi
  a8:	e8 00 00 00 00       	call   ad <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJRKS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0xad>
  ad:	48 89 c2             	mov    %rax,%rdx
				   __new_start + __elems_before,
  b0:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  b4:	48 8d 0c c5 00 00 00 	lea    0x0(,%rax,8),%rcx
  bb:	00 
	  _Alloc_traits::construct(this->_M_impl,
  bc:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  c0:	48 01 c1             	add    %rax,%rcx
  c3:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  c7:	48 89 ce             	mov    %rcx,%rsi
  ca:	48 89 c7             	mov    %rax,%rdi
  cd:	e8 00 00 00 00       	call   d2 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJRKS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0xd2>
#if __cplusplus >= 201103L
				   std::forward<_Args>(__args)...);
#else
				   __x);
#endif
	  __new_finish = pointer();
  d2:	48 c7 45 e0 00 00 00 	movq   $0x0,-0x20(%rbp)
  d9:	00 

#if __cplusplus >= 201103L
	  if _GLIBCXX17_CONSTEXPR (_S_use_relocate())
	    {
	      __new_finish = _S_relocate(__old_start, __position.base(),
					 __new_start, _M_get_Tp_allocator());
  da:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  de:	48 89 c7             	mov    %rax,%rdi
  e1:	e8 00 00 00 00       	call   e6 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJRKS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0xe6>
  e6:	48 89 c3             	mov    %rax,%rbx
	      __new_finish = _S_relocate(__old_start, __position.base(),
  e9:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
  ed:	48 89 c7             	mov    %rax,%rdi
  f0:	e8 00 00 00 00       	call   f5 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJRKS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0xf5>
  f5:	48 8b 30             	mov    (%rax),%rsi
  f8:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
  fc:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
 100:	48 89 d9             	mov    %rbx,%rcx
 103:	48 89 c7             	mov    %rax,%rdi
 106:	e8 00 00 00 00       	call   10b <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJRKS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0x10b>
 10b:	48 89 45 e0          	mov    %rax,-0x20(%rbp)

	      ++__new_finish;
 10f:	48 83 45 e0 08       	addq   $0x8,-0x20(%rbp)

	      __new_finish = _S_relocate(__position.base(), __old_finish,
					 __new_finish, _M_get_Tp_allocator());
 114:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
 118:	48 89 c7             	mov    %rax,%rdi
 11b:	e8 00 00 00 00       	call   120 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJRKS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0x120>
 120:	48 89 c3             	mov    %rax,%rbx
	      __new_finish = _S_relocate(__position.base(), __old_finish,
 123:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
 127:	48 89 c7             	mov    %rax,%rdi
 12a:	e8 00 00 00 00       	call   12f <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJRKS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0x12f>
 12f:	48 8b 00             	mov    (%rax),%rax
 132:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
 136:	48 8b 75 c8          	mov    -0x38(%rbp),%rsi
 13a:	48 89 d9             	mov    %rbx,%rcx
 13d:	48 89 c7             	mov    %rax,%rdi
 140:	e8 00 00 00 00       	call   145 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJRKS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0x145>
 145:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
#if __cplusplus >= 201103L
      if _GLIBCXX17_CONSTEXPR (!_S_use_relocate())
#endif
	std::_Destroy(__old_start, __old_finish, _M_get_Tp_allocator());
      _GLIBCXX_ASAN_ANNOTATE_REINIT;
      _M_deallocate(__old_start,
 149:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
		    this->_M_impl._M_end_of_storage - __old_start);
 14d:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
 151:	48 8b 52 10          	mov    0x10(%rdx),%rdx
 155:	48 2b 55 c0          	sub    -0x40(%rbp),%rdx
 159:	48 c1 fa 03          	sar    $0x3,%rdx
      _M_deallocate(__old_start,
 15d:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
 161:	48 89 ce             	mov    %rcx,%rsi
 164:	48 89 c7             	mov    %rax,%rdi
 167:	e8 00 00 00 00       	call   16c <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJRKS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0x16c>
      this->_M_impl._M_start = __new_start;
 16c:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
 170:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
 174:	48 89 10             	mov    %rdx,(%rax)
      this->_M_impl._M_finish = __new_finish;
 177:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
 17b:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
 17f:	48 89 50 08          	mov    %rdx,0x8(%rax)
      this->_M_impl._M_end_of_storage = __new_start + __len;
 183:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
 187:	48 8d 14 c5 00 00 00 	lea    0x0(,%rax,8),%rdx
 18e:	00 
 18f:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 193:	48 01 c2             	add    %rax,%rdx
 196:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
 19a:	48 89 50 10          	mov    %rdx,0x10(%rax)
    }
 19e:	90                   	nop
 19f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
 1a3:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
 1aa:	00 00 
 1ac:	74 05                	je     1b3 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJRKS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0x1b3>
 1ae:	e8 00 00 00 00       	call   1b3 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJRKS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0x1b3>
 1b3:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
 1b7:	c9                   	leave  
 1b8:	c3                   	ret    

Disassembly of section .text._ZNSaIN7KVStore7ssLevelEEC2Ev:

0000000000000000 <_ZNSaIN7KVStore7ssLevelEEC1Ev>:
      allocator() _GLIBCXX_NOTHROW { }
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZNSaIN7KVStore7ssLevelEEC1Ev+0x1c>
  1c:	90                   	nop
  1d:	c9                   	leave  
  1e:	c3                   	ret    

Disassembly of section .text._ZNSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EE17_Vector_impl_dataC2Ev:

0000000000000000 <_ZNSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EE17_Vector_impl_dataC1Ev>:
	_Vector_impl_data() _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
	: _M_start(), _M_finish(), _M_end_of_storage()
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	48 c7 00 00 00 00 00 	movq   $0x0,(%rax)
  17:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  1b:	48 c7 40 08 00 00 00 	movq   $0x0,0x8(%rax)
  22:	00 
  23:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  27:	48 c7 40 10 00 00 00 	movq   $0x0,0x10(%rax)
  2e:	00 
	{ }
  2f:	90                   	nop
  30:	5d                   	pop    %rbp
  31:	c3                   	ret    

Disassembly of section .text._ZNSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EE13_M_deallocateEPS1_m:

0000000000000000 <_ZNSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EE13_M_deallocateEPS1_m>:
      _M_deallocate(pointer __p, size_t __n)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
	if (__p)
  18:	48 83 7d f0 00       	cmpq   $0x0,-0x10(%rbp)
  1d:	74 17                	je     36 <_ZNSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EE13_M_deallocateEPS1_m+0x36>
	  _Tr::deallocate(_M_impl, __p, __n);
  1f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  23:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  27:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
  2b:	48 89 ce             	mov    %rcx,%rsi
  2e:	48 89 c7             	mov    %rax,%rdi
  31:	e8 00 00 00 00       	call   36 <_ZNSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EE13_M_deallocateEPS1_m+0x36>
      }
  36:	90                   	nop
  37:	c9                   	leave  
  38:	c3                   	ret    

Disassembly of section .text._ZNSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EE19_M_get_Tp_allocatorEv:

0000000000000000 <_ZNSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EE19_M_get_Tp_allocatorEv>:
      _M_get_Tp_allocator() _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
      { return this->_M_impl; }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	5d                   	pop    %rbp
  11:	c3                   	ret    

Disassembly of section .text._ZSt8_DestroyIPN7KVStore7ssLevelES1_EvT_S3_RSaIT0_E:

0000000000000000 <_ZSt8_DestroyIPN7KVStore7ssLevelES1_EvT_S3_RSaIT0_E>:
#endif
    }

  template<typename _ForwardIterator, typename _Tp>
    inline void
    _Destroy(_ForwardIterator __first, _ForwardIterator __last,
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
	     allocator<_Tp>&)
    {
      _Destroy(__first, __last);
  18:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  1c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  20:	48 89 d6             	mov    %rdx,%rsi
  23:	48 89 c7             	mov    %rax,%rdi
  26:	e8 00 00 00 00       	call   2b <_ZSt8_DestroyIPN7KVStore7ssLevelES1_EvT_S3_RSaIT0_E+0x2b>
    }
  2b:	90                   	nop
  2c:	c9                   	leave  
  2d:	c3                   	ret    

Disassembly of section .text._ZNSaIPN8MemTable8QuadlistEEC2Ev:

0000000000000000 <_ZNSaIPN8MemTable8QuadlistEEC1Ev>:
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZNSaIPN8MemTable8QuadlistEEC1Ev+0x1c>
  1c:	90                   	nop
  1d:	c9                   	leave  
  1e:	c3                   	ret    

Disassembly of section .text._ZNSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EE17_Vector_impl_dataC2Ev:

0000000000000000 <_ZNSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EE17_Vector_impl_dataC1Ev>:
	_Vector_impl_data() _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
	: _M_start(), _M_finish(), _M_end_of_storage()
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	48 c7 00 00 00 00 00 	movq   $0x0,(%rax)
  17:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  1b:	48 c7 40 08 00 00 00 	movq   $0x0,0x8(%rax)
  22:	00 
  23:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  27:	48 c7 40 10 00 00 00 	movq   $0x0,0x10(%rax)
  2e:	00 
	{ }
  2f:	90                   	nop
  30:	5d                   	pop    %rbp
  31:	c3                   	ret    

Disassembly of section .text._ZNSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EE13_M_deallocateEPS2_m:

0000000000000000 <_ZNSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EE13_M_deallocateEPS2_m>:
      _M_deallocate(pointer __p, size_t __n)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
	if (__p)
  18:	48 83 7d f0 00       	cmpq   $0x0,-0x10(%rbp)
  1d:	74 17                	je     36 <_ZNSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EE13_M_deallocateEPS2_m+0x36>
	  _Tr::deallocate(_M_impl, __p, __n);
  1f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  23:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  27:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
  2b:	48 89 ce             	mov    %rcx,%rsi
  2e:	48 89 c7             	mov    %rax,%rdi
  31:	e8 00 00 00 00       	call   36 <_ZNSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EE13_M_deallocateEPS2_m+0x36>
      }
  36:	90                   	nop
  37:	c9                   	leave  
  38:	c3                   	ret    

Disassembly of section .text._ZNSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EE19_M_get_Tp_allocatorEv:

0000000000000000 <_ZNSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EE19_M_get_Tp_allocatorEv>:
      _M_get_Tp_allocator() _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
      { return this->_M_impl; }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	5d                   	pop    %rbp
  11:	c3                   	ret    

Disassembly of section .text._ZSt8_DestroyIPPN8MemTable8QuadlistES2_EvT_S4_RSaIT0_E:

0000000000000000 <_ZSt8_DestroyIPPN8MemTable8QuadlistES2_EvT_S4_RSaIT0_E>:
    _Destroy(_ForwardIterator __first, _ForwardIterator __last,
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
      _Destroy(__first, __last);
  18:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  1c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  20:	48 89 d6             	mov    %rdx,%rsi
  23:	48 89 c7             	mov    %rax,%rdi
  26:	e8 00 00 00 00       	call   2b <_ZSt8_DestroyIPPN8MemTable8QuadlistES2_EvT_S4_RSaIT0_E+0x2b>
    }
  2b:	90                   	nop
  2c:	c9                   	leave  
  2d:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm>:
    basic_string<_CharT, _Traits, _Alloc>::
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 28          	sub    $0x28,%rsp
   d:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  11:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  15:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
      if (__capacity > max_size())
  19:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  1d:	48 8b 18             	mov    (%rax),%rbx
  20:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  24:	48 89 c7             	mov    %rax,%rdi
  27:	e8 00 00 00 00       	call   2c <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm+0x2c>
  2c:	48 39 c3             	cmp    %rax,%rbx
  2f:	0f 97 c0             	seta   %al
  32:	84 c0                	test   %al,%al
  34:	74 0f                	je     45 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm+0x45>
	std::__throw_length_error(__N("basic_string::_M_create"));
  36:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 3d <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm+0x3d>
  3d:	48 89 c7             	mov    %rax,%rdi
  40:	e8 00 00 00 00       	call   45 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm+0x45>
      if (__capacity > __old_capacity && __capacity < 2 * __old_capacity)
  45:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  49:	48 8b 00             	mov    (%rax),%rax
  4c:	48 39 45 d8          	cmp    %rax,-0x28(%rbp)
  50:	73 52                	jae    a4 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm+0xa4>
  52:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  56:	48 8b 00             	mov    (%rax),%rax
  59:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
  5d:	48 01 d2             	add    %rdx,%rdx
  60:	48 39 d0             	cmp    %rdx,%rax
  63:	73 3f                	jae    a4 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm+0xa4>
	  __capacity = 2 * __old_capacity;
  65:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  69:	48 8d 14 00          	lea    (%rax,%rax,1),%rdx
  6d:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  71:	48 89 10             	mov    %rdx,(%rax)
	  if (__capacity > max_size())
  74:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  78:	48 8b 18             	mov    (%rax),%rbx
  7b:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  7f:	48 89 c7             	mov    %rax,%rdi
  82:	e8 00 00 00 00       	call   87 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm+0x87>
  87:	48 39 c3             	cmp    %rax,%rbx
  8a:	0f 97 c0             	seta   %al
  8d:	84 c0                	test   %al,%al
  8f:	74 13                	je     a4 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm+0xa4>
	    __capacity = max_size();
  91:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  95:	48 89 c7             	mov    %rax,%rdi
  98:	e8 00 00 00 00       	call   9d <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm+0x9d>
  9d:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
  a1:	48 89 02             	mov    %rax,(%rdx)
      return _Alloc_traits::allocate(_M_get_allocator(), __capacity + 1);
  a4:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  a8:	48 8b 00             	mov    (%rax),%rax
  ab:	48 8d 58 01          	lea    0x1(%rax),%rbx
  af:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  b3:	48 89 c7             	mov    %rax,%rdi
  b6:	e8 00 00 00 00       	call   bb <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm+0xbb>
  bb:	48 89 de             	mov    %rbx,%rsi
  be:	48 89 c7             	mov    %rax,%rdi
  c1:	e8 00 00 00 00       	call   c6 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm+0xc6>
    }
  c6:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  ca:	c9                   	leave  
  cb:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_S_copyEPcPKcm:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_S_copyEPcPKcm>:
      _S_copy(_CharT* __d, const _CharT* __s, size_type __n)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
	if (__n == 1)
  18:	48 83 7d e8 01       	cmpq   $0x1,-0x18(%rbp)
  1d:	75 15                	jne    34 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_S_copyEPcPKcm+0x34>
	  traits_type::assign(*__d, *__s);
  1f:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  23:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  27:	48 89 d6             	mov    %rdx,%rsi
  2a:	48 89 c7             	mov    %rax,%rdi
  2d:	e8 00 00 00 00       	call   32 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_S_copyEPcPKcm+0x32>
      }
  32:	eb 17                	jmp    4b <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_S_copyEPcPKcm+0x4b>
	  traits_type::copy(__d, __s, __n);
  34:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  38:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
  3c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  40:	48 89 ce             	mov    %rcx,%rsi
  43:	48 89 c7             	mov    %rax,%rdi
  46:	e8 00 00 00 00       	call   4b <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_S_copyEPcPKcm+0x4b>
      }
  4b:	90                   	nop
  4c:	c9                   	leave  
  4d:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEmmPKcm:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEmmPKcm>:

  template<typename _CharT, typename _Traits, typename _Alloc>
    void
    basic_string<_CharT, _Traits, _Alloc>::
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 50          	sub    $0x50,%rsp
   c:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  10:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
  14:	48 89 55 c8          	mov    %rdx,-0x38(%rbp)
  18:	48 89 4d c0          	mov    %rcx,-0x40(%rbp)
  1c:	4c 89 45 b8          	mov    %r8,-0x48(%rbp)
  20:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  27:	00 00 
  29:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  2d:	31 c0                	xor    %eax,%eax
    _M_mutate(size_type __pos, size_type __len1, const _CharT* __s,
	      size_type __len2)
    {
      const size_type __how_much = length() - __pos - __len1;
  2f:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  33:	48 89 c7             	mov    %rax,%rdi
  36:	e8 00 00 00 00       	call   3b <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEmmPKcm+0x3b>
  3b:	48 2b 45 d0          	sub    -0x30(%rbp),%rax
  3f:	48 2b 45 c8          	sub    -0x38(%rbp),%rax
  43:	48 89 45 e8          	mov    %rax,-0x18(%rbp)

      size_type __new_capacity = length() + __len2 - __len1;
  47:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  4b:	48 89 c7             	mov    %rax,%rdi
  4e:	e8 00 00 00 00       	call   53 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEmmPKcm+0x53>
  53:	48 8b 55 b8          	mov    -0x48(%rbp),%rdx
  57:	48 01 d0             	add    %rdx,%rax
  5a:	48 2b 45 c8          	sub    -0x38(%rbp),%rax
  5e:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
      pointer __r = _M_create(__new_capacity, capacity());
  62:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  66:	48 89 c7             	mov    %rax,%rdi
  69:	e8 00 00 00 00       	call   6e <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEmmPKcm+0x6e>
  6e:	48 89 c2             	mov    %rax,%rdx
  71:	48 8d 4d e0          	lea    -0x20(%rbp),%rcx
  75:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  79:	48 89 ce             	mov    %rcx,%rsi
  7c:	48 89 c7             	mov    %rax,%rdi
  7f:	e8 00 00 00 00       	call   84 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEmmPKcm+0x84>
  84:	48 89 45 f0          	mov    %rax,-0x10(%rbp)

      if (__pos)
  88:	48 83 7d d0 00       	cmpq   $0x0,-0x30(%rbp)
  8d:	74 22                	je     b1 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEmmPKcm+0xb1>
	this->_S_copy(__r, _M_data(), __pos);
  8f:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  93:	48 89 c7             	mov    %rax,%rdi
  96:	e8 00 00 00 00       	call   9b <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEmmPKcm+0x9b>
  9b:	48 89 c1             	mov    %rax,%rcx
  9e:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
  a2:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  a6:	48 89 ce             	mov    %rcx,%rsi
  a9:	48 89 c7             	mov    %rax,%rdi
  ac:	e8 00 00 00 00       	call   b1 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEmmPKcm+0xb1>
      if (__s && __len2)
  b1:	48 83 7d c0 00       	cmpq   $0x0,-0x40(%rbp)
  b6:	74 26                	je     de <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEmmPKcm+0xde>
  b8:	48 83 7d b8 00       	cmpq   $0x0,-0x48(%rbp)
  bd:	74 1f                	je     de <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEmmPKcm+0xde>
	this->_S_copy(__r + __pos, __s, __len2);
  bf:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  c3:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  c7:	48 8d 0c 02          	lea    (%rdx,%rax,1),%rcx
  cb:	48 8b 55 b8          	mov    -0x48(%rbp),%rdx
  cf:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
  d3:	48 89 c6             	mov    %rax,%rsi
  d6:	48 89 cf             	mov    %rcx,%rdi
  d9:	e8 00 00 00 00       	call   de <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEmmPKcm+0xde>
      if (__how_much)
  de:	48 83 7d e8 00       	cmpq   $0x0,-0x18(%rbp)
  e3:	74 3d                	je     122 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEmmPKcm+0x122>
	this->_S_copy(__r + __pos + __len2,
		      _M_data() + __pos + __len1, __how_much);
  e5:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  e9:	48 89 c7             	mov    %rax,%rdi
  ec:	e8 00 00 00 00       	call   f1 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEmmPKcm+0xf1>
  f1:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
  f5:	48 8b 55 c8          	mov    -0x38(%rbp),%rdx
  f9:	48 01 ca             	add    %rcx,%rdx
  fc:	48 8d 34 10          	lea    (%rax,%rdx,1),%rsi
	this->_S_copy(__r + __pos + __len2,
 100:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
 104:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
 108:	48 01 c2             	add    %rax,%rdx
 10b:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
 10f:	48 8d 0c 02          	lea    (%rdx,%rax,1),%rcx
 113:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
 117:	48 89 c2             	mov    %rax,%rdx
 11a:	48 89 cf             	mov    %rcx,%rdi
 11d:	e8 00 00 00 00       	call   122 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEmmPKcm+0x122>

      _M_dispose();
 122:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 126:	48 89 c7             	mov    %rax,%rdi
 129:	e8 00 00 00 00       	call   12e <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEmmPKcm+0x12e>
      _M_data(__r);
 12e:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
 132:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 136:	48 89 d6             	mov    %rdx,%rsi
 139:	48 89 c7             	mov    %rax,%rdi
 13c:	e8 00 00 00 00       	call   141 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEmmPKcm+0x141>
      _M_capacity(__new_capacity);
 141:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
 145:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 149:	48 89 d6             	mov    %rdx,%rsi
 14c:	48 89 c7             	mov    %rax,%rdi
 14f:	e8 00 00 00 00       	call   154 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEmmPKcm+0x154>
    }
 154:	90                   	nop
 155:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
 159:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
 160:	00 00 
 162:	74 05                	je     169 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEmmPKcm+0x169>
 164:	e8 00 00 00 00       	call   169 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_mutateEmmPKcm+0x169>
 169:	c9                   	leave  
 16a:	c3                   	ret    

Disassembly of section .text._ZNSt6chrono8durationIlSt5ratioILl1ELl1000EEEC2IlvEERKT_:

0000000000000000 <_ZNSt6chrono8durationIlSt5ratioILl1ELl1000EEEC1IlvEERKT_>:
	  constexpr explicit duration(const _Rep2& __rep)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
	  : __r(static_cast<rep>(__rep)) { }
  10:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  14:	48 8b 10             	mov    (%rax),%rdx
  17:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  1b:	48 89 10             	mov    %rdx,(%rax)
  1e:	90                   	nop
  1f:	5d                   	pop    %rbp
  20:	c3                   	ret    

Disassembly of section .text._ZSt12construct_atIN7KVStore7ssLevelEJRKS1_EEDTgsnwcvPvLi0E_T_pispcl7declvalIT0_EEEEPS5_DpOS6_:

0000000000000000 <_ZSt12construct_atIN7KVStore7ssLevelEJRKS1_EEDTgsnwcvPvLi0E_T_pispcl7declvalIT0_EEEEPS5_DpOS6_>:
    construct_at(_Tp* __location, _Args&&... __args)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 18          	sub    $0x18,%rsp
   d:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  11:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    { return ::new((void*)__location) _Tp(std::forward<_Args>(__args)...); }
  15:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  19:	48 89 c7             	mov    %rax,%rdi
  1c:	e8 00 00 00 00       	call   21 <_ZSt12construct_atIN7KVStore7ssLevelEJRKS1_EEDTgsnwcvPvLi0E_T_pispcl7declvalIT0_EEEEPS5_DpOS6_+0x21>
  21:	48 89 c3             	mov    %rax,%rbx
  24:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  28:	48 89 c6             	mov    %rax,%rsi
  2b:	bf 08 00 00 00       	mov    $0x8,%edi
  30:	e8 00 00 00 00       	call   35 <_ZSt12construct_atIN7KVStore7ssLevelEJRKS1_EEDTgsnwcvPvLi0E_T_pispcl7declvalIT0_EEEEPS5_DpOS6_+0x35>
  35:	48 8b 13             	mov    (%rbx),%rdx
  38:	48 89 10             	mov    %rdx,(%rax)
  3b:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  3f:	c9                   	leave  
  40:	c3                   	ret    

Disassembly of section .text._ZNSt16allocator_traitsISaIN7KVStore7ssLevelEEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_:

0000000000000000 <_ZNSt16allocator_traitsISaIN7KVStore7ssLevelEEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_>:
	construct(allocator_type& __a __attribute__((__unused__)), _Up* __p,
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
	  std::construct_at(__p, std::forward<_Args>(__args)...);
  18:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  1c:	48 89 c7             	mov    %rax,%rdi
  1f:	e8 00 00 00 00       	call   24 <_ZNSt16allocator_traitsISaIN7KVStore7ssLevelEEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_+0x24>
  24:	48 89 c2             	mov    %rax,%rdx
  27:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  2b:	48 89 d6             	mov    %rdx,%rsi
  2e:	48 89 c7             	mov    %rax,%rdi
  31:	e8 00 00 00 00       	call   36 <_ZNSt16allocator_traitsISaIN7KVStore7ssLevelEEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_+0x36>
	}
  36:	90                   	nop
  37:	c9                   	leave  
  38:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE3endEv:

0000000000000000 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE3endEv>:
      end() _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  10:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  17:	00 00 
  19:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  1d:	31 c0                	xor    %eax,%eax
      { return iterator(this->_M_impl._M_finish); }
  1f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  23:	48 8d 50 08          	lea    0x8(%rax),%rdx
  27:	48 8d 45 f0          	lea    -0x10(%rbp),%rax
  2b:	48 89 d6             	mov    %rdx,%rsi
  2e:	48 89 c7             	mov    %rax,%rdi
  31:	e8 00 00 00 00       	call   36 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE3endEv+0x36>
  36:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  3a:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  3e:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
  45:	00 00 
  47:	74 05                	je     4e <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE3endEv+0x4e>
  49:	e8 00 00 00 00       	call   4e <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE3endEv+0x4e>
  4e:	c9                   	leave  
  4f:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_:

0000000000000000 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_>:
      vector<_Tp, _Alloc>::
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 68          	sub    $0x68,%rsp
   d:	48 89 7d a8          	mov    %rdi,-0x58(%rbp)
  11:	48 89 75 a0          	mov    %rsi,-0x60(%rbp)
  15:	48 89 55 98          	mov    %rdx,-0x68(%rbp)
  19:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  20:	00 00 
  22:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  26:	31 c0                	xor    %eax,%eax
	_M_check_len(size_type(1), "vector::_M_realloc_insert");
  28:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  2c:	48 8d 15 00 00 00 00 	lea    0x0(%rip),%rdx        # 33 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_+0x33>
  33:	be 01 00 00 00       	mov    $0x1,%esi
  38:	48 89 c7             	mov    %rax,%rdi
  3b:	e8 00 00 00 00       	call   40 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_+0x40>
  40:	48 89 45 b8          	mov    %rax,-0x48(%rbp)
      pointer __old_start = this->_M_impl._M_start;
  44:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  48:	48 8b 00             	mov    (%rax),%rax
  4b:	48 89 45 c0          	mov    %rax,-0x40(%rbp)
      pointer __old_finish = this->_M_impl._M_finish;
  4f:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  53:	48 8b 40 08          	mov    0x8(%rax),%rax
  57:	48 89 45 c8          	mov    %rax,-0x38(%rbp)
      const size_type __elems_before = __position - begin();
  5b:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  5f:	48 89 c7             	mov    %rax,%rdi
  62:	e8 00 00 00 00       	call   67 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_+0x67>
  67:	48 89 45 b0          	mov    %rax,-0x50(%rbp)
  6b:	48 8d 55 b0          	lea    -0x50(%rbp),%rdx
  6f:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
  73:	48 89 d6             	mov    %rdx,%rsi
  76:	48 89 c7             	mov    %rax,%rdi
  79:	e8 00 00 00 00       	call   7e <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_+0x7e>
  7e:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
      pointer __new_start(this->_M_allocate(__len));
  82:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  86:	48 8b 55 b8          	mov    -0x48(%rbp),%rdx
  8a:	48 89 d6             	mov    %rdx,%rsi
  8d:	48 89 c7             	mov    %rax,%rdi
  90:	e8 00 00 00 00       	call   95 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_+0x95>
  95:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
      pointer __new_finish(__new_start);
  99:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  9d:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
	  _Alloc_traits::construct(this->_M_impl,
  a1:	48 8b 45 98          	mov    -0x68(%rbp),%rax
  a5:	48 89 c7             	mov    %rax,%rdi
  a8:	e8 00 00 00 00       	call   ad <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_+0xad>
  ad:	48 89 c2             	mov    %rax,%rdx
				   __new_start + __elems_before,
  b0:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  b4:	48 8d 0c c5 00 00 00 	lea    0x0(,%rax,8),%rcx
  bb:	00 
	  _Alloc_traits::construct(this->_M_impl,
  bc:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  c0:	48 01 c1             	add    %rax,%rcx
  c3:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  c7:	48 89 ce             	mov    %rcx,%rsi
  ca:	48 89 c7             	mov    %rax,%rdi
  cd:	e8 00 00 00 00       	call   d2 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_+0xd2>
	  __new_finish = pointer();
  d2:	48 c7 45 e0 00 00 00 	movq   $0x0,-0x20(%rbp)
  d9:	00 
					 __new_start, _M_get_Tp_allocator());
  da:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  de:	48 89 c7             	mov    %rax,%rdi
  e1:	e8 00 00 00 00       	call   e6 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_+0xe6>
  e6:	48 89 c3             	mov    %rax,%rbx
	      __new_finish = _S_relocate(__old_start, __position.base(),
  e9:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
  ed:	48 89 c7             	mov    %rax,%rdi
  f0:	e8 00 00 00 00       	call   f5 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_+0xf5>
  f5:	48 8b 30             	mov    (%rax),%rsi
  f8:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
  fc:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
 100:	48 89 d9             	mov    %rbx,%rcx
 103:	48 89 c7             	mov    %rax,%rdi
 106:	e8 00 00 00 00       	call   10b <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_+0x10b>
 10b:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
	      ++__new_finish;
 10f:	48 83 45 e0 08       	addq   $0x8,-0x20(%rbp)
					 __new_finish, _M_get_Tp_allocator());
 114:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
 118:	48 89 c7             	mov    %rax,%rdi
 11b:	e8 00 00 00 00       	call   120 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_+0x120>
 120:	48 89 c3             	mov    %rax,%rbx
	      __new_finish = _S_relocate(__position.base(), __old_finish,
 123:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
 127:	48 89 c7             	mov    %rax,%rdi
 12a:	e8 00 00 00 00       	call   12f <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_+0x12f>
 12f:	48 8b 00             	mov    (%rax),%rax
 132:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
 136:	48 8b 75 c8          	mov    -0x38(%rbp),%rsi
 13a:	48 89 d9             	mov    %rbx,%rcx
 13d:	48 89 c7             	mov    %rax,%rdi
 140:	e8 00 00 00 00       	call   145 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_+0x145>
 145:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
      _M_deallocate(__old_start,
 149:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
		    this->_M_impl._M_end_of_storage - __old_start);
 14d:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
 151:	48 8b 52 10          	mov    0x10(%rdx),%rdx
 155:	48 2b 55 c0          	sub    -0x40(%rbp),%rdx
 159:	48 c1 fa 03          	sar    $0x3,%rdx
      _M_deallocate(__old_start,
 15d:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
 161:	48 89 ce             	mov    %rcx,%rsi
 164:	48 89 c7             	mov    %rax,%rdi
 167:	e8 00 00 00 00       	call   16c <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_+0x16c>
      this->_M_impl._M_start = __new_start;
 16c:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
 170:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
 174:	48 89 10             	mov    %rdx,(%rax)
      this->_M_impl._M_finish = __new_finish;
 177:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
 17b:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
 17f:	48 89 50 08          	mov    %rdx,0x8(%rax)
      this->_M_impl._M_end_of_storage = __new_start + __len;
 183:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
 187:	48 8d 14 c5 00 00 00 	lea    0x0(,%rax,8),%rdx
 18e:	00 
 18f:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 193:	48 01 c2             	add    %rax,%rdx
 196:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
 19a:	48 89 50 10          	mov    %rdx,0x10(%rax)
    }
 19e:	90                   	nop
 19f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
 1a3:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
 1aa:	00 00 
 1ac:	74 05                	je     1b3 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_+0x1b3>
 1ae:	e8 00 00 00 00       	call   1b3 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_+0x1b3>
 1b3:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
 1b7:	c9                   	leave  
 1b8:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_destroyEm:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_destroyEm>:
      _M_destroy(size_type __size) throw()
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	41 54                	push   %r12
   a:	53                   	push   %rbx
   b:	48 83 ec 10          	sub    $0x10,%rsp
   f:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  13:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
      { _Alloc_traits::deallocate(_M_get_allocator(), _M_data(), __size + 1); }
  17:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  1b:	48 8d 58 01          	lea    0x1(%rax),%rbx
  1f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  23:	48 89 c7             	mov    %rax,%rdi
  26:	e8 00 00 00 00       	call   2b <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_destroyEm+0x2b>
  2b:	49 89 c4             	mov    %rax,%r12
  2e:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  32:	48 89 c7             	mov    %rax,%rdi
  35:	e8 00 00 00 00       	call   3a <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_destroyEm+0x3a>
  3a:	48 89 da             	mov    %rbx,%rdx
  3d:	4c 89 e6             	mov    %r12,%rsi
  40:	48 89 c7             	mov    %rax,%rdi
  43:	e8 00 00 00 00       	call   48 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_destroyEm+0x48>
  48:	90                   	nop
  49:	48 83 c4 10          	add    $0x10,%rsp
  4d:	5b                   	pop    %rbx
  4e:	41 5c                	pop    %r12
  50:	5d                   	pop    %rbp
  51:	c3                   	ret    

Disassembly of section .text._ZSt15__alloc_on_moveISaIcEEvRT_S2_:

0000000000000000 <_ZSt15__alloc_on_moveISaIcEEvRT_S2_>:
    __alloc_on_move(_Alloc& __one, _Alloc& __two)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
	__one = std::move(__two);
  14:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  18:	48 89 c7             	mov    %rax,%rdi
  1b:	e8 00 00 00 00       	call   20 <_ZSt15__alloc_on_moveISaIcEEvRT_S2_+0x20>
    }
  20:	90                   	nop
  21:	c9                   	leave  
  22:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5clearEv:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5clearEv>:
      clear() _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
      { _M_set_length(0); }
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	be 00 00 00 00       	mov    $0x0,%esi
  19:	48 89 c7             	mov    %rax,%rdi
  1c:	e8 00 00 00 00       	call   21 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5clearEv+0x21>
  21:	90                   	nop
  22:	c9                   	leave  
  23:	c3                   	ret    

Disassembly of section .text._ZSt12__niter_baseIPKcET_S2_:

0000000000000000 <_ZSt12__niter_baseIPKcET_S2_>:
    __niter_base(_Iterator __it)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    { return __it; }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	5d                   	pop    %rbp
  11:	c3                   	ret    

Disassembly of section .text._ZSt12__niter_baseIPcET_S1_:

0000000000000000 <_ZSt12__niter_baseIPcET_S1_>:
    __niter_base(_Iterator __it)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    { return __it; }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	5d                   	pop    %rbp
  11:	c3                   	ret    

Disassembly of section .text._ZSt14__copy_move_a1ILb0EPKcPcET1_T0_S4_S3_:

0000000000000000 <_ZSt14__copy_move_a1ILb0EPKcPcET1_T0_S4_S3_>:
    __copy_move_a1(_II __first, _II __last, _OI __result)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
    { return std::__copy_move_a2<_IsMove>(__first, __last, __result); }
  18:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  1c:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
  20:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  24:	48 89 ce             	mov    %rcx,%rsi
  27:	48 89 c7             	mov    %rax,%rdi
  2a:	e8 00 00 00 00       	call   2f <_ZSt14__copy_move_a1ILb0EPKcPcET1_T0_S4_S3_+0x2f>
  2f:	c9                   	leave  
  30:	c3                   	ret    

Disassembly of section .text._ZSt12__niter_wrapIPcET_RKS1_S1_:

0000000000000000 <_ZSt12__niter_wrapIPcET_RKS1_S1_>:
    __niter_wrap(const _Iterator&, _Iterator __res)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    { return __res; }
  10:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  14:	5d                   	pop    %rbp
  15:	c3                   	ret    

Disassembly of section .text._ZSt8__fill_aIPccEvT_S1_RKT0_:

0000000000000000 <_ZSt8__fill_aIPccEvT_S1_RKT0_>:
    __fill_a(_FIte __first, _FIte __last, const _Tp& __value)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
    { std::__fill_a1(__first, __last, __value); }
  18:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  1c:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
  20:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  24:	48 89 ce             	mov    %rcx,%rsi
  27:	48 89 c7             	mov    %rax,%rdi
  2a:	e8 00 00 00 00       	call   2f <_ZSt8__fill_aIPccEvT_S1_RKT0_+0x2f>
  2f:	90                   	nop
  30:	c9                   	leave  
  31:	c3                   	ret    

Disassembly of section .text._ZNSt14pointer_traitsIPcE10pointer_toERc:

0000000000000000 <_ZNSt14pointer_traitsIPcE10pointer_toERc>:
       *  @brief  Obtain a pointer to an object
       *  @param  __r  A reference to an object of type @c element_type
       *  @return @c addressof(__r)
      */
      static _GLIBCXX20_CONSTEXPR pointer
      pointer_to(__make_not_void<element_type>& __r) noexcept
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
      { return std::addressof(__r); }
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZNSt14pointer_traitsIPcE10pointer_toERc+0x1c>
  1c:	c9                   	leave  
  1d:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_S_assignEPcmc:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_S_assignEPcmc>:
      _S_assign(_CharT* __d, size_type __n, _CharT __c)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	89 d0                	mov    %edx,%eax
  16:	88 45 ec             	mov    %al,-0x14(%rbp)
	if (__n == 1)
  19:	48 83 7d f0 01       	cmpq   $0x1,-0x10(%rbp)
  1e:	75 15                	jne    35 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_S_assignEPcmc+0x35>
	  traits_type::assign(*__d, __c);
  20:	48 8d 55 ec          	lea    -0x14(%rbp),%rdx
  24:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  28:	48 89 d6             	mov    %rdx,%rsi
  2b:	48 89 c7             	mov    %rax,%rdi
  2e:	e8 00 00 00 00       	call   33 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_S_assignEPcmc+0x33>
      }
  33:	eb 1a                	jmp    4f <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_S_assignEPcmc+0x4f>
	  traits_type::assign(__d, __n, __c);
  35:	0f b6 45 ec          	movzbl -0x14(%rbp),%eax
  39:	0f be d0             	movsbl %al,%edx
  3c:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
  40:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  44:	48 89 ce             	mov    %rcx,%rsi
  47:	48 89 c7             	mov    %rax,%rdi
  4a:	e8 00 00 00 00       	call   4f <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_S_assignEPcmc+0x4f>
      }
  4f:	90                   	nop
  50:	c9                   	leave  
  51:	c3                   	ret    

Disassembly of section .text._ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv:

0000000000000000 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv>:
      _M_local_data() const
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
	return std::pointer_traits<const_pointer>::pointer_to(*_M_local_buf);
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 83 c0 10          	add    $0x10,%rax
  18:	48 89 c7             	mov    %rax,%rdi
  1b:	e8 00 00 00 00       	call   20 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv+0x20>
      }
  20:	c9                   	leave  
  21:	c3                   	ret    

Disassembly of section .text._ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE15_M_check_lengthEmmPKc:

0000000000000000 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE15_M_check_lengthEmmPKc>:
      _M_check_length(size_type __n1, size_type __n2, const char* __s) const
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 28          	sub    $0x28,%rsp
   d:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  11:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  15:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
  19:	48 89 4d d0          	mov    %rcx,-0x30(%rbp)
	if (this->max_size() - (this->size() - __n1) < __n2)
  1d:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  21:	48 89 c7             	mov    %rax,%rdi
  24:	e8 00 00 00 00       	call   29 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE15_M_check_lengthEmmPKc+0x29>
  29:	48 89 c3             	mov    %rax,%rbx
  2c:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  30:	48 89 c7             	mov    %rax,%rdi
  33:	e8 00 00 00 00       	call   38 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE15_M_check_lengthEmmPKc+0x38>
  38:	48 89 c2             	mov    %rax,%rdx
  3b:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  3f:	48 29 d0             	sub    %rdx,%rax
  42:	48 01 d8             	add    %rbx,%rax
  45:	48 39 45 d8          	cmp    %rax,-0x28(%rbp)
  49:	0f 97 c0             	seta   %al
  4c:	84 c0                	test   %al,%al
  4e:	74 0c                	je     5c <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE15_M_check_lengthEmmPKc+0x5c>
	  __throw_length_error(__N(__s));
  50:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  54:	48 89 c7             	mov    %rax,%rdi
  57:	e8 00 00 00 00       	call   5c <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE15_M_check_lengthEmmPKc+0x5c>
      }
  5c:	90                   	nop
  5d:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  61:	c9                   	leave  
  62:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_appendEPKcm:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_appendEPKcm>:
	this->_M_set_length(__n);
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT, _Traits, _Alloc>&
    basic_string<_CharT, _Traits, _Alloc>::
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 38          	sub    $0x38,%rsp
   d:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  11:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
  15:	48 89 55 c8          	mov    %rdx,-0x38(%rbp)
    _M_append(const _CharT* __s, size_type __n)
    {
      const size_type __len = __n + this->size();
  19:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  1d:	48 89 c7             	mov    %rax,%rdi
  20:	e8 00 00 00 00       	call   25 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_appendEPKcm+0x25>
  25:	48 8b 55 c8          	mov    -0x38(%rbp),%rdx
  29:	48 01 d0             	add    %rdx,%rax
  2c:	48 89 45 e8          	mov    %rax,-0x18(%rbp)

      if (__len <= this->capacity())
  30:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  34:	48 89 c7             	mov    %rax,%rdi
  37:	e8 00 00 00 00       	call   3c <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_appendEPKcm+0x3c>
  3c:	48 39 45 e8          	cmp    %rax,-0x18(%rbp)
  40:	0f 96 c0             	setbe  %al
  43:	84 c0                	test   %al,%al
  45:	74 3b                	je     82 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_appendEPKcm+0x82>
	{
	  if (__n)
  47:	48 83 7d c8 00       	cmpq   $0x0,-0x38(%rbp)
  4c:	74 62                	je     b0 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_appendEPKcm+0xb0>
	    this->_S_copy(this->_M_data() + this->size(), __s, __n);
  4e:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  52:	48 89 c7             	mov    %rax,%rdi
  55:	e8 00 00 00 00       	call   5a <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_appendEPKcm+0x5a>
  5a:	48 89 c3             	mov    %rax,%rbx
  5d:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  61:	48 89 c7             	mov    %rax,%rdi
  64:	e8 00 00 00 00       	call   69 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_appendEPKcm+0x69>
  69:	48 8d 0c 03          	lea    (%rbx,%rax,1),%rcx
  6d:	48 8b 55 c8          	mov    -0x38(%rbp),%rdx
  71:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  75:	48 89 c6             	mov    %rax,%rsi
  78:	48 89 cf             	mov    %rcx,%rdi
  7b:	e8 00 00 00 00       	call   80 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_appendEPKcm+0x80>
  80:	eb 2e                	jmp    b0 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_appendEPKcm+0xb0>
	}
      else
	this->_M_mutate(this->size(), size_type(0), __s, __n);
  82:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  86:	48 89 c7             	mov    %rax,%rdi
  89:	e8 00 00 00 00       	call   8e <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_appendEPKcm+0x8e>
  8e:	48 89 c6             	mov    %rax,%rsi
  91:	48 8b 4d c8          	mov    -0x38(%rbp),%rcx
  95:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
  99:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  9d:	49 89 c8             	mov    %rcx,%r8
  a0:	48 89 d1             	mov    %rdx,%rcx
  a3:	ba 00 00 00 00       	mov    $0x0,%edx
  a8:	48 89 c7             	mov    %rax,%rdi
  ab:	e8 00 00 00 00       	call   b0 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_appendEPKcm+0xb0>

      this->_M_set_length(__len);
  b0:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  b4:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  b8:	48 89 d6             	mov    %rdx,%rsi
  bb:	48 89 c7             	mov    %rax,%rdi
  be:	e8 00 00 00 00       	call   c3 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_appendEPKcm+0xc3>
      return *this;
  c3:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    }
  c7:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  cb:	c9                   	leave  
  cc:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7replaceEmmPKcm:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7replaceEmmPKcm>:
      replace(size_type __pos, size_type __n1, const _CharT* __s,
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 38          	sub    $0x38,%rsp
   d:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  11:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  15:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
  19:	48 89 4d d0          	mov    %rcx,-0x30(%rbp)
  1d:	4c 89 45 c8          	mov    %r8,-0x38(%rbp)
	return _M_replace(_M_check(__pos, "basic_string::replace"),
  21:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
  25:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
  29:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  2d:	48 89 ce             	mov    %rcx,%rsi
  30:	48 89 c7             	mov    %rax,%rdi
  33:	e8 00 00 00 00       	call   38 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7replaceEmmPKcm+0x38>
  38:	48 89 c3             	mov    %rax,%rbx
  3b:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
  3f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  43:	48 8d 15 00 00 00 00 	lea    0x0(%rip),%rdx        # 4a <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7replaceEmmPKcm+0x4a>
  4a:	48 89 ce             	mov    %rcx,%rsi
  4d:	48 89 c7             	mov    %rax,%rdi
  50:	e8 00 00 00 00       	call   55 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7replaceEmmPKcm+0x55>
  55:	48 89 c6             	mov    %rax,%rsi
  58:	48 8b 4d c8          	mov    -0x38(%rbp),%rcx
  5c:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
  60:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  64:	49 89 c8             	mov    %rcx,%r8
  67:	48 89 d1             	mov    %rdx,%rcx
  6a:	48 89 da             	mov    %rbx,%rdx
  6d:	48 89 c7             	mov    %rax,%rdi
  70:	e8 00 00 00 00       	call   75 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7replaceEmmPKcm+0x75>
      }
  75:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  79:	c9                   	leave  
  7a:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx17__is_null_pointerIKcEEbPT_:

0000000000000000 <_ZN9__gnu_cxx17__is_null_pointerIKcEEbPT_>:


  // For use in string and vstring.
  template<typename _Type>
    inline bool
    __is_null_pointer(_Type* __ptr)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    { return __ptr == 0; }
   c:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
  11:	0f 94 c0             	sete   %al
  14:	5d                   	pop    %rbp
  15:	c3                   	ret    

Disassembly of section .text._ZSt19__iterator_categoryIPKcENSt15iterator_traitsIT_E17iterator_categoryERKS3_:

0000000000000000 <_ZSt19__iterator_categoryIPKcENSt15iterator_traitsIT_E17iterator_categoryERKS3_>:
    __iterator_category(const _Iter&)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    { return typename iterator_traits<_Iter>::iterator_category(); }
   c:	5d                   	pop    %rbp
   d:	c3                   	ret    

Disassembly of section .text._ZSt10__distanceIPKcENSt15iterator_traitsIT_E15difference_typeES3_S3_St26random_access_iterator_tag:

0000000000000000 <_ZSt10__distanceIPKcENSt15iterator_traitsIT_E15difference_typeES3_S3_St26random_access_iterator_tag>:
    __distance(_RandomAccessIterator __first, _RandomAccessIterator __last,
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
      return __last - __first;
  10:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  14:	48 2b 45 f8          	sub    -0x8(%rbp),%rax
    }
  18:	5d                   	pop    %rbp
  19:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsEPcPKcS7_:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsEPcPKcS7_>:
      _S_copy_chars(_CharT* __p, const _CharT* __k1, const _CharT* __k2)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
      { _S_copy(__p, __k1, __k2 - __k1); }
  18:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  1c:	48 2b 45 f0          	sub    -0x10(%rbp),%rax
  20:	48 89 c2             	mov    %rax,%rdx
  23:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
  27:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  2b:	48 89 ce             	mov    %rcx,%rsi
  2e:	48 89 c7             	mov    %rax,%rdi
  31:	e8 00 00 00 00       	call   36 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsEPcPKcS7_+0x36>
  36:	90                   	nop
  37:	c9                   	leave  
  38:	c3                   	ret    

Disassembly of section .text._ZNSt16allocator_traitsISaIcEE37select_on_container_copy_constructionERKS0_:

0000000000000000 <_ZNSt16allocator_traitsISaIcEE37select_on_container_copy_constructionERKS0_>:
      select_on_container_copy_construction(const allocator_type& __rhs)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
      { return __rhs; }
  14:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  18:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  1c:	48 89 d6             	mov    %rdx,%rsi
  1f:	48 89 c7             	mov    %rax,%rdi
  22:	e8 00 00 00 00       	call   27 <_ZNSt16allocator_traitsISaIcEE37select_on_container_copy_constructionERKS0_+0x27>
  27:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  2b:	c9                   	leave  
  2c:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_construct_auxIPcEEvT_S7_St12__false_type:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_construct_auxIPcEEvT_S7_St12__false_type>:
        _M_construct_aux(_InIterator __beg, _InIterator __end,
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 30          	sub    $0x30,%rsp
   c:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  10:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  14:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
  18:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  1f:	00 00 
  21:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  25:	31 c0                	xor    %eax,%eax
          _M_construct(__beg, __end, _Tag());
  27:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
  2b:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
  2f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  33:	48 89 ce             	mov    %rcx,%rsi
  36:	48 89 c7             	mov    %rax,%rdi
  39:	e8 00 00 00 00       	call   3e <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_construct_auxIPcEEvT_S7_St12__false_type+0x3e>
	}
  3e:	90                   	nop
  3f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  43:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
  4a:	00 00 
  4c:	74 05                	je     53 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_construct_auxIPcEEvT_S7_St12__false_type+0x53>
  4e:	e8 00 00 00 00       	call   53 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_construct_auxIPcEEvT_S7_St12__false_type+0x53>
  53:	c9                   	leave  
  54:	c3                   	ret    

Disassembly of section .text._ZSt7forwardIPN8MemTable8QuadlistEEOT_RNSt16remove_referenceIS3_E4typeE:

0000000000000000 <_ZSt7forwardIPN8MemTable8QuadlistEEOT_RNSt16remove_referenceIS3_E4typeE>:
    forward(typename std::remove_reference<_Tp>::type& __t) noexcept
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    { return static_cast<_Tp&&>(__t); }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	5d                   	pop    %rbp
  11:	c3                   	ret    

Disassembly of section .text._ZSt12construct_atIPN8MemTable8QuadlistEJS2_EEDTgsnwcvPvLi0E_T_pispcl7declvalIT0_EEEEPS4_DpOS5_:

0000000000000000 <_ZSt12construct_atIPN8MemTable8QuadlistEJS2_EEDTgsnwcvPvLi0E_T_pispcl7declvalIT0_EEEEPS4_DpOS5_>:
    construct_at(_Tp* __location, _Args&&... __args)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 18          	sub    $0x18,%rsp
   d:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  11:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    { return ::new((void*)__location) _Tp(std::forward<_Args>(__args)...); }
  15:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  19:	48 89 c7             	mov    %rax,%rdi
  1c:	e8 00 00 00 00       	call   21 <_ZSt12construct_atIPN8MemTable8QuadlistEJS2_EEDTgsnwcvPvLi0E_T_pispcl7declvalIT0_EEEEPS4_DpOS5_+0x21>
  21:	48 8b 18             	mov    (%rax),%rbx
  24:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  28:	48 89 c6             	mov    %rax,%rsi
  2b:	bf 08 00 00 00       	mov    $0x8,%edi
  30:	e8 00 00 00 00       	call   35 <_ZSt12construct_atIPN8MemTable8QuadlistEJS2_EEDTgsnwcvPvLi0E_T_pispcl7declvalIT0_EEEEPS4_DpOS5_+0x35>
  35:	48 89 18             	mov    %rbx,(%rax)
  38:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  3c:	c9                   	leave  
  3d:	c3                   	ret    

Disassembly of section .text._ZNSt16allocator_traitsISaIPN8MemTable8QuadlistEEE9constructIS2_JS2_EEEvRS3_PT_DpOT0_:

0000000000000000 <_ZNSt16allocator_traitsISaIPN8MemTable8QuadlistEEE9constructIS2_JS2_EEEvRS3_PT_DpOT0_>:
	construct(allocator_type& __a __attribute__((__unused__)), _Up* __p,
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
	  std::construct_at(__p, std::forward<_Args>(__args)...);
  18:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  1c:	48 89 c7             	mov    %rax,%rdi
  1f:	e8 00 00 00 00       	call   24 <_ZNSt16allocator_traitsISaIPN8MemTable8QuadlistEEE9constructIS2_JS2_EEEvRS3_PT_DpOT0_+0x24>
  24:	48 89 c2             	mov    %rax,%rdx
  27:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  2b:	48 89 d6             	mov    %rdx,%rsi
  2e:	48 89 c7             	mov    %rax,%rdi
  31:	e8 00 00 00 00       	call   36 <_ZNSt16allocator_traitsISaIPN8MemTable8QuadlistEEE9constructIS2_JS2_EEEvRS3_PT_DpOT0_+0x36>
	}
  36:	90                   	nop
  37:	c9                   	leave  
  38:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_:

0000000000000000 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_>:
      vector<_Tp, _Alloc>::
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 68          	sub    $0x68,%rsp
   d:	48 89 7d a8          	mov    %rdi,-0x58(%rbp)
  11:	48 89 75 a0          	mov    %rsi,-0x60(%rbp)
  15:	48 89 55 98          	mov    %rdx,-0x68(%rbp)
  19:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  20:	00 00 
  22:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  26:	31 c0                	xor    %eax,%eax
	_M_check_len(size_type(1), "vector::_M_realloc_insert");
  28:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  2c:	48 8d 15 00 00 00 00 	lea    0x0(%rip),%rdx        # 33 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0x33>
  33:	be 01 00 00 00       	mov    $0x1,%esi
  38:	48 89 c7             	mov    %rax,%rdi
  3b:	e8 00 00 00 00       	call   40 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0x40>
  40:	48 89 45 b8          	mov    %rax,-0x48(%rbp)
      pointer __old_start = this->_M_impl._M_start;
  44:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  48:	48 8b 00             	mov    (%rax),%rax
  4b:	48 89 45 c0          	mov    %rax,-0x40(%rbp)
      pointer __old_finish = this->_M_impl._M_finish;
  4f:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  53:	48 8b 40 08          	mov    0x8(%rax),%rax
  57:	48 89 45 c8          	mov    %rax,-0x38(%rbp)
      const size_type __elems_before = __position - begin();
  5b:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  5f:	48 89 c7             	mov    %rax,%rdi
  62:	e8 00 00 00 00       	call   67 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0x67>
  67:	48 89 45 b0          	mov    %rax,-0x50(%rbp)
  6b:	48 8d 55 b0          	lea    -0x50(%rbp),%rdx
  6f:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
  73:	48 89 d6             	mov    %rdx,%rsi
  76:	48 89 c7             	mov    %rax,%rdi
  79:	e8 00 00 00 00       	call   7e <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0x7e>
  7e:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
      pointer __new_start(this->_M_allocate(__len));
  82:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  86:	48 8b 55 b8          	mov    -0x48(%rbp),%rdx
  8a:	48 89 d6             	mov    %rdx,%rsi
  8d:	48 89 c7             	mov    %rax,%rdi
  90:	e8 00 00 00 00       	call   95 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0x95>
  95:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
      pointer __new_finish(__new_start);
  99:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  9d:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
	  _Alloc_traits::construct(this->_M_impl,
  a1:	48 8b 45 98          	mov    -0x68(%rbp),%rax
  a5:	48 89 c7             	mov    %rax,%rdi
  a8:	e8 00 00 00 00       	call   ad <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0xad>
  ad:	48 89 c2             	mov    %rax,%rdx
				   __new_start + __elems_before,
  b0:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  b4:	48 8d 0c c5 00 00 00 	lea    0x0(,%rax,8),%rcx
  bb:	00 
	  _Alloc_traits::construct(this->_M_impl,
  bc:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  c0:	48 01 c1             	add    %rax,%rcx
  c3:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  c7:	48 89 ce             	mov    %rcx,%rsi
  ca:	48 89 c7             	mov    %rax,%rdi
  cd:	e8 00 00 00 00       	call   d2 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0xd2>
	  __new_finish = pointer();
  d2:	48 c7 45 e0 00 00 00 	movq   $0x0,-0x20(%rbp)
  d9:	00 
					 __new_start, _M_get_Tp_allocator());
  da:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  de:	48 89 c7             	mov    %rax,%rdi
  e1:	e8 00 00 00 00       	call   e6 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0xe6>
  e6:	48 89 c3             	mov    %rax,%rbx
	      __new_finish = _S_relocate(__old_start, __position.base(),
  e9:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
  ed:	48 89 c7             	mov    %rax,%rdi
  f0:	e8 00 00 00 00       	call   f5 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0xf5>
  f5:	48 8b 30             	mov    (%rax),%rsi
  f8:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
  fc:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
 100:	48 89 d9             	mov    %rbx,%rcx
 103:	48 89 c7             	mov    %rax,%rdi
 106:	e8 00 00 00 00       	call   10b <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0x10b>
 10b:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
	      ++__new_finish;
 10f:	48 83 45 e0 08       	addq   $0x8,-0x20(%rbp)
					 __new_finish, _M_get_Tp_allocator());
 114:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
 118:	48 89 c7             	mov    %rax,%rdi
 11b:	e8 00 00 00 00       	call   120 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0x120>
 120:	48 89 c3             	mov    %rax,%rbx
	      __new_finish = _S_relocate(__position.base(), __old_finish,
 123:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
 127:	48 89 c7             	mov    %rax,%rdi
 12a:	e8 00 00 00 00       	call   12f <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0x12f>
 12f:	48 8b 00             	mov    (%rax),%rax
 132:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
 136:	48 8b 75 c8          	mov    -0x38(%rbp),%rsi
 13a:	48 89 d9             	mov    %rbx,%rcx
 13d:	48 89 c7             	mov    %rax,%rdi
 140:	e8 00 00 00 00       	call   145 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0x145>
 145:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
      _M_deallocate(__old_start,
 149:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
		    this->_M_impl._M_end_of_storage - __old_start);
 14d:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
 151:	48 8b 52 10          	mov    0x10(%rdx),%rdx
 155:	48 2b 55 c0          	sub    -0x40(%rbp),%rdx
 159:	48 c1 fa 03          	sar    $0x3,%rdx
      _M_deallocate(__old_start,
 15d:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
 161:	48 89 ce             	mov    %rcx,%rsi
 164:	48 89 c7             	mov    %rax,%rdi
 167:	e8 00 00 00 00       	call   16c <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0x16c>
      this->_M_impl._M_start = __new_start;
 16c:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
 170:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
 174:	48 89 10             	mov    %rdx,(%rax)
      this->_M_impl._M_finish = __new_finish;
 177:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
 17b:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
 17f:	48 89 50 08          	mov    %rdx,0x8(%rax)
      this->_M_impl._M_end_of_storage = __new_start + __len;
 183:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
 187:	48 8d 14 c5 00 00 00 	lea    0x0(,%rax,8),%rdx
 18e:	00 
 18f:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 193:	48 01 c2             	add    %rax,%rdx
 196:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
 19a:	48 89 50 10          	mov    %rdx,0x10(%rax)
    }
 19e:	90                   	nop
 19f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
 1a3:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
 1aa:	00 00 
 1ac:	74 05                	je     1b3 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0x1b3>
 1ae:	e8 00 00 00 00       	call   1b3 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE17_M_realloc_insertIJS2_EEEvN9__gnu_cxx17__normal_iteratorIPS2_S4_EEDpOT_+0x1b3>
 1b3:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
 1b7:	c9                   	leave  
 1b8:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE4backEv:

0000000000000000 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE4backEv>:
      back() _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 30          	sub    $0x30,%rsp
   c:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  10:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  17:	00 00 
  19:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  1d:	31 c0                	xor    %eax,%eax
	return *(end() - 1);
  1f:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  23:	48 89 c7             	mov    %rax,%rdi
  26:	e8 00 00 00 00       	call   2b <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE4backEv+0x2b>
  2b:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  2f:	48 8d 45 e8          	lea    -0x18(%rbp),%rax
  33:	be 01 00 00 00       	mov    $0x1,%esi
  38:	48 89 c7             	mov    %rax,%rdi
  3b:	e8 00 00 00 00       	call   40 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE4backEv+0x40>
  40:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
  44:	48 8d 45 f0          	lea    -0x10(%rbp),%rax
  48:	48 89 c7             	mov    %rax,%rdi
  4b:	e8 00 00 00 00       	call   50 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE4backEv+0x50>
      }
  50:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  54:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
  5b:	00 00 
  5d:	74 05                	je     64 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE4backEv+0x64>
  5f:	e8 00 00 00 00       	call   64 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE4backEv+0x64>
  64:	c9                   	leave  
  65:	c3                   	ret    

Disassembly of section .text._ZSt15__alloc_on_copyISaIcEEvRT_RKS1_:

0000000000000000 <_ZSt15__alloc_on_copyISaIcEEvRT_RKS1_>:
    __alloc_on_copy(_Alloc& __one, const _Alloc& __two)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    }
  10:	90                   	nop
  11:	5d                   	pop    %rbp
  12:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_>:
    basic_string<_CharT, _Traits, _Alloc>::
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 48          	sub    $0x48,%rsp
   d:	48 89 7d b8          	mov    %rdi,-0x48(%rbp)
  11:	48 89 75 b0          	mov    %rsi,-0x50(%rbp)
  15:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  1c:	00 00 
  1e:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  22:	31 c0                	xor    %eax,%eax
      if (this != &__str)
  24:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  28:	48 3b 45 b0          	cmp    -0x50(%rbp),%rax
  2c:	0f 84 c9 00 00 00    	je     fb <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_+0xfb>
	  const size_type __rsize = __str.length();
  32:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
  36:	48 89 c7             	mov    %rax,%rdi
  39:	e8 00 00 00 00       	call   3e <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_+0x3e>
  3e:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
	  const size_type __capacity = capacity();
  42:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  46:	48 89 c7             	mov    %rax,%rdi
  49:	e8 00 00 00 00       	call   4e <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_+0x4e>
  4e:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
	  if (__rsize > __capacity)
  52:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  56:	48 3b 45 d8          	cmp    -0x28(%rbp),%rax
  5a:	76 55                	jbe    b1 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_+0xb1>
	      size_type __new_capacity = __rsize;
  5c:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  60:	48 89 45 c8          	mov    %rax,-0x38(%rbp)
	      pointer __tmp = _M_create(__new_capacity, __capacity);
  64:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
  68:	48 8d 4d c8          	lea    -0x38(%rbp),%rcx
  6c:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  70:	48 89 ce             	mov    %rcx,%rsi
  73:	48 89 c7             	mov    %rax,%rdi
  76:	e8 00 00 00 00       	call   7b <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_+0x7b>
  7b:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
	      _M_dispose();
  7f:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  83:	48 89 c7             	mov    %rax,%rdi
  86:	e8 00 00 00 00       	call   8b <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_+0x8b>
	      _M_data(__tmp);
  8b:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
  8f:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  93:	48 89 d6             	mov    %rdx,%rsi
  96:	48 89 c7             	mov    %rax,%rdi
  99:	e8 00 00 00 00       	call   9e <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_+0x9e>
	      _M_capacity(__new_capacity);
  9e:	48 8b 55 c8          	mov    -0x38(%rbp),%rdx
  a2:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  a6:	48 89 d6             	mov    %rdx,%rsi
  a9:	48 89 c7             	mov    %rax,%rdi
  ac:	e8 00 00 00 00       	call   b1 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_+0xb1>
	  if (__rsize)
  b1:	48 83 7d d0 00       	cmpq   $0x0,-0x30(%rbp)
  b6:	74 30                	je     e8 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_+0xe8>
	    this->_S_copy(_M_data(), __str._M_data(), __rsize);
  b8:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
  bc:	48 89 c7             	mov    %rax,%rdi
  bf:	e8 00 00 00 00       	call   c4 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_+0xc4>
  c4:	48 89 c3             	mov    %rax,%rbx
  c7:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  cb:	48 89 c7             	mov    %rax,%rdi
  ce:	e8 00 00 00 00       	call   d3 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_+0xd3>
  d3:	48 89 c1             	mov    %rax,%rcx
  d6:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  da:	48 89 c2             	mov    %rax,%rdx
  dd:	48 89 de             	mov    %rbx,%rsi
  e0:	48 89 cf             	mov    %rcx,%rdi
  e3:	e8 00 00 00 00       	call   e8 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_+0xe8>
	  _M_set_length(__rsize);
  e8:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
  ec:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  f0:	48 89 d6             	mov    %rdx,%rsi
  f3:	48 89 c7             	mov    %rax,%rdi
  f6:	e8 00 00 00 00       	call   fb <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_+0xfb>
    }
  fb:	90                   	nop
  fc:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
 100:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
 107:	00 00 
 109:	74 05                	je     110 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_+0x110>
 10b:	e8 00 00 00 00       	call   110 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_+0x110>
 110:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
 114:	c9                   	leave  
 115:	c3                   	ret    

Disassembly of section .text._ZNSt8__detail5__modImLm4294967296ELm1ELm0EEET_S1_:

0000000000000000 <_ZNSt8__detail5__modImLm4294967296ELm1ELm0EEET_S1_>:
      __mod(_Tp __x)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
	    constexpr _Tp __a1 = __a ? __a : 1;
  10:	48 c7 45 f8 01 00 00 	movq   $0x1,-0x8(%rbp)
  17:	00 
	    return _Mod<_Tp, __m, __a1, __c>::__calc(__x);
  18:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  1c:	48 89 c7             	mov    %rax,%rdi
  1f:	e8 00 00 00 00       	call   24 <_ZNSt8__detail5__modImLm4294967296ELm1ELm0EEET_S1_+0x24>
      }
  24:	c9                   	leave  
  25:	c3                   	ret    

Disassembly of section .text._ZNSt8__detail5__modImLm624ELm1ELm0EEET_S1_:

0000000000000000 <_ZNSt8__detail5__modImLm624ELm1ELm0EEET_S1_>:
      __mod(_Tp __x)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
	    constexpr _Tp __a1 = __a ? __a : 1;
  10:	48 c7 45 f8 01 00 00 	movq   $0x1,-0x8(%rbp)
  17:	00 
	    return _Mod<_Tp, __m, __a1, __c>::__calc(__x);
  18:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  1c:	48 89 c7             	mov    %rax,%rdi
  1f:	e8 00 00 00 00       	call   24 <_ZNSt8__detail5__modImLm624ELm1ELm0EEET_S1_+0x24>
      }
  24:	c9                   	leave  
  25:	c3                   	ret    

Disassembly of section .text._ZNSt8__detail8_AdaptorISt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEdEC2ERS2_:

0000000000000000 <_ZNSt8__detail8_AdaptorISt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEdEC1ERS2_>:
	_Adaptor(_Engine& __g)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
	: _M_g(__g) { }
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  18:	48 89 10             	mov    %rdx,(%rax)
  1b:	90                   	nop
  1c:	5d                   	pop    %rbp
  1d:	c3                   	ret    

Disassembly of section .text._ZNSt8__detail8_AdaptorISt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEdEclEv:

0000000000000000 <_ZNSt8__detail8_AdaptorISt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEdEclEv>:
	operator()()
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
	                            _Engine>(_M_g);
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 8b 00             	mov    (%rax),%rax
  17:	48 89 c7             	mov    %rax,%rdi
  1a:	e8 00 00 00 00       	call   1f <_ZNSt8__detail8_AdaptorISt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEdEclEv+0x1f>
  1f:	66 48 0f 7e c0       	movq   %xmm0,%rax
	}
  24:	66 48 0f 6e c0       	movq   %rax,%xmm0
  29:	c9                   	leave  
  2a:	c3                   	ret    

Disassembly of section .text._ZNKSt25uniform_real_distributionIdE10param_type1bEv:

0000000000000000 <_ZNKSt25uniform_real_distributionIdE10param_type1bEv>:
	b() const
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
	{ return _M_b; }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	f2 0f 10 40 08       	movsd  0x8(%rax),%xmm0
  15:	66 48 0f 7e c0       	movq   %xmm0,%rax
  1a:	66 48 0f 6e c0       	movq   %rax,%xmm0
  1f:	5d                   	pop    %rbp
  20:	c3                   	ret    

Disassembly of section .text._ZNKSt25uniform_real_distributionIdE10param_type1aEv:

0000000000000000 <_ZNKSt25uniform_real_distributionIdE10param_type1aEv>:
	a() const
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
	{ return _M_a; }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	f2 0f 10 00          	movsd  (%rax),%xmm0
  14:	66 48 0f 7e c0       	movq   %xmm0,%rax
  19:	66 48 0f 6e c0       	movq   %rax,%xmm0
  1e:	5d                   	pop    %rbp
  1f:	c3                   	ret    

Disassembly of section .text._ZSt7forwardIRKPN8MemTable8QuadlistEEOT_RNSt16remove_referenceIS5_E4typeE:

0000000000000000 <_ZSt7forwardIRKPN8MemTable8QuadlistEEOT_RNSt16remove_referenceIS5_E4typeE>:
    forward(typename std::remove_reference<_Tp>::type& __t) noexcept
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    { return static_cast<_Tp&&>(__t); }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	5d                   	pop    %rbp
  11:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx17__normal_iteratorIPPN8MemTable8QuadlistESt6vectorIS3_SaIS3_EEEC2ERKS4_:

0000000000000000 <_ZN9__gnu_cxx17__normal_iteratorIPPN8MemTable8QuadlistESt6vectorIS3_SaIS3_EEEC1ERKS4_>:

      _GLIBCXX_CONSTEXPR __normal_iterator() _GLIBCXX_NOEXCEPT
      : _M_current(_Iterator()) { }

      explicit _GLIBCXX20_CONSTEXPR
      __normal_iterator(const _Iterator& __i) _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
      : _M_current(__i) { }
  10:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  14:	48 8b 10             	mov    (%rax),%rdx
  17:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  1b:	48 89 10             	mov    %rdx,(%rax)
  1e:	90                   	nop
  1f:	5d                   	pop    %rbp
  20:	c3                   	ret    

Disassembly of section .text._ZNKSt6vectorIPN8MemTable8QuadlistESaIS2_EE12_M_check_lenEmPKc:

0000000000000000 <_ZNKSt6vectorIPN8MemTable8QuadlistESaIS2_EE12_M_check_lenEmPKc>:
      { return _M_insert_rval(__position, std::move(__v)); }
#endif

      // Called by _M_fill_insert, _M_insert_aux etc.
      size_type
      _M_check_len(size_type __n, const char* __s) const
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 48          	sub    $0x48,%rsp
   d:	48 89 7d c8          	mov    %rdi,-0x38(%rbp)
  11:	48 89 75 c0          	mov    %rsi,-0x40(%rbp)
  15:	48 89 55 b8          	mov    %rdx,-0x48(%rbp)
  19:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  20:	00 00 
  22:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  26:	31 c0                	xor    %eax,%eax
      {
	if (max_size() - size() < __n)
  28:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  2c:	48 89 c7             	mov    %rax,%rdi
  2f:	e8 00 00 00 00       	call   34 <_ZNKSt6vectorIPN8MemTable8QuadlistESaIS2_EE12_M_check_lenEmPKc+0x34>
  34:	48 89 c3             	mov    %rax,%rbx
  37:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  3b:	48 89 c7             	mov    %rax,%rdi
  3e:	e8 00 00 00 00       	call   43 <_ZNKSt6vectorIPN8MemTable8QuadlistESaIS2_EE12_M_check_lenEmPKc+0x43>
  43:	48 29 c3             	sub    %rax,%rbx
  46:	48 89 da             	mov    %rbx,%rdx
  49:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
  4d:	48 39 c2             	cmp    %rax,%rdx
  50:	0f 92 c0             	setb   %al
  53:	84 c0                	test   %al,%al
  55:	74 0c                	je     63 <_ZNKSt6vectorIPN8MemTable8QuadlistESaIS2_EE12_M_check_lenEmPKc+0x63>
	  __throw_length_error(__N(__s));
  57:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  5b:	48 89 c7             	mov    %rax,%rdi
  5e:	e8 00 00 00 00       	call   63 <_ZNKSt6vectorIPN8MemTable8QuadlistESaIS2_EE12_M_check_lenEmPKc+0x63>

	const size_type __len = size() + (std::max)(size(), __n);
  63:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  67:	48 89 c7             	mov    %rax,%rdi
  6a:	e8 00 00 00 00       	call   6f <_ZNKSt6vectorIPN8MemTable8QuadlistESaIS2_EE12_M_check_lenEmPKc+0x6f>
  6f:	48 89 c3             	mov    %rax,%rbx
  72:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  76:	48 89 c7             	mov    %rax,%rdi
  79:	e8 00 00 00 00       	call   7e <_ZNKSt6vectorIPN8MemTable8QuadlistESaIS2_EE12_M_check_lenEmPKc+0x7e>
  7e:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
  82:	48 8d 55 c0          	lea    -0x40(%rbp),%rdx
  86:	48 8d 45 d8          	lea    -0x28(%rbp),%rax
  8a:	48 89 d6             	mov    %rdx,%rsi
  8d:	48 89 c7             	mov    %rax,%rdi
  90:	e8 00 00 00 00       	call   95 <_ZNKSt6vectorIPN8MemTable8QuadlistESaIS2_EE12_M_check_lenEmPKc+0x95>
  95:	48 8b 00             	mov    (%rax),%rax
  98:	48 01 d8             	add    %rbx,%rax
  9b:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
	return (__len < size() || __len > max_size()) ? max_size() : __len;
  9f:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  a3:	48 89 c7             	mov    %rax,%rdi
  a6:	e8 00 00 00 00       	call   ab <_ZNKSt6vectorIPN8MemTable8QuadlistESaIS2_EE12_M_check_lenEmPKc+0xab>
  ab:	48 39 45 e0          	cmp    %rax,-0x20(%rbp)
  af:	72 12                	jb     c3 <_ZNKSt6vectorIPN8MemTable8QuadlistESaIS2_EE12_M_check_lenEmPKc+0xc3>
  b1:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  b5:	48 89 c7             	mov    %rax,%rdi
  b8:	e8 00 00 00 00       	call   bd <_ZNKSt6vectorIPN8MemTable8QuadlistESaIS2_EE12_M_check_lenEmPKc+0xbd>
  bd:	48 39 45 e0          	cmp    %rax,-0x20(%rbp)
  c1:	76 0e                	jbe    d1 <_ZNKSt6vectorIPN8MemTable8QuadlistESaIS2_EE12_M_check_lenEmPKc+0xd1>
  c3:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  c7:	48 89 c7             	mov    %rax,%rdi
  ca:	e8 00 00 00 00       	call   cf <_ZNKSt6vectorIPN8MemTable8QuadlistESaIS2_EE12_M_check_lenEmPKc+0xcf>
  cf:	eb 04                	jmp    d5 <_ZNKSt6vectorIPN8MemTable8QuadlistESaIS2_EE12_M_check_lenEmPKc+0xd5>
  d1:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
      }
  d5:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  d9:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
  e0:	00 00 
  e2:	74 05                	je     e9 <_ZNKSt6vectorIPN8MemTable8QuadlistESaIS2_EE12_M_check_lenEmPKc+0xe9>
  e4:	e8 00 00 00 00       	call   e9 <_ZNKSt6vectorIPN8MemTable8QuadlistESaIS2_EE12_M_check_lenEmPKc+0xe9>
  e9:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  ed:	c9                   	leave  
  ee:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE5beginEv:

0000000000000000 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE5beginEv>:
      begin() _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  10:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  17:	00 00 
  19:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  1d:	31 c0                	xor    %eax,%eax
      { return iterator(this->_M_impl._M_start); }
  1f:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  23:	48 8d 45 f0          	lea    -0x10(%rbp),%rax
  27:	48 89 d6             	mov    %rdx,%rsi
  2a:	48 89 c7             	mov    %rax,%rdi
  2d:	e8 00 00 00 00       	call   32 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE5beginEv+0x32>
  32:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  36:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  3a:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
  41:	00 00 
  43:	74 05                	je     4a <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE5beginEv+0x4a>
  45:	e8 00 00 00 00       	call   4a <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE5beginEv+0x4a>
  4a:	c9                   	leave  
  4b:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxxmiIPPN8MemTable8QuadlistESt6vectorIS3_SaIS3_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSB_SE_:

0000000000000000 <_ZN9__gnu_cxxmiIPPN8MemTable8QuadlistESt6vectorIS3_SaIS3_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSB_SE_>:
    { return __lhs.base() - __rhs.base(); }

  template<typename _Iterator, typename _Container>
    _GLIBCXX20_CONSTEXPR
    inline typename __normal_iterator<_Iterator, _Container>::difference_type
    operator-(const __normal_iterator<_Iterator, _Container>& __lhs,
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 18          	sub    $0x18,%rsp
   d:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  11:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
	      const __normal_iterator<_Iterator, _Container>& __rhs)
    _GLIBCXX_NOEXCEPT
    { return __lhs.base() - __rhs.base(); }
  15:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  19:	48 89 c7             	mov    %rax,%rdi
  1c:	e8 00 00 00 00       	call   21 <_ZN9__gnu_cxxmiIPPN8MemTable8QuadlistESt6vectorIS3_SaIS3_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSB_SE_+0x21>
  21:	48 8b 18             	mov    (%rax),%rbx
  24:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  28:	48 89 c7             	mov    %rax,%rdi
  2b:	e8 00 00 00 00       	call   30 <_ZN9__gnu_cxxmiIPPN8MemTable8QuadlistESt6vectorIS3_SaIS3_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSB_SE_+0x30>
  30:	48 8b 10             	mov    (%rax),%rdx
  33:	48 89 d8             	mov    %rbx,%rax
  36:	48 29 d0             	sub    %rdx,%rax
  39:	48 c1 f8 03          	sar    $0x3,%rax
  3d:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  41:	c9                   	leave  
  42:	c3                   	ret    

Disassembly of section .text._ZNSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EE11_M_allocateEm:

0000000000000000 <_ZNSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EE11_M_allocateEm>:
      _M_allocate(size_t __n)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
	return __n != 0 ? _Tr::allocate(_M_impl, __n) : pointer();
  14:	48 83 7d f0 00       	cmpq   $0x0,-0x10(%rbp)
  19:	74 15                	je     30 <_ZNSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EE11_M_allocateEm+0x30>
  1b:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  1f:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  23:	48 89 d6             	mov    %rdx,%rsi
  26:	48 89 c7             	mov    %rax,%rdi
  29:	e8 00 00 00 00       	call   2e <_ZNSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EE11_M_allocateEm+0x2e>
  2e:	eb 05                	jmp    35 <_ZNSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EE11_M_allocateEm+0x35>
  30:	b8 00 00 00 00       	mov    $0x0,%eax
      }
  35:	c9                   	leave  
  36:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE11_S_relocateEPS2_S5_S5_RS3_:

0000000000000000 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE11_S_relocateEPS2_S5_S5_RS3_>:
      _S_relocate(pointer __first, pointer __last, pointer __result,
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
  18:	48 89 4d e0          	mov    %rcx,-0x20(%rbp)
	return _S_do_relocate(__first, __last, __result, __alloc, __do_it{});
  1c:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
  20:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  24:	48 8b 75 f0          	mov    -0x10(%rbp),%rsi
  28:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  2c:	48 89 c7             	mov    %rax,%rdi
  2f:	e8 00 00 00 00       	call   34 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE11_S_relocateEPS2_S5_S5_RS3_+0x34>
      }
  34:	c9                   	leave  
  35:	c3                   	ret    

Disassembly of section .text._ZNK9__gnu_cxx17__normal_iteratorIPPN8MemTable8QuadlistESt6vectorIS3_SaIS3_EEE4baseEv:

0000000000000000 <_ZNK9__gnu_cxx17__normal_iteratorIPPN8MemTable8QuadlistESt6vectorIS3_SaIS3_EEE4baseEv>:
      base() const _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
      { return _M_current; }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	5d                   	pop    %rbp
  11:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx13new_allocatorIN7KVStore7ssLevelEEC2Ev:

0000000000000000 <_ZN9__gnu_cxx13new_allocatorIN7KVStore7ssLevelEEC1Ev>:
      // 2103. propagate_on_container_move_assignment
      typedef std::true_type propagate_on_container_move_assignment;
#endif

      _GLIBCXX20_CONSTEXPR
      new_allocator() _GLIBCXX_USE_NOEXCEPT { }
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	90                   	nop
   d:	5d                   	pop    %rbp
   e:	c3                   	ret    

Disassembly of section .text._ZNSt16allocator_traitsISaIN7KVStore7ssLevelEEE10deallocateERS2_PS1_m:

0000000000000000 <_ZNSt16allocator_traitsISaIN7KVStore7ssLevelEEE10deallocateERS2_PS1_m>:
      deallocate(allocator_type& __a, pointer __p, size_type __n)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 40          	sub    $0x40,%rsp
   c:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  10:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
  14:	48 89 55 c8          	mov    %rdx,-0x38(%rbp)
  18:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  1c:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  20:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  24:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
  28:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  2c:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
	if (std::is_constant_evaluated())
  30:	e8 00 00 00 00       	call   35 <_ZNSt16allocator_traitsISaIN7KVStore7ssLevelEEE10deallocateERS2_PS1_m+0x35>
  35:	84 c0                	test   %al,%al
  37:	74 0e                	je     47 <_ZNSt16allocator_traitsISaIN7KVStore7ssLevelEEE10deallocateERS2_PS1_m+0x47>
	    ::operator delete(__p);
  39:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  3d:	48 89 c7             	mov    %rax,%rdi
  40:	e8 00 00 00 00       	call   45 <_ZNSt16allocator_traitsISaIN7KVStore7ssLevelEEE10deallocateERS2_PS1_m+0x45>
	    return;
  45:	eb 18                	jmp    5f <_ZNSt16allocator_traitsISaIN7KVStore7ssLevelEEE10deallocateERS2_PS1_m+0x5f>
	__allocator_base<_Tp>::deallocate(__p, __n);
  47:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  4b:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
  4f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  53:	48 89 ce             	mov    %rcx,%rsi
  56:	48 89 c7             	mov    %rax,%rdi
  59:	e8 00 00 00 00       	call   5e <_ZNSt16allocator_traitsISaIN7KVStore7ssLevelEEE10deallocateERS2_PS1_m+0x5e>
      { __a.deallocate(__p, __n); }
  5e:	90                   	nop
  5f:	90                   	nop
  60:	c9                   	leave  
  61:	c3                   	ret    

Disassembly of section .text._ZSt8_DestroyIPN7KVStore7ssLevelEEvT_S3_:

0000000000000000 <_ZSt8_DestroyIPN7KVStore7ssLevelEEvT_S3_>:
   * a trivial destructor, the compiler should optimize all of this
   * away, otherwise the objects' destructors must be invoked.
   */
  template<typename _ForwardIterator>
    _GLIBCXX20_CONSTEXPR inline void
    _Destroy(_ForwardIterator __first, _ForwardIterator __last)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
      // A deleted destructor is trivial, this ensures we reject such types:
      static_assert(is_destructible<_Value_type>::value,
		    "value type is destructible");
#endif
#if __cplusplus > 201703L && defined __cpp_lib_is_constant_evaluated
      if (std::is_constant_evaluated())
  14:	e8 00 00 00 00       	call   19 <_ZSt8_DestroyIPN7KVStore7ssLevelEEvT_S3_+0x19>
  19:	84 c0                	test   %al,%al
  1b:	74 15                	je     32 <_ZSt8_DestroyIPN7KVStore7ssLevelEEvT_S3_+0x32>
	return _Destroy_aux<false>::__destroy(__first, __last);
  1d:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  21:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  25:	48 89 d6             	mov    %rdx,%rsi
  28:	48 89 c7             	mov    %rax,%rdi
  2b:	e8 00 00 00 00       	call   30 <_ZSt8_DestroyIPN7KVStore7ssLevelEEvT_S3_+0x30>
  30:	eb 13                	jmp    45 <_ZSt8_DestroyIPN7KVStore7ssLevelEEvT_S3_+0x45>
#endif
      std::_Destroy_aux<__has_trivial_destructor(_Value_type)>::
	__destroy(__first, __last);
  32:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  36:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  3a:	48 89 d6             	mov    %rdx,%rsi
  3d:	48 89 c7             	mov    %rax,%rdi
  40:	e8 00 00 00 00       	call   45 <_ZSt8_DestroyIPN7KVStore7ssLevelEEvT_S3_+0x45>
    }
  45:	c9                   	leave  
  46:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx13new_allocatorIPN8MemTable8QuadlistEEC2Ev:

0000000000000000 <_ZN9__gnu_cxx13new_allocatorIPN8MemTable8QuadlistEEC1Ev>:
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	90                   	nop
   d:	5d                   	pop    %rbp
   e:	c3                   	ret    

Disassembly of section .text._ZNSt16allocator_traitsISaIPN8MemTable8QuadlistEEE10deallocateERS3_PS2_m:

0000000000000000 <_ZNSt16allocator_traitsISaIPN8MemTable8QuadlistEEE10deallocateERS3_PS2_m>:
      deallocate(allocator_type& __a, pointer __p, size_type __n)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 40          	sub    $0x40,%rsp
   c:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  10:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
  14:	48 89 55 c8          	mov    %rdx,-0x38(%rbp)
  18:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  1c:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  20:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  24:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
  28:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  2c:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
	if (std::is_constant_evaluated())
  30:	e8 00 00 00 00       	call   35 <_ZNSt16allocator_traitsISaIPN8MemTable8QuadlistEEE10deallocateERS3_PS2_m+0x35>
  35:	84 c0                	test   %al,%al
  37:	74 0e                	je     47 <_ZNSt16allocator_traitsISaIPN8MemTable8QuadlistEEE10deallocateERS3_PS2_m+0x47>
	    ::operator delete(__p);
  39:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  3d:	48 89 c7             	mov    %rax,%rdi
  40:	e8 00 00 00 00       	call   45 <_ZNSt16allocator_traitsISaIPN8MemTable8QuadlistEEE10deallocateERS3_PS2_m+0x45>
	    return;
  45:	eb 18                	jmp    5f <_ZNSt16allocator_traitsISaIPN8MemTable8QuadlistEEE10deallocateERS3_PS2_m+0x5f>
	__allocator_base<_Tp>::deallocate(__p, __n);
  47:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  4b:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
  4f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  53:	48 89 ce             	mov    %rcx,%rsi
  56:	48 89 c7             	mov    %rax,%rdi
  59:	e8 00 00 00 00       	call   5e <_ZNSt16allocator_traitsISaIPN8MemTable8QuadlistEEE10deallocateERS3_PS2_m+0x5e>
      { __a.deallocate(__p, __n); }
  5e:	90                   	nop
  5f:	90                   	nop
  60:	c9                   	leave  
  61:	c3                   	ret    

Disassembly of section .text._ZSt8_DestroyIPPN8MemTable8QuadlistEEvT_S4_:

0000000000000000 <_ZSt8_DestroyIPPN8MemTable8QuadlistEEvT_S4_>:
    _Destroy(_ForwardIterator __first, _ForwardIterator __last)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
      if (std::is_constant_evaluated())
  14:	e8 00 00 00 00       	call   19 <_ZSt8_DestroyIPPN8MemTable8QuadlistEEvT_S4_+0x19>
  19:	84 c0                	test   %al,%al
  1b:	74 15                	je     32 <_ZSt8_DestroyIPPN8MemTable8QuadlistEEvT_S4_+0x32>
	return _Destroy_aux<false>::__destroy(__first, __last);
  1d:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  21:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  25:	48 89 d6             	mov    %rdx,%rsi
  28:	48 89 c7             	mov    %rax,%rdi
  2b:	e8 00 00 00 00       	call   30 <_ZSt8_DestroyIPPN8MemTable8QuadlistEEvT_S4_+0x30>
  30:	eb 13                	jmp    45 <_ZSt8_DestroyIPPN8MemTable8QuadlistEEvT_S4_+0x45>
	__destroy(__first, __last);
  32:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  36:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  3a:	48 89 d6             	mov    %rdx,%rsi
  3d:	48 89 c7             	mov    %rax,%rdi
  40:	e8 00 00 00 00       	call   45 <_ZSt8_DestroyIPPN8MemTable8QuadlistEEvT_S4_+0x45>
    }
  45:	c9                   	leave  
  46:	c3                   	ret    

Disassembly of section .text._ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8max_sizeEv:

0000000000000000 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8max_sizeEv>:
      max_size() const _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
      { return (_Alloc_traits::max_size(_M_get_allocator()) - 1) / 2; }
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8max_sizeEv+0x1c>
  1c:	48 89 c7             	mov    %rax,%rdi
  1f:	e8 00 00 00 00       	call   24 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8max_sizeEv+0x24>
  24:	48 83 e8 01          	sub    $0x1,%rax
  28:	48 d1 e8             	shr    %rax
  2b:	c9                   	leave  
  2c:	c3                   	ret    

Disassembly of section .text._ZSt7forwardIRKN7KVStore7ssLevelEEOT_RNSt16remove_referenceIS4_E4typeE:

0000000000000000 <_ZSt7forwardIRKN7KVStore7ssLevelEEOT_RNSt16remove_referenceIS4_E4typeE>:
    forward(typename std::remove_reference<_Tp>::type& __t) noexcept
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    { return static_cast<_Tp&&>(__t); }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	5d                   	pop    %rbp
  11:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx17__normal_iteratorIPN7KVStore7ssLevelESt6vectorIS2_SaIS2_EEEC2ERKS3_:

0000000000000000 <_ZN9__gnu_cxx17__normal_iteratorIPN7KVStore7ssLevelESt6vectorIS2_SaIS2_EEEC1ERKS3_>:
      __normal_iterator(const _Iterator& __i) _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
      : _M_current(__i) { }
  10:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  14:	48 8b 10             	mov    (%rax),%rdx
  17:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  1b:	48 89 10             	mov    %rdx,(%rax)
  1e:	90                   	nop
  1f:	5d                   	pop    %rbp
  20:	c3                   	ret    

Disassembly of section .text._ZNKSt6vectorIN7KVStore7ssLevelESaIS1_EE12_M_check_lenEmPKc:

0000000000000000 <_ZNKSt6vectorIN7KVStore7ssLevelESaIS1_EE12_M_check_lenEmPKc>:
      _M_check_len(size_type __n, const char* __s) const
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 48          	sub    $0x48,%rsp
   d:	48 89 7d c8          	mov    %rdi,-0x38(%rbp)
  11:	48 89 75 c0          	mov    %rsi,-0x40(%rbp)
  15:	48 89 55 b8          	mov    %rdx,-0x48(%rbp)
  19:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  20:	00 00 
  22:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  26:	31 c0                	xor    %eax,%eax
	if (max_size() - size() < __n)
  28:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  2c:	48 89 c7             	mov    %rax,%rdi
  2f:	e8 00 00 00 00       	call   34 <_ZNKSt6vectorIN7KVStore7ssLevelESaIS1_EE12_M_check_lenEmPKc+0x34>
  34:	48 89 c3             	mov    %rax,%rbx
  37:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  3b:	48 89 c7             	mov    %rax,%rdi
  3e:	e8 00 00 00 00       	call   43 <_ZNKSt6vectorIN7KVStore7ssLevelESaIS1_EE12_M_check_lenEmPKc+0x43>
  43:	48 29 c3             	sub    %rax,%rbx
  46:	48 89 da             	mov    %rbx,%rdx
  49:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
  4d:	48 39 c2             	cmp    %rax,%rdx
  50:	0f 92 c0             	setb   %al
  53:	84 c0                	test   %al,%al
  55:	74 0c                	je     63 <_ZNKSt6vectorIN7KVStore7ssLevelESaIS1_EE12_M_check_lenEmPKc+0x63>
	  __throw_length_error(__N(__s));
  57:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  5b:	48 89 c7             	mov    %rax,%rdi
  5e:	e8 00 00 00 00       	call   63 <_ZNKSt6vectorIN7KVStore7ssLevelESaIS1_EE12_M_check_lenEmPKc+0x63>
	const size_type __len = size() + (std::max)(size(), __n);
  63:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  67:	48 89 c7             	mov    %rax,%rdi
  6a:	e8 00 00 00 00       	call   6f <_ZNKSt6vectorIN7KVStore7ssLevelESaIS1_EE12_M_check_lenEmPKc+0x6f>
  6f:	48 89 c3             	mov    %rax,%rbx
  72:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  76:	48 89 c7             	mov    %rax,%rdi
  79:	e8 00 00 00 00       	call   7e <_ZNKSt6vectorIN7KVStore7ssLevelESaIS1_EE12_M_check_lenEmPKc+0x7e>
  7e:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
  82:	48 8d 55 c0          	lea    -0x40(%rbp),%rdx
  86:	48 8d 45 d8          	lea    -0x28(%rbp),%rax
  8a:	48 89 d6             	mov    %rdx,%rsi
  8d:	48 89 c7             	mov    %rax,%rdi
  90:	e8 00 00 00 00       	call   95 <_ZNKSt6vectorIN7KVStore7ssLevelESaIS1_EE12_M_check_lenEmPKc+0x95>
  95:	48 8b 00             	mov    (%rax),%rax
  98:	48 01 d8             	add    %rbx,%rax
  9b:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
	return (__len < size() || __len > max_size()) ? max_size() : __len;
  9f:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  a3:	48 89 c7             	mov    %rax,%rdi
  a6:	e8 00 00 00 00       	call   ab <_ZNKSt6vectorIN7KVStore7ssLevelESaIS1_EE12_M_check_lenEmPKc+0xab>
  ab:	48 39 45 e0          	cmp    %rax,-0x20(%rbp)
  af:	72 12                	jb     c3 <_ZNKSt6vectorIN7KVStore7ssLevelESaIS1_EE12_M_check_lenEmPKc+0xc3>
  b1:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  b5:	48 89 c7             	mov    %rax,%rdi
  b8:	e8 00 00 00 00       	call   bd <_ZNKSt6vectorIN7KVStore7ssLevelESaIS1_EE12_M_check_lenEmPKc+0xbd>
  bd:	48 39 45 e0          	cmp    %rax,-0x20(%rbp)
  c1:	76 0e                	jbe    d1 <_ZNKSt6vectorIN7KVStore7ssLevelESaIS1_EE12_M_check_lenEmPKc+0xd1>
  c3:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  c7:	48 89 c7             	mov    %rax,%rdi
  ca:	e8 00 00 00 00       	call   cf <_ZNKSt6vectorIN7KVStore7ssLevelESaIS1_EE12_M_check_lenEmPKc+0xcf>
  cf:	eb 04                	jmp    d5 <_ZNKSt6vectorIN7KVStore7ssLevelESaIS1_EE12_M_check_lenEmPKc+0xd5>
  d1:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
      }
  d5:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  d9:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
  e0:	00 00 
  e2:	74 05                	je     e9 <_ZNKSt6vectorIN7KVStore7ssLevelESaIS1_EE12_M_check_lenEmPKc+0xe9>
  e4:	e8 00 00 00 00       	call   e9 <_ZNKSt6vectorIN7KVStore7ssLevelESaIS1_EE12_M_check_lenEmPKc+0xe9>
  e9:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  ed:	c9                   	leave  
  ee:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE5beginEv:

0000000000000000 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE5beginEv>:
      begin() _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  10:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  17:	00 00 
  19:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  1d:	31 c0                	xor    %eax,%eax
      { return iterator(this->_M_impl._M_start); }
  1f:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  23:	48 8d 45 f0          	lea    -0x10(%rbp),%rax
  27:	48 89 d6             	mov    %rdx,%rsi
  2a:	48 89 c7             	mov    %rax,%rdi
  2d:	e8 00 00 00 00       	call   32 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE5beginEv+0x32>
  32:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  36:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  3a:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
  41:	00 00 
  43:	74 05                	je     4a <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE5beginEv+0x4a>
  45:	e8 00 00 00 00       	call   4a <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE5beginEv+0x4a>
  4a:	c9                   	leave  
  4b:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxxmiIPN7KVStore7ssLevelESt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_:

0000000000000000 <_ZN9__gnu_cxxmiIPN7KVStore7ssLevelESt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_>:
    operator-(const __normal_iterator<_Iterator, _Container>& __lhs,
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 18          	sub    $0x18,%rsp
   d:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  11:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    { return __lhs.base() - __rhs.base(); }
  15:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  19:	48 89 c7             	mov    %rax,%rdi
  1c:	e8 00 00 00 00       	call   21 <_ZN9__gnu_cxxmiIPN7KVStore7ssLevelESt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_+0x21>
  21:	48 8b 18             	mov    (%rax),%rbx
  24:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  28:	48 89 c7             	mov    %rax,%rdi
  2b:	e8 00 00 00 00       	call   30 <_ZN9__gnu_cxxmiIPN7KVStore7ssLevelESt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_+0x30>
  30:	48 8b 10             	mov    (%rax),%rdx
  33:	48 89 d8             	mov    %rbx,%rax
  36:	48 29 d0             	sub    %rdx,%rax
  39:	48 c1 f8 03          	sar    $0x3,%rax
  3d:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  41:	c9                   	leave  
  42:	c3                   	ret    

Disassembly of section .text._ZNSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EE11_M_allocateEm:

0000000000000000 <_ZNSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EE11_M_allocateEm>:
      _M_allocate(size_t __n)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
	return __n != 0 ? _Tr::allocate(_M_impl, __n) : pointer();
  14:	48 83 7d f0 00       	cmpq   $0x0,-0x10(%rbp)
  19:	74 15                	je     30 <_ZNSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EE11_M_allocateEm+0x30>
  1b:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  1f:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  23:	48 89 d6             	mov    %rdx,%rsi
  26:	48 89 c7             	mov    %rax,%rdi
  29:	e8 00 00 00 00       	call   2e <_ZNSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EE11_M_allocateEm+0x2e>
  2e:	eb 05                	jmp    35 <_ZNSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EE11_M_allocateEm+0x35>
  30:	b8 00 00 00 00       	mov    $0x0,%eax
      }
  35:	c9                   	leave  
  36:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE11_S_relocateEPS1_S4_S4_RS2_:

0000000000000000 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE11_S_relocateEPS1_S4_S4_RS2_>:
      _S_relocate(pointer __first, pointer __last, pointer __result,
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
  18:	48 89 4d e0          	mov    %rcx,-0x20(%rbp)
	return _S_do_relocate(__first, __last, __result, __alloc, __do_it{});
  1c:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
  20:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  24:	48 8b 75 f0          	mov    -0x10(%rbp),%rsi
  28:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  2c:	48 89 c7             	mov    %rax,%rdi
  2f:	e8 00 00 00 00       	call   34 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE11_S_relocateEPS1_S4_S4_RS2_+0x34>
      }
  34:	c9                   	leave  
  35:	c3                   	ret    

Disassembly of section .text._ZNK9__gnu_cxx17__normal_iteratorIPN7KVStore7ssLevelESt6vectorIS2_SaIS2_EEE4baseEv:

0000000000000000 <_ZNK9__gnu_cxx17__normal_iteratorIPN7KVStore7ssLevelESt6vectorIS2_SaIS2_EEE4baseEv>:
      base() const _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
      { return _M_current; }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	5d                   	pop    %rbp
  11:	c3                   	ret    

Disassembly of section .text._ZNSt16allocator_traitsISaIcEE10deallocateERS0_Pcm:

0000000000000000 <_ZNSt16allocator_traitsISaIcEE10deallocateERS0_Pcm>:
      deallocate(allocator_type& __a, pointer __p, size_type __n)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 40          	sub    $0x40,%rsp
   c:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  10:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
  14:	48 89 55 c8          	mov    %rdx,-0x38(%rbp)
  18:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  1c:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  20:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  24:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
  28:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  2c:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
	if (std::is_constant_evaluated())
  30:	e8 00 00 00 00       	call   35 <_ZNSt16allocator_traitsISaIcEE10deallocateERS0_Pcm+0x35>
  35:	84 c0                	test   %al,%al
  37:	74 0e                	je     47 <_ZNSt16allocator_traitsISaIcEE10deallocateERS0_Pcm+0x47>
	    ::operator delete(__p);
  39:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  3d:	48 89 c7             	mov    %rax,%rdi
  40:	e8 00 00 00 00       	call   45 <_ZNSt16allocator_traitsISaIcEE10deallocateERS0_Pcm+0x45>
	    return;
  45:	eb 18                	jmp    5f <_ZNSt16allocator_traitsISaIcEE10deallocateERS0_Pcm+0x5f>
	__allocator_base<_Tp>::deallocate(__p, __n);
  47:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  4b:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
  4f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  53:	48 89 ce             	mov    %rcx,%rsi
  56:	48 89 c7             	mov    %rax,%rdi
  59:	e8 00 00 00 00       	call   5e <_ZNSt16allocator_traitsISaIcEE10deallocateERS0_Pcm+0x5e>
      { __a.deallocate(__p, __n); }
  5e:	90                   	nop
  5f:	90                   	nop
  60:	c9                   	leave  
  61:	c3                   	ret    

Disassembly of section .text._ZSt14__copy_move_a2ILb0EPKcPcET1_T0_S4_S3_:

0000000000000000 <_ZSt14__copy_move_a2ILb0EPKcPcET1_T0_S4_S3_>:
    __copy_move_a2(_II __first, _II __last, _OI __result)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
      if (std::is_constant_evaluated())
  18:	e8 00 00 00 00       	call   1d <_ZSt14__copy_move_a2ILb0EPKcPcET1_T0_S4_S3_+0x1d>
  1d:	84 c0                	test   %al,%al
  1f:	74 19                	je     3a <_ZSt14__copy_move_a2ILb0EPKcPcET1_T0_S4_S3_+0x3a>
	  __copy_m(__first, __last, __result);
  21:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  25:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
  29:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  2d:	48 89 ce             	mov    %rcx,%rsi
  30:	48 89 c7             	mov    %rax,%rdi
  33:	e8 00 00 00 00       	call   38 <_ZSt14__copy_move_a2ILb0EPKcPcET1_T0_S4_S3_+0x38>
  38:	eb 18                	jmp    52 <_ZSt14__copy_move_a2ILb0EPKcPcET1_T0_S4_S3_+0x52>
			      _Category>::__copy_m(__first, __last, __result);
  3a:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  3e:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
  42:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  46:	48 89 ce             	mov    %rcx,%rsi
  49:	48 89 c7             	mov    %rax,%rdi
  4c:	e8 00 00 00 00       	call   51 <_ZSt14__copy_move_a2ILb0EPKcPcET1_T0_S4_S3_+0x51>
  51:	90                   	nop
    }
  52:	c9                   	leave  
  53:	c3                   	ret    

Disassembly of section .text._ZSt9__fill_a1IcEN9__gnu_cxx11__enable_ifIXsrSt9__is_byteIT_E7__valueEvE6__typeEPS3_S7_RKS3_:

0000000000000000 <_ZSt9__fill_a1IcEN9__gnu_cxx11__enable_ifIXsrSt9__is_byteIT_E7__valueEvE6__typeEPS3_S7_RKS3_>:
    __fill_a1(_Tp* __first, _Tp* __last, const _Tp& __c)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 30          	sub    $0x30,%rsp
   c:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  10:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  14:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
      const _Tp __tmp = __c;
  18:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  1c:	0f b6 00             	movzbl (%rax),%eax
  1f:	88 45 f7             	mov    %al,-0x9(%rbp)
      if (std::is_constant_evaluated())
  22:	e8 00 00 00 00       	call   27 <_ZSt9__fill_a1IcEN9__gnu_cxx11__enable_ifIXsrSt9__is_byteIT_E7__valueEvE6__typeEPS3_S7_RKS3_+0x27>
  27:	84 c0                	test   %al,%al
  29:	74 1d                	je     48 <_ZSt9__fill_a1IcEN9__gnu_cxx11__enable_ifIXsrSt9__is_byteIT_E7__valueEvE6__typeEPS3_S7_RKS3_+0x48>
	  for (; __first != __last; ++__first)
  2b:	eb 0f                	jmp    3c <_ZSt9__fill_a1IcEN9__gnu_cxx11__enable_ifIXsrSt9__is_byteIT_E7__valueEvE6__typeEPS3_S7_RKS3_+0x3c>
	    *__first = __tmp;
  2d:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  31:	0f b6 55 f7          	movzbl -0x9(%rbp),%edx
  35:	88 10                	mov    %dl,(%rax)
	  for (; __first != __last; ++__first)
  37:	48 83 45 e8 01       	addq   $0x1,-0x18(%rbp)
  3c:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  40:	48 3b 45 e0          	cmp    -0x20(%rbp),%rax
  44:	75 e7                	jne    2d <_ZSt9__fill_a1IcEN9__gnu_cxx11__enable_ifIXsrSt9__is_byteIT_E7__valueEvE6__typeEPS3_S7_RKS3_+0x2d>
	  return;
  46:	eb 2c                	jmp    74 <_ZSt9__fill_a1IcEN9__gnu_cxx11__enable_ifIXsrSt9__is_byteIT_E7__valueEvE6__typeEPS3_S7_RKS3_+0x74>
      if (const size_t __len = __last - __first)
  48:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  4c:	48 2b 45 e8          	sub    -0x18(%rbp),%rax
  50:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  54:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
  59:	74 19                	je     74 <_ZSt9__fill_a1IcEN9__gnu_cxx11__enable_ifIXsrSt9__is_byteIT_E7__valueEvE6__typeEPS3_S7_RKS3_+0x74>
	__builtin_memset(__first, static_cast<unsigned char>(__tmp), __len);
  5b:	0f b6 45 f7          	movzbl -0x9(%rbp),%eax
  5f:	0f b6 c8             	movzbl %al,%ecx
  62:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  66:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  6a:	89 ce                	mov    %ecx,%esi
  6c:	48 89 c7             	mov    %rax,%rdi
  6f:	e8 00 00 00 00       	call   74 <_ZSt9__fill_a1IcEN9__gnu_cxx11__enable_ifIXsrSt9__is_byteIT_E7__valueEvE6__typeEPS3_S7_RKS3_+0x74>
    }
  74:	c9                   	leave  
  75:	c3                   	ret    

Disassembly of section .text._ZSt9addressofIcEPT_RS0_:

0000000000000000 <_ZSt9addressofIcEPT_RS0_>:
   *  @return   The actual address.
  */
  template<typename _Tp>
    _GLIBCXX_NODISCARD
    inline _GLIBCXX17_CONSTEXPR _Tp*
    addressof(_Tp& __r) noexcept
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    { return std::__addressof(__r); }
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZSt9addressofIcEPT_RS0_+0x1c>
  1c:	c9                   	leave  
  1d:	c3                   	ret    

Disassembly of section .text._ZNSt14pointer_traitsIPKcE10pointer_toERS0_:

0000000000000000 <_ZNSt14pointer_traitsIPKcE10pointer_toERS0_>:
      pointer_to(__make_not_void<element_type>& __r) noexcept
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
      { return std::addressof(__r); }
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZNSt14pointer_traitsIPKcE10pointer_toERS0_+0x1c>
  1c:	c9                   	leave  
  1d:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm>:
      return *this;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT, _Traits, _Alloc>&
    basic_string<_CharT, _Traits, _Alloc>::
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 60          	sub    $0x60,%rsp
   c:	48 89 7d c8          	mov    %rdi,-0x38(%rbp)
  10:	48 89 75 c0          	mov    %rsi,-0x40(%rbp)
  14:	48 89 55 b8          	mov    %rdx,-0x48(%rbp)
  18:	48 89 4d b0          	mov    %rcx,-0x50(%rbp)
  1c:	4c 89 45 a8          	mov    %r8,-0x58(%rbp)
    _M_replace(size_type __pos, size_type __len1, const _CharT* __s,
	       const size_type __len2)
    {
      _M_check_length(__len1, __len2, "basic_string::_M_replace");
  20:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
  24:	48 8b 75 b8          	mov    -0x48(%rbp),%rsi
  28:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  2c:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # 33 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x33>
  33:	48 89 c7             	mov    %rax,%rdi
  36:	e8 00 00 00 00       	call   3b <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x3b>

      const size_type __old_size = this->size();
  3b:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  3f:	48 89 c7             	mov    %rax,%rdi
  42:	e8 00 00 00 00       	call   47 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x47>
  47:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
      const size_type __new_size = __old_size + __len2 - __len1;
  4b:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
  4f:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  53:	48 01 d0             	add    %rdx,%rax
  56:	48 2b 45 b8          	sub    -0x48(%rbp),%rax
  5a:	48 89 45 d8          	mov    %rax,-0x28(%rbp)

      if (__new_size <= this->capacity())
  5e:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  62:	48 89 c7             	mov    %rax,%rdi
  65:	e8 00 00 00 00       	call   6a <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x6a>
  6a:	48 39 45 d8          	cmp    %rax,-0x28(%rbp)
  6e:	0f 96 c0             	setbe  %al
  71:	84 c0                	test   %al,%al
  73:	0f 84 e4 01 00 00    	je     25d <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x25d>
	{
	  pointer __p = this->_M_data() + __pos;
  79:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  7d:	48 89 c7             	mov    %rax,%rdi
  80:	e8 00 00 00 00       	call   85 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x85>
  85:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
  89:	48 01 d0             	add    %rdx,%rax
  8c:	48 89 45 e0          	mov    %rax,-0x20(%rbp)

	  const size_type __how_much = __old_size - __pos - __len1;
  90:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  94:	48 2b 45 c0          	sub    -0x40(%rbp),%rax
  98:	48 2b 45 b8          	sub    -0x48(%rbp),%rax
  9c:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
	  if (_M_disjunct(__s))
  a0:	48 8b 55 b0          	mov    -0x50(%rbp),%rdx
  a4:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  a8:	48 89 d6             	mov    %rdx,%rsi
  ab:	48 89 c7             	mov    %rax,%rdi
  ae:	e8 00 00 00 00       	call   b3 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0xb3>
  b3:	84 c0                	test   %al,%al
  b5:	74 5f                	je     116 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x116>
	    {
	      if (__how_much && __len1 != __len2)
  b7:	48 83 7d e8 00       	cmpq   $0x0,-0x18(%rbp)
  bc:	74 31                	je     ef <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0xef>
  be:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  c2:	48 3b 45 a8          	cmp    -0x58(%rbp),%rax
  c6:	74 27                	je     ef <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0xef>
		this->_S_move(__p + __len2, __p + __len1, __how_much);
  c8:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
  cc:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  d0:	48 8d 34 02          	lea    (%rdx,%rax,1),%rsi
  d4:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
  d8:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  dc:	48 8d 0c 02          	lea    (%rdx,%rax,1),%rcx
  e0:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  e4:	48 89 c2             	mov    %rax,%rdx
  e7:	48 89 cf             	mov    %rcx,%rdi
  ea:	e8 00 00 00 00       	call   ef <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0xef>
	      if (__len2)
  ef:	48 83 7d a8 00       	cmpq   $0x0,-0x58(%rbp)
  f4:	0f 84 82 01 00 00    	je     27c <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x27c>
		this->_S_copy(__p, __s, __len2);
  fa:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
  fe:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
 102:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
 106:	48 89 ce             	mov    %rcx,%rsi
 109:	48 89 c7             	mov    %rax,%rdi
 10c:	e8 00 00 00 00       	call   111 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x111>
 111:	e9 66 01 00 00       	jmp    27c <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x27c>
	    }
	  else
	    {
	      // Work in-place.
	      if (__len2 && __len2 <= __len1)
 116:	48 83 7d a8 00       	cmpq   $0x0,-0x58(%rbp)
 11b:	74 21                	je     13e <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x13e>
 11d:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
 121:	48 3b 45 b8          	cmp    -0x48(%rbp),%rax
 125:	77 17                	ja     13e <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x13e>
		this->_S_move(__p, __s, __len2);
 127:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
 12b:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
 12f:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
 133:	48 89 ce             	mov    %rcx,%rsi
 136:	48 89 c7             	mov    %rax,%rdi
 139:	e8 00 00 00 00       	call   13e <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x13e>
	      if (__how_much && __len1 != __len2)
 13e:	48 83 7d e8 00       	cmpq   $0x0,-0x18(%rbp)
 143:	74 31                	je     176 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x176>
 145:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
 149:	48 3b 45 a8          	cmp    -0x58(%rbp),%rax
 14d:	74 27                	je     176 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x176>
		this->_S_move(__p + __len2, __p + __len1, __how_much);
 14f:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
 153:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
 157:	48 8d 34 02          	lea    (%rdx,%rax,1),%rsi
 15b:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
 15f:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
 163:	48 8d 0c 02          	lea    (%rdx,%rax,1),%rcx
 167:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
 16b:	48 89 c2             	mov    %rax,%rdx
 16e:	48 89 cf             	mov    %rcx,%rdi
 171:	e8 00 00 00 00       	call   176 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x176>
	      if (__len2 > __len1)
 176:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
 17a:	48 3b 45 b8          	cmp    -0x48(%rbp),%rax
 17e:	0f 86 f8 00 00 00    	jbe    27c <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x27c>
		{
		  if (__s + __len2 <= __p + __len1)
 184:	48 8b 55 b0          	mov    -0x50(%rbp),%rdx
 188:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
 18c:	48 01 c2             	add    %rax,%rdx
 18f:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
 193:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
 197:	48 01 c8             	add    %rcx,%rax
 19a:	48 39 c2             	cmp    %rax,%rdx
 19d:	77 1c                	ja     1bb <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x1bb>
		    this->_S_move(__p, __s, __len2);
 19f:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
 1a3:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
 1a7:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
 1ab:	48 89 ce             	mov    %rcx,%rsi
 1ae:	48 89 c7             	mov    %rax,%rdi
 1b1:	e8 00 00 00 00       	call   1b6 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x1b6>
 1b6:	e9 c1 00 00 00       	jmp    27c <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x27c>
		  else if (__s >= __p + __len1)
 1bb:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
 1bf:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
 1c3:	48 01 d0             	add    %rdx,%rax
 1c6:	48 39 45 b0          	cmp    %rax,-0x50(%rbp)
 1ca:	72 3b                	jb     207 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x207>
		    {
		      // Hint to middle end that __p and __s overlap
		      // (PR 98465).
		      const size_type __poff = (__s - __p) + (__len2 - __len1);
 1cc:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
 1d0:	48 2b 45 e0          	sub    -0x20(%rbp),%rax
 1d4:	48 89 c2             	mov    %rax,%rdx
 1d7:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
 1db:	48 2b 45 b8          	sub    -0x48(%rbp),%rax
 1df:	48 01 d0             	add    %rdx,%rax
 1e2:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
		      this->_S_copy(__p, __p + __poff, __len2);
 1e6:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
 1ea:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
 1ee:	48 8d 0c 02          	lea    (%rdx,%rax,1),%rcx
 1f2:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
 1f6:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
 1fa:	48 89 ce             	mov    %rcx,%rsi
 1fd:	48 89 c7             	mov    %rax,%rdi
 200:	e8 00 00 00 00       	call   205 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x205>
 205:	eb 75                	jmp    27c <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x27c>
		    }
		  else
		    {
		      const size_type __nleft = (__p + __len1) - __s;
 207:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
 20b:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
 20f:	48 01 d0             	add    %rdx,%rax
 212:	48 2b 45 b0          	sub    -0x50(%rbp),%rax
 216:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
		      this->_S_move(__p, __s, __nleft);
 21a:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
 21e:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
 222:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
 226:	48 89 ce             	mov    %rcx,%rsi
 229:	48 89 c7             	mov    %rax,%rdi
 22c:	e8 00 00 00 00       	call   231 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x231>
		      this->_S_copy(__p + __nleft, __p + __len2,
 231:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
 235:	48 2b 45 f0          	sub    -0x10(%rbp),%rax
 239:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
 23d:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
 241:	48 8d 34 11          	lea    (%rcx,%rdx,1),%rsi
 245:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
 249:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
 24d:	48 01 d1             	add    %rdx,%rcx
 250:	48 89 c2             	mov    %rax,%rdx
 253:	48 89 cf             	mov    %rcx,%rdi
 256:	e8 00 00 00 00       	call   25b <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x25b>
 25b:	eb 1f                	jmp    27c <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x27c>
		    }
		}
	    }
	}
      else
	this->_M_mutate(__pos, __len1, __s, __len2);
 25d:	48 8b 7d a8          	mov    -0x58(%rbp),%rdi
 261:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
 265:	48 8b 55 b8          	mov    -0x48(%rbp),%rdx
 269:	48 8b 75 c0          	mov    -0x40(%rbp),%rsi
 26d:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
 271:	49 89 f8             	mov    %rdi,%r8
 274:	48 89 c7             	mov    %rax,%rdi
 277:	e8 00 00 00 00       	call   27c <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x27c>

      this->_M_set_length(__new_size);
 27c:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
 280:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
 284:	48 89 d6             	mov    %rdx,%rsi
 287:	48 89 c7             	mov    %rax,%rdi
 28a:	e8 00 00 00 00       	call   28f <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm+0x28f>
      return *this;
 28f:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    }
 293:	c9                   	leave  
 294:	c3                   	ret    

Disassembly of section .text._ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8_M_checkEmPKc:

0000000000000000 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8_M_checkEmPKc>:
      _M_check(size_type __pos, const char* __s) const
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
	if (__pos > this->size())
  18:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  1c:	48 89 c7             	mov    %rax,%rdi
  1f:	e8 00 00 00 00       	call   24 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8_M_checkEmPKc+0x24>
  24:	48 39 45 f0          	cmp    %rax,-0x10(%rbp)
  28:	0f 97 c0             	seta   %al
  2b:	84 c0                	test   %al,%al
  2d:	74 2e                	je     5d <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8_M_checkEmPKc+0x5d>
	  __throw_out_of_range_fmt(__N("%s: __pos (which is %zu) > "
  2f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  33:	48 89 c7             	mov    %rax,%rdi
  36:	e8 00 00 00 00       	call   3b <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8_M_checkEmPKc+0x3b>
  3b:	48 89 c1             	mov    %rax,%rcx
  3e:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  42:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  46:	48 89 c6             	mov    %rax,%rsi
  49:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 50 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8_M_checkEmPKc+0x50>
  50:	48 89 c7             	mov    %rax,%rdi
  53:	b8 00 00 00 00       	mov    $0x0,%eax
  58:	e8 00 00 00 00       	call   5d <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8_M_checkEmPKc+0x5d>
	return __pos;
  5d:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
      }
  61:	c9                   	leave  
  62:	c3                   	ret    

Disassembly of section .text._ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8_M_limitEmm:

0000000000000000 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8_M_limitEmm>:
      _M_limit(size_type __pos, size_type __off) const _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 30          	sub    $0x30,%rsp
   c:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  10:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  14:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
	const bool __testoff =  __off < this->size() - __pos;
  18:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  1c:	48 89 c7             	mov    %rax,%rdi
  1f:	e8 00 00 00 00       	call   24 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8_M_limitEmm+0x24>
  24:	48 2b 45 e0          	sub    -0x20(%rbp),%rax
  28:	48 39 45 d8          	cmp    %rax,-0x28(%rbp)
  2c:	0f 92 c0             	setb   %al
  2f:	88 45 ff             	mov    %al,-0x1(%rbp)
	return __testoff ? __off : this->size() - __pos;
  32:	80 7d ff 00          	cmpb   $0x0,-0x1(%rbp)
  36:	74 06                	je     3e <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8_M_limitEmm+0x3e>
  38:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  3c:	eb 10                	jmp    4e <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8_M_limitEmm+0x4e>
  3e:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  42:	48 89 c7             	mov    %rax,%rdi
  45:	e8 00 00 00 00       	call   4a <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8_M_limitEmm+0x4a>
  4a:	48 2b 45 e0          	sub    -0x20(%rbp),%rax
      }
  4e:	c9                   	leave  
  4f:	c3                   	ret    

Disassembly of section .text._ZSt8distanceIPcENSt15iterator_traitsIT_E15difference_typeES2_S2_:

0000000000000000 <_ZSt8distanceIPcENSt15iterator_traitsIT_E15difference_typeES2_S2_>:
    distance(_InputIterator __first, _InputIterator __last)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
			     std::__iterator_category(__first));
  14:	48 8d 45 f8          	lea    -0x8(%rbp),%rax
  18:	48 89 c7             	mov    %rax,%rdi
  1b:	e8 00 00 00 00       	call   20 <_ZSt8distanceIPcENSt15iterator_traitsIT_E15difference_typeES2_S2_+0x20>
      return std::__distance(__first, __last,
  20:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  24:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  28:	48 89 d6             	mov    %rdx,%rsi
  2b:	48 89 c7             	mov    %rax,%rdi
  2e:	e8 00 00 00 00       	call   33 <_ZSt8distanceIPcENSt15iterator_traitsIT_E15difference_typeES2_S2_+0x33>
    }
  33:	c9                   	leave  
  34:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag>:
      basic_string<_CharT, _Traits, _Alloc>::
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 30          	sub    $0x30,%rsp
   c:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  10:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  14:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
  18:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  1f:	00 00 
  21:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  25:	31 c0                	xor    %eax,%eax
	if (__gnu_cxx::__is_null_pointer(__beg) && __beg != __end)
  27:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  2b:	48 89 c7             	mov    %rax,%rdi
  2e:	e8 00 00 00 00       	call   33 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag+0x33>
  33:	84 c0                	test   %al,%al
  35:	74 11                	je     48 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag+0x48>
  37:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  3b:	48 3b 45 d8          	cmp    -0x28(%rbp),%rax
  3f:	74 07                	je     48 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag+0x48>
  41:	b8 01 00 00 00       	mov    $0x1,%eax
  46:	eb 05                	jmp    4d <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag+0x4d>
  48:	b8 00 00 00 00       	mov    $0x0,%eax
  4d:	84 c0                	test   %al,%al
  4f:	74 0f                	je     60 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag+0x60>
	  std::__throw_logic_error(__N("basic_string::"
  51:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 58 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag+0x58>
  58:	48 89 c7             	mov    %rax,%rdi
  5b:	e8 00 00 00 00       	call   60 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag+0x60>
	size_type __dnew = static_cast<size_type>(std::distance(__beg, __end));
  60:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
  64:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  68:	48 89 d6             	mov    %rdx,%rsi
  6b:	48 89 c7             	mov    %rax,%rdi
  6e:	e8 00 00 00 00       	call   73 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag+0x73>
  73:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
	if (__dnew > size_type(_S_local_capacity))
  77:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  7b:	48 83 f8 0f          	cmp    $0xf,%rax
  7f:	76 3d                	jbe    be <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag+0xbe>
	    _M_data(_M_create(__dnew, size_type(0)));
  81:	48 8d 4d f0          	lea    -0x10(%rbp),%rcx
  85:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  89:	ba 00 00 00 00       	mov    $0x0,%edx
  8e:	48 89 ce             	mov    %rcx,%rsi
  91:	48 89 c7             	mov    %rax,%rdi
  94:	e8 00 00 00 00       	call   99 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag+0x99>
  99:	48 89 c2             	mov    %rax,%rdx
  9c:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  a0:	48 89 d6             	mov    %rdx,%rsi
  a3:	48 89 c7             	mov    %rax,%rdi
  a6:	e8 00 00 00 00       	call   ab <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag+0xab>
	    _M_capacity(__dnew);
  ab:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  af:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  b3:	48 89 d6             	mov    %rdx,%rsi
  b6:	48 89 c7             	mov    %rax,%rdi
  b9:	e8 00 00 00 00       	call   be <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag+0xbe>
	  { this->_S_copy_chars(_M_data(), __beg, __end); }
  be:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  c2:	48 89 c7             	mov    %rax,%rdi
  c5:	e8 00 00 00 00       	call   ca <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag+0xca>
  ca:	48 89 c1             	mov    %rax,%rcx
  cd:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
  d1:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  d5:	48 89 c6             	mov    %rax,%rsi
  d8:	48 89 cf             	mov    %rcx,%rdi
  db:	e8 00 00 00 00       	call   e0 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag+0xe0>
	_M_set_length(__dnew);
  e0:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  e4:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  e8:	48 89 d6             	mov    %rdx,%rsi
  eb:	48 89 c7             	mov    %rax,%rdi
  ee:	e8 00 00 00 00       	call   f3 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag+0xf3>
      }
  f3:	90                   	nop
  f4:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  f8:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
  ff:	00 00 
 101:	74 05                	je     108 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag+0x108>
 103:	e8 00 00 00 00       	call   108 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag+0x108>
 108:	c9                   	leave  
 109:	c3                   	ret    

Disassembly of section .text._ZNK9__gnu_cxx17__normal_iteratorIPPN8MemTable8QuadlistESt6vectorIS3_SaIS3_EEEmiEl:

0000000000000000 <_ZNK9__gnu_cxx17__normal_iteratorIPPN8MemTable8QuadlistESt6vectorIS3_SaIS3_EEEmiEl>:
      operator-(difference_type __n) const _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 30          	sub    $0x30,%rsp
   c:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  10:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
  14:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  1b:	00 00 
  1d:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  21:	31 c0                	xor    %eax,%eax
      { return __normal_iterator(_M_current - __n); }
  23:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  27:	48 8b 10             	mov    (%rax),%rdx
  2a:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  2e:	48 c1 e0 03          	shl    $0x3,%rax
  32:	48 f7 d8             	neg    %rax
  35:	48 01 d0             	add    %rdx,%rax
  38:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  3c:	48 8d 55 e8          	lea    -0x18(%rbp),%rdx
  40:	48 8d 45 f0          	lea    -0x10(%rbp),%rax
  44:	48 89 d6             	mov    %rdx,%rsi
  47:	48 89 c7             	mov    %rax,%rdi
  4a:	e8 00 00 00 00       	call   4f <_ZNK9__gnu_cxx17__normal_iteratorIPPN8MemTable8QuadlistESt6vectorIS3_SaIS3_EEEmiEl+0x4f>
  4f:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  53:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  57:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
  5e:	00 00 
  60:	74 05                	je     67 <_ZNK9__gnu_cxx17__normal_iteratorIPPN8MemTable8QuadlistESt6vectorIS3_SaIS3_EEEmiEl+0x67>
  62:	e8 00 00 00 00       	call   67 <_ZNK9__gnu_cxx17__normal_iteratorIPPN8MemTable8QuadlistESt6vectorIS3_SaIS3_EEEmiEl+0x67>
  67:	c9                   	leave  
  68:	c3                   	ret    

Disassembly of section .text._ZNK9__gnu_cxx17__normal_iteratorIPPN8MemTable8QuadlistESt6vectorIS3_SaIS3_EEEdeEv:

0000000000000000 <_ZNK9__gnu_cxx17__normal_iteratorIPPN8MemTable8QuadlistESt6vectorIS3_SaIS3_EEEdeEv>:
      operator*() const _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
      { return *_M_current; }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	48 8b 00             	mov    (%rax),%rax
  13:	5d                   	pop    %rbp
  14:	c3                   	ret    

Disassembly of section .text._ZNK9__gnu_cxx13new_allocatorIcE11_M_max_sizeEv:

0000000000000000 <_ZNK9__gnu_cxx13new_allocatorIcE11_M_max_sizeEv>:
	{ return false; }
#endif

    private:
      _GLIBCXX_CONSTEXPR size_type
      _M_max_size() const _GLIBCXX_USE_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
      {
#if __PTRDIFF_MAX__ < __SIZE_MAX__
	return std::size_t(__PTRDIFF_MAX__) / sizeof(_Tp);
   c:	48 b8 ff ff ff ff ff 	movabs $0x7fffffffffffffff,%rax
  13:	ff ff 7f 
#else
	return std::size_t(-1) / sizeof(_Tp);
#endif
      }
  16:	5d                   	pop    %rbp
  17:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx13new_allocatorIcE8allocateEmPKv:

0000000000000000 <_ZN9__gnu_cxx13new_allocatorIcE8allocateEmPKv>:
      allocate(size_type __n, const void* = static_cast<const void*>(0))
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
	if (__builtin_expect(__n > this->_M_max_size(), false))
  18:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  1c:	48 89 c7             	mov    %rax,%rdi
  1f:	e8 00 00 00 00       	call   24 <_ZN9__gnu_cxx13new_allocatorIcE8allocateEmPKv+0x24>
  24:	48 39 45 f0          	cmp    %rax,-0x10(%rbp)
  28:	0f 97 c0             	seta   %al
  2b:	0f b6 c0             	movzbl %al,%eax
  2e:	48 85 c0             	test   %rax,%rax
  31:	0f 95 c0             	setne  %al
  34:	84 c0                	test   %al,%al
  36:	74 05                	je     3d <_ZN9__gnu_cxx13new_allocatorIcE8allocateEmPKv+0x3d>
	    std::__throw_bad_alloc();
  38:	e8 00 00 00 00       	call   3d <_ZN9__gnu_cxx13new_allocatorIcE8allocateEmPKv+0x3d>
	return static_cast<_Tp*>(::operator new(__n * sizeof(_Tp)));
  3d:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  41:	48 89 c7             	mov    %rax,%rdi
  44:	e8 00 00 00 00       	call   49 <_ZN9__gnu_cxx13new_allocatorIcE8allocateEmPKv+0x49>
  49:	90                   	nop
      }
  4a:	c9                   	leave  
  4b:	c3                   	ret    

Disassembly of section .text._ZNSt8__detail4_ModImLm4294967296ELm1ELm0ELb1ELb1EE6__calcEm:

0000000000000000 <_ZNSt8__detail4_ModImLm4294967296ELm1ELm0ELb1ELb1EE6__calcEm>:
	__calc(_Tp __x)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
	  _Tp __res = __a * __x + __c;
   c:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  10:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
	    __res %= __m;
  14:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  19:	48 21 45 f8          	and    %rax,-0x8(%rbp)
	  return __res;
  1d:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
	}
  21:	5d                   	pop    %rbp
  22:	c3                   	ret    

Disassembly of section .text._ZNSt8__detail4_ModImLm624ELm1ELm0ELb1ELb1EE6__calcEm:

0000000000000000 <_ZNSt8__detail4_ModImLm624ELm1ELm0ELb1ELb1EE6__calcEm>:
	__calc(_Tp __x)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
	  _Tp __res = __a * __x + __c;
   c:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  10:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
	    __res %= __m;
  14:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
  18:	48 89 c8             	mov    %rcx,%rax
  1b:	48 c1 e8 04          	shr    $0x4,%rax
  1f:	48 ba 21 0d d2 20 0d 	movabs $0xd20d20d20d20d21,%rdx
  26:	d2 20 0d 
  29:	48 f7 e2             	mul    %rdx
  2c:	48 89 d0             	mov    %rdx,%rax
  2f:	48 d1 e8             	shr    %rax
  32:	48 69 d0 70 02 00 00 	imul   $0x270,%rax,%rdx
  39:	48 89 c8             	mov    %rcx,%rax
  3c:	48 29 d0             	sub    %rdx,%rax
  3f:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
	  return __res;
  43:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
	}
  47:	5d                   	pop    %rbp
  48:	c3                   	ret    

Disassembly of section .text._ZSt3minImERKT_S2_S2_:

0000000000000000 <_ZSt3minImERKT_S2_S2_>:
    min(const _Tp& __a, const _Tp& __b)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
      if (__b < __a)
  10:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  14:	48 8b 10             	mov    (%rax),%rdx
  17:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  1b:	48 8b 00             	mov    (%rax),%rax
  1e:	48 39 c2             	cmp    %rax,%rdx
  21:	73 06                	jae    29 <_ZSt3minImERKT_S2_S2_+0x29>
	return __b;
  23:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  27:	eb 04                	jmp    2d <_ZSt3minImERKT_S2_S2_+0x2d>
      return __a;
  29:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    }
  2d:	5d                   	pop    %rbp
  2e:	c3                   	ret    

Disassembly of section .text._ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE3minEv:

0000000000000000 <_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE3minEv>:
      min()
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
      { return 0; }
   8:	b8 00 00 00 00       	mov    $0x0,%eax
   d:	5d                   	pop    %rbp
   e:	c3                   	ret    

Disassembly of section .text._ZSt3maxImERKT_S2_S2_:

0000000000000000 <_ZSt3maxImERKT_S2_S2_>:
    max(const _Tp& __a, const _Tp& __b)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
      if (__a < __b)
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 8b 10             	mov    (%rax),%rdx
  17:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  1b:	48 8b 00             	mov    (%rax),%rax
  1e:	48 39 c2             	cmp    %rax,%rdx
  21:	73 06                	jae    29 <_ZSt3maxImERKT_S2_S2_+0x29>
	return __b;
  23:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  27:	eb 04                	jmp    2d <_ZSt3maxImERKT_S2_S2_+0x2d>
      return __a;
  29:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    }
  2d:	5d                   	pop    %rbp
  2e:	c3                   	ret    

Disassembly of section .text._ZSt18generate_canonicalIdLm53ESt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEET_RT1_:

0000000000000000 <_ZSt18generate_canonicalIdLm53ESt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEET_RT1_>:
    }

  template<typename _RealType, size_t __bits,
	   typename _UniformRandomNumberGenerator>
    _RealType
    generate_canonical(_UniformRandomNumberGenerator& __urng)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 68          	sub    $0x68,%rsp
   d:	48 89 7d 98          	mov    %rdi,-0x68(%rbp)
    {
      static_assert(std::is_floating_point<_RealType>::value,
		    "template argument must be a floating point type");

      const size_t __b
  11:	48 c7 45 c8 35 00 00 	movq   $0x35,-0x38(%rbp)
  18:	00 
	= std::min(static_cast<size_t>(std::numeric_limits<_RealType>::digits),
                   __bits);
      const long double __r = static_cast<long double>(__urng.max())
  19:	db 2d 00 00 00 00    	fldt   0x0(%rip)        # 1f <_ZSt18generate_canonicalIdLm53ESt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEET_RT1_+0x1f>
  1f:	db 7d e0             	fstpt  -0x20(%rbp)
			    - static_cast<long double>(__urng.min()) + 1.0L;
      const size_t __log2r = std::log(__r) / std::log(2.0L);
  22:	48 c7 45 d0 20 00 00 	movq   $0x20,-0x30(%rbp)
  29:	00 
      const size_t __m = std::max<size_t>(1UL,
  2a:	48 c7 45 d8 02 00 00 	movq   $0x2,-0x28(%rbp)
  31:	00 
					  (__b + __log2r - 1UL) / __log2r);
      _RealType __ret;
      _RealType __sum = _RealType(0);
  32:	66 0f ef c0          	pxor   %xmm0,%xmm0
  36:	f2 0f 11 45 b0       	movsd  %xmm0,-0x50(%rbp)
      _RealType __tmp = _RealType(1);
  3b:	f2 0f 10 05 00 00 00 	movsd  0x0(%rip),%xmm0        # 43 <_ZSt18generate_canonicalIdLm53ESt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEET_RT1_+0x43>
  42:	00 
  43:	f2 0f 11 45 b8       	movsd  %xmm0,-0x48(%rbp)
      for (size_t __k = __m; __k != 0; --__k)
  48:	48 c7 45 c0 02 00 00 	movq   $0x2,-0x40(%rbp)
  4f:	00 
  50:	eb 6c                	jmp    be <_ZSt18generate_canonicalIdLm53ESt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEET_RT1_+0xbe>
	{
	  __sum += _RealType(__urng() - __urng.min()) * __tmp;
  52:	48 8b 45 98          	mov    -0x68(%rbp),%rax
  56:	48 89 c7             	mov    %rax,%rdi
  59:	e8 00 00 00 00       	call   5e <_ZSt18generate_canonicalIdLm53ESt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEET_RT1_+0x5e>
  5e:	48 89 c3             	mov    %rax,%rbx
  61:	e8 00 00 00 00       	call   66 <_ZSt18generate_canonicalIdLm53ESt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEET_RT1_+0x66>
  66:	48 89 c2             	mov    %rax,%rdx
  69:	48 89 d8             	mov    %rbx,%rax
  6c:	48 29 d0             	sub    %rdx,%rax
  6f:	48 85 c0             	test   %rax,%rax
  72:	78 0b                	js     7f <_ZSt18generate_canonicalIdLm53ESt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEET_RT1_+0x7f>
  74:	66 0f ef c0          	pxor   %xmm0,%xmm0
  78:	f2 48 0f 2a c0       	cvtsi2sd %rax,%xmm0
  7d:	eb 19                	jmp    98 <_ZSt18generate_canonicalIdLm53ESt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEET_RT1_+0x98>
  7f:	48 89 c2             	mov    %rax,%rdx
  82:	48 d1 ea             	shr    %rdx
  85:	83 e0 01             	and    $0x1,%eax
  88:	48 09 c2             	or     %rax,%rdx
  8b:	66 0f ef c0          	pxor   %xmm0,%xmm0
  8f:	f2 48 0f 2a c2       	cvtsi2sd %rdx,%xmm0
  94:	f2 0f 58 c0          	addsd  %xmm0,%xmm0
  98:	f2 0f 59 45 b8       	mulsd  -0x48(%rbp),%xmm0
  9d:	f2 0f 10 4d b0       	movsd  -0x50(%rbp),%xmm1
  a2:	f2 0f 58 c1          	addsd  %xmm1,%xmm0
  a6:	f2 0f 11 45 b0       	movsd  %xmm0,-0x50(%rbp)
	  __tmp *= __r;
  ab:	dd 45 b8             	fldl   -0x48(%rbp)
  ae:	db 2d 00 00 00 00    	fldt   0x0(%rip)        # b4 <_ZSt18generate_canonicalIdLm53ESt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEET_RT1_+0xb4>
  b4:	de c9                	fmulp  %st,%st(1)
  b6:	dd 5d b8             	fstpl  -0x48(%rbp)
      for (size_t __k = __m; __k != 0; --__k)
  b9:	48 83 6d c0 01       	subq   $0x1,-0x40(%rbp)
  be:	48 83 7d c0 00       	cmpq   $0x0,-0x40(%rbp)
  c3:	75 8d                	jne    52 <_ZSt18generate_canonicalIdLm53ESt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEET_RT1_+0x52>
	}
      __ret = __sum / __tmp;
  c5:	f2 0f 10 45 b0       	movsd  -0x50(%rbp),%xmm0
  ca:	f2 0f 5e 45 b8       	divsd  -0x48(%rbp),%xmm0
  cf:	f2 0f 11 45 a8       	movsd  %xmm0,-0x58(%rbp)
      if (__builtin_expect(__ret >= _RealType(1), 0))
  d4:	f2 0f 10 45 a8       	movsd  -0x58(%rbp),%xmm0
  d9:	f2 0f 10 0d 00 00 00 	movsd  0x0(%rip),%xmm1        # e1 <_ZSt18generate_canonicalIdLm53ESt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEET_RT1_+0xe1>
  e0:	00 
  e1:	66 0f 2f c1          	comisd %xmm1,%xmm0
  e5:	0f 93 c0             	setae  %al
  e8:	0f b6 c0             	movzbl %al,%eax
  eb:	48 85 c0             	test   %rax,%rax
  ee:	74 0d                	je     fd <_ZSt18generate_canonicalIdLm53ESt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEET_RT1_+0xfd>
	{
#if _GLIBCXX_USE_C99_MATH_TR1
	  __ret = std::nextafter(_RealType(1), _RealType(0));
  f0:	f2 0f 10 05 00 00 00 	movsd  0x0(%rip),%xmm0        # f8 <_ZSt18generate_canonicalIdLm53ESt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEET_RT1_+0xf8>
  f7:	00 
  f8:	f2 0f 11 45 a8       	movsd  %xmm0,-0x58(%rbp)
#else
	  __ret = _RealType(1)
	    - std::numeric_limits<_RealType>::epsilon() / _RealType(2);
#endif
	}
      return __ret;
  fd:	f2 0f 10 45 a8       	movsd  -0x58(%rbp),%xmm0
 102:	66 48 0f 7e c0       	movq   %xmm0,%rax
    }
 107:	66 48 0f 6e c0       	movq   %rax,%xmm0
 10c:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
 110:	c9                   	leave  
 111:	c3                   	ret    

Disassembly of section .text._ZNKSt6vectorIPN8MemTable8QuadlistESaIS2_EE8max_sizeEv:

0000000000000000 <_ZNKSt6vectorIPN8MemTable8QuadlistESaIS2_EE8max_sizeEv>:
      max_size() const _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
      { return _S_max_size(_M_get_Tp_allocator()); }
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZNKSt6vectorIPN8MemTable8QuadlistESaIS2_EE8max_sizeEv+0x1c>
  1c:	48 89 c7             	mov    %rax,%rdi
  1f:	e8 00 00 00 00       	call   24 <_ZNKSt6vectorIPN8MemTable8QuadlistESaIS2_EE8max_sizeEv+0x24>
  24:	c9                   	leave  
  25:	c3                   	ret    

Disassembly of section .text._ZNSt16allocator_traitsISaIPN8MemTable8QuadlistEEE8allocateERS3_m:

0000000000000000 <_ZNSt16allocator_traitsISaIPN8MemTable8QuadlistEEE8allocateERS3_m>:
      allocate(allocator_type& __a, size_type __n)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  10:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  14:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  18:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
  1c:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  20:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
	if (std::is_constant_evaluated())
  24:	e8 00 00 00 00       	call   29 <_ZNSt16allocator_traitsISaIPN8MemTable8QuadlistEEE8allocateERS3_m+0x29>
  29:	84 c0                	test   %al,%al
  2b:	74 12                	je     3f <_ZNSt16allocator_traitsISaIPN8MemTable8QuadlistEEE8allocateERS3_m+0x3f>
	  return static_cast<_Tp*>(::operator new(__n * sizeof(_Tp)));
  2d:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  31:	48 c1 e0 03          	shl    $0x3,%rax
  35:	48 89 c7             	mov    %rax,%rdi
  38:	e8 00 00 00 00       	call   3d <_ZNSt16allocator_traitsISaIPN8MemTable8QuadlistEEE8allocateERS3_m+0x3d>
  3d:	eb 19                	jmp    58 <_ZNSt16allocator_traitsISaIPN8MemTable8QuadlistEEE8allocateERS3_m+0x58>
	return __allocator_base<_Tp>::allocate(__n, 0);
  3f:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
  43:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  47:	ba 00 00 00 00       	mov    $0x0,%edx
  4c:	48 89 ce             	mov    %rcx,%rsi
  4f:	48 89 c7             	mov    %rax,%rdi
  52:	e8 00 00 00 00       	call   57 <_ZNSt16allocator_traitsISaIPN8MemTable8QuadlistEEE8allocateERS3_m+0x57>
  57:	90                   	nop
      { return __a.allocate(__n); }
  58:	c9                   	leave  
  59:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE14_S_do_relocateEPS2_S5_S5_RS3_St17integral_constantIbLb1EE:

0000000000000000 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE14_S_do_relocateEPS2_S5_S5_RS3_St17integral_constantIbLb1EE>:
      _S_do_relocate(pointer __first, pointer __last, pointer __result,
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
  18:	48 89 4d e0          	mov    %rcx,-0x20(%rbp)
	return std::__relocate_a(__first, __last, __result, __alloc);
  1c:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
  20:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  24:	48 8b 75 f0          	mov    -0x10(%rbp),%rsi
  28:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  2c:	48 89 c7             	mov    %rax,%rdi
  2f:	e8 00 00 00 00       	call   34 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE14_S_do_relocateEPS2_S5_S5_RS3_St17integral_constantIbLb1EE+0x34>
      }
  34:	c9                   	leave  
  35:	c3                   	ret    

Disassembly of section .text._ZSt10destroy_atIPN8MemTable8QuadlistEEvPT_:

0000000000000000 <_ZSt10destroy_atIPN8MemTable8QuadlistEEvPT_>:
    destroy_at(_Tp* __location)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    }
   c:	90                   	nop
   d:	5d                   	pop    %rbp
   e:	c3                   	ret    

Disassembly of section .text._ZNSt12_Destroy_auxILb0EE9__destroyIPN7KVStore7ssLevelEEEvT_S5_:

0000000000000000 <_ZNSt12_Destroy_auxILb0EE9__destroyIPN7KVStore7ssLevelEEEvT_S5_>:
	__destroy(_ForwardIterator __first, _ForwardIterator __last)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
	  for (; __first != __last; ++__first)
  14:	eb 19                	jmp    2f <_ZNSt12_Destroy_auxILb0EE9__destroyIPN7KVStore7ssLevelEEEvT_S5_+0x2f>
	    std::_Destroy(std::__addressof(*__first));
  16:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  1a:	48 89 c7             	mov    %rax,%rdi
  1d:	e8 00 00 00 00       	call   22 <_ZNSt12_Destroy_auxILb0EE9__destroyIPN7KVStore7ssLevelEEEvT_S5_+0x22>
  22:	48 89 c7             	mov    %rax,%rdi
  25:	e8 00 00 00 00       	call   2a <_ZNSt12_Destroy_auxILb0EE9__destroyIPN7KVStore7ssLevelEEEvT_S5_+0x2a>
	  for (; __first != __last; ++__first)
  2a:	48 83 45 f8 08       	addq   $0x8,-0x8(%rbp)
  2f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  33:	48 3b 45 f0          	cmp    -0x10(%rbp),%rax
  37:	75 dd                	jne    16 <_ZNSt12_Destroy_auxILb0EE9__destroyIPN7KVStore7ssLevelEEEvT_S5_+0x16>
	}
  39:	90                   	nop
  3a:	90                   	nop
  3b:	c9                   	leave  
  3c:	c3                   	ret    

Disassembly of section .text._ZNSt12_Destroy_auxILb1EE9__destroyIPN7KVStore7ssLevelEEEvT_S5_:

0000000000000000 <_ZNSt12_Destroy_auxILb1EE9__destroyIPN7KVStore7ssLevelEEEvT_S5_>:
        __destroy(_ForwardIterator, _ForwardIterator) { }
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  10:	90                   	nop
  11:	5d                   	pop    %rbp
  12:	c3                   	ret    

Disassembly of section .text._ZNSt12_Destroy_auxILb0EE9__destroyIPPN8MemTable8QuadlistEEEvT_S6_:

0000000000000000 <_ZNSt12_Destroy_auxILb0EE9__destroyIPPN8MemTable8QuadlistEEEvT_S6_>:
	__destroy(_ForwardIterator __first, _ForwardIterator __last)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
	  for (; __first != __last; ++__first)
  14:	eb 19                	jmp    2f <_ZNSt12_Destroy_auxILb0EE9__destroyIPPN8MemTable8QuadlistEEEvT_S6_+0x2f>
	    std::_Destroy(std::__addressof(*__first));
  16:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  1a:	48 89 c7             	mov    %rax,%rdi
  1d:	e8 00 00 00 00       	call   22 <_ZNSt12_Destroy_auxILb0EE9__destroyIPPN8MemTable8QuadlistEEEvT_S6_+0x22>
  22:	48 89 c7             	mov    %rax,%rdi
  25:	e8 00 00 00 00       	call   2a <_ZNSt12_Destroy_auxILb0EE9__destroyIPPN8MemTable8QuadlistEEEvT_S6_+0x2a>
	  for (; __first != __last; ++__first)
  2a:	48 83 45 f8 08       	addq   $0x8,-0x8(%rbp)
  2f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  33:	48 3b 45 f0          	cmp    -0x10(%rbp),%rax
  37:	75 dd                	jne    16 <_ZNSt12_Destroy_auxILb0EE9__destroyIPPN8MemTable8QuadlistEEEvT_S6_+0x16>
	}
  39:	90                   	nop
  3a:	90                   	nop
  3b:	c9                   	leave  
  3c:	c3                   	ret    

Disassembly of section .text._ZNSt12_Destroy_auxILb1EE9__destroyIPPN8MemTable8QuadlistEEEvT_S6_:

0000000000000000 <_ZNSt12_Destroy_auxILb1EE9__destroyIPPN8MemTable8QuadlistEEEvT_S6_>:
        __destroy(_ForwardIterator, _ForwardIterator) { }
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  10:	90                   	nop
  11:	5d                   	pop    %rbp
  12:	c3                   	ret    

Disassembly of section .text._ZNSt16allocator_traitsISaIcEE8max_sizeERKS0_:

0000000000000000 <_ZNSt16allocator_traitsISaIcEE8max_sizeERKS0_>:
      max_size(const allocator_type& __a __attribute__((__unused__))) noexcept
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
	return size_t(-1) / sizeof(value_type);
   c:	48 c7 c0 ff ff ff ff 	mov    $0xffffffffffffffff,%rax
      }
  13:	5d                   	pop    %rbp
  14:	c3                   	ret    

Disassembly of section .text._ZNKSt6vectorIN7KVStore7ssLevelESaIS1_EE8max_sizeEv:

0000000000000000 <_ZNKSt6vectorIN7KVStore7ssLevelESaIS1_EE8max_sizeEv>:
      max_size() const _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
      { return _S_max_size(_M_get_Tp_allocator()); }
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZNKSt6vectorIN7KVStore7ssLevelESaIS1_EE8max_sizeEv+0x1c>
  1c:	48 89 c7             	mov    %rax,%rdi
  1f:	e8 00 00 00 00       	call   24 <_ZNKSt6vectorIN7KVStore7ssLevelESaIS1_EE8max_sizeEv+0x24>
  24:	c9                   	leave  
  25:	c3                   	ret    

Disassembly of section .text._ZNSt16allocator_traitsISaIN7KVStore7ssLevelEEE8allocateERS2_m:

0000000000000000 <_ZNSt16allocator_traitsISaIN7KVStore7ssLevelEEE8allocateERS2_m>:
      allocate(allocator_type& __a, size_type __n)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  10:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  14:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  18:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
  1c:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  20:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
	if (std::is_constant_evaluated())
  24:	e8 00 00 00 00       	call   29 <_ZNSt16allocator_traitsISaIN7KVStore7ssLevelEEE8allocateERS2_m+0x29>
  29:	84 c0                	test   %al,%al
  2b:	74 12                	je     3f <_ZNSt16allocator_traitsISaIN7KVStore7ssLevelEEE8allocateERS2_m+0x3f>
	  return static_cast<_Tp*>(::operator new(__n * sizeof(_Tp)));
  2d:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  31:	48 c1 e0 03          	shl    $0x3,%rax
  35:	48 89 c7             	mov    %rax,%rdi
  38:	e8 00 00 00 00       	call   3d <_ZNSt16allocator_traitsISaIN7KVStore7ssLevelEEE8allocateERS2_m+0x3d>
  3d:	eb 19                	jmp    58 <_ZNSt16allocator_traitsISaIN7KVStore7ssLevelEEE8allocateERS2_m+0x58>
	return __allocator_base<_Tp>::allocate(__n, 0);
  3f:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
  43:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  47:	ba 00 00 00 00       	mov    $0x0,%edx
  4c:	48 89 ce             	mov    %rcx,%rsi
  4f:	48 89 c7             	mov    %rax,%rdi
  52:	e8 00 00 00 00       	call   57 <_ZNSt16allocator_traitsISaIN7KVStore7ssLevelEEE8allocateERS2_m+0x57>
  57:	90                   	nop
      { return __a.allocate(__n); }
  58:	c9                   	leave  
  59:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE14_S_do_relocateEPS1_S4_S4_RS2_St17integral_constantIbLb1EE:

0000000000000000 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE14_S_do_relocateEPS1_S4_S4_RS2_St17integral_constantIbLb1EE>:
      _S_do_relocate(pointer __first, pointer __last, pointer __result,
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
  18:	48 89 4d e0          	mov    %rcx,-0x20(%rbp)
	return std::__relocate_a(__first, __last, __result, __alloc);
  1c:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
  20:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  24:	48 8b 75 f0          	mov    -0x10(%rbp),%rsi
  28:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  2c:	48 89 c7             	mov    %rax,%rdi
  2f:	e8 00 00 00 00       	call   34 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE14_S_do_relocateEPS1_S4_S4_RS2_St17integral_constantIbLb1EE+0x34>
      }
  34:	c9                   	leave  
  35:	c3                   	ret    

Disassembly of section .text._ZSt10destroy_atIN7KVStore7ssLevelEEvPT_:

0000000000000000 <_ZSt10destroy_atIN7KVStore7ssLevelEEvPT_>:
    destroy_at(_Tp* __location)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    }
   c:	90                   	nop
   d:	5d                   	pop    %rbp
   e:	c3                   	ret    

Disassembly of section .text._ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPKcPcEET0_T_S7_S6_:

0000000000000000 <_ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPKcPcEET0_T_S7_S6_>:
	__copy_m(_II __first, _II __last, _OI __result)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
   c:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  10:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
	  for(_Distance __n = __last - __first; __n > 0; --__n)
  14:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  18:	48 2b 45 e8          	sub    -0x18(%rbp),%rax
  1c:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  20:	eb 1c                	jmp    3e <_ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPKcPcEET0_T_S7_S6_+0x3e>
	      *__result = *__first;
  22:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  26:	0f b6 10             	movzbl (%rax),%edx
  29:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  2d:	88 10                	mov    %dl,(%rax)
	      ++__first;
  2f:	48 83 45 e8 01       	addq   $0x1,-0x18(%rbp)
	      ++__result;
  34:	48 83 45 d8 01       	addq   $0x1,-0x28(%rbp)
	  for(_Distance __n = __last - __first; __n > 0; --__n)
  39:	48 83 6d f8 01       	subq   $0x1,-0x8(%rbp)
  3e:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
  43:	7f dd                	jg     22 <_ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPKcPcEET0_T_S7_S6_+0x22>
	  return __result;
  45:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
	}
  49:	5d                   	pop    %rbp
  4a:	c3                   	ret    

Disassembly of section .text._ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIcEEPT_PKS3_S6_S4_:

0000000000000000 <_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIcEEPT_PKS3_S6_S4_>:
	__copy_m(const _Tp* __first, const _Tp* __last, _Tp* __result)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 30          	sub    $0x30,%rsp
   c:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  10:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  14:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
	  const ptrdiff_t _Num = __last - __first;
  18:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  1c:	48 2b 45 e8          	sub    -0x18(%rbp),%rax
  20:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
	  if (_Num)
  24:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
  29:	74 17                	je     42 <_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIcEEPT_PKS3_S6_S4_+0x42>
	    __builtin_memmove(__result, __first, sizeof(_Tp) * _Num);
  2b:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  2f:	48 8b 4d e8          	mov    -0x18(%rbp),%rcx
  33:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  37:	48 89 ce             	mov    %rcx,%rsi
  3a:	48 89 c7             	mov    %rax,%rdi
  3d:	e8 00 00 00 00       	call   42 <_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIcEEPT_PKS3_S6_S4_+0x42>
	  return __result + _Num;
  42:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  46:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  4a:	48 01 d0             	add    %rdx,%rax
	}
  4d:	c9                   	leave  
  4e:	c3                   	ret    

Disassembly of section .text._ZSt11__addressofIcEPT_RS0_:

0000000000000000 <_ZSt11__addressofIcEPT_RS0_>:
    __addressof(_Tp& __r) _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    { return __builtin_addressof(__r); }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	5d                   	pop    %rbp
  11:	c3                   	ret    

Disassembly of section .text._ZSt9addressofIKcEPT_RS1_:

0000000000000000 <_ZSt9addressofIKcEPT_RS1_>:
    addressof(_Tp& __r) noexcept
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    { return std::__addressof(__r); }
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZSt9addressofIKcEPT_RS1_+0x1c>
  1c:	c9                   	leave  
  1d:	c3                   	ret    

Disassembly of section .text._ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_disjunctEPKc:

0000000000000000 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_disjunctEPKc>:
      _M_disjunct(const _CharT* __s) const _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	53                   	push   %rbx
   9:	48 83 ec 28          	sub    $0x28,%rsp
   d:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  11:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
  15:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  1c:	00 00 
  1e:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  22:	31 c0                	xor    %eax,%eax
	return (less<const _CharT*>()(__s, _M_data())
  24:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  28:	48 89 c7             	mov    %rax,%rdi
  2b:	e8 00 00 00 00       	call   30 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_disjunctEPKc+0x30>
  30:	48 89 c2             	mov    %rax,%rdx
  33:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
  37:	48 8d 45 e6          	lea    -0x1a(%rbp),%rax
  3b:	48 89 ce             	mov    %rcx,%rsi
  3e:	48 89 c7             	mov    %rax,%rdi
  41:	e8 00 00 00 00       	call   46 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_disjunctEPKc+0x46>
		|| less<const _CharT*>()(_M_data() + this->size(), __s));
  46:	84 c0                	test   %al,%al
  48:	75 36                	jne    80 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_disjunctEPKc+0x80>
  4a:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  4e:	48 89 c7             	mov    %rax,%rdi
  51:	e8 00 00 00 00       	call   56 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_disjunctEPKc+0x56>
  56:	48 89 c3             	mov    %rax,%rbx
  59:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  5d:	48 89 c7             	mov    %rax,%rdi
  60:	e8 00 00 00 00       	call   65 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_disjunctEPKc+0x65>
  65:	48 8d 0c 03          	lea    (%rbx,%rax,1),%rcx
  69:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
  6d:	48 8d 45 e7          	lea    -0x19(%rbp),%rax
  71:	48 89 ce             	mov    %rcx,%rsi
  74:	48 89 c7             	mov    %rax,%rdi
  77:	e8 00 00 00 00       	call   7c <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_disjunctEPKc+0x7c>
  7c:	84 c0                	test   %al,%al
  7e:	74 07                	je     87 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_disjunctEPKc+0x87>
  80:	b8 01 00 00 00       	mov    $0x1,%eax
  85:	eb 05                	jmp    8c <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_disjunctEPKc+0x8c>
  87:	b8 00 00 00 00       	mov    $0x0,%eax
      }
  8c:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  90:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
  97:	00 00 
  99:	74 05                	je     a0 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_disjunctEPKc+0xa0>
  9b:	e8 00 00 00 00       	call   a0 <_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_disjunctEPKc+0xa0>
  a0:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  a4:	c9                   	leave  
  a5:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_S_moveEPcPKcm:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_S_moveEPcPKcm>:
      _S_move(_CharT* __d, const _CharT* __s, size_type __n)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
	if (__n == 1)
  18:	48 83 7d e8 01       	cmpq   $0x1,-0x18(%rbp)
  1d:	75 15                	jne    34 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_S_moveEPcPKcm+0x34>
	  traits_type::assign(*__d, *__s);
  1f:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  23:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  27:	48 89 d6             	mov    %rdx,%rsi
  2a:	48 89 c7             	mov    %rax,%rdi
  2d:	e8 00 00 00 00       	call   32 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_S_moveEPcPKcm+0x32>
      }
  32:	eb 17                	jmp    4b <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_S_moveEPcPKcm+0x4b>
	  traits_type::move(__d, __s, __n);
  34:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  38:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
  3c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  40:	48 89 ce             	mov    %rcx,%rsi
  43:	48 89 c7             	mov    %rax,%rdi
  46:	e8 00 00 00 00       	call   4b <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_S_moveEPcPKcm+0x4b>
      }
  4b:	90                   	nop
  4c:	c9                   	leave  
  4d:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx17__is_null_pointerIcEEbPT_:

0000000000000000 <_ZN9__gnu_cxx17__is_null_pointerIcEEbPT_>:
    __is_null_pointer(_Type* __ptr)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    { return __ptr == 0; }
   c:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
  11:	0f 94 c0             	sete   %al
  14:	5d                   	pop    %rbp
  15:	c3                   	ret    

Disassembly of section .text._ZSt10__distanceIPcENSt15iterator_traitsIT_E15difference_typeES2_S2_St26random_access_iterator_tag:

0000000000000000 <_ZSt10__distanceIPcENSt15iterator_traitsIT_E15difference_typeES2_S2_St26random_access_iterator_tag>:
    __distance(_RandomAccessIterator __first, _RandomAccessIterator __last,
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
      return __last - __first;
  10:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  14:	48 2b 45 f8          	sub    -0x8(%rbp),%rax
    }
  18:	5d                   	pop    %rbp
  19:	c3                   	ret    

Disassembly of section .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsEPcS5_S5_:

0000000000000000 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsEPcS5_S5_>:
      _S_copy_chars(_CharT* __p, _CharT* __k1, _CharT* __k2) _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
      { _S_copy(__p, __k1, __k2 - __k1); }
  18:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  1c:	48 2b 45 f0          	sub    -0x10(%rbp),%rax
  20:	48 89 c2             	mov    %rax,%rdx
  23:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
  27:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  2b:	48 89 ce             	mov    %rcx,%rsi
  2e:	48 89 c7             	mov    %rax,%rdi
  31:	e8 00 00 00 00       	call   36 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsEPcS5_S5_+0x36>
  36:	90                   	nop
  37:	c9                   	leave  
  38:	c3                   	ret    

Disassembly of section .text._ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEclEv:

0000000000000000 <_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEclEv>:
    mersenne_twister_engine<_UIntType, __w, __n, __m, __r, __a, __u, __d,
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
      if (_M_p >= state_size)
  10:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  14:	48 8b 80 80 13 00 00 	mov    0x1380(%rax),%rax
  1b:	48 3d 6f 02 00 00    	cmp    $0x26f,%rax
  21:	76 0c                	jbe    2f <_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEclEv+0x2f>
	_M_gen_rand();
  23:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  27:	48 89 c7             	mov    %rax,%rdi
  2a:	e8 00 00 00 00       	call   2f <_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEclEv+0x2f>
      result_type __z = _M_x[_M_p++];
  2f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  33:	48 8b 80 80 13 00 00 	mov    0x1380(%rax),%rax
  3a:	48 8d 48 01          	lea    0x1(%rax),%rcx
  3e:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  42:	48 89 8a 80 13 00 00 	mov    %rcx,0x1380(%rdx)
  49:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  4d:	48 8b 04 c2          	mov    (%rdx,%rax,8),%rax
  51:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
      __z ^= (__z >> __u) & __d;
  55:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  59:	48 c1 e8 0b          	shr    $0xb,%rax
  5d:	89 c0                	mov    %eax,%eax
  5f:	48 31 45 f8          	xor    %rax,-0x8(%rbp)
      __z ^= (__z << __s) & __b;
  63:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  67:	48 c1 e0 07          	shl    $0x7,%rax
  6b:	25 80 56 2c 9d       	and    $0x9d2c5680,%eax
  70:	48 31 45 f8          	xor    %rax,-0x8(%rbp)
      __z ^= (__z << __t) & __c;
  74:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  78:	48 c1 e0 0f          	shl    $0xf,%rax
  7c:	25 00 00 c6 ef       	and    $0xefc60000,%eax
  81:	48 31 45 f8          	xor    %rax,-0x8(%rbp)
      __z ^= (__z >> __l);
  85:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  89:	48 c1 e8 12          	shr    $0x12,%rax
  8d:	48 31 45 f8          	xor    %rax,-0x8(%rbp)
      return __z;
  91:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    }
  95:	c9                   	leave  
  96:	c3                   	ret    

Disassembly of section .text._ZNSt16allocator_traitsISaIPN8MemTable8QuadlistEEE8max_sizeERKS3_:

0000000000000000 <_ZNSt16allocator_traitsISaIPN8MemTable8QuadlistEEE8max_sizeERKS3_>:
      max_size(const allocator_type& __a __attribute__((__unused__))) noexcept
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
	return size_t(-1) / sizeof(value_type);
   c:	48 b8 ff ff ff ff ff 	movabs $0x1fffffffffffffff,%rax
  13:	ff ff 1f 
      }
  16:	5d                   	pop    %rbp
  17:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE11_S_max_sizeERKS3_:

0000000000000000 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE11_S_max_sizeERKS3_>:
	      __N("cannot create std::vector larger than max_size()"));
	return __n;
      }

      static size_type
      _S_max_size(const _Tp_alloc_type& __a) _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 30          	sub    $0x30,%rsp
   c:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  10:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  17:	00 00 
  19:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  1d:	31 c0                	xor    %eax,%eax
      {
	// std::distance(begin(), end()) cannot be greater than PTRDIFF_MAX,
	// and realistically we can't store more than PTRDIFF_MAX/sizeof(T)
	// (even if std::allocator_traits::max_size says we can).
	const size_t __diffmax
  1f:	48 b8 ff ff ff ff ff 	movabs $0xfffffffffffffff,%rax
  26:	ff ff 0f 
  29:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
	  = __gnu_cxx::__numeric_traits<ptrdiff_t>::__max / sizeof(_Tp);
	const size_t __allocmax = _Alloc_traits::max_size(__a);
  2d:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  31:	48 89 c7             	mov    %rax,%rdi
  34:	e8 00 00 00 00       	call   39 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE11_S_max_sizeERKS3_+0x39>
  39:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
	return (std::min)(__diffmax, __allocmax);
  3d:	48 8d 55 f0          	lea    -0x10(%rbp),%rdx
  41:	48 8d 45 e8          	lea    -0x18(%rbp),%rax
  45:	48 89 d6             	mov    %rdx,%rsi
  48:	48 89 c7             	mov    %rax,%rdi
  4b:	e8 00 00 00 00       	call   50 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE11_S_max_sizeERKS3_+0x50>
  50:	48 8b 00             	mov    (%rax),%rax
      }
  53:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  57:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
  5e:	00 00 
  60:	74 05                	je     67 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE11_S_max_sizeERKS3_+0x67>
  62:	e8 00 00 00 00       	call   67 <_ZNSt6vectorIPN8MemTable8QuadlistESaIS2_EE11_S_max_sizeERKS3_+0x67>
  67:	c9                   	leave  
  68:	c3                   	ret    

Disassembly of section .text._ZNKSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EE19_M_get_Tp_allocatorEv:

0000000000000000 <_ZNKSt12_Vector_baseIPN8MemTable8QuadlistESaIS2_EE19_M_get_Tp_allocatorEv>:
      _M_get_Tp_allocator() const _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
      { return this->_M_impl; }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	5d                   	pop    %rbp
  11:	c3                   	ret    

Disassembly of section .text._ZSt12__relocate_aIPPN8MemTable8QuadlistES3_SaIS2_EET0_T_S6_S5_RT1_:

0000000000000000 <_ZSt12__relocate_aIPPN8MemTable8QuadlistES3_SaIS2_EET0_T_S6_S5_RT1_>:
    }

  template <typename _InputIterator, typename _ForwardIterator,
	    typename _Allocator>
    inline _ForwardIterator
    __relocate_a(_InputIterator __first, _InputIterator __last,
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	41 54                	push   %r12
   a:	53                   	push   %rbx
   b:	48 83 ec 20          	sub    $0x20,%rsp
   f:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  13:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  17:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
  1b:	48 89 4d d0          	mov    %rcx,-0x30(%rbp)
		 _ForwardIterator __result, _Allocator& __alloc)
    noexcept(noexcept(__relocate_a_1(std::__niter_base(__first),
				     std::__niter_base(__last),
				     std::__niter_base(__result), __alloc)))
    {
      return __relocate_a_1(std::__niter_base(__first),
  1f:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  23:	48 89 c7             	mov    %rax,%rdi
  26:	e8 00 00 00 00       	call   2b <_ZSt12__relocate_aIPPN8MemTable8QuadlistES3_SaIS2_EET0_T_S6_S5_RT1_+0x2b>
  2b:	49 89 c4             	mov    %rax,%r12
  2e:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  32:	48 89 c7             	mov    %rax,%rdi
  35:	e8 00 00 00 00       	call   3a <_ZSt12__relocate_aIPPN8MemTable8QuadlistES3_SaIS2_EET0_T_S6_S5_RT1_+0x3a>
  3a:	48 89 c3             	mov    %rax,%rbx
  3d:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  41:	48 89 c7             	mov    %rax,%rdi
  44:	e8 00 00 00 00       	call   49 <_ZSt12__relocate_aIPPN8MemTable8QuadlistES3_SaIS2_EET0_T_S6_S5_RT1_+0x49>
  49:	48 89 c7             	mov    %rax,%rdi
  4c:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  50:	48 89 c1             	mov    %rax,%rcx
  53:	4c 89 e2             	mov    %r12,%rdx
  56:	48 89 de             	mov    %rbx,%rsi
  59:	e8 00 00 00 00       	call   5e <_ZSt12__relocate_aIPPN8MemTable8QuadlistES3_SaIS2_EET0_T_S6_S5_RT1_+0x5e>
			    std::__niter_base(__last),
			    std::__niter_base(__result), __alloc);
    }
  5e:	48 83 c4 20          	add    $0x20,%rsp
  62:	5b                   	pop    %rbx
  63:	41 5c                	pop    %r12
  65:	5d                   	pop    %rbp
  66:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx13new_allocatorIN7KVStore7ssLevelEE10deallocateEPS2_m:

0000000000000000 <_ZN9__gnu_cxx13new_allocatorIN7KVStore7ssLevelEE10deallocateEPS2_m>:
      deallocate(_Tp* __p, size_type __t __attribute__ ((__unused__)))
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
	::operator delete(__p
  18:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  1c:	48 8d 14 c5 00 00 00 	lea    0x0(,%rax,8),%rdx
  23:	00 
  24:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  28:	48 89 d6             	mov    %rdx,%rsi
  2b:	48 89 c7             	mov    %rax,%rdi
  2e:	e8 00 00 00 00       	call   33 <_ZN9__gnu_cxx13new_allocatorIN7KVStore7ssLevelEE10deallocateEPS2_m+0x33>
      }
  33:	c9                   	leave  
  34:	c3                   	ret    

Disassembly of section .text._ZSt11__addressofIN7KVStore7ssLevelEEPT_RS2_:

0000000000000000 <_ZSt11__addressofIN7KVStore7ssLevelEEPT_RS2_>:
    __addressof(_Tp& __r) _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    { return __builtin_addressof(__r); }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	5d                   	pop    %rbp
  11:	c3                   	ret    

Disassembly of section .text._ZSt8_DestroyIN7KVStore7ssLevelEEvPT_:

0000000000000000 <_ZSt8_DestroyIN7KVStore7ssLevelEEvPT_>:
    _Destroy(_Tp* __pointer)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
      std::destroy_at(__pointer);
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZSt8_DestroyIN7KVStore7ssLevelEEvPT_+0x1c>
    }
  1c:	90                   	nop
  1d:	c9                   	leave  
  1e:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx13new_allocatorIPN8MemTable8QuadlistEE10deallocateEPS3_m:

0000000000000000 <_ZN9__gnu_cxx13new_allocatorIPN8MemTable8QuadlistEE10deallocateEPS3_m>:
      deallocate(_Tp* __p, size_type __t __attribute__ ((__unused__)))
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
	::operator delete(__p
  18:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  1c:	48 8d 14 c5 00 00 00 	lea    0x0(,%rax,8),%rdx
  23:	00 
  24:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  28:	48 89 d6             	mov    %rdx,%rsi
  2b:	48 89 c7             	mov    %rax,%rdi
  2e:	e8 00 00 00 00       	call   33 <_ZN9__gnu_cxx13new_allocatorIPN8MemTable8QuadlistEE10deallocateEPS3_m+0x33>
      }
  33:	c9                   	leave  
  34:	c3                   	ret    

Disassembly of section .text._ZSt11__addressofIPN8MemTable8QuadlistEEPT_RS3_:

0000000000000000 <_ZSt11__addressofIPN8MemTable8QuadlistEEPT_RS3_>:
    __addressof(_Tp& __r) _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    { return __builtin_addressof(__r); }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	5d                   	pop    %rbp
  11:	c3                   	ret    

Disassembly of section .text._ZSt8_DestroyIPN8MemTable8QuadlistEEvPT_:

0000000000000000 <_ZSt8_DestroyIPN8MemTable8QuadlistEEvPT_>:
    _Destroy(_Tp* __pointer)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
      std::destroy_at(__pointer);
  10:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  14:	48 89 c7             	mov    %rax,%rdi
  17:	e8 00 00 00 00       	call   1c <_ZSt8_DestroyIPN8MemTable8QuadlistEEvPT_+0x1c>
    }
  1c:	90                   	nop
  1d:	c9                   	leave  
  1e:	c3                   	ret    

Disassembly of section .text._ZNSt16allocator_traitsISaIN7KVStore7ssLevelEEE8max_sizeERKS2_:

0000000000000000 <_ZNSt16allocator_traitsISaIN7KVStore7ssLevelEEE8max_sizeERKS2_>:
      max_size(const allocator_type& __a __attribute__((__unused__))) noexcept
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
	return size_t(-1) / sizeof(value_type);
   c:	48 b8 ff ff ff ff ff 	movabs $0x1fffffffffffffff,%rax
  13:	ff ff 1f 
      }
  16:	5d                   	pop    %rbp
  17:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE11_S_max_sizeERKS2_:

0000000000000000 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE11_S_max_sizeERKS2_>:
      _S_max_size(const _Tp_alloc_type& __a) _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 30          	sub    $0x30,%rsp
   c:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  10:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  17:	00 00 
  19:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  1d:	31 c0                	xor    %eax,%eax
	const size_t __diffmax
  1f:	48 b8 ff ff ff ff ff 	movabs $0xfffffffffffffff,%rax
  26:	ff ff 0f 
  29:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
	const size_t __allocmax = _Alloc_traits::max_size(__a);
  2d:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  31:	48 89 c7             	mov    %rax,%rdi
  34:	e8 00 00 00 00       	call   39 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE11_S_max_sizeERKS2_+0x39>
  39:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
	return (std::min)(__diffmax, __allocmax);
  3d:	48 8d 55 f0          	lea    -0x10(%rbp),%rdx
  41:	48 8d 45 e8          	lea    -0x18(%rbp),%rax
  45:	48 89 d6             	mov    %rdx,%rsi
  48:	48 89 c7             	mov    %rax,%rdi
  4b:	e8 00 00 00 00       	call   50 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE11_S_max_sizeERKS2_+0x50>
  50:	48 8b 00             	mov    (%rax),%rax
      }
  53:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  57:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
  5e:	00 00 
  60:	74 05                	je     67 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE11_S_max_sizeERKS2_+0x67>
  62:	e8 00 00 00 00       	call   67 <_ZNSt6vectorIN7KVStore7ssLevelESaIS1_EE11_S_max_sizeERKS2_+0x67>
  67:	c9                   	leave  
  68:	c3                   	ret    

Disassembly of section .text._ZNKSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EE19_M_get_Tp_allocatorEv:

0000000000000000 <_ZNKSt12_Vector_baseIN7KVStore7ssLevelESaIS1_EE19_M_get_Tp_allocatorEv>:
      _M_get_Tp_allocator() const _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
      { return this->_M_impl; }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	5d                   	pop    %rbp
  11:	c3                   	ret    

Disassembly of section .text._ZSt12__relocate_aIPN7KVStore7ssLevelES2_SaIS1_EET0_T_S5_S4_RT1_:

0000000000000000 <_ZSt12__relocate_aIPN7KVStore7ssLevelES2_SaIS1_EET0_T_S5_S4_RT1_>:
    __relocate_a(_InputIterator __first, _InputIterator __last,
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	41 54                	push   %r12
   a:	53                   	push   %rbx
   b:	48 83 ec 20          	sub    $0x20,%rsp
   f:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  13:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  17:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
  1b:	48 89 4d d0          	mov    %rcx,-0x30(%rbp)
      return __relocate_a_1(std::__niter_base(__first),
  1f:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  23:	48 89 c7             	mov    %rax,%rdi
  26:	e8 00 00 00 00       	call   2b <_ZSt12__relocate_aIPN7KVStore7ssLevelES2_SaIS1_EET0_T_S5_S4_RT1_+0x2b>
  2b:	49 89 c4             	mov    %rax,%r12
  2e:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  32:	48 89 c7             	mov    %rax,%rdi
  35:	e8 00 00 00 00       	call   3a <_ZSt12__relocate_aIPN7KVStore7ssLevelES2_SaIS1_EET0_T_S5_S4_RT1_+0x3a>
  3a:	48 89 c3             	mov    %rax,%rbx
  3d:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  41:	48 89 c7             	mov    %rax,%rdi
  44:	e8 00 00 00 00       	call   49 <_ZSt12__relocate_aIPN7KVStore7ssLevelES2_SaIS1_EET0_T_S5_S4_RT1_+0x49>
  49:	48 89 c7             	mov    %rax,%rdi
  4c:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  50:	48 89 c1             	mov    %rax,%rcx
  53:	4c 89 e2             	mov    %r12,%rdx
  56:	48 89 de             	mov    %rbx,%rsi
  59:	e8 00 00 00 00       	call   5e <_ZSt12__relocate_aIPN7KVStore7ssLevelES2_SaIS1_EET0_T_S5_S4_RT1_+0x5e>
    }
  5e:	48 83 c4 20          	add    $0x20,%rsp
  62:	5b                   	pop    %rbx
  63:	41 5c                	pop    %r12
  65:	5d                   	pop    %rbp
  66:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx13new_allocatorIcE10deallocateEPcm:

0000000000000000 <_ZN9__gnu_cxx13new_allocatorIcE10deallocateEPcm>:
      deallocate(_Tp* __p, size_type __t __attribute__ ((__unused__)))
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
	::operator delete(__p
  18:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  1c:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  20:	48 89 d6             	mov    %rdx,%rsi
  23:	48 89 c7             	mov    %rax,%rdi
  26:	e8 00 00 00 00       	call   2b <_ZN9__gnu_cxx13new_allocatorIcE10deallocateEPcm+0x2b>
      }
  2b:	c9                   	leave  
  2c:	c3                   	ret    

Disassembly of section .text._ZSt11__addressofIKcEPT_RS1_:

0000000000000000 <_ZSt11__addressofIKcEPT_RS1_>:
    __addressof(_Tp& __r) _GLIBCXX_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    { return __builtin_addressof(__r); }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	5d                   	pop    %rbp
  11:	c3                   	ret    

Disassembly of section .text._ZNKSt4lessIPKcEclES1_S1_:

0000000000000000 <_ZNKSt4lessIPKcEclES1_S1_>:
  // Partial specialization of std::less for pointers.
  template<typename _Tp>
    struct less<_Tp*> : public binary_function<_Tp*, _Tp*, bool>
    {
      _GLIBCXX14_CONSTEXPR bool
      operator()(_Tp* __x, _Tp* __y) const _GLIBCXX_NOTHROW
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   c:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  10:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
#else
	if (__builtin_constant_p(__x < __y))
#endif
	  return __x < __y;
#endif
	return (__UINTPTR_TYPE__)__x < (__UINTPTR_TYPE__)__y;
  14:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  18:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  1c:	48 39 c2             	cmp    %rax,%rdx
  1f:	0f 92 c0             	setb   %al
      }
  22:	5d                   	pop    %rbp
  23:	c3                   	ret    

Disassembly of section .text._ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE11_M_gen_randEv:

0000000000000000 <_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE11_M_gen_randEv>:
    mersenne_twister_engine<_UIntType, __w, __n, __m, __r, __a, __u, __d,
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d b8          	mov    %rdi,-0x48(%rbp)
      const _UIntType __upper_mask = (~_UIntType()) << __r;
   c:	48 c7 45 d8 00 00 00 	movq   $0xffffffff80000000,-0x28(%rbp)
  13:	80 
      const _UIntType __lower_mask = ~__upper_mask;
  14:	48 c7 45 e0 ff ff ff 	movq   $0x7fffffff,-0x20(%rbp)
  1b:	7f 
      for (size_t __k = 0; __k < (__n - __m); ++__k)
  1c:	48 c7 45 c8 00 00 00 	movq   $0x0,-0x38(%rbp)
  23:	00 
  24:	eb 7d                	jmp    a3 <_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE11_M_gen_randEv+0xa3>
	  _UIntType __y = ((_M_x[__k] & __upper_mask)
  26:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  2a:	48 8b 55 c8          	mov    -0x38(%rbp),%rdx
  2e:	48 8b 04 d0          	mov    (%rax,%rdx,8),%rax
  32:	48 25 00 00 00 80    	and    $0xffffffff80000000,%rax
  38:	48 89 c1             	mov    %rax,%rcx
			   | (_M_x[__k + 1] & __lower_mask));
  3b:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  3f:	48 8d 50 01          	lea    0x1(%rax),%rdx
  43:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  47:	48 8b 04 d0          	mov    (%rax,%rdx,8),%rax
  4b:	25 ff ff ff 7f       	and    $0x7fffffff,%eax
	  _UIntType __y = ((_M_x[__k] & __upper_mask)
  50:	48 09 c8             	or     %rcx,%rax
  53:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
	  _M_x[__k] = (_M_x[__k + __m] ^ (__y >> 1)
  57:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  5b:	48 8d 90 8d 01 00 00 	lea    0x18d(%rax),%rdx
  62:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  66:	48 8b 14 d0          	mov    (%rax,%rdx,8),%rdx
  6a:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  6e:	48 d1 e8             	shr    %rax
  71:	48 31 c2             	xor    %rax,%rdx
		       ^ ((__y & 0x01) ? __a : 0));
  74:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  78:	83 e0 01             	and    $0x1,%eax
  7b:	48 85 c0             	test   %rax,%rax
  7e:	74 07                	je     87 <_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE11_M_gen_randEv+0x87>
  80:	b8 df b0 08 99       	mov    $0x9908b0df,%eax
  85:	eb 05                	jmp    8c <_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE11_M_gen_randEv+0x8c>
  87:	b8 00 00 00 00       	mov    $0x0,%eax
  8c:	48 31 d0             	xor    %rdx,%rax
  8f:	48 89 c1             	mov    %rax,%rcx
	  _M_x[__k] = (_M_x[__k + __m] ^ (__y >> 1)
  92:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  96:	48 8b 55 c8          	mov    -0x38(%rbp),%rdx
  9a:	48 89 0c d0          	mov    %rcx,(%rax,%rdx,8)
      for (size_t __k = 0; __k < (__n - __m); ++__k)
  9e:	48 83 45 c8 01       	addq   $0x1,-0x38(%rbp)
  a3:	48 81 7d c8 e2 00 00 	cmpq   $0xe2,-0x38(%rbp)
  aa:	00 
  ab:	0f 86 75 ff ff ff    	jbe    26 <_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE11_M_gen_randEv+0x26>
      for (size_t __k = (__n - __m); __k < (__n - 1); ++__k)
  b1:	48 c7 45 d0 e3 00 00 	movq   $0xe3,-0x30(%rbp)
  b8:	00 
  b9:	eb 7d                	jmp    138 <_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE11_M_gen_randEv+0x138>
	  _UIntType __y = ((_M_x[__k] & __upper_mask)
  bb:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  bf:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
  c3:	48 8b 04 d0          	mov    (%rax,%rdx,8),%rax
  c7:	48 25 00 00 00 80    	and    $0xffffffff80000000,%rax
  cd:	48 89 c1             	mov    %rax,%rcx
			   | (_M_x[__k + 1] & __lower_mask));
  d0:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  d4:	48 8d 50 01          	lea    0x1(%rax),%rdx
  d8:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  dc:	48 8b 04 d0          	mov    (%rax,%rdx,8),%rax
  e0:	25 ff ff ff 7f       	and    $0x7fffffff,%eax
	  _UIntType __y = ((_M_x[__k] & __upper_mask)
  e5:	48 09 c8             	or     %rcx,%rax
  e8:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
	  _M_x[__k] = (_M_x[__k + (__m - __n)] ^ (__y >> 1)
  ec:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  f0:	48 8d 90 1d ff ff ff 	lea    -0xe3(%rax),%rdx
  f7:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  fb:	48 8b 14 d0          	mov    (%rax,%rdx,8),%rdx
  ff:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
 103:	48 d1 e8             	shr    %rax
 106:	48 31 c2             	xor    %rax,%rdx
		       ^ ((__y & 0x01) ? __a : 0));
 109:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
 10d:	83 e0 01             	and    $0x1,%eax
 110:	48 85 c0             	test   %rax,%rax
 113:	74 07                	je     11c <_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE11_M_gen_randEv+0x11c>
 115:	b8 df b0 08 99       	mov    $0x9908b0df,%eax
 11a:	eb 05                	jmp    121 <_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE11_M_gen_randEv+0x121>
 11c:	b8 00 00 00 00       	mov    $0x0,%eax
 121:	48 31 d0             	xor    %rdx,%rax
 124:	48 89 c1             	mov    %rax,%rcx
	  _M_x[__k] = (_M_x[__k + (__m - __n)] ^ (__y >> 1)
 127:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
 12b:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
 12f:	48 89 0c d0          	mov    %rcx,(%rax,%rdx,8)
      for (size_t __k = (__n - __m); __k < (__n - 1); ++__k)
 133:	48 83 45 d0 01       	addq   $0x1,-0x30(%rbp)
 138:	48 81 7d d0 6e 02 00 	cmpq   $0x26e,-0x30(%rbp)
 13f:	00 
 140:	0f 86 75 ff ff ff    	jbe    bb <_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE11_M_gen_randEv+0xbb>
      _UIntType __y = ((_M_x[__n - 1] & __upper_mask)
 146:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
 14a:	48 8b 80 78 13 00 00 	mov    0x1378(%rax),%rax
 151:	48 25 00 00 00 80    	and    $0xffffffff80000000,%rax
 157:	48 89 c2             	mov    %rax,%rdx
		       | (_M_x[0] & __lower_mask));
 15a:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
 15e:	48 8b 00             	mov    (%rax),%rax
 161:	25 ff ff ff 7f       	and    $0x7fffffff,%eax
      _UIntType __y = ((_M_x[__n - 1] & __upper_mask)
 166:	48 09 d0             	or     %rdx,%rax
 169:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
      _M_x[__n - 1] = (_M_x[__m - 1] ^ (__y >> 1)
 16d:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
 171:	48 8b 90 60 0c 00 00 	mov    0xc60(%rax),%rdx
 178:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
 17c:	48 d1 e8             	shr    %rax
 17f:	48 31 c2             	xor    %rax,%rdx
		       ^ ((__y & 0x01) ? __a : 0));
 182:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
 186:	83 e0 01             	and    $0x1,%eax
 189:	48 85 c0             	test   %rax,%rax
 18c:	74 07                	je     195 <_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE11_M_gen_randEv+0x195>
 18e:	b8 df b0 08 99       	mov    $0x9908b0df,%eax
 193:	eb 05                	jmp    19a <_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE11_M_gen_randEv+0x19a>
 195:	b8 00 00 00 00       	mov    $0x0,%eax
 19a:	48 31 c2             	xor    %rax,%rdx
      _M_x[__n - 1] = (_M_x[__m - 1] ^ (__y >> 1)
 19d:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
 1a1:	48 89 90 78 13 00 00 	mov    %rdx,0x1378(%rax)
      _M_p = 0;
 1a8:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
 1ac:	48 c7 80 80 13 00 00 	movq   $0x0,0x1380(%rax)
 1b3:	00 00 00 00 
    }
 1b7:	90                   	nop
 1b8:	5d                   	pop    %rbp
 1b9:	c3                   	ret    

Disassembly of section .text._ZNK9__gnu_cxx13new_allocatorIPN8MemTable8QuadlistEE11_M_max_sizeEv:

0000000000000000 <_ZNK9__gnu_cxx13new_allocatorIPN8MemTable8QuadlistEE11_M_max_sizeEv>:
      _M_max_size() const _GLIBCXX_USE_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
	return std::size_t(__PTRDIFF_MAX__) / sizeof(_Tp);
   c:	48 b8 ff ff ff ff ff 	movabs $0xfffffffffffffff,%rax
  13:	ff ff 0f 
      }
  16:	5d                   	pop    %rbp
  17:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx13new_allocatorIPN8MemTable8QuadlistEE8allocateEmPKv:

0000000000000000 <_ZN9__gnu_cxx13new_allocatorIPN8MemTable8QuadlistEE8allocateEmPKv>:
      allocate(size_type __n, const void* = static_cast<const void*>(0))
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
	if (__builtin_expect(__n > this->_M_max_size(), false))
  18:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  1c:	48 89 c7             	mov    %rax,%rdi
  1f:	e8 00 00 00 00       	call   24 <_ZN9__gnu_cxx13new_allocatorIPN8MemTable8QuadlistEE8allocateEmPKv+0x24>
  24:	48 39 45 f0          	cmp    %rax,-0x10(%rbp)
  28:	0f 97 c0             	seta   %al
  2b:	0f b6 c0             	movzbl %al,%eax
  2e:	48 85 c0             	test   %rax,%rax
  31:	0f 95 c0             	setne  %al
  34:	84 c0                	test   %al,%al
  36:	74 1a                	je     52 <_ZN9__gnu_cxx13new_allocatorIPN8MemTable8QuadlistEE8allocateEmPKv+0x52>
	    if (__n > (std::size_t(-1) / sizeof(_Tp)))
  38:	48 b8 ff ff ff ff ff 	movabs $0x1fffffffffffffff,%rax
  3f:	ff ff 1f 
  42:	48 39 45 f0          	cmp    %rax,-0x10(%rbp)
  46:	76 05                	jbe    4d <_ZN9__gnu_cxx13new_allocatorIPN8MemTable8QuadlistEE8allocateEmPKv+0x4d>
	      std::__throw_bad_array_new_length();
  48:	e8 00 00 00 00       	call   4d <_ZN9__gnu_cxx13new_allocatorIPN8MemTable8QuadlistEE8allocateEmPKv+0x4d>
	    std::__throw_bad_alloc();
  4d:	e8 00 00 00 00       	call   52 <_ZN9__gnu_cxx13new_allocatorIPN8MemTable8QuadlistEE8allocateEmPKv+0x52>
	return static_cast<_Tp*>(::operator new(__n * sizeof(_Tp)));
  52:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  56:	48 c1 e0 03          	shl    $0x3,%rax
  5a:	48 89 c7             	mov    %rax,%rdi
  5d:	e8 00 00 00 00       	call   62 <_ZN9__gnu_cxx13new_allocatorIPN8MemTable8QuadlistEE8allocateEmPKv+0x62>
  62:	90                   	nop
      }
  63:	c9                   	leave  
  64:	c3                   	ret    

Disassembly of section .text._ZSt12__niter_baseIPPN8MemTable8QuadlistEET_S4_:

0000000000000000 <_ZSt12__niter_baseIPPN8MemTable8QuadlistEET_S4_>:
    __niter_base(_Iterator __it)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    { return __it; }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	5d                   	pop    %rbp
  11:	c3                   	ret    

Disassembly of section .text._ZSt14__relocate_a_1IPN8MemTable8QuadlistES2_ENSt9enable_ifIXsrSt24__is_bitwise_relocatableIT_vE5valueEPS5_E4typeES7_S7_S7_RSaIT0_E:

0000000000000000 <_ZSt14__relocate_a_1IPN8MemTable8QuadlistES2_ENSt9enable_ifIXsrSt24__is_bitwise_relocatableIT_vE5valueEPS5_E4typeES7_S7_S7_RSaIT0_E>:
    __relocate_a_1(_Tp* __first, _Tp* __last,
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 30          	sub    $0x30,%rsp
   c:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  10:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  14:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
  18:	48 89 4d d0          	mov    %rcx,-0x30(%rbp)
      ptrdiff_t __count = __last - __first;
  1c:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  20:	48 2b 45 e8          	sub    -0x18(%rbp),%rax
  24:	48 c1 f8 03          	sar    $0x3,%rax
  28:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
      if (__count > 0)
  2c:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
  31:	7e 1f                	jle    52 <_ZSt14__relocate_a_1IPN8MemTable8QuadlistES2_ENSt9enable_ifIXsrSt24__is_bitwise_relocatableIT_vE5valueEPS5_E4typeES7_S7_S7_RSaIT0_E+0x52>
	__builtin_memmove(__result, __first, __count * sizeof(_Tp));
  33:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  37:	48 8d 14 c5 00 00 00 	lea    0x0(,%rax,8),%rdx
  3e:	00 
  3f:	48 8b 4d e8          	mov    -0x18(%rbp),%rcx
  43:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  47:	48 89 ce             	mov    %rcx,%rsi
  4a:	48 89 c7             	mov    %rax,%rdi
  4d:	e8 00 00 00 00       	call   52 <_ZSt14__relocate_a_1IPN8MemTable8QuadlistES2_ENSt9enable_ifIXsrSt24__is_bitwise_relocatableIT_vE5valueEPS5_E4typeES7_S7_S7_RSaIT0_E+0x52>
      return __result + __count;
  52:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  56:	48 8d 14 c5 00 00 00 	lea    0x0(,%rax,8),%rdx
  5d:	00 
  5e:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  62:	48 01 d0             	add    %rdx,%rax
    }
  65:	c9                   	leave  
  66:	c3                   	ret    

Disassembly of section .text._ZNK9__gnu_cxx13new_allocatorIN7KVStore7ssLevelEE11_M_max_sizeEv:

0000000000000000 <_ZNK9__gnu_cxx13new_allocatorIN7KVStore7ssLevelEE11_M_max_sizeEv>:
      _M_max_size() const _GLIBCXX_USE_NOEXCEPT
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
	return std::size_t(__PTRDIFF_MAX__) / sizeof(_Tp);
   c:	48 b8 ff ff ff ff ff 	movabs $0xfffffffffffffff,%rax
  13:	ff ff 0f 
      }
  16:	5d                   	pop    %rbp
  17:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx13new_allocatorIN7KVStore7ssLevelEE8allocateEmPKv:

0000000000000000 <_ZN9__gnu_cxx13new_allocatorIN7KVStore7ssLevelEE8allocateEmPKv>:
      allocate(size_type __n, const void* = static_cast<const void*>(0))
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  10:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  14:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
	if (__builtin_expect(__n > this->_M_max_size(), false))
  18:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  1c:	48 89 c7             	mov    %rax,%rdi
  1f:	e8 00 00 00 00       	call   24 <_ZN9__gnu_cxx13new_allocatorIN7KVStore7ssLevelEE8allocateEmPKv+0x24>
  24:	48 39 45 f0          	cmp    %rax,-0x10(%rbp)
  28:	0f 97 c0             	seta   %al
  2b:	0f b6 c0             	movzbl %al,%eax
  2e:	48 85 c0             	test   %rax,%rax
  31:	0f 95 c0             	setne  %al
  34:	84 c0                	test   %al,%al
  36:	74 1a                	je     52 <_ZN9__gnu_cxx13new_allocatorIN7KVStore7ssLevelEE8allocateEmPKv+0x52>
	    if (__n > (std::size_t(-1) / sizeof(_Tp)))
  38:	48 b8 ff ff ff ff ff 	movabs $0x1fffffffffffffff,%rax
  3f:	ff ff 1f 
  42:	48 39 45 f0          	cmp    %rax,-0x10(%rbp)
  46:	76 05                	jbe    4d <_ZN9__gnu_cxx13new_allocatorIN7KVStore7ssLevelEE8allocateEmPKv+0x4d>
	      std::__throw_bad_array_new_length();
  48:	e8 00 00 00 00       	call   4d <_ZN9__gnu_cxx13new_allocatorIN7KVStore7ssLevelEE8allocateEmPKv+0x4d>
	    std::__throw_bad_alloc();
  4d:	e8 00 00 00 00       	call   52 <_ZN9__gnu_cxx13new_allocatorIN7KVStore7ssLevelEE8allocateEmPKv+0x52>
	return static_cast<_Tp*>(::operator new(__n * sizeof(_Tp)));
  52:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  56:	48 c1 e0 03          	shl    $0x3,%rax
  5a:	48 89 c7             	mov    %rax,%rdi
  5d:	e8 00 00 00 00       	call   62 <_ZN9__gnu_cxx13new_allocatorIN7KVStore7ssLevelEE8allocateEmPKv+0x62>
  62:	90                   	nop
      }
  63:	c9                   	leave  
  64:	c3                   	ret    

Disassembly of section .text._ZSt12__niter_baseIPN7KVStore7ssLevelEET_S3_:

0000000000000000 <_ZSt12__niter_baseIPN7KVStore7ssLevelEET_S3_>:
    __niter_base(_Iterator __it)
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    { return __it; }
   c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  10:	5d                   	pop    %rbp
  11:	c3                   	ret    

Disassembly of section .text._ZSt14__relocate_a_1IN7KVStore7ssLevelES1_ENSt9enable_ifIXsrSt24__is_bitwise_relocatableIT_vE5valueEPS4_E4typeES6_S6_S6_RSaIT0_E:

0000000000000000 <_ZSt14__relocate_a_1IN7KVStore7ssLevelES1_ENSt9enable_ifIXsrSt24__is_bitwise_relocatableIT_vE5valueEPS4_E4typeES6_S6_S6_RSaIT0_E>:
    __relocate_a_1(_Tp* __first, _Tp* __last,
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 30          	sub    $0x30,%rsp
   c:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  10:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  14:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
  18:	48 89 4d d0          	mov    %rcx,-0x30(%rbp)
      ptrdiff_t __count = __last - __first;
  1c:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  20:	48 2b 45 e8          	sub    -0x18(%rbp),%rax
  24:	48 c1 f8 03          	sar    $0x3,%rax
  28:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
      if (__count > 0)
  2c:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
  31:	7e 1f                	jle    52 <_ZSt14__relocate_a_1IN7KVStore7ssLevelES1_ENSt9enable_ifIXsrSt24__is_bitwise_relocatableIT_vE5valueEPS4_E4typeES6_S6_S6_RSaIT0_E+0x52>
	__builtin_memmove(__result, __first, __count * sizeof(_Tp));
  33:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  37:	48 8d 14 c5 00 00 00 	lea    0x0(,%rax,8),%rdx
  3e:	00 
  3f:	48 8b 4d e8          	mov    -0x18(%rbp),%rcx
  43:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  47:	48 89 ce             	mov    %rcx,%rsi
  4a:	48 89 c7             	mov    %rax,%rdi
  4d:	e8 00 00 00 00       	call   52 <_ZSt14__relocate_a_1IN7KVStore7ssLevelES1_ENSt9enable_ifIXsrSt24__is_bitwise_relocatableIT_vE5valueEPS4_E4typeES6_S6_S6_RSaIT0_E+0x52>
      return __result + __count;
  52:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  56:	48 8d 14 c5 00 00 00 	lea    0x0(,%rax,8),%rdx
  5d:	00 
  5e:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  62:	48 01 d0             	add    %rdx,%rax
    }
  65:	c9                   	leave  
  66:	c3                   	ret    
