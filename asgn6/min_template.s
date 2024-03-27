.data               # start of data section
# put any global or static variables here

.section .rodata    # start of read-only data section
# constants here, such as strings
# modifying these during runtime causes a segmentation fault, so be cautious!
ansString1: .string "The answer to 1.) is %d\n"
ansString2: .string "The answer to 2.) is %d\n"

.text           # start of text /code
# everything inside .text is read-only, which includes your code!
.global main  # required, tells gcc where to begin execution


main:           # start of main() function
# preamble
pushq %rbp
movq %rsp, %rbp

# === code here ===
movq $4, %rdx          # A = 4   in rdx
movq $2, %rbx          # B = 2   in rbx

# FUNCTION FOR A*5
# multiples A by 5
# Takes in A integer
# Outputs A * 5
imulq $5, %rdx         # A * 5 into rdx

movq %rdx, %rax     # answer in rax

movq $ansString1, %rdi # ptr to string in rdi
movq %rax, %rsi        #move answer into rsi
xorq %rax, %rax        # 0 in rax now
call printf            # print output

# FUNCTION FOR (A + B) - (A / B)
movq %rdx, %rax       #move A into rax
addq %rbx, %rax       # add A to B into rbx register

xorq %rdx, %rdx       #clear rdx register
divq %rbx             # divide A by B

subq %rdx, %rax       # subtract (A+B) from (A/B) into rax

movq $ansString2, %rdi
movq %rax, %rsi
xorq %rax, %rax
call printf

# return
movq $0, %rax   # place return value in rax
leave           # undo preamble, clean up the stack
ret             # return
