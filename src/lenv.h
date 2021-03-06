#pragma once
typedef struct lval lval;
typedef struct lenv lenv;
struct lenv {
    lenv* par;
    int count;
    char** syms;
    lval** vals;
};

void lenv_delete(lenv* e);
lenv* lenv_new(void);

lval* lenv_get(lenv* e, lval* k);
void lenv_put(lenv* e, lval* k, lval* v);
void lenv_def(lenv* e, lval* k, lval* v);
lenv* lenv_copy(lenv* e);

void lenv_add_builtins(lenv* e);
lval* lenv_lookup_sym(lenv* e, lval* v);
void lenv_print(lenv* e);
