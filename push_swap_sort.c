/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongble <jeongble@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:02:50 by jeongble          #+#    #+#             */
/*   Updated: 2023/02/09 12:10:55 by jeongble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort23(t_stack *stack, int len, t_ops *ops);
static int sort_b(t_stack *stack, int len, t_ops *ops);

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

static int rrai22(t_stack *stack, int i) {
  int j;

  j = 0;
  while (j < i) {
    rra(stack);
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
  if (h1 + h2 < t) return (1);
  // if (h1 + h2 < t && h2 * 3 < t * 2) return (1);
  return (0);
}

void sort7(t_stack *stack, int len, int span, t_ops *ops) {
  int i;
  int x;
  int q;
  int r;
  int rr;
  int *arr;
  int t_span;
  t_stack *stack2;

  arr = malloc(sizeof(int) * len);
  stack2 = stack_dup(stack);
  x = 1;
  r = 0;
  rr = 0;
  i = 0;
  q = span / 4 + 1;
  t_span = span * 2;

  if (raorrra(stack2, i + t_span, len - i)) rrai22(stack2, (len - i) / 3);
  // rrai(stack, 10, ops);
  while (stack2->stack_a) {
    if (stack2->stack_a->n <= i + t_span) {
      arr[i] = stack2->stack_a->n;
      pb(stack2);
      i++;
      if (i % q == 0 && t_span > 1) t_span -= 1;
      if (raorrra(stack2, i + t_span, len - i)) rrai22(stack2, (len - i) / 3);
    } else {
      ra(stack2);
    }
  }
  sort71(arr, len);
  // btoa2(stack, len, ops);
}

t_stk *stk_new(int len) {
  t_stk *result;

  result = malloc(sizeof(t_stk));
  result->stk = malloc(sizeof(int) * len);
  result->stk_size = 0;
  result->n_stk = -1;
  result->arr = malloc(sizeof(int) * len);
  result->arr_size = 0;
  result->n_arr = -1;
  return (result);
}

void stk_compare(t_stk *src, t_stk *dst, int pop, int len) {
  int new_n_arr;
  int new_n_stk;
  int i;
  int j;

  new_n_arr = src->n_arr;
  new_n_stk = 0;
  i = 0;
  while (i < pop) {
    src->arr[src->arr_size + i] = src->stk[src->stk_size - 1 - i];
    new_n_arr += (src->stk[src->stk_size - 1 - i] - (src->arr_size + i)) *
                 (src->stk[src->stk_size - 1 - i] - (src->arr_size + i));
    i++;
  }
  while (i < src->stk_size) {
    new_n_stk += (src->stk[src->stk_size - 1 - i] - (src->arr_size + i)) *
                 (src->stk[src->stk_size - 1 - i] - (src->arr_size + i));
    i++;
  }
  if (dst->n_arr == -1 || new_n_arr + new_n_stk < dst->n_arr + dst->n_stk) {
    dst->stk_size = src->stk_size - pop;
    i = -1;
    while (++i < dst->stk_size) dst->stk[i] = src->stk[i];
    dst->n_stk = new_n_stk;

    dst->arr_size = src->arr_size + pop;
    i = -1;
    while (++i < dst->arr_size) dst->arr[i] = src->arr[i];
    dst->n_arr = new_n_arr;
  }
}

void stk_push(t_stk *src, int value) {
  int i;
  int new_n_stk;

  src->stk[src->stk_size] = value;
  src->stk_size += 1;
  new_n_stk = 0;
  i = 0;
  while (i < src->stk_size) {
    new_n_stk += (src->stk[src->stk_size - 1 - i] - (src->arr_size + i)) *
                 (src->stk[src->stk_size - 1 - i] - (src->arr_size + i));
    i++;
  }
  src->n_stk = new_n_stk;
}

void stk_free(t_stk *src) {
  if (src) {
    free(src->arr);
    free(src->stk);
    free(src);
  }
}

void sort71(int *arr, int len) {
  t_stk **dpt;
  int i;
  int j;
  int k;
  int n;
  t_stk *min;

  dpt = malloc(sizeof(t_stk *) * len);
  i = -1;
  while (++i < len) dpt[i] = stk_new(len);
  dpt[0]->n_arr = 0;
  dpt[0]->n_stk = 0;
  i = 0;
  while (i < len - 1) {
    j = i;
    while (j >= 0) {
      stk_push(dpt[j], arr[i]);
      k = i + 1;
      while (k > j) {
        stk_compare(dpt[j], dpt[k], k - j, len);
        k--;
      }
      j--;
    }
    i++;
  }
  min = dpt[0];
  n = dpt[0]->n_arr + dpt[0]->n_stk;
  i = 1;
  while (i < len) {
    if (dpt[i]->n_arr + dpt[i]->n_stk < n) {
      stk_free(min);
      min = dpt[i];
    } else {
      stk_free(dpt[i]);
    }
    i++;
  }

  i = 0;
  while (i < len) {
    printf("%d ", arr[i]);
    i++;
  }
  printf("\n");

  i = 0;
  while (i < min->arr_size) {
    arr[i] = min->arr[i];
    i++;
  }
  i = 0;
  while (i < min->stk_size) {
    arr[i + min->arr_size] = min->stk[min->stk_size - 1 - i];
    i++;
  }

  i = 0;
  while (i < len) {
    printf("%d ", arr[i]);
    i++;
  }
  printf("\n");
  exit(1);
}

void sort(t_stack *stack, int len, int span, t_ops *ops) {
  int i;
  int x;
  int q;
  int r;
  int rr;

  x = 1;
  r = 0;
  rr = 0;
  i = 0;
  q = span / 4 + 1;
  span *= 2;
  // span = 6;
  // q = 3;
  // printf("q = %d spqn %d\n", q, span);
  if (raorrra(stack, i + span, len - i)) rrai(stack, (len - i) / 3, ops);
  // rrai(stack, 10, ops);
  while (stack->stack_a) {
    if (stack->stack_a->n <= i) {
      if (i == rr) rr = 0;
      while (rr) {
        if (!rb(stack))
          if (x) ops_push_back(ops, RB);
        rr--;
      }
      if (stack->stack_b && stack->stack_b->n > stack->stack_a->n) {
        if (!rb(stack))
          if (x) ops_push_back(ops, RB);
        if (!pb(stack))
          if (x) ops_push_back(ops, PB);
        if (!rrb(stack))
          if (x) ops_push_back(ops, RRB);
      } else {
        if (!pb(stack))
          if (x) ops_push_back(ops, PB);
      };
      i++;
      if (i % q == 0 && span > 1) span -= 1;
      if (raorrra(stack, i + span, len - i)) rrai(stack, (len - i) / 3, ops);
    } else if (stack->stack_a->n <= i + span) {
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
      if (raorrra(stack, i + span, len - i)) {
        rrai(stack, (len - i) / 3, ops);
      }
    } else {
      if (!ra(stack))
        if (x) ops_push_back(ops, RA);
    }
  }
  // btoa(stack, len, ops);
  // btoa2(stack, len, ops);
}

t_ops *sortn(int *s, int len) {
  int span;
  int q;
  int i;
  int min;
  t_stack *stack;
  t_stack *c_stack;
  t_ops *ops;
  t_ops *c_ops;

  span = 2 * getspan(len);
  stack = stack_init(s, len);
  ops = sortn2(stack, len, span);
  min = ops->n;
  // printf("%d\n", min);
  i = 0;
  while (++i <= span) {
    c_stack = stack_init(s, len);
    c_ops = sortn2(c_stack, len, span - i);
    // printf("i = %d, %d\n", i, i * (i + 1) / 16 + c_ops->n);
    if (i * (i + 1) / 16 + c_ops->n <= min) {
      stack_del(stack);
      ops_free(ops);
      min = i * (i + 1) / 16 + c_ops->n;
      stack = c_stack;
      ops = c_ops;
    } else {
      stack_del(c_stack);
      ops_free(c_ops);
    }
  }
  // printf("%d\n", min);
  btoa2(stack, len, ops);
  return (ops);
}

t_ops *sortn2(t_stack *stack, int len, int span) {
  int i;
  int x;
  int q;
  int rr;
  t_ops *ops;

  ops = ops_new();
  x = 1;
  rr = 0;
  i = 0;
  if (!span)
    q = 1;
  else
    q = len / span + 1;
  // printf("span = %d, q = %d\n", span, q);
  if (raorrra(stack, i + span, len - i)) rrai(stack, (len - i) / 3, ops);
  while (stack->stack_a) {
    if (stack->stack_a->n <= i + span) {
      if (stack->stack_a->n <= i) {
        if (i == rr) rr = 0;
        while (rr) {
          if (!rb(stack)) ops_push_back(ops, RB);
          rr--;
        }
        if (stack->stack_b != NULL && stack->stack_b->n > stack->stack_a->n) {
          if (!rb(stack)) ops_push_back(ops, RB);
          if (!pb(stack)) ops_push_back(ops, PB);
          if (!rrb(stack)) ops_push_back(ops, RRB);
        } else if (!pb(stack))
          ops_push_back(ops, PB);
      } else {
        while (rr && stack->stack_b->n < stack->stack_a->n) {
          if (!rb(stack)) ops_push_back(ops, RB);
          rr--;
        }
        if (!pb(stack)) ops_push_back(ops, PB);
        rr++;
      }
      i++;
      if (i % q == 0 && span > 1) span -= 1;
      if (raorrra(stack, i + span, len - i)) rrai(stack, (len - i) / 3, ops);
    } else {
      if (!ra(stack)) ops_push_back(ops, RA);
    }
  }
  while (ops->tail && (ops->tail->op == RA || ops->tail->op == RRA)) {
    ops_erase(ops, ops->tail);
  }
  return (ops);
}

t_ops *sort2n(int *s, int len) {
  int span;
  int q;
  int i;
  int min;
  t_stack *stack;
  t_stack *c_stack;
  t_ops *ops;
  t_ops *c_ops;

  span = 2 * getspan(len);
  stack = stack_init(s, len);
  ops = sort2n2(stack, len, span);
  min = ops->n;
  // printf("%d\n", min);
  i = 0;
  while (++i <= span) {
    c_stack = stack_init(s, len);
    c_ops = sort2n2(c_stack, len, span - i);
    // printf("i = %d, %d\n", i, i * (i + 1) / 16 + c_ops->n);
    if (i * (i + 1) / 16 + c_ops->n <= min) {
      stack_del(stack);
      ops_free(ops);
      min = i * (i + 1) / 16 + c_ops->n;
      stack = c_stack;
      ops = c_ops;
    } else {
      stack_del(c_stack);
      ops_free(c_ops);
    }
  }
  // printf("%d\n", min);
  btoa2(stack, len, ops);
  return (ops);
}

t_ops *sort2n2(t_stack *stack, int len, int span) {
  int i;
  int x;
  int q;
  int rr;
  t_ops *ops;

  ops = ops_new();
  x = 1;
  rr = 0;
  i = 0;
  if (!span)
    q = 1;
  else
    q = len / span + 1;
  // printf("span = %d, q = %d\n", span, q);
  if (raorrra(stack, i + span, len - i)) rrai(stack, (len - i) / 3, ops);
  while (stack->stack_a) {
    if (stack->stack_a->n <= i + span) {
      if (stack->stack_a->n <= i) {
        while (rr && stack->stack_b->n < stack->stack_a->n) {
          if (!rb(stack)) ops_push_back(ops, RB);
          rr--;
        }
        if (!pb(stack)) ops_push_back(ops, PB);
        rr++;
      } else {
        if (i == rr) rr = 0;
        while (rr) {
          if (!rb(stack)) ops_push_back(ops, RB);
          rr--;
        }
        if (stack->stack_b != NULL && stack->stack_b->n > stack->stack_a->n) {
          if (!rb(stack)) ops_push_back(ops, RB);
          if (!pb(stack)) ops_push_back(ops, PB);
          if (!rrb(stack)) ops_push_back(ops, RRB);
        } else if (!pb(stack))
          ops_push_back(ops, PB);
      }
      i++;
      if (i % q == 0 && span > 1) span -= 1;
      if (raorrra(stack, i + span, len - i)) rrai(stack, (len - i) / 3, ops);
    } else {
      if (!ra(stack)) ops_push_back(ops, RA);
    }
  }
  while (ops->tail && (ops->tail->op == RA || ops->tail->op == RRA)) {
    ops_erase(ops, ops->tail);
  }
  return (ops);
}

void sort2(t_stack *stack, int len, int span, t_ops *ops) {
  int i;
  int x;
  int q;
  int r;
  int rr;

  x = 1;
  r = 0;
  rr = 0;
  i = 0;
  q = span / 4 + 1;
  span *= 2;
  // span = 6;
  // q = 3;
  // printf("q = %d spqn %d\n", q, span);
  if (raorrra(stack, i + span, len - i)) rrai(stack, (len - i) / 3, ops);
  // rrai(stack, 10, ops);
  while (stack->stack_a) {
    if (stack->stack_a->n <= i) {
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
    } else if (stack->stack_a->n <= i + span) {
      if (i == rr) rr = 0;
      while (rr) {
        if (!rb(stack))
          if (x) ops_push_back(ops, RB);
        rr--;
      }
      if (stack->stack_b != NULL && stack->stack_b->n > stack->stack_a->n) {
        if (!rb(stack))
          if (x) ops_push_back(ops, RB);
        if (!pb(stack))
          if (x) ops_push_back(ops, PB);
        if (!rrb(stack))
          if (x) ops_push_back(ops, RRB);
      } else {
        if (!pb(stack))
          if (x) ops_push_back(ops, PB);
      };
      i++;
      if (i % q == 0 && span > 1) span -= 1;
      if (raorrra(stack, i + span, len - i)) rrai(stack, (len - i) / 3, ops);
    } else {
      if (!ra(stack))
        if (x) ops_push_back(ops, RA);
    }
  }
  btoa2(stack, len, ops);
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

t_s *s_dup(t_s *src, int len, int size, int index) {
  t_s *result;
  int i;
  int j;

  result = malloc(sizeof(t_s));

  if (index >= 0)
    result->n = src->n + index;
  else {
    result->n = src->n - index;
    index += size;
  }

  result->stack_b = malloc(sizeof(int) * (size - 1));
  i = 0;
  while (i + index + 1 < size) {
    result->stack_b[i] = src->stack_b[i + index + 1];
    i++;
  }
  j = 0;
  while (i < size - 1) {
    result->stack_b[i] = src->stack_b[j];
    i++;
    j++;
  }

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
    free(s->stack_b);
    s->stack_b = NULL;

    free(s->inst);
    s->inst = NULL;
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
