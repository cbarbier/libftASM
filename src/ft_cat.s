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

extern _read
SECTION .data
buf times 42 db 0

SECTION .text
global _ft_cat

;void   ft_cat(int fd)
_ft_cat:
enter 0, 0
    mov r12d, edi
    cmp r12d, 0
    jl return
read_loop:
    xor rax, rax
    mov edi, r12d
    lea rsi, [rel buf]
    mov edx, 41
    call _read
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
leave
ret