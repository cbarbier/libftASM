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
buf times 5 db 0

SECTION .text
global _ft_cat

;void   ft_cat(int fd)
_ft_cat:
enter 0, 0
    mov ebx, edi
    cmp ebx, 0
    jl return
read_loop:
    mov edi, ebx
    lea rsi, [rel buf]
    mov edx, 4
    mov rax, 0x2000003 ; read
    syscall
    cmp eax, 0
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