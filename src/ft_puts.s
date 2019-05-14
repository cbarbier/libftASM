;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_puts.s                                          :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2019/04/30 15:34:13 by cbarbier          #+#    #+#              #
;#    Updated: 2019/04/30 15:50:20 by cbarbier         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

SECTION .data
nul db "(null)", 10, 0
SECTION .text
global _ft_puts

; int ft_puts(const char *s);
_ft_puts:
enter 16, 0
    mov rdx, 0
    cmp rdi, 0
    je put_null
while1: ; *s
    cmp byte [rdi + rdx], 0
    je end1
    inc rdx
    jmp while1
end1:
    mov rsi, rdi
    mov rdi, 1
    mov rax, 0x2000004
    syscall
    jc end
    mov rdi, 1
    mov byte [rsp+32], 10
    mov rsi, rsp
    add rsi, 32
    mov rdx, 1
    mov rax, 0x2000004
    syscall
    jc end
    mov rax, 10
end:
leave
ret

put_null:
    mov rdi, 1
    lea rsi, [rel nul]
    mov rdx, 7
    mov rax, 0x2000004
    syscall
    jc end
    mov rax, 10
    jmp end