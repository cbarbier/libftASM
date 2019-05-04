;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_memcpy.s                                       :+:      :+:    :+:     #
;#                                                     +:+ +:+         +:+      #
;#    By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2019/04/30 15:34:13 by cbarbier          #+#    #+#              #
;#    Updated: 2019/04/30 15:50:20 by cbarbier         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

SECTION .text
global _ft_memcpy

; void *ft_memcpy(void *b, int c, size_t len);
_ft_memcpy:
enter 0, 0
    mov r10, rdi
    mov rcx, rdx
    mov al, sil
    rep movsb
    mov rax, r10
leave
ret