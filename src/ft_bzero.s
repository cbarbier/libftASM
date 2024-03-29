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

extern _ft_memset
SECTION .text
global _ft_bzero

; void ft_bzero(void *s, size_t n)
_ft_bzero:
enter 0, 0
    mov rdx, rsi
    mov esi, 0
    call _ft_memset
end:
leave
ret