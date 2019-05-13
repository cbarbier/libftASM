;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_putchar.s                                        :+:      :+:    :+:   #
;#                                                     +:+ +:+         +:+      #
;#    By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2019/04/30 15:34:13 by cbarbier          #+#    #+#              #
;#    Updated: 2019/04/30 15:50:20 by cbarbier         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

SECTION .data
tst db "test", 10, 0
SECTION .text
global _ft_putchar

; int ft_putchar(int c);
_ft_putchar:
enter 16, 0
   mov byte [rsp + 32], dil
   mov rdi, 1
   mov rsi, rsp
   add rsi, 32
   mov rdx, 1
   mov rax, 0x2000004
   syscall
   cmp rax, 0
   jl return
   xor rax, rax
   mov al, byte [rsp + 32]
return:
leave
ret