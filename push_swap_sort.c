/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongble <jeongble@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:02:50 by jeongble          #+#    #+#             */
/*   Updated: 2022/07/22 07:58:46 by jeongble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort2(t_stack *stack, int len, t_ops *ops);
static void sort23(t_stack *stack, int len, t_ops *ops);
static int sort_b(t_stack *stack, int len, t_ops *ops);
static void sort_a2b(t_stack *stack, int i, int span);

static int rai(t_stack *stack, int i, t_ops *ops) {
  int j;

  j = 0;
  while (j < i) {
    ra(stack);
    ops_push_back(ops, RA);
    j++;
  }
  return (1);
}

static int rrai(t_stack *stack, int i, t_ops *ops) {
  int j;

  j = 0;
  while (j < i) {
    rra(stack);
    ops_push_back(ops, RRA);
    j++;
  }
  return (1);
}

int getspan2(int argc) {
  const int size = 2 * argc;
  int i;

  i = 0;
  while (i * i < size) i++;
  return (i);
}

int raorrra(t_stack *stack, int ispan, int len) {
  t_num *head;
  t_num *tail;
  int i;
  int h1;
  int h2;
  int t;

  head = stack->stack_a;
  if (!head || head->n <= ispan) {
    return (0);
  }
  head = head->next;
  tail = stack->tail_a;
  t = 0;
  i = 0;
  while (i < len / 3) {
    if (tail->n <= ispan) t++;
    i++;
    tail = tail->last;
  }
  h1 = 0;
  i = 0;
  while (i < len / 3) {
    if (head->n <= ispan) h1++;
    i++;
    head = head->next;
  }
  h2 = 0;
  while (i < len * 2 / 3) {
    if (head->n <= ispan) h2++;
    i++;
    head = head->next;
  }
  // ft_printf("%d %d\n", h, t);
  if (h1 + h2 < t) return (1);
  // if (h1 + h2 < t && h2 * 3 < t * 2) return (1);
  return (0);
}

void sort(t_stack *stack, int len, int span, t_ops *ops) {
  int i;
  int x;
  int q;
  int rr;

  x = 1;
  rr = 0;
  i = 0;
  // q = 5 * span;
  q = span / 4 + 1;
  span *= 2;
  // span = 6;
  // q = 3;
  // ft_printf("q = %d spqn %d\n", q, span);
  if (raorrra(stack, i + span, len - i)) rrai(stack, (len - i) / 3, ops);
  // rrai(stack, 10, ops);
  while (stack->stack_a) {
    if (stack->stack_a->n <= i) {
      while (rr) {
        if (!rb(stack))
          if (x) ops_push_back(ops, RB);
        rr--;
      }
      if (stack->stack_b != NULL && stack->stack_b->n > stack->stack_a->n) {
        if (!pb(stack))
          if (x) ops_push_back(ops, PB);
        if (!sb(stack))
          if (x) ops_push_back(ops, SB);
      } else {
        if (!pb(stack))
          if (x) ops_push_back(ops, PB);
      };
      i++;
      if (i % q == 0 && span > 1) span -= 1;
      if (raorrra(stack, i + span, len - i)) rrai(stack, (len - i) / 3, ops);
      // if (i % q == 0) span -= 1;
    } else if (stack->stack_a->n > i && stack->stack_a->n <= i + span) {
      while (rr && stack->stack_b->n < stack->stack_a->n) {
        if (!rb(stack))
          if (x) ops_push_back(ops, RB);
        rr--;
      }
      if (!pb(stack))
        if (x) ops_push_back(ops, PB);
      rr++;
      i++;
      if (i % q == 0 && span > 1) span -= 1;
      if (raorrra(stack, i + span, len - i)) rrai(stack, (len - i) / 3, ops);
      // if (i % q == 0) span -= 1;
    } else {
      // } else if (stack->stack_a->n > (i + span)){
      if (!ra(stack))
        if (x) ops_push_back(ops, RA);
    }
  }
  // btoa(stack, len, ops);
}

static void sort_a2b(t_stack *stack, int i, int span) {
  if (stack->stack_a->n <= i) {
    if (stack->stack_b != NULL && stack->stack_b->n > stack->stack_a->n) {
      pb(stack);
      ft_printf("pb\n");
      sb(stack);
      ft_printf("sb\n");
    } else {
      pb(stack);
      ft_printf("pb\n");
    };

  } else if (stack->stack_a->n > i && stack->stack_a->n <= i + span) {
    if (!pb(stack)) ft_printf("pb\n");
    if (!rb(stack)) ft_printf("rb\n");
  }
}

static void sort2(t_stack *stack, int len, t_ops *ops) {
  int result;

  len--;
  result = 0;
  while (stack->stack_b) {
    result += sort_b(stack, len, ops);
    if (!pa(stack)) {
      result += 1;
      ft_printf("pa\n");
    }
    len--;
  }
}

int rbi2(t_stack *stack, int i) {
  int j;

  j = 0;
  while (j < i) {
    rb(stack);
    j++;
  }
  return (i);
}

int rrbi2(t_stack *stack, int i) {
  int j;

  j = 0;
  while (j < i) {
    rrb(stack);
    j++;
  }
  return (i);
}

t_s *s_dup(t_s *src, int len) {
  t_s *result;
  int i;

  result = malloc(sizeof(t_s));
  result->n = src->n;
  result->stacks = stack_dup(src->stacks);
  result->inst = malloc(sizeof(int) * len);
  i = 0;
  while (i < len) {
    (result->inst)[i] = src->inst[i];
    i++;
  }
  return (result);
}

void s_del(t_s *s) {
  if (s) {
    stack_del(s->stacks);
    free(s->inst);
    free(s);
  }
}

int rbi(t_stack *stack, int i, t_ops *ops) {
  int j;

  j = 0;
  while (j < i) {
    rb(stack);
    ops_push_back(ops, RB);
    j++;
  }
  return (i);
}

int rrbi(t_stack *stack, int i, t_ops *ops) {
  int j;

  j = 0;
  while (j < i) {
    rrb(stack);
    ops_push_back(ops, RRB);
    j++;
  }
  return (i);
}

static int sort_b(t_stack *stack, int len, t_ops *ops) {
  t_num *head;
  t_num *tail;
  int i;

  head = stack->stack_b;
  tail = stack->tail_b;
  if (head->n == len) return (0);
  head = head->next;
  i = 1;
  while (head) {
    if (head->n == len) return (rbi(stack, i, ops));
    if (tail->n == len) return (rrbi(stack, i, ops));
    i++;
    head = head->next;
    tail = tail->last;
  }
  return (0);
}
