;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_isdigit.s                                       :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2019/04/30 15:34:13 by cbarbier          #+#    #+#              #
;#    Updated: 2019/04/30 15:50:20 by cbarbier         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

SECTION .text
global _ft_isdigit

; int ft_isdigit(int c);
_ft_isdigit:
enter 0, 0
    cmp edi, 0
    jl false
    cmp edi, 255
    jg false
    cmp dil, '0'
    jl false
    cmp dil, '9'
    jg false
true:
    mov rax, 1
    jmp return
false:
    mov rax, 0
return:
leave
ret