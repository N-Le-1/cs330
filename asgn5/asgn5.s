	.file	"asgn5.c" 		#declares source file name with assembly code
	.text					# start of code
	.globl	myAddTwoNumbersFunction		#declares the myAddTwoNumbersFunction as global variable
	.type	myAddTwoNumbersFunction, @function  #declares that myAddTwoNumbersFunction is a function
myAddTwoNumbersFunction:    #start of the function
.LFB0:						# label for function
	.cfi_startproc 		#ignore
	pushq	%rbp		#pushes value of the register into the stack
	.cfi_def_cfa_offset 16 		#ignore
	.cfi_offset 6, -16			#ignore
	movq	%rsp, %rbp			#moves the rsp value into the current stack pointer rbp
	.cfi_def_cfa_register 6		#ignore
	movl	%edi, -4(%rbp)		#moves first argument into the local variable
	movl	%esi, -8(%rbp)		#moves the second argument into the local variable
	movl	-4(%rbp), %edx		#loads the first argument into the edx register
	movl	-8(%rbp), %eax		#loads the second argument into the eax register
	addl	%edx, %eax			#adds the value of edx and eax together and stores the added value in eax
	popq	%rbp				#Pops and restores the base pointer from the stack
	.cfi_def_cfa 7, 			#ignore
	ret							# return statement for the function
	.cfi_endproc 				#ignore
.LFE0:							#label for function exit
	.size	myAddTwoNumbersFunction, .-myAddTwoNumbersFunction  #creates the size of the function
	.section	.rodata											#starts read only data section
.LC0:							 #label for the string "The answer is %d\n"
	.string	"The answer is %d\n" #defines string being used for printing
	.text 						 # returns to code section
	.globl	main				 #declares main function as a global function
	.type	main, @function		 #declares main as a function
main: 							 #beginning of main function
.LFB1:							 #label for function 
	.cfi_startproc				 #ignore
	pushq	%rbp				 #pushes the base value of pointer into the stack
	.cfi_def_cfa_offset 16		 #ignore
	.cfi_offset 6, -16			 #ignore
	movq	%rsp, %rbp			 #sets the pointer rsp to the current pointer rbp
	.cfi_def_cfa_register 6		 #ignore
	subq	$16, %rsp			 #subtracts 16 from rsp to allocate space in the stack.
	movl	$10, -12(%rbp)		 #initializes variavle to have the value of 10
	movl	$7, -8(%rbp)		 #initializes another variable to have the value 7	 
	movl	$0, -4(%rbp)		 #initializes a third variable to have the value of 0
	movl	-8(%rbp), %edx		 #loads value of -8rbp (which is 7) into the edx register
	movl	-12(%rbp), %eax      #loads value of -12 rbp (which is 10) into the eax register
	movl	%edx, %esi		   	 #moves value of edx into esi register to pass a function argument
	movl	%eax, %edi			 #moves value of eax into the edi register to also pass a function argument
	call	myAddTwoNumbersFunction		#calls the myAddTwoNumbersFunction function using esi and edi registers
	movl	%eax, -4(%rbp) 		 #moves the return value of eax into the third variable -4rbp
	movl	-4(%rbp), %eax		 #loads the result of adding the two integers back into eax
	movl	%eax, %esi 			 #moves the value of eax into esi
	leaq	.LC0(%rip), %rdi	 #prepares the string to print as the output
	movl	$0, %eax			 #clears the eax value used to return value of functions
	call	printf@PLT			 #calls the printf function pasing the string with the result.
	movl	$0, %eax			 #clears eax again
	leave						 #leaves the main function and resets the stack
	.cfi_def_cfa 7, 8			 #ignore
	ret							 #return statement for main function
	.cfi_endproc				 #ignore
.LFE1:							 #label to show the end of the main function
	.size	main, .-main		 #calculates the size of main function in bytes
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"	 # compiler details that generated the code
	.section	.note.GNU-stack,"",@progbits			 #notes about the stack
