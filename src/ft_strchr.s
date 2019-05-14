;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_strchr.s                                       :+:      :+:    :+:     #
;#                                                     +:+ +:+         +:+      #
;#    By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2019/04/30 15:34:13 by cbarbier          #+#    #+#              #
;#    Updated: 2019/04/30 15:50:20 by cbarbier         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

SECTION .text
extern _ft_strlen
global _ft_strchr

; char *strrchr(const char *s1, int c);
_ft_strchr:
enter 0, 0
    push r12
    mov r12, rdi
    call _ft_strlen
    cmp rax, 0
    je ret_null
    mov rcx, rax
    mov rdi, r12
    mov al, sil
    repne scasb
    dec rdi
    cmp rcx, 0
    je pos_end
    mov rax, rdi
    jmp return
pos_end:
    cmp esi, 0
    je ret_pos
    cmp byte [rdi], sil
    jne ret_null
    jmp ret_pos2
ret_pos:
    inc rdi
ret_pos2:
    mov rax, rdi
    jmp return
ret_null:
    mov rax, 0
    jmp return
return:
    pop r12
leave
ret