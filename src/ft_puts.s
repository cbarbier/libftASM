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

SECTION .text
global _ft_puts

; int ft_puts(const char *s);
_ft_puts:
enter 0, 0
    mov rdx, 0
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
leave
ret