;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_strcat.s                                        :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2019/04/30 15:34:13 by cbarbier          #+#    #+#              #
;#    Updated: 2019/04/30 15:50:20 by cbarbier         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

SECTION .text
global _ft_strcat

; char *strcat(char *restrict s1, const char *restrict s2);
_ft_strcat:
enter 0, 0
    mov r8, 0
    mov r9, 0
while1: ; *s1
    cmp byte [rdi + r8], 0
    je end1
    inc r8
    jmp while1
end1:
while2: ; *s2
    cmp byte [rsi + r9], 0
    je end2
    mov r10b, byte [rsi + r9]
    mov byte [rdi + r8], r10b
    inc r8
    inc r9
    jmp while2
end2:
    mov byte[rdi + r8], 0
    mov rax, rdi
leave
ret