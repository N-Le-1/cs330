.data               # start of data section
# put any global or static variables here

.section .rodata    # start of read-only data section
# constants here, such as strings
# modifying these during runtime causes a segmentation fault, so be cautious!
ansString1: .string "The answer to #1 is: %d\n"


.text           # start of text /code
# everything inside .text is read-only, which includes your code!
.global main  # required, tells gcc where to begin execution

# === functions here ===
# function that takes A and multiplies it by 5
# takes one arg, A in %rdi
# returns whole num int mult. by 5 in %rax
multByFive:





main:           # start of main() function
# preamble
pushq %rbp      
movq %rsp, %rbp

# === code here ===
# A = 4, B = 2

movq $4, %rax   # A = 4
movq $2, %rbx   # B = 2




# return
movq $0, %rax   # place return value in rax
leave           # undo preamble, clean up the stack
ret             # return
