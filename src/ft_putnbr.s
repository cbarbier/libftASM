;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_putnbr.s                                          :+:      :+:    :+:  #
;#                                                     +:+ +:+         +:+      #
;#    By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2019/04/30 15:34:13 by cbarbier          #+#    #+#              #
;#    Updated: 2019/04/30 15:50:20 by cbarbier         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #


extern _ft_putchar
SECTION .data
SECTION .text
global _ft_putnbr

; int ft_putnbr(const char *s);
_ft_putnbr:
enter 32, 0
    mov ebx, edi
    cmp ebx, 0
    jge positive
    mov r13d, ebx
    imul r13d, -1
    mov rbx, r13
    mov rdi, '-'
    call _ft_putchar
positive:
    xor rdx, rdx
    cmp rbx, 10
    jl print_digit
    push rbx
    mov rax, rbx
    mov ebx, 10
    idiv rbx
    mov r12d, eax
    mov edi, r12d
    call _ft_putnbr
    pop rbx
print_digit:
    xor rdx, rdx
    mov rax, rbx
    mov rbx, 10
    div rbx
    add rdx, '0'
    mov rdi, rdx
    call _ft_putchar
leave
ret