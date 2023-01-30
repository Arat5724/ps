/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongble <jeongble@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:39:05 by jeongble          #+#    #+#             */
/*   Updated: 2022/07/22 10:59:39 by jeongble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int getspan(int argc) {
  // return (40);
  const int size = 2 * (argc - 1);
  int i;

  i = 0;
  while (i * i < size) i++;
  return (i);
}

void queue_play(t_queue **front, t_queue **back, t_op **result) {
  while (*(front)) queue_start(front, back, result, 0);
  op_print(*(result));
}

int main(int argc, char **argv) {
  t_stack *stack;
  t_stack *kcats;
  t_queue *front;
  t_queue *back;
  t_op *result;
  t_ops *ops;
  t_ops *spo;

  ops = ops_new();
  spo = ops_new();

  stack = stack_init();
  kcats = stack_init();
  if (!ft_parse(argc, argv, stack, kcats)) {
    // stack_print(kcats);
    // return (0);
    if (!node_issort(stack->stack_a)) {
      if (argc > 1) {
        sort(stack, argc - 1, getspan(argc), ops);
        // ops_print(ops);  // del
        // return (0);      // del
        sort(kcats, argc - 1, getspan(argc), spo);
        if (ops->n < spo->n) {
          // printf("ddd\n");
          ops_print(ops);
        } else {
          ops_reverse(spo);
          ops_print(spo);
        }
      } else {
        result = 0;
        front = queue_new(stack, 0, 0, -1);
        back = front;
        queue_play(&front, &back, &result);
        return (0);
      }
    }
  }
  stack_del(stack);
  return (0);
}
