.data               # start of data section
# put any global or static variables here

.section .rodata    # start of read-only data section
# constants here, such as strings
# modifying these during runtime causes a segmentation fault, so be cautious!
ansString1: .string "The answer to 1.) is %d\n"
ansString2: .string "The answer to 2.) is %d\n"
ansString3: .string "The answer to 3.) is %d\n"

.text           # start of text /code
# everything inside .text is read-only, which includes your code!
.global main  # required, tells gcc where to begin execution


main:           # start of main() function
# preamble
pushq %rbp
movq %rsp, %rbp

# === code here ===
movq $4, %rbp          # A = 4   in rdx
movq $2, %rbx          # B = 2   in rbx

# ======FUNCTION FOR A*5 ======
# multiples A by 5
# Takes in A integer (A=5)
# Outputs A * 5 which is 20

movq %rbp, %rax         #move A=4 into rax 
imulq $5, %rax          # A * 5 into rax. answer into rax


movq $ansString1, %rdi # ptr to string in rdi
movq %rax, %rsi        #move answer into rsi
xorq %rax, %rax        # 0 in rax now
call printf            # print output

# ======FUNCTION FOR (A + B) - (A / B)======
/*
Does the function (A+B) - (A/B)
Takes in A and B integer (A=4,B=2)
Outputs the final integer value which is 4
*/
#(A+B)
movq %rbp, %rax  # move A=4 in rax
movq %rbx, %r8   #move B=2 in r8

addq %rax, %r8   # A+B is in r8 (4+2) = 6

#(A/B)
# A already in rax
idivq %rbx   #rax / rbx   answer in rax (4/2) = 2

#(A+B)-(A/B)
subq %rax,%r8  # First operation - second operation, valued stored in r8 (6-2) = 4

movq $ansString2, %rdi #ptr to string in rdi
movq %r8, %rsi  #move answer into rsi
xorq %r8, %r8   # set r8 back to 0
xorq %rax, %rax # set rax back to 0
call printf     #print answer

# ====== FUNCTION FOR (A - B) + (A * B)======
/*
Does the function (A-B) + (A*B)
Takes in A and B integers (A=4,B=2)
Outputs the final integer value which is 10
*/
#Initialize
movq %rbp, %r8     #move A=4 in r8
movq %rbx, %r9     #move B=2 in r9

#(A-B)
subq %r9, %r8     # A - B in r8 (4-2) = 2

#(A*B)
movq %rbx, %r10   # move B=2 in r10 
imulq %rbp, %r10  # A*B in r10 (4*2) = 8

#(A-B) + (A*B) 
addq %r8,%r10    #First operation + second operation, value stored in rbx (2+8 = 10)

movq $ansString3, %rdi #ptr string in rdi
movq %r10, %rsi        #move answer into rsi
xorq %r10, %r10        #set r10 back to 0
call printf            #print answer

# return
movq $0, %rax   # place return value in rax
leave           # undo preamble, clean up the stack
ret             # return
