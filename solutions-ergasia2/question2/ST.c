#include <stdlib.h>
#include "ST_base.h"
#include "Item_base.h"
#include "Item.h"

link NEW(Item item, link l, link r, int N) {
  link x = malloc(sizeof *x);
  x->item = item;
  x->l = l;
  x->r = r;
  x->N = N;

  return x;
}

void STinit() {
  head = (z = NEW(NULLitem, NULL, NULL, 0));
}

int STcount() {
  return head->N;
}

Item searchR(link h, Key v) {
  Key t = key(h->item);

  if (h == z)
    return NULLitem;

  if eq(v, t)
    return h->item;

  if less(v, t)
    return searchR(h->l, v);
  else
    return searchR(h->r, v);
}

Item STsearch(Key v) {
  return searchR(head, v);
}

link insertR(link h, Item item) {
  Key v = key(item), t = key(h->item);

  if (h == z)
    return NEW(item, z, z, 1);

  if less(v, t)
    h->l = insertR(h->l, item);
  else
    h->r = insertR(h->r, item);

  (h->N)++;

  return h;
}

void STinsert(Item item) {
  head = insertR(head, item);
}

void sortR(link h, void (*visit)(Item)) {
  if (h == z)
    return;

  sortR(h->l, visit);
  visit(h->item);
  sortR(h->r, visit);
}

void STsort(void (*visit)(Item)) {
  sortR(head, visit);
}
