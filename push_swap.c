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
  t_stack *stack2;
  t_stack *kcats;
  t_stack *kcats2;
  t_queue *front;
  t_queue *back;
  t_op *result;
  t_ops *ops;
  t_ops *ops2;
  t_ops *spo;
  t_ops *spo2;
  clock_t start;
  clock_t end;

  start = clock();

  ops = ops_new();
  ops2 = ops_new();
  spo = ops_new();
  spo2 = ops_new();
  stack = stack_init();
  kcats = stack_init();
  if (!ft_parse(argc, argv, stack, kcats)) {
    // stack_print(kcats);
    // return (0);
    if (!node_issort(stack->stack_a)) {
      if (argc > 1) {
        stack2 = stack_dup(stack);
        kcats2 = stack_dup(kcats);
        sort(stack, argc - 1, getspan(argc), ops);
        sort2(stack2, argc - 1, getspan(argc), ops2);
        sort(kcats, argc - 1, getspan(argc), spo);
        sort2(kcats2, argc - 1, getspan(argc), spo2);
        ops_optimize(ops);
        ops_optimize(ops2);
        ops_optimize(spo);
        ops_optimize(spo2);
        if (ops->n <= ops2->n && ops->n <= spo->n && ops->n <= spo2->n) {
          ops_print(ops);
        } else if (ops2->n <= ops->n && ops2->n <= spo->n &&
                   ops2->n <= spo2->n) {
          ops_print(ops2);
        } else if (spo->n <= ops->n && spo->n <= ops2->n && spo->n <= spo2->n) {
          ops_reverse(spo);
          ops_print(spo);
        } else {
          ops_reverse(spo2);
          ops_print(spo2);
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
  end = clock();
  // printf("time = %f\n", (double)(end - start) / CLOCKS_PER_SEC);
  return (0);
}
