;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_isalpha.s                                       :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2019/04/30 15:34:13 by cbarbier          #+#    #+#              #
;#    Updated: 2019/04/30 15:50:20 by cbarbier         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

SECTION .text
global _ft_isalpha

; int ft_isalpha(int c);
_ft_isalpha:
enter 0, 0
    cmp edi, 0
    jl false
    cmp edi, 255
    jg false
    cmp dil, 'A'
    jl false
    cmp dil, 'z'
    jg false
    cmp dil, 'a'
    jge true
    cmp dil, 'Z'
    jg false
true:
    mov rax, 1
    jmp return
false:
    mov rax, 0
return:
leave
ret