;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_isalnum.s                                       :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2019/04/30 15:34:13 by cbarbier          #+#    #+#              #
;#    Updated: 2019/04/30 15:50:20 by cbarbier         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

SECTION .text
extern _ft_isalpha
extern _ft_isdigit
global _ft_isalnum

; int ft_isalnum(int c);
_ft_isalnum:
enter 0, 0
    call _ft_isdigit
    cmp ax, 0
    jne true
    call _ft_isalpha
    cmp ax, 0
    jne true
false:
    mov rax, 0
    jmp return
true:
    mov rax, 1
return:
leave
ret