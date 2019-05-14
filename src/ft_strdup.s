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
extern _malloc
extern _ft_strlen
global _ft_strdup

; char *strdup(const char *s1);
_ft_strdup:
enter 0, 0
    push r12
    push r13
    mov r12, rdi
    call _ft_strlen
    mov rdi, rax
    inc rdi
    mov r13, rax
    call _malloc
    cmp rax, 0
    je return
    mov rdi, rax
    mov rsi, r12
    mov r12, rax
    mov rcx, r13
    rep movsb
    mov byte [rdi], 0
    mov rax, r12
return:
    pop r12
    pop r13
leave
ret