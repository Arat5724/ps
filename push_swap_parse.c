/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongble <jeongble@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:07:11 by jeongble          #+#    #+#             */
/*   Updated: 2022/07/22 10:53:47 by jeongble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void pretty_n(int *arr, int *rra, t_stack *stack, t_stack *kcats);
static void get_size(t_num *last, t_num *next, int n, int *size);

static void ft_putendl_fd(char *s, int fd) {
  int i;

  i = 0;
  while (*(s + i)) i++;
  write(fd, s, i);
  write(fd, "\n", 1);
}

int ft_parse(int argc, char **argv, t_stack *stack, t_stack *kcats) {
  int i;
  int n;
  int *arr;
  int *rra;
  t_num *new;

  if (argc == 1) return (1);
  arr = (int *)malloc(sizeof(int) * (argc - 1));
  rra = (int *)malloc(sizeof(int) * (argc - 1));
  i = 0;
  while (i < argc - 1) {
    new = node_new(0);
    if (kcats->tail_a == NULL) {
      kcats->stack_a = new;
      kcats->tail_a = new;
    } else {
      kcats->tail_a->next = new;
      new->last = kcats->tail_a;
      kcats->tail_a = new;
    }
    i++;
  }
  i = 1;
  while (i < argc) {
    n = ft_atoi_err(argv[i], &(stack->stack_a), &(stack->tail_a));
    if (n) {
      free(arr);
      ft_putendl_fd("ERROR", 2);
      return (1);
    }
    arr[i - 1] = stack->tail_a->n;
    i++;
  }
  pretty_n(arr, rra, stack, kcats);
  free(arr);
  return (0);
}

static void get_size(t_num *last, t_num *next, int n, int *size) {
  while (last) {
    if (last->n < n) *(size) += 1;
    last = last->last;
  }
  while (next) {
    if (next->n < n) *(size) += 1;
    next = next->next;
  }
}

static void pretty_n(int *arr, int *rra, t_stack *stack, t_stack *kcats) {
  int n;
  int i;
  int size;
  t_num *stack_a;
  t_num *head;

  stack_a = stack->stack_a;
  i = 0;
  while (stack_a) {
    size = 0;
    n = stack_a->n;
    get_size(stack_a->last, stack_a->next, n, &size);
    arr[i++] = size;
    stack_a = stack_a->next;
  }
  head = stack->stack_a;
  i = 0;
  while (head) {
    rra[arr[i]] = i;
    head->n = arr[i++];
    head = head->next;
  }
  head = kcats->stack_a;
  i = 0;
  while (head) {
    head->n = rra[i];
    head = head->next;
    i++;
  }
}
