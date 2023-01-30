/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongble <jeongble@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:39:15 by jeongble          #+#    #+#             */
/*   Updated: 2022/07/22 10:57:20 by jeongble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "ft_printf/ft_printf.h"
#define I_MAX 2147483647
#define I_MIN -2147483648
#include <stdlib.h>

#define SA 0
#define SB 1
#define SS 2
#define PA 3
#define PB 4
#define RA 5
#define RB 6
#define RR 7
#define RRA 8
#define RRB 9
#define RRR 10

typedef struct s_num {
  struct s_num *next;
  struct s_num *last;
  int n;
} t_num;

typedef struct s_stack {
  struct s_num *stack_a;
  struct s_num *tail_a;
  struct s_num *stack_b;
  struct s_num *tail_b;
} t_stack;

typedef struct s_op {
  struct s_op *next;
  struct s_op *last;
  int op;
} t_op;

typedef struct s_ops {
  struct s_op *head;
  struct s_op *tail;
  int n;
} t_ops;

typedef struct s_queue {
  struct s_queue *next;
  struct s_stack *stacks;
  struct s_op *head;
  struct s_op *tail;
  int last_op;
} t_queue;

typedef struct s_s {
  int n;
  struct s_stack *stacks;
  int *inst;
} t_s;

t_num *node_new(int n);
void node_clear(t_num **stack);
void node_dup(t_num **dst, t_num **dst_tail, t_num *src);
int node_issort(t_num *stack);

t_op *op_new(int op);
void op_clear(t_op **op);
void op_dup(t_op **dst, t_op **dst_tail, t_op *src);
void op_print(t_op *head);
int op_size(t_op *head);

void op_sa(t_ops *ops, int op);
void op_sb(t_ops *ops, int op);
void op_pa(t_ops *ops, int op);
void op_pb(t_ops *ops, int op);
void op_ra(t_ops *ops, int op);
void op_rb(t_ops *ops, int op);
void op_rra(t_ops *ops, int op);
void op_rrb(t_ops *ops, int op);

t_ops *ops_new();
void ops_push_back(t_ops *ops, int op);
void ops_reverse(t_ops *spo);

t_stack *stack_init(void);
void stack_del(t_stack *stacks);
t_stack *stack_dup(t_stack *stacks);
void stack_print(t_stack *stacks);
// void	print_stack(t_stack *stack);

t_queue *queue_new(t_stack *stacks, t_op *head, t_op *tail, int last_op);
void queue_start(t_queue **front, t_queue **back, t_op **result, int n);

int op_valid(int op1, int op2);

int swap(t_num **stack, t_num **tail);
int push(t_num **dst, t_num **dst_tail, t_num **src, t_num **src_tail);
int rotate(t_num **stack, t_num **tail);
int rrotate(t_num **stack, t_num **tail);

int sa(t_stack *stacks);
int sb(t_stack *stacks);
int ss(t_stack *stacks);
int pa(t_stack *stacks);
int pb(t_stack *stacks);
int ra(t_stack *stacks);
int rb(t_stack *stacks);
int rr(t_stack *stacks);
int rra(t_stack *stacks);
int rrb(t_stack *stacks);
int rrr(t_stack *stacks);

void sort(t_stack *stack, int len, int span, t_ops *ops);

int ft_atoi_err(const char *str, t_num **stack_a, t_num **tail);
int ft_parse(int argc, char **argv, t_stack *stack, t_stack *kcats);

void s_del(t_s *s);
t_s *s_dup(t_s *src, int len);
void dpt0(t_stack *stack, t_s **a, int n, int len);
t_s *an(t_s *a, int n, int len);
void dptn(t_s *a[3], t_s *b[3], int n, int len);
int getspan(int argc);

void btoa(t_stack *stack, int len, t_ops *ops);
void pa_case(t_stack *stack, t_ops *ops);
int rotate_b(t_stack *stack, int n, t_ops *ops);
void a_n(t_s *a[], t_s *b[], int n, int len);
t_s *get_s(t_s *a, int n, int len);
void a_0(t_s *a[], t_s *b[], t_stack *stack, int len);
t_s *a_init(t_stack *stack, int len);

int rbi(t_stack *stack, int i, t_ops *ops);
int rrbi(t_stack *stack, int i, t_ops *ops);
int rbi2(t_stack *stack, int i);
int rrbi2(t_stack *stack, int i);

void ops_print(t_ops *ops);

#include <stdio.h>

#endif