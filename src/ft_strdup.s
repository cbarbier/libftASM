;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_strdup.s                                       :+:      :+:    :+:     #
;#                                                     +:+ +:+         +:+      #
;#    By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2019/04/30 15:34:13 by cbarbier          #+#    #+#              #
;#    Updated: 2019/04/30 15:50:20 by cbarbier         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

SECTION .text
global _ft_strdup

; char *strdup(const char *s1);
_ft_strdup:
enter 0, 0
    push r10
    xor rcx, rcx
    dec rcx
    mov r10, rdi
    xor al, al
    repne scasb
    sub rdi, r10
    mov rax, rdi
    dec rax
    pop r10
leave
ret