;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_cat.s                                         :+:      :+:    :+:      #
;#                                                     +:+ +:+         +:+      #
;#    By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2019/04/30 15:34:13 by cbarbier          #+#    #+#              #
;#    Updated: 2019/04/30 15:50:20 by cbarbier         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

SECTION .data
tst db "test", 10, 0
buf times 1025 db 0

SECTION .text
global _ft_cat

;void   ft_cat(int fd)
_ft_cat:
enter 0, 0
    push r10
    mov r10, rdi
    cmp r10, 0
    jl return
    mov rdi, 1
    lea rsi, [rel tst]
    mov rdx, 5
    mov rax, 0x2000004
    syscall
read_loop:
    mov rdi, r10
    lea rsi, [rel tst]
    mov rdx, 1024
    mov rax, 0x2000003 ;read
    syscall
    cmp rax, 0
    jle return
    lea rsi, [rel buf]
    mov byte [rsi + rax], 0
    mov rdi, 1
    mov rdx, rax
    mov rax, 0x2000004 ; write
    syscall
    cmp rax, 0
    jl return
    jmp read_loop
return:
    pop r10
leave
ret