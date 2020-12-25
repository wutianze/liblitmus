#ifndef ASM_CYCLES_H
#define ASM_CYCLES_H

typedef unsigned long cycles_t;

#define CYCLES_FMT "lu"
#define read_csr(reg) ({ unsigned long __tmp; \
  asm volatile ("csrr %0, " #reg : "=r"(__tmp)); \
  __tmp; })

static inline cycles_t get_cycles(void)
{
	cycles_t c;
	c = read_csr(mcycle);
	return c;
}

#endif
