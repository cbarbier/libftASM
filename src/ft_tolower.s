;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_tolower.s                                       :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2019/04/30 15:34:13 by cbarbier          #+#    #+#              #
;#    Updated: 2019/04/30 15:50:20 by cbarbier         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

SECTION .text
extern _ft_isupper
global _ft_tolower

; int ft_tolower(int c);
_ft_tolower:
enter 0, 0
    call _ft_isupper
    cmp rax, 0
    je false
true:
    add rdi, 32
    mov rax, rdi
    jmp return
false:
    mov rax, rdi
return:
leave
ret