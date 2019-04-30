;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_bzero.s                                         :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2019/04/30 15:34:13 by cbarbier          #+#    #+#              #
;#    Updated: 2019/04/30 15:50:20 by cbarbier         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

SECTION .text
global _ft_bzero

; void ft_bzero(void *s, size_t n)
_ft_bzero:
enter 0, 0
while: ; n > 0 && *s
    cmp word[ rdi], 0
    je end
    cmp rsi, 0
    je end
    mov word [rdi], 0
    inc rdi
    dec rsi
    jmp while
end:
leave
ret