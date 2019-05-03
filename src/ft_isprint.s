;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_isprint.s                                       :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2019/04/30 15:34:13 by cbarbier          #+#    #+#              #
;#    Updated: 2019/04/30 15:50:20 by cbarbier         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

SECTION .text
global _ft_isprint

; int ft_isprint(int c);
_ft_isprint:
enter 0, 0
    cmp rdi, 32
    jl false
    cmp rdi, 126
    jg false
true:
    mov rax, 1
    jmp return
false:
    mov rax, 0
return:
leave
ret