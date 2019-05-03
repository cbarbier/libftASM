;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_toupper.s                                       :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2019/04/30 15:34:13 by cbarbier          #+#    #+#              #
;#    Updated: 2019/04/30 15:50:20 by cbarbier         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

SECTION .text
extern _ft_islower
global _ft_toupper

; int ft_toupper(int c);
_ft_toupper:
enter 0, 0
    call _ft_islower
    cmp rax, 0
    je false
true:
    sub rdi, 32
    mov rax, rdi
    jmp return
false:
    mov rax, rdi
return:
leave
ret