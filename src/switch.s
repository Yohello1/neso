.include "abi.s"

;C declaration:
;   void switch_to_task(struct context *old, struct context *next);
;
switch_to_task:
    ;;  Save previous task's state
    ;;
    ;;  Notes:
    ;;      Only registers;
    ;;      ra, sp, s0-11 are saved
    ;;      The rest are NOT caller-saved registers
    ;;
    ;; Ok for citations on how this works, check out linux/arch/riscv/include/asm/asm.h
    ;; and linux/arch/riscv/kernel/entry.S
    ;;
    ;; Their REG_S/REG_L is literally just a store function
    ;; Which is asliased to either the double word
    ;; (ld/sd), or the single word variant depending
    ;; upon the aarget is 32-bits or 64-bits
    ;;
    ;; Ok first it stores the old context, then it loads the next one
    sd ra, 0(a0)
    sd sp, 8(a0)
    sd s0, 16(a0)
    sd s1, 24(a0)
    sd s2, 32(a0)
    sd s3, 40(a0)
    sd s4, 48(a0)
    sd s5, 56(a0)
    sd s6, 64(a0)
    sd s7, 72(a0)
    sd s8, 80(a0)
    sd s9, 88(a0)
    sd s10, 96(a0)
    sd s11, 104(a0)

    ld ra, 0(a1)
    ld sp, 8(a1)
    ld s0, 16(a1)
    ld s1, 24(a1)
    ld s2, 32(a1)
    ld s3, 40(a1)
    ld s4, 48(a1)
    ld s5, 56(a1)
    ld s6, 64(a1)
    ld s7, 72(a1)
    ld s8, 80(a1)
    ld s9, 88(a1)
    ld s10, 96(a1)
    ld s11, 104(a1)

    ret
