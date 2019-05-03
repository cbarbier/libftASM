;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_isupper.s                                       :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2019/04/30 15:34:13 by cbarbier          #+#    #+#              #
;#    Updated: 2019/04/30 15:50:20 by cbarbier         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

SECTION .text
global _ft_isupper

; int ft_isupper(int c);
_ft_isupper:
enter 0, 0
    cmp edi, 'A'
    jl false
    cmp edi, 'Z'
    jg false
true:
    mov rax, 1
    jmp return
false:
    mov rax, 0
return:
leave
ret