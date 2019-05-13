;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_swapbits.s                                      :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2019/04/30 15:34:13 by cbarbier          #+#    #+#              #
;#    Updated: 2019/04/30 15:50:20 by cbarbier         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

SECTION .data
tst db "test", 10, 0
SECTION .text
global _ft_swapbits

; unsigned char ft_swapbits(unsigned char c);
_ft_swapbits:
enter 16, 0
  xor rax, rax
  mov sil, dil
  mov al, dil
  shl sil, 4
  shr al, 4
  or al, sil
return:
leave
ret