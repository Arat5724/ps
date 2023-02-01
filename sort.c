// 3 4 1 2 5 v
// 3 4 1 2 6
// 3 4 1 2 7
// 2 4 1 3 5 v
// 2 4 1 3 6
// 2 4 1 3 7
// 3 2 1 4 5 v
// 3 2 1 4 6
// 3 2 1 4 7
// 2 4 1 5 3 v
// 3 2 1 5 4 v
// 3 2 1 5 6
// 3 2 1 5 7
// 2 4 1 6 3
// 3 2 1 6 4
// 3 2 1 6 5
// 3 2 1 6 7
// 1 4 2 3 5 v
// 1 4 2 3 6
// 1 4 2 3 7
// 3 1 2 4 5 v
// 3 1 2 4 6
// 3 1 2 4 7
// 1 4 2 5 3 v
// 3 1 2 5 4 v
// 3 1 2 5 6
// 3 1 2 5 7
// 1 4 2 6 3
// 3 1 2 6 4
// 3 1 2 6 5
// 3 1 2 6 7
// 1 4 3 2 5 v
// 1 4 3 2 6
// 1 4 3 2 7
// 2 1 3 4 5 v
// 2 1 3 4 6
// 2 1 3 4 7
// 2 1 3 5 4 v
// 2 1 3 5 6
// 2 1 3 5 7
// 2 1 3 6 4
// 2 1 3 6 5
// 2 1 3 6 7
// 3 1 4 2 5 v
// 3 1 4 2 6
// 3 1 4 2 7
// 2 1 4 3 5 v
// 2 1 4 3 6
// 2 1 4 3 7
// 2 1 4 5 3 v
// 2 1 4 6 3
// 1 4 5 2 3 v
// 3 1 5 2 4 v
// 3 1 5 2 6
// 3 1 5 2 7
// 2 1 5 3 4 v
// 2 1 5 3 6
// 2 1 5 3 7
// 2 1 5 4 3 v
// 2 1 5 6 3

#include "push_swap.h"

#define N 60

static const int rt1[61][3] = {
    {0, 0, 0}, {0, 0, 2}, {0, 0, 3}, {0, 0, 4}, {0, 1, 2}, {0, 1, 3}, {0, 1, 4},
    {0, 2, 2}, {0, 2, 3}, {0, 2, 4}, {0, 3, 0}, {0, 3, 1}, {0, 3, 3}, {0, 3, 4},
    {0, 4, 0}, {0, 4, 1}, {0, 4, 2}, {0, 4, 4}, {1, 1, 2}, {1, 1, 3}, {1, 1, 4},
    {1, 2, 2}, {1, 2, 3}, {1, 2, 4}, {1, 3, 0}, {1, 3, 1}, {1, 3, 3}, {1, 3, 4},
    {1, 4, 0}, {1, 4, 1}, {1, 4, 2}, {1, 4, 4}, {2, 0, 2}, {2, 0, 3}, {2, 0, 4},
    {2, 2, 2}, {2, 2, 3}, {2, 2, 4}, {2, 3, 1}, {2, 3, 3}, {2, 3, 4}, {2, 4, 1},
    {2, 4, 2}, {2, 4, 4}, {3, 0, 2}, {3, 0, 3}, {3, 0, 4}, {3, 1, 2}, {3, 1, 3},
    {3, 1, 4}, {3, 3, 0}, {3, 4, 0}, {4, 0, 0}, {4, 0, 1}, {4, 0, 3}, {4, 0, 4},
    {4, 1, 1}, {4, 1, 3}, {4, 1, 4}, {4, 2, 0}, {4, 4, 0}};

static const int rt2[61][3] = {
    {0, 0, 0}, {0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 0, 0}, {1, 0, 0}, {1, 1, 0},
    {0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 0, 0}, {0, 0, 0}, {2, 0, 0}, {2, 0, 0},
    {1, 0, 0}, {1, 0, 0}, {2, 0, 0}, {2, 0, 0}, {0, 0, 0}, {1, 0, 0}, {1, 1, 0},
    {0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 0, 0}, {0, 0, 0}, {2, 0, 0}, {2, 0, 0},
    {1, 0, 0}, {1, 0, 0}, {2, 0, 0}, {2, 0, 0}, {0, 0, 0}, {1, 0, 0}, {1, 1, 0},
    {0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 0, 0}, {2, 0, 0}, {2, 0, 0}, {1, 0, 0},
    {2, 0, 0}, {2, 0, 0}, {0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 0, 0}, {1, 0, 0},
    {1, 1, 0}, {0, 0, 0}, {1, 0, 0}, {0, 0, 0}, {0, 0, 0}, {2, 0, 0}, {2, 0, 0},
    {0, 0, 0}, {2, 0, 0}, {2, 0, 0}, {0, 0, 0}, {2, 0, 0}};

static const int rt[61][4] = {
    {0, 0, 0},    {7, 8, 9},    {11, 12, 13}, {15, 16, 17}, {21, 22, 23},
    {25, 26, 27}, {29, 30, 31}, {35, 36, 37}, {38, 39, 40}, {41, 42, 43},
    {44, 45, 46}, {47, 48, 49}, {50, 0, 0},   {51, 0, 0},   {53, 54, 55},
    {56, 57, 58}, {59, 0, 0},   {60, 0, 0},   {21, 22, 23}, {25, 26, 27},
    {29, 30, 31}, {35, 36, 37}, {38, 39, 40}, {41, 42, 43}, {44, 45, 46},
    {47, 48, 49}, {50, 0, 0},   {51, 0, 0},   {53, 54, 55}, {56, 57, 58},
    {59, 0, 0},   {60, 0, 0},   {7, 8, 9},    {11, 12, 13}, {15, 16, 17},
    {35, 36, 37}, {38, 39, 40}, {41, 42, 43}, {47, 48, 49}, {50, 0, 0},
    {51, 0, 0},   {56, 57, 58}, {59, 0, 0},   {60, 0, 0},   {7, 8, 9},
    {11, 12, 13}, {15, 16, 17}, {21, 22, 23}, {25, 26, 27}, {29, 30, 31},
    {44, 45, 46}, {53, 54, 55}, {1, 2, 3},    {4, 5, 6},    {10, 0, 0},
    {14, 0, 0},   {18, 19, 20}, {24, 0, 0},   {28, 0, 0},   {32, 33, 34},
    {52, 0, 0}};

static const int rinit[20] = {1,  4,  7,  10, 11, 18, 21, 24, 25, 32,
                              35, 38, 44, 47, 50, 52, 53, 56, 59, 0};

void btoa(t_stack *stack, int len, t_ops *ops) {
  int i;
  t_s *c;
  t_s *a[61];
  t_s *b[61];
  int *inst;

  a_0(a, b, stack, len);
  i = len - 1;
  while (i >= 0) {
    a_n(a, b, i, len);
    i--;
  }

  c = NULL;
  i = 1;
  while (i < 61) {
    if (c == NULL || (a[i] && a[i]->n < c->n)) {
      c = a[i];
    }
    i++;
  }
  inst = c->inst;
  i = len - 1;
  while (stack->stack_b) {
    rotate_b(stack, inst[i], ops);
    pa_case(stack, ops);
    i--;
  }
  // stack_print(stack);
}

void a_0(t_s *a[], t_s *b[], t_stack *stack, int len) {
  int i;

  i = -1;
  while (++i < 61) {
    a[i] = NULL;
    b[i] = NULL;
  }
  i = 0;
  while (rinit[i]) {
    a[rinit[i]] = a_init(stack, len);
    i++;
  }
}

void a_n(t_s *a[], t_s *b[], int n, int len) {
  int i;
  int j;
  int k;
  int temp;

  i = 1;
  while (i < 61) {
    if (a[i]) {
      j = 0;
      while (j < 3 && rt[i][j]) {
        if (n + 2 - rt1[rt[i][j]][2] >= 0) {
          if (b[rt[i][j]] == NULL) {
            b[rt[i][j]] = get_s(a[i], n + 2 - rt1[rt[i][j]][2], n + 1, len);
            b[rt[i][j]]->inst[n] = n + 2 - rt1[rt[i][j]][2];
            b[rt[i][j]]->n += rt2[i][j];
          } else {
            temp = a[i]->n + get_s2(a[i], n + 2 - rt1[rt[i][j]][2], n + 1) +
                   rt2[i][j];
            if (temp < b[rt[i][j]]->n) {
              b[rt[i][j]]->n = temp;

              free(b[rt[i][j]]->inst);
              b[rt[i][j]]->inst = malloc(sizeof(int) * len);
              k = 0;
              while (k < len) {
                (b[rt[i][j]]->inst)[k] = a[i]->inst[k];
                k++;
              }
              b[rt[i][j]]->inst[n] = n + 2 - rt1[rt[i][j]][2];
            }
          }
        }
        j++;
      }
    }
    i++;
  }
  i = 1;
  while (i < 61) {
    s_del(a[i]);
    a[i] = b[i];
    b[i] = NULL;
    i++;
  }
}

void pa_case(t_stack *stack, t_ops *ops) {
  int n;
  int first;
  int second;
  t_num *head;

  n = stack->stack_b->n;
  head = stack->stack_a;
  if (!head) {
    pa(stack);
    ops_push_back(ops, PA);
  } else if (!head->next) {
    first = head->n;
    if (n < first) {
      pa(stack);
      ops_push_back(ops, PA);
    } else {
      pa(stack);
      ops_push_back(ops, PA);
      sa(stack);
      ops_push_back(ops, SA);
    }
  } else if (!head->next->next) {
    first = head->n;
    second = head->next->n;
    if (n < first) {
      pa(stack);
      ops_push_back(ops, PA);
    } else if (n > second) {
      pa(stack);
      ops_push_back(ops, PA);
      ra(stack);
      ops_push_back(ops, RA);
    } else {
      pa(stack);
      ops_push_back(ops, PA);
      sa(stack);
      ops_push_back(ops, SA);
    }
  } else {
    first = head->n;
    second = head->next->n;
    if (n < first) {
      pa(stack);
      ops_push_back(ops, PA);
    } else if (n > second) {
      // ra(stack);
      // ops_push_back(ops, RA);
      // pa(stack);
      // ops_push_back(ops, PA);
      // sa(stack);
      // ops_push_back(ops, SA);
      // rra(stack);
      // ops_push_back(ops, RRA);
      ra(stack);
      ops_push_back(ops, RA);
      ra(stack);
      ops_push_back(ops, RA);
      pa(stack);
      ops_push_back(ops, PA);
      rra(stack);
      ops_push_back(ops, RRA);
      rra(stack);
      ops_push_back(ops, RRA);

    } else {
      // pa(stack);
      // ops_push_back(ops, PA);
      // sa(stack);
      // ops_push_back(ops, SA);
      ra(stack);
      ops_push_back(ops, RA);
      pa(stack);
      ops_push_back(ops, PA);
      rra(stack);
      ops_push_back(ops, RRA);

      // ra pa rra
    }
  }
}

int rotate_b(t_stack *stack, int n, t_ops *ops) {
  t_num *head;
  t_num *tail;
  int i;

  head = stack->stack_b;
  tail = stack->tail_b;
  if (head->n == n) return (0);
  head = head->next;
  i = 1;
  while (head) {
    if (head->n == n) return (rbi(stack, i, ops));
    if (tail->n == n) return (rrbi(stack, i, ops));
    i++;
    head = head->next;
    tail = tail->last;
  }
  return (0);
}

int get_s2(t_s *a, int n, int size) {
  int i;
  int *stack_b;

  stack_b = a->stack_b;
  i = 0;
  if (stack_b[i] != n) {
    i = 1;
    while (stack_b[i] != n && stack_b[size - i] != n) i++;
  }
  return (i);
}

t_s *get_s(t_s *a, int n, int size, int len) {
  t_s *temp;
  int i;
  int *stack_b;

  stack_b = a->stack_b;
  i = 0;
  if (stack_b[i] != n) {
    i = 1;
    while (1) {
      if (stack_b[i] == n) {
        break;
      }
      if (stack_b[size - i] == n) {
        i *= -1;
        break;
      }
      i++;
    }
  }
  temp = s_dup(a, len, size, i);
  return (temp);
}

t_s *a_init(t_stack *stack, int len) {
  t_s *result;
  int i;
  t_num *head;

  result = malloc(sizeof(t_s));
  result->n = 0;

  result->stack_b = malloc(sizeof(int) * len);

  i = 0;
  head = stack->stack_b;
  while (i < len) {
    result->stack_b[i] = head->n;
    i++;
    head = head->next;
  }

  result->inst = malloc(sizeof(int) * len);
  return (result);
}
