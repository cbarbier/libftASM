;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_memset.s                                       :+:      :+:    :+:     #
;#                                                     +:+ +:+         +:+      #
;#    By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2019/04/30 15:34:13 by cbarbier          #+#    #+#              #
;#    Updated: 2019/04/30 15:50:20 by cbarbier         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

SECTION .text
global _ft_memset

; void *ft_memset(void *b, int c, size_t len);
_ft_memset:
enter 0, 0
    mov r10, rdi
    mov rcx, rdx
    mov al, sil
    rep stosb
    mov rax, r10
leave
ret