.include "abi.s"

;C declaration:
;   void switch_to_task(thread_control_block *next_thread);
;
;WARNING: Caller is expected to disable IRQs before calling, and enable IRQs again after function returns

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
